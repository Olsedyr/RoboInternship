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
#include "loadcell.h"

#define MAXERRORCOUNT 10000

static int ioerrorstm;
static int dummyerror;
int *loadcellerror=NULL;

int openBeebusSocket(char *host,int port)
{
	int on=1;
	int beebusSocket,
		status = 0;
  struct hostent *hostPtr = NULL;
  struct sockaddr_in serverName = { 0 };
  
	
  beebusSocket = socket(PF_INET, SOCK_STREAM, 
												IPPROTO_TCP);
  if (-1 == beebusSocket)
  {
    perror("socket()");
    return -1;
  }
	setsockopt(beebusSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
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
			close(beebusSocket);
      return -1;
    }
  }
  
  serverName.sin_family = AF_INET;
  serverName.sin_port = htons(port);
  (void) memcpy(&serverName.sin_addr, 
								hostPtr->h_addr,
								hostPtr->h_length);
  
  status = connect(beebusSocket, 
									 (struct sockaddr*) &serverName,
									 sizeof(serverName));
  if (-1 == status)
  {
    perror("openSocket()");
		close(beebusSocket);
    return -1;
  }
  return beebusSocket;
}

char calculate_lrc(BeebusPacket *bbp)
{
	int i;
	char lrc;
	lrc=2;
	lrc^=bbp->lge;
	lrc^=bbp->dvn;
	lrc^=bbp->type;
	for (i=0;i<bbp->lge-3;i++)
	{
		lrc^=bbp->data[i];
	}
	return lrc;
}

int	build_BeeRequest(BeebusPacket *bbp,char *array)
{
	array[0]=2;
	array[1]=(char)bbp->lge;
	array[2]=(char)bbp->dvn;
	array[3]=(char)bbp->type;
	memcpy(&array[4],&bbp->data[0],bbp->lge-3);
	array[1+bbp->lge]=calculate_lrc(bbp);
	if (bbp->next!=NULL)
		return 2+bbp->lge+build_BeeRequest(bbp->next,&array[2+bbp->lge]);
	else
		return 2+bbp->lge;
}

int	get_BeeRequest(char *array,BeebusPacket *bbp)
{
	int i;
	if (array[0]!=2)
	{
		for (i=0;i<30;i++)
		{
			printf("get_BeeReq failed %i: %i\n",i,array[i]);
		}
		return BAD;
	}
	bbp->lge=array[1];
	bbp->dvn=array[2];
	bbp->type=array[3];
	memcpy(&bbp->data[0],&array[4],bbp->lge-3);
	if (array[1+bbp->lge]!=calculate_lrc(bbp))
	{
		//printf("CHK %i (%i,%i)\n",CHECKSUMERR,array[1+bbp->lge],calculate_lrc(bbp));
		return CHECKSUMERR;
	}
	//	printf("GOOOD %i\n",GOOD);
	return GOOD;
}

int sendBeebus(BeebusPacket *request, BeebusPacket *answer, int sfd, int numOfCells)
{
	int i,len;
	char sendpacket[1024];
	char recpacket[1024];
	int spacketlen;
	struct timeval tv;
  fd_set readfds;
  int retselect=0;
  int rbytes=0;	
	int totrbytes=0;
	spacketlen=build_BeeRequest(request,sendpacket);
	request->bcc=calculate_lrc(request);
#ifdef DEBUG
	for (i=0;i<spacketlen;i++)
	{
		printf("packet%i: 0x%02x\n",i,sendpacket[i]);
	}
#endif
	if (send(sfd, sendpacket,spacketlen, 0) == -1)
	{
		perror("beebus sendRequest()");
		return 0;
	}
	recpacket[1]=255;
	while(totrbytes < (recpacket[1]+2)*numOfCells)
  {
		tv.tv_sec = 0;
		tv.tv_usec = 50000;
		FD_ZERO(&readfds);
		FD_SET(sfd, &readfds);
		
		// don't care about writefds and exceptfds: 
		retselect = select(sfd+1, &readfds, NULL, NULL, &tv);
		if(retselect<=0)
		{
			printf("beebus: timeout %i\n",numOfCells);
			return 0;
		}
		if (FD_ISSET(sfd, &readfds))
		{
			/// read from the given socket 
			rbytes=read(sfd, &recpacket[totrbytes], 255);
			if(rbytes<=0)
			{
				printf("beebus: readerror\n");
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
	int ret=1;
	len=(recpacket[1]+2);
	for (i=0;i<numOfCells;i++) {
		if (get_BeeRequest(&recpacket[len*i],&answer[i])==GOOD)
			ret&=1;
		else
			ret&=0;
	}
	return ret;
}

void beebusMakeDevicePollRequest(BeebusPacket *bp, int addr)
{
	bp->lge=3;
	bp->dvn=(char)addr;
	bp->type=0;
	bp->next=NULL;
}

int beebusParseDevicePollAnswer(BeebusPacket *bp, int addr)
{
	int i;
	if ((bp->lge!=6)||(bp->type!=1)||(bp->dvn!=addr))
	{
		printf("beebus: lge: %i type: %i dvn: %i\n",bp->lge,bp->type,bp->dvn);
		for (i=0;i<bp->lge-3;i++)
			printf("beebus: %i[%i]\n",i,bp->data[i]);
		return -1;
	}
	if (bp->data[0]==MCE9010)
		printf("beebus: Found LoadCell module MCE9010 at address %i. Beebus revision %i.%i\n",addr,bp->data[1],bp->data[2]);
	else if (bp->data[0]==MCE9610)
		printf("beebus: Found LoadCell module MCE9610 at address %i. Beebus revision %i.%i\n",addr,bp->data[1],bp->data[2]);
	else if (bp->data[0]==MCE2010)
		printf("beebus: Found LoadCell module MCE2010 at address %i. Beebus revision %i.%i\n",addr,bp->data[1],bp->data[2]);
	else if (bp->data[0]==MCE9624)
		printf("beebus: Found LED Display MCE9624 at address %i. Beebus revision %i.%i\n",addr,bp->data[1],bp->data[2]);
	else if (bp->data[0]==MCE9629)
		printf("beebus: Found Analog output module MCE9629 at address %i. Beebus revision %i.%i\n",addr,bp->data[1],bp->data[2]);
	return bp->data[0];
}

void beebusMakeLoadCellIdentifyRequest(BeebusPacket *bp, int addr)
{
	bp->lge=3;
	bp->dvn=(char)addr;
	bp->type=0x10;
	bp->next=NULL;
}

int beebusParseLoadCellIdentifyAnswer(BeebusPacket *bp, loadcellConnect *lcc, int addr)
{
	int i;
	int exp;
	float res;
	if ((bp->lge!=14)||(bp->type!=0x11)||(bp->dvn!=addr))
	{
		printf("beebus identify answer failed: lge: %i type: %i dvn: %i\n",bp->lge,bp->type,bp->dvn);
		for (i=0;i<30;i++)
			printf("beebus: %i[%i]\n",i,bp->data[i]);
		return -1;
	}
	exp = bp->data[10];
	res = pow(10.0,(float)exp);
	lcc->factor=res;
	printf("beebus IdentifyAnswer from addr=%i.\n{\n\t Firmware revision %i.%i.\n\t Produced in year 200%i.\n\t Serial number %i.\n\t Load cell capacity %0.1f grams.\n\t Resolution %0.4f grams\n}\n",addr,bp->data[0],bp->data[1],bp->data[2],*((unsigned int*)&bp->data[3])&0xFFFFFF,(*((int*)&bp->data[6]))*res,res);
	return 0;
}

void beebusMakeMeasurementSampleRequest(BeebusPacket *bp)
{
	static unsigned int sampleid=0;
	static unsigned int latchid=0;
	static unsigned int latchflag=1;
	bp->lge=4;
	bp->dvn=(char)0xFF; //broadcast
	bp->type=0x12;
	//	latchflag++;
	//	latchflag=(latchflag%2);
	bp->data[0]=(char)((latchid&0x07)|(latchflag<<3)|(sampleid<<4));
	if (latchflag)
	{
		if (++latchid>=0x08) latchid=0x00;	
	}
	if (++sampleid>=0x10) sampleid=0x00;
	//printf("data[0]=%X\n",bp->data[0]);
}

void beebusMakeSingleMeasurementRequest(BeebusPacket *bp,int addr)
{
	bp->lge=3;
	bp->dvn=(char)addr; 
	bp->type=0x13;
	bp->next=NULL;
}

void beebusMakeMultipleMeasurementRequest(BeebusPacket *bp,int firstAddr,int noOfCells)
{
	bp->lge=4;
	bp->dvn=(char)firstAddr; 
	bp->type=0x14;
	bp->data[0]=noOfCells;
	bp->next=NULL;
}

int beebusParseMeasurementAnswer(BeebusPacket *bp, loadcellConnect* lcc, int addr, int errDisplay)
{
	int i;
	static unsigned int sampleid[8]={100,100,100,100,100,100,100,100};
	static unsigned int latchid[8]={100,100,100,100,100,100,100,100};
	if ((bp->lge!=0x0a)||(bp->type!=0x15)||(bp->dvn!=addr))
	{
		printf("beebus measurement answer failed: lge: %i type: %i dvn: %i\n",bp->lge,bp->type,bp->dvn);
		for (i=0;i<30;i++)
			printf("beebus: %i[%i]\n",i,bp->data[i]);
		return -1;
	}
	unsigned int sampid;
	sampid=(bp->data[0]>>4)&0x0F;
	if (sampid!=sampleid[addr])
	{
		sampleid[addr]=sampid;
	}
	else 
	{
		if (errDisplay)
			printf("beebus measurement answer failed: sampleid not incremented %i %i\n",sampid,sampleid[addr]);
		return -1;
	}
	if ((bp->data[0]>>3)&0x01)
	{
		unsigned int lid;
		lid=(bp->data[0])&0x07;
		if (lid!=latchid[addr])
		{
			latchid[addr]=lid;
		}
		else 
		{
			if (errDisplay)
				printf("beebus measurement answer failed: latchid not incremented %i %i\n",lid,latchid[addr]);
			return -1;
		}
	}
	unsigned int status;
	unsigned int comparecode=0x00;
	status=bp->data[1];
	if (lcc->ignoreError)
	{
		comparecode=0x20;
	}
	if ((status!=comparecode)&&(status!=0x00))
	{
		if (errDisplay)
		{
			printf("beebus measurement answer failed 0x%08X:\n",status);
			if (status&0x01)
				printf("\tstatus: one or more sample id's are missing\n");
			if ((status>>1)&0x01)
				printf("\tstatus: Load cell timeout. Loadcell not connected or loadcell error\n");
			if ((status>>2)&0x01)
				printf("\tstatus: Load cell synchronization error. Loadcell not connected or loadcell error\n");
			if ((status>>3)&0x01)
				printf("\tstatus: Hardware synchronization error. Error synchronizing between loadcells.\n");
			if ((status>>4)&0x01)
				printf("\tstatus: Power failure. 24V DC too low.\n");
			if ((status>>5)&0x01)
				printf("\tstatus: Weight buffer calculation error. Internal load cell error.\n");
			if ((status>>6)&0x02)
				printf("\tstatus: Not used. Reserved for use in EE master code.\n");
		}
		return -1;
	}
	int val;
	val = *((int*)&bp->data[2]);
	lcc->fdata=val*lcc->factor;
	return 1;
}

void initLoadCellTasks(tmpnWorkcell *workcell) 
{
	int i;
	ioerrorstm = getMachineIdx("IOError");
	if (ioerrorstm!=-1)
	{
		loadcellerror = getMachineValuePtr(ioerrorstm,"loadcellerror");
		if (loadcellerror==NULL)
			loadcellerror=&dummyerror;
	}
  else
  {
    loadcellerror=&dummyerror;
	}
	for (i=0;i<workcell->loadcells.maxidx;i++)
	{
		//thread with loadcellTask
		pthread_t LoadCellTask;
		pthread_attr_t attr;
		struct sched_param sched_param;
		pthread_attr_init(&attr);
		sched_param.sched_priority = 0;
		pthread_attr_setschedparam (&attr, &sched_param);
		pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_create(&LoadCellTask, &attr, lcTask, (void *) &workcell->loadcells.loadcell[i]);
	}
}	


void *lcTask(void * arg )
{
	int errorCount=0;
	int i;
	int addr,numOfCells;
	clock_t start;
  clock_t stop;
  float diff;
	diff=0.0;  
	int cycles=0;
	BeebusPacket sendpack;
	BeebusPacket extrapack;
	BeebusPacket getpack[8];
	tmpnLoadCell *lc = (tmpnLoadCell*) arg;
	for (i=0;i<8;i++)
	{
		lc->iotab[i].fdata=0.0;
		lc->iotab[i].factor=1.0;
	}
	if(lc->simulate==2)
	{
		printf("simulating loadcellbus on %s port %d\n",lc->ipaddr,lc->port); 
		return NULL;
	}
	lc->sfd = openBeebusSocket(lc->ipaddr,lc->port);
	if (lc->sfd!=-1)
	{
		printf("Opened socket to %s port %d.\n",lc->ipaddr,lc->port);
	}
	else
	{
		printf("Socket to %s port %d could not be opened\n",lc->ipaddr,lc->port);
    printf("Defaulting to simulation mode!\n");
    for (i=0;i<8;i++)
    {
      lc->iotab[i].fdata=0.0;
      lc->iotab[i].factor=1.0;
    }
    *loadcellerror=1;
    return NULL;
	}
	numOfCells=0;
	for (addr=0;addr<lc->numOfModules;addr++)
	{
		beebusMakeDevicePollRequest(&sendpack,addr);
		if (sendBeebus(&sendpack, &getpack[addr], lc->sfd, 1)>0)
		{
			if (beebusParseDevicePollAnswer(&getpack[addr], addr)==MCE2010)
			{
				usleep(1000);
				beebusMakeLoadCellIdentifyRequest(&sendpack, addr);
				if (sendBeebus(&sendpack, &getpack[addr], lc->sfd, 1)>0)
				{
					if (beebusParseLoadCellIdentifyAnswer(&getpack[addr], &lc->iotab[addr],addr)!=-1)
					{
						//We have a live one!!
						numOfCells++;
					}
				}
			}
		}
	}
	if (lc->simulate==0&&numOfCells!=lc->numOfModules)
	{
		printf("Not all loadcells found on bus. Is correct address set?\n");
		printf("Defaulting to simulation mode!\n");
		for (i=0;i<8;i++)
		{
			lc->iotab[i].fdata=0.0;
			lc->iotab[i].factor=1.0;
		}
		*loadcellerror=1;
		return NULL;
	}
	addr=0;
	beebusMakeMultipleMeasurementRequest(&extrapack,addr,numOfCells);
	beebusMakeMeasurementSampleRequest(&sendpack);
	sendpack.next=&extrapack;
	start = times(NULL);
	while (1)
	{
		if (errorCount>MAXERRORCOUNT)
		{
			printf("Too many errors on beebus. Quitting.");
			printf("Defaulting to simulation mode!\n");
			for (i=0;i<8;i++)
			{
				lc->iotab[i].fdata=0.0;
				lc->iotab[i].factor=1.0;
			}
			*loadcellerror=1;
			break;
		}
		if (sendBeebus(&sendpack, &getpack[addr], lc->sfd, numOfCells)<=0)
		{
			errorCount++;
			usleep(5000);
			beebusMakeMeasurementSampleRequest(&sendpack);
			sendpack.next=&extrapack;
			continue;
		}
	
		for (i=addr;i<numOfCells;i++)
		{
			if (beebusParseMeasurementAnswer(&getpack[i],&lc->iotab[i], i, (errorCount>MAXERRORCOUNT-100))==-1)
			{
				errorCount++;
			}
			//printf("grams[%i]: %f\n",i,lc->iotab[i].fdata);
		}
		stop = times(NULL);
		diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
		if(diff>1.00) 
		{  
			if (rs_param.io_debug>0)
			{
				printf("readLoadCell executed %d cycles in %f %d\n",cycles,diff,errorCount);
				cycles=0;
			}
			cycles=0;
			start = times(NULL);
		}
		cycles++;
		if (!lc->fastmoxa)
			usleep(1500);
		beebusMakeMeasurementSampleRequest(&sendpack);
		sendpack.next=&extrapack;
	}
	return NULL;
}
