/***************************************************************************
                          vision.c  -  description
                             -------------------
    begin                : ons nov 5 2003
    copyright            : (C) 2003 by MPN A/S - Guided by vision(R) Lars M Sandig
    email                : lms@mpn.nu
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/times.h>
#include <sys/time.h>
#include <pthread.h>

#include <unistd.h>
#include "rs.h"

#define MAXFRMPERPOS 2 // Antal frame pr position (kommunikations performance problem)

#define PORT 3490 // the port client will be connecting to

#define MAXDATASIZE 640 // max number of bytes we can get at once

#define MAXFRAME 75

#define WAIT_FOR_PROFILE 0
#define GET_PROFILE      1

#define MAX_PROFILE_LEN   MAXFRAME-1
#define MIN_PROFILE_LEN   5

#define MAXCAPWIN         10
#define MINFRAMEDIST      10 //10mm pr sample

typedef struct PROFILESTRUCT
{
  int profile[MAXDATASIZE];
  int convpos;
} PROFILESTRUCT;

typedef struct CAPWINSTRUCT
{
  PROFILESTRUCT profiles[MAXFRAME];
  int profile_len;
} CAPWINSTRUCT;

static volatile int GUIDED_BY_VISION = FALSE;

pthread_cond_t capwin_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t capwin_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t getbag_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t getbag_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bagready_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t bagready_mtx = PTHREAD_MUTEX_INITIALIZER;

volatile visionstructure vicam = {0, 0, "192.168.0.51", 250, 5, 5};    
  
volatile static int in_buffer = 0;
volatile static long conveyorpos = 0;

int state = WAIT_FOR_PROFILE;
int profile = 0;

volatile CAPWINSTRUCT capwin[MAXCAPWIN];

int GuidedByVision(int state)
{
  int old = GUIDED_BY_VISION;

  if(state < 0)
    return GUIDED_BY_VISION;
    
  GUIDED_BY_VISION = state;
  return old;
}

static void InitCapWin(void)
{
  int i,j;

  for(i=0;i<MAXCAPWIN;i++)
  {
    for(j=0;j<MAXFRAME;j++)
      memset((void*)&capwin[i].profiles[j], 0, sizeof(PROFILESTRUCT));
  }
}

void *visionTask(void *argument)
{
  int capwinnum = 0;
  int sockfd, numbytes,i;
  socklen_t* addr_len;
  int gfrm=0;
  int over;
  int PROFILE_DONE = 0;
  struct hostent *he;
  struct sockaddr_in vision_addr; // connector's address information
  int fps = 0, tid = times(NULL);
  int clkprsec = sysconf(_SC_CLK_TCK);
  float posdiff = 0.0;
  int oldconvpos = 0;

  InitCapWin();

  if(LoadVisionParam()==FALSE)
  {
    SaveVisionParam();
  }

//  conveyorpos = GetConvPos();
  
  for(;;)
  {
    if(GUIDED_BY_VISION)
    {
      if ((he=gethostbyname((const char*)vicam.camip)) != NULL) // get the host info
      {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) != -1)
        {
          vision_addr.sin_family = AF_INET;    // host byte order
          vision_addr.sin_port = htons(PORT);  // short, network byte order
          vision_addr.sin_addr = *((struct in_addr *)he->h_addr);
          memset(&(vision_addr.sin_zero), '\0', 8);  // zero the rest of the struct

          if (connect(sockfd, (struct sockaddr *)&vision_addr, sizeof(struct sockaddr)) != -1)
          {
            vicam.connected = 1;

            switch(state)
            {
              case WAIT_FOR_PROFILE:
                gfrm = MAXFRMPERPOS;
                profile = 0;
                PROFILE_DONE = 0;
                break;
            }

            addr_len = (socklen_t*)sizeof(struct sockaddr);
            if ((numbytes=recvfrom(sockfd,(char*)&capwin[capwinnum].profiles[profile].profile[0], (MAXDATASIZE-1)*4, 0,
                       NULL, addr_len)) == -1)
            {
              perror("recvfrom");
            }

            close(sockfd);
            fps++;

            /* Check if this is a profile */
            over=0;
            for(i=1;i<capwin[capwinnum].profiles[profile].profile[0];i++)
              if(capwin[capwinnum].profiles[profile].profile[i]<vicam.minimum)
                over++;

            if(gfrm > MAXFRMPERPOS)
            {
              oldconvpos = conveyorpos;
//              conveyorpos = GetConvPos();
              posdiff = (conveyorpos-oldconvpos)/gfrm;
              gfrm = 0;
            }
        //    else
        //      conveyorpos += posdiff;

            gfrm++;

            if(RobotState())
            {
              if(over > vicam.minwidth)
              {
                state = GET_PROFILE;

                // change when communication performance is ok. - lms
                ///////////////////////////////////////////////////////////////
          //      if(RobotState()&&gfrm >= MAXFRMPERPOS)
        //        if(gfrm >= MAXFRMPERPOS)
                {
        //          conveyorpos = GetConvPos();
                  // interpoler pos imellem positioner
        /*
                  posdiff = (conveyorpos - capwin[capwinnum].profiles[profile-MAXFRMPERPOS].convpos)/MAXFRMPERPOS;

                  if(profile > MAXFRMPERPOS)
                  {
                    for(i=profile-MAXFRMPERPOS-1;i<profile;i++)
                    {
                      capwin[capwinnum].profiles[i].convpos = capwin[capwinnum].profiles[i-1].convpos + posdiff;
                    }
                  }
        */
                }
                capwin[capwinnum].profiles[profile].convpos = conveyorpos;
                //////////////////////////////////////////////////////////////

                profile++;

                if(profile > MAXFRMPERPOS &&
                   abs(capwin[capwinnum].profiles[profile-2].convpos-capwin[capwinnum].profiles[profile-1].convpos) < MINFRAMEDIST)
                   profile--;

                if(profile > MAX_PROFILE_LEN)
                {
                  PROFILE_DONE = 1;
                  capwin[capwinnum].profile_len = profile-1;
                  state = WAIT_FOR_PROFILE;
                  profile = 0;
                  gfrm = MAXFRMPERPOS;
                }
              }
              else
              {
                if(state==GET_PROFILE)
                {
                  if(profile >= vicam.minlen)
                  {
                    PROFILE_DONE = 1;
                    capwin[capwinnum].profile_len = profile-1;
                  }
                  profile = 0;
                  gfrm = MAXFRMPERPOS;
                }
                state = WAIT_FOR_PROFILE;
              }
            }

            if(PROFILE_DONE)
            {
              PROFILE_DONE=0;

        //      printf("%d, %d\n",capwin[capwinnum].profiles[capwin[capwinnum].profile_len].convpos, capwinnum);
        //      for(i=0;i<=capwin[capwinnum].profile_len;i++)
        //        printf("position %d\n", capwin[capwinnum].profiles[i].convpos);

              if(capwinnum < MAXCAPWIN-1)
                capwinnum++;
              else
                capwinnum=0;

              in_buffer++;

              pthread_cond_signal(&capwin_cond);
            }

            if(times(NULL)-tid >= clkprsec)
            {
              vicam.fps = fps;
              fps = 0;
              tid = times(NULL);
            }
          }
          else
          {
            printf("Connection to vision failed...\n");
            vicam.connected = 0;
            vicam.fps = 0;
            usleep(1000000);
          }
        }
        else
        {
          printf("Socket failed...\n");
          vicam.connected = 0;
          vicam.fps = 0;
          usleep(1000000);
        }
      }
      else
      {
        printf("Gethostbyname failed...\n");
        vicam.connected = 0;
        vicam.fps = 0;
        usleep(1000000);
      }
    }  
    else
    {
      usleep(5000000); // wait 5 sec. and check again.
      /// DEBUG ONLY
      capwin[capwinnum].profile_len = 0;
//      capwin[capwinnum].profiles[0].convpos = GetConvPos();
      if(capwinnum < MAXCAPWIN-1)
        capwinnum++;
      else
        capwinnum=0;

      in_buffer++;
      pthread_cond_signal(&capwin_cond);
      /// DEBUG END
    }
  }
  return 0;
}

int LoadVisionParam(void)
{
  visionstructure tvicam;
  FILE *fp;
  char filename[256];
  sprintf(filename,"%s/system/vision.dat",rs_systempath);

  if((fp = fopen(filename, "r"))==NULL)
  {
    return FALSE;
  }

  fread(tvicam.camip, sizeof(tvicam.camip), 1, fp);
  fread(&tvicam.minimum , sizeof(tvicam.minimum), 1, fp);
  fread(&tvicam.minlen, sizeof(tvicam.minlen), 1, fp);
  fread(&tvicam.minwidth, sizeof(tvicam.minwidth), 1, fp);
  fclose(fp);

  strcpy((char*)vicam.camip, tvicam.camip);
  vicam.minimum = tvicam.minimum;
  vicam.minlen = tvicam.minlen;
  vicam.minwidth = tvicam.minwidth;

  return TRUE;
}

int SaveVisionParam(void)
{
  FILE *fp;
  visionstructure tvicam;
  char filename[256];

  strcpy(tvicam.camip, (const char*)vicam.camip);
  tvicam.minimum = vicam.minimum;
  tvicam.minlen = vicam.minlen;
  tvicam.minwidth = vicam.minwidth;
  
  sprintf(filename,"%s/system/vision.dat",rs_systempath);

  if((fp = fopen(filename, "w"))==NULL)
  {
    return FALSE;
  }
  fwrite(tvicam.camip, sizeof(tvicam.camip), 1, fp);
  fwrite(&tvicam.minimum, sizeof(tvicam.minimum), 1, fp);
  fwrite(&tvicam.minlen, sizeof(tvicam.minlen), 1, fp);
  fwrite(&tvicam.minwidth, sizeof(tvicam.minwidth), 1, fp);
  fclose(fp);

  return TRUE;
}

void GetLeastSquaresValues(int numPts, float *X, float *Y, float *mvalue, float *bvalue)
{
  float A = 0.0;
  float B = 0.0;
  float C = 0.0;
  float D = 0.0;
  int i;

// Compute the sums
  for(i=0;i<numPts;i++)
  {
    A += (X[i]*X[i]);
    B += X[i];
    C += (X[i]*Y[i]);
    D += Y[i];
  }
  *mvalue = (B * D - C * numPts) / (B * B - A * numPts);
  *bvalue = (B * C - A * D) / (B * B - A * numPts);
}

void *conveyorTask(void *argument)
{
  int retcode;
    
  int capwinnum = 0;
  float xprofile[2*MAX_PROFILE_LEN];
  float yprofile[2*MAX_PROFILE_LEN];
  float mvalue, bvalue;
  float x1, x2, y1, y2;
  float center_x, center_y, angle;
  int pp = 0, y = 0, p;
  int lh, lhp, lhy, j;
    
  pthread_cond_init(&capwin_cond, NULL);
  pthread_cond_init(&bagready_cond, NULL);

  for(;;)
  {
    if(in_buffer==0)
    {
      retcode = pthread_cond_wait(&capwin_cond, &capwin_mtx);
    }
    if(in_buffer > 0)
    {
      in_buffer--;

      y=0;
      lh = 10000;
      lhp = 0;
      lhy = 0;
      pp = 0;
      for(p=0;p<capwin[capwinnum].profile_len;p++)
      {
        for(j=1;j<capwin[capwinnum].profiles[p].profile[0];j++)
        {
          if(capwin[capwinnum].profiles[p].profile[j]<vicam.minimum)
          {
            xprofile[pp] = j-1;
            yprofile[pp] = y;
            j = capwin[capwinnum].profiles[p].profile[0];
          }
        }
        pp++;
        for(j=capwin[capwinnum].profiles[p].profile[0]-1;j>1;j--)
        {
          if(capwin[capwinnum].profiles[p].profile[j]<vicam.minimum)
          {
            xprofile[pp] = j-1;
            yprofile[pp] = y;
            j = 0;
          }
        }
        pp++;
        y+=4;
      }

      GetLeastSquaresValues(pp, yprofile, xprofile, &mvalue, &bvalue);

      y1 = yprofile[0];
      y2 = y1;

      for(j=1;j<pp;j++)
      {
        if(y1 < yprofile[j]) y1 = yprofile[j];
        if(y2 > yprofile[j]) y2 = yprofile[j];
      }

      x1 = (mvalue * y1) + bvalue;
      x2 = (mvalue * y2) + bvalue;

      center_x = (x1 + x2)/2.0;
      center_y = (y1 + y2)/2.0;

      if((x2 - x1)!=0)
        angle = atan2((y2 - y1),(x2 - x1));

//      printf("X %f Y %f V %f\n", center_x, center_y, angle);
      
      // calculate conveyor stop.
//      ModifyConveyorPos((float)(capwin[capwinnum].profiles[capwin[capwinnum].profile_len].convpos-trobot->m_frames[visionTrans].z), capwinnum); 
//      printf("ModifyConveyorPos %f %d\n", capwin[capwinnum].profiles[capwin[capwinnum].profile_len].convpos-trobot.m_frames[visionTrans].z, capwinnum);
      if(capwinnum < MAXCAPWIN-1)
        capwinnum++;
      else
        capwinnum=0;
    }
  }
}
