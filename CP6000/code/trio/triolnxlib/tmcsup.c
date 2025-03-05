#include "tmclnx.h"

long WriteData(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten)
{
   LONG  rc;
   
   switch (controller[iIndex].controllerinfo.fControllerType)
   {
      default:
         return 0;      
#ifdef TMC_SERIAL
      case ControllerTypeSerial:
         rc = SERIALWriteData(iIndex, pchCommand, cbCommand, pulBytesWritten);
         break;
#endif
#ifdef TMC_ETHERNET
      case ControllerTypeEthernet:
         rc = ETHERNETWriteData(iIndex, pchCommand, cbCommand, pulBytesWritten);
         break;
#endif
   }

#ifdef TMC_DEBUG
   TMCTrace("   Bytes written <%ld>.\n", *pulBytesWritten);
   TMCTrace("Leaving WriteData.\n");
#endif   
   return rc;
}

long ReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead)
{
   LONG  rc;
   
   switch (controller[iIndex].controllerinfo.fControllerType)
   {
      default:
         return 0;      
#ifdef TMC_SERIAL
      case ControllerTypeSerial:
         rc = SERIALReadData(iIndex, pchResponse, cbResponse, pulBytesRead);
         break;
#endif
#ifdef TMC_ETHERNET
      case ControllerTypeEthernet:
         rc = ETHERNETReadData(iIndex, pchResponse, cbResponse, pulBytesRead);
         break;
#endif
   }

#ifdef TMC_DEBUG
   TMCTrace("   Bytes read <%ld>.\n", *pulBytesRead);
   TMCTrace("Leaving ReadData.\n");
#endif   
   return rc;
}

int CharAvailableInput(int iIndex)
{
   switch (controller[iIndex].controllerinfo.fControllerType)
   {
      default:
         return 0;      
#ifdef TMC_SERIAL
      case ControllerTypeSerial:
         return SERIALCharAvailableInput(iIndex);
#endif
#ifdef TMC_ETHERNET
      case ControllerTypeEthernet:
         return ETHERNETCharAvailableInput(iIndex);
#endif
   }
}

void /* __cdecl*/ TMCTrace(char* pFormat, ...)
{
	va_list  pArgList;
	FILE*    fileTrace;

/*
    va_start(pArgList, pFormat);
		vfprintf(stdout, pFormat, pArgList);
		va_end(pArgList);
		fflush(stdout);
*/
  if (!szFileTrace[0])
		return;
	
	fileTrace = fopen(szFileTrace, "a");
	if (fileTrace)
	{
		va_start(pArgList, pFormat);
		vfprintf(fileTrace, pFormat, pArgList);
		va_end(pArgList);
		fflush(fileTrace);
		fclose(fileTrace);
	}
}

//
//	Purpose	:	Set main index to controler
//	
//	Returns	:	zero based index to our device else -1 on error
//
int AddIndex(	PCONTROLLERINFO pcontrollerinfo	)
{
	int   i;
	
	for (i = 0; i < MAX_CONTROLLERS; i++)
	{
		if (!controller[i].fInUse)
	  {
	  	controller[i].fInUse = 1;
	    controller[i].fBinaryCommand = 0;
	    controller[i].controllerinfo.cbSize = pcontrollerinfo->cbSize;
	    controller[i].controllerinfo.usModelID = pcontrollerinfo->usModelID;
	    controller[i].controllerinfo.fControllerType = pcontrollerinfo->fControllerType;
	    controller[i].controllerinfo.ulTimeout = pcontrollerinfo->ulTimeout;
	    controller[i].controllerinfo.ulDelay = pcontrollerinfo->ulDelay;
	    controller[i].controllerinfo.pid = pcontrollerinfo->pid;
	     
	    switch (controller[i].controllerinfo.fControllerType)
	    {
	      case ControllerTypeSerial:
	         memcpy(&(controller[i].controllerinfo.hardwareinfo.serialinfo),
	            &(pcontrollerinfo->hardwareinfo.serialinfo), sizeof(SERIALINFO));
	         break;
	      case ControllerTypeEthernet:
	         memcpy(&(controller[i].controllerinfo.hardwareinfo.socketinfo),
	            &(pcontrollerinfo->hardwareinfo.socketinfo), sizeof(SOCKETINFO));
	         break;
	    }
	     
	    return i;
	  }
  }
	return -1;
}

//
//	Purpose	:	remove main index to controler
//	
//	Returns	:	zero based index to our device else -1 on error
//
int DeleteIndex(int iIndex)
{
   if ((iIndex >= 0) && (iIndex < MAX_CONTROLLERS))
   {
      if (controller[iIndex].fInUse)
         memset(&(controller[iIndex]), '\0', sizeof(CONTROLLERINFO));
      return 0;
   }
   return -1;
}

//
//	Purpose	:	Retrieve index based upon handle
//	
//	Returns	:	zero based index to our device else -1 on error
//
int Handle2Index(HANDLETMC hdmc)
{
	int i = (int)(hdmc - 1L);

  if ((i >= 0) && (i < MAX_CONTROLLERS))
  {
  	if (controller[i].fInUse)
    	return i;
  }

  return -1;
}

//
//	Purpose	:	Set main index to controler
//	
//	Returns	:	zero based index to our device else -1 on error
//
HANDLETMC Index2Handle(int iIndex)
{
	return (HANDLETMC)(iIndex + 1);
}

#ifdef __BORLANDC__
#define Timeb   timeb
#define BTime   biostime
#define Ftime   ftime
#else
#define Timeb   _timeb
#define BTime   _biostime
#define Ftime   _ftime
#endif

/* Return the time of the day in milliseconds */
ULONG TMCGetTime(void)
{
	return clock();
  //ULONG     ulMilliSeconds;
  //clock_t   time;
  //time = clock();
  //ulMilliSeconds = time/*(ULONG)((double)time / (double)(CLOCKS_PER_SEC / 1000))*/;
 	// return ulMilliSeconds;
}

