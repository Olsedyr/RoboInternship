//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogToolUser.c#
#include <unistd.h>
#include "Bx.h"
#include "formJogTool.h"
#include "rs.h"
#include "tmpnrobot.h"
#include "cmd.h"
#include "stm.h"

extern tmpnJoints m_actuator;
extern volatile unsigned int mposupdatecount;
extern pthread_mutex_t actuator_mutex;
extern volatile int jogikscreen;

static char jogtoolspeed[256];
static char stepmm[256];
static char stepdeg[256];
float jogspeed = 50.0;
float jogstepmm = 50.0;
float jogstepdeg = 2.0;

void WaitForNextMPOS2(void)
{
	unsigned int mposcounter;
	if(rs_param.simulateMC!=0) return;
	mposcounter=mposupdatecount;
	while (mposcounter==mposupdatecount)
	{
		usleep(10000);
	}
	return;
}

int MoveToPosition2(void)
{
	
  long rc;
	rc=MoveAllAbs(trobot->m_actuator.a,trobot->m_actuator.b,trobot->m_actuator.c,trobot->m_actuator.d,trobot->m_actuator.e);
	usleep(100000);
	while (GetMType(1)!=0)
	{
		usleep(100000);
	}
	WaitForNextMPOS2();
	return rc;
}

static tmpnStateMachineValue *jogzmax=NULL;
static int framesstm = -1;

BX_BOOL formJogToolUserInit(HBOX hBox,BX_LPARAM lParam)
{
  BOXSTRUCT *b;
	jogikscreen=1;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSPEED));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSPEED), getLanguageLineFromIdx(langptr, 15, "Speed"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELTILT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELTILT), getLanguageLineFromIdx(langptr, 75, "Tilt"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELTURN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELTURN), getLanguageLineFromIdx(langptr, 76, "Turn"));
  /*	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTILTLEFT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTILTLEFT), getLanguageLineFromIdx(langptr, 7, "Left"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTILTRIGHT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTILTRIGHT), getLanguageLineFromIdx(langptr, 6, "Right"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTURNLEFT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTURNLEFT), getLanguageLineFromIdx(langptr, 7, "Left"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTURNRIGHT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDTURNRIGHT), getLanguageLineFromIdx(langptr, 6, "Right"));
  */
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDRESETTURNTILT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDRESETTURNTILT), getLanguageLineFromIdx(langptr, 294, "Reset"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSTEPDEG));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSTEPDEG), getLanguageLineFromIdx(langptr, 10, "Step"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSTEPMM));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_TEXTLABELSTEPMM), getLanguageLineFromIdx(langptr, 10, "Step"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));

	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDRELEASE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDRELEASE), getLanguageLineFromIdx(langptr, 297, "Release"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDUP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDUP), getLanguageLineFromIdx(langptr, 263, "Up"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDDOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDDOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDOUT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDOUT), getLanguageLineFromIdx(langptr, 295, "Out"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDIN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDIN), getLanguageLineFromIdx(langptr, 296, "In"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDZLEFT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDZLEFT), getLanguageLineFromIdx(langptr, 7, "Left"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDZRIGHT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGTOOL_CMDZRIGHT), getLanguageLineFromIdx(langptr, 6, "Right"));

  framesstm = getMachineIdx("Frames");
  jogzmax = getMachineValue(framesstm,"jogzmax");

  if(rs_param.workcellid==319
   ||rs_param.workcellid==320
   ||rs_param.workcellid==321)
  {
    SetSpeed(axis_a, jogspeed);
    SetAccel(axis_a, jogspeed*0.5);
    SetDecel(axis_a, jogspeed*0.5);
  }
	else
  {
    SetSpeed(axis_a, jogspeed);
    SetAccel(axis_a, jogspeed*2);
    SetDecel(axis_a, jogspeed*2);
	}

/*
  b = (BOXSTRUCT*)BxGetDlgItem(hBox, FORMJOGIK_CMDIKTCPIDX);
  sprintf(tcpidxstr,"%i", trobot->m_tcpidx);
  b->lpBoxStr = tcpidxstr;
*/
	pthread_mutex_lock(&actuator_mutex);
  tmpnComputeFK((tmpnRobot*)trobot, m_actuator.a, m_actuator.b, m_actuator.c, m_actuator.d, m_actuator.e, m_actuator.f,trobot->m_tcpidx);
	pthread_mutex_unlock(&actuator_mutex);

  b = (BOXSTRUCT*)BxGetDlgItem(hBox, FORMJOGTOOL_CMDJOGSPEED);
  sprintf(jogtoolspeed,"%.2f", jogspeed);
  b->lpBoxStr = jogtoolspeed;
  
  b = (BOXSTRUCT*)BxGetDlgItem(hBox, FORMJOGTOOL_CMDSTEPDEG);
  sprintf(stepdeg,"%.2f", jogstepdeg);
  b->lpBoxStr = stepdeg;
  b = (BOXSTRUCT*)BxGetDlgItem(hBox, FORMJOGTOOL_CMDSTEPMM);
  sprintf(stepmm,"%.2f", jogstepmm);
  b->lpBoxStr = stepmm;

  /*

  if(accesslevel>SERVICELEVEL)
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDJOGSPEED), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDIKSTEP), TRUE);
    //    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDZLEFT), TRUE);
    // BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDZRIGHT), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTILTRIGHT), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTURNRIGHT), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTILTLEFT), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTURNLEFT), TRUE);
    BxShowBox(BxGetDlgItem(hBox, FORMJOGIK_CMDIKTCPIDX), TRUE);
    BxShowBox(BxGetDlgItem(hBox, FORMJOGIK_TEXTLABELIKTCPIDX), TRUE);
  }
  else
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDJOGSPEED), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDIKSTEP), FALSE);
    //   BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDZLEFT), FALSE);
    // BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDZRIGHT), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTILTRIGHT), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTURNRIGHT), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTILTLEFT), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGIK_CMDTURNLEFT), FALSE);
    BxShowBox(BxGetDlgItem(hBox, FORMJOGIK_CMDIKTCPIDX), FALSE);
    BxShowBox(BxGetDlgItem(hBox, FORMJOGIK_TEXTLABELIKTCPIDX), FALSE);
  }

*/
  return TRUE;
}

BX_BOOL formJogToolUserUpdate(HBOX hBox)
{
  jogikscreen=1;
	pthread_mutex_lock(&actuator_mutex);
  tmpnComputeFK((tmpnRobot*)trobot, m_actuator.a, m_actuator.b, m_actuator.c, m_actuator.d, m_actuator.e, m_actuator.f,trobot->m_tcpidx);
	pthread_mutex_unlock(&actuator_mutex);
  return TRUE;
}

BX_BOOL formJogTool_cmdStepMM_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(jogstepmm);
  BxVirtNumBox_SetFloatLimits(1.0, 300.0);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    jogstepmm = BxVirtNumBox_GetFloatValue();
    sprintf(stepmm, "%0.2f", jogstepmm);
  }
  BxRequestPaint(BxGetDlgItem(hBox, FORMJOGTOOL_CMDSTEPMM));

  return TRUE;
}

//TODO: flip left/right possibility
BX_BOOL formJogTool_cmdZRight_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	z -= jogstepmm;
  if(jogzmax!=NULL && z<0.0)
  {
    z=0.0;
  }
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u,trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
    //		UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdZLeft_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	z += jogstepmm;
  if(jogzmax!=NULL && z>jogzmax->fdata)
  {
    z=jogzmax->fdata;
  }
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u,trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
    //		UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdDown_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	y -= jogstepmm;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
    //		UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdUp_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	y += jogstepmm;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdIn_Click(HBOX hBox)
{
 	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	x -= jogstepmm;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u,trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdOut_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	x += jogstepmm;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdResetTurnTilt_Click(HBOX hBox)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 299,"Turn and tilt will move to default position. Make sure there is sufficient free space"),
              getLanguageLineFromIdx(langptr, 16,"Information"),0,
              getLanguageLineFromIdx(langptr, 74,"Ok"),
              getLanguageLineFromIdx(langptr, 3,"Cancel")) != IDOK)
    return FALSE;
  
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	v = 90.0;
  w = 0.0;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdStepDeg_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(jogstepdeg);
  BxVirtNumBox_SetFloatLimits(1.0, 20.0);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    jogstepdeg = BxVirtNumBox_GetFloatValue();
    sprintf(stepdeg, "%0.2f", jogstepdeg);
  }
  BxRequestPaint(BxGetDlgItem(hBox, FORMJOGTOOL_CMDSTEPDEG));

  return TRUE;
}

BX_BOOL formJogTool_cmdTiltLeft_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	v -= jogstepdeg;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdTurnLeft_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	w -= jogstepdeg;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u,trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdTurnRight_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	w += jogstepdeg;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdTiltRight_Click(HBOX hBox)
{
	float x = trobot->m_worldPoint.x;
	float y = trobot->m_worldPoint.y;
	float z = trobot->m_worldPoint.z;
	float v = trobot->m_worldPoint.v;
	float w = trobot->m_worldPoint.w;
	float u = trobot->m_worldPoint.u;
	
	v += jogstepdeg;
	if(tmpnComputeIK((tmpnRobot*)trobot, x, y, z, v, w, u, trobot->m_tcpidx))
	{
		tmpnJointToActuator((tmpnRobot*)trobot,trobot->m_tcpidx);
		//UpdateIkView(hBox);
		MoveToPosition2();
	}
  return TRUE;
}

BX_BOOL formJogTool_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, TRUE);
	jogikscreen=0;
  return FALSE;
}

BX_BOOL formJogTool_cmdJogSpeed_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(jogspeed);
  BxVirtNumBox_SetFloatLimits(1.0, 200.0);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    jogspeed = BxVirtNumBox_GetFloatValue();
    sprintf(jogtoolspeed, "%.2f", jogspeed);
    BxRequestPaint(BxGetDlgItem(hBox, FORMJOGTOOL_CMDJOGSPEED));

    if(rs_param.workcellid==319
     ||rs_param.workcellid==320
     ||rs_param.workcellid==321)
    {
      SetSpeed(axis_a, jogspeed);
      SetAccel(axis_a, jogspeed*0.5);
      SetDecel(axis_a, jogspeed*0.5);
    }
	  else
    {
      SetSpeed(axis_a, jogspeed);
      SetAccel(axis_a, jogspeed*2);
      SetDecel(axis_a, jogspeed*2);
	  }
  }
  return TRUE;
}

BX_BOOL formJogTool_cmdRelease_Click(HBOX hBox)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 298,"Any object the robot is carrying will be released"),
              getLanguageLineFromIdx(langptr, 16,"Information"),0,
              getLanguageLineFromIdx(langptr, 74,"Ok"),
              getLanguageLineFromIdx(langptr, 3,"Cancel")) != IDOK)
    return FALSE;
  //TODO: some general smart way to do this.
  if(rs_param.workcellid==319
   ||rs_param.workcellid==320
   ||rs_param.workcellid==321)
  {
    int i,idx = getMachineIdx("Tool");
    if(idx == -1)
      return FALSE;
    tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[idx];
    int stateidx=getStateIdx(idx,"ST_HALT");
    if (stateidx>=0)
      setState(idx, stateidx);

    for(i=0;i<stm->numoutput;i++)
    {
      if (stm->output[i].iotype==OUTPUT)
      {
        if(strcmp(stm->output[i].name, "suck")==0)
          setConnectValueInt(stm->output[i].connect,0);
        if(strcmp(stm->output[i].name, "blow")==0)
          setConnectValueInt(stm->output[i].connect,1);
        if(strcmp(stm->output[i].name, "startvac")==0)
          setConnectValueInt(stm->output[i].connect,0);
        if(strcmp(stm->output[i].name, "stopvac")==0)
          setConnectValueInt(stm->output[i].connect,1);
      }
    }
    usleep(500000);
    stateidx=getStateIdx(idx,"ST_IDLE");
    if (stateidx>=0)
      setState(idx, stateidx);
  }
	else
  {
    //Box support
    SetOutput(10, 0);
    //Grip tool
    SetOutput(11, 0);
	}
  return TRUE;
}
