#include "Bx.h"
#include "BxGdi.h"
#include "formSTMList.h"
#include "formDistIO.h"
#include "formTest.h"
#include "formProgram.h"
#include "cmd.h"
#include "libstm.h"
#include "robostackerBxr.h"
#include <time.h>
#include <sys/timeb.h>

extern int supervisorLogin(HBOX hBox);

extern int accesslevel; //mc.c
extern int GoRobot(int run); //mc.c

static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

BX_BOOL formTestUserInit(HBOX hBox,BX_LPARAM lParam)
{
  BxAssignStringValue(BxGetDlgItem(hBox, FORMTEST_TEXTLABEL2_2_2));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMTEST_CMDSPEED));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMTEST_CMDSPEED), 100.0);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMTEST_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMTEST_LABINFO));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMTEST_LABTIME));
  BxSetBoxText(BxGetDlgItem(hBox, FORMTEST_LABTIME), "00:00:00");
  time(&starttid);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMTEST_TEXTLABEL2_2));
 return TRUE;
}

//void drawTab(BxDC* bdc);
BX_BOOL formTestUserUpdate(HBOX hBox)
{
  //  HBOX hBx;
  int t, m, s;
  char workcellstr[512];
  char infostr[256];
  char tidstr[256];
  int stmErrorCode;
  int stmMessageCode;

  stmErrorCode=getStateMachineError();
  if(stmErrorCode>0)
  {
    if(testMachineState("WorkCell","ST_RUNNING"))
    {
      formTest_cmdStop_Click(hBox);
    }
  }

  stmMessageCode = getStateMachineMessage();
  if(stmMessageCode>0)
  {
    setStateTekst(infostr,stmMessageCode,0);
  }
  else sprintf(infostr,"%s","");

  if(testMachineState("ContinueKnap","ST_PRESSED"))
  {
    if(testMachineState("WorkCell","ST_RUNNING"))
    {
      formTest_cmdStop_Click(hBox);
    } 
    else if(testMachineState("WorkCell","ST_PAUSED"))
    {
      formTest_cmdRun_Click(hBox);
    }
  }
//***************************************************************************
//* WorkCell.statemachine                                                   *
//***************************************************************************
		if(testMachineState("WorkCell","ST_IDLE"))
    {
      sprintf(workcellstr,"Program %s - Klar.",rs_param.script);
    } 
		else if(testMachineState("WorkCell","ST_STARTING"))
    {
      sprintf(workcellstr,"Program %s - Starter.",rs_param.script);
    }
		else if(testMachineState("WorkCell","ST_RESTARTING"))
    {
      sprintf(workcellstr,"Program %s - Fortsætter.",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_RUNNING"))
    {
      sprintf(workcellstr,"Program %s - Kører.",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_STOPPING"))
    {
      sprintf(workcellstr,"Program %s - Stopper.",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_PAUSING"))
    {
      sprintf(workcellstr,"Program %s - Forbereder pause.",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_PAUSED"))
    {
      sprintf(workcellstr,"Program %s - Pause",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_ERROR"))
    {
      sprintf(workcellstr,"Program %s - error",rs_param.script);
    }
    else if(testMachineState("WorkCell","ST_HALT"))
    {
      sprintf(workcellstr,"Program %s - halt",rs_param.script);
    }
  
  BxSetBoxText(BxGetDlgItem(hBox, FORMTEST_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMTEST_LABINFO), infostr);     
  
  if(!isRunning())
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), TRUE);
  }

  if(isRunning())
  {
    time(&sluttid);
    t = difftime(sluttid, starttid)/3600.0;
    m = (difftime(sluttid, starttid)-(t*3600.0))/60.0;
    s = (difftime(sluttid, starttid)-(t*3600.0))-(m*60.0);
    sprintf(tidstr, "%02d:%02d:%02d", t, m, s);
    BxSetBoxText(BxGetDlgItem(hBox, FORMTEST_LABTIME), tidstr);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), FALSE);
    if(accesslevel>OPERATORLEVEL)
    {
      BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), TRUE);
    }
  }
  if(testMachineState("WorkCell","ST_HALT")
   ||testMachineState("WorkCell","ST_IDLE")
	 ||testMachineState("WorkCell","ST_PAUSED")
   ||testMachineState("WorkCell","ST_ERROR"))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), TRUE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), FALSE);
  }
  else
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), FALSE); 
    if(accesslevel>OPERATORLEVEL)
      BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), TRUE);
    else   
      BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), FALSE);
  }
  if(testMachineState("WorkCell","ST_RUNNING")
   ||testMachineState("WorkCell","ST_ERROR"))
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), TRUE);
  else
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), FALSE);
  return TRUE;
}

BX_BOOL formTestRun_cmdSpeed_Click(HBOX hBox)
{
 return TRUE;
}

BX_BOOL formTest_cmdRun_Click(HBOX hBox)
{
  if(testMachineState("WorkCell","ST_IDLE")
	 ||testMachineState("WorkCell","ST_PAUSED")
   ||testMachineState("WorkCell","ST_ERROR"))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
    GoRobot(TRUE);
  }
  return TRUE;
}

BX_BOOL formTest_cmdStop_Click(HBOX hBox)
{
  if(testMachineState("WorkCell","ST_RUNNING")
   ||testMachineState("WorkCell","ST_PAUSED")
   ||testMachineState("WorkCell","ST_ERROR"))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMTEST_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMTEST_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMTEST_CMDRUN));
    GoRobot(FALSE);
  }
  return TRUE;
}
BX_BOOL formTest_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL formTest_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTest_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTest_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTest_cmdMenu_Click(HBOX hBox)
{
  HBOX hBx, ToolBx, hOptions;

  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORMTEST_CMDMENU), &pBxMainMenu);
  
  BxMenu_Add(hBx ,"Program", MENU, formTest_cmdProgram_Click, TRUE, NULL);
  BxMenu_Add(hBx ,"Login", MENU, formTest_cmdSupervisor_Click, TRUE,BxResourceLoadBxIcon(FORMICON_LABUNLOCK_ICON, "data/robostacker.bxr"));

  if(accesslevel>OPERATORLEVEL)
  {
    hOptions = BxMenu_Add(hBx ,"Setup", SUB, NULL, TRUE, BxResourceLoadBxIcon(FORMICON_LABOPTION_ICON, "data/robostacker.bxr"));
		{
		}
		ToolBx = BxMenu_Add(hBx , "Tools", SUB, NULL, TRUE, BxResourceLoadBxIcon(FORMICON_LABTOOLS_2_ICON, "data/robostacker.bxr"));
		{
			BxMenu_Add(ToolBx ,"Distr. IO", MENU, formTest_cmdDistIO_Click, TRUE, NULL);
			BxMenu_Add(ToolBx ,"STM control", MENU, formTest_cmdSTMCtrl_Click, TRUE, NULL);
		}
  }
  DoMenu(BxGetDlgItem(hBox, FORMTEST_CMDMENU));

  return TRUE;
}

BX_BOOL formTest_cmdSpeed_Click(HBOX hBox)
{
  return TRUE;
}

