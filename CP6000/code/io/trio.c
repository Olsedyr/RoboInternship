/****************************************************************************
* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd.h"
#include "rs.h"
#include "stm.h"

void startUp(void);

extern int readSummary(void);
extern int GetAxisParamValues(int axis, int table);
extern int SetAxisParamValues(int axis, int table);
extern int ReadAxisPosition(tmpnJoints *);
volatile int trioUpAndRunning=0;
extern volatile int bxUpAndRunning;
extern volatile int advantysUpAndRunning;
extern volatile int stmUpAndRunning;

extern volatile unsigned int mposupdatecount;
extern tmpnJoints m_actuator;
extern pthread_mutex_t actuator_mutex;
extern volatile int jogikscreen;

static tmpnStateMachineValue *mpos;
static int *axist;
static tmpnStateMachineValue *mtypet;
static tmpnStateMachineValue *mtypef;
static tmpnStateMachineValue *axisa;
static tmpnStateMachineValue *axisb;
static tmpnStateMachineValue *axisc;
static tmpnStateMachineValue *axisd;
static tmpnStateMachineValue *axise;
static tmpnStateMachineValue *axisf;
static tmpnStateMachineValue *fea;
static tmpnStateMachineValue *feb;
static tmpnStateMachineValue *fec;
static tmpnStateMachineValue *fed;
static tmpnStateMachineValue *fee;
static tmpnStateMachineValue *fef;
static int *mpnstate;
static int *wdog;
static int *emerg;
static int *startupstate;
static int *mposreq;
static int *mpostcpidx;
static int robotVersion=0;

/******************************
 * kasseLift workcellid = 401 *
 ******************************/
static tmpnStateMachineValue *kasseLiftEnable;
static tmpnStateMachineValue *kasseLiftSpeed;
static tmpnStateMachineValue *kasseLiftAccel;
static tmpnStateMachineValue *kasseLiftDecel;
static tmpnStateMachineValue *kasseLiftSetpoint;

void *trioStmTask(void * argument )
{
	tmpnRobot temprobot;
	float oldspeedFactor;
  clock_t start;
  clock_t stop;
  float diff;

  int i;

	while(!trioUpAndRunning)
	{
		usleep(10000); 
		//printf("trioNotRunning\n");
	}
	printf("trioRunning\n");
	while(!stmUpAndRunning)
	{
		usleep(10000); 
		//printf("stmNotRunning\n");
	}
	printf("stmRunning\n");
//	while(!bxUpAndRunning)
//	{
//		usleep(10000); 
		//printf("bxNotRunning\n");
//	}
 //	printf("bxRunning\n");
  for(i=0;i<trobot->timing.maxidx;i++)
  {
    if(rs_param.mc_task_debug>0)
    {
      printf("%s %3.2f = ",trobot->timing.item[i].name,trobot->timing.item[i].value);
      printf("%3.2f\n",getTimingValue((const char*)trobot->timing.item[i].name,(tmpnRobot*)trobot));
    }
  }
  memcpy(&temprobot,(tmpnRobot *)trobot,sizeof(temprobot)); //kopier tmpnrobot strukturen

  //GetMPos
	int robotstm = getMachineIdx("Robot");
	int emergstm = getMachineIdx("Emergency");
	int state_followerr = getStateIdx(robotstm, "ST_FOLLOWERROR");
	int state_emerg = getStateIdx(robotstm, "ST_EMERGENCY");
	mpos = getMachineValue(robotstm, "mpos");

  wdog = getMachineValuePtr(robotstm,"wdog");
  emerg = getMachineValuePtr(emergstm,"emergency");
	mpnstate = getMachineValuePtr(robotstm,"mpnstate");
  mtypet = getMachineValue(robotstm,"mtype_t");
  mtypef = getMachineValue(robotstm,"mtype_f");
  axist = getMachineValuePtr(robotstm,"axis_t");
  axisa = getMachineValue(robotstm,"axis_a");
  axisb = getMachineValue(robotstm,"axis_b");
  axisc = getMachineValue(robotstm,"axis_c");
  axisd = getMachineValue(robotstm,"axis_d");
  axise = getMachineValue(robotstm,"axis_e");
  axisf = getMachineValue(robotstm,"axis_f");
  fea = getMachineValue(robotstm,"fe_a");
  feb = getMachineValue(robotstm,"fe_b");
  fec = getMachineValue(robotstm,"fe_c");
  fed = getMachineValue(robotstm,"fe_d");
  fee = getMachineValue(robotstm,"fe_e");
  fef = getMachineValue(robotstm,"fe_f");
  robotVersion = getMachineVersion(robotstm);

  if(rs_param.mc_version>=3&&robotVersion>=1&&rs_param.workcellid==401)
  {
	  int servolift = getMachineIdx("ServoLift");
    kasseLiftEnable = getMachineValue(servolift,"enable");
    kasseLiftSpeed = getMachineValue(servolift,"speed");
    kasseLiftAccel = getMachineValue(servolift,"accel");
    kasseLiftDecel = getMachineValue(servolift,"decel");
    kasseLiftSetpoint = getMachineValue(servolift,"setpoint");
	}
  mposreq = getMachineValuePtr(robotstm, "mposreq");
	mpostcpidx = getMachineValuePtr(robotstm, "mpostcpidx");
	startupstate = getMachineValuePtr(robotstm,"startupstate");


  oldspeedFactor = GetSpeedFactor();
  for(;;) //scan forever
  {
    //trio writes to new_trio_statemachine_signal
    start = times(NULL);
    if(rs_param.mc_version>=2&&robotVersion>=1)
    {
      readSummary();
      *mpnstate = (int)tspace.summary.state;
      *wdog = (int)tspace.summary.wdog;
      *emerg = (int)tspace.summary.emergency;
      *axist=(int)tspace.summary.axist;
      mtypet->data=tspace.summary.mtypet;
      mtypef->data=tspace.summary.mtypef;
      axisa->fdata=tspace.summary.axisa;
      axisb->fdata=tspace.summary.axisb;
      axisc->fdata=tspace.summary.axisc;
      axisd->fdata=tspace.summary.axisd;
      axise->fdata=tspace.summary.axise;
      axisf->fdata=tspace.summary.axisf;
      fea->fdata=tspace.summary.fea;
      feb->fdata=tspace.summary.feb;
      fec->fdata=tspace.summary.fec;
      fed->fdata=tspace.summary.fed;
      fee->fdata=tspace.summary.fee;
      fef->fdata=tspace.summary.fef;
    }
    else
    {
      *mpnstate = GetRunningState();
      GetAxisParamValues(0,1);
      *wdog = IsWDOGOn();
      *emerg = emergency();
      *axist=(int)tspace.axis.name.t.mpos;
    }
		
		if (*mposreq == 1 || jogikscreen)
		{
      pthread_mutex_lock(&actuator_mutex);
      if(rs_param.mc_version>=2&&robotVersion>=1)
			{
        m_actuator.a = tspace.summary.axisa;
        m_actuator.b = tspace.summary.axisb;
        m_actuator.c = tspace.summary.axisc;
        m_actuator.d = tspace.summary.axisd;
        m_actuator.e = tspace.summary.axise;
        m_actuator.f = tspace.summary.axisf;
      }
      else
      {
			  ReadAxisPosition(&m_actuator);
			}
		  pthread_mutex_unlock(&actuator_mutex);
      mposupdatecount++; 
			tmpnComputeFK(&temprobot, m_actuator.a, m_actuator.b, m_actuator.c, m_actuator.d, m_actuator.e, m_actuator.f,*mpostcpidx);
			if (mpos->type==FRAME)
			{
				mpos->frame->x=temprobot.m_worldPoint.x;
				mpos->frame->y=temprobot.m_worldPoint.y;
				mpos->frame->z=temprobot.m_worldPoint.z;
				mpos->frame->v=temprobot.m_worldPoint.v;
				mpos->frame->w=temprobot.m_worldPoint.w;
				mpos->frame->u=temprobot.m_worldPoint.u;
			}
			if (*mposreq == 1)
				*mposreq=2;
		}
		/* Update speed in controller if neccesary */
		if (oldspeedFactor != GetSpeedFactor())
		{
			oldspeedFactor = SetSpeedFactor(GetSpeedFactor());
		}
		if(testState(robotstm, state_followerr)||testState(robotstm, state_emerg))
		{
			startUp();
		}
    if(rs_param.mc_version>=3&&robotVersion>=1&&rs_param.workcellid==401)
    {
		  SetKasseLiftValues(kasseLiftEnable->data
                        ,kasseLiftSpeed->fdata
                        ,kasseLiftAccel->fdata
                        ,kasseLiftDecel->fdata
                        ,kasseLiftSetpoint->fdata);
    }
		usleep(100000);
		stop = times(NULL);
    diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
    //if(diff>0.2) 
		if(rs_param.io_debug>=2)
      printf("************************ trio executed in %f\n",diff);
  }
}

void startUp()
{
  int val;
  float version;
  char s[256];

//  printf("startupstate=%d\n",*startupstate);  
	switch(*startupstate)
	{
	case 0 :
		(*startupstate)++;
		break;
	case 1 :
		CancelMc(1);
		version=GetVersion();
    if(version<rs_param.mc_version)
    {
//we want to set PID from host but mc does not support it.
		  sprintf(s,"MC version is to old. Workcell(mc_version=%d) can not run on VERSION: %f\n",rs_param.workcellid, version);
      printf("%s\n",s);
		  printf("Please update MC, first\n");
      logMsg(s);
      mpnexit(1);
    }
    else
    { 
		  printf("Workcell(mc_version=%d)  running on VERSION: %f\n", rs_param.mc_version,version);
  		(*startupstate)++;
    }
		break;
	case 2 :
		if(*emerg||rs_param.simulateMC>=1)
		{
  	  (*startupstate)++;
    }
		break;
	case 3 : // reset pressed ?
		if(!*emerg||rs_param.simulateMC==2)
		{
			usleep(1000000);
			// start STARTUP
			if (CmdStartup()==0)
			{
				(*startupstate)++;
			}
		}
		break;
	case 4 : // is SETUP done ?
		val = GetReply();
		if(val==1)
		{
			// start mpn_command_set_units_and_defaults
//from version>=2 the PID is saved on host. Not on mc.
      if(rs_param.mc_version<2)
			{
			  SetUnitsAndDefaults();
      }
      else
      {
  			SetAxisParamValues(axis_t, 0);
			  SetAxisParamValues(axis_a, 0);
			  SetAxisParamValues(axis_b, 0);
			  SetAxisParamValues(axis_c, 0);
			  SetAxisParamValues(axis_d, 0);
			  SetAxisParamValues(axis_e, 0);
			  SetAxisParamValues(axis_f, 0);
			}
		  (*startupstate)++;
		}
		break;
	case 5 : // is setup units .... done ?
		val = GetReply();
		if(val==1)
		{
			(*startupstate)++;
		}
		break;
	case 6 : // is setup units .... done ?
		val = GetReply();
		if(val==1)
		{
			// start mpn_command_resetaxis
			if(ResetAxis()==0)
			{
				(*startupstate)++;
			}
		}
		break;
	case 7 : // is reset .... done ?
		val = GetReply();
		if(val==1)
		{
			// start mpn_command_set_mpn_home_all
			if(SetHomeAll()==0)
			{
				(*startupstate)++;
			}
		}
		break;
	case 8 : // continue
		val = GetReply();
		if(val==1)
		{
//from version>=2 the PID is saved on host. Not on mc.
      if(rs_param.mc_version<2)
			{
        GetAxisParamValues(axis_t, 0);
			  GetAxisParamValues(axis_a, 0);
			  GetAxisParamValues(axis_b, 0);
			  GetAxisParamValues(axis_c, 0);
			  GetAxisParamValues(axis_d, 0);
			  GetAxisParamValues(axis_e, 0);
			  GetAxisParamValues(axis_f, 0);
      }
			GetAxisParamValues(axis_t, 1);
			GetAxisParamValues(axis_a, 1);
			GetAxisParamValues(axis_b, 1);
			GetAxisParamValues(axis_c, 1);
			GetAxisParamValues(axis_d, 1);
			GetAxisParamValues(axis_e, 1);
			GetAxisParamValues(axis_f, 1);
			val = (float)GetRetur();
			if(val==0)
			{
				*startupstate = 10;
			}
			else
			{
				*startupstate = 9;
			}
			CancelMc(0);
		}
		break;
	case 9 : 
		// if supervisorlevel =1 *startupstate++;
	case 10 :
		break;
	}
}
