/****************************************************************************
* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
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

#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "tmpnrobot.h"
#include "stm.h"
#include "cmd.h"
#include "advantys.h"

volatile int service_count=0;
pthread_mutex_t stmServer_mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_chld(void *arg);


/***************************************************************************
 *
 *  stmserver task
 *
 ***************************************************************************/

void *stmServer(void *t)
{
  int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
  struct sockaddr_in my_addr;    // my address information
  struct sockaddr_in their_addr; // connector's address information
  socklen_t sin_size;
  int yes=1;

  pthread_t do_chld_task;
  pthread_attr_t attr;
  struct sched_param sched_param;
  pthread_attr_init(&attr);
  sched_param.sched_priority = 1;
  pthread_attr_setschedparam (&attr, &sched_param);
  pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) 
  {
    perror("socket");
    exit(1);
    return 0;
  }
  
  if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) 
  {
    perror("setsockopt");
    exit(1);
    return 0;
  }
  
  my_addr.sin_family = AF_INET;         // host byte order
  my_addr.sin_port = htons(rs_param.stmServerPort);     // short, network byte order
  my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
  memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
  
  if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))
      == -1) 
  {
    perror("bind");
    return 0;
  }
  
  if (listen(sockfd, STMSERVER_BACKLOG) == -1) {
    perror("listen");
    return 0;
  }
   
  while(1)   // main accept() loop
  {    
    sin_size = sizeof(struct sockaddr_in);
    if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
			 &sin_size)) == -1) {
      perror("accept");
      continue;
    }
    if(rs_param.statemachine_debug>2)
    {
      printf("stmServer: Got connection from %s\n",
						 inet_ntoa(their_addr.sin_addr));
    }
    /* create a new thread to process the incoming request */
    pthread_create(&do_chld_task, &attr, do_chld, (void *) new_fd);
  }
  return 0;
}

int getStrFromLine(char *instring, char *outstring, int lim)
{
  int i;
  for (i=0;i<lim;i++)
  {
    if (instring[i] == '\n')
    {
      outstring[i]='\0';
      return i;
    }
    outstring[i]=instring[i];
  }
  outstring[lim]='\0';
  return lim;
}

void *do_chld(void *arg)
{
  int mysocfd = (int) arg;
  char indata[STMSERVER_RECVBUFFER];
  char outdata[STMSERVER_SNDBUFFER];
  char s[256];
  char line[256];
  struct timeval tv;
  fd_set readfds;
  int retselect,rbytes,obytes,ibytes;
  int goodbye=0;
  int statemarray[STMSERVER_MAXSTATEMCOUNT];
	int stmvaluearray[STMSERVER_MAXVALUECOUNT];
	tmpnStateMachineValue *valuearray[STMSERVER_MAXVALUECOUNT];
  int statemidx=0;
	int valueidx=0;

  pthread_mutex_lock(&stmServer_mutex);
  service_count++;
  pthread_mutex_unlock(&stmServer_mutex);

  sprintf(s,"STMSERVER\nMODEL RS2050\nWORKCELL %i\n",rs_param.workcellid);
  if (send(mysocfd, s, strlen(s), 0) == -1)
    perror("do_chld sendinit"); 
  if(rs_param.statemachine_debug>2)
  {
    printf("Child thread [%d]: Socket number = %d. Socket number %i\n", (int)pthread_self(), mysocfd,service_count);
  }
  tv.tv_sec = STMSERVER_TIMEOUT;
  tv.tv_usec = 0;
  FD_ZERO(&readfds);
  FD_SET(mysocfd, &readfds);
  
  while(1) 
  {
    /* don't care about writefds and exceptfds: */
    retselect = select(mysocfd+1, &readfds, NULL, NULL, &tv);
    if(retselect<=0)
    {
      if(rs_param.statemachine_debug>2)
      {
				printf("Child thread [%d]: Connection timed out [%i sec].\n", (int)pthread_self(), STMSERVER_TIMEOUT);
				//printf("retselect=%d %d\n",retselect,errno);
      }
      break;
    }
    if (FD_ISSET(mysocfd, &readfds))
    {
      rbytes=0;
      obytes=0;
      ibytes=0;
      /* read from the given socket */
      rbytes=read(mysocfd, indata, STMSERVER_RECVBUFFER-1);
      if(rbytes<=0) 
      {
				if(rs_param.statemachine_debug>2)
				{
					printf("Child thread [%d]: Connection closed from foreign host.\n", (int)pthread_self());
				}
				break;
      }
      indata[rbytes]='\0'; // Null termination
      tv.tv_sec = STMSERVER_TIMEOUT;
      tv.tv_usec = 0;
      if(rs_param.statemachine_debug>2)
      {
				printf("Child thread [%d]: %i My indata = %s\n", (int)pthread_self(), rbytes, indata);
      }
      
      
      char questionmark[64];
      questionmark[63]='\0';
      
      int conversions = 0;
      
      int omsglen;
      int linelen;
      
      /* Parse messages */
      while(ibytes<rbytes)
      {
				linelen = getStrFromLine(&indata[ibytes], line, 255);
				ibytes+=(linelen+1);
				if (!strncmp("STATE",line,5)) 
				{
					char *statename;
					int idx;
					int mnlen;
					char machinename[64];
					machinename[63]='\0';
					conversions=sscanf(line,"STATE %63s %63s\n",machinename,questionmark);
					if ((conversions==2)&&(!strncmp("?",questionmark,1)))
					{
						mnlen=strlen(machinename);
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: STATE request received\n",(int)pthread_self());
						}
						idx = getMachineIdx(machinename);
						if (idx >= 0)
						{
							statename = getCurrentStateName(idx);
							omsglen = (8+mnlen+strlen(statename));
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"STATE %s %s\n",machinename,statename);
							obytes += omsglen;
							statemarray[statemidx++]=idx;
							if (statemidx>=STMSERVER_MAXSTATEMCOUNT) 
							{
								fprintf(stderr,"Child thread [%d]: Maximum statemcount [%i] pr. repeat reached \n", (int)pthread_self(), STMSERVER_MAXSTATEMCOUNT);
								close(mysocfd);
								return 0;
							}
						}
						else
						{
							omsglen = (15+mnlen);
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"STATE %s UNKNOWN\n",machinename);
							obytes += omsglen;
						}
					}	  
				}
				else if (!strncmp("VAL",line,3))
				{
					int idx;
					int mnlen;
					int vnlen;
					tmpnStateMachineValue* vlp;
					char valuename[64];
					char machinename[64];
					char datastring[64];
					machinename[63]='\0';
					valuename[63]='\0';
					datastring[63]='\0';
					conversions=sscanf(line,"VAL %63s %63s %63s\n",valuename,machinename,questionmark);
					if ((conversions==3)&&(!strncmp("?",questionmark,1)))
					{
						vnlen=strlen(valuename);
						mnlen=strlen(machinename);
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: VAL request received\n",(int)pthread_self());
						}
						idx = getMachineIdx(machinename);
						if (idx >= 0)
						{
							vlp = getMachineValue(idx, valuename);
							if (vlp==NULL||vlp->type==LINKVALUE)
								goto valerr;
							//				vlp = getLinkValue(&(tworkcell->statemachines.statemachine[idx]), vlp);
							if (vlp->subtype==0)
							{
								// TABLE,VALUE or CONSTANT
								sprintf(datastring,"I %i",vlp->data);
							}
							else
							{
								//TABLE,VALUE or CONSTANT
								sprintf(datastring,"F %0.4f",vlp->fdata);
							}
							omsglen = (7+mnlen+vnlen+strlen(datastring));
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER)
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"VAL %s %s %s\n",machinename,valuename,datastring);
							obytes += omsglen;
							stmvaluearray[valueidx]=idx;
							valuearray[valueidx++]=vlp;
							if (valueidx>=STMSERVER_MAXVALUECOUNT)
							{
								fprintf(stderr,"Child thread [%d]: Maximum valuecount [%i] pr. repeat reached \n", (int)pthread_self(), STMSERVER_MAXVALUECOUNT);
								close(mysocfd);
								return 0;
							}
						}
						else
						{
						valerr:
							omsglen = (16+mnlen+vnlen);
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"VAL %s %s I UNKNOWN\n",machinename,valuename);
							obytes += omsglen;
						}
					}	  
				}
				else if (!strncmp("REPEAT",line,6)&&(linelen==6))
				{
					char *statename;
					int idx;
					int mnlen;
					int vnlen;
					char *machinename;
					char *valuename;
					char datastring[64];	
					int i;
					if(rs_param.statemachine_debug>2)
					{
						printf("Child thread [%d]: REPEAT received\n",(int)pthread_self());
					}
					omsglen = 13;
					if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
					{
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
						}
						if (send(mysocfd, outdata, obytes, 0) == -1)
							perror("do_chld send");
						obytes=0;
					}
					if (statemidx>0||valueidx>0)
					{
						sprintf(&outdata[obytes],"REPEAT_START\n");
						obytes += omsglen;
						
						for (i=0;i<statemidx;i++)
						{
							idx=statemarray[i];
							machinename = tworkcell->statemachines.statemachine[idx].name;
							mnlen = strlen(machinename);
							statename = getCurrentStateName(idx);
							omsglen = (8+mnlen+strlen(statename));
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"STATE %s %s\n",machinename,statename);
							obytes += omsglen;
						}
						for (i=0;i<valueidx;i++)
						{
							datastring[63]='\0';
							tmpnStateMachineValue* vlp;
							vlp=valuearray[i];
							idx=stmvaluearray[i];
							machinename = tworkcell->statemachines.statemachine[idx].name;
							mnlen = strlen(machinename);
							valuename = vlp->name;
							vnlen = strlen(valuename);
							if (vlp->subtype==0)
							{
								// TABLE,VALUE or CONSTANT
								sprintf(datastring,"I %i",vlp->data);
							}
							else
							{
								//TABLE,VALUE or CONSTANT
								sprintf(datastring,"F %0.4f",vlp->fdata);
							}
							omsglen = (7+mnlen+vnlen+strlen(datastring));
							if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
							{
								if(rs_param.statemachine_debug>2)
								{
									printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
								}
								if (send(mysocfd, outdata, obytes, 0) == -1)
									perror("do_chld send");
								obytes=0;
							}
							sprintf(&outdata[obytes],"VAL %s %s %s\n",machinename,valuename,datastring);
							obytes += omsglen;
						}
					}
					omsglen = 11;
					if ((obytes+omsglen)>=STMSERVER_SNDBUFFER)
					{
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
						}
						if (send(mysocfd, outdata, obytes, 0) == -1)
							perror("do_chld send");
						obytes=0;
					}
					sprintf(&outdata[obytes],"REPEAT_END\n");
					obytes += omsglen;
				}
				else if (!strncmp("CLEAR",line,5)&&(linelen==5))
				{
					if(rs_param.statemachine_debug>2)
					{
						printf("Child thread [%d]: CLEAR received\n",(int)pthread_self());
					}
					omsglen = 9;
					if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
					{
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
						}
						if (send(mysocfd, outdata, obytes, 0) == -1)
							perror("do_chld send");
						obytes=0;
					}
					statemidx=0;
					sprintf(&outdata[obytes],"CLEAR_OK\n");
					obytes += omsglen;
 				}
	 			else if (!strncmp("END",line,3)&&(linelen==3))
		 		{
			 		if(rs_param.statemachine_debug>2)
				 	{
					  printf("Child thread [%d]: END received\n",(int)pthread_self());
					}
					omsglen = 8;
					if ((obytes+omsglen)>=STMSERVER_SNDBUFFER) 
					{
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
						}
						if (send(mysocfd, outdata, obytes, 0) == -1)
							perror("do_chld send");
						obytes=0;
					}
					sprintf(&outdata[obytes],"GOODBYE\n");
					obytes += omsglen;
					goodbye++;
					break;
				}
				else if (!strncmp("ALLSTATES",line,9)&&(linelen==9))
		 		{
					int i;
					char *statename;
					int mnlen;
					char *machinename;
					if(rs_param.statemachine_debug>2)
				 	{
					  printf("Child thread [%d]: ALLSTATES received\n",(int)pthread_self());
					}
					for (i=0;i<tworkcell->statemachines.maxidx;i++)
					{
						machinename = tworkcell->statemachines.statemachine[i].name;
						mnlen = strlen(machinename);
						statename = getCurrentStateName(i);
						omsglen = (8+mnlen+strlen(statename));
						if ((obytes+omsglen)>=STMSERVER_SNDBUFFER)
						{
							if(rs_param.statemachine_debug>2)
							{
								printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
							}
							if (send(mysocfd, outdata, obytes, 0) == -1)
								perror("do_chld send");
							obytes=0;
						}
						sprintf(&outdata[obytes],"STATE %s %s\n",machinename,statename);
						obytes += omsglen;
					}
				}
				else if (!strncmp("ALLVALS",line,7))
		 		{
					int i,idx;
					int mnlen,vnlen;
					tmpnStateMachineValue* vlp;
					char *valuename;
					char machinename[64];
					char datastring[64];
					machinename[63]='\0';
					datastring[63]='\0';
					conversions=sscanf(line,"ALLVALS %63s %63s\n",machinename,questionmark);
					if ((conversions==2)&&(!strncmp("?",questionmark,1)))
					{
						if(rs_param.statemachine_debug>2)
						{
							printf("Child thread [%d]: ALLVALS received\n",(int)pthread_self());
						}
						mnlen=strlen(machinename);
						idx = getMachineIdx(machinename);
						if (idx >= 0)
						{
							for (i=0;i<tworkcell->statemachines.statemachine[idx].numvalue;i++)
							{
								vlp = &tworkcell->statemachines.statemachine[idx].value[i];
								if (vlp!=NULL&&vlp->type!=LINKVALUE)
								{
									if (vlp->subtype==0)
									{
										// TABLE,VALUE or CONSTANT
										sprintf(datastring,"I %i",vlp->data);
									}
									else
									{
										//TABLE,VALUE or CONSTANT
										sprintf(datastring,"F %0.4f",vlp->fdata);
									}
									valuename=vlp->name;
									vnlen=strlen(valuename);
									omsglen = (7+mnlen+vnlen+strlen(datastring));
									if ((obytes+omsglen)>=STMSERVER_SNDBUFFER)
									{
										if(rs_param.statemachine_debug>2)
										{
											printf("Child thread [%d]: Sending fragmented response %i bytes long =\n%s\n", (int)pthread_self(),obytes,outdata);
										}
										if (send(mysocfd, outdata, obytes, 0) == -1)
											perror("do_chld send");
										obytes=0;
									}
									sprintf(&outdata[obytes],"VAL %s %s %s\n",machinename,valuename,datastring);
									obytes += omsglen;
								}
							}
						}
					}
				}
			}
			if (obytes>0)
			{
				if(rs_param.statemachine_debug>2)
				{
					printf("Child thread [%d]: Sending response %i bytes long = \n%s\n", (int)pthread_self(),obytes,outdata);
				}
				if (send(mysocfd, outdata, obytes, 0) == -1)
					perror("do_chld send"); 	  
      }
      if (goodbye) break;
    }
  }
  /* close the socket and exit this thread */
  if(rs_param.statemachine_debug>2)
  {
    printf("Child thread [%d]: closing\n", (int)pthread_self());
  }
  close(mysocfd);
  return 0;
}
