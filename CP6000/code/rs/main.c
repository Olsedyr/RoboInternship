//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/times.h>
#include <termio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/mman.h> // mlockall()
#ifdef SDL
#include <SDL/SDL.h>
#endif
#include "tmpnrobot.h"
#include "cmd.h"
#include "stm.h"
#include "rs.h"
#include "comsk.h"
#include "mac.h"
#include "icpcon.h"
#include "loadcell.h"
#include "Bx.h"
#include "form2pCal.h"
#include "formStartup.h"
#include "formHome.h"
#include "formStdRun.h"
#include "formDemo.h"
#include "formCW.h"
#include "formCP.h"
#include "formCM.h"
#include "form900.h"
#include "formTest.h"
#include "robostackerBxr.h"
#include "hmi.h"

//*****************************************************************************
//*  extern                                                                   *
//*****************************************************************************
extern void *stm_task(void * argument );
extern void *stmServer(void * argument );
extern void *trioStmTask(void * argument );
extern void *loaderTask(void * argument );
extern void *executerTask(void * argument );
extern void InitializeLoader(void);

//*****************************************************************************
//*  globals                                                                  *
//*****************************************************************************
char userid[256];
char password[256];
volatile int bxUpAndRunning=0;
extern int demo;
int accesslevel=OPERATORLEVEL; 
BxIcon *icon1,*icon2,*icon3,*icon4,*icon5,*iconreload,*iconscope;
//*****************************************************************************
//*  static                                                                   *
//*****************************************************************************
static unsigned long bx_update_freq = 100000;
//*****************************************************************************
//* mutex to protect startupsequence                                          *
//*****************************************************************************
pthread_mutex_t start_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int startupsequence=0;
//*****************************************************************************
//*  supervisorLogin                                                          *
//*****************************************************************************
//#define LOGOUTLEVEL         0 //Bx.h
//#define BROWSERLEVEL        1//Bx.h

//#define OPERATORLEVEL       2//Bx.h

//#define SERVICELEVEL        3//Bx.h

//#define MANAGERLEVEL        4 //Bx.h

//#define PROGRAMMERLEVEL     5 //Bx.h

//#define MAXLEVEL            6 //Bx.h

void setlevel(void)
{
  if(strcmp(userid,"operator")==0&&strcmp(password,"operator")==0) accesslevel=OPERATORLEVEL;
  if(strcmp(userid,"user")==0&&strcmp(password,"useruser")==0) accesslevel=SERVICELEVEL;
  if(strcmp(userid,"service")==0&&strcmp(password,"service")==0) accesslevel=SERVICELEVEL;
  if(strcmp(userid,"manager")==0&&strcmp(password,"manager")==0) accesslevel=MANAGERLEVEL;
  if(strcmp(userid,"mpn")==0&&strcmp(password,"sprit")==0) accesslevel=MANAGERLEVEL;
  if(strcmp(userid,"programmer")==0&&strcmp(password,"programmer")==0) accesslevel=PROGRAMMERLEVEL;
  if(strcmp(userid,"mpn")==0&&strcmp(password,"Rotten")==0) accesslevel=MAXLEVEL;
}

pthread_mutex_t exit_mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 ** mpnexit: Use when SDL also must be shutdown
 **/

void mpnexit(int returnval) 
{
	pthread_mutex_lock(&exit_mutex);
	printf("mpnexit %d\n",returnval);
#ifdef SDL
	SDL_Quit();
#endif
	exit(returnval);
}

void sigproc(int signal)
{
	mpnexit(0);
}

int supervisorLogin(HBOX hBox)
{
  //default to english during login
  char *oldlang = tworkcell->languages.language[tworkcell->languages.currentLanguage].name;
  selectLanguage((tmpnLanguages*)&tworkcell->languages, "English");
    
  if(BxVirtualKeyboard( hBox, "", 10)==IDOK)
  {
    strcpy(userid,BxVirtualKeyboard_GetString());
		BxVirtualKeyboard_LoginMode();
    if(BxVirtualKeyboard( hBox, "", 10)==IDOK)
    {
      strcpy(password,BxVirtualKeyboard_GetString());
    }
    //synonymer
		// if(strcmp(userid,"")==0) strcpy(userid,"user");
    //find level for alle kendte brugere
    accesslevel=OPERATORLEVEL;
		//    for(i=0;i<tworkcell->users.maxuser;i++)
		//    {
		//      if(strcmp(userid,tworkcell->users.user[i].id)==0&&strcmp(password,tworkcell->users.user[i].password)==0) 
		//        accesslevel=tworkcell->users.user[i].level;
		//       
		//    }
    setlevel();
    BxSetUserLevel(accesslevel);
  }
  selectLanguage((tmpnLanguages*)&tworkcell->languages, oldlang);
  return accesslevel;
}
//*****************************************************************************
//*  boxMain 
//*****************************************************************************
void *boxMain(void *t)
{
  INSTANCESTRUCT inst = {&formStdRun[0], FALSE, 0,};
  INSTANCESTRUCT instcw = {&formCW[0], FALSE, 0,};
  INSTANCESTRUCT instcp = {&formCP[0], FALSE, 0,};
  INSTANCESTRUCT instcm = {&formCM[0], FALSE, 0,};
  INSTANCESTRUCT inst900 = {&form900[0], FALSE, 0,};
  INSTANCESTRUCT insttest = {&formTest[0], FALSE, 0,};
  INSTANCESTRUCT instdemo = {&formDemo[0], FALSE, 0,};
  HBOX hBox;
	BxInitSystem();

  BxSetUserLevel(accesslevel);

  if(!rs_param.touch.initialized)
  {
    hBox = BxCreateDialog(&inst, &form2pCal[0], form2pCalProc);
    DoModal(hBox);
  }
  else
  {
    printf("2. ox=%d,oy=%d,fx=%f,fy=%f\n"
					 ,rs_param.touch.offx
					 ,rs_param.touch.offy
					 ,rs_param.touch.calx
					 ,rs_param.touch.caly); 
    
    SetTouchCalibration(rs_param.touch.calx, rs_param.touch.caly);
    SetTouchCalibrationOffset(rs_param.touch.offx, rs_param.touch.offy);
  }

  setlevel();
  if(strcmp(rs_param.mainDialog,"formStdRun")==0)
  //kun hvis robot
  {
    hBox = BxCreateDialog(&inst, &formStdRun[0], formStdRunProc);
		bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  } 
  else if(strcmp(rs_param.mainDialog,"formCW")==0)
  {
    hBox = BxCreateDialog(&instcw, &formCW[0], formCWProc);
		bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  } 
  else if(strcmp(rs_param.mainDialog,"formCP")==0)
  {
    hBox = BxCreateDialog(&instcp, &formCP[0], formCPProc);
		bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  }
  else if(strcmp(rs_param.mainDialog,"formCM")==0)
  {
    hBox = BxCreateDialog(&instcm, &formCM[0], formCMProc);
    bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  }
  else if(strcmp(rs_param.mainDialog,"form900")==0)
  {
    hBox = BxCreateDialog(&inst900, &form900[0], form900Proc);
    bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  }
  else if(strcmp(rs_param.mainDialog,"formTest")==0)
  {
    hBox = BxCreateDialog(&insttest, &formTest[0], formTestProc);
		bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  }
  else if(strcmp(rs_param.mainDialog,"formDemo")==0)
  {
    hBox = BxCreateDialog(&instdemo, &formDemo[0], formDemoProc);
		bxUpAndRunning++;
    DoModal(hBox);
    BxCloseSystem();
  }
  return NULL;
}
//*****************************************************************************
// SetUpdateFreq
//*****************************************************************************
unsigned long SetUpdateFreq(unsigned long updfq)
{
  unsigned long old = bx_update_freq;

  if(updfq > 1000)
    bx_update_freq = updfq;

  return old;
}
//*****************************************************************************
// Send opdate til Bx hver sek.
//*****************************************************************************
void *one_second_interval(void * argument )
{
  for(;;)
  {
    usleep(bx_update_freq);

    BxUpdate();
    BxSetEvent();
  }
}
//*****************************************************************************
// Print usage/help text
//*****************************************************************************
void usage(char *progName){
  printf("Usage: %s [OPTION]...\n",progName);
  printf("\n");
  printf("  -s          Simulate all\n");
  printf("  -s mouse    Use mouse instead of touch\n");
  printf("  -w id       Override workcell id given in mntdatabase.txt\n");
  printf("  -db path    Override database path given in mntdatabase.txt\n");
  printf("\n");
}
extern volatile int stmUpAndRunning;
extern volatile int trioUpAndRunning;
//*****************************************************************************
//*  main                                                                     *
//*****************************************************************************
int main(int argc, char *argv[])
{
	int argsdl, i, simulate = 0, usemouse = 0, superuser = 0, workcellid;
  pthread_attr_t attr;
  struct sched_param sched_param;
  int ret;
  char str[256];
  pthread_t box_task;
  pthread_t stmServer_task;
  pthread_t ev_task;
#ifdef DFD
  pthread_t dfd_task;
#else 
#ifdef SDL
	pthread_t sdl_task;
#endif
#endif
  pthread_t box_timertask;
  pthread_t motion_task;
  pthread_t statemachine_task;
  pthread_t triostm_task;
  pthread_t uload_task;
  pthread_t loader_task;
  pthread_t executer_task;
  //mlockall(MCL_CURRENT | MCL_FUTURE);
  //loop through arguments:
  for(i = 1; i < argc; i++)
  {
      if(!strcmp(argv[i], "--help"))
      {
        usage(argv[0]);
        exit(101);
      }
      if(!strcmp(argv[i], "-s"))
      {
        if(argc <= i+1 || argv[i+1][0] == '-')
        {
          simulate = 1;
          continue;
        }
        else
        {
          i++;
          if(!strcmp(argv[i], "mouse"))
          {
            usemouse = 1;
            continue;
          }
          else
          {
            printf("Error: unknown argument: '%s'.\n",argv[i]);
            usage(argv[0]);
            exit(101);
          }
        }
      }
      if(!strcmp(argv[i], "-su"))
      {
        superuser = 1;
        continue;
      }
      if(!strcmp(argv[i], "-w"))
      {
        i++;
        if(argc > i)
          if((workcellid = atoi(argv[i])) != 0)
          {
            sprintf(rs_systemini, "%dsystem.ini", workcellid);
            continue;
          }
          else
          {
            printf("Error: '%s' doesn't seem to be a valid workcell id.\n", argv[i]);
            usage(argv[0]);
            exit(101);
          }
        else
        {
          printf("Error: need workcell id number after -w argument.\n");
          usage(argv[0]);
          exit(101);
        }
      }
      if(!strcmp(argv[i], "-db"))
      {
        i++;
        if(argc > i)
        {
          struct stat buf;
          if(stat(argv[i], &buf) == 0)
          {
            sprintf(rs_systempath, "%s", argv[i]);
            continue;
          }
          else
          {          
            printf("Error: '%s' doesn't seem to be a directory.\n", argv[i]);
            usage(argv[0]);
            exit(101);
          }
        }
        else
        {
          printf("Error: need database path after -db argument.\n");
          usage(argv[0]);
          exit(101);
        }
      }
      printf("Error: unknown argument: '%s'.\n",argv[i]);
      usage(argv[0]);
      exit(101);
    }
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT,sigproc);//catch ctrl-c
  signal(SIGQUIT,sigproc);
  signal(SIGTERM,sigproc);//catch killall
  sprintf(str,"Starting roboStacker %s",GetRSVersion());
  printf("%s\n",str);
  logMsg(str);
  if(LoadRSSystemData(&rs_param)==FALSE)
  {
    printf("system.ini: not found\n");
    //SaveRSSystemData(&rs_param);
    exit(1);
  }
  tmpnSetDatabase(rs_systempath);
  logMsg(rs_systempath);
  if(!LoadCalibrationParam(&rs_param))
  {
    printf("LoadCalibrationParam: failed\n");
    exit(1);
  }
  if (usemouse)
  {
#ifdef DFD
    rs_param.touch.ctrltype=3;
#else 
#ifdef SDL
    rs_param.touch.ctrltype=4;
#endif
#endif
  }    
  if (simulate || demo == 1)
  {
    int i;
    printf("\e[31mSystem running in simulation mode!!!!!!\e[0m\n");
    rs_param.simulateMC=1;
    if(demo==0)
    {
#ifdef DFD
      rs_param.touch.ctrltype=3;
#else 
#ifdef SDL
      rs_param.touch.ctrltype=4;
#endif
#endif
      rs_param.touch.initialized=1;
    }
    for (i=0;i<tworkcell->dios.maxidx;i++)
    {
      tworkcell->dios.dio[i].simulate=1;
    }
    for (i=0;i<tworkcell->comsks.maxidx;i++)
    {
      tworkcell->comsks.comsk[i].simulate=1;
    }
    for (i=0;i<tworkcell->macs.maxidx;i++)
    {
      tworkcell->macs.mac[i].simulate=1;
    }
    for (i=0;i<tworkcell->icpcons.maxidx;i++)
    {
      tworkcell->icpcons.icpcon[i].simulate=1;
    }
    for (i=0;i<tworkcell->loadcells.maxidx;i++)
    {
      tworkcell->loadcells.loadcell[i].simulate=2;
    }
	}
  if(superuser)
  {
    strcpy(userid,"mpn");
    strcpy(password,"Rotten");
    printf("Running as superuser\n");
  }
  else
  {
    strcpy(userid,rs_param.user);
    strcpy(password,rs_param.password);
    printf("user='%s' password='%s'\n",userid,password);
  }
  sprintf(rs_param.scriptname,"%sStart",rs_param.script);
  printf("defaultscript='%s'\n",rs_param.script);
  speedFactor = rs_param.startSpeed*0.01;
	// logMsg("Before initialize!");
  InitializeRobostacker();
  if(rs_param.roboStacker>1)
    InitializeLoader();
  // logMsg("After initialize!");
  pthread_attr_init(&attr);
	
  printf("Starting comsk tasks\n");
	initComskTasks((tmpnWorkcell *)tworkcell); 

	printf("Starting mac tasks\n");
	initMacTasks((tmpnWorkcell *)tworkcell); 

	printf("Starting icpcon tasks\n");
	initICPconTasks((tmpnWorkcell *)tworkcell); 

	printf("Starting loadcell tasks\n");
	initLoadCellTasks((tmpnWorkcell *)tworkcell); 

  printf("Starting stm tasks\n");
  sched_param.sched_priority = 10;
  pthread_attr_setschedparam (&attr, &sched_param);
  ret = pthread_create(&statemachine_task, &attr, stm_task, NULL);
  pthread_setschedparam (statemachine_task, SCHED_FIFO, &sched_param);
	
  //Starting stmServer task
  printf("Starting stmServer tasks\n");
  
  sched_param.sched_priority = 0;
  pthread_attr_setschedparam (&attr, &sched_param);
	ret = pthread_create(&stmServer_task, &attr, stmServer, NULL);
	pthread_setschedparam (stmServer_task, SCHED_OTHER, &sched_param);

  //Starting stmClient task
  printf("Starting stmClient tasks\n");
  initRemoteStatemachines((tmpnWorkcell *)tworkcell);
	
  if(rs_param.scriptExec==1)
  {
    printf("scriptExec==1 starting mc_task\n");
    sched_param.sched_priority = 0;
    pthread_attr_setschedparam (&attr, &sched_param);
    ret = pthread_create(&motion_task, &attr, mc_task, NULL);
    pthread_setschedparam (motion_task, SCHED_OTHER, &sched_param);
  }

  if(rs_param.roboStacker>0)
  {
    printf("roboStacker>0\n");
    if(rs_param.simulateMC==0)
    {
      printf("simulateMC==0 starting trioStmTask\n");
      //set_up_tcp is called from InitializeRobostacker
      //all tasks that communicate with trio use same socket
      //and mutex each other
      sched_param.sched_priority = 0;
      pthread_attr_setschedparam (&attr, &sched_param);
      ret = pthread_create(&triostm_task, &attr, trioStmTask, NULL);
      pthread_setschedparam (triostm_task, SCHED_OTHER, &sched_param);
    }
    if(rs_param.roboStacker>1)
    { 
      printf("loader_task\n");
      sched_param.sched_priority = 0;
      pthread_attr_setschedparam (&attr, &sched_param);
      ret = pthread_create(&loader_task, &attr, loaderTask, NULL);
      pthread_setschedparam (loader_task, SCHED_OTHER, &sched_param);
      printf("executer_task\n");
      sched_param.sched_priority = 0;
      pthread_attr_setschedparam (&attr, &sched_param);
			ret = pthread_create(&executer_task, &attr, executerTask, NULL);
			pthread_setschedparam (executer_task, SCHED_OTHER, &sched_param);
    }
    else
    {
      printf("upload_task\n");
      sched_param.sched_priority = 0;
      pthread_attr_setschedparam (&attr, &sched_param);
			ret = pthread_create(&uload_task, &attr, upload_task, NULL);
			pthread_setschedparam (uload_task, SCHED_OTHER, &sched_param);
    }
  }

	while(stmUpAndRunning<=0) usleep(200000);
	while((rs_param.simulateMC==0)&&(trioUpAndRunning<=0)) usleep(200000);

  if(strcmp(rs_param.mainDialog,"formStdRun")==0
   ||strcmp(rs_param.mainDialog,"formCW")==0
   ||strcmp(rs_param.mainDialog,"formCP")==0
   ||strcmp(rs_param.mainDialog,"formCM")==0
   ||strcmp(rs_param.mainDialog,"formDemo")==0
   ||strcmp(rs_param.mainDialog,"form900")==0)
  {
    if(rs_param.touch.ctrltype!=TOUCH_NONE
			 &&rs_param.touch.ctrltype!=TOUCH_DFD
			 &&rs_param.touch.ctrltype!=TOUCH_SDL)
    {
      rs_param.touch.ctrltype = FindTouchCtrl();
      printf("ctrltype=%d\n",rs_param.touch.ctrltype);
      sched_param.sched_priority = 0;
      pthread_attr_setschedparam (&attr, &sched_param);
      if(rs_param.touch.ctrltype==TOUCH_ELO)
        ret = pthread_create(&ev_task, &attr, EloTask, NULL);
      else if(rs_param.touch.ctrltype==TOUCH_EGLX)
        ret = pthread_create(&ev_task, &attr, EGalaxTask, NULL);
      pthread_setschedparam (ev_task, SCHED_OTHER, &sched_param);
    }
#ifdef DFD
  	else if (rs_param.touch.ctrltype==TOUCH_DFD)
  	{
  		sched_param.sched_priority = 0;
  		pthread_attr_setschedparam (&attr, &sched_param);
			ret = pthread_create(&dfd_task, &attr, dfdevent_task, NULL);
  		pthread_setschedparam (dfd_task, SCHED_OTHER, &sched_param);
  	}
#else 
#ifdef SDL
//  	else if (rs_param.touch.ctrltype==TOUCH_SDL)
  	{
  		argsdl = (rs_param.touch.ctrltype==TOUCH_SDL);
			sched_param.sched_priority = 0;
			pthread_attr_setschedparam (&attr, &sched_param);
		  ret = pthread_create(&sdl_task, &attr, sdlevent_task, &argsdl);
		  pthread_setschedparam(sdl_task, SCHED_OTHER, &sched_param);
    }
#endif
#endif
		//Load icons		
		icon1 = BxResourceLoadBxIcon(FORMICON_LABUNLOCK_ICON, "data/robostacker.bxr");
		icon2 = BxResourceLoadBxIcon(FORMICON_LABPROGRAM_ICON, "data/robostacker.bxr");
		icon3 = BxResourceLoadBxIcon(FORMICON_LABOPTION_ICON, "data/robostacker.bxr");
		icon4 = BxResourceLoadBxIcon(FORMICON_LABTOOLS_2_ICON, "data/robostacker.bxr");
		iconreload = BxResourceLoadBxIcon(FORMICON_LABSHUTDOWN_ICON, "data/robostacker.bxr");
		iconscope = BxResourceLoadBxIcon(FORMICON_LABSCOPE_ICON, "data/robostacker.bxr");		

		sched_param.sched_priority = 0;
		pthread_attr_setschedparam (&attr, &sched_param);
		ret = pthread_create(&box_task, &attr, boxMain, NULL);
		pthread_setschedparam(box_task, SCHED_OTHER, &sched_param);
		
		sched_param.sched_priority = 0;
		pthread_attr_setschedparam (&attr, &sched_param);
		ret = pthread_create(&box_timertask, &attr, one_second_interval, NULL);
		pthread_setschedparam(box_timertask, SCHED_OTHER, &sched_param);
		
		pthread_join(box_task, NULL); // Vent paa boxtasket stopper
	}
  else
  {
    pthread_join(statemachine_task, NULL); // Vent paa boxtasket stopper
  }
	BxDeleteIcon(icon1);
	BxDeleteIcon(icon2);
	BxDeleteIcon(icon3);
	BxDeleteIcon(icon4);
	BxDeleteIcon(iconreload);
	BxDeleteIcon(iconscope);
  return EXIT_SUCCESS;
}
