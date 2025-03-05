

#ifndef __LOADCELL_H
#define __LOADCELL_H

#define MAX_BEEBUS_DATALEN 100

#define BAD 0
#define GOOD 1
#define CHECKSUMERR 2

#define MCE9010 0x00
#define MCE9610 0x01
#define MCE2010 0x02
#define MCE9624 0x10
#define MCE9629 0x20

typedef struct BeebusPacket
{
	int lge;
	int dvn;
	int type;
	char data[MAX_BEEBUS_DATALEN];
	int bcc;
	struct BeebusPacket* next;
} BeebusPacket;


/* loadcell.c prototypes */
#ifdef __cplusplus
extern "C" int openBeebusSocket(char *host, int port);
extern "C" char calculate_lrc(BeebusPacket *bbp);
extern "C" int build_BeeRequest(BeebusPacket *bbp, char *array);
extern "C" int get_BeeRequest(char *array, BeebusPacket *bbp);
extern "C" int sendBeebus(BeebusPacket *request, BeebusPacket *answer, int sfd, int numOfCells);
extern "C" void beebusMakeDevicePollRequest(BeebusPacket *bp, int addr);
extern "C" int beebusParseDevicePollAnswer(BeebusPacket *bp, int addr);
extern "C" void beebusMakeLoadCellIdentifyRequest(BeebusPacket *bp, int addr);
extern "C" int beebusParseLoadCellIdentifyAnswer(BeebusPacket *bp, loadcellConnect *lcc, int addr);
extern "C" void beebusMakeMeasurementSampleRequest(BeebusPacket *bp);
extern "C" void beebusMakeSingleMeasurementRequest(BeebusPacket *bp, int addr);
extern "C" void beebusMakeMultipleMeasurementRequest(BeebusPacket *bp, int firstAddr, int noOfCells);
extern "C" int beebusParseMeasurementAnswer(BeebusPacket *bp, loadcellConnect* lcc, int addr, int errDisplay);
extern "C" void initLoadCellTasks(tmpnWorkcell *workcell);
extern "C" void *lcTask(void * arg );
#else
extern int openBeebusSocket(char *host, int port);
extern char calculate_lrc(BeebusPacket *bbp);
extern int build_BeeRequest(BeebusPacket *bbp, char *array);
extern int get_BeeRequest(char *array, BeebusPacket *bbp);
extern int sendBeebus(BeebusPacket *request, BeebusPacket *answer, int sfd, int numOfCells);
extern void beebusMakeDevicePollRequest(BeebusPacket *bp, int addr);
extern int beebusParseDevicePollAnswer(BeebusPacket *bp, int addr);
extern void beebusMakeLoadCellIdentifyRequest(BeebusPacket *bp, int addr);
extern int beebusParseLoadCellIdentifyAnswer(BeebusPacket *bp, loadcellConnect *lcc, int addr);
extern void beebusMakeMeasurementSampleRequest(BeebusPacket *bp);
extern void beebusMakeSingleMeasurementRequest(BeebusPacket *bp, int addr);
extern void beebusMakeMultipleMeasurementRequest(BeebusPacket *bp, int firstAddr, int noOfCells);
extern int beebusParseMeasurementAnswer(BeebusPacket *bp, loadcellConnect* lcc, int addr, int errDisplay);
extern void initLoadCellTasks(tmpnWorkcell *workcell);
extern void *lcTask(void * arg );
#endif

#endif /* __LOADCELL_H */
