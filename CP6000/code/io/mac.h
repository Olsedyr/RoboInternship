#ifndef __MAC_H
#define __MAC_H

#define MAX_MACTALK_DATALEN 20

#define BAD 0
#define GOOD 1

#define WRITE 0
#define WRITE16 1
#define WRITE16U 2
#define READ 3
#define ACCEPT 4
#define CMD 5


typedef struct MacTalkPacket
{
	int type;     //read or write
	int address;
	int regnum;
	union {
		int data;
		short int sdata;
		short unsigned int udata;
	};
} MacTalkPacket;


/* mac.c prototypes */
#ifdef __cplusplus
extern "C" int openMactalkSocket(char *host, int port);
extern "C" int build_MacRequest(MacTalkPacket *mtp, char *array);
extern "C" int get_MacRequest(char *array, MacTalkPacket *mtp, int type);
extern "C" int sendMactalk(MacTalkPacket *request, MacTalkPacket *answer, tmpnMac *mac);
extern "C" void makeSendPack(MacTalkPacket *sendpack, macConnect *mccon);
extern "C" void parseGetPack(MacTalkPacket *getpack, macConnect *mccon);
extern "C" void initMacTasks(tmpnWorkcell *workcell);
extern "C" void *macTask(void *arg);
#else
int openMactalkSocket(char *host, int port);
int build_MacRequest(MacTalkPacket *mtp, char *array);
int get_MacRequest(char *array, MacTalkPacket *mtp, int type);
int sendMactalk(MacTalkPacket *request, MacTalkPacket *answer, tmpnMac *mac);
void makeSendPack(MacTalkPacket *sendpack, macConnect *mccon);
void parseGetPack(MacTalkPacket *getpack, macConnect *mccon);
void initMacTasks(tmpnWorkcell *workcell);
void *macTask(void *arg);
#endif

#endif /* __MAC_H */
