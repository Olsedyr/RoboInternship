//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual319User.c
#include "Bx.h"
#include "formManual319.h"
#include "cmd.h"
#include "stm.h"
#include "manual.h"

extern BOXSTRUCT *b;
extern int busy;
extern int busyidx;
extern int busyCmd;
extern tmpnConnect *busyconnect;

BX_BOOL formManual319UserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMD2_3UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMD2_3UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL319_CMD2_3CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMD2_3DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMD2_3DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL319_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));

  return TRUE;
}
BX_BOOL formManual319_released(void)
{
  if(busyCmd == FORMMANUAL319_CMD2_3DOWN){
    tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[busyidx];
    int i;
    for(i=0;i<stm->numoutput;i++)
    {
      if (stm->output[i].iotype==OUTPUT)
      {
        if(strcmp(stm->output[i].name, "yv1")==0)
        {
          setConnectValueInt(stm->output[i].connect,0);
          printf("yv1 0\n");
        }
        if(strcmp(stm->output[i].name, "yv2")==0)
        {
          setConnectValueInt(stm->output[i].connect,0);
          printf("yv2 0\n");
        }
        if(strcmp(stm->output[i].name, "yv3")==0)
        {
          setConnectValueInt(stm->output[i].connect,0);
          printf("yv3 0\n");
        }
      }
    }
  }
  else
    manual_resetOutput(0);
  busyCmd=-1;
  busyidx=-1;
  busyconnect=NULL;
  busy = 0;
  return TRUE;
}

BX_BOOL formManual319UserUpdate(HBOX hBox)
{
  if(busy==0)
  {
    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_3REV))
      if(manual_setOutput("ScissorDepalletizer2_3", "rollerrev", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_3UP))
      if(manual_setOutput("ScissorDepalletizer2_3", "pump", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_3DOWN))
      if(manual_setOutput("ScissorDepalletizer2_3", "yv1", 1) &&
         manual_setOutput("ScissorDepalletizer2_3", "yv2", 1) &&
         manual_setOutput("ScissorDepalletizer2_3", "yv3", 1))
      {
        busyCmd = FORMMANUAL319_CMD2_3DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_3FWD))
      if(manual_setOutput("ScissorDepalletizer2_3", "rollerfwd", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_1FWD))
      if(manual_setOutput("PalletConveyor1", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_1REV))
      if(manual_setOutput("PalletReverse2_3", "MotorRev1", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_2FWD))
      if(manual_setOutput("PalletConveyor2", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL319_CMD2_2REV))
      if(manual_setOutput("PalletReverse2_3", "MotorRev2", 1))
        return TRUE;
  }
  else
  {
    //if mouse moved, reset
    if((b->boxState & BBS_STATEMASK) != BA_CLICKACTIVE)
      formManual319_released();
  }
  return TRUE;
}

BX_BOOL formManual319_cmd2_1Rev_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_1Fwd_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_2Fwd_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_2Rev_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, TRUE);
  formManual319_released();

  manual_idle("ScissorDepalletizer2_3");
  manual_idle("PalletConveyor1");
  manual_idle("PalletConveyor2");
  
  return FALSE;
}
 
BX_BOOL formManual319_cmd2_3Fwd_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_3Rev_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_3Down_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

BX_BOOL formManual319_cmd2_3Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorDepalletizer2_3", "centre");
}

BX_BOOL formManual319_cmd2_3Up_Click(HBOX hBox)
{
  formManual319_released(); return TRUE;
}

