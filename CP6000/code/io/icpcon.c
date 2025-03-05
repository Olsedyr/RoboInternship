/****************************************************************************
* Copyright (C) 2007 by MPN A/S - Guided by vision(R) Mads Lundstrøm        *
* All rights reserved.                                                      *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/times.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <netdb.h>

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "cmd.h"
#include "tmpnrobot.h"
#include "icpcon.h"

//#define DEBUG 1

#define MAXERRORCOUNT 10

static int ioerrorstm;
static int dummyerror;
int *icpconerror=NULL;

int openIcpconSocket(char *host,int port)
{
	int icpconSocket,
	 status = 0;
  struct hostent *hostPtr = NULL;
  struct sockaddr_in serverName = { 0 };
  

  icpconSocket = socket(PF_INET, SOCK_STREAM, 
												IPPROTO_TCP);
  if (-1 == icpconSocket)
  {
    perror("socket()");
    return -1;
  }

  /*
   * need to resolve the remote server name or 
   * IP address */
  hostPtr = gethostbyname(host);
  if (NULL == hostPtr)
  {
    hostPtr = gethostbyaddr(host, 
														strlen(host), AF_INET);
    if (NULL == hostPtr)
    {
      perror("Error resolving server address");
      return -1;
    }
  }
  
  serverName.sin_family = AF_INET;
  serverName.sin_port = htons(port);
  (void) memcpy(&serverName.sin_addr, 
								hostPtr->h_addr,
								hostPtr->h_length);
  
  status = connect(icpconSocket, 
									 (struct sockaddr*) &serverName,
									 sizeof(serverName));
  if (-1 == status)
  {
    perror("openSocket()");
    return -1;
  }
  return icpconSocket;
}

#define ICP_FIRMWAREVERSION 0
#define ICP_SETCONFIGURATION 1
#define ICP_SETOUTPUT 2
#define ICP_GETINPUT 3

int	build_IcpRequest(int type, int address, int data, char *array)
{
	int len;
	int i;
	unsigned int sum=0;
	char s[32];
	switch (type)
	{
	case ICP_FIRMWAREVERSION:
		array[0]='$';
		array[1]='0'; //address msb
		array[2]='0'+address; //address lsb (in ascii)
		array[3]='F';
		len = 4;
		break;
	case ICP_SETCONFIGURATION:
		array[0]='%';
		array[1]='0'; //address msb
		array[2]='0'+address; //address lsb (in ascii)
		array[3]='0';
		array[4]='1';
		array[5]='4'; //type msb
		array[6]='0'; //type lsb
		array[7]='0'; //baud rate
		array[8]='A'; //baud rate = 0A = 115200
		array[9]='4'; //data format
		array[10]='1'; //data format = 41 = checksum enabled, 7060 series
		len = 11;
		break;
	case ICP_SETOUTPUT:
		array[0]='@';
		array[1]='0'; //address msb
		array[2]='0'+address; //address lsb (in ascii)
		array[3]='0'+data;
		len=4;
		break;
	case ICP_GETINPUT:
		array[0]='@';
		array[1]='0'; //address msb
		array[2]='0'+address; //address lsb (in ascii)
		len=3;
	}
	for (i=0;i<len;i++)
	{
		sum+=array[i];
	}
	sprintf(s,"%2X",0xFF&sum);
	array[len]=s[0];
	array[len+1]=s[1];
	array[len+2]=0x0D; //CR
	return len+3;
}

#define BAD 0
#define GOOD 1
#define CHECKSUMERR 2

int sendIcpcon(int type, int address,unsigned int *data,int sfd) {
	int i;
	char s[16];
	char sendpacket[32];
	char recpacket[32];
	int spacketlen;
	struct timeval tv;
  fd_set readfds;
  int retselect=0;
  int rbytes=0;	
	int totrbytes=0;
	int supposedrbytes;
	switch (type)
	{
	case ICP_SETCONFIGURATION:
		supposedrbytes=6;
		break;
	case ICP_FIRMWAREVERSION:
		supposedrbytes=9;
		break;
	case ICP_SETOUTPUT:
		supposedrbytes=4;
		break;
	case ICP_GETINPUT:
		supposedrbytes=8;
		break;
	}
	spacketlen=build_IcpRequest(type,address,*data,sendpacket);
#ifdef DEBUG
	for (i=0;i<spacketlen;i++)
	{
		printf("packet%i: 0x%02x\n",i,sendpacket[i]);
	}
#endif
	if (send(sfd, sendpacket,spacketlen, 0) == -1)
	{
		perror("icpcon sendRequest()");
	}
	while(totrbytes < supposedrbytes)
  {
		tv.tv_sec = 0;
		tv.tv_usec = 50000;
		FD_ZERO(&readfds);
		FD_SET(sfd, &readfds);
		
		// don't care about writefds and exceptfds: 
		retselect = select(sfd+1, &readfds, NULL, NULL, &tv);
		if(retselect<=0)
		{
			printf("icpcon: timeout \n");
			return 0;
		}
		if (FD_ISSET(sfd, &readfds))
		{
			/// read from the given socket 
			rbytes=read(sfd, &recpacket[totrbytes], 255);
			if(rbytes<=0)
			{
				printf("icpcon: readerror\n");
				return 0;
			}
			totrbytes+=rbytes;
		}
	}
#ifdef DEBUG
	for (i=0;i<totrbytes;i++)
	{
		printf("recpacket%i: 0x%02x %c\n",i,recpacket[i],recpacket[i]);
	}
#endif
	// checksum verification
	strncpy(s,&recpacket[totrbytes-3],2);
	s[2]='\0';
	int chksum,sum=0;
	chksum=strtol(s, (char **)NULL, 16);
	for (i=0;i<totrbytes-3;i++)
	{
		sum+=recpacket[i];
	}
	if ((0xFF&sum)!=chksum)
	{
		printf("Checksum failed!\n");
		for (i=0;i<totrbytes;i++)
		{
			printf("recpacket%i: 0x%02x %c\n",i,recpacket[i],recpacket[i]);
		}
		return 0;
	}
	if (recpacket[totrbytes-1]!=0x0D)
	{
		printf("No carriage return!\n");
		for (i=0;i<totrbytes;i++)
		{
			printf("recpacket%i: 0x%02x %c\n",i,recpacket[i],recpacket[i]);
		}
		return 0;
	}
	if (type==ICP_GETINPUT)
	{
		strncpy(s,&recpacket[1],4);
		s[4]='\0';
		*data=strtol(s, (char **)NULL, 16); 
		//FOR 7063BD: 8 inputs in lsbyte, 3 outputs in no. 2 byte.
	}
	else if (type==ICP_FIRMWAREVERSION)
	{
		strncpy(s,&recpacket[1],2);
		s[2]='\0';
		printf("Found module on address %s, with firmware version ",s);
		strncpy(s,&recpacket[3],4);
		s[4]='\0';
		printf("%s\n",s);
	}
	return 1;
}

void initICPconTasks(tmpnWorkcell *workcell)
{
	int i;
	ioerrorstm = getMachineIdx("IOError");
	if (ioerrorstm!=-1)
	{
		icpconerror = getMachineValuePtr(ioerrorstm,"icpconerror");
		if (icpconerror==NULL)
			icpconerror=&dummyerror;
	}
	for (i=0;i<workcell->icpcons.maxidx;i++)
	{
		//thread with icpconTask
		pthread_t ICPConTask;
		pthread_attr_t attr;
		struct sched_param sched_param;
		pthread_attr_init(&attr);
		sched_param.sched_priority = 0;
		pthread_attr_setschedparam (&attr, &sched_param);
		pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_create(&ICPConTask, &attr, icpconTask, (void *) &workcell->icpcons.icpcon[i]);
	}
}

void *icpconTask(void * arg )
{
	int errorCount=0;
	int i;
	clock_t start;
  clock_t stop;
  float diff;
	int cycles=0;
	unsigned int dummy=0;
	diff=0.0;
	tmpnICPcon *icpcon = (tmpnICPcon*) arg;
	if(icpcon->simulate>0)
	{
		printf("simulating icpcon on %s port %d\n",icpcon->ipaddr,icpcon->port);
		return NULL;
	}
	icpcon->sfd = openIcpconSocket(icpcon->ipaddr,icpcon->port);
	if (icpcon->sfd!=-1)
	{
		printf("Opened socket to %s port %d.\n",icpcon->ipaddr,icpcon->port);
	}
	else
	{
		printf("ICPcon: Socket to %s port %d could not be opened\n",icpcon->ipaddr,icpcon->port);
		printf("Defaulting to simulation mode!\n");
		*icpconerror=1;
    return NULL;
	}
	int numOfUnits=0;
	for (i=0;i<icpcon->numOfModules;i++)
	{
		if (sendIcpcon(ICP_FIRMWAREVERSION,icpcon->iotab[i].address,&dummy,icpcon->sfd))
		{
			numOfUnits++;
		}
	}
	if (icpcon->simulate==0&&numOfUnits!=icpcon->numOfModules)
	{
		printf("Not all icpcons found on bus. Is correct address set?\n");
		printf("Defaulting to simulation mode!\n");
		*icpconerror=1;
		return NULL;
	}
	/* Init */
	for (i=0;i<icpcon->numOfModules;i++)
	{
		if (icpcon->iotab[i].dosetup==1)
		{
			printf("Sending initialization to %s,%i rs-485 address %i.\n",icpcon->ipaddr,icpcon->port,icpcon->iotab[i].address);
			printf("Set moxa to 9600 baud, and short INIT-leg on icpcon to ground.\n");
			printf("Sending init-data in: \n");
			int k;
			for (k=10;k>=0;k--)
			{
				printf("%i seconds\n",k);
				usleep(1000000);
			}
			sendIcpcon(ICP_SETCONFIGURATION,icpcon->iotab[i].address,&dummy,icpcon->sfd);
			printf("Initialization complete. New baud-rate is 115200.\n");
			exit(1);
		}
	}
	start = times(NULL);
	unsigned int res=0;
	/*  poll loop */
	while (1)
	{
		for (i=0;i<icpcon->numOfModules;i++)
		{
			errorCount=0;
			while (!sendIcpcon(ICP_SETOUTPUT,icpcon->iotab[i].address,&icpcon->iotab[i].odata,icpcon->sfd))
			{
				errorCount++;
				//resend
				if (errorCount>MAXERRORCOUNT)
				{
					printf("Too many errors on ICPcon. Quitting.");
					printf("Defaulting to simulation mode!\n");
					*icpconerror=1;
					break;
				}
			}
			errorCount=0;
			while (!sendIcpcon(ICP_GETINPUT,icpcon->iotab[i].address,&res,icpcon->sfd)) 
			{
				errorCount++;
				//resend
				if (errorCount>MAXERRORCOUNT)
				{
					printf("Too many errors on ICPcon. Quitting.");
					printf("Defaulting to simulation mode!\n");
					*icpconerror=1;
					break;
				}
			}
			icpcon->iotab[i].idata=0xFF&res;
			stop = times(NULL);
			diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
			if(diff>1.00)
			{
				if (rs_param.io_debug>0)
				{
					printf("readICPcon executed %d cycles in %f - %d\n",cycles,diff,errorCount);
				}
				cycles=0;
				start = times(NULL);
			}
			cycles++;
			if (*icpconerror) break;
		}
	}
	close(icpcon->sfd);
	return NULL;
}
