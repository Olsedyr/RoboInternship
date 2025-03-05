/****************************************************************************
* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "tmpnrobot.h"
#include "cmd.h"
#include "modbus_tcp.h"
#include "comsk.h"

#define rdtscll(low) asm volatile("rdtsc":"=A"(low))

static int ioerrorstm;
static int dummyerror;
int *comskerror=NULL;

float nearbyintf(float x); // from math.h (ISOC99)

volatile int comskUpAndRunning=0;


int readmultiple_CTreg(int slave, int X, int Y,short *dest, int destsize, int fd)
{
	return read_holding_registers_tcp( slave, X*100+Y, destsize, dest, destsize*2, fd );
	
}

int writesingle_CTreg(int slave, int X, int Y, int value, int fd)
{	
	return preset_single_register_tcp(slave, X*100+Y, value, fd );
	//return preset_multiple_registers_tcp(slave, X*100+Y, 1, (short *)&value, fd , 0);	
	//return preset_multiple_registers_tcp_async1(slave, X*100+Y, 1, (short *)&value, fd );	
}

int writemultiple_CTreg(int slave, int adr, short* array, int count, int fd)
{	
	return preset_multiple_registers_tcp(slave, adr, count, array, fd , 0);	
}

int openComSK(tmpnComSK *comsk)
{
  int i;
  int j=0;
	comskstruct *freq=NULL;
	if(comsk->type!=0)
  {
		printf("Other ComSK-types than WONLY currently not supported!\n");
		exit(98);
  }
	else
	{
		if(comsk->simulate==0)
		{
			comsk->sfd = set_up_tcp(comsk->ipaddr);
			while( comsk->sfd  < 0 )
			{
				if(j++>20)
				{
					printf("ComSK: Can not connect to socket!\n");
          printf("simulateComSK\n");
          comsk->simulate = 1;
					*comskerror=1;
          return 0;
				}
				else
				{
					usleep(1000000); 
					comsk->sfd = set_up_tcp(comsk->ipaddr);
				}
			}
			printf("openComSK(): socket %d\n", comsk->sfd);
		}
		else
		{
			printf("simulateComSK\n");
			return 0;
		}
	}
	usleep(1000000);
	comskUpAndRunning++;
	
	for (i=0;i<comsk->numOfModules;i++)
	{
		freq = (comskstruct *)&comsk->iotab[i];
		for (j=0;j<freq->numOfInitWords;j++)
		{
			// write all init values
			writesingle_CTreg(freq->address, freq->initdata[j].major, freq->initdata[j].minor, (short)nearbyintf(freq->initdata[j].fdata*freq->initdata[j].factor), comsk->sfd);
		}
	}
	return 1;
}

void closeComSK(tmpnComSK *comsk)
{
  if(comsk->simulate==0&&close_tcp(comsk->sfd) <= 0)
  {
    printf("error close output.\n");
  }
}

void initComskTasks(tmpnWorkcell *workcell) 
{
	int i;
	ioerrorstm = getMachineIdx("IOError");
	if (ioerrorstm!=-1)
	{
		comskerror = getMachineValuePtr(ioerrorstm,"comskerror");
		if (comskerror==NULL)
			comskerror=&dummyerror;
	}
	for (i=0;i<workcell->comsks.maxidx;i++)
	{
		if (openComSK(&workcell->comsks.comsk[i]))
		{
			//thread with comskTask
			pthread_t ComSKTask;
			pthread_attr_t attr;
			struct sched_param sched_param;
			pthread_attr_init(&attr);
			sched_param.sched_priority = 0;
			pthread_attr_setschedparam (&attr, &sched_param);
			pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
			pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
			pthread_create(&ComSKTask, &attr, comskWonlyTask, (void *) &workcell->comsks.comsk[i]);
		}
	}
}	

void *comskWonlyTask(void * arg )
{
	int i,j;
  clock_t start;
  clock_t stop;
  float diff;
	tmpnComSK *comsk = (tmpnComSK*) arg;
	comskstruct *freq=NULL;
	diff=0.0;  
  start = times(NULL);
	int comskcycles=0;
	while (1)
	{
		for (i=0;i<comsk->numOfModules;i++)
		{
			freq = (comskstruct *)&comsk->iotab[i];
			for (j=0;j<freq->numOfOutWords;j++)
			{
				*freq->odata[j].data = (short)nearbyintf(freq->odata[j].fdata*freq->odata[j].factor);
			}
		}
		//broadcast
		if ( writemultiple_CTreg(0, comsk->lowadr, comsk->oarray, comsk->adrcount, comsk->sfd) < 0 )
		{
			*comskerror=1;
		}
		stop = times(NULL);
    diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
    if(diff>1.00) 
    {  
			if (rs_param.io_debug>0)
			{
				printf("writeComSK executed %d cycles in %f\n",comskcycles,diff);
				comskcycles=0;
			}
			start = times(NULL);
    }
		comskcycles++;
		usleep(1);
	}
	closeComSK(comsk);
	return (void *)0;
}
