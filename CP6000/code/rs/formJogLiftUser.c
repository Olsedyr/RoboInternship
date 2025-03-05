//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogLiftUser.c
#include "Bx.h"
#include "formJogLift.h"
#include "cmd.h"
#include "stm.h" 
#include "tmpnrobot.h"

float stepVal = 50.0; //mm
static char stepStr[256];
//camgen/pid
float maxticks = 500.0;
static int camgenliftstm = -1;
static int pidliftstm = -1;
static int *encoder=NULL;
tmpnStateMachineValue *endpos=NULL;
static int statec_idle = -1;
static int statec_halt = -1;
static int statec_reset = -1;
static int statep_idle = -1;
static int statep_halt = -1;
//servo
int imaxticks = 500;
static int servoliftstm = -1;
macConnect *curpos=NULL;
macConnect *setpoint=NULL;
static int stateservo_idle = -1;
static int stateservo_halt = -1;
static int stateservo_reset = -1;
//both
tmpnStateMachineValue *tickspermm=NULL;
tmpnStateMachineValue *postop=NULL;
static int *jogmode=NULL;

BX_BOOL formJogLiftUserInit(HBOX hBox,BX_LPARAM lParam)
{
  BOXSTRUCT *b;
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  BX_BOOL jogable=FALSE;

	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), getLanguageLineFromIdx(langptr, 263, "Up"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELSTEP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELSTEP), getLanguageLineFromIdx(langptr, 10, "Step"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE1));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE1),"");
	BxAssignStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE2),"");

  BxAssignFloatValue(BxGetDlgItem(hBox, FORMJOGLIFT_VALUELABELCURPOS));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMJOGLIFT_VALUELABELCURPOS), 0.0);

  b = (BOXSTRUCT*)BxGetDlgItem(hBox, FORMJOGLIFT_CMDSTEP);
  sprintf(stepStr,"%.2f", stepVal);
  b->lpBoxStr = stepStr;

  camgenliftstm = getMachineIdx("CamGenLift");
  pidliftstm = getMachineIdx("PIDLift");
  servoliftstm = getMachineIdx("ServoLift");

  if (camgenliftstm != -1 && pidliftstm != -1 )
  {
    jogmode = getMachineValuePtr(camgenliftstm,"jogmode");
    if(jogmode != NULL)
    {
      statec_idle = getStateIdx(camgenliftstm, "ST_IDLE");
      statec_halt = getStateIdx(camgenliftstm, "ST_HALT");
      statec_reset = getStateIdx(camgenliftstm, "ST_RESET");
      statep_idle = getStateIdx(pidliftstm, "ST_IDLE");
      statep_halt = getStateIdx(pidliftstm, "ST_HALT");
      if((testState(camgenliftstm,statec_halt) || testState(camgenliftstm,statec_idle))
         &&(testState(pidliftstm,statep_halt) || testState(pidliftstm,statep_idle)))
      {
        jogable=TRUE;
        encoder = getMachineValuePtr(pidliftstm,"encoder");
        tickspermm = getMachineValue(camgenliftstm,"tickspermm");
        endpos = getMachineValue(camgenliftstm,"endpos");
        postop = getMachineValue(camgenliftstm,"posTop");
        maxticks = (postop->fdata - 120.0)* tickspermm->fdata;
        *jogmode = 1;
        BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), TRUE);
        BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), TRUE);
        setState(camgenliftstm, getStateIdx(camgenliftstm,"ST_RESET"));
      }
    }
  }
  else if (servoliftstm != -1 )
  {
    jogmode = getMachineValuePtr(servoliftstm,"jogmode");
    if(jogmode != NULL)
    {
      stateservo_idle = getStateIdx(servoliftstm, "ST_IDLE");
      stateservo_halt = getStateIdx(servoliftstm, "ST_HALT");
      stateservo_reset = getStateIdx(servoliftstm, "ST_RESET");
      if((testState(servoliftstm,stateservo_halt) || testState(servoliftstm,stateservo_idle)))
      {
        jogable=TRUE;

        tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[servoliftstm];
        curpos = getMacConnectPtr(stm,"curpos");
        printf("%s, %s\n",curpos->key, curpos->comment);
        printf("%d,%f\n",curpos->data,curpos->fdata);

        setpoint = getMacConnectPtr(stm,"setpoint");
        printf("%s, %s\n",setpoint->key, setpoint->comment);
        printf("%d,%f\n",setpoint->data,setpoint->fdata);

        tickspermm = getMachineValue(servoliftstm,"tickspermm");
        postop = getMachineValue(servoliftstm,"posTop");
        imaxticks = (postop->fdata - 120.0)* tickspermm->fdata;
        *jogmode = 1;
        BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), TRUE);
        BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), TRUE);
        setState(servoliftstm, getStateIdx(servoliftstm,"ST_RESET"));
      }
    }
  }
  if(jogable==FALSE)
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), FALSE);
  }

  return TRUE;
}

BX_BOOL formJogLiftUserUpdate(HBOX hBox)
{
  if (camgenliftstm != -1)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMJOGLIFT_VALUELABELCURPOS), ((float)*encoder)/(tickspermm->fdata));
    if((testState(camgenliftstm,statec_halt) || testState(camgenliftstm,statec_idle))
       &&(testState(pidliftstm,statep_halt) || testState(pidliftstm,statep_idle)))
    {
      BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), FALSE);
      BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), FALSE);
    }
  }
  else if (servoliftstm != -1 )
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMJOGLIFT_VALUELABELCURPOS), ((float)curpos->data)/(tickspermm->fdata));
    if((testState(servoliftstm,stateservo_halt) || testState(servoliftstm,stateservo_idle)))
    {
      BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDUP), FALSE);
      BxEnableBox(BxGetDlgItem(hBox, FORMJOGLIFT_CMDDOWN), FALSE);
    }
  }

  //*****************************************************************
  //* look for errorCode
  //***************************************************************** 
  int stmErrorCode;
  char stmerror1[256];
  char stmerror2[256];

  sprintf(stmerror1,"%s","");
  sprintf(stmerror2,"%s","");

	stmErrorCode=getStateMachineError(0);
	if(stmErrorCode>0)
	{
		setStateTekst(stmerror1,stmErrorCode,0);
		setStateTekst(stmerror2,stmErrorCode,1);
		if (strlen(stmerror2)==0)
		{
			stmErrorCode=getStateMachineError(1);
			if(stmErrorCode>0)
			{
				setStateTekst(stmerror2,stmErrorCode,1);
			}
		}
	}
  BxSetBoxText(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE1), stmerror1);
  BxSetBoxText(BxGetDlgItem(hBox, FORMJOGLIFT_TEXTLABELMESSAGE2), stmerror2);
  
  return TRUE;
}

BX_BOOL formJogLift_cmdCancel_Click(HBOX hBox)
{
  //set state back to idle or halt?
  if(jogmode != NULL)
    *jogmode = 0;
  BxEndDialog(hBox, TRUE);
  return FALSE;
}

BX_BOOL formJogLift_cmdStep_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(stepVal);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    stepVal = BxVirtNumBox_GetFloatValue();
    sprintf(stepStr, "%0.2f", stepVal);
  }
  BxRequestPaint(BxGetDlgItem(hBox, FORMJOGLIFT_CMDSTEP));
  return TRUE;
}

BX_BOOL formJogLift_cmdUp_Click(HBOX hBox)
{
  if (camgenliftstm != -1)
  {
    if(endpos->fdata != maxticks)
    {
      endpos->fdata = (stepVal * tickspermm->fdata) + (float)*encoder;
      if(endpos->fdata > maxticks)
        endpos->fdata = maxticks;
      setState(camgenliftstm, getStateIdx(camgenliftstm,"ST_PRESTART"));
    }
  }
  else if (servoliftstm != -1 )
  {
    if(setpoint->data != imaxticks)
    {
      setpoint->data = (stepVal * tickspermm->fdata) + curpos->data;
      if(setpoint->data > imaxticks)
        setpoint->data = imaxticks;
      setpoint->userchange = 1;
      setState(servoliftstm, getStateIdx(servoliftstm,"ST_START"));
    }
  }
  return TRUE;
}

BX_BOOL formJogLift_cmdDown_Click(HBOX hBox)
{
  if (camgenliftstm != -1)
  {
    if(endpos->fdata != 0.0)
    {
      endpos->fdata =  (float)*encoder - (stepVal * tickspermm->fdata);
      if(endpos->fdata < 0.0)
        endpos->fdata = 0.0;
      setState(camgenliftstm, getStateIdx(camgenliftstm,"ST_PRESTART"));
    }
  }
  else if (servoliftstm != -1 )
  {
    if(setpoint->data != 0)
    {
      setpoint->data =  curpos->data - (stepVal * tickspermm->fdata);
      if(setpoint->data < 0)
        setpoint->data = 0;
      setpoint->userchange = 1;
      setState(servoliftstm, getStateIdx(servoliftstm,"ST_START"));
    }
  }
  return TRUE;
}
