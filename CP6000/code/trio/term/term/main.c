#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include "tmclnx.h"
#include "../../libmpnrobot/libmpnrobot/cmd.h"
//#include "dmcdrc.h"

void PrintError(long rc)
{
	printf("An error has occurred. Return code = %ld\n", rc);
	fflush(stdout);
}

void listerror()
{
	printf("List of all the API error codes: \n\n");
 printf("-1    Timeout Error       -2    Command Error\n");
	printf("-3    Controller Error    -4    File Error\n");
	printf("-5    Driver Error           -6   Handle Error\n");
	printf("-7    HModule Error	 -8    Memory Error\n");
	printf("-9    Buffer Full Error    -10  ResponseData Error\n");
	printf("-11  DMA Error              -12   Argument Error\n");
	printf("-13  Data Record Error  -14   Download Error\n");
	printf("-15  Firmware Error      -16   Conversion Error\n");
	printf("-17  Resource Error       -18   Registry Error\n");
	printf("-19  Controller Busy      -20   Device Disconnectted\n");
}

int getFotoFriMM(void)
{
  return 0;
}

int main(int argc, char* argv[])
{
	int            i, iDriver, temp;
	long           ltemp,rc = 0;      // Return code
	int            fInMotion = FALSE; // Motion complete flag
	char           buffer[4096] = "";  // Response from controller
	char           Command[40];
	USHORT         usStatus;
	HANDLETMC      hdmc = -1;         // Handle to controller
	CONTROLLERINFO controllerinfo;    // Controller information structure
	char           tempchar[4];
	long           timeout=1000;
	char           filename[32];
	char           label[8];
	char		  uresponse[256];
	int 		 n = 0, s, NotConnect = 0;
	ULONG	ibytes, obytes;
	fd_set 	rdfd;
	struct termios tc, oldTC;
	struct timeval timeout1 = {0, 100000};
	USHORT 	type1;
	long		out1;
	int 		ctype;
	char    	ipaddress[32];

	argc = argc;
	argv = argv;

//        printf("Galil Terminal Program for Linux Ver. 1.1.0\n\n");
//	printf("Galil Motion Control Inc. 7/2000\n\n");
//	memset(&controllerinfo, '\0', sizeof(controllerinfo));
//	printf("Please specify which type of controller you are using \n\n");
//	printf("1  for ETHERNET controllers\n");
//	printf("2  for SERIAL controllers\n");
//	scanf("%d", &ctype);
  ctype=1;
  switch(ctype)
  {
    case 1:
  printf("Please specify IP address:\n");
  scanf("%s", ipaddress);
//  sprintf(ipaddress,"192.168.0.250");
//      if(!LoadRSSystemData(&rs_param)) 
//      {
//        printf("IP address %s not found:\n",rs_param.mcIPaddr);		
//        return -1;
//      }
      strcpy(rs_param.mcIPaddr,ipaddress);
      controllerinfo.cbSize = sizeof(controllerinfo);
      controllerinfo.usModelID = MODEL_224;
      controllerinfo.fControllerType = ControllerTypeEthernet;
      controllerinfo.ulTimeout = 1000;
      controllerinfo.ulDelay = 5;
      controllerinfo.hardwareinfo.socketinfo.fProtocol = EthernetProtocolTCP;
      strcpy(controllerinfo.hardwareinfo.socketinfo.szIPAddress,rs_param.mcIPaddr);
      break;
		case 2:
			controllerinfo.cbSize = sizeof(controllerinfo);
			controllerinfo.usModelID = MODEL_224;
			controllerinfo.fControllerType = ControllerTypeSerial;
			controllerinfo.ulTimeout = 1000;
			controllerinfo.ulDelay = 0;
			controllerinfo.hardwareinfo.serialinfo.usCommPort = 1;
			controllerinfo.hardwareinfo.serialinfo.ulCommSpeed = 38400L;
			controllerinfo.hardwareinfo.serialinfo.fHandshake = SerialHandshakeHardware;
			break;
		default:
			printf("No controller specified, End the program. \n");
			return -1;
  };

  TMCInitLibrary();

  // Open the connection
  rc = TMCOpen( &controllerinfo, &hdmc );
  if (rc)
  {
    PrintError(rc);
    return rc;
  } 
  else 
  {
    printf("Connected to ip=%s with %s based controller, serial # %d \n"
    ,rs_param.mcIPaddr
    ,controllerinfo.fControllerType == ControllerTypeEthernet ? "Ethernet" : "Serial" 
    ,controllerinfo.ulSerialNumber);
  }

  rc = TMCGetTimeout(hdmc, &timeout);
  if (rc) PrintError(rc);

  tcgetattr(0, &tc);
  oldTC = tc;
  cfmakeraw(&tc);
  tcsetattr(0, TCSANOW, &tc);

  FD_ZERO(&rdfd);

  while (1)
  {
		rc = TMCGetUnsolicitedResponse(hdmc, uresponse, sizeof(uresponse));
		if (rc )
    {
			PrintError(rc);
		}
    else
    {
			if ( strcmp(uresponse,"")!=0)
      {
				printf("%s \n", uresponse);
			}
		}

		FD_SET(0, &rdfd);

		s = select(1, &rdfd, 0, 0, &timeout1);

		if (FD_ISSET(0, &rdfd) )
		{
			s = read(0,  &tempchar[n], 1);
			switch (tempchar[n])
			{
				case 1:   //CTR A, Testing purpose only
					tcsetattr(0, TCSANOW, &oldTC);
	  				//test(hdmc);

					/*
	  				printf("Testing API functions \n");

	  				printf("get data record using offset");
	  				printf("print out digital output 1...\n");
	  				rc = DMCRefreshDataRecord(hdmc, 10);

        if (rc) PrintError(rc);
	  				rc = DMCGetDataRecord(hdmc, 13, 0, &type1,&out1);
	  				if (rc) PrintError(rc);
	  				printf("here too!\n");
	  				else printf("Out put 1 is %d , the type is %d\n\n", out1,type1);

	  				printf("get data record using id");
	  				rc = DMCRefreshDataRecord(hdmc,10);
	  				rc = DMCGetDataRecordByItemId(hdmc, DRIdGeneralOutput0, 1,&type1, &out1);
	  				if (rc) PrintError(rc);
	  				else printf("Out put 1 is %d, the type is %d\n\n", out1, type1);
	  				*/

					tcsetattr(0, TCSANOW, &tc);

					break;
				case 3:	//CTR C, STOP PROGRAM
					tcsetattr(0, TCSANOW, &oldTC);
					rc = TMCClose(hdmc);
					if (rc)
					{
						PrintError(rc);
						return rc;
					}
					printf("\nThank you for using MPN TRIO terminal !\n");
					return 0L;
					break;
				case 8:     //^H, help
					tcsetattr(0, TCSANOW, &oldTC);
					printf("Linux Terminal Program, Version 1.0, 8/2000\n\n");
					printf("Help:  Extra Function Keys:\n\n");
					printf("^C to quit the program\n");
					tcsetattr(0, TCSANOW, &tc);
					n = 0;
					break;
				case 13:	//RETURN
					tempchar[n]='\r';
					rc = TMCWriteData(hdmc, tempchar,n+1, &ibytes);
					write(1,"\r\n",2);
					if (rc){ PrintError(rc);}
					n = 0;
					break;
				case 0x7f:  //DEL/
					if (n) {
						write(1, "\b \b", 3);
						n--;
					}
					break;
				default :
					//if (isprint(tempchar[0])){
					//if  (tempchar[n] == 18) write(1, "^R",2);
					//if (tempchar[n] == 19) write (1, "^S",2);
					//if (tempchar[n] == 22) write (1, "^V",2);
					write(1, &tempchar[n], 1);
					n++;
						  				//}
			}
		}

		usleep (timeout);
		rc = TMCReadData(hdmc, buffer, sizeof(buffer), &obytes);
		if (rc) PrintError(rc);
		if (obytes > 0){
			write (1,buffer,obytes);
			strcpy(buffer,"");
		}

	}

	rc = TMCClose(hdmc);
	if (rc)
	{
		PrintError(rc);
		return rc;
	}

	printf("\nDone\n");

	return 0L;
}
