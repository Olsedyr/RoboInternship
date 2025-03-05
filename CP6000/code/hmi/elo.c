/* Elo touch and Micro Touch library functions */
/* L.M.Sandig (lms@mpn.nu) */
#include <fcntl.h>
#include <time.h>
#include <ctype.h>
#include <termio.h>
#include <stdio.h>
#include <unistd.h>
//#include "rs.h"
#include "Bx.h"
#include "BxEvent.h"
#include "hmi.h"
#include "cmd.h"

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

extern BX_BOOL BxInsertMouseEvent(BX_WORD state, BX_WORD xpos, BX_WORD ypos);
int set_up_comms(void);

static struct termio tnew,tsaved;
static int ttyfd;               
static int iState = 0;
static unsigned int rawx=0, rawy=0, rawz=0;
static float elo_cal_x = 1.0;
static float elo_cal_y = 1.0;
static int elo_cal_x_offset = 0;
static int elo_cal_y_offset = 0;
static int buttonState = 0;

int GetTouchXOffset(void)
{
  return elo_cal_x_offset;
}

int GetTouchYOffset(void)
{
  return elo_cal_y_offset;
}

float GetTouchXFactor(void)
{
  return elo_cal_x;
}

float GetTouchYFactor(void)
{
  return elo_cal_y;
}

void SetTouchCalibrationOffset(int xoff, int yoff)
{
  elo_cal_x_offset = xoff;
  elo_cal_y_offset = yoff;
}
void SetTouchCalibration(float xcal, float ycal)
{
  if(xcal!=0.0)
    elo_cal_x = xcal;
  if(ycal!=0.0)
    elo_cal_y = ycal;
}
void SetRawX(int x)
{
  rawx = x;
}

void SetRawY(int y)
{
  rawy = y;
}

void SetRawZ(int z)
{
  rawz = z;
}

unsigned int GetRawX(void)
{
  return rawx;
}

unsigned int GetRawY(void)
{
  return rawy;
}

unsigned int GetRawZ(void)
{
  return rawz;
}

int GetCalcX(void)
{
  return (int)(elo_cal_x * (float)((int)rawx-elo_cal_x_offset));
}

int GetCalcY(void)
{
  return (int)(elo_cal_y * (float)((int)rawy-elo_cal_y_offset));
}

void *EGalaxTask(void *arg)
{
  unsigned char c = 0, buf[12];
  unsigned char state;
  int x, y;

  /* setup communication parameters */
//  set_up_comms();

  for(;;)
  {
    if(read(ttyfd,&c,1)==1)
    {
      switch(iState) {
        case 0:
          if(c&0x80)
          {
            buf[0] = c;
            iState = 1;
          }
          else
            iState = 0;
        break;
        case 1:
          buf[1] = c;
          iState++;
          break;
        case 2:
          buf[2] = c;
          iState++;
          break;
        case 3:
          buf[3] = c;
          iState++;
          break;
        case 4:
          buf[4] = c;
          state = buf[0] & 0x01;
          if(buttonState==1&&state==1)
            buttonState = 2;
          if(buttonState==4&&state==1)
            buttonState = 1;
          if(state == 0)
            buttonState = 4;  

          rawx = (buf[1])<<7 | buf[2];
          x = (int)(elo_cal_x * (float)((int)rawx-elo_cal_x_offset));

          rawy = (buf[3])<<7 | buf[4];
          y = (int)(elo_cal_y * (float)((int)rawy-elo_cal_y_offset));

	  //	  printf("0x%02x, %i %i\n",c,rawx,rawy);
      
          BxInsertMouseEvent(buttonState, x, y);
          BxSetEvent();
          
          iState=0;
          break;
      }
    }    

	}

	//	ioctl(ttyfd,TCSETA,&tsaved); 
	//	close(ttyfd);

}  


void *EloTask(void *arg)
{
  unsigned char c = 0, buf[12];
  unsigned char state;
  int x, y, z;

  /* setup communication parameters */
//  set_up_comms();

  for(;;)
  {
    if(read(ttyfd,&c,1)==1)
    {
      switch(iState) {
				case 0:
					if(c==0x55)
					{
						buf[0] = c;
						iState = 1;
					}
					break;
				case 1:
					if(c==0x54)
					{
						buf[1] = c;
						iState = 2;
					}
					else
						iState = 0;
     break;
				case 2:
					buf[2] = c;
					iState++;
					break;
				case 3:
					buf[3] = c;
					iState++;
					break;
				case 4:
					buf[4] = c;
					iState++;
					break;
				case 5:
					buf[5] = c;
					iState++;
					break;
				case 6:
					buf[6] = c;
					iState++;
					break;
				case 7:
					buf[7] = c;
					iState++;
					break;
				case 8:
					buf[8] = c;
					iState++;
					break;
				case 9:
					buf[9] = c;
					state = buf[2];
          rawx = buf[4]<<8 | buf[3];
          x = (unsigned int)(elo_cal_x * (float)(rawx-elo_cal_x_offset));
          rawy = buf[6]<<8 | buf[5];
          y = (unsigned int)(elo_cal_y * (float)(rawy-elo_cal_y_offset));
					rawz = z = buf[8]<<8 | buf[7];
					iState =0;
          BxInsertMouseEvent(state, x, y);
					BxSetEvent();
					break;
			}
    }

	}

	//	ioctl(ttyfd,TCSETA,&tsaved);
	//	close(ttyfd);

}


int set_up_comms_for_snooping(void)
{

	ttyfd = open(rs_param.touch.port, O_RDWR);

	tcflush(ttyfd, TCIOFLUSH);

	ioctl(ttyfd,TCGETA,&tsaved); 

	tnew.c_iflag = IGNBRK | IGNPAR;
	tnew.c_oflag = 0;
	tnew.c_lflag = 0;
	tnew.c_line  = 0;
	tnew.c_cc[VTIME] = 100;
	tnew.c_cc[VMIN]  = 0;

	tnew.c_cflag = CS8 | CSTOPB | CREAD | CLOCAL | HUPCL | B9600;

	ioctl(ttyfd,TCSETA,&tnew); 

	ioctl(ttyfd,TCFLSH,0);   /*  clear serial input  buffer */ 

	return 0;
}

int set_up_comms(void)
{

	ttyfd = open(rs_param.touch.port, O_RDWR);

	tcflush(ttyfd, TCIOFLUSH);

	ioctl(ttyfd,TCGETA,&tsaved); 

	tnew.c_iflag = IGNBRK | IGNPAR;
	tnew.c_oflag = 0;
	tnew.c_lflag = 0;
	tnew.c_line  = 0;
	tnew.c_cc[VTIME] = 0;
	tnew.c_cc[VMIN]  = 1;

	tnew.c_cflag = CS8 | CSTOPB | CREAD | CLOCAL | HUPCL | B9600;

	ioctl(ttyfd,TCSETA,&tnew); 

	ioctl(ttyfd,TCFLSH,0);   /*  clear serial input  buffer */ 

	return 0;
}

int testForEGalax(void)
{
  char cmd[16], rtn[16];

  cmd[0] = 0x0A;
  cmd[1] = 1;
  cmd[2] = 'A';
  write(ttyfd,cmd,3);
  if(read(ttyfd,rtn,3)==3)
  {
    if(strncmp(cmd, rtn,3)==0)
    {
      printf("EGalax found.\n");
      cmd[0] = 0x0A;
      cmd[1] = 1;
      cmd[2] = 'D';
      write(ttyfd,cmd,3);
      if(read(ttyfd,rtn,16)!=0)
      {
        rtn[2+rtn[1]] = '\0';
        printf("firmware %s\n", &rtn[3]);
      }
      cmd[0] = 0x0A;
      cmd[1] = 1;
      cmd[2] = 'E';
      write(ttyfd,cmd,3);
      if(read(ttyfd,rtn,16)!=0)
      {
        printf("%s\n", &rtn[3]);
      }
      return TOUCH_EGLX;
    }
  }
  return 0;
}

int FindTouchCtrl(void)
{
  printf("Looking for touch controller...\n");
  set_up_comms_for_snooping();

  if(testForEGalax()!=0)
  {
    set_up_comms();
    printf("eGalaxy touch controller found on %s.\n",rs_param.touch.port);
    return TOUCH_EGLX;
  }

  set_up_comms();
  printf("No touch controller found, default == elo on %s.\n",rs_param.touch.port);
  return TOUCH_ELO;
}
