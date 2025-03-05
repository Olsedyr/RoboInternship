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
#include "cmd.h"
#include "modbus_tcp.h"
#include "advantys.h"

#define ISLAND_COM_STATUS 5357
#define ERROR_REPORTING   5358
#define NODE_CONF         5359
#define NODE_ASSEM        5367
#define EMRG_MSG          5375
#define FAULT_DETECT      5383
#define NIP_STATUS        5391

volatile int advantysUpAndRunning=0;

static int ioerrorstm;
static int dummyerror;
int *advantyserror=NULL;

/*
static void clearDIOerror(tmpnDIO *dio)
{
  int i;
 	if(dio->simulate!=0) return;
  for(i=0;i<dio->numOfOutWords;i++)
    preset_single_register_tcp( 1, 1+i, 0x00, dio->sfd );
  dio->cleardioerror=FALSE;
}

static void GetStatus(tmpnDIO *dio)
{
  short data[10];
  int *ptr = (int*)data;

  if(read_holding_registers_tcp( 1, NIP_STATUS, 1, (short*)ptr, 2, dio->sfd ) <=0)
		printf("error return force\n");
  if(read_holding_registers_tcp( 1, NODE_CONF, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
  if(read_holding_registers_tcp( 1, NODE_CONF+1, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
	if(read_holding_registers_tcp( 1, NODE_ASSEM, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
  if(read_holding_registers_tcp( 1, NODE_ASSEM+1, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
  if(read_holding_registers_tcp( 1, EMRG_MSG, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
	if(read_holding_registers_tcp( 1, EMRG_MSG+1, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
	if(read_holding_registers_tcp( 1, FAULT_DETECT, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
	if(read_holding_registers_tcp( 1, FAULT_DETECT+1, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
	if(read_holding_registers_tcp( 1, ISLAND_COM_STATUS, 1, (short*)ptr, 2, dio->sfd ) <=0)
      printf("error return force\n");
  
	if(rs_param.io_debug>0)
	{
		printf("NIP Status: 4%d :%X \n", NIP_STATUS, data[0]);
		printf("NODE_CONF : 4%d :%X \n", NODE_CONF, data[0]);
		printf("NODE_CONF+1 : 4%d :%X \n", NODE_CONF+1, data[0]);
		printf("NODE_ASSEM : 4%d :%X \n", NODE_ASSEM, data[0]);
		printf("NODE_ASSEM+1 : 4%d :%X \n", NODE_ASSEM+1, data[0]);
		printf("EMRG_MSG : 4%d :%X \n", EMRG_MSG, data[0]);
		printf("EMRG_MSG+1 : 4%d :%X \n", EMRG_MSG+1, data[0]);
		printf("FAULT_DETECT : 4%d :%X \n", FAULT_DETECT, data[0]);
		printf("FAULT_DETECT+1 : 4%d :%X \n", FAULT_DETECT+1, data[0]);
		printf("Input: 4%d :%X \n", ISLAND_COM_STATUS, data[0]);
	
		if((data[0]&0x00FF) == 0)
			printf("Mode 1 - The island is initializing\n");
		if((data[0]&0x00FF) == 0x40)
			printf("Mode 2\n");
		if((data[0]&0x00FF) == 0x60)
			printf("Mode 3\n");
		if((data[0]&0x00FF) == 0x61)
			printf("Mode 4\n");
		if((data[0]&0x00FF) == 0x62)
			printf("Mode 5\n");
		if((data[0]&0x00FF) == 0x63)
			printf("Mode 6\n");
		if((data[0]&0x00FF) == 0x64)
			printf("Mode 7\n");
		if((data[0]&0x00FF) == 0x80)
			printf("Mode 8\n");
		if((data[0]&0x00FF) == 0x81)
			printf("Mode 9\n");
		if((data[0]&0x00FF) == 0x82)
			printf("Mode 10\n");
		if((data[0]&0x00FF) == 0x83)
			printf("Mode 11\n");
		if((data[0]&0x00FF) == 0xA0)
			printf("Mode 12 - The conf matches.\n");
		if((data[0]&0x00FF) == 0xA1)
			printf("Mode 13\n");
		if((data[0]&0x00FF) == 0xA2)
			printf("Mode 14\n");
		if((data[0]&0x00FF) == 0xC0)
			printf("Mode 15\n");
		
		if((data[0]&0xFF00) & 0x0100)
			printf("Queue receive software overrun error.\n");
		if((data[0]&0xFF00) & 0x0200)
			printf("NIM overrun error.\n");
		if((data[0]&0xFF00) & 0x0400)
			printf("buff-off error.\n");
		if((data[0]&0xFF00) & 0x0800)
			printf("NIM warning level reached.\n");
		if((data[0]&0xFF00) & 0x1000)
			printf("NIM error status bit reset.\n");
		if((data[0]&0xFF00) & 0x2000)
			printf("Queue transfer software overrun error.\n");
		if((data[0]&0xFF00) & 0x4000)
			printf("Queue receive high-prio software overrun error.\n");
		if((data[0]&0xFF00) & 0x8000)
			printf("Queue transfer high-prio software overrun error.\n");
	}
	
	if(read_holding_registers_tcp( 1, ERROR_REPORTING, 1, (short*)ptr, 2, dio->sfd ) <=0)
		printf("error return force\n");
	if(rs_param.io_debug>0)
	{	
		printf("Input: 4%d :%X \n\n", ERROR_REPORTING, data[0]);
	}
	//    printf("GET_STATEMACHINES_IDX=%d\n",GET_STATEMACHINES_IDX);
	
}
*/

void clearErrorAdvantys(tmpnDIO *dio)
{
  if(dio->simulate==0)
  {
    dio->cleardioerror=TRUE;
    while(dio->cleardioerror) usleep(100000);
  }
}

void readAdvantys(tmpnDIO *dio)
{
  if(dio->simulate==0)
  {
		//NIP_STATUS=5391, INPUT_BASE=5392
		if(read_holding_registers_tcp( 1, INPUT_BASE, (dio->numOfInWords), (short*)dio->idata, (dio->numOfInWords)*2, dio->sfd ) <=0)
		{
			*advantyserror=1;
			printf("error read input a\n");
		}
		/* don't clear errors anyway. */ 
		/*use autorecovery on latch errors in advantys configuration */
	}
}

void readAdvantys1(tmpnDIO *dio)
{
  if(dio->simulate==0)
  {
		if(read_holding_registers_tcp_async1( 1, INPUT_BASE, (dio->numOfInWords), (short*)dio->idata, (dio->numOfInWords)*2, dio->sfd ) <=0)
		{
			*advantyserror=1;
			printf("error read input a1\n");
		}
	}
}
void readAdvantys2(tmpnDIO *dio)
{
  if(dio->simulate==0)
  {
		if(read_holding_registers_tcp_async2( 1, INPUT_BASE, (dio->numOfInWords), (short*)dio->idata, (dio->numOfInWords)*2, dio->sfd ) <=0)
		{
			*advantyserror=1;
			printf("error read input a2\n");
		}
	}
}

// Open() Read() Write() Close()
//OPEN
void openAdvantys(tmpnDIO *dio)
{
  int i;
  int j=0;
  if(dio->simulate==0)
	{
		ioerrorstm = getMachineIdx("IOError");
		if (ioerrorstm!=-1)
		{
			advantyserror = getMachineValuePtr(ioerrorstm,"advantyserror");
			if (advantyserror==NULL)
				advantyserror=&dummyerror;
		}
		dio->sfd = set_up_tcp(dio->ipaddr);
		while( dio->sfd  < 0 )
		{
			if(j++>10)
			{
				printf("Advantys: Can not connect to socket!\n");
        printf("Defaulting to simulation mode!\n");
        dio->simulate=1;
        *advantyserror=1;
        return;
			}
			else
			{
				usleep(1000000); 
				dio->sfd = set_up_tcp(dio->ipaddr);
			}
		}
		printf("openAdvantys(): socket %d\n", dio->sfd);
		usleep(8000000);
	}
  else
	{
    printf("simulateAdvantys\n");
	}
  //TODO read io numbering from database/workcell/statemachine
  for(i=0;i<dio->numOfInWords;i++) dio->idata[i]=0;
  for(i=0;i<dio->numOfOutWords;i++) dio->odata[i]=0;
  if(dio->simulate==0)
  {
    //READ
    //Status(dio);
    preset_multiple_registers_tcp( 1, OUTPUT_BASE, dio->numOfOutWords, (short*)dio->odata, dio->sfd , 10);

    readAdvantys(dio);

    if(read_holding_registers_tcp( 1, OUTPUT_BASE, dio->numOfOutWords, (short*)dio->odata, dio->numOfOutWords*2, dio->sfd ) <=0)
      printf("error read input\n");
  }
	advantysUpAndRunning++;
}

void writeAdvantys(tmpnDIO *dio)
{
  // Set output
  if(dio->simulate==0)
  {
    if(preset_multiple_registers_tcp( 1, OUTPUT_BASE, dio->numOfOutWords, (short*)dio->odata, dio->sfd , 10) <= 0)
      printf("error set output.\n");
  }
}
void writeAdvantys1(tmpnDIO *dio)
{
  // Set output
  if(dio->simulate==0)
  {
    if(preset_multiple_registers_tcp_async1( 1, OUTPUT_BASE, dio->numOfOutWords, (short*)dio->odata, dio->sfd ) <= 0)
      printf("error set output.\n");
  }
}
void writeAdvantys2(tmpnDIO *dio)
{
  // Set output
  if(dio->simulate==0)
  {
    if(preset_multiple_registers_tcp_async2( 1, OUTPUT_BASE, dio->numOfOutWords, (short*)dio->odata, dio->sfd ) <= 0)
      printf("error set output.\n");
  }
}

void closeAdvantys(tmpnDIO *dio)
{
  if(dio->simulate==0&&close_tcp(dio->sfd) <= 0)
  {
    printf("error close output.\n");
  }
}
	

void SetDIOCMsg(int msg)
{
}
