#ifndef INCLUDE_TMCSUP
#define INCLUDE_TMCSUP

/* Conditional includes */

/* Serial communications */
#ifdef TMC_SERIAL
   #include "tmcser.h"
#endif

/* Ethernet communications */
#ifdef TMC_ETHERNET
   #include "tmceth.h"
#endif

/* For advanced communications */
/*
#ifdef DMC_BINARYCOMMANDS
   #include "dmcbin.h"
#endif
#ifdef DMC_FIRMWARE
   #include "dmcfmw.h"
#endif
#ifdef DMC_DATARECORDACCESS
   #include "dmcdma.h"
#endif
*/
#define MAX_DEVICES 4

#define OUTP   outp
#define INP    inp
#define OUTPW  outpw
#define INPW   inpw

typedef struct _CONTROLLER
{
   SHORT          fInUse;              /* Array member in use */
   SHORT          fBinaryCommand;      /* Is the command ASCII or binary */
   int            iDriver;
#ifdef TMC_DATARECORDACCESS   
   CHAR           usRevision;          /* Data Record Access revision */
   USHORT         usDataRecordSize;    /* Data record size */
   USHORT         usMaxGeneralOffset;  /* Max value for general offsets */
   USHORT         usMaxAxisOffset;     /* Max value for axis offsets */
   PBYTE          pbDataRecord;        /* Copy of data record for data record access */
   PBYTE          pTemp1;              /* Data record access temp storage */
   PBYTE          pTemp2;              /* Data record access temp storage */
#ifdef TMC_DMA 
   DMADATA        dmadata;             /* DMA info */
#endif /* DMC_DMA */   
#endif /* DMC_DATARECORDACCESS */
#ifdef TMC_ETHERNET
   SOCKET         socket;
   SOCKET         socketMulticast;
   SOCKET         socketMessages;
   ULONG          ulMessageSize;
   SHORT          fReadMulticast;
#endif /* DMC_ETHERNET */
   CHAR           szResponse[RESPONSE_BUFFER_SIZE];
   CHAR           szUnsolicitedResponse[RESPONSE_BUFFER_SIZE];
   CONTROLLERINFO controllerinfo;
} CONTROLLER, FAR* PCONTROLLER;   

/* Global variables */
extern CHAR szTempCommand[COMMAND_BUFFER_SIZE]; 
extern CHAR szTempResponse[RESPONSE_BUFFER_SIZE]; 
extern CHAR szFileTrace[MAX_PATH];
extern CONTROLLER controller[MAX_CONTROLLERS];

/* Libary utility functions */
extern int AddIndex(PCONTROLLERINFO pcontrollerinfo);
extern int DeleteIndex(int iIndex);
extern int Handle2Index(HANDLETMC hdmc);
extern HANDLETMC Index2Handle(int iIndex);
extern ULONG TMCGetTime(void);
extern void /*__cdecl*/ TMCTrace(char* pFormat, ...);

/* Library I/O rotuines */
extern long ReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
extern long WriteData(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
extern long Clear(void);
extern int CharAvailableInput(int iIndex);

#endif /* INCLUDE_DMCSUP */


