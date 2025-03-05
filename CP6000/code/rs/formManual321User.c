//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual321User.c
#include "Bx.h"
#include "formManual321.h"
#include "cmd.h"
#include "stm.h"
#include "manual.h"

extern BOXSTRUCT *b;
extern int busy;
extern int busyidx;
extern int busyCmd;
extern tmpnConnect *busyconnect;

BX_BOOL formManual321UserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_3UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_3UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL321_CMD4_3CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_3DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_3DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_7UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_7UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL321_CMD4_7CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_7DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_7DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_10UP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_10UP), getLanguageLineFromIdx(langptr, 263, "Up"));
  //FORMMANUAL321_CMD4_10CENTER
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_10DOWN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMD4_10DOWN), getLanguageLineFromIdx(langptr, 264, "Down"));

	BxAssignStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMANUAL321_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));

  return TRUE;
}

BX_BOOL formManual321_released(void)
{
  if(busyCmd == FORMMANUAL321_CMD4_3DOWN ||
     busyCmd == FORMMANUAL321_CMD4_7DOWN ||
     busyCmd == FORMMANUAL321_CMD4_10DOWN){
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

BX_BOOL formManual321UserUpdate(HBOX hBox)
{
  if(busy==0)
  {
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_3REV))
      if(manual_setOutput("ScissorDepalletizer4_3", "rollerrev", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_3UP))
      if(manual_setOutput("ScissorDepalletizer4_3", "pump", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_3DOWN))
      if(manual_setOutput("ScissorDepalletizer4_3", "yv1", 1) &&
         manual_setOutput("ScissorDepalletizer4_3", "yv2", 1))
        //? yv3 (its noisy when it hits bottom)
      {
        busyCmd = FORMMANUAL321_CMD4_7DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_3FWD))
      if(manual_setOutput("ScissorDepalletizer4_3", "rollerfwd", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_7DOWN))
      if(manual_setOutput("ScissorDepalletizer4_7", "yv1", 1) &&
         manual_setOutput("ScissorDepalletizer4_7", "yv2", 1) &&
         manual_setOutput("ScissorDepalletizer4_7", "yv3", 1))
      {
        busyCmd = FORMMANUAL321_CMD4_7DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_7UP))
      if(manual_setOutput("ScissorDepalletizer4_7", "pump", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_7REV))
      if(manual_setOutput("ScissorDepalletizer4_7", "rollerrev", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_7FWD))
      if(manual_setOutput("ScissorDepalletizer4_7", "rollerfwd", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_10REV))
      if(manual_setOutput("ScissorPalletizer4_10", "rollerrev", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_10UP))
      if(manual_setOutput("ScissorPalletizer4_10", "pump", 1))
        return TRUE;
    
    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_10DOWN))
      if(manual_setOutput("ScissorPalletizer4_10", "yv1", 1) &&
         manual_setOutput("ScissorPalletizer4_10", "yv2", 1))
      {
        busyCmd = FORMMANUAL321_CMD4_10DOWN;
        return TRUE;
      }

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_10FWD))
      if(manual_setOutput("ScissorPalletizer4_10", "rollerfwd", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_1FWD))
      if(manual_setOutput("Pos4_1", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_1REV))
      if(manual_setOutput("PalletReverse4_3", "MotorRev1", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_2FWD))
      if(manual_setOutput("Pos4_2", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_2REV))
      if(manual_setOutput("PalletReverse4_3", "MotorRev2", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_5FWD))
      if(manual_setOutput("Pos4_5", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_5REV))
      if(manual_setOutput("PalletReverse4_7", "MotorRev1", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_6FWD))
      if(manual_setOutput("Pos4_6", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_6REV))
      if(manual_setOutput("PalletReverse4_7", "MotorRev2", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_11FWD))
      if(manual_setOutput("Pos4_11", "Motor", 1))
        return TRUE;

    if(manual_activityCheck(hBox, FORMMANUAL321_CMD4_12FWD))
      if(manual_setOutput("Pos4_12", "Motor", 1))
        return TRUE;
  }
  else
  {
    //if mouse moved, reset
    if((b->boxState & BBS_STATEMASK) != BA_CLICKACTIVE)
      formManual321_released();
  }
  return TRUE;
}

BX_BOOL formManual321_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, TRUE);
  formManual321_released();

  manual_idle("ScissorDepalletizer4_3");
  manual_idle("ScissorDepalletizer4_7");
  manual_idle("ScissorPalletizer4_10");
  manual_idle("Pos4_1");
  manual_idle("PalletReverse4_3");
  manual_idle("Pos4_2");
  manual_idle("Pos4_5");
  manual_idle("PalletReverse4_7");
  manual_idle("Pos4_6");
  manual_idle("Pos4_11");
  manual_idle("Pos4_12");
  
  return FALSE;
}

BX_BOOL formManual321_cmd4_10Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_10Up_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_10Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorPalletizer4_10", "centre");
}

BX_BOOL formManual321_cmd4_10Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_10Down_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_7Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_7Up_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_7Down_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_7Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_7Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorDepalletizer4_7", "centre");
}

BX_BOOL formManual321_cmd4_3Up_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_3Down_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_3Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_3Center_Click(HBOX hBox)
{
  return manual_togleOutput("ScissorDepalletizer4_3", "centre");
}

BX_BOOL formManual321_cmd4_3Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_2Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_2Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_1Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_1Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_6Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_6Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_5Rev_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_5Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_11Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

BX_BOOL formManual321_cmd4_12Fwd_Click(HBOX hBox)
{
    formManual321_released(); return TRUE;
}

