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
#include <termio.h>   /* POSIX terminal control definitions */

#include "cmd.h"
#include "tmpnrobot.h"
#include "mac.h"

#define MAXERRORCOUNT 5

//#define DEBUG

static int ioerrorstm;
static int dummyerror;
int *macerror=NULL;

int openMactalkSocket(char *host,int port)
{
	int on=1;
	int mactalkSocket,
		status = 0;
  struct hostent *hostPtr = NULL;
  struct sockaddr_in serverName = { 0 };
  	
  mactalkSocket = socket(PF_INET, SOCK_STREAM, 
												 IPPROTO_TCP);
  if (-1 == mactalkSocket)
  {
    perror("socket()");
    return -1;
  }
	setsockopt(mactalkSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  /*
   * need to resolve the remote server name or 
   * IP address 
	 */
	hostPtr = gethostbyname(host);
  if (NULL == hostPtr)
  {
    hostPtr = gethostbyaddr(host, 
														strlen(host), AF_INET);
    if (NULL == hostPtr)
    {
      perror("Error resolving server address");
			close(mactalkSocket);
      return -1;
    }
  }
  
  serverName.sin_family = AF_INET;
  serverName.sin_port = htons(port);
  (void) memcpy(&serverName.sin_addr, 
								hostPtr->h_addr,
								hostPtr->h_length);
  
  status = connect(mactalkSocket, 
									 (struct sockaddr*) &serverName,
									 sizeof(serverName));
  if (-1 == status)
  {
    perror("openSocket()");
		close(mactalkSocket);
    return -1;
  }
  return mactalkSocket;
}

int	build_MacRequest(MacTalkPacket *mtp, char *array)
{
	if (mtp->type!=CMD)
	{
		array[3]=mtp->address;
		array[4]=~array[3];
		array[5]=mtp->regnum;
		array[6]=~array[5];
		if (mtp->type==WRITE)
		{
			array[0]=0x52;
			array[1]=0x52;
			array[2]=0x52;
			array[7]=0x04; //len
			array[8]=~0x04;
			array[9]=0xFF&mtp->data;
			array[10]=~array[9];
			array[11]=0xFF&(mtp->data>>8);
			array[12]=~array[11];
			array[13]=0xFF&(mtp->data>>16);
			array[14]=~array[13];
			array[15]=0xFF&(mtp->data>>24);
			array[16]=~array[15];
			array[17]=0xAA;
			array[18]=0xAA;
			return 19;
		}
		else if (mtp->type==WRITE16)
		{
			array[0]=0x52;
			array[1]=0x52;
			array[2]=0x52;
			array[7]=0x02; //len
			array[8]=~0x02;
			array[9]=0xFF&mtp->sdata;
			array[10]=~array[9];
			array[11]=0xFF&(mtp->sdata>>8);
			array[12]=~array[11];
			array[13]=0xAA;
			array[14]=0xAA;
			return 15;
		}
		else if (mtp->type==WRITE16U)
		{
			array[0]=0x52;
			array[1]=0x52;
			array[2]=0x52;
			array[7]=0x02; //len
			array[8]=~0x02;
			array[9]=0xFF&mtp->udata;
			array[10]=~array[9];
			array[11]=0xFF&(mtp->udata>>8);
			array[12]=~array[11];
			array[13]=0xAA;
			array[14]=0xAA;
			return 15;
		}
		else
		{
			array[0]=0x50;
			array[1]=0x50;
			array[2]=0x50;
			array[7]=0xAA;
			array[8]=0xAA;
			return 9;
		}
	}
	else
	{
		array[0]=mtp->regnum;
		array[1]=array[0];
		array[2]=array[0];
		array[3]=0x01;
		array[4]=~0x01;
		array[5]=0xAA;
		array[6]=0xAA;
		return 7;
	}
}


int	get_MacRequest(char *array, MacTalkPacket *mtp, int type)
{
	int i;
	if (type==ACCEPT)
	{
		if (array[0]!=0x11||array[1]!=0x11||array[2]!=0x11)
		{
			for (i=0;i<3;i++)
			{
				printf("get_MacReq (ACCEPTHEADER) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		}
	}
	else if (type==WRITE)
	{
		if (array[0]!=0x52||array[1]!=0x52||array[2]!=0x52)
		{
			for (i=0;i<3;i++)
			{
				printf("get_MacReq (WRITEHEADER) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		}
		if (((0xFF&array[3])!=0x00)||((0xFF&array[4])!= 0xFF)) //address must be 0. we are master
		{
			for (i=0;i<3;i++)
			{
				printf("get_MacReq (address) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		} 
		mtp->address=0;
		if (array[5]!=~array[6])
		{
			for (i=0;i<10;i++)
			{
				printf("get_MacReq (regnum) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		}
		mtp->regnum=array[5];
		if (((0xFF&array[7])!=0x04)||((0xFF&array[8])!=0xFB))
		{
			for (i=0;i<10;i++)
			{
				printf("get_MacReq (len) failed %i: %i\n",i,array[i]);
			}
			return BAD;
			}
		if ((array[9]!=~array[10])||(array[11]!=~array[12])||(array[13]!=~array[14])||(array[15]!=~array[16]))
		{
			for (i=0;i<30;i++)
			{
				printf("get_MacReq (data) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		}
		int temp;
		char *d=(char*)&temp;
		*d=array[9];
		*(d+1)=array[11];
		*(d+2)=array[13];
		*(d+3)=array[15];
		mtp->data=temp;
		if ((0xFF&array[17])!=0xAA||(0xFF&array[18])!=0xAA)
		{
			for (i=0;i<30;i++)
			{
				printf("get_MacReq (cmd termination) failed %i: %i\n",i,array[i]);
			}
			return BAD;
		}
	}
	else
	{
		printf("get_MacReq failed. Type %i is not supported\n",type);
		return BAD;
	}
	return GOOD;
}

int sendMactalk(MacTalkPacket *request, MacTalkPacket *answer, tmpnMac *mac)
{
	char sendpacket[20];
	char recpacket[20];
	int spacketlen;
	struct timeval tv;
  fd_set readfds;
  int retselect=0;
  int rbytes=0;
	int totrbytes=0;
	int wantedbytes=20;
	spacketlen=build_MacRequest(request,sendpacket);
#ifdef DEBUG
	int i;
	for (i=0;i<spacketlen;i++)
	{
		printf("packet%i: 0x%02x\n",i,(char)sendpacket[i]);
	}
#endif
	if (send(mac->sfd, sendpacket,spacketlen, 0) == -1)
	{
		perror("mactalk sendRequest()");
		return 0;
	}
	if (request->type==READ) wantedbytes=19;
	else wantedbytes=3;
															
	while(totrbytes < wantedbytes)
  {
		tv.tv_sec = 0;
		tv.tv_usec = 50000;
		FD_ZERO(&readfds);
		FD_SET(mac->sfd, &readfds);
		
		// don't care about writefds and exceptfds: 
		retselect = select(mac->sfd+1, &readfds, NULL, NULL, &tv);
		if(retselect<=0)
		{
			printf("mactalk: timeout\n",mac->ipaddr, mac->port);
			return 0;
		}
		if (FD_ISSET(mac->sfd, &readfds))
		{
			/// read from the given socket 
			rbytes=read(mac->sfd, &recpacket[totrbytes], 255);
			if(rbytes<=0)
			{
				printf("mactalk: readerror\n");
				return 0;
			}
			totrbytes+=rbytes;
		}
	}
#ifdef DEBUG
	for (i=0;i<totrbytes;i++)
	{
		printf("recpacket%i: 0x%02x\n",i,recpacket[i]);
	}
#endif
	int anstype;
	if (request->type==WRITE||request->type==WRITE16||request->type==WRITE16U||request->type==CMD) anstype=ACCEPT;
	else if (request->type==READ) anstype=WRITE;
	if (get_MacRequest(recpacket,answer,anstype)==GOOD)
		return 1;
	return 0;
}

void makeSendPack(MacTalkPacket *sendpack, macConnect *mccon)
{
	float ftemp;
	sendpack->regnum=mccon->reg;
	sendpack->type=WRITE;
	switch (mccon->type)
	{
	case MAC_LONGINT:
		sendpack->data=mccon->data;
		break;
	case MAC_SHORTINT:
		sendpack->sdata=mccon->data;
		sendpack->type=WRITE16;
		break;
	case MAC_SHORTUINT:
		sendpack->udata=mccon->data;
		sendpack->type=WRITE16U;
		break;
	case MAC_FIXED4:
		ftemp=mccon->fdata/mccon->factor;
		if (ftemp>7.999756)
			ftemp=7.999756;
		else if (ftemp<-7.999756)
			ftemp=-7.999756;
		sendpack->sdata=ftemp*4096.0;
		sendpack->type=WRITE16;
		break;
	case MAC_FIXED8:
		ftemp=mccon->fdata/mccon->factor;
		if (ftemp>127.996)
			ftemp=127.996;
		else if (ftemp<-127.996)
			ftemp=-127.996;
		sendpack->sdata=ftemp*256.0;
		sendpack->type=WRITE16;
		break;
	case MAC_FIXED16:
		ftemp=mccon->fdata/mccon->factor;
		if (ftemp>32767.9999)
			ftemp=32767.9999847;
		else if (ftemp<-32768.0000)
			ftemp=-32768.0000;
		sendpack->data=ftemp*65536.0;
		break;
	case MAC_FIXED24:
		ftemp=mccon->fdata/mccon->factor;
		if (ftemp>127.99999994)
			ftemp=127.99999994;
		else if (ftemp<-128.0000)
			ftemp=-128.0000;
		sendpack->data=ftemp*16777216.0;
		break;
	case MAC_LONGINT_ASFLOAT:
		sendpack->data=mccon->fdata/mccon->factor;
		break;
	case MAC_SHORTINT_ASFLOAT:
		sendpack->sdata=mccon->fdata/mccon->factor;
		sendpack->type=WRITE16;
		break;
	case MAC_SHORTUINT_ASFLOAT:
		sendpack->udata=mccon->fdata/mccon->factor;
		sendpack->type=WRITE16U;
		break;
	case MAC_CMD:
		sendpack->type=CMD;
	}
}

void parseGetPack(MacTalkPacket *getpack, macConnect *mccon)
{
	float ftemp;
	unsigned short int ui;
	short int si;
	switch (mccon->type)
	{
	case MAC_LONGINT:
		mccon->data=getpack->data*mccon->factor;
		break;
	case MAC_SHORTINT:
		si=getpack->data&0xFFFF;
		mccon->data=si*mccon->factor;
		break;
	case MAC_SHORTUINT:
		ui=getpack->data&0xFFFF;
		mccon->data=ui*mccon->factor;
		break;
	case MAC_FIXED4:
		si=getpack->data&0xFFFF;
		ftemp=si/4096.0;
		mccon->fdata=mccon->factor*ftemp;
		break;
	case MAC_FIXED8:
		si=getpack->data&0xFFFF;
		ftemp=si/256.0;
		mccon->fdata=mccon->factor*ftemp;
		break;
	case MAC_FIXED16:
		ftemp=getpack->data/65536.0;
		mccon->fdata=mccon->factor*ftemp;
		break;
	case MAC_FIXED24:
		ftemp=getpack->data/16777216.0;
		mccon->fdata=mccon->factor*ftemp;
		break;
	case MAC_LONGINT_ASFLOAT:
		mccon->fdata=getpack->data*mccon->factor;
		break;
	case MAC_SHORTINT_ASFLOAT:
		si=getpack->data&0xFFFF;
		mccon->fdata=si*mccon->factor;
		break;
	case MAC_SHORTUINT_ASFLOAT:
		ui=getpack->data&0xFFFF;
		mccon->fdata=si*mccon->factor;
	}
}

void initMacTasks(tmpnWorkcell *workcell)
{
	int i;
	ioerrorstm = getMachineIdx("IOError");
	if (ioerrorstm!=-1)
	{
		macerror = getMachineValuePtr(ioerrorstm,"macerror");
		if (macerror==NULL)
			macerror=&dummyerror;
	}
	else
    macerror=&dummyerror;
  
	for (i=0;i<workcell->macs.maxidx;i++)
	{
		//thread with macTask
		pthread_t MacTask;
		pthread_attr_t attr;
		struct sched_param sched_param;
		pthread_attr_init(&attr);
		sched_param.sched_priority = 0;
		pthread_attr_setschedparam (&attr, &sched_param);
		pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_create(&MacTask, &attr, macTask, (void *) &workcell->macs.mac[i]);
	}
}

void *macTask(void * arg )
{
	int errorCount=0;
	int i,j;
	clock_t start;
  clock_t stop;
  float diff;
	char notstr[5];
	char betastr[5];
	int cycles=0;
	MacTalkPacket sendpack;
	MacTalkPacket getpack;
	diff=0.0;
	tmpnMac *mac = (tmpnMac*) arg;
	if(mac->simulate>0)
	{
		printf("simulating mactalk on %s port %d\n",mac->ipaddr,mac->port);
		return NULL;
	}
	mac->sfd = openMactalkSocket(mac->ipaddr,mac->port);
	if (mac->sfd!=-1)
	{
		printf("Opened socket to %s port %d.\n",mac->ipaddr,mac->port);
	}
	else
	{
		printf("Socket to %s port %d could not be opened\n",mac->ipaddr,mac->port);
		printf("Defaulting to simulation mode!\n");
		*macerror=1;
    return NULL;
	}
	int numOfUnits=0;
	for (i=0;i<mac->numOfMotors;i++)
	{
		sendpack.type=READ;
		sendpack.address=mac->iotab[i].address;
		sendpack.regnum=1;
		if (sendMactalk(&sendpack, &getpack, mac))
		{
			if ((getpack.data>>15)&0x01)
				sprintf(notstr,"%s","");
			else
				sprintf(notstr,"not ");
			if ((getpack.data>>13)&0x01)
				sprintf(betastr,"beta ");
			else
				sprintf(betastr,"%s","");
			printf("Found %s at address %d: MACTALK VERSION %i.%i %s(this is %sa MAC400/MAC800)\n",mac->iotab[i].module_name,mac->iotab[i].address,(getpack.data>>6)&0x7F,getpack.data&0x3F,betastr,notstr);
			numOfUnits++;
		}
	}
	if (mac->simulate==0&&numOfUnits!=mac->numOfMotors)
	{
		printf("Not all macs found on bus. Is correct address set?\n");
		printf("Defaulting to simulation mode!\n");
		*macerror=1;
		return NULL;
	}
	/* Init */
	for (i=0;i<mac->numOfMotors;i++)
	{
		sendpack.address=mac->iotab[i].address;
		for (j=0;j<mac->iotab[i].numOfInitWords;j++)
		{
			macConnect *mccon=&mac->iotab[i].initdata[j];
			makeSendPack(&sendpack,mccon);
			if (sendMactalk(&sendpack, &getpack, mac))
			{
				if (sendpack.type==CMD)
				{
					//wait a while if previous was a command.
					usleep(100000);
				}
			}
			else
			{
				printf("Error on MacTalk init routine. ");
				printf("Defaulting to simulation mode!\n");
				*macerror=1;
				break;
			}
		}
	}
	int packetsend;
	int motornum;
	int innum;
	macConnect *mccon;
	start = times(NULL);
	motornum=0;
	innum=0;
	/*  poll loop */
	while (1)
	{
		motornum++;
		if (motornum>=mac->numOfMotors) motornum=0;
		packetsend=0;
		/* Decide which packet gets send */

		// look on all outputs and inputs
		// outputs has higher priority
		// outputs only gets send if userchange==1
		// the input-queries are send round-robin.
		sendpack.address=mac->iotab[motornum].address;
		for (j=0;j<mac->iotab[motornum].numOfOutWords;j++)
		{
			int localsend=0;
			mccon=&mac->iotab[motornum].odata[j];
			while (mccon->userchange)
			{
				makeSendPack(&sendpack,mccon);		
				if (!sendMactalk(&sendpack, &getpack, mac))
				{
					errorCount++;
					if (errorCount>MAXERRORCOUNT)
					{
						printf("Too many errors on MacTalk. %s (%d)",mac->iotab[motornum].module_name,mac->iotab[motornum].address);
						printf("Defaulting to simulation mode!\n");
						*macerror=1;
						break;
					}
					usleep(10000);
					tcflush( mac->sfd, TCIOFLUSH );	/* flush the input & output streams */
					continue;
				}
				errorCount=0;
				mccon->userchange=0;
				localsend++;
			}
			if (localsend)
			{
				packetsend++;
				break;
			}
		}
		if (packetsend) usleep(1000);
		if (mac->iotab[motornum].numOfInWords<1) continue;
		innum++;
		if (innum>=mac->iotab[motornum].numOfInWords) innum=0;
		while (mac->iotab[motornum].idata[innum].bitmode!=-1)
		{
			innum++;
			if (innum>=mac->iotab[motornum].numOfInWords) innum=0;
		}
		mccon=&mac->iotab[motornum].idata[innum];
		packetsend=0;
		sendpack.regnum=mccon->reg;
		sendpack.type=READ;

		if (sendMactalk(&sendpack, &getpack, mac))
		{
			parseGetPack(&getpack, mccon);
#ifdef DEBUG			
			if (mccon->type==MAC_LONGINT)
				printf("reg %d %d\n",mccon->reg,mccon->data);
			else
				printf("reg %d %f\n",mccon->reg,mccon->fdata);
#endif
			packetsend++;
		}
		if (packetsend)
		{
			//update bitinputs
			for (j=0;j<mac->iotab[motornum].numOfInWords;j++)
			{
				mccon=&mac->iotab[motornum].idata[j];
				if (mccon->bitmode!=-1)
				{
					mccon->data=0x00000001&(((macConnect*)mccon->bitparent)->data>>mccon->bitmode);
				}
			}
		}
		stop = times(NULL);
		diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
		if(diff>1.00)
		{
			if (rs_param.io_debug>0)
			{
				printf("readMac executed %d cycles in %f %d\n",cycles,diff,errorCount);
				cycles=0;
			}
			cycles=0;
			start = times(NULL);
		}
		cycles++;
		usleep(1000);
	}
	close(mac->sfd);
	return NULL;
}
