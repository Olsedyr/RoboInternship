//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual320User.c
#include "Bx.h"
#include "formManual320.h"
#include "cmd.h"
#include "stm.h"
#include "manual.h"

extern BOXSTRUCT *b;
extern int busy;
extern int busyidx;
extern int busyCmd;
extern tmpnConnect *busyconnect;

BX_BOOL formManual320UserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_6UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_6UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL320_CMD3_6CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_6DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_6DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_3UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_3UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL320_CMD3_3CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_3DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMD3_3DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL320_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));

  return TRUE;
}

BX_BOOL formManual320_released(void)
{
  if(busyCmd == FORMMANUAL320_CMD3_6DOWN ||
     busyCmd == FORMMANUAL320_CMD3_3DOWN){
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

BX_BOOL formManual320UserUpdate(HBOX hBox)
{
  if(busy==0)
  {
    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_6REV))
      if(manual_setOutput("ScissorPalletizer3_6", "rollerrev", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_6UP))
      if(manual_setOutput("ScissorPalletizer3_6", "pump", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_6DOWN))
      if(manual_setOutput("ScissorPalletizer3_6", "yv1", 1) &&
         manual_setOutput("ScissorPalletizer3_6", "yv2", 1))
      {
        busyCmd = FORMMANUAL320_CMD3_6DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_6FWD))
      if(manual_setOutput("ScissorPalletizer3_6", "rollerfwd", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_3DOWN))
      if(manual_setOutput("ScissorDepalletizer3_3", "yv1", 1) &&
         manual_setOutput("ScissorDepalletizer3_3", "yv2", 1) &&
         manual_setOutput("ScissorDepalletizer3_3", "yv3", 1))
      {
        busyCmd = FORMMANUAL320_CMD3_3DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_3UP))
      if(manual_setOutput("ScissorDepalletizer3_3", "pump", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_3REV))
      if(manual_setOutput("ScissorDepalletizer3_3", "rollerrev", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_3FWD))
      if(manual_setOutput("ScissorDepalletizer3_3", "rollerfwd", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_8FWD))
      if(manual_setOutput("PalletConveyor8", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_9FWD))
      if(manual_setOutput("PalletConveyor9", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_2REV))
      if(manual_setOutput("PalletReverse3_3", "MotorRev2", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_1REV))
      if(manual_setOutput("PalletReverse3_3", "MotorRev1", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_1FWD))
      if(manual_setOutput("PalletConveyor1", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL320_CMD3_2FWD))
      if(manual_setOutput("PalletConveyor2", "Motor", 1))
        return TRUE;
  }
  else
  {
    //if mouse moved, reset
    if((b->boxState & BBS_STATEMASK) != BA_CLICKACTIVE)
      formManual320_released();
  }
  return TRUE;
}

BX_BOOL formManual320_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, TRUE);
  formManual320_released();

  manual_idle("ScissorPalletizer3_6");
  manual_idle("ScissorDepalletizer3_3");
  manual_idle("PalletConveyor8");
  manual_idle("PalletConveyor9");
  manual_idle("PalletReverse3_3");
  manual_idle("PalletConveyor1");
  manual_idle("PalletConveyor2");
  
  return FALSE;
}

BX_BOOL formManual320_cmd3_6Rev_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_6Up_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_6Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorPalletizer3_6", "centre");
}

BX_BOOL formManual320_cmd3_6Down_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_6Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_3Down_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_3Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorDepalletizer3_3", "centre");
}

BX_BOOL formManual320_cmd3_3Up_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_3Rev_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_3Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_8Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_9Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_2Rev_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_1Rev_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_1Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

BX_BOOL formManual320_cmd3_2Fwd_Click(HBOX hBox)
{
  formManual320_released();
  return TRUE;
}

