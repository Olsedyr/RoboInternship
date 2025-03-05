//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#include "Bx.h"
#include "BxGdi.h"
#include "formSTMList.h"
#include "formDistIO.h"
#include "formJogLift.h"
#include "formCP.h"
#include "formProgram.h"
#include "formLanguage.h"
#include "formCW.h"
#include "cmd.h"
#include "stm.h"
#include "robostackerBxr.h"
#include <time.h>
#include <sys/timeb.h>

extern int supervisorLogin(HBOX hBox);
extern BX_BOOL formDemo_cmdDemoClose_Click(HBOX hBox);
extern int demo;
extern int accesslevel; //mc.c
extern volatile int dioIndex;
extern int GoRobot(int run); //mc.c
extern char programStateMachineName[256];

char *GetCPVersion(void);
char *GetCPType(void);

static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

static char prodpermin[256]="";

static FONT strFont;
static int useprogramstm=-1;

//tmpnStateMachineValue *ppmin;

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
static int cpcounterstm = -1;
static int *continueknap=NULL;
static int *doFakeProducts=NULL;

static int languagechange=0;

BX_BOOL formCPUserInit(HBOX hBox,BX_LPARAM lParam)
{
  char s[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

	BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_GROUPBOX1_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCP_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LAB1_4));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCP_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_CMDMENU));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_CMDSTOP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_CMDRUN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));


  sprintf(programStateMachineName,"Program");
	useprogramstm = getMachineIdx(programStateMachineName);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABERROR1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABERROR2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABINFO));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABTIME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_LABPRODPERMIN));
  BxOpenFont(&strFont, "data/decker.ttf", 80);
  BxSetFont(BxGetDC(BxGetDlgItem(hBox, FORMCP_LABPRODPERMIN)), &strFont);
  time(&starttid);
  sprintf(s,"%s %s",GetCPType(),GetCPVersion());
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCP_TEXTLABEL2_2));
  BxSetStringValue(BxGetDlgItem(hBox, FORMCP_TEXTLABEL2_2),s);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABTIME), "00:00:00");

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
	cpcounterstm = getMachineIdx("CPCounter");
  	doFakeProducts = getMachineValuePtr(wstm,"doFakeProducts");
	return TRUE;
}

BX_BOOL formCPUserUpdate(HBOX hBox)
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
		BxSetStringValue(BxGetDlgItem(hBox, FORMCP_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCP_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCP_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABWORKCELLSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABERROR1));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABERROR2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABINFO));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABTIME));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_TEXTLABEL2_2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCP_LABPRODPERMIN));
	}
  sprintf(programStateMachineName,"Program");
	if (useprogramstm == -1)
	{
		programstr=rs_param.script;
	}
	else
	{
		int istate;
		istate=tworkcell->statemachines.statemachine[useprogramstm].istate;
		programstr=tworkcell->statemachines.statemachine[useprogramstm].state[istate].name;
		if (!strncmp(programstr,"ST_RUNNING_",11))
		{
			programstr+=11;
		}
		else
		{
			programstr=NULL;
		}
	}
	
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
  ppmin = getMachineValue(cpcounterstm,"prodpermin");
  if(ppmin != NULL)
    sprintf(prodpermin,"%4.1f %s",ppmin->fdata,getLanguageLineFromIdx(langptr, 136,"p/min."));
  else
    sprintf(prodpermin, "ppmin==NULL");
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABPRODPERMIN),prodpermin);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABERROR1), stmerror1);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABERROR2), stmerror2);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABINFO), infostr);     
	
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
    BxSetBoxText(BxGetDlgItem(hBox, FORMCP_LABTIME), tidstr);
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
			 ||testState(wstm,statew_paused))
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
	if(testState(wstm,statew_error))
	{
		stopEn=FALSE;
		runEn=FALSE;
	}
	BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDMENU), menuEn);
	BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDRUN), runEn);
	BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDSTOP), stopEn);
  return TRUE;
}

BX_BOOL formCP_cmdRun_Click(HBOX hBox)
{
  if(testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
 		*continueknap=1;
  }
  return TRUE;
}

BX_BOOL formCP_cmdStop_Click(HBOX hBox)
{
  if(testState(wstm,statew_running))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCP_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCP_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCP_CMDRUN));
		*continueknap=1;
  }
  return TRUE;
}


BX_BOOL formCP_cmdLanguage_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLanguage[0], formLanguageProc);
	if(DoModal(hBx)==IDOK)
	{	
		languagechange++;
	}
  return TRUE;
}

BX_BOOL formCP_zeroKassePakker_Click(HBOX hBox)
{
	setState(wstm,statew_idle);
  return TRUE;
}

BX_BOOL formCP_cmdDoFakeProducts_Click(HBOX hBox)
{
  if(*doFakeProducts == 0)
    *doFakeProducts=1;
  else
    *doFakeProducts=0;
  return TRUE;
}

BX_BOOL formCP_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL formCP_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCP_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}

static BX_BOOL formCP_cmdCW_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formCW[0], formCWProc);
  languagechange=DoModal(hBx);
  return TRUE;
}

static BX_BOOL formTools_cmdJogLift_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formJogLift[0], formJogLiftProc);
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

BX_BOOL formCP_cmdMenu_Click(HBOX hBox)
{
  HBOX hBx,hOptions,ToolBx;
	extern BxIcon *icon1;
	extern BxIcon *icon2;
	//extern BxIcon *icon3;
	//extern BxIcon *icon4;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORMCP_CMDMENU), &pBxMainMenu);
	if (!testState(emergstm,stateemerg_poweron)&&accesslevel<OPERATORLEVEL)
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, formCP_cmdSupervisor_Click, TRUE,icon1);
    if(demo == 1)
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
		DoMenu(BxGetDlgItem(hBox, FORMCP_CMDMENU));
		return TRUE;
	}
	if(rs_param.checkWeigher>0)
  {
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 20,"checkWeigher"), MENU, formCP_cmdCW_Click, TRUE, NULL);
  }
	if(testState(wstm,statew_halt)
		 ||testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 41,"Reset casepacker"), MENU, formCP_zeroKassePakker_Click, TRUE, NULL);
    if(doFakeProducts != NULL)
		{
      if(*doFakeProducts == 0)
        BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 42,"Empty casepacker"), MENU, formCP_cmdDoFakeProducts_Click, TRUE, NULL);
      else
        BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 43,"Stop emptying"), MENU, formCP_cmdDoFakeProducts_Click, TRUE, NULL);
		}
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, formCP_cmdProgram_Click, TRUE, icon2);
	}
	else
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 41,"Reset casepacker"), MENU, formCP_zeroKassePakker_Click, FALSE, NULL);
    if(doFakeProducts != NULL)
		{
      if(*doFakeProducts == 0)
        BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 42,"Empty casepacker"), MENU, formCP_cmdDoFakeProducts_Click, FALSE, NULL);
      else
        BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 43,"Stop emptying"), MENU, formCP_cmdDoFakeProducts_Click, FALSE, NULL);
		}
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, formCP_cmdProgram_Click, FALSE, NULL);
	}
	BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, formCP_cmdSupervisor_Click, TRUE,icon1);
  if(accesslevel>OPERATORLEVEL)
  {
    hOptions = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 18,"Setup"), SUB, NULL, TRUE, NULL);//icon3);
		{
			BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 250, "Language"), MENU, formCP_cmdLanguage_Click, TRUE, NULL);
		}
		ToolBx = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 19, "Tools"), SUB, NULL, TRUE, NULL);//icon4);
		{
			if(testState(wstm,statew_halt)
				||testState(wstm,statew_idle)
				||testState(wstm,statew_paused)
				||testState(wstm,statew_error))
			BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 31, "Jog Manual"), MENU, formTools_cmdJogLift_Click, TRUE, NULL);
			else
			BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 31, "Jog Manual"), MENU, formTools_cmdJogLift_Click, FALSE, NULL);
			if(tworkcell->dios.maxidx>0 || tworkcell->loadcells.maxidx>0 || tworkcell->comsks.maxidx>0 || tworkcell->macs.maxidx>0)
			{
				BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 24, "Dist. I/O"), MENU, formTools_cmdDistIO_Click, TRUE, NULL);
			}
			BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 25, "STM control"), MENU, formCP_cmdSTMCtrl_Click, TRUE, NULL);
		}
  }
  if(demo == 1)
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
  DoMenu(BxGetDlgItem(hBox, FORMCP_CMDMENU));
	return TRUE;
}

BX_BOOL formCP_cmdSpeed_Click(HBOX hBox)
{
  return TRUE;
}

