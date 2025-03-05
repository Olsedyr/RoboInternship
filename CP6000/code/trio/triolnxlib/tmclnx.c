#include "tmclnx.h"

/* Global variables */
CHAR szTempCommand[COMMAND_BUFFER_SIZE];
CHAR szTempResponse[RESPONSE_BUFFER_SIZE];
CHAR szFileTrace[MAX_PATH];
CONTROLLER controller[MAX_CONTROLLERS];

LONG FAR TRIOCALL TMCInitLibrary()
{
   // Initialize all global variables
   memset(szTempCommand, '\0', sizeof(szTempCommand));
   memset(szTempResponse, '\0', sizeof(szTempResponse));
   memset(szFileTrace, '\0', sizeof(szFileTrace));
   memset(controller, '\0', sizeof(controller));

   return 0L;
}

//
// Purpose 	:	Main entry point for Galil controled open
//
LONG FAR TRIOCALL TMCOpen(PCONTROLLERINFO pcontrollerinfo, PHANDLETMC phdmc)
{
	LONG  rc = 0L;
  int   iIndex;

#ifdef TMC_DEBUG
  TMCTrace("Entering TMCOpen.\n");
#endif

  // Check arguments
  if (!pcontrollerinfo || !phdmc)
  {
#ifdef TMC_DEBUG
  	TMCTrace("   One or more arguments is NULL or 0.\n");
    TMCTrace("Leaving TMCOpen.\n");
#endif
    return TMCERROR_ARGUMENT;
  }

  // check struct size
  if (pcontrollerinfo->cbSize != sizeof(CONTROLLERINFO))
  {
#ifdef TMC_DEBUG
  	TMCTrace("   The CONTROLLERINFO structure is invalid.\n");
    TMCTrace("Leaving TMCOpen.\n");
#endif
    return TMCERROR_ARGUMENT;
  }

  *phdmc = -1;

  iIndex = AddIndex(pcontrollerinfo);
  if (iIndex == -1)
  {
#ifdef TMC_DEBUG
  	TMCTrace("   All available controller handles are in use.\n");
    TMCTrace("Leaving TMCOpen.\n");
#endif
   	return TMCERROR_CONTROLLER;
  }

  if (iIndex == TMCERROR_MEMORY)
  {
#ifdef TMC_DEBUG
  	TMCTrace("   Out of memory.\n");
    TMCTrace("Leaving TMCOpen.\n");
    return TMCERROR_MEMORY;
#endif
  }

#ifdef TMC_DEBUG
  TMCTrace("   Added index <%d>.\n", iIndex);
#endif

  // Create a controller handle
  *phdmc = Index2Handle(iIndex);
#ifdef TMC_DEBUG
  TMCTrace("   Generated controller handle <%d>.\n", *phdmc);
#endif

	switch ( pcontrollerinfo->fControllerType )
	{
		case ControllerTypeSerial:
	  	rc = OpenPort(iIndex);
  	  if (rc)
   	 	{
#ifdef TMC_DEBUG
    		TMCTrace("   Could not open serial port.\n");
      	TMCTrace("Leaving TMCOpen.\n");
#endif
      	return rc;
  		}	break;

		case ControllerTypeEthernet:
	  	rc = OpenSocket(iIndex);
	    if (rc)
	    {
#ifdef TMC_DEBUG
	    	TMCTrace("   Could not open socket.\n");
	      TMCTrace("Leaving TMCOpen.\n");
#endif
	      return rc;
		  }
  }

  ULONG ulBytes;
  // Empty the FIFO
  rc = ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytes);

  // Check to see if we are in the monitor - the controller's OS
/*
  {
      int   i;
      ULONG ulCurrentTime;
      ULONG ulTimeout;
      ULONG ulBytes;

      // Empty the FIFO
      rc = ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytes);

			//if ( rc )
      for (i = 0; i < 5; i++)
      {
         rc = WriteData(iIndex, ";", 1, &ulBytes);

         ulCurrentTime = TMCGetTime();
         ulTimeout = ulCurrentTime + 1000;

         do
         {
            szTempResponse[0] = '\0';
            ulCurrentTime = TMCGetTime();
            if (ulCurrentTime > ulTimeout)
               rc = TMCERROR_TIMEOUT;
            else
               rc = ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytes);
            if (szTempResponse[0] == '\r')
               strcpy(szTempResponse, &szTempResponse[1]);
            if (szTempResponse[0] == '\n')
               strcpy(szTempResponse, &szTempResponse[1]);
         } while ((szTempResponse[0] != ':' && szTempResponse[0] != '?' && szTempResponse[0] != '>') && (rc == 0));

         // If a ? is returned, do it one more time 
         if (szTempResponse[0] != '?')
            break;
      }

      if (szTempResponse[0] == '>')
      {
#ifdef TMC_DEBUG
         TMCTrace("   Warning: The controller is in the monitor.\n");
         TMCTrace("Leaving TMCOpen.\n");
#endif
         return TMCWARNING_MONITOR;
      }
   }
*/
   // Reset the FIFO (this will also check communications) 
   rc = TMCClear(*phdmc);

   // Clear any remaining characters 
   if (CharAvailableInput(iIndex))
   {
      ULONG ulBytesRead;
      ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytesRead);
      memset(controller[iIndex].szResponse, '\0', sizeof(controller[iIndex].szResponse));
      memset(controller[iIndex].szUnsolicitedResponse, '\0', sizeof(controller[iIndex].szUnsolicitedResponse));
   }

   // Turn echo off 
   TMCCommand(*phdmc, "EO0\r", szTempResponse, sizeof(szTempResponse));

#ifdef TMC_DEBUG
   TMCTrace("Leaving TMCOpen.\n");
#endif

   return rc;
}

LONG FAR TRIOCALL TMCClose(HANDLETMC hdmc)
{
   LONG  rc = 0L;
   int   iIndex;

#ifdef TMC_DEBUG
   TMCTrace("Entering TMCClose.\n");
#endif

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
   {
#ifdef TMC_DEBUG
      TMCTrace("   Invalid handle.\n");
      TMCTrace("Leaving TMCClose.\n");
#endif
      return TMCERROR_HANDLE;
   }

#ifdef TMC_SERIAL
   if (controller[iIndex].controllerinfo.fControllerType == ControllerTypeSerial)
      ClosePort(iIndex);
#endif /* TMC_SERIAL */

#ifdef TMC_ETHERNET
   if (controller[iIndex].controllerinfo.fControllerType == ControllerTypeEthernet)
      CloseSocket(iIndex);
#endif /* TMC_ETHERNET */

   DeleteIndex(iIndex);
#ifdef TMC_DEBUG
   TMCTrace("   Deleted index <%d>.\n", iIndex);
#endif

#ifdef TMC_DEBUG
   TMCTrace("Leaving TMCClose.\n");
#endif
   return rc;
}


LONG FAR TRIOCALL TMCReadData(HANDLETMC hdmc, PCHAR pchBuffer,
   ULONG cbBuffer, PULONG pulBytesRead)
{
   LONG  rc = 0L;
   int   iIndex;

   if (!pchBuffer || !cbBuffer || !pulBytesRead)
      return TMCERROR_ARGUMENT;

   *pulBytesRead = 0;

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
      return TMCERROR_HANDLE;

   rc = ReadData(iIndex, pchBuffer, cbBuffer, pulBytesRead);

#ifdef TMC_DEBUG
   if (*pulBytesRead && cbBuffer < RESPONSE_BUFFER_SIZE)
   {
      char  szTemp[RESPONSE_BUFFER_SIZE];
      strncpy(szTemp, pchBuffer, (size_t)(cbBuffer - 1));
      szTemp[(size_t)(cbBuffer - 1)] = '\0';
      TMCTrace("TMCReadData: Data read <%s>.\n", szTemp);
   }
   TMCTrace("TMCReadData: Bytes read <%ld>.\n", *pulBytesRead);
#endif

   return rc;
}

LONG FAR TRIOCALL TMCWriteData(HANDLETMC hdmc, PCHAR pchBuffer,
   ULONG cbBuffer, PULONG pulBytesWritten)
{
   LONG  rc = 0L;
   int   iIndex;

   if (!pchBuffer || !cbBuffer || !pulBytesWritten)
      return TMCERROR_ARGUMENT;

   *pulBytesWritten = 0;

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
      return TMCERROR_HANDLE;

   rc = WriteData(iIndex, pchBuffer, cbBuffer, pulBytesWritten);

#ifdef TMC_DEBUG
   if (*pulBytesWritten && cbBuffer < COMMAND_BUFFER_SIZE)
   {
      char  szTemp[COMMAND_BUFFER_SIZE];
      strncpy(szTemp, pchBuffer, (size_t)(cbBuffer - 1));
      szTemp[(size_t)(cbBuffer - 1)] = '\0';
      TMCTrace("TMCWriteData: Data written <%s>.\n", szTemp);
   }
   TMCTrace("TMCWriteData: Bytes written <%ld>.\n", *pulBytesWritten);
#endif

   return rc;
}


LONG FAR TRIOCALL TMCGetTimeout(HANDLETMC hdmc, PLONG pulTimeout)
{
   LONG  rc = 0L;
   int   iIndex;

#ifdef TMC_DEBUG
   TMCTrace("Entering TMCGetTimeout.\n");
#endif

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
   {
#ifdef TMC_DEBUG
      TMCTrace("   Invalid handle.\n");
      TMCTrace("Leaving TMCGetTimeout.\n");
#endif
      return TMCERROR_HANDLE;
   }

   if (!pulTimeout)
   {
#ifdef TMC_DEBUG
      TMCTrace("   Time-out is NULL.\n");
      TMCTrace("Leaving TMCGetTimeout.\n");
#endif
      return TMCERROR_ARGUMENT;
   }

   *pulTimeout = controller[iIndex].controllerinfo.ulTimeout;

#ifdef TMC_DEBUG
   TMCTrace("Leaving TMCGetTimeout.\n");
#endif
   return rc;
}

//
//
//
LONG FAR TRIOCALL TMCCommand(HANDLETMC hdmc, PSZ pszCommand, PCHAR pchResponse,ULONG cbResponse)
{
	LONG  rc = 0L;
	LONG  saverc = 0L;
	int   iIndex;
	ULONG ulCurrentTime;
	ULONG ulTimeout;
	ULONG ulBytesRead;
	ULONG ulBytesWritten;
	int   iCommands = 0;
	int   iResponses = 0;
	char* pch;
	char* pchTempResponse = NULL;
#ifdef TMC_DEBUG
	TMCTrace("Entering TMCCommand.\n");
#endif

	iIndex = Handle2Index(hdmc);
	if (iIndex == -1)
	{
#ifdef TMC_DEBUG
	  TMCTrace("   Invalid handle.\n");
	  TMCTrace("Leaving TMCCommand.\n");
#endif
	  return TMCERROR_HANDLE;
	}

	controller[iIndex].fBinaryCommand = 0;
#ifdef TMC_ETHERNET
	controller[iIndex].fReadMulticast = 0;
#endif

	// NOTE: the length of pszCommand must be less than COMMAND_BUFFER_SIZE - 2

	// Create a default command if none exists
	if (pszCommand && *pszCommand)
	{
	  strncpy(szTempCommand, pszCommand, sizeof(szTempCommand) - 2);
	  if (szTempCommand[strlen(szTempCommand)-1] != '\r' && szTempCommand[strlen(szTempCommand)-1] != ';')
	     strcat(szTempCommand, "\r");
	}
	else
	  strcpy(szTempCommand, "\r");

#ifdef TMC_DEBUG
	TMCTrace("   Command <%s>.\n", szTempCommand);
#endif

	// Use a temporary response buffer if none exists
	if (pchResponse && cbResponse)
	  pchTempResponse = pchResponse;
	else
	{
	  pchTempResponse = szTempResponse;
	  cbResponse = sizeof(szTempResponse);
	}

	// Clear any remaining characters from previous command - note that any unsolicited responses
	// will be buffered in szUnsolicitedResponse
	if (CharAvailableInput(iIndex))
	  ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytesRead);

	*pchTempResponse = '\0';

	// Count how many commands are to be sent
	for (pch = strchr(szTempCommand, ':'); pch; pch = strchr(pch, ':'))
	{
	  iCommands++;
	  pch++;
	}

	for (pch = strchr(szTempCommand, '\r'); pch; pch = strchr(pch, '\r'))
	{
	  iCommands++;
	  pch++;
	}

	// The controller does not send a response for the DL command; also, the user may have input a
	//  pure number in response to the IN command
/*
  if (!strncmp(szTempCommand, "DL", 2) 	||
			!strncmp(szTempCommand, "UL", 2) 	||
			!strncmp(szTempCommand, "LS", 2) 	||
			isdigit(*szTempCommand) 					||
			*szTempCommand == '-')
	  iCommands--;
*/
  rc = WriteData(iIndex, szTempCommand, strlen(szTempCommand), &ulBytesWritten);
	if (rc || ulBytesWritten == 0)
	{
#ifdef TMC_DEBUG
	  TMCTrace("  A timeout ocurred waiting for the controller to recieve the command.\n");
	  TMCTrace("Leaving TMCCommand.\n");
#endif
	  return rc;
	}

	rc = 0L;

	memset(controller[iIndex].szResponse, '\0',  sizeof(controller[iIndex].szResponse));

	if (controller[iIndex].controllerinfo.ulTimeout)
	{
	  ulCurrentTime = TMCGetTime();
	  ulTimeout = ulCurrentTime + controller[iIndex].controllerinfo.ulTimeout;
	}

	// Wait until a response is received or a timeout occurs
	while (!CharAvailableInput(iIndex) && !rc)
	{
	  // If time-out is 0, ignore time-out errors
	  if (controller[iIndex].controllerinfo.ulTimeout)
	  {
	     ulCurrentTime = TMCGetTime();
	     if (ulCurrentTime > ulTimeout)
	        rc = TMCERROR_TIMEOUT;
	  }
	  else
	     break;
	}

	if (rc)
	{
#ifdef TMC_DEBUG
	  TMCTrace("  A timeout ocurred waiting for a response from the controller.\n");
	  TMCTrace("Leaving TMCCommand.\n");
#endif
	  return rc;
	}

	if (controller[iIndex].controllerinfo.ulTimeout)
	{
	  ulCurrentTime = TMCGetTime();
	  ulTimeout = ulCurrentTime + controller[iIndex].controllerinfo.ulTimeout;
	}

	// Delay the read
	/*
	if (controller[iIndex].controllerinfo.ulDelay)
	  sleep(controller[iIndex].controllerinfo.ulDelay / 1000);
	*/

	// Receive the response
	do
	{
	  rc = ReadData(iIndex, pchResponse, cbResponse, &ulBytesRead);

	  // Looking for the prompt ">>"
  	iResponses = 0;
    for (pch = strchr(pchResponse, '>'); pch; pch = strchr(pch, '>'))
    {
      iResponses++;
      pch++;
    }
    if (iResponses >= 2)
    	break;

    if (rc)
	     saverc = rc;

	  if (rc == 0 || rc == TMCERROR_BUFFERFULL)
	  {
	     if (!ulBytesRead)
	     {
	        // Do not wait for a response because time-out is zero
	        if (!controller[iIndex].controllerinfo.ulTimeout)
	        {
	           saverc = 0;
	           rc = 0;
	           break;
	        }
	        // Check clock
	        ulCurrentTime = TMCGetTime();
	        if (ulCurrentTime > ulTimeout)
	           rc = TMCERROR_TIMEOUT;
	     }
	     else
	     {
	        // Reset clock
	        if (controller[iIndex].controllerinfo.ulTimeout)
	        {
	           ulCurrentTime = TMCGetTime();
	           ulTimeout = ulCurrentTime + controller[iIndex].controllerinfo.ulTimeout;
		      }
      }
    }
	} while ((rc == 0 || rc == TMCERROR_BUFFERFULL));

	if (saverc)
	  rc = saverc;

	// Do no report time-out errors on program listing
/*
  if (!strncmp(szTempCommand, "LS", 2))
	{
	  if (rc == TMCERROR_TIMEOUT)
	     rc = 0L;
	}
*/
	// User wants to ignore time-out errors
	if (rc == TMCERROR_TIMEOUT && !controller[iIndex].controllerinfo.ulTimeout)
	  rc = 0L;


  if (pchResponse && *pchResponse)
	{
    //remove echo
    strcpy(pchResponse, &pchResponse[ulBytesWritten+1]);

    if (!strncmp(pchResponse, "%", 1))
      rc = TMCERROR_COMMAND;
    else
    {
      //remove prompt  "\n\r>>"
      pchResponse[strlen(pchResponse)-2]='\0';
    }
  }


#ifdef TMC_DEBUG
	TMCTrace("   Response <%s>.\n", pchResponse);
	TMCTrace("Leaving TMCCommand.\n");
#endif

	return rc;
}

//
//
//
LONG FAR TRIOCALL TMCGetUnsolicitedResponse(HANDLETMC hdmc, PCHAR pchResponse, ULONG cbResponse)
{
   LONG  rc = 0L;
   int   iIndex;
   ULONG ulBytesRead = 0L;

#ifdef TMC_DEBUG
   TMCTrace("Entering TMCGetUnsolicitedResponse.\n");
#endif

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
   {
      rc = TMCERROR_HANDLE;
#ifdef TMC_DEBUG
      TMCTrace("   Invalid handle.\n");
      TMCTrace("Leaving TMCGetUnsolicitedResponse.\n");
#endif
      return rc;
   }

   if (!pchResponse || !cbResponse)
   {
#ifdef TMC_DEBUG
      TMCTrace("   One or more arguments is NULL or 0.\n");
      TMCTrace("Leaving TMCGetUnsolicitedResponse.\n");
#endif
      return TMCERROR_ARGUMENT;
   }

   /* See if more unsolicited response data is available */
   if (CharAvailableInput(iIndex))
      rc = ReadData(iIndex, szTempResponse, sizeof(szTempResponse), &ulBytesRead);

   strncpy(pchResponse, controller[iIndex].szUnsolicitedResponse, (size_t)(cbResponse - 1));

   if (cbResponse - 1 < strlen(controller[iIndex].szUnsolicitedResponse))
   {
      /* Shift the buffer */
      strcpy(controller[iIndex].szUnsolicitedResponse,
         &(controller[iIndex].szUnsolicitedResponse[(size_t)(cbResponse - 1)]));
   }
   else
   {
      /* Reset the buffer */
      memset(controller[iIndex].szUnsolicitedResponse, '\0',
         sizeof(controller[iIndex].szUnsolicitedResponse));
   }

#ifdef TMC_DEBUG
   TMCTrace("Leaving TMCGetUnsolicitedResponse.\n");
#endif
   return rc;
}

LONG FAR TRIOCALL TMCClear(HANDLETMC hdmc)
{
   LONG  rc = 0L;
   int   iIndex;

#ifdef TMC_DEBUG
   TMCTrace("Entering TMCClear.\n");
#endif

   iIndex = Handle2Index(hdmc);
   if (iIndex == -1)
   {
      rc = TMCERROR_HANDLE;
#ifdef TMC_DEBUG
      TMCTrace("   Invalid handle.\n");
      TMCTrace("Leaving TMCClear.\n");
#endif
      return rc;
   }

   switch (controller[iIndex].controllerinfo.fControllerType)
   {
      default:
         return 0;
#ifdef TMC_SERIAL
      case ControllerTypeSerial:
         rc = SERIALClear(iIndex);
         break;
#endif /* TMC_SERIAL */
#ifdef TMC_ETHERNET
      case ControllerTypeEthernet:
         rc = ETHERNETClear(iIndex);
         break;
#endif /* TMC_ETHERNET */
   }


    //Make sure communications are OK
/*
    {
  	   int   i;

   	   for (i = 0, rc = 1; rc != 0 && i < 5; i++)
   	      rc = TMCCommand(hdmc, "\r", szTempResponse, sizeof(szTempResponse));
  	}
*/
#ifdef TMC_DEBUG
   TMCTrace("Leaving TMCClear.\n");
#endif
   return rc;
}

