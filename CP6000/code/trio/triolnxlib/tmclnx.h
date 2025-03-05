#ifndef INCLUDE_TMCCOM
#define INCLUDE_TMCCOM

#include <sys/time.h>
#include <sys/param.h>
//#include <asm/system.h>
#include <bits/types.h>

#include <ctype.h>
#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TMC_DEBUG               //Enable debug trace

// Serial communications
#define TMC_SERIAL                /* Enable base serial communications */

// Ethernet communications
#define TMC_ETHERNET

// Advanced communications options
//#define DMC_BINARYCOMMANDS      	// Enable binary command interface (DMC-1200/DMC-1600/DMC-1700/DMC-1800/DMC-2000 only)
//#define DMC_FIRMWARE            	// Enable firmware updates (DMC-1200/DMC-1600/DMC-1700/DMC-1800/DMC-2000 only)
//#define DMC_DATARECORDACCESS   	 	// Enable data record access (DMC-1600/DMC-1700/DMC-1800 only)
//#define DMC_DATARECORDACCESSQR  	// Enable data record access for controllers which can use the QR command

#ifdef __cplusplus
   extern "C" {
#endif

#define FAR
#define PASCAL

/* Common data types */
typedef short int SHORT;
typedef short int FAR* PSHORT;
typedef unsigned short int USHORT;
typedef unsigned short int FAR* PUSHORT; 
typedef long int LONG; 
typedef long int FAR* PLONG;
typedef unsigned long int ULONG;
typedef unsigned long int FAR* PULONG;
typedef char CHAR; 
typedef char FAR* PCHAR; 
typedef char SZ;
typedef char FAR* PSZ;
typedef char BYTE;
typedef unsigned char UCHAR;
typedef unsigned char FAR* PBYTE;
typedef void VOID;
typedef void FAR* PVOID;

typedef unsigned int UINT;
typedef unsigned short WORD;
typedef unsigned long DWORD;

/* Trio data types */

/* Handle to Trio controller - returned by TMCOpen and used as input
   to most API functions */
typedef SHORT HANDLETMC;
typedef HANDLETMC FAR* PHANDLETMC;

/* API calling convention - when you link, turn-off case
   sensitivity */
#define TRIOCALL PASCAL

/* Controller model constants */
#define MC224   "MC224"

#define MODEL_UNKNOWN          0
#define MODEL_224              224

// Structure and memory defines - modify these to adjust memory usage
#ifndef MAX_PATH
   #define MAX_PATH            256
#endif   
#define COMMAND_BUFFER_SIZE    255
#define RESPONSE_BUFFER_SIZE   1024
#define MAX_CONTROLLERS        4

// Misc defines
#define DEFAULT_TIMEOUT        5000
#define DEFAULT_DELAY          0
#ifndef TRUE
   #define TRUE                1
#endif
#ifndef FALSE
   #define FALSE               0
#endif

// Errors
#define TMCNOERROR                    0
#define TMCWARNING_MONITOR            1

#define TMCERROR_TIMEOUT              -1
#define TMCERROR_COMMAND              -2
#define TMCERROR_CONTROLLER           -3
#define TMCERROR_FILE                 -4
#define TMCERROR_DRIVER               -5
#define TMCERROR_HANDLE               -6
#define TMCERROR_HMODULE              -7
#define TMCERROR_MEMORY               -8
#define TMCERROR_BUFFERFULL           -9
#define TMCERROR_RESPONSEDATA         -10
#define TMCERROR_DMA                  -11 
#define TMCERROR_ARGUMENT             -12
#define TMCERROR_DATARECORD           -13
#define TMCERROR_DOWNLOAD             -14
#define TMCERROR_FIRMWARE             -15
#define TMCERROR_CONVERSION           -16
#define TMCERROR_RESOURCE             -17
#define TMCERROR_REGISTRY             -18
#define TMCERROR_BUSY                 -19
#define TMCERROR_DEVICE_DISCONNECTED  -20

// Constant values

// Constant values for data record data types
//#include "dmcdrc.h"

// Constant values for hardware structures
enum TMCControllerTypes
{
   ControllerTypeSerial = 0,     /* RS-232 serial communications controller */
   ControllerTypeEthernet = 1    /* Ethernet controller */
};

enum TMCSerialHandshake
{
   SerialHandshakeNone = 0,      /* No handshake */
   SerialHandshakeHardware = 1,  /* Hardware handshake (RTS/CTS) */
   SerialHandshakeSoftware = 2   /* Software handshake (XOn/XOff) - not implemented yet */
};

enum TMCDataRecordAccess
{
   DataRecordAccessNone = 0,     /* No data record access capability or data record access is off */
   DataRecordAccessDMA = 1,      /* Use DMA for data record access */
   DataRecordAccessFIFO = 2      /* Use FIFO for data record access */
};

enum TMCEthernetProtocol
{
   EthernetProtocolTCP = 0,
   EthernetProtocolUDP = 1
};

// Ethernet flags
#define ETH_NO_MULTICAST         0x0001   /* Do not open a multi-cast session */
#define ETH_UNSOLICITEDMESSAGES  0x0002   /* Open an unsolicited message session */

// Structures

// Hardware info - ISA and PCI bus
typedef struct _BUSINFO
{
	USHORT  usDevice;             /* Device number [0-3] */
	USHORT  usAddress;            /* I/O port address */
	USHORT  usAddress2;           /* I/O port address for PCI status register */
	USHORT  usInterrupt;          /* Interrupt */
	USHORT  fDataRecordAccess;    /* Data record access type */
	USHORT  usRefreshRate;        /* Data record refresh rate in 2^usRefreshRate ms */
	USHORT  usDMAChannel;         /* DMA channel - for DMC-1700 only */
	USHORT  fIOStyle;             /* I/O Style - for Galil use only */
	USHORT  fInterruptStyle;      /* Interrupt style - for Galil use only */
	ULONG   ulReserved1;          /* Reserved for future use */
	ULONG   ulReserved2;          /* Reserved for future use */
} BUSINFO;

// Hardware info - serial communications
typedef struct _SERIALINFO
{
   USHORT  usCommPort;           /* Communications port */
   ULONG   ulCommSpeed;          /* Communications speed */
   USHORT  fHandshake;           /* Communications handshake */
   USHORT  usReserved1;          /* Reserved for future use */
   USHORT  usReserved2;          /* Reserved for future use */
} SERIALINFO;

// Hardware info - serial communications
typedef struct _SOCKETINFO
{
   ULONG   ulPort;               /* Host port number - for Galil use only */
   CHAR    szIPAddress[32];      /* Host name string */
   USHORT  fProtocol;            /* UDP or TCP */
   ULONG   fFlags;               /* Controls auto opening of multi-cast and unsolicited message sessions */
   ULONG   ulReserved1;          /* Reserved for future use */
   ULONG   ulReserved2;          /* Reserved for future use */
} SOCKETINFO;

// Hardware info for CONTROLLERINFO struct
typedef union _HARDWAREINFO
{
   BUSINFO     businfo;
   SERIALINFO  serialinfo;
   SOCKETINFO  socketinfo;
} HARDWAREINFO;

// Structure used define controller info
typedef struct _CONTROLLERINFO
{
   USHORT         cbSize;          // Structure size
   USHORT         usModelID;       // Model ID of the Galil controller
   USHORT         fControllerType; // Controller type (ISA bus, PCI bus, serial, etc.)
   ULONG          ulTimeout;       // Time-out in milliseconds
   ULONG          ulDelay;         // Delay in milliseconds
   ULONG          ulSerialNumber;  // Serial number
   ULONG          ulRelativeNumber;// relative number on the bus
   pid_t          pid;             // Process ID
   HARDWAREINFO   hardwareinfo;    // Union defining the hardware characteristics of the controller
} CONTROLLERINFO, FAR* PCONTROLLERINFO;

// Function prototypes
// All functions return an error code. DMCNOERROR (0) is function completed
// successfully. Error code < 0 is a fatal error. Error code > 0 is a warning.
// General functions for all controllers

extern LONG FAR TRIOCALL TMCInitLibrary(void);
// Initialize the library.  This function MUST be called before using the library.

extern LONG FAR TRIOCALL TMCOpen(PCONTROLLERINFO pcontrollerinfo, PHANDLETMC phtmc);
/* Open communications with the TRIO controller. The handle to the TRIO
   controller is returned in the argument phdmc.

   pcontrollerinfo   Galil controller information. Users should declare a
                     variable of type CONTROLLERINFO, fill-in the necessary values,
                     and pass the address of the variable to the function.
   phdmc             Buffer to receive the handle to the Galil controller to be
                     used for all subsequent API calls. Users should declare a
                     variable of type HANDLEDMC and pass the address of the
                     variable to the function. Output only. */

extern LONG FAR TRIOCALL TMCClose(HANDLETMC hdmc);
/* Close communications with the Galil controller.

   hdmc              Handle to the Galil controller. */

extern LONG FAR TRIOCALL TMCCommand(HANDLETMC hdmc, PSZ pszCommand,
   PCHAR pchResponse, ULONG cbResponse);
/* Send a DMC command in ascii format to the Galil controller.

   hdmc              Handle to the Galil controller.
   pszCommand        The command to send to the Galil controller.
   pchResponse       Buffer to receive the response data. If the buffer is too
                     small to recieve all the response data from the controller,
                     the error code DMCERROR_BUFFERFULL will be returned. The
                     user may get additional response data by calling the
                     function DMCGetAdditionalResponse. The length of the
                     additonal response data may ascertained by call the
                     function DMCGetAdditionalResponseLen. If the response
                     data from the controller is too large for the internal
                     additional response buffer, the error code
                     DMCERROR_RESPONSEDATA will be returned. Output only.
   cbResponse        Length of the buffer. */

extern LONG FAR TRIOCALL TMCBinaryCommand(HANDLETMC hdmc, PBYTE pbCommand, ULONG ulCommandLength,
   PCHAR pchResponse, ULONG cbResponse);
/* Send a DMC command in binary format to the Galil controller.

   hdmc              Handle to the Galil controller.
   pbCommand         The command to send to the Galil controller in binary.
   ulCommandLength   The length of the command (binary commands are not null-terminated).
   pchResponse       Buffer to receive the response data. If the buffer is too
                     small to recieve all the response data from the controller,
                     the error code DMCERROR_BUFFERFULL will be returned. The
                     user may get additional response data by calling the
                     function DMCGetAdditionalResponse. The length of the
                     additonal response data may ascertained by call the
                     function DMCGetAdditionalResponseLen. If the response
                     data from the controller is too large for the internal
                     additional response buffer, the error code
                     DMCERROR_RESPONSEDATA will be returned. Output only.
   cbResponse        Length of the buffer. */

extern LONG FAR TRIOCALL TMCGetUnsolicitedResponse(HANDLETMC hdmc,
   PCHAR pchResponse, ULONG cbResponse);
/* Query the Galil controller for unsolicited responses. These are messages
   output from programs running in the background in the Galil controller.
   The data placed in the user buffer (pchResponse) is NULL terminated.
   NOTE: This function requires that the CW property be set to 1. The DMC
   command CW1 makes bit 7 high for characters in all messages which originate
   from the controller. This is how the library is able to distinguish between
   responses from commands (foreground) and messages from the controller
   (background). The DMC command CW2 disables this action.

   hdmc              Handle to the Galil controller.
   pchResponse       Buffer to receive the response data.
   cbResponse        Length of the buffer. */

extern LONG FAR TRIOCALL TMCWriteData(HANDLETMC hdmc,
   PCHAR pchBuffer, ULONG cbBuffer, PULONG pulBytesWritten);
/* Low-level I/O routine to write data to the Galil controller. Data is written
   to the Galil controller only if it is "ready" to receive it. The function
   will attempt to write exactly cbBuffer characters to the controller.
   NOTE: For Win32 and WinRT driver the maximum number of bytes which can be
   written each time is 64. There are no restrictions with the Galil driver. 

   hdmc              Handle to the Galil controller.
   pchBuffer         Buffer to write the data from.
   cbBuffer          Length of the buffer.
   pulBytesWritten   Number of bytes written. */

extern LONG FAR TRIOCALL TMCReadData(HANDLETMC hdmc,
   PCHAR pchBuffer, ULONG cbBuffer, PULONG pulBytesRead);
/* Low-level I/O routine to read data from the Galil controller. The routine
   will read what ever is currently in the FIFO (bus controller) or
   communications port input queue (serial controller). The function will read
   up to cbBuffer characters from the controller. The data placed in the 
   user buffer (pchBuffer) is NOT NULL terminated. The data returned is not
   guaranteed to be a complete response - you may have to call this function
   repeatedly to get a complete response.
   NOTE: For Win32 and WinRT driver the maximum number of bytes which can be
   read each time is 64. There are no restrictions with the Galil driver. 

   hdmc              Handle to the Galil controller.
   pchBuffer         Buffer to read the data into.
   cbBuffer          Length of the buffer.
   pulBytesRead      Number of bytes read. */

extern LONG FAR TRIOCALL TMCGetAdditionalResponseLen(HANDLETMC hdmc,
   PULONG pulResponseLen);
/* Query the Galil controller for the length of additional response data. There
   will be more response data available if the DMCCommand function returned
   DMCERROR_BUFFERFULL.

   hdmc              Handle to the Galil controller.
   pulResponseLen    Buffer to receive the additional response data length.
                     Output only. */

extern LONG FAR TRIOCALL TMCGetAdditionalResponse(HANDLETMC hdmc,
   PCHAR pchResponse, ULONG cbResponse);
/* Query the Galil controller for more response data. There will be more
   response data available if the DMCCommand function returned
   DMCERROR_BUFFERFULL. Once this function is called, the internal
   additonal response buffer is cleared.

   hdmc              Handle to the Galil controller.
   pchResponse       Buffer to receive the response data. Output only.
   cbResponse        Length of the buffer. */

extern LONG FAR TRIOCALL TMCError(HANDLETMC hdmc, LONG lError, PCHAR pchMessage,
   ULONG cbMessage);
/* Retrieve the error message text from a DMCERROR_COMMAND error.

   hdmc              Handle to the Galil controller.
   pchMessage        Buffer to receive the error message text. Output only.
   cbMessage         Length of the buffer. */

extern LONG FAR TRIOCALL TMCClear(HANDLETMC hdmc);
/* Clear the Galil controller FIFO.

   hdmc              Handle to the Galil controller. */

extern LONG FAR TRIOCALL TMCReset(HANDLETMC hdmc);
/* Reset the Galil controller.

   hdmc              Handle to the Galil controller. */

extern LONG FAR TRIOCALL TMCMasterReset(HANDLETMC hdmc);
/* Master reset the Galil controller.

   hdmc              Handle to the Galil controller. */

extern LONG FAR TRIOCALL TMCVersion(HANDLETMC hdmc, PCHAR pchVersion,
   ULONG cbVersion);
/* Get the version of the Galil controller.

   hdmc              Handle to the Galil controller.
   pchVersion        Buffer to receive the version information. Output only.
   cbVersion         Length of the buffer. */

extern LONG FAR TRIOCALL TMCDownloadFile(HANDLETMC hdmc, PSZ pszFileName,
   PSZ pszLabel);
/* Download a file to the Galil controller.

   hdmc              Handle to the Galil controller.
   pszFileName       File name to download to the Galil controller.
   pszLabel          Program label to download to. This argument is ignored if
                     NULL. */
extern LONG FAR TRIOCALL TMCSendFile(HANDLETMC hdmc, PSZ pszFileName);
/* Send a file consisting of DMC commands in ascii format to the Galil controller.

   hdmc              Handle to the Galil controller.
   pszFileName       File name to send to the Galil controller. */

/* Binary communications functions for the DMC-1200, DMC-1600, DMC-1700, DMC-1800, and DMC-2000. */


extern LONG FAR TRIOCALL TMCGetTimeout(HANDLETMC hdmc, LONG FAR* pTimeout);
/* Get current time-out value. The default is 1000.

   hdmc              Handle to the Galil controller.
   pTimeout          Buffer to receive the current time-out value in
                     milliseconds. Output only. */

extern LONG FAR TRIOCALL TMCSetTimeout(HANDLETMC hdmc, LONG lTimeout);
/* Set time-out value. The default is 1000. If the time-out value is set to
   zero, the DLLs will ignore time-out errors. This is useful for sending
   Galil commands which do not return a response, such as providing records
   to the DL or QD commands.

   hdmc              Handle to the Galil controller.
   lTimeout          Time-out value in milliseconds. */

extern LONG FAR TRIOCALL TMCAssignIPAddress(PCONTROLLERINFO pcontrollerinfo, int fVerbose);
/* Assign the IP Address to a DMC-2100 or DMC-1415 Ethernet controller. The controller
   must be in BOOTP broadcast mode.

   pcontrollerinfo   Galil controller information. Users should declare a
                     variable of type CONTROLLERINFO, fill-in the ulSerialNumber
                     and hardwareinfo.socketinfo.szIPAddress of the controller
                     to be assigned an IP address, and pass the address of the
                     variable to the function.
   fVerbose          Verbose mode if TRUE */

#ifdef __cplusplus
   }
#endif

/* Low-level and intermediate routines */
#include "tmcsup.h"

#endif /* INCLUDE_TMCCOM */
