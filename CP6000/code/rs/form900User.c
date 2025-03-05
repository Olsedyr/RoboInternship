//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form900User.c
#include "Bx.h"
#include "BxGdi.h"
#include "formSTMList.h"
#include "formDistIO.h"
#include "formProgram.h"
#include "formLanguage.h"
#include "form900.h"
#include "cmd.h"
#include "stm.h"
#include "robostackerBxr.h"
#include <time.h>
#include <sys/timeb.h>

extern int supervisorLogin(HBOX hBox);

extern int accesslevel; //mc.c
extern volatile int dioIndex;
extern char programStateMachineName[256];

static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

static int useprogramstm=-1;

static int wstm = -1;
static int statew_idle = -1;
static int statew_starting = -1;
static int statew_restarting = -1;
static int statew_running = -1;
static int statew_stopping = -1;
static int statew_pausing = -1;
static int statew_paused = -1;
static int statew_error = -1;
static int statew_halt = -1;
static int emergstm = -1;
static int stateemerg_poweron = -1;
static int continueknapstm = -1;
static int *continueknap=NULL;

static int languagechange=0;

BX_BOOL form900UserInit(HBOX hBox,BX_LPARAM lParam)
{ 
  char s[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

	BxAssignStringValue(BxGetDlgItem(hBox, FORM900_GROUPBOX1_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORM900_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LAB1_4));
	BxSetStringValue(BxGetDlgItem(hBox, FORM900_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORM900_CMDMENU));
	BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORM900_CMDSTOP));
	BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORM900_CMDRUN));
	BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));


  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
	useprogramstm = getMachineIdx(programStateMachineName);
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LABERROR1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LABERROR2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LABINFO));
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_LABTIME));
  time(&starttid);
  sprintf(s,"%s","900 Series");//GetCPType(),GetCPVersion());
  BxAssignStringValue(BxGetDlgItem(hBox, FORM900_TEXTLABEL2_2));
  BxSetStringValue(BxGetDlgItem(hBox, FORM900_TEXTLABEL2_2),s);
  BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABTIME), "00:00:00");

	wstm = getMachineIdx("WorkCell");
	statew_idle = getStateIdx(wstm, "ST_IDLE");
	statew_starting = getStateIdx(wstm, "ST_STARTING");
	statew_restarting = getStateIdx(wstm, "ST_RESTARTING");
	statew_running = getStateIdx(wstm, "ST_RUNNING");
	statew_stopping = getStateIdx(wstm, "ST_STOPPING");
	statew_pausing = getStateIdx(wstm, "ST_PAUSING");
	statew_paused = getStateIdx(wstm, "ST_PAUSED");
	statew_error = getStateIdx(wstm, "ST_ERROR");
	statew_halt = getStateIdx(wstm, "ST_HALT");
	emergstm = getMachineIdx("Emergency");
	stateemerg_poweron = getStateIdx(emergstm,"ST_POWERON");
	continueknapstm = getMachineIdx("ContinueKnap");
	continueknap = getMachineValuePtr(continueknapstm,"knap");
  return TRUE;
}

BX_BOOL form900UserUpdate(HBOX hBox)
{
  //  HBOX hBx;
  int t, m, s;
  char workcellstr[256];
  char stmerror1[256];
  char stmerror2[256];
  char infostr[256];
  char tidstr[256];
	char* programstr;
  int stmErrorCode;
  int stmMessageCode;
	BX_BOOL menuEn,runEn,stopEn;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	if (languagechange>0)
	{
		languagechange=0;
		BxSetStringValue(BxGetDlgItem(hBox, FORM900_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
		BxSetStringValue(BxGetDlgItem(hBox, FORM900_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
		BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
		BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
		BxSetStringValue(BxGetDlgItem(hBox, FORM900_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_LABWORKCELLSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_LABERROR1));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_LABERROR2));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_LABINFO));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_LABTIME));
		BxRequestPaint(BxGetDlgItem(hBox, FORM900_TEXTLABEL2_2));
	}
  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
 	programstr = getProgramName(programStateMachineName);
	
  sprintf(stmerror1,"%s","");
  sprintf(stmerror2,"%s","");
  sprintf(infostr,"%s","");
//*****************************************************************
//* look for errorCode
//***************************************************************** 

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

//*****************************************************************
//* look for message
//***************************************************************** 
  stmMessageCode = getStateMachineMessage();
  if(stmMessageCode>0)
  {
  //  sprintf(infostr,"%d",stmMessageCode);
    setStateTekst(infostr,stmMessageCode,0);
  }

//***************************************************************************
//* WorkCell.statemachine                                                   *
//***************************************************************************

	if(testState(wstm,statew_idle))
	{
		if (programstr != NULL)
			sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 97,"Ready"));
		else
			sprintf(workcellstr,"%s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),getLanguageLineFromIdx(langptr, 98,"Not ready"));
	}
	else if(testState(wstm,statew_starting))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 128,"Starting"));
	}
	else if(testState(wstm,statew_restarting))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 129,"Continuing"));
	}
	else if(testState(wstm,statew_running))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 130,"Running"));
	}
	else if(testState(wstm,statew_stopping))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 131,"Stopping"));
	}
	else if(testState(wstm,statew_pausing))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 132,"Preparing pause"));
	}
	else if(testState(wstm,statew_paused))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 133,"Paused"));
	}
	else if(testState(wstm,statew_error))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 134,"Error"));
	}
	else if(testState(wstm,statew_halt))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 135,"Halted"));
	}
	//***************************************************************************
	//* update 
	//***************************************************************************
  BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABERROR1), stmerror1);     
  BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABERROR2), stmerror2);     
  BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABINFO), infostr);     
	
	menuEn=FALSE;
	runEn=TRUE;
	stopEn=TRUE;

  if(!isRunning("WorkCell"))
  {
		menuEn=TRUE;
		runEn=TRUE;
		stopEn=FALSE;
  }
	else
  {
    time(&sluttid);
    t = difftime(sluttid, starttid)/3600.0;
    m = (difftime(sluttid, starttid)-(t*3600.0))/60.0;
    s = (difftime(sluttid, starttid)-(t*3600.0))-(m*60.0);
    sprintf(tidstr, "%02d:%02d:%02d", t, m, s);
    BxSetBoxText(BxGetDlgItem(hBox, FORM900_LABTIME), tidstr);
		stopEn = TRUE;
		runEn=FALSE;
    if(accesslevel>OPERATORLEVEL)
    {
			menuEn=TRUE;
    }
  }
	if (!testState(emergstm,stateemerg_poweron))
	{
		menuEn=TRUE;
		stopEn=FALSE;
		runEn=FALSE;
	}
	else
	{
		if(testState(wstm,statew_halt)
			 ||testState(wstm,statew_idle)
			 ||testState(wstm,statew_paused)
       ||testState(wstm,statew_error))
		{
			menuEn=TRUE;
			runEn=TRUE;
			stopEn=FALSE;
		}
		else
		{
			runEn=FALSE;
			if(accesslevel>OPERATORLEVEL)
				menuEn=TRUE;
			else   
				menuEn=FALSE;
		}
		if(testState(wstm,statew_running))
			stopEn=TRUE;
		else
			stopEn=FALSE;
	}
	BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDMENU), menuEn);
	BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDRUN), runEn);
	BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDSTOP), stopEn);
  return TRUE;
}

BX_BOOL form900_cmdRun_Click(HBOX hBox)
{
  if(testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
 		*continueknap=1;
  }
  return TRUE;
}

BX_BOOL form900_cmdStop_Click(HBOX hBox)
{
  if(testState(wstm,statew_running))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORM900_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORM900_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORM900_CMDRUN));
		*continueknap=1;
  }
  return TRUE;
}

BX_BOOL form900_cmdLanguage_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLanguage[0], formLanguageProc);
	if(DoModal(hBx)==IDOK)
	{	
		languagechange++;
	}
  return TRUE;
}

BX_BOOL form900_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL form900_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL form900_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}

static BX_BOOL formTools_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL form900_cmdMenu_Click(HBOX hBox)
{
  HBOX hBx,hOptions,ToolBx;
	extern BxIcon *icon1;
	extern BxIcon *icon2;
	//extern BxIcon *icon3;
	//extern BxIcon *icon4;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORM900_CMDMENU), &pBxMainMenu);
	if (!testState(emergstm,stateemerg_poweron)&&accesslevel<OPERATORLEVEL)
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, form900_cmdSupervisor_Click, TRUE,icon1);
		DoMenu(BxGetDlgItem(hBox, FORM900_CMDMENU));
		return TRUE;
	}
	if(testState(wstm,statew_halt)
		 ||testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, form900_cmdProgram_Click, TRUE, icon2);
	}
	else
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, form900_cmdProgram_Click, FALSE, NULL);
	}
	BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, form900_cmdSupervisor_Click, TRUE,icon1);
  if(accesslevel>OPERATORLEVEL)
  {
    hOptions = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 18,"Setup"), SUB, NULL, TRUE, NULL);//icon3);
		{
			BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 250, "Language"), MENU, form900_cmdLanguage_Click, TRUE, NULL);
		}
		ToolBx = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 19, "Tools"), SUB, NULL, TRUE, NULL);//icon4);
		{
      if(tworkcell->dios.maxidx>0 || tworkcell->loadcells.maxidx>0 || tworkcell->comsks.maxidx>0 || tworkcell->macs.maxidx>0)
      {
        BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 24, "Dist. I/O"), MENU, formTools_cmdDistIO_Click, TRUE, NULL);
			}
			BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 25, "STM control"), MENU, form900_cmdSTMCtrl_Click, TRUE, NULL);
		}
  }
  DoMenu(BxGetDlgItem(hBox, FORM900_CMDMENU));
  return TRUE;
}
