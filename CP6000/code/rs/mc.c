/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <sys/times.h>
#include <unistd.h>

#include "Bx.h"
#include "formUploadProg.h"

#include "rs.h"
#include "cmd.h"
#include "stm.h"
#include "modbus_tcp.h"
#include "genscript.h"

volatile int trio_sdf;
volatile int *roboError=NULL;
volatile int *restart=NULL;

//volatile int ppos=0;
//volatile float rpos=0;
//volatile int rtype=0;

extern int defpathsamprate;

char mcstm[256]="MC";

//TODO move these to tmpnRobot struct
volatile int jumpToLayer=-1; //used by NYHUUS
volatile int scriptLoaded=FALSE; //script_mutex
volatile int resetPreload=FALSE; //script_mutex
volatile int resetPreloadgroup[MAXLOADGROUP];

volatile int ctrlNumOfUploads[MAXLOADGROUP];
extern int stateMachineError(void);
extern int getFotoFriMM(void);
extern void setMachineState(const char *machinename, const char *statename);
extern int testMachineState(const char *machinename, const char *statename);
extern int isRunning(char *WorkCell);
extern volatile int trioUpAndRunning;
extern volatile int bxUpAndRunning;

#define LOADING 2
#define LOADING_DONE 3

volatile static bufferstruct buffer0 = { NULL };

clock_t gstart;

pthread_mutex_t mc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mc_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mc_mtx = PTHREAD_MUTEX_INITIALIZER;


WSPSTRUCT CalOffset = {0.0, 0.0, 0.0, 0.0, 0.0};
 
void logVRStatus(void);
void setTiming(void);

int RoboError(void)
{
  return *roboError;
}

void ClearErrors(void)
{
  *roboError = 0;
}
static void InitializeMcLock(void)
{
  int pthreadret;
  pthreadret=pthread_mutex_init(&mc_mutex, NULL);
  if(pthreadret!=0) printf("IMC pthreadret=%d\n",pthreadret);
}

static void McLock(void)
{               
  int pthreadret;
  pthreadret=pthread_mutex_lock(&mc_mutex);
  if(pthreadret!=0) printf("MCL pthreadret=%d\n",pthreadret);
}

static void McUnlock(void)
{
  int pthreadret;
  pthreadret=pthread_mutex_unlock(&mc_mutex);
  if(pthreadret!=0) printf("MCUL pthreadret=%d\n",pthreadret);
}

extern int pauseknaptrykket(void);


//reset preload 
static void signalResetPreload(int loadgroup)
{   
  int i;
  scriptLoaded=TRUE;
  jumpToLayer=-1;
  resetPreload=TRUE;
  for(i=0;i<MAXLOADGROUP;i++)
  {
    resetPreloadgroup[i]=FALSE;
  }
  resetPreloadgroup[loadgroup]=TRUE;
//  printf("ResetPreload %d\n",loadgroup);
}

//load script and reset preload 
static void signalLoadCommandScript(void)
{
  int i;
  scriptLoaded=FALSE;
  jumpToLayer=-1;
  resetPreload=FALSE;
  for(i=0;i<MAXLOADGROUP;i++)
  {
    resetPreloadgroup[i]=FALSE;
  }
}


void *mc_task(void * argument )
{
  char logstr[256];
  volatile COMMANDSTRUCT *pcmd;
  int pthreadret,i;
  if(rs_param.mc_task_debug>1)
  {
    printf("***************************************************\n");
    printf("* PC - MC command address - workcell_task         *\n");
    printf("***************************************************\n");
    printf("AXIS_A_PARAM_IDX         = %d\n",AXIS_A_PARAM_IDX);
    printf("AXIS_B_PARAM_IDX         = %d\n",AXIS_B_PARAM_IDX);
    printf("AXIS_C_PARAM_IDX         = %d\n",AXIS_C_PARAM_IDX);
    printf("AXIS_D_PARAM_IDX         = %d\n",AXIS_D_PARAM_IDX);
    printf("AXIS_E_PARAM_IDX         = %d\n",AXIS_E_PARAM_IDX);
    printf("AXIS_F_PARAM_IDX         = %d\n",AXIS_F_PARAM_IDX);
    printf("***************************************************\n");
    printf("SCOPE_CMD_RTN_IDX        = %d\n",SCOPE_CMD_RTN_IDX);
    printf("SCOPE_CMD_ARG_IDX        = %d\n",SCOPE_CMD_ARG_IDX);
    printf("SCOPE_CMD_IDX            = %d\n",SCOPE_CMD_IDX);
    printf("SCOPE_TYPE               = %d\n",SCOPE_TYPE);
    printf("SCOPE_LENGTH             = %d\n",SCOPE_LENGTH);
    printf("SCOPE_NUMOFSAMPLES       = %d\n",SCOPE_NUMOFSAMPLES);
    printf("SCOPE_ASCALE             = %d\n",SCOPE_ASCALE);
    printf("SCOPE_BSCALE             = %d\n",SCOPE_BSCALE);
    printf("SCOPE_CSCALE             = %d\n",SCOPE_CSCALE);
    printf("SCOPE_DSCALE             = %d\n",SCOPE_DSCALE);
    printf("SCOPE_ESCALE             = %d\n",SCOPE_ESCALE);
    printf("SCOPE_FSCALE             = %d\n",SCOPE_FSCALE);
    printf("SCOPE_BUFFER             = %d\n",SCOPE_BUFFER);
    printf("***************************************************\n");
    printf("CONTROLLER_CMD_RTN_IDX   = %d\n",CONTROLLER_CMD_RTN_IDX);
    printf("CONTROLLER_CMD_ARG_IDX   = %d\n",CONTROLLER_CMD_ARG_IDX);
    printf("CONTROLLER_CMD_IDX       = %d\n",CONTROLLER_CMD_IDX);
    printf("***************************************************\n");
    printf("MPN_CMD_RTN_IDX          = %d\n",MPN_CMD_RTN_IDX);
    printf("MPN_CMD_ARG_IDX          = %d\n",MPN_CMD_ARG_IDX);
    printf("MPN_CMD_IDX              = %d\n",MPN_CMD_IDX);
    printf("***************************************************\n");
    printf("MPN_TRIO_BASIC_ERROR     = %d\n",MPN_TRIO_BASIC_ERROR);
    printf("MPN_TRIO_BASIC_LINE_ERROR= %d\n",MPN_TRIO_BASIC_LINE_ERROR);
    printf("***************************************************\n");
    printf("MPN_CANCEL               = %d\n",MPN_CANCEL);
    printf("MPN_RUNNING              = %d\n",MPN_RUNNING);
    printf("MPN_STATE                = %d\n",MPN_STATE);
    printf("MPN_SPEEDFACTOR          = %d\n",MPN_SPEEDFACTOR);
    printf("***************************************************\n");
    printf("MPN_TRIO_SUMMARY         = %d\n",MPN_TRIO_SUMMARY);
    printf("MPN_TRIO_SUMMARY_SIZE    = %d\n",MPN_TRIO_SUMMARY_SIZE);
    printf("***************************************************\n");
    printf("* PC - MC path address loadgroup 0 and 1          *\n");
    printf("***************************************************\n");
    for(i=0;i<MAXLOADGROUP;i++)
    {
      printf("NUM_OF_PATH_INDEX(%d)   = %d\n",i,NUM_OF_PATH_INDEX(i));
      printf("PATH_INDEX(%d)          = %d\n",i,PATH_INDEX(i));
      printf("FIRST_PATH_INDEX(%d)    = %d\n",i,FIRST_PATH_INDEX(i));
      printf("***************************************************\n");
    }
    printf("***************************************************\n");
    printf("* Diverse address and size                        *\n");
    printf("***************************************************\n");
    printf("sizeof(tspace)           = %d\n",sizeof(tspace));
    printf("sizeof(tspace.scope)     = %d\n",sizeof(tspace.scope));
    printf("sizeof(tspace.ctrl_cmd)  = %d\n",sizeof(tspace.ctrl_cmd));
    printf("sizeof(tspace.mpn_cmd)   = %d\n",sizeof(tspace.mpn_cmd));
  }  
  
  sprintf(rs_param.scriptname,"%sStart",rs_param.script);

  CancelMc(1);
	roboError = getMachineValuePtr(getMachineIdx("RoboError"),"roboError");
	restart = getMachineValuePtr(getMachineIdx("RoboError"),"restart");
  ClearErrors();
  for(;;)
  {
    if(testMachineState(mcstm,"ST_IDLE"))
    {
  		//TODO xxxworkcell.statemachine should set the traficlights via advantys not TRIO
      SetTraficLight(ROBOSTATE_IDLE);
      usleep(100000); 
      if(testMachineState("WorkCell","ST_STARTING"))
        setMachineState(mcstm,"ST_STARTING");
    } 
    else if(testMachineState(mcstm,"ST_STARTING"))
    {
      SetTraficLight(ROBOSTATE_STARTING);
      ClearErrors();
      CancelMc(1);
      if(trobot!=NULL) 
      {
        //prepare robot
        setTiming();
        SetSpeedFactor(GetSpeedFactor());
        SetSpeed(axis_a, 200.0);
        SetAccel(axis_a, 400.0);
        SetDecel(axis_a, 400.0);
      }
      if(rs_param.workcellid<500) usleep(3000000);
      pthreadret=pthread_mutex_lock(&script_mutex);
      if(pthreadret!=0) printf("START lock pthreadret=%d\n",pthreadret);
      sprintf(rs_param.scriptname,"%sStart",rs_param.script);
      //load script and reset preload
      signalLoadCommandScript();  
      while(scriptLoaded==FALSE&&pthreadret==0)
        pthreadret=pthread_cond_wait( &script_cond, &script_mutex);
      pthreadret=pthread_mutex_unlock(&script_mutex);
      
      pcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
      if(testMachineState("WorkCell","ST_RUNNING"))
        setMachineState(mcstm,"ST_RUNNING");
      else if(testMachineState("WorkCell","ST_PAUSING"))
        setMachineState(mcstm,"ST_IDLE");
      else if(testMachineState("WorkCell","ST_ERROR"))
        setMachineState(mcstm,"ST_ERROR");
    }
    else if(testMachineState(mcstm,"ST_RESTARTING"))
    {
      SetTraficLight(ROBOSTATE_RESTARTING);
      ClearErrors();
      CancelMc(1);
      setTiming();
      SetSpeedFactor(GetSpeedFactor());
      SetSpeed(axis_a, 200.0);
      SetAccel(axis_a, 400.0);
      SetDecel(axis_a, 400.0);
      if(rs_param.workcellid<500) usleep(3000000);
      pthreadret=pthread_mutex_lock(&script_mutex);
      sprintf(rs_param.scriptname,"%sReStart",rs_param.script);
      signalLoadCommandScript();        
      while(scriptLoaded==FALSE&&pthreadret==0)
        pthreadret=pthread_cond_wait( &script_cond, &script_mutex);
      pthreadret=pthread_mutex_unlock(&script_mutex);
      pcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
      if(testMachineState("WorkCell","ST_RUNNING"))
        setMachineState(mcstm,"ST_RUNNING");
      else if(testMachineState("WorkCell","ST_ERROR"))
        setMachineState(mcstm,"ST_ERROR");
    }
    else if(testMachineState(mcstm,"ST_RUNNING"))
    {
      SetTraficLight(ROBOSTATE_RUNNING);
      //ParseCmd will set roboError if an error occurs
      //printf("ParseCmd %d ",pcmd->type);
      if(rs_param.mc_task_debug>1) printf("time=%3.2f :: ",(float)(times(NULL)-gstart)/(float)sysconf(_SC_CLK_TCK));
      ParseCmd(&pcmd);
      //common error handling
      switch(*roboError)
      {
        case 0:
          break;
        case 1:
         setMachineState(mcstm,"ST_STOPPING");
          //caused by STOP command
          break;
        case -1:
    		  setMachineState(mcstm,"ST_ERROR");
          logMsg("ParseCmd: error MPNcommand");
          break;
        case 2:
        case 6: //caused by rapidstop
        case 7: //caused by basicerror
          setMachineState(mcstm,"ST_IDLE");
          printf(logstr,"ParseCmd retur roboError %d...",*roboError);
          logMsg(logstr);
          break;
        default:
          setMachineState(mcstm,"ST_PAUSING");
          printf(logstr,"ParseCmd retur roboError %d...",*roboError);
          logMsg(logstr);
          break;
      }
      if(*roboError==0) 
      {
        if(testMachineState("WorkCell","ST_PAUSING"))
          setMachineState(mcstm,"ST_PAUSING");
        else if(testMachineState("WorkCell","ST_ERROR"))
          setMachineState(mcstm,"ST_ERROR");
      }
    }
    else if(testMachineState(mcstm,"ST_PAUSING"))
    {  
      SetTraficLight(ROBOSTATE_STOPPING);
      //delay stop until script has finished vital sequence
      if(*roboError==0&&atoi(getCounterValue("delaystop"))==1) 
			{
        printf("delaystop=%s  ST_PAUSING\n",getCounterValue("delaystop"));
        //ParseCmd will set roboError if an error occurs
        //printf("ParseCmd %d ",pcmd->type);
        if(rs_param.mc_task_debug>1) printf("time=%3.2f :: ",(float)(times(NULL)-gstart)/(float)sysconf(_SC_CLK_TCK));
        ParseCmd(&pcmd);
        switch(*roboError)
        {
         case 0:
           break;
         case 1:
            setMachineState(mcstm,"ST_STOPPING");
            //caused by STOP command
            break;
           case -1:
      		  setMachineState(mcstm,"ST_ERROR");
            logMsg("ParseCmd: error MPNcommand");
            break;
          case 2:
          case 6: //caused by rapidstop
          case 7: //caused by basicerror
            setMachineState(mcstm,"ST_IDLE");
            printf(logstr,"ParseCmd retur roboError %d...",*roboError);
            logMsg(logstr);
            break;
          default:
            setMachineState(mcstm,"ST_PAUSING");
            printf(logstr,"ParseCmd retur roboError %d...",*roboError);
            logMsg(logstr);
            break;
        }
        if(testMachineState("WorkCell","ST_ERROR"))
          setMachineState(mcstm,"ST_ERROR");
      }
      else
      {
        pthreadret=pthread_cond_signal(&uploaddone_cond);

        if(*roboError==0) 
        {
          //if(!testMachineState("ErrorCode","ST_ERROR"))
            *roboError=15;
        }
       
        if(testMachineState("WorkCell","ST_ERROR"))
          setMachineState(mcstm,"ST_ERROR");
        else
        {
          setMachineState(mcstm,"ST_PAUSED");
        }
      }
      //continue eller stop
    }
    else if(testMachineState(mcstm,"ST_STOPPING"))
    { 
			SetTraficLight(ROBOSTATE_STOPPING);
      usleep(100000);
      setMachineState(mcstm,"ST_IDLE");
    }
    else if(testMachineState(mcstm,"ST_PAUSED"))
    { 
			SetTraficLight(ROBOSTATE_PAUSED);
      usleep(100000);
      if(testMachineState("WorkCell","ST_RESTARTING"))
        setMachineState(mcstm,"ST_RESTARTING");
      else if(testMachineState("WorkCell","ST_IDLE"))
        setMachineState(mcstm,"ST_IDLE");
    }
    else if(testMachineState(mcstm,"ST_ERROR"))
    {  //Gcase ROBOSTATE_ERROR:  //we  might not get here because of wait condition
      if(testMachineState("WorkCell","ST_STARTING"))
        setMachineState(mcstm,"ST_STARTING");
      usleep(100000);
    }
    else
    {
  		//TODO xxxworkcell.statemachine should set the traficlights via advantys not TRIO
      usleep(100000); 
    } 
//  printf("roboError=%d\n",*roboError);
  }
  return NULL;
}

/*static void RapidStop(void)
{
  CancelMc(1);
} */

//called by varius Bx form's
//to wakeup mc_task
int GoRobot(int run)
{
  return 0;
}

//old version used by workcellid 302 and 303
int continueRobot(void)
{
/*  int pthreadret;
  if(!testContinue()) return FALSE;
  roboError = 0;
  pthreadret=pthread_cond_signal(&mc_cond);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);*/
  return TRUE;
}

void newcontinueRobot(void)
{
  return;
}

//used to display text about the state
int RobotState(void)
{
  return 0;
}

/***************************************************************************/
/* ControllerCommand                                                       */               
/***************************************************************************/
static int ControllerCommand(int cmd)
{
  tspace.ctrl_cmd.cmd_nr=cmd;
  if(rs_param.simulateMC!=0) return 0;
  trio_preset_multiple_registers_tcp( 1, 1+CONTROLLER_CMD_RTN_IDX, CONTROLLER_CMD_SIZE*2, (short *)&tspace.ctrl_cmd.rtn, trio_sdf);
  usleep(10000);
  while(GetCtrlReply()!=1);
  {
    usleep(10000);
  }
  return 0;
}
/***************************************************************************/
/*                                                                         */
/* Functions using ControllerCommand                                       */
/*                                                                         */
/* isNearFrame(char *frameName)                                            */
/* moveUp(float mm)                                                        */
/*                                                                         */
/***************************************************************************/
//used by Bx
void ReadAxisPosition(tmpnJoints *actuator)
{
  actuator->a = GetMPos(axis_a);
  actuator->b = GetMPos(axis_b);
  actuator->c = GetMPos(axis_c);
  actuator->d = GetMPos(axis_d);
  actuator->e = GetMPos(axis_e);
  actuator->f = GetMPos(axis_f);
}



int MoveAllAbs(float a, float b, float c, float d, float e)
{
  McLock();
  tspace.ctrl_cmd.arg[0] = a;
  tspace.ctrl_cmd.arg[1] = b;
  tspace.ctrl_cmd.arg[2] = c;
  tspace.ctrl_cmd.arg[3] = d;
  tspace.ctrl_cmd.arg[4] = e;
  ControllerCommand(ctrl_command_moveallabs);
  McUnlock();
  return 0;
}

int Move(int axis, float pos)
{
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = pos;
  ControllerCommand(ctrl_command_move);
  McUnlock();
  return 0;
}

int MoveAbs(int axis, float pos)
{
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = pos;
  ControllerCommand(ctrl_command_moveabs);
  McUnlock();
  return 0;
}

int MoveModify(int axis, float pos)
{
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = pos;
  ControllerCommand(ctrl_command_movemodify);
  McUnlock();
  return 0;
}

float GetVR(int number)
{
  float rtn;
  McLock();
  tspace.ctrl_cmd.arg[0] = number;
  ControllerCommand(ctrl_command_get_vr);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

float SetVR(int number, float val)
{
  float rtn;
  McLock();
  tspace.ctrl_cmd.arg[0] = number;
  tspace.ctrl_cmd.arg[1] = val;
  ControllerCommand(ctrl_command_set_vr);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

void setTiming(void)
{
  int i;
  for(i=0;i<trobot->timing.maxidx;i++)
  {
    SetVR(200+i,trobot->timing.item[i].value);
  }
}


void logVRStatus(void)
{
  char log[256];

  sprintf(log,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
          (int)GetVR(700),
          (int)GetVR(701),
          (int)GetVR(702),
          (int)GetVR(703),
          (int)GetVR(704),
          (int)GetVR(705),
          (int)GetVR(706),
          (int)GetVR(707),
          (int)GetVR(708),
          (int)GetVR(709),
          (int)GetVR(710),
          (int)GetVR(711),
          (int)GetVR(732),
          (int)GetVR(737));
  logStatus(log);
}

int GetAxisParamValues(int axis, int table)
{
  short *ptr;
  float array[1000];
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  if(rs_param.mc_version>=2)
//arg[1] is used to tell trio that we want the new function
    tspace.ctrl_cmd.arg[1] = 2;
  else
    tspace.ctrl_cmd.arg[1] = table;
  tspace.ctrl_cmd.arg[2] = 0; //read
  ControllerCommand(ctrl_command_axisvalues);
  if(rs_param.mc_version<2)
  {
    ptr = (short*)&tspace.axis.array[axis];
  }
  else
  {
    ptr = (short*)&array[0];
  }
  trio_read_holding_registers_tcp( 1, 1+AXIS_T_PARAM_IDX+(axis*AXIS_PARAM_SIZE), AXIS_PARAM_SIZE*2, ptr, AXIS_PARAM_SIZE_BYTE, trio_sdf );
  if(rs_param.mc_version>=2)
  {
    if(table==0)
    {
      tspace.axis.array[axis].p_gain=array[1];
      tspace.axis.array[axis].i_gain=array[2];
      tspace.axis.array[axis].d_gain=array[3];
      tspace.axis.array[axis].ov_gain=array[4];
      tspace.axis.array[axis].vff_gain=array[5];
      tspace.axis.array[axis].units=array[6];
      tspace.axis.array[axis].speed=array[7];
      tspace.axis.array[axis].accel=array[8];
      tspace.axis.array[axis].decel=array[9];
      tspace.axis.array[axis].creep=array[10];
      tspace.axis.array[axis].jogspeed=array[11];
      tspace.axis.array[axis].felimit=array[12];
    }  
    else
    {
      tspace.axis.array[axis].atype=array[0];
      tspace.axis.array[axis].dac=array[13];
      tspace.axis.array[axis].servo=array[14];
      tspace.axis.array[axis].redispt=array[15];
      tspace.axis.array[axis].fwd_in=array[16];
      tspace.axis.array[axis].rev_in=array[17];
      tspace.axis.array[axis].dat_in=array[18];
      tspace.axis.array[axis].fh_in=array[19];
      tspace.axis.array[axis].fslimit=array[20];
      tspace.axis.array[axis].rslimit=array[21];
      tspace.axis.array[axis].mtype=array[22];
      tspace.axis.array[axis].ntype=array[23];
      tspace.axis.array[axis].mpos=array[24];
      tspace.axis.array[axis].dpos=array[25];
      tspace.axis.array[axis].fe=array[26];
      tspace.axis.array[axis].axisstatus=array[27];
      tspace.axis.array[axis].vpspeed=array[28];
    }
  }
  McUnlock();
  return 0;
}

int SetAxisParamValues(int axis, int table)
{
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  ptr = (short*)&tspace.axis.array[axis];
  trio_preset_multiple_registers_tcp( 1, 1+AXIS_T_PARAM_IDX+(axis*AXIS_PARAM_SIZE), AXIS_PARAM_SIZE*2, ptr, trio_sdf);
  tspace.ctrl_cmd.arg[0] = axis;
//arg[1] is used to tell trio that we want the new function
  if(rs_param.mc_version>=2)
    tspace.ctrl_cmd.arg[1] = 2;
  else
    tspace.ctrl_cmd.arg[1] = table;
  tspace.ctrl_cmd.arg[2] = 1; //write
  ControllerCommand(ctrl_command_axisvalues);
  McUnlock();
  return 0;
}

void SetKasseLiftValues(float enable, float speed, float accel, float decel, float setpoint)
{
  short *ptr;
  float array[1000];
  if(rs_param.simulateMC!=0) return;
  array[0]=enable;
  array[1]=speed;
  array[2]=accel;
  array[3]=decel;
  array[4]=setpoint;
  tspace.axis.array[axis_f].speed=speed;
  tspace.axis.array[axis_f].accel=accel;
  tspace.axis.array[axis_f].decel=decel;
  McLock();
  ptr = (short*)&array[0];
  //printf("TABLE(%d,%d) %f %f %f %f %f\n",MPN_KASSELIFT,MPN_KASSELIFT_SIZE,array[0],array[1],array[2],array[3],array[4]);
  trio_preset_multiple_registers_tcp( 1, 1+MPN_KASSELIFT, MPN_KASSELIFT_SIZE*2, ptr, trio_sdf);
  McUnlock();
}

float GetMPos(int axis)
{
  float buffer=0.0;
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = 1; //MPOS
  tspace.ctrl_cmd.arg[2] = 0; //read
  ControllerCommand(ctrl_command_axisvalues);
  ptr = (short*)&buffer;
  trio_read_holding_registers_tcp( 1, 1+AXIS_T_PARAM_IDX+(axis*AXIS_PARAM_SIZE)+MPOS_INDEX, 2, ptr, 4, trio_sdf );
  McUnlock();
  return buffer;
}

float GetMType(int axis)
{
  float buffer=0.0;
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = 1; //MTYPE (read-only)
  tspace.ctrl_cmd.arg[2] = 0; //read
  ControllerCommand(ctrl_command_axisvalues);
  ptr = (short*)&buffer;
  trio_read_holding_registers_tcp( 1, 1+AXIS_T_PARAM_IDX+(axis*AXIS_PARAM_SIZE)+MTYPE_INDEX, 2, ptr, 4, trio_sdf );
  McUnlock();
  return buffer;
}

static float GetDPos(int axis)
{
  float buffer=0.0;
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  tspace.ctrl_cmd.arg[1] = 1; //MPOS
  tspace.ctrl_cmd.arg[2] = 0; //read
  ControllerCommand(ctrl_command_axisvalues);
  ptr = (short*)&buffer;
  trio_read_holding_registers_tcp( 1, 1+AXIS_T_PARAM_IDX+(axis*AXIS_PARAM_SIZE)+DPOS_INDEX, 2, ptr, 4, trio_sdf );
  McUnlock();
  return buffer;
}


int IsWDOGOn(void)
{
  int val;
  if(rs_param.simulateMC!=0) return TRUE;
  McLock();
  ControllerCommand(ctrl_command_watch_dog);
  val = GetCtrlRetur();
  McUnlock();
  if(val==FALSE)
  {
    if(testMachineState(mcstm,"ST_IDLE")
    ||testMachineState(mcstm,"ST_PAUSED")
    ||testMachineState(mcstm,"ST_ERROR"))
    {
    }
    else
    {
      setMachineState(mcstm,"ST_ERROR");
    }
  }
  return val;
}

int testContinue(void)
{
  int val;
  McLock();
  ControllerCommand(ctrl_command_continue);
  val = GetCtrlRetur();
  McUnlock();
  return val;
}

float GetEndMove(int axis)
{
  float rtn;
  McLock();
  tspace.ctrl_cmd.arg[0] = axis;
  ControllerCommand(ctrl_command_get_endmove);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

int GetErrorAxis(void)
{
  float rtn;
  McLock();
  ControllerCommand(ctrl_command_get_erroraxis);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

float GetVersion(void)
{
  float rtn;
  McLock();
  ControllerCommand(ctrl_command_get_version);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

int emergency(void)
{
  int rtn;
  McLock();
  ControllerCommand(ctrl_command_get_in);
  rtn = GetCtrlRetur();
  McUnlock();
  if(rtn&2) return TRUE;
  return FALSE;
}

// val & 0x00000002 ? TRUE : FALSE
int GetInput(void)
{
  int rtn;
  McLock();
  ControllerCommand(ctrl_command_get_in);
  rtn = GetCtrlRetur();
  McUnlock();
  return rtn;
}

int SetOutput(int port, int state)
{
  McLock();
  tspace.ctrl_cmd.arg[0] = port;
  tspace.ctrl_cmd.arg[1] = state;
  ControllerCommand(ctrl_command_set_outport);
  McUnlock();
  return 0;
}

float SetSpeedFactor(float ns)
{
  float oldSpeedFactor = speedFactor;
  if(ns > 0.0 && ns <= 1.0)
  {
    McLock();
    tspace.ctrl_cmd.arg[0] = ns;
    ControllerCommand(ctrl_command_set_speedfactor);
    McUnlock();
    speedFactor = ns;
  }
  return oldSpeedFactor;
}

float GetSpeedFactor(void)
{
  return speedFactor;
}

float GetCtrlRetur(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+CONTROLLER_CMD_RTN_IDX, 2, (short *)&tspace.ctrl_cmd.rtn, 4, trio_sdf );
  return tspace.ctrl_cmd.rtn;
}
int GetCtrlReply(void)
{
  float val=0.0;
  if(rs_param.simulateMC!=0) return 1;
  trio_read_holding_registers_tcp( 1, 1+CONTROLLER_CMD_IDX, 2, (short *)&val, 4, trio_sdf );
  return (int)val;
}

int readSummary(void)
{
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  McLock();
  ptr = (short*)&tspace.summary.wdog;
  trio_read_holding_registers_tcp( 1, 1+MPN_TRIO_SUMMARY, MPN_TRIO_SUMMARY_SIZE*2, ptr, MPN_TRIO_SUMMARY_SIZE, trio_sdf );
  McUnlock();
  return 0;
}
/***************************************************************************/
/* initScopeCommand                                                        */
/***************************************************************************/
int initScopeCommand(int forceA, int forceB, int forceC, int forceD, int forceE, int forceF
                   ,int feA, int feB, int feC, int feD, int feE, int feF
                   ,int posA, int posB, int posC, int posD, int posE, int posF )
{
  float val;
  if(rs_param.simulateMC!=0) return TRUE;
  
  tspace.scope.cmd_nr=scope_command_init;
  tspace.scope.arg[0]=forceA;
  tspace.scope.arg[1]=forceB;
  tspace.scope.arg[2]=forceC;
  tspace.scope.arg[3]=forceD;
  tspace.scope.arg[4]=forceE;
  tspace.scope.arg[5]=forceF;
  tspace.scope.arg[6]=feA;
  tspace.scope.arg[7]=feB;
  tspace.scope.arg[8]=feC;
  tspace.scope.arg[9]=feD;
  tspace.scope.arg[10]=feE;
  tspace.scope.arg[11]=feF;
  tspace.scope.arg[12]=posA;
  tspace.scope.arg[13]=posB;
  tspace.scope.arg[14]=posC;
  tspace.scope.arg[15]=posD;
  tspace.scope.arg[16]=posE;
  tspace.scope.arg[17]=posF;
  trio_preset_multiple_registers_tcp( 1, 1+SCOPE_CMD_RTN_IDX, SCOPE_CMD_SIZE*2, (short *)&tspace.scope, trio_sdf);
  val=0;
  usleep(10000);
  trio_read_holding_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&val, 4, trio_sdf );
  while(val==scope_command_init)
  {
    usleep(100000);
    trio_read_holding_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&val, 4, trio_sdf );
  }
  return TRUE;
}
/***************************************************************************/
/* doScopeCommand                                                          */
/***************************************************************************/
int doScopeCommand(void)
{
  if(rs_param.simulateMC!=0) return TRUE;
  tspace.scope.cmd_nr=scope_command_execute;
  trio_preset_multiple_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&tspace.scope.cmd_nr, trio_sdf);
  return TRUE;
}




tmpnFloat actuatorToJoint(int n, int i, float length) {
  tmpnFloat val = tspace.scope.buffer[n+7+i*(int)length];
  tmpnFloat dval;
  //val = actuator fra trio
  //subtract calibration values to get logic actuator position
  switch(n) {
    case 0:
      return MMTOM(trobot->m_max.z-(val-trobot->m_jointCalib.a)*trobot->m_sign.name.a);
    case 1:
      //negate (see robot->m_joint.b = -joint.b; in libmpnrobot)
      return (-(val-trobot->m_jointCalib.b)*trobot->m_sign.name.b+90.0);
    case 2:
      //negate (see robot->m_joint.c = -joint.c; in libmpnrobot)
      return (-(val-trobot->m_jointCalib.c)*trobot->m_sign.name.c);
    case 3:
      return ((val-trobot->m_jointCalib.d)*trobot->m_sign.name.d);
    case 4:
      dval = tspace.scope.buffer[n+6+i*(int)length];
      return ((val-trobot->m_jointCalib.e)*trobot->m_sign.name.e + (dval-trobot->m_jointCalib.d)*trobot->m_sign.name.d/trobot->m_gearing.name.e);
    case 5:
      return MMTOM((val-trobot->m_jointCalib.f)*trobot->m_sign.name.f);
  }
  return -1;
}

/***************************************************************************/
/* getScopeCommand                                                         */
/***************************************************************************/

int getScopeCommand(int id)
{
  float scopestate,type,length,numofsamples,vala,valb,valc,vald,vale,valf;
  char filename[256];
  char buf[256];
  short *ptr;
  int total,i;
	i=0;

  if(rs_param.simulateMC!=0) return TRUE;
  trio_read_holding_registers_tcp( 1, 1+SCOPE_TYPE, 2, (short *)&type, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_LENGTH, 2, (short *)&length, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_NUMOFSAMPLES, 2, (short *)&numofsamples, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_ASCALE, 2, (short *)&vala, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_BSCALE, 2, (short *)&valb, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_CSCALE, 2, (short *)&valc, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_DSCALE, 2, (short *)&vald, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_ESCALE, 2, (short *)&vale, 4, trio_sdf );
  trio_read_holding_registers_tcp( 1, 1+SCOPE_FSCALE, 2, (short *)&valf, 4, trio_sdf );
  sprintf(filename,"scope%d",id);
  sprintf(buf,"scope%d: type=%d length=%d numofsamples=%d scale a=%d b=%d c=%d d=%d e=%d f=%d\n"
          ,id
          ,(int)type
          ,(int)length
          ,(int)numofsamples
          ,(int)vala
          ,(int)valb
          ,(int)valc
          ,(int)vald
          ,(int)vale
          ,(int)valf);
  printf("scope%d: type=%d length=%d numofsamples=%d scale a=%d b=%d c=%d d=%d e=%d f=%d\n"
          ,id
          ,(int)type
          ,(int)length
          ,(int)numofsamples
          ,(int)vala
          ,(int)valb
          ,(int)valc
          ,(int)vald
          ,(int)vale
          ,(int)valf);
  saveScopeSample(filename,buf);
  total=0;
nextline:
//  usleep(5000);
 //wait until scope has moved some data down from 200000 to <65000
  trio_read_holding_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&scopestate, 4, trio_sdf );
  while(scopestate!=scope_command_nextsaved&&scopestate!=scope_command_copydone)
  {
//    printf("wating\n");
    usleep(1);
    trio_read_holding_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&scopestate, 4, trio_sdf );
  }
  ptr = (short*)&tspace.scope.buffer[0];
  trio_read_holding_registers_tcp( 1, 1+SCOPE_BUFFER, SCOPE_BUFFER_SIZE*2, ptr, SCOPE_BUFFER_SIZE_BYTE, trio_sdf);
  sprintf(buf,"%0.0f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n"
    ,tspace.scope.buffer[0+i*(int)length] //t
    ,tspace.scope.buffer[1+i*(int)length] //
    ,tspace.scope.buffer[2+i*(int)length] //
    ,tspace.scope.buffer[3+i*(int)length] //
    ,tspace.scope.buffer[4+i*(int)length] //
    ,tspace.scope.buffer[5+i*(int)length] //
    ,tspace.scope.buffer[6+i*(int)length] //
    ,tspace.scope.buffer[7+i*(int)length] //
    ,tspace.scope.buffer[8+i*(int)length] //
    ,tspace.scope.buffer[9+i*(int)length] //
    ,tspace.scope.buffer[10+i*(int)length] //
    ,tspace.scope.buffer[11+i*(int)length] //
    ,tspace.scope.buffer[12+i*(int)length] //
    );
    total++;
    saveScopeSample(filename,buf);

/*  for(i=0;total<(int)numofsamples&&i<(int)(SCOPE_BUFFER_SIZE/(int)length);i++)
  {
    tmpnFloat torq[6],pos[6];
    tmpnFloat nomcur[6]={9.375,15.000,9.375,2.500,2.500,2.500}; //define other place maybe!
    int j;
    for (j=0;j<6;j++) {
      torq[j] = tspace.scope.buffer[j+1+i*(int)length];
      if(torq[j]>32767) torq[j]-=65536;
      //Output current (Amps) = Pr65 * (2 * drive nominal current) / 32767
      torq[j]=torq[j]*1.6*nomcur[j]*2*trobot->m_sign.array[j]*trobot->m_gearing.array[j]/32767;
      pos[j] = actuatorToJoint(j,i,length);
    }
    //type=1
    sprintf(buf,"t=%0.0f fa=%0.4f fb=%0.4f fc=%0.4f fd=%0.4f fe=%0.4f ff=%0.4f pa=%0.4f pb=%0.4f pc=%0.4f pd=%0.4f pe=%0.4f pf=%0.4f\n"
      ,tspace.scope.buffer[0+i*(int)length] //t
      ,torq[0]
      ,torq[1]
      ,torq[2]
      ,torq[3]
      ,torq[4]
      ,torq[5]
      ,pos[0]
      ,pos[1]
      ,pos[2]
      ,pos[3]
      ,pos[4]
      ,pos[5]
      );
//    printf("line written\n");
  }*/
  if(scopestate!=scope_command_copydone)
  {
//    printf("next line\n");
    tspace.scope.cmd_nr=scope_command_savenext;
    trio_preset_multiple_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&tspace.scope.cmd_nr, trio_sdf);
    goto nextline;
  }
  tspace.scope.cmd_nr=scope_command_nothing;
  trio_preset_multiple_registers_tcp( 1, 1+SCOPE_CMD_IDX, 2, (short *)&tspace.scope.cmd_nr, trio_sdf);
  return TRUE;
}
/***************************************************************************/
/*                                                                         */
/* MpnCommand functions                                                    */
/*                                                                         */
/***************************************************************************/
//TODO allways use MpnCommand (not trio_preset_multiple_registers_tcp)
int MpnCommand(int cmd)
{
  tspace.mpn_cmd.cmd_nr=cmd;
  if(rs_param.simulateMC!=0) return 0;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_RTN_IDX, MPN_CMD_SIZE*2, (short *)&tspace.mpn_cmd.rtn, trio_sdf);
  return 0;
}
float GetRetur(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+MPN_CMD_RTN_IDX, 2, (short *)&tspace.mpn_cmd.rtn, 4, trio_sdf );
  return tspace.mpn_cmd.rtn;
}
float GetArg(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+MPN_CMD_ARG_IDX, 2, (short *)&tspace.mpn_cmd.arg[0], 4, trio_sdf );
  return tspace.mpn_cmd.arg[0];
}

int SetHomeAll(void)
{
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cmd.cmd_nr=mpn_command_set_mpn_home_all;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&tspace.mpn_cmd.cmd_nr, trio_sdf);
  return 0;
}

int ResetAxis(void)
{
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cmd.cmd_nr=mpn_command_resetaxis;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&tspace.mpn_cmd.cmd_nr, trio_sdf);
  return 0;
}

int SetUnitsAndDefaults(void)
{
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cmd.cmd_nr=mpn_command_set_units_and_defaults;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&tspace.mpn_cmd.cmd_nr, trio_sdf);
  return 0;
}

int GetReply(void)
{
  if(rs_param.simulateMC!=0) return 1;
  float val=0.0;
  trio_read_holding_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&val, 4, trio_sdf );
  return (int)val;
}

int CmdStartup(void)
{
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cmd.cmd_nr=mpn_command_startup;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&tspace.mpn_cmd.cmd_nr, trio_sdf);
  return 0;
}

int SetDefPos(void)
{
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cmd.cmd_nr=mpn_command_set_defpos;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CMD_IDX, 2, (short *)&tspace.mpn_cmd.cmd_nr, trio_sdf);
  return 0;
}

float autoHomeSensor(void)
{
  float val;
  if(rs_param.simulateMC!=0) return 0;
  MpnCommand(mpn_command_set_mpn_auto_home);
  do { usleep(100000); val = GetReply(); } while(val!=1);
  val = GetRetur();
  return val;
}

int mpnIn(void)
{
  float val;
  MpnCommand(mpn_command_get_in);
  val = GetReply();
  while(val!=1) 
  { 
    usleep(10000); 
    val = GetReply(); 
  };
  val = GetRetur();
  return val;
}

int mpnOut(int idx, int state)
{
  float val;
  
  tspace.mpn_cmd.arg[0] = idx;
  tspace.mpn_cmd.arg[1] = state;
  MpnCommand(mpn_command_set_out);
  val = GetReply();
  while(val!=1) 
  { 
    usleep(10000); 
    val = GetReply(); 
  };
  val = GetRetur();
  return val;
}

/***************************************************************************/
/* RunPath                                                                 */
/***************************************************************************/
int RunPath(tmpnPathDef *pathdef)
{
  long rc;
  float val;
  int idx;
  int rtn=0;
  clock_t start;
  int *pathtype=NULL;

  pathtype = getMachineValuePtr(getMachineIdx("Robot"),"pathtype");
  if(rs_param.mc_task_debug>0) start = times(NULL);

  idx=pathdef->idx;
  tspace.mpn_cmd.arg[0] = idx;
  *pathtype=pathdef->pathtype;
  rc = MpnCommand(mpn_command_run_path);
  if(rc < 0)
  {
    printf("rc<0: runpath tid %f\n",(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
    return -1;
  }
  do
  {
    usleep(10000);
    val = GetReply();
  }
  while(val!=1);

  if((rtn = (int)GetRetur())!=0)
  {
    
  }
  *pathtype=0;
  if(rs_param.mc_task_debug>0) 
    printf("Path %30s idx=%05d execute %8.3f\n"
        //   ,(float)(times(NULL)-gstart)/(float)sysconf(_SC_CLK_TCK)
	   ,pathdef->name
     ,idx
     ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  
  return rtn;
}
/***************************************************************************/
/* RunMacro                                                                */
/***************************************************************************/
int RunMacro(int idx, int p0, int p1, int p2, COMMANDSTRUCT *cmd, volatile COMMANDSTRUCT **pcmd )
{
  char s[256];
  float val;
  int numoflayers,rtn=0;
  int pthreadret;
  clock_t start;
  if(rs_param.mc_task_debug>0) start = times(NULL);
  
//  printf("Macro %d %d %d %d begin\n",idx,p0,p1,p2);
  tspace.mpn_cmd.arg[0] = p0;
  tspace.mpn_cmd.arg[1] = p1;
  tspace.mpn_cmd.arg[2] = p2;
  MpnCommand(idx);
  do
  {
    usleep(10000);
    val = GetReply();
  }
  while(val!=1);
  val = GetRetur();
  if(val<0)
  {
    //TODO dont use return value as num of layers
    numoflayers=val;
    numoflayers=-numoflayers;
    sprintf(s,"Number of layers found: %d",numoflayers);
    printf("%s\n",s);
    logMsg(s);

    pthreadret=pthread_mutex_lock(&script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
    sprintf(rs_param.scriptname,"%s%d",rs_param.script,numoflayers);
    
    signalLoadCommandScript();
    
//    pthreadret=pthread_mutex_unlock(&script_mutex);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//    pthreadret=pthread_cond_signal(&upload_cond);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
    
//    pthreadret=pthread_mutex_lock(&script_mutex);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
//    printf("Start wating for script_cond\n");
    while(scriptLoaded==FALSE&&pthreadret==0)
      pthreadret=pthread_cond_wait(&script_cond, &script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
//    printf("End wating for script_cond\n");
    pthreadret=pthread_mutex_unlock(&script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
    *pcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
    rtn=0;
    if(rs_param.mc_task_debug>0) 
      printf("Macro %d execute %f\n",idx,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  }
  else
  {
    *pcmd=getNextRunCommand(cmd);
    rtn=val;
    if(rs_param.mc_task_debug>1) 
      printf("Macro %d execute %f\n",idx,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  }
 return rtn;
}
/***************************************************************************/
/* RunScope                                                                */
/***************************************************************************/
int RunScope(int p0, int p1, int p2)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) start = times(NULL);
//  printf("Scope %d %d begin\n",p0,p1);
  if(p0==1)
  {
    initScopeCommand(1,1,1,1,1,1 ,0,0,0,0,0,0 ,0,0,0,0,0,0);
  }
  else if(p0==2)
  {
   doScopeCommand();
  }
  else if(p0==3)
  {
    getScopeCommand(p1);
  }
  if(rs_param.mc_task_debug>1) 
    printf("Scope %d %d execute %f\n",p0,p1,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}


extern int testState(int machine, int state);
extern int waitState(int machine, int state);
extern int setState(int machine, int state);
/***************************************************************************/
/* RunOut                                                                  */
/***************************************************************************/
int RunOut(COMMANDSTRUCT *cmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
  mpnOut(((OUTPUTSTRUCT*)cmd->data)->p,((OUTPUTSTRUCT*)cmd->data)->state);
  if(rs_param.mc_task_debug>1) 
    printf("Out %d = %d execute %f\n"
      ,((OUTPUTSTRUCT*)cmd->data)->p
      ,((OUTPUTSTRUCT*)cmd->data)->state
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* RunIn                                                                   */
/***************************************************************************/
int RunIn(COMMANDSTRUCT *cmd)
{
  int rtn=0,val;
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
  val=mpnIn();
  if(rs_param.mc_task_debug>1) 
    printf("In %d = %d  execute %f\n"
      ,((INPUTSTRUCT*)cmd->data)->p
      ,val & (0x0001 << ((INPUTSTRUCT*)cmd->data)->p) ? TRUE : FALSE
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return rtn;
}
/***************************************************************************/
/* RunTestEvent                                                            */
/***************************************************************************/
int RunTestEvent(COMMANDSTRUCT *cmd)
{
  int ret;
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
	ret=testState(((EVENTSTRUCT*)cmd->data)->machine,((EVENTSTRUCT*)cmd->data)->state);
	if(rs_param.mc_task_debug>1) 
    printf("TestEvent %d %s %s execute %f\n"
      ,((EVENTSTRUCT*)cmd->data)->type
      ,((EVENTSTRUCT*)cmd->data)->machineName
      ,((EVENTSTRUCT*)cmd->data)->stateName
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return ret;
}
/***************************************************************************/
/* RunSleep                                                                */
/***************************************************************************/
int RunSleep(COMMANDSTRUCT *cmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
  usleep(((SLEEPSTRUCT*)cmd->data)->ms*1000);
  if(rs_param.mc_task_debug>1) 
    printf("Sleep %d execute %f\n"
      ,((SLEEPSTRUCT*)cmd->data)->ms
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* RunSignalEvent                                                          */
/***************************************************************************/
int RunSignalEvent(COMMANDSTRUCT *cmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
  if(((EVENTSTRUCT*)cmd->data)->type==1)
  {
    setState(((EVENTSTRUCT*)cmd->data)->machine,((EVENTSTRUCT*)cmd->data)->state);
    if(rs_param.mc_task_debug>1) 
      printf("SignalEvent %d %s %s execute %f\n"
        ,((EVENTSTRUCT*)cmd->data)->type
        ,((EVENTSTRUCT*)cmd->data)->machineName
        ,((EVENTSTRUCT*)cmd->data)->stateName
        ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  }
  return 0;
}
/***************************************************************************/
/* RunTuning                                                               */
/***************************************************************************/
int RunTuning(COMMANDSTRUCT *cmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) 
    start = times(NULL);
  
  SetVR(((TUNINGSTRUCT*)cmd->data)->vr,((TUNINGSTRUCT*)cmd->data)->value);
    
  if(rs_param.mc_task_debug>1) 
    printf("Tuning %s %d %3.2f execute %f\n"
      ,((TUNINGSTRUCT*)cmd->data)->name
      ,((TUNINGSTRUCT*)cmd->data)->vr
      ,((TUNINGSTRUCT*)cmd->data)->value
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* RunGoto                                                                 */
/***************************************************************************/
int RunGoto(COMMANDSTRUCT *cmd, volatile COMMANDSTRUCT **pcmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) start = times(NULL);
  *pcmd=getLabelCommand((COMMANDSTRUCT*)tworkcell->m_root,((GOTOSTRUCT*)cmd->data)->label);
  if(rs_param.mc_task_debug>1) 
    printf("Goto %s execute %f\n"
      ,((GOTOSTRUCT*)cmd->data)->label
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;  
}
/***************************************************************************/
/* RunLabel                                                                */
/***************************************************************************/
int RunLabel(COMMANDSTRUCT *cmd,volatile COMMANDSTRUCT **pcmd)
{
  clock_t start;
  if(rs_param.mc_task_debug>1) start = times(NULL);
  *pcmd=getNextRunCommand(cmd);
  if(rs_param.mc_task_debug>1) 
    printf("Label %s execute %f\n"
      ,((LABELSTRUCT*)cmd->data)->label
      ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;  
}
/***************************************************************************/
/* moveAxis                                                                */
/***************************************************************************/
int moveAxis(COMMANDSTRUCT *cmd)
{
  float val;
  tspace.mpn_cmd.arg[0] = ((MOVEAXISSTRUCT*)cmd->data)->axis;
  tspace.mpn_cmd.arg[1] = ((MOVEAXISSTRUCT*)cmd->data)->speed;
  tspace.mpn_cmd.arg[2] = ((MOVEAXISSTRUCT*)cmd->data)->accel;
  tspace.mpn_cmd.arg[3] = ((MOVEAXISSTRUCT*)cmd->data)->decel;
  tspace.mpn_cmd.arg[4] = ((MOVEAXISSTRUCT*)cmd->data)->distance;
  tspace.mpn_cmd.arg[5] = ((MOVEAXISSTRUCT*)cmd->data)->wait;
  MpnCommand(mpn_command_moveaxis);
  if(((MOVEAXISSTRUCT*)cmd->data)->wait==1)
  {
    do { usleep(10000); val = GetReply(); } while(val!=1);
  }
  val = GetRetur();
  return val;
}
/***************************************************************************/
/* cancelAxis                                                              */
/***************************************************************************/
int cancelAxis(COMMANDSTRUCT *cmd)
{
  float val;
  tspace.mpn_cmd.arg[0] = ((CANCELAXISSTRUCT*)cmd->data)->axis;
  MpnCommand(mpn_command_cancelaxis);
  if(((CANCELAXISSTRUCT*)cmd->data)->wait==1)
  {
    do { usleep(10000); val = GetReply(); } while(val!=1);
  }
  val = GetRetur();
  return val;
}

/***************************************************************************/
/* RunCall                                                                */
/***************************************************************************/
int RunCall(COMMANDSTRUCT *cmd, volatile COMMANDSTRUCT **pcmd)
{
  clock_t start;
  int pthreadret;
  if(rs_param.mc_task_debug>0) start = times(NULL);
//  printf("Call %s %d begin\n"
//        ,((CALLSTRUCT*)cmd->data)->script  
//        ,((CALLSTRUCT*)cmd->data)->lag
//         );

  pthreadret=pthread_mutex_lock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  if(((CALLSTRUCT*)cmd->data)->lag>=0)
  {
    sprintf(rs_param.scriptname,"%s%d"
          ,((CALLSTRUCT*)cmd->data)->script
          ,((CALLSTRUCT*)cmd->data)->lag);
  }
  else
    sprintf(rs_param.scriptname,"%s",((CALLSTRUCT*)cmd->data)->script);
  
  signalLoadCommandScript();
   
//  pthreadret=pthread_mutex_unlock(&script_mutex);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//  pthreadret=pthread_cond_signal(&upload_cond);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//  pthreadret=pthread_mutex_lock(&script_mutex);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
//  printf("Start wating for script_cond\n");
  while(scriptLoaded==FALSE&&pthreadret==0)
    pthreadret=pthread_cond_wait(&script_cond,&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//  printf("End wating for script_cond\n");
  pthreadret=pthread_mutex_unlock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  
  *pcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);

  if(rs_param.mc_task_debug>0) 
    printf("Call execute %f\n",(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* RunJumpLayer only used by NYHUUS                                        */
/* TODO rename to generateProgram                                          */
/***************************************************************************/
int RunJumpLayer(COMMANDSTRUCT *cmd, volatile COMMANDSTRUCT **pcmd)
{
  clock_t start;
  int pthreadret;
  if(rs_param.mc_task_debug>0) start = times(NULL);

  if(strcmp(((JUMPLAYERSTRUCT*)cmd->data)->function,"fotoFriMM")==0)
  {
    pthreadret=pthread_mutex_lock(&script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

    //TODO new getFotoFriMM function
//  signalGenerateProgram(getFotoFriMM());

//    pthreadret=pthread_mutex_unlock(&script_mutex);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//    pthreadret=pthread_cond_signal(&upload_cond);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//    pthreadret=pthread_mutex_lock(&script_mutex);
//    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//    printf("Start wating for script_cond\n");
    while(jumpToLayer>=0&&pthreadret==0)
      pthreadret=pthread_cond_wait(&script_cond, &script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
//      printf("End wating for script_cond\n");
    pthreadret=pthread_mutex_unlock(&script_mutex);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

    *pcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
  }
  else
  {
    printf("ukendt func\n");
    exit(1);
  }
  if(rs_param.mc_task_debug>0) 
    printf("JumpLayer %d execute %f\n",jumpToLayer,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* RunResetPreload                                                         */
/***************************************************************************/
int RunResetPreload(COMMANDSTRUCT *cmd, volatile COMMANDSTRUCT **pcmd)
{
  clock_t start;
  int pthreadret;
  if(rs_param.mc_task_debug>0) start = times(NULL);

  pthreadret=pthread_mutex_lock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  
  signalResetPreload(((RESETPRELOADSTRUCT*)cmd->data)->loadgroup);  
   
//  pthreadret=pthread_mutex_unlock(&script_mutex);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

//  usleep(100000);

//  pthreadret=pthread_cond_signal(&upload_cond);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

    
//  pthreadret=pthread_mutex_lock(&script_mutex);
//  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);

  if(rs_param.mc_task_debug==3) printf("Start wait ResetPreload %d\n",((RESETPRELOADSTRUCT *)cmd->data)->loadgroup);

  while(resetPreload==TRUE&&pthreadret==0) 
  {
    if(rs_param.mc_task_debug==3) printf("Start wait ResetPreload %d\n",((RESETPRELOADSTRUCT *)cmd->data)->loadgroup);
    pthreadret=pthread_cond_wait(&script_cond, &script_mutex);
  }

  if(rs_param.mc_task_debug==3) printf("Slut wait ResetPreload %d\n",((RESETPRELOADSTRUCT *)cmd->data)->loadgroup);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  pthreadret=pthread_mutex_unlock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);


  *pcmd=getNextRunCommand(cmd);

  if(rs_param.mc_task_debug>0) 
    printf("ResetPreload %d execute %f\n",((RESETPRELOADSTRUCT *)cmd->data)->loadgroup,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK));
  return 0;
}
/***************************************************************************/
/* ParseCmd                                                                */
/***************************************************************************/
void ParseCmd(volatile COMMANDSTRUCT **pcmd)
{
  int pthreadret;
  COMMANDSTRUCT *cmd;
  cmd=(COMMANDSTRUCT*)*pcmd;

  switch(cmd->type) {
    case STOP :
        *roboError = 1;
      break;
    case ERROR:
        *roboError=((ERRORSTRUCT*)cmd->data)->number;
      break;
    case MACRO :
        *roboError=RunMacro(((MACROSTRUCT*)cmd->data)->idx,
                    ((MACROSTRUCT*)cmd->data)->parameter0,
                    ((MACROSTRUCT*)cmd->data)->parameter1,
                    ((MACROSTRUCT*)cmd->data)->parameter2,
                    cmd,
                    pcmd);
      break;
    case PATH:
      if(rs_param.simulateMC==0)
      {

        pthreadret=pthread_mutex_lock(&uploaddone_mtx);
        if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
      
        if(rs_param.mc_task_debug==3)
        printf("Start wating for uploaddone_cond path.id=%d\n",((PATHSTRUCT*)cmd->data)->tpathdef.id);
        while(((volatile PATHSTRUCT*)cmd->data)->tpathdef.idx==-1&&pthreadret==0
					&&(testMachineState(mcstm,"ST_PAUSING")||testMachineState(mcstm,"ST_RUNNING")))
        {
          if(rs_param.mc_task_debug==3)
            printf("start wating for %s id=%d\n",((volatile PATHSTRUCT*)cmd->data)->tpathdef.name,((volatile PATHSTRUCT*)cmd->data)->tpathdef.id);
	        pthreadret=pthread_cond_wait(&uploaddone_cond, &uploaddone_mtx);
        }
        if(rs_param.mc_task_debug==3)
          printf("End wating for uploaddone_cond\n");
        pthreadret=pthread_mutex_unlock(&uploaddone_mtx);
      } 
      if(*roboError==0&&(testMachineState(mcstm,"ST_PAUSING")||testMachineState(mcstm,"ST_RUNNING")))
      {
        *roboError=RunPath(&((PATHSTRUCT*)cmd->data)->tpathdef);
                //normal end of mpn path
        if(*roboError==0)
        {
          ctrlNumOfUploads[((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup]--;
          ((PATHSTRUCT*)cmd->data)->tpathdef.idx=-1;
          //signal next upload
//          pthreadret=pthread_cond_signal(&upload_cond);
          *pcmd=getNextRunCommand(cmd);
        }
      }
      break;
    case IN:
        RunIn(cmd);
        *pcmd=getNextRunCommand(cmd);
      break;
    case OUT:
        RunOut(cmd);
        *pcmd=getNextRunCommand(cmd);
      break;
    case SLEEP:
        RunSleep(cmd);
        *pcmd=getNextRunCommand(cmd);
      break;
    case WAITEVENT:
        if(RunTestEvent(cmd))
          *pcmd=getNextRunCommand(cmd);
        else
          usleep(100000);
      break;
     case TESTEVENT:
        if(RunTestEvent(cmd))
	        *pcmd=getNextRunCommand(cmd);
	      else
	        *pcmd=getNextRunCommandAtSameLevel(cmd);
      break;
    case SIGNALEVENT :
        RunSignalEvent(cmd);
        *pcmd=getNextRunCommand(cmd);
      break;
    case TUNING:
        RunTuning(cmd);
        *pcmd=getNextRunCommand(cmd);
			break;
    case SETSPEED:
      if ((accesslevel<=OPERATORLEVEL)&&(rs_param.workcellid!=305)&&(rs_param.workcellid!=306))
      {
				SetSpeedFactor(((SETSPEEDSTRUCT*)cmd->data)->factor);
      }
      *pcmd=getNextRunCommand(cmd);
      break;
    case SCOPE :
        RunScope(((SCOPESTRUCT*)cmd->data)->parameter0,
                           ((SCOPESTRUCT*)cmd->data)->parameter1,
                           ((SCOPESTRUCT*)cmd->data)->parameter2);
        *pcmd=getNextRunCommand(cmd);
      break;
    case GOTO:
        RunGoto(cmd,pcmd);
      break;
    case LABEL:
        RunLabel(cmd,pcmd);
      break;
    case RESETPRELOAD:
        RunResetPreload(cmd,pcmd);
      break;
    case CALL:
        RunCall(cmd,pcmd);
      break;
    case JUMPLAYER:
        RunJumpLayer(cmd,pcmd);
      break;
    case COUNTER:
        libRunCounter(cmd,(COMMANDSTRUCT**)pcmd);
        char *p = getCounterValue("restart");
        if(strcmp(p,"restart"))
   	      *restart = atoi(p);
      break;
    default:
      *pcmd=getNextRunCommand(cmd);
      break;
  }
  if(*pcmd==NULL&&*roboError==0)
  {
    *roboError = 1;
  }
}

//returns mpnhome
float moveToHomeSensor(int axis)
{
  float val;
  tspace.mpn_cmd.arg[0] = axis;
  MpnCommand(mpn_command_movehome);
  do { usleep(10000); val = GetReply(); } while(val!=1);
  val = GetRetur();
  return val;
}

/***************************************************************************/
/*                                                                         */
/* Functions  that write to TABLESPACE                                     */
/*                                                                         */
/***************************************************************************/
int SetTraficLight(int state)
{
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_running = state;
  ptr = (short*)&tspace.mpn_running;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_RUNNING, 2, ptr, trio_sdf);
  return 0;
}

int CancelMc(int v)
{
  short *ptr;
  if(rs_param.simulateMC!=0) return 0;
  tspace.mpn_cancel = v;
  ptr = (short*)&tspace.mpn_cancel;
  trio_preset_multiple_registers_tcp( 1, 1+MPN_CANCEL, 2, ptr, trio_sdf);
  return 0;
}
/***************************************************************************/
/*                                                                         */
/* Functions used by JogAxisUser                                           */
/*                                                                         */
/***************************************************************************/
float GetAktuelSpeed(int axis)
{
  return tspace.axis.array[axis].speed;
}

float GetAktuelAccel(int axis)
{
  return tspace.axis.array[axis].accel;
}

float GetAktuelDecel(int axis)
{
  return tspace.axis.array[axis].decel;
}
/***************************************************************************/
/* Functions used by JogAxisUser                                           */
/***************************************************************************/
//get running state is set by TRIO and used to display a message on screen
int GetRunningState(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+MPN_STATE, 2, (short*)&tspace.mpn_state, 4, trio_sdf );
  return tspace.mpn_state;
}

int GetBasicError(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+MPN_TRIO_BASIC_ERROR, 2, (short*)&tspace.mpn_trio_basic_error, 4, trio_sdf );
  return tspace.mpn_trio_basic_error;
}

int GetBasicLineError(void)
{
  if(rs_param.simulateMC!=0) return 0;
  trio_read_holding_registers_tcp( 1, 1+MPN_TRIO_BASIC_LINE_ERROR, 2, (short*)&tspace.mpn_trio_basic_line_error, 4, trio_sdf );
  return tspace.mpn_trio_basic_line_error;
}



int GetNumOfPath(int sfp, int loadgroup)
{
  short *ptr;
  float buffer;
  int val=0;
  if(rs_param.simulateMC!=0) return 0;
  ptr = (short*)&buffer;
  trio_read_holding_registers_tcp( 1, 1 + NUM_OF_PATH_INDEX(loadgroup), 2, ptr, 4, sfp );
  val = (int)buffer;
  return val;
}

int pathdatasize(int numberofaxis, int numofposhints, int numberofsamples)
{
  /* Structure of pathdata uploaded into tablespace in TRIO */

  //numberofaxis
  //maxTime
  //pathtype
  //unused
  //numofsamples
  //numofposhints
  //poshint[0].time
  //...
  //poshint[last].time
  //axisA data first
  //...
  //axisA data last
  //axisB data first
  //...
  //axisB data last
  //axisC data first
  //...
  //axisC data last
  //axisD data first
  //...
  //axisD data last
  //axisE data first
  //...
  //axisE data last
  //axisF data first
  //...
  //axisF data last
  //axisVT data first
  //...
  //axisVT data last
  return 1+5+numofposhints+numberofsamples*numberofaxis;
}

int GetNewPathIndex(int sfp, int currentnumofpath,int loadgroup)
{
  int numberofaxis,numberofsamples,addresseofaxisdata,numberofposhints;
  float buffer=0.0;
  short *ptr;

  ptr = (short*)&buffer;
    
  if(currentnumofpath==0)
    return FIRST_PATH_INDEX(loadgroup);

  if(rs_param.simulateMC!=0) return 0;
  //read addresseofaxisdata
  trio_read_holding_registers_tcp( 1, PATH_INDEX(loadgroup)+currentnumofpath, 2, ptr, 4, sfp );
  usleep(1);
  addresseofaxisdata = (int)buffer;

  //read number of axis
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata, 2, ptr, 4, sfp );
  usleep(1);
  numberofaxis = (int)buffer;

  //read numberofposhints
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata+5, 2, ptr, 4, sfp );
  usleep(1);
  numberofposhints = (int)buffer;

  //read numberofsamples
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata+4, 2, ptr, 4, sfp );
  usleep(1);
  numberofsamples = (int)buffer;
  
/*  printf("***** axisdata=%d pathdatasize(%d,%d,%d)=%d\n"
        ,addresseofaxisdata,numberofaxis,numberofposhints,numberofsamples
        ,pathdatasize(numberofaxis,numberofposhints,numberofsamples));*/
  return addresseofaxisdata + pathdatasize(numberofaxis,numberofposhints,numberofsamples);
}

int SetPathTables(int sfp, tmpnPath *pPath, tmpnPathDef *pathdef)
{
  int loadgroup;
  int psize,i, s, index, sidx;
  int numofpath;
  int numSamples;
  float newpathaddr;
  float newnumofpath=0.0;
  float endaddr;
  float xbuffer[60000];
  clock_t start;
  short *pnewnumofpath=(short*)&newnumofpath;
  short *pnewpathaddr=(short*)&newpathaddr;
  short *xptr=(short*)&xbuffer;
    
  loadgroup=pathdef->loadgroup;
  
  if(!isRunning(mcstm)) return -1;
  
  if(ctrlNumOfUploads[loadgroup] >= MAX_PATH_UPLOAD) return -1;
 
 //******************************************
 //* find the new addr for this path        *
 //******************************************
  if(rs_param.mc_task_debug>2) start = times(NULL);
  numofpath = GetNumOfPath(sfp,loadgroup);
  newpathaddr = GetNewPathIndex(sfp, numofpath,loadgroup);
  endaddr=newpathaddr+pathdatasize(NUMBER_OF_AXIS,pathdef->maxpidx,pPath->maxidx);
  if(rs_param.mc_task_debug==3)
    printf("numofpath=%d,newpathaddr=%f,endaddr=%f\n",numofpath,newpathaddr,endaddr);
  //is maximum number of preloaded path's reached
 //is maximum index number reached
  if(numofpath > MAX_PATH_INDEX-1)
  {
    numofpath = 0;
    newpathaddr = FIRST_PATH_INDEX(loadgroup);
  }
  if(endaddr>NUM_OF_PATH_INDEX(loadgroup)+UPLOADGROUP_SIZE-1) 
  {
    newpathaddr = FIRST_PATH_INDEX(loadgroup);
    numofpath = 0;
  }
  index = PATH_INDEX(loadgroup) + numofpath;
  newnumofpath = numofpath+1;
  numSamples = 0;
  /******************************************
  * fill local table with data              *
  ******************************************/
  sidx=0;
  xbuffer[sidx++] = NUMBER_OF_AXIS;      //Number of axis in path a,b,c,d,e,vt
  xbuffer[sidx++] = pathdef->maxTime;    //maxTime
  xbuffer[sidx++] = pathdef->pathtype;   //pathtype
  xbuffer[sidx++] = 0;                   //disp
  xbuffer[sidx++] = pPath->maxidx;       //number of samples in axisdata common for all axis
  xbuffer[sidx++] = pathdef->maxpidx;    //numofposhints
  for(s=0;s<pathdef->maxpidx;s++) xbuffer[sidx++] = pathdef->poshint[s].time;
  for(i=0; i<NUMBER_OF_AXIS; i++)
  {
    if(i<6)
      for(s=0;s<pPath->maxidx;s++) xbuffer[sidx++] = pPath->position[s].actuatorSpace.array[i];
    else
      for(s=0;s<pPath->maxidx;s++) xbuffer[sidx++] = pPath->position[s].t;
  }
  /******************************************
  * send local table to mc                  *
  ******************************************/
  psize=pathdatasize(NUMBER_OF_AXIS,pathdef->maxpidx,pPath->maxidx);
  for(i=0; i<psize; i+=10)
  {
    if(!isRunning(mcstm))
    {
      if(rs_param.mc_task_debug==3) 
        printf("SetPathTables 7: NOT RUNNING\n");
      return -1;
    }
    trio_preset_multiple_registers_tcp( 1,1+newpathaddr+i, 20, &xptr[i*2], sfp);
    usleep(1);
  }
  /******************************************
  * update mc path index                    *
  ******************************************/
  trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(loadgroup), 2, pnewnumofpath, sfp);
  usleep(1);
  trio_preset_multiple_registers_tcp( 1, 1+PATH_INDEX(loadgroup) + numofpath, 2, pnewpathaddr, sfp);
  usleep(1);
  tspace.path_index[numofpath] = newpathaddr;
  tspace.num_of_path_index = newnumofpath;
  ctrlNumOfUploads[loadgroup]++;
  if(rs_param.mc_task_debug>2) printf("upload %s %f for %d regs float, bane %d i buffer %f loadgroup=%d\n"
  ,buffer0.tpathdef->name
  ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK)
  ,psize, index, newpathaddr, loadgroup);
  return index;
}



int SetSpeed(int axis, float val)
{
  tspace.axis.array[axis].speed = val;
  return SetAxisParamValues(axis, 0);
}

int SetAccel(int axis, float val)
{
  tspace.axis.array[axis].accel = val;
  return SetAxisParamValues(axis, 0);
}

int SetDecel(int axis, float val)
{
  tspace.axis.array[axis].decel = val;
  return SetAxisParamValues(axis, 0);
}

static void ResetLoadBuffer(int loadgroup)
{
  short *ptr;
  float buffer = 0.0;
  ResetCmdLoadBuffer((COMMANDSTRUCT*)tworkcell->m_root,loadgroup); //clear all preloaded path ((PATHSTRUCT*)prcmd->data)->idx = -1;
  ptr = (short*)&buffer;
  ctrlNumOfUploads[loadgroup]  = 0;
  if(rs_param.simulateMC!=0) 
  {
    usleep(1);
  }
  else
  {
    usleep(1);
    trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(loadgroup), 2, ptr, trio_sdf);
  }
}

COMMANDSTRUCT *nextpathcmd[MAXLOADGROUP];

int UploadNextPath(int sfp)
{
  int pthreadret;
  long rc=-1;
  int pnum;
  int level=0;
  int i;
  int runUpload=FALSE;
  
  pthreadret=pthread_mutex_lock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  //only one off scriptLoaded and jumpToLayer can be active at a time
  if(scriptLoaded==FALSE)
  {
    RemoveAllCommands((COMMANDSTRUCT**)&tworkcell->m_root);
    if(rs_param.mc_task_debug>0) printf("%s loaded ",rs_param.scriptname);
    tworkcell->m_root=LoadCommandScript(rs_param.scriptname,0);
    if(tworkcell->m_root==NULL)
    {
      printf("script %s not found\n",rs_param.scriptname);
      exit(1);
    }
    if(tworkcell->m_root)
    {
      for(i=0;i<MAXLOADGROUP;i++)
      {
        ResetLoadBuffer(i);
        nextpathcmd[i]=findItemPathInGroup((COMMANDSTRUCT*)tworkcell->m_root,i);
      }
      scriptLoaded=TRUE;
      if(rs_param.mc_task_debug==3)  
        printf("Signal script_cond\n");
      pthreadret=pthread_cond_signal(&script_cond);
      if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
    }
  }
  else if(jumpToLayer>=0)
  {
    RemoveAllCommands((COMMANDSTRUCT**)&tworkcell->m_root);
    if(rs_param.mc_task_debug==3)  
      printf("Start generateProgram %d\n",jumpToLayer);
    tworkcell->m_root=generateProgram((COMMANDSTRUCT*)tworkcell->m_root,(tmpnRobot*)trobot,&level,jumpToLayer,-1,rs_param.script);
    if(tworkcell->m_root)
    {
      for(i=0;i<MAXLOADGROUP;i++)
      {
        ResetLoadBuffer(i);
        nextpathcmd[i]=findItemPathInGroup((COMMANDSTRUCT*)tworkcell->m_root,i);
      }
      jumpToLayer=-1;
      if(rs_param.mc_task_debug==3)  
        printf("Signal script_cond\n");
      pthreadret=pthread_cond_signal(&script_cond);
      if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
    }
  } 
   //resetPreload can be set by COMMAND RESETPRELOAD
  else if(resetPreload==TRUE)
  {
    if(rs_param.mc_task_debug==3)  
      printf("resetPreload\n");
    for(i=0;i<MAXLOADGROUP;i++)
    {
      if(resetPreloadgroup[i])
      {
        ResetLoadBuffer(i);
        nextpathcmd[i]=findItemPathInGroup((COMMANDSTRUCT*)tworkcell->m_root,i);
        if(rs_param.mc_task_debug==3)
          printf("findItemPathInGroup(%d) = %s\n",i,nextpathcmd[i]==NULL ? "FALSE" : "TRUE");
        resetPreloadgroup[i]=FALSE;        
      }
    }
    resetPreload=FALSE;
    if(rs_param.mc_task_debug==3)  
       printf("Signal script_cond\n");
    pthreadret=pthread_cond_signal(&script_cond);
    if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  }
  pthreadret=pthread_mutex_unlock(&script_mutex);
  if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
  
  for(i=0;i<MAXLOADGROUP;i++)
  {
    if(nextpathcmd[i]!=NULL) runUpload=TRUE; 
  }  
  if(isRunning(mcstm)&&runUpload)
  {
    runUpload=FALSE;
    for(i=0;i<MAXLOADGROUP;i++)
    {
      pnum=0;
      while(isRunning(mcstm)&&pnum>=0&&nextpathcmd[i]!=NULL&&ctrlNumOfUploads[i]<MAX_PATH_UPLOAD)
      {
        buffer0.tpathdef = &((PATHSTRUCT*)nextpathcmd[i]->data)->tpathdef;
        // if bopt then boptcmd 
        if (buffer0.tpathdef->runbopt) 
        {
          //304 send parameter til expand via PScounter
	  expandBopt((tmpnRobot*)trobot,(COMMANDSTRUCT*)nextpathcmd[i]);
	  buffer0.tpathdef->samplesBetweenKeypoints=defpathsamprate;
        }
        else 
        {
	  refreshPath((COMMANDSTRUCT*)nextpathcmd[i]);
        }
        printf("spline=%d maxidx=%d\n",buffer0.tpathdef->spline,buffer0.pathdata.maxidx);
        generatePath((tmpnRobot*)trobot, buffer0.tpathdef, (tmpnPath*)&buffer0.pathdata);
        if(rs_param.simulateMC==0)
          pnum = SetPathTables(sfp, (tmpnPath*)&buffer0.pathdata,buffer0.tpathdef);
        else
        {
          ctrlNumOfUploads[i]++;
          pnum=-1; 
          nextpathcmd[i]=findNextToPreload(nextpathcmd[i]);
        }
        if(pnum >= 0) //upload completed without errors
        {
          runUpload=TRUE;
          pthreadret=pthread_mutex_lock(&uploaddone_mtx);
          if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
          buffer0.tpathdef->idx = pnum;
          rc = pnum;
          pthreadret=pthread_cond_signal(&uploaddone_cond);
          if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
          pthreadret=pthread_mutex_unlock(&uploaddone_mtx);
          if(pthreadret!=0) printf("pthreadret=%d\n",pthreadret);
          nextpathcmd[i]=findNextToPreload(nextpathcmd[i]);
          if(rs_param.mc_task_debug==3)  
            printf("countPreload(%d)=%d  nextpathcmd[0]=%p nextpathcmd[1]=%p\n",i,countPreload((COMMANDSTRUCT*)tworkcell->m_root,i),nextpathcmd[0],nextpathcmd[1]);
        }
      } 
    }
  }
  if(!runUpload)
  {
//    if(rs_param.mc_task_debug==3) printf("upload_task going to sleep %d\n",resetPreload);
//    gettimeofday(&now,NULL);    
//    timeout.tv_sec = now.tv_sec+1;
//    timeout.tv_nsec = now.tv_usec * 1000;
//    pthreadret=pthread_cond_timedwait(&upload_cond, &upload_mtx,&timeout);
//    if(rs_param.mc_task_debug==3) printf("upload_task woken up %d\n",resetPreload);
 //   if(pthreadret!=0&&pthreadret!=110) printf("pthreadret=%d\n",pthreadret);
    usleep(100000);
  }

  return rc;
}


void *upload_task(void * argument )
{
  int i;
  for(i=0;i<MAXLOADGROUP;i++)
  {
    resetPreloadgroup[i] = FALSE;
    ctrlNumOfUploads[i] = 0;
    nextpathcmd[i]=NULL;
  }
	while(!bxUpAndRunning&&!trioUpAndRunning) usleep(100000);
  for(;;)
  {
    UploadNextPath(trio_sdf);
  }

  close( trio_sdf );

  return NULL;
}
/***************************************************************************/
/* InitializeRobostacker                                                   */
/***************************************************************************/
void InitializeRobostacker(void)
{
  short *ptr, i,j;
  float buffer = 0.0;

  
  gstart = times(NULL);
  
  InitializeMcLock();

  if(rs_param.roboStacker>1) return;

  if(rs_param.simulateMC==0)
  {
		j=0;
    while((trio_sdf = set_up_tcp( rs_param.mcIPaddr )) < 0)
    {
      if(j++>10)
      {
        printf("Cannot connect to controller at %s!\n",rs_param.mcIPaddr);
        exit(1);
      }
      else
        usleep(1000000); //WAIT UNTIL TRIO-CONTROLLER HAS STARTED
    }
  }
  buffer0.pathdata.maxidx=0;
//  buffer0.pathdata.position = (tmpnPosition*)malloc(sizeof(tmpnPosition)*MAXPOSITIONS);
  ptr = (short*)&buffer;
  if(rs_param.simulateMC==0)
  {
		usleep(3000000);
    for(i=0;i<MAXLOADGROUP;i++)
    {
      buffer=0;
			trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(i), 2, ptr, trio_sdf);
    }
		trioUpAndRunning++;
  }
}

