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
#include <netdb.h>

#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "tmpnrobot.h"
#include "stm.h"
#include "cmd.h"
#include "advantys.h"


static int reinitialize=0;

char recvbuf[STMCLIENT_RECVBUFFER];

extern int getStrFromLine(char *instring, char *outstring, int lim);


int getResponse(int* ibytes, int rbytes,char *instring,char *outstring1,char *outstring2,char *outstring3,char *outstring4) 
{
  char line[256];
  int linelen = 0;
  int conversions=0;
  /* Parse messages */
  if(*ibytes<rbytes)
  {
    linelen = getStrFromLine(&instring[*ibytes], line, 255);
    *ibytes+=(linelen+1);
    if (!strncmp("STATE",line,5)) 
    {
      conversions=sscanf(line,"STATE %63s %63s\n",outstring1,outstring2);
      if (conversions==2)
      {
				outstring1[63]='\0';
				outstring2[63]='\0';
				if (!strncmp(outstring2,"UNKNOWN",7)) return RESPONSE_STMUNKNOWN;
				else return RESPONSE_STMKNOWN;
      }  
    }
		else if (!strncmp("VAL",line,3))
    {
      conversions=sscanf(line,"VAL %63s %63s %63s %63s\n",outstring1,outstring2,outstring3,outstring4);
      if (conversions==4)
      {
				outstring1[63]='\0';
				outstring2[63]='\0';
				outstring3[63]='\0';
				outstring4[63]='\0';
				if (!strncmp(outstring4,"UNKNOWN",7)) return RESPONSE_VALUEUNKNOWN;
				else return RESPONSE_VALUEKNOWN;
      }
    }
    else if (!strncmp("REPEAT_START",line,12)&&(linelen==12)) 
    {
      return RESPONSE_REPEAT_START;
    }
    else if (!strncmp("REPEAT_END",line,10)&&(linelen==10)) 
    {
      return RESPONSE_REPEAT_END;
    }
    else if (!strncmp("STMSERVER",line,9)&&(linelen==9)) 
    {
      return RESPONSE_STMSERVER;
    }
    else if (!strncmp("GOODBYE",line,7)&&(linelen==7)) 
    {
      return RESPONSE_GOODBYE;
    }
    else if (!strncmp("MODEL",line,5)) 
    {
      conversions=sscanf(line,"MODEL %63s\n",outstring1);
      if (conversions==1)
      {
				outstring1[63]='\0';
				return RESPONSE_MODEL;
      }  
    }
    else if (!strncmp("WORKCELL",line,8)) 
    {
      conversions=sscanf(line,"WORKCELL %63s\n",outstring1);
      if (conversions==1)
      {
				outstring1[63]='\0';
				return RESPONSE_WORKCELL;
      }  
    }
    else if (!strncmp("CLEAR_OK",line,8)&&(linelen==8)) 
    {
      return RESPONSE_CLEAR_OK;
    }
    return RESPONSE_RUBBISH;
  }
  return RESPONSE_NONE;
}

int queryRemoteHost(tmpnWorkcell *workcell, tmpnRemoteHost *remotehost)
{
  char s[512];
  int i;
  int rbytes=0,ibytes=0;
  int resp = RESPONSE_RUBBISH;
  char os1[64];
  char os2[64];
	char os3[64];
  char os4[64];
  
  char rmodel[64];
  char rworkcell[64];
  
  if (remotehost->sockfd == -1)
  {
    resetRequest(remotehost);
    //openSocket to relevant hosts
    remotehost->sockfd = openSocket(remotehost->name,remotehost->port);
    if (remotehost->sockfd != -1)
    {
      if ((rbytes=sendRequest(remotehost)) != -1)
      {
				ibytes = 0;
				if(ibytes<rbytes)
				{
					// First get STMSERVER response
					resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
					if (resp != RESPONSE_STMSERVER)
					{
						closeSocket(remotehost);
						return -1;
					}
				}
				if(ibytes<rbytes)
				{
					//Then get MODEL response
					resp = getResponse(&ibytes,rbytes,recvbuf,rmodel,os2,os3,os4);
					if (resp != RESPONSE_MODEL)
					{
						closeSocket(remotehost);
						return -1;
					}
				}
				if(ibytes<rbytes)
				{
					//Then get WORKCELL response
					resp = getResponse(&ibytes,rbytes,recvbuf,rworkcell,os2,os3,os4);
					if (resp != RESPONSE_WORKCELL)
					{
						closeSocket(remotehost);
						return -1;
					}
					else if(rs_param.statemachine_debug>2)
					{
						printf("Scanning stmserver %s. Model %s, workcellid %s...",remotehost->name,rmodel,rworkcell);
					}
				}	
				resetRequest(remotehost);
				for(i=0;i<workcell->remotestatemachines.maxidx;i++)
				{
					if (workcell->remotestatemachines.remotestatemachine[i].remotehost==NULL)
					{
						sprintf(s,"STATE %s ?\n",workcell->remotestatemachines.remotestatemachine[i].name);
						buildRequest(remotehost,s, 256);
					}
				}
				if ((rbytes=sendRequest(remotehost)) != -1)
				{
					ibytes = 0;
					i=0;
					while(ibytes<rbytes)
					{
						// Get STATE response
						resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
						if (resp != RESPONSE_STMKNOWN)
						{
							if(rs_param.statemachine_debug>2)
								printf("STATE FAILED %i\n",i);
						}
						else
						{
							if(rs_param.statemachine_debug>2)
								printf("STATE SUCCEDED %i\n",i);
							remotehost->alive=1;
							workcell->remotestatemachines.remotestatemachine[getRemoteStatemachineIdx(workcell,os1)].remotehost = remotehost;
						}
						i++;
					}
				}
				else
				{
					return -1;
				}
				resetRequest(remotehost);
				for(i=0;i<workcell->remotevalues.maxidx;i++)
				{
					if (workcell->remotevalues.remotevalue[i].remotehost==NULL)
					{
						sprintf(s,"VAL %s %s ?\n",workcell->remotevalues.remotevalue[i].name,workcell->remotevalues.remotevalue[i].link);
						buildRequest(remotehost,s, 256);
					}
				}
				if ((rbytes=sendRequest(remotehost)) != -1)
				{
					ibytes = 0;
					i=0;
					while(ibytes<rbytes)
					{
						// Get VALUE response
						resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
						if (resp != RESPONSE_VALUEKNOWN)
						{
							if(rs_param.statemachine_debug>2)
								printf("VAL FAILED %i\n",i);
						}
						else
						{
							if(rs_param.statemachine_debug>2)
								printf("VAL SUCCEDED %i\n",i);
							remotehost->alive=1;
							workcell->remotevalues.remotevalue[getRemoteValueIdx(workcell,os2,os1)].remotehost = remotehost;
						}
						i++;
					}
				}
				else
				{
					return -1;
				}
      }
    }
  }
  return 1;
}

void resetRemoteHost(tmpnWorkcell *workcell, tmpnRemoteHost *remotehost)
{
	int j;
	remotehost->alive=0;
	if  (remotehost->sockfd != -1)
	{
		closeSocket(remotehost);
	}
	// Go through remotestatemachines and set state=unknown and remotehost = NULL
	for(j=0;j<workcell->remotestatemachines.maxidx;j++)
	{
		if (workcell->remotestatemachines.remotestatemachine[j].remotehost == remotehost)
		{
			workcell->remotestatemachines.remotestatemachine[j].remotehost=NULL;
			strcpy(workcell->remotestatemachines.remotestatemachine[j].state,"UNKNOWN");
		}
		if (workcell->remotevalues.remotevalue[j].remotehost == remotehost)
		{
			workcell->remotevalues.remotevalue[j].remotehost=NULL;
			workcell->remotevalues.remotevalue[j].subtype=0;
			workcell->remotevalues.remotevalue[j].data=0;
			workcell->remotevalues.remotevalue[j].fdata=0.0;
		}
	}
}

int initRemoteStatemachines(tmpnWorkcell *workcell)
{
  int i,j;
  int foundany=0;
  reinitialize=1;
  usleep(2000000);
  //Find statemachine-links that need to be looked up remotely
  workcell->remotestatemachines.maxidx = 0;
	tmpnStateMachine *stm;
  for(i=0;i<workcell->statemachines.maxidx;i++)
  {
		stm=&workcell->statemachines.statemachine[i];
		for (j=0;j<stm->numlink;j++)
    {
      if (stm->link[j].stmidx==-1)
      {
				int idx = workcell->remotestatemachines.maxidx++;
				tmpnRemoteStateMachine *remstm = &workcell->remotestatemachines.remotestatemachine[idx];
				strncpy(remstm->name,stm->link[j].name,127);
				remstm->name[127]='\0';
				pthread_mutex_init(&remstm->remotelock, NULL);		
				pthread_mutex_lock(&remstm->remotelock);
				strcpy(remstm->state,"UNKNOWN");
				pthread_mutex_unlock(&remstm->remotelock);
				remstm->remotehost=NULL;
				if(rs_param.statemachine_debug>2)
					printf("initRemoteStatemachines %i: State reset to %s\n",idx,remstm->state);
      }
    }
  }
	for(i=0;i<workcell->statemachines.maxidx;i++)
  {
		tmpnStateMachine *stm=&workcell->statemachines.statemachine[i];
		for (j=0;j<stm->numvalue;j++)
		{			
			if (stm->value[j].type==LINKVALUE)
			{
				if (stm->value[j].linkvalue==NULL)
				{
					char *remotelvalname;
					int l;
					remotelvalname=stm->value[j].link;
					for(l=0;l<stm->numlink;l++)
					{
						if (!strcmp(stm->link[l].localname,stm->value[j].link))
						{
							remotelvalname=stm->link[l].name;
							break;
						}
					}					
					int remidx=-1;
					remidx=getRemoteValueIdx(workcell,stm->value[j].linkname,remotelvalname);
					if (remidx >= 0)
					{
						// remote linkvalue already exists. Link to the pre-existing remotevalue.
						stm->value[j].remote=&(workcell->remotevalues.remotevalue[remidx]);
					}
					else
					{
						// make new remotevalue
						int idx = workcell->remotevalues.maxidx++;
						strncpy(workcell->remotevalues.remotevalue[idx].name,stm->value[j].linkname,127);
						workcell->remotevalues.remotevalue[idx].name[127]='\0';
						
						strncpy(workcell->remotevalues.remotevalue[idx].link,remotelvalname,127);
						workcell->remotevalues.remotevalue[idx].link[127]='\0';
						workcell->remotevalues.remotevalue[idx].data=0;
						workcell->remotevalues.remotevalue[idx].fdata=0.0;
						workcell->remotevalues.remotevalue[idx].subtype=0; //INT
						workcell->remotevalues.remotevalue[idx].remotehost=NULL;
						stm->value[j].remote=&(workcell->remotevalues.remotevalue[idx]);
						if(rs_param.statemachine_debug>2)
							printf("initRemoteStatemachines %i: Value reset to %i\n",idx,workcell->remotevalues.remotevalue[idx].data);
					}
				}
			}
		}
	}
  for(i=0;i<workcell->remotehosts.maxidx;i++)
  {
    //reset socket to relevant hosts
    workcell->remotehosts.remotehost[i].sockfd = -1;
    // Reset sendqueues
    resetRequest(&workcell->remotehosts.remotehost[i]);
    workcell->remotehosts.remotehost[i].alive=0;
  }
  // Find host for each link
  for(j=0;j<workcell->remotehosts.maxidx;j++)
  {
    if(queryRemoteHost(workcell, &workcell->remotehosts.remotehost[j])==1)
    {
      foundany++;
    }
  }
  for(i=0;i<workcell->remotehosts.maxidx;i++)
  {
    //closeSocket to un-needed hosts
    if  ((workcell->remotehosts.remotehost[i].alive == 0)&&(workcell->remotehosts.remotehost[i].sockfd != -1))
    {
      closeSocket(&workcell->remotehosts.remotehost[i]);
      // Reset sendqueues
      resetRequest(&workcell->remotehosts.remotehost[i]);
    }
  }
  //thread with RemoteStatemachinesClientTask
  pthread_t RemoteStatemachinesClientTask;
  pthread_attr_t attr;
  struct sched_param sched_param;
  pthread_attr_init(&attr);
  sched_param.sched_priority = 0;
  pthread_attr_setschedparam (&attr, &sched_param);
  pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_create(&RemoteStatemachinesClientTask, &attr, RemoteStatemachinesClient, (void *) workcell);
  return foundany;
}

void *RemoteStatemachinesClient(void *arg)
{
  int i,j;
  int iterations=0;
  int repeatend;
  int ibytes=0,rbytes=0;
  char s[256];
  int resp = RESPONSE_RUBBISH;
  char os1[64];
  char os2[64];
	char os3[64];
  char os4[64];
  tmpnWorkcell *workcell = (tmpnWorkcell *) arg;
  reinitialize=0;
  clock_t start;
  clock_t stop;
  float diff;
	diff=0.0;  
  start = times(NULL);
	int stmclientcycles=0;
  while(!reinitialize) 
  {
    // build Requests for each external host
    sprintf(s,"REPEAT\n");
    // Go through remotehosts
    for(i=0;i<workcell->remotehosts.maxidx;i++)
    {
      // Reset sendqueues
			tmpnRemoteHost *remotehost=&workcell->remotehosts.remotehost[i];
      resetRequest(remotehost);
      if (remotehost->sockfd != -1)	 
      {
				buildRequest(remotehost,s, 255);
      }
      else 
      {
				if (!(iterations%(STMCLIENT_POLLDEADINTERVAL/STMCLIENT_UPDATEINTERVAL)))
				{
					int firstunknown=-1;
					// Reinit
					for(j=0;j<workcell->remotestatemachines.maxidx;j++)
					{
						if (workcell->remotestatemachines.remotestatemachine[j].remotehost==NULL)
						{
							firstunknown=j;
							break;
						}
					}
					if (firstunknown == -1)
					{
						for(j=0;j<workcell->remotevalues.maxidx;j++)
						{
							if (workcell->remotevalues.remotevalue[j].remotehost==NULL)
							{
								firstunknown=j;
								break;
							}
						}
					}
					if (firstunknown != -1)
					{
						queryRemoteHost(workcell, &workcell->remotehosts.remotehost[i]);
						resetRequest(&workcell->remotehosts.remotehost[i]);
					}
				}
      }
    }
    // Send requests
    for(i=0;i<workcell->remotehosts.maxidx;i++)
    {
			tmpnRemoteHost *rhost=&workcell->remotehosts.remotehost[i];
			if (rhost->sndbuf_idx>0)
      {
				if ((rbytes=sendRequest(rhost)) != -1)
				{
					ibytes = 0;
					if(ibytes<rbytes)
					{
						// Get response
						resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
						if (resp != RESPONSE_REPEAT_START)
						{
							if(rs_param.statemachine_debug>2)
								printf("Didn't receive REPEAT_START\n");
							resetRemoteHost(workcell, rhost);
							continue;
						}
						repeatend=0;
						while(ibytes<rbytes)
						{
							resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
							if (resp == RESPONSE_STMKNOWN)
							{
								// update workcell->remotestatemachines.remotestatemachine[idx].state
								int remidx;
								remidx = getRemoteStatemachineIdx(workcell,os1);
								tmpnRemoteStateMachine *remstm = &workcell->remotestatemachines.remotestatemachine[remidx];
								if (remidx>=0)
								{
									if(rs_param.statemachine_debug>2)
										printf("Updated STM %s to state %s\n",remstm->name,os2);
									pthread_mutex_lock(&remstm->remotelock);
									strcpy(remstm->state,os2);
									pthread_mutex_unlock(&remstm->remotelock);
								}
								else
								{
									if(rs_param.statemachine_debug>2)
										printf("Couldn't find local statemachine: %s\n",os1);
									//	return (void *)-1;
									exit(1);
								}
							}
							else if (resp == RESPONSE_VALUEKNOWN)
							{
								// update workcell->remotevalues.remotevalue[idx]
								int remidx;
								remidx = getRemoteValueIdx(workcell,os2,os1);
								if (remidx>=0)
								{
									if (*os3=='I')
									{
										workcell->remotevalues.remotevalue[remidx].data = atoi(os4);
										workcell->remotevalues.remotevalue[remidx].subtype=0;
									}
									else if (*os3=='F')
									{
										workcell->remotevalues.remotevalue[remidx].fdata = atof(os4);
										workcell->remotevalues.remotevalue[remidx].subtype=1;
									}
									if(rs_param.statemachine_debug>2)
									{
										if (workcell->remotevalues.remotevalue[remidx].subtype==0)
											printf("Updated VAL %s (%s) to %i\n",workcell->remotevalues.remotevalue[remidx].name,workcell->remotevalues.remotevalue[remidx].link,workcell->remotevalues.remotevalue[remidx].data);
										else
											printf("Updated VAL %s (%s) to %0.4f\n",workcell->remotevalues.remotevalue[remidx].name,workcell->remotevalues.remotevalue[remidx].link,workcell->remotevalues.remotevalue[remidx].fdata);
									}
								}
								else
								{
									if(rs_param.statemachine_debug>2)
										printf("Couldn't find local value: %s in %s\n",os2,os1);
									//return (void *)-1;
									//exit(1);
								}
							}
							else if (resp == RESPONSE_REPEAT_END)
							{
								repeatend++;
								break;
							} 
							else 
							{
								if(rs_param.statemachine_debug>2)
									printf("received %i\n",resp);
								//return (void *)-1;
								//exit(1);
								resetRemoteHost(workcell, rhost);
								continue;
							}
						}
						if ((!repeatend)) 
						{
							if(rs_param.statemachine_debug>2)
								printf("Didn't receive REPEAT_END\n");
							//return (void *)-1;
							//	exit(1);
							resetRemoteHost(workcell, rhost);
							continue;
						}
					}
				}
				else
				{
					resetRemoteHost(workcell, rhost);
				}
      }
    }
		stop = times(NULL);
    diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
    if(diff>1.00) 
    {  
			if (rs_param.statemachine_debug>2)
			{
				printf("stmClient executed %d cycles in %f\n",stmclientcycles,diff);
				stmclientcycles=0;
			}
			start = times(NULL);
    }
		stmclientcycles++;
    usleep(STMCLIENT_UPDATEINTERVAL);
    if(++iterations==10000) iterations=0;
  }
  // build Requests for each external host
  sprintf(s,"END\n");
  // Go through remotehosts
  for(i=0;i<workcell->remotehosts.maxidx;i++)
  {
    resetRequest(&workcell->remotehosts.remotehost[i]);
    if  ((workcell->remotehosts.remotehost[i].alive == 1)&&(workcell->remotehosts.remotehost[i].sockfd != -1))
    {
      buildRequest(&(workcell->remotehosts.remotehost[i]),s, 256);
    }
  }
  // Send requests
  for(i=0;i<workcell->remotehosts.maxidx;i++)
  {
		tmpnRemoteHost *rhost=&workcell->remotehosts.remotehost[i];
    if ((rhost->alive==1)&&(rhost->sndbuf_idx>0)&&(rhost->sockfd != -1))
    {
      if ((rbytes=sendRequest(rhost)) != -1)
      {
				ibytes = 0;
				if(ibytes<rbytes)
				{
					// Get GOODBYE response
					resp = getResponse(&ibytes,rbytes,recvbuf,os1,os2,os3,os4);
					if (resp == RESPONSE_GOODBYE)
					{
						if(rs_param.statemachine_debug>2)
							printf("Received expected GOODBYE from %s",rhost->name);
					}
				}
      }      
      closeSocket(rhost);
		}
  }
  return (void *)0;
}

void resetRequest(tmpnRemoteHost* remotehost)
{
  remotehost->sndbuf_idx=0;
}

int buildRequest(tmpnRemoteHost* remotehost,char *s, int lim)
{
  int i;
  for (i=0;i<lim;i++)
  {
    if (s[i]!='\0')
    {
      remotehost->sndbuf[remotehost->sndbuf_idx++]=s[i];
    }
    else break;
  }
  remotehost->sndbuf[remotehost->sndbuf_idx]='\0';
  return remotehost->sndbuf_idx;
}

int openSocket(char *remoteHost, int port)
{
  int clientSocket,
    remotePort,
    status = 0;
  struct hostent *hostPtr = NULL;
  struct sockaddr_in serverName = { 0 };

  remotePort = port;

  clientSocket = socket(PF_INET, SOCK_STREAM, 
												IPPROTO_TCP);
  if (-1 == clientSocket)
  {
    perror("socket()");
    return -1;
  }

  /*
   * need to resolve the remote server name or 
   * IP address */
  hostPtr = gethostbyname(remoteHost);
  if (NULL == hostPtr)
  {
    hostPtr = gethostbyaddr(remoteHost, 
														strlen(remoteHost), AF_INET);
    if (NULL == hostPtr)
    {
      perror("Error resolving server address");
			close(clientSocket);
      return -1;
    }
  }
  
  serverName.sin_family = AF_INET;
  serverName.sin_port = htons(remotePort);
  (void) memcpy(&serverName.sin_addr, 
								hostPtr->h_addr,
								hostPtr->h_length);
  
  status = connect(clientSocket, 
									 (struct sockaddr*) &serverName,
									 sizeof(serverName));
  if (-1 == status)
  {
    perror("openSocket()");
		close(clientSocket);
    return -1;
  }
  return clientSocket;
}

void closeSocket(tmpnRemoteHost* remotehost)
{
  close(remotehost->sockfd);
  remotehost->sockfd=-1;
}

int sendRequest(tmpnRemoteHost* remotehost)
{
  struct timeval tv;
  fd_set readfds;
  int retselect;
  int rbytes=0;
  

  //only send if something in sndbuffer
  if (remotehost->sndbuf_idx>0) 
  {
    if(rs_param.statemachine_debug>2)
      printf("sendRequest sndbuf_idx %i sndbuf: %35s\n",remotehost->sndbuf_idx,remotehost->sndbuf);
    if (send(remotehost->sockfd, remotehost->sndbuf, remotehost->sndbuf_idx, 0) == -1)
    {
      perror("sendRequest()");
    }
  }
  tv.tv_sec = STMCLIENT_TIMEOUT;
  tv.tv_usec = 0;
  FD_ZERO(&readfds);
  FD_SET(remotehost->sockfd, &readfds);

  /* don't care about writefds and exceptfds: */
  retselect = select(remotehost->sockfd+1, &readfds, NULL, NULL, &tv);
  if(retselect<=0)
  {
    if(rs_param.statemachine_debug>2)
      printf("timeout\n");
    return -1;
  }
  if (FD_ISSET(remotehost->sockfd, &readfds))
  {
    /* read from the given socket */
    rbytes=read(remotehost->sockfd, recvbuf, STMCLIENT_RECVBUFFER-1);
    if(rbytes<=0)
    {
      if(rs_param.statemachine_debug>2)
				printf("readerror\n");
      return -1;
    }
    recvbuf[rbytes]='\0'; // Null termination
    return rbytes;
  }
  if(rs_param.statemachine_debug>2)
    printf("dont go here!\n");
  return -1;
}
