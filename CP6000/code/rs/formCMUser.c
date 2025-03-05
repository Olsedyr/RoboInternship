//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCMUser.c
#include "Bx.h"
#include "formCM.h"
#include "BxGdi.h"
#include "formSTMList.h"
#include "formDistIO.h"
#include "formProgram.h"
#include "formLanguage.h"
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

char *GetCMVersion(void);
char *GetCMType(void);

static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

static char prodpermin[256]="";
static char casecountstr[256]="";

static FONT strFont;
static int useprogramstm=-1;

//tmpnStateMachineValue *ppmin;
//tmpnStateMachineValue *casecount;

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
static int cmcounterstm= -1;
static int casecountstm= -1;
static int pallestationstm = -1;
static int pallestationportstm = -1;
static int conveyorcontrolstm = -1;
static int *goFree=NULL;
static int *goHome=NULL;
static int *tryopen=NULL;
static int *tryclose=NULL;
static int *run=NULL;

static int languagechange=0;

BX_BOOL formCMUserInit(HBOX hBox,BX_LPARAM lParam)
{
  char s[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

	BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_GROUPBOX1_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCM_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LAB1_4));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCM_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_CMDMENU));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_CMDSTOP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_CMDRUN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
	
  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
  useprogramstm = getMachineIdx(programStateMachineName);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABERROR1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABERROR2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABINFO));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABTIME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABPRODPERMIN));
  BxOpenFont(&strFont, "data/decker.ttf", 50);
  BxSetFont(BxGetDC(BxGetDlgItem(hBox, FORMCM_LABPRODPERMIN)), &strFont);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABCASECOUNT));
  BxOpenFont(&strFont, "data/decker.ttf", 50);
  BxSetFont(BxGetDC(BxGetDlgItem(hBox, FORMCM_LABCASECOUNT)), &strFont);
  time(&starttid);
  sprintf(s,"%s %s",GetCMType(),GetCMVersion());
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCM_LABHEAD));
  BxSetStringValue(BxGetDlgItem(hBox, FORMCM_LABHEAD),s);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABTIME), "00:00:00");

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
  cmcounterstm = getMachineIdx("CMCounter");
  casecountstm = getMachineIdx("CaseCount");
	pallestationstm = getMachineIdx("PalleStation");
	pallestationportstm = getMachineIdx("PalleStationPort");
	conveyorcontrolstm = getMachineIdx("ConveyorControl");
	goFree = getMachineValuePtr(getMachineIdx("KasseStativ"),"goFree");
	goHome = getMachineValuePtr(pallestationstm,"goHome");
	tryopen = getMachineValuePtr(pallestationportstm,"tryOpen");
	tryclose = getMachineValuePtr(pallestationportstm,"tryClose");
  if(conveyorcontrolstm != -1)
    run = getMachineValuePtr(conveyorcontrolstm,"run");
  return TRUE;
}

BX_BOOL formCMUserUpdate(HBOX hBox)
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
		BxSetStringValue(BxGetDlgItem(hBox, FORMCM_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCM_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCM_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABWORKCELLSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABERROR1));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABERROR2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABINFO));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABTIME));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABHEAD));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABPRODPERMIN));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCM_LABCASECOUNT));
	}

  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
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
  ppmin = getMachineValue(cmcounterstm,"prodpermin");
  sprintf(prodpermin,"%4.1f %s", ppmin->fdata,getLanguageLineFromIdx(langptr, 137,"cases/min."));
  if(casecountstm != -1)
  {
    casecount = getMachineValue(casecountstm,"casecount");
    if(casecount->data == 0)
      sprintf(casecountstr,"0 %s",getLanguageLineFromIdx(langptr, 138,"cases left"));
    else
      sprintf(casecountstr,"%s %d %s", getLanguageLineFromIdx(langptr, 139,"approx."), casecount->data, getLanguageLineFromIdx(langptr, 138,"cases left"));
  }
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABPRODPERMIN),prodpermin);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABCASECOUNT),casecountstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABERROR1), stmerror1);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABERROR2), stmerror2);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABINFO), infostr);     
  
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
    BxSetBoxText(BxGetDlgItem(hBox, FORMCM_LABTIME), tidstr);
    stopEn = TRUE;
    runEn=FALSE;
    if(accesslevel>=OPERATORLEVEL)
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
      if(accesslevel>=OPERATORLEVEL)
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
    runEn=TRUE;
  }
  BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDMENU), menuEn);
  BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDRUN), runEn);
  BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDSTOP), stopEn);
  return TRUE;
}

BX_BOOL formCM_cmdRun_Click(HBOX hBox)
{
  if(testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
    *continueknap=1;
  }
  return TRUE;
}

BX_BOOL formCM_cmdStop_Click(HBOX hBox)
{
  if(testState(wstm,statew_running))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCM_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCM_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCM_CMDRUN));
    *continueknap=1;
  }
  return TRUE;
}

/*
BX_BOOL formStd_zeroKassePakker_Click(HBOX hBox)
{
  setMachineState("WorkCell","ST_IDLE");
  return TRUE;
}
*/
BX_BOOL formCM_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL formCM_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCM_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}
/*
BX_BOOL formCM_cmdZero_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formCM_cmdCalibrate_Click(HBOX hBox)
{
  return TRUE;
}

static BX_BOOL formStd_cmdCW_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formCW[0], formCWProc);
  languagechange=DoModal(hBx);
  return TRUE;
}
*/

static BX_BOOL formTools_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCM_cmdGoFree_Click(HBOX hBox){
  *goFree=1;
  return TRUE; 
}

BX_BOOL formCM_cmdGoHome_Click(HBOX hBox){
  *goHome=1;
  return TRUE; 
}

BX_BOOL formCM_cmdOpen_Click(HBOX hBox){
  *tryopen=1;
  return TRUE; 
}

BX_BOOL formCM_cmdClose_Click(HBOX hBox){
  *tryclose=1;
  return TRUE; 
}

BX_BOOL formCM_cmdStartConveyors_Click(HBOX hBox){
  *run=1;
  return TRUE; 
}

BX_BOOL formCM_cmdStopConveyors_Click(HBOX hBox){
  *run=0;
  return TRUE; 
}

BX_BOOL formCM_cmdLanguage_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLanguage[0], formLanguageProc);
	if(DoModal(hBx)==IDOK)
	{	
		languagechange++;
	}
  return TRUE;
}

BX_BOOL formCM_cmdMenu_Click(HBOX hBox)
{
  HBOX hBx,ToolBx,hOptions;
	extern BxIcon *icon1;
	extern BxIcon *icon2;
	extern BxIcon *icon3;
	extern BxIcon *icon4;
	
  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORMCM_CMDMENU), &pBxMainMenu);
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	
  //BX_BOOL portOpen = *getMachineValuePtr(getMachineIdx("PalleStationPort"),"isOpen");
  BX_BOOL stopped = (testState(wstm,statew_halt)
                     ||testState(wstm,statew_idle)
                     ||testState(wstm,statew_paused)
                     ||testState(wstm,statew_error));
  
  BxMenu_Add(hBx, getLanguageLineFromIdx(langptr, 251, "Goto home pos."), MENU, formCM_cmdGoHome_Click, TRUE, NULL);
  
  BxMenu_Add(hBx, getLanguageLineFromIdx(langptr, 252, "Open gate"), MENU, formCM_cmdOpen_Click, TRUE, NULL);
  BxMenu_Add(hBx, getLanguageLineFromIdx(langptr, 253, "Close gate"), MENU, formCM_cmdClose_Click, TRUE, NULL);
  
  if(conveyorcontrolstm != -1)
  {
    if(*run == 0)
      BxMenu_Add(hBx, getLanguageLineFromIdx(langptr, 254, "Start conveyor"), MENU, formCM_cmdStartConveyors_Click, TRUE, NULL);
    else
      BxMenu_Add(hBx, getLanguageLineFromIdx(langptr, 255, "Stop conveyor"), MENU, formCM_cmdStopConveyors_Click, TRUE, NULL);
  }

  if(stopped)
  {
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 235, "Box release"), MENU, formCM_cmdGoFree_Click, TRUE, NULL);
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1, "Program"), MENU, formCM_cmdProgram_Click, TRUE, icon2);
  }
  else
  {
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 235, "Box release"), MENU, formCM_cmdGoFree_Click, FALSE, NULL);
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1, "Program"), MENU, formCM_cmdProgram_Click, FALSE, NULL);
  }
  BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, formCM_cmdSupervisor_Click, TRUE, icon1);
  hOptions = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 18, "Setup"), SUB, NULL, TRUE, icon3);
  {
    BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 250, "Language"), MENU, formCM_cmdLanguage_Click, TRUE, NULL);
  }
  
  if(accesslevel>OPERATORLEVEL)
  {
    ToolBx = BxMenu_Add(hBx , getLanguageLineFromIdx(langptr, 19, "Tools"), SUB, NULL, TRUE, icon4);
    {
      if(tworkcell->dios.maxidx>0 || tworkcell->loadcells.maxidx>0 || tworkcell->comsks.maxidx>0 || tworkcell->macs.maxidx>0)
      {
				BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 24, "Dist. I/O"), MENU, formTools_cmdDistIO_Click, TRUE, NULL);
      }
      BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 25, "STM control"), MENU, formCM_cmdSTMCtrl_Click, TRUE, NULL);
    }
  }
  if(demo == 1)
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
  DoMenu(BxGetDlgItem(hBox, FORMCM_CMDMENU));
  return TRUE;
}
