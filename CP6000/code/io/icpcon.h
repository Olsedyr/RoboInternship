#ifndef __ICPCON_H
#define __ICPCON_H

/* icpcon.c prototypes */
#ifdef __cplusplus
extern "C" int openIcpconSocket(char *host, int port);
extern "C" int build_IcpRequest(int type, int address, int data, char *array);
extern "C" int sendIcpcon(int type, int address,int *data,int sfd);
extern "C" void initICPconTasks(tmpnWorkcell *workcell);
extern "C" void *icpconTask(void *arg);
#else
int openIcpconSocket(char *host, int port);
int build_IcpRequest(int type, int address, int data, char *array);
int sendIcpcon(int type, int address,unsigned int *data,int sfd);
void initICPconTasks(tmpnWorkcell *workcell);
void *icpconTask(void *arg);
#endif

#endif /* __ICPCON_H */
