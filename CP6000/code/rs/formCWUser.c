//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#include "Bx.h"
#include "BxGdi.h"
#include "formSTMList.h"
#include "formDistIO.h"
#include "formCW.h"
#include "formCWdata.h"
#include "formProgram.h"
#include "formLanguage.h"
#include "cmd.h"
#include "stm.h"
#include "robostackerBxr.h"
#include <time.h>
#include <sys/timeb.h>

extern char programStateMachineName[256];
extern int supervisorLogin(HBOX hBox);
extern BX_BOOL formDemo_cmdDemoClose_Click(HBOX hBox);
extern int demo;
extern volatile int dioIndex;
extern int accesslevel; //mc.c
char *GetCWVersion(void);
char *GetCWType(void);

static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

static char weightstr[256]="";
static char ws[256];
static char es[256];

tmpnStateMachineValue *avgWeight[3];
tmpnStateMachineValue *calcWeight[3];
tmpnStateMachineValue *weight;
tmpnStateMachineValue *fweight;
tmpnStateMachineValue *ffweight;
tmpnStateMachineValue *lowerWeight;
tmpnStateMachineValue *upperWeight;

char cwSlave[3][256]={"S1","S2","S3"};

static FONT strFont;

static int languagechange=0;
static int languagechangeonclose=0;

int cw60 = FALSE;

BX_BOOL formCWUserInit(HBOX hBox,BX_LPARAM lParam)
{
  char s[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_GROUPBOX1_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LAB1_4));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_CMDMENU));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_CMDSTOP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_CMDRUN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2_2_3));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2_2_3), getLanguageLineFromIdx(langptr, 106, "Lower < Weight < Upper"));

  sprintf(ws,"WorkCell%s",cwSlave[0]);
  if(getMachineIdx(ws) == -1)
  {
    //workcell using cw60xxx statemachines
    cw60 = TRUE;
    sprintf(ws,"WorkCell");
    sprintf(es,"Emergency");
    sprintf(programStateMachineName,"Program");
    sprintf(s,"checkWeigherCalc");
  }
  else
  {
    sprintf(es,"Emergency%s",cwSlave[0]);
    sprintf(programStateMachineName,"Program%s",cwSlave[0]);
    sprintf(s,"checkWeigherCalc%s",cwSlave[0]);
  }
  weight      = getMachineValue(getMachineIdx(s),"weight");
  fweight     = getMachineValue(getMachineIdx(s),"fweight");
  ffweight    = getMachineValue(getMachineIdx(s),"ffweight");

  if(cw60)
    sprintf(s,"checkWeigher");
  else
    sprintf(s,"checkWeigher%s",cwSlave[0]);
  avgWeight[0]   = getMachineValue(getMachineIdx(s),"avgWeight");
  calcWeight[0]   = getMachineValue(getMachineIdx(s),"calcWeight");

  //only >1 if not cw60
  if(rs_param.checkWeigher>1)
  {
    sprintf(s,"checkWeigher%s",cwSlave[1]);
    avgWeight[1]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[1]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  if(rs_param.checkWeigher>2)
  {
    sprintf(s,"checkWeigher%s",cwSlave[2]);
    avgWeight[2]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[2]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  
  if(cw60)
    sprintf(s,"Program");
  else
    sprintf(s,"Program%s",cwSlave[0]);
  lowerWeight = getMachineValue(getMachineIdx(s),"lowerWeight");
  upperWeight = getMachineValue(getMachineIdx(s),"upperWeight");
  
  BxAssignIntValue(BxGetDlgItem(hBox, FORMCW_LOWER));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMCW_UPPER));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABERROR1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABERROR2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABINFO));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABTIME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABWEIGHT));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_LABWEIGHT_2));
  BxOpenFont(&strFont, "data/decker.ttf", 70);
  BxSetFont(BxGetDC(BxGetDlgItem(hBox, FORMCW_LABWEIGHT)), &strFont);

  sprintf(s,"%s %s",GetCWType(),GetCWVersion());
  
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2));
  BxSetStringValue(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2),s);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABTIME), "00:00:00");
 return TRUE;
}

//void drawTab(BxDC* bdc);
BX_BOOL formCWUserUpdate(HBOX hBox)
{
  //  HBOX hBx;
  int t, m, ss;
  char workcellstr[256];
  char stmerror1[256];
  char stmerror2[256];
  char infostr[256];
  char tidstr[256];
  int stmErrorCode;
  int stmMessageCode;
  char s[256];
	char* programstr;
	int menuEn,runEn,stopEn;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
  tmpnStateMachine *stm;
 	if (languagechange>0)
	{
		languagechange=0;
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_LAB1_4), getLanguageLineFromIdx(langptr, 11, "Time:"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2_2_3), getLanguageLineFromIdx(langptr, 106, "Lower < Weight < Upper"));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABWORKCELLSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABERROR1));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABERROR2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABINFO));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABTIME));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABWEIGHT));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_LABWEIGHT_2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMCW_TEXTLABEL2_2));
	}
  if(cw60)
  {
    sprintf(ws,"WorkCell");
    sprintf(es,"Emergency");
    sprintf(s,"checkWeigher");
  }
  else
  {
    sprintf(ws,"WorkCell%s",cwSlave[0]);
    sprintf(es,"Emergency%s",cwSlave[0]);
    sprintf(s,"checkWeigher%s",cwSlave[0]);
  }
  stm=&tworkcell->statemachines.statemachine[getMachineIdx(s)];
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
    setStateTekst(infostr,stmMessageCode,0);
  }
//***************************************************************************
//* WorkCell.statemachine                                                   *
//***************************************************************************
  getWorkCellStr(ws,programstr,workcellstr);
//***************************************************************************
//* update 
//***************************************************************************
  if(accesslevel>OPERATORLEVEL)
  {
    if(cw60)
      sprintf(weightstr,"% .0f(% .0f)",calcWeight[0]->fdata,avgWeight[0]->fdata);
    else
      sprintf(weightstr,"%s:  % .0f(% .0f)",cwSlave[0],calcWeight[0]->fdata,avgWeight[0]->fdata);
  }
  else
  {
    if(cw60)
      sprintf(weightstr,"% .0f",calcWeight[0]->fdata);
    else
      sprintf(weightstr,"%s:  % .0f",cwSlave[0],calcWeight[0]->fdata);
  }
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABWEIGHT),weightstr);

//  if(accesslevel>OPERATORLEVEL)
//    sprintf(weightstr,"%04.0f %04.0f %04.0f %s",weight->fdata,fweight->fdata,ffweight->fdata,stm->state[stm->istate].name);
//  else
  if(accesslevel>OPERATORLEVEL)
  {
    sprintf(weightstr,"%s","");
    //only >1 if not cw60
    if(rs_param.checkWeigher>1)
      sprintf(weightstr,"%s: %.0f(%.0f)",cwSlave[1],calcWeight[1]->fdata,avgWeight[1]->fdata);
    if(rs_param.checkWeigher>2)
      sprintf(weightstr,"%s: %.0f(%.0f)   %s: %.0f(%.0f)",cwSlave[1],calcWeight[1]->fdata,avgWeight[1]->fdata
                                                        ,cwSlave[2],calcWeight[2]->fdata,avgWeight[2]->fdata);
  }  
  else
  {
    sprintf(weightstr,"%s","");
    if(rs_param.checkWeigher>1)
      sprintf(weightstr,"%s: % .0f",cwSlave[1],calcWeight[1]->fdata);
    if(rs_param.checkWeigher>2)
      sprintf(weightstr,"%s: % .0f   %s: % .0f",cwSlave[1],calcWeight[1]->fdata,cwSlave[2],calcWeight[2]->fdata);
  }  
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABWEIGHT_2),weightstr);

  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABERROR1), stmerror1);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABERROR2), stmerror2);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABINFO), infostr);     
  BxSetIntValue(BxGetDlgItem(hBox, FORMCW_LOWER), (lowerWeight->data));
  BxSetIntValue(BxGetDlgItem(hBox, FORMCW_UPPER), upperWeight->data);
//***************************************************************************
//* buttons 
//***************************************************************************
  if(isRunning(ws))
  {
    time(&sluttid);
    t = difftime(sluttid, starttid)/3600.0;
    m = (difftime(sluttid, starttid)-(t*3600.0))/60.0;
    ss = (difftime(sluttid, starttid)-(t*3600.0))-(m*60.0);
    sprintf(tidstr, "%02d:%02d:%02d", t, m, ss);
    BxSetBoxText(BxGetDlgItem(hBox, FORMCW_LABTIME), tidstr);
  }
  getButtonState(ws, es, &menuEn, &runEn, &stopEn);
  if(accesslevel>=OPERATORLEVEL) menuEn = TRUE;
  BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDRUN), runEn);
  BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDSTOP), stopEn);
  BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDMENU), menuEn);
  
  return TRUE;
}

static void signalContinueS(void)
{
  char s[256];
  if(cw60)
    sprintf(s,"ContinueKnap");
  else
    sprintf(s,"ContinueKnap%s",cwSlave[0]);
  *getMachineValuePtr(getMachineIdx(s),"knap")=1;
} 

BX_BOOL formCW_cmdRun_Click(HBOX hBox)
{
  char s[256];
  if(cw60)
    sprintf(s,"WorkCell");
  else
    sprintf(s,"WorkCell%s",cwSlave[0]);
  if(testMachineState(s,"ST_IDLE")
	 ||testMachineState(s,"ST_PAUSED")
   ||testMachineState(s,"ST_ERROR"))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
    signalContinueS();
  }
  return TRUE;
}

BX_BOOL formCW_cmdStop_Click(HBOX hBox)
{
  char s[256];
  if(cw60)
    sprintf(s,"WorkCell");
  else
    sprintf(s,"WorkCell%s",cwSlave[0]);
  if(testMachineState(s,"ST_RUNNING")
   ||testMachineState(s,"ST_PAUSED")
   ||testMachineState(s,"ST_ERROR"))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMCW_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMCW_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMCW_CMDRUN));
    signalContinueS();
  }
  return TRUE;
}

BX_BOOL formCW_Lower_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(BxGetIntValue(BxGetDlgItem(hBox, FORMCW_LOWER)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    lowerWeight->data = BxVirtNumBox_GetValue();
    BxSetIntValue(BxGetDlgItem(hBox, FORMCW_LOWER), lowerWeight->data);
  }
  return TRUE;
}

BX_BOOL formCW_Upper_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(BxGetIntValue(BxGetDlgItem(hBox, FORMCW_UPPER)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    upperWeight->data = BxVirtNumBox_GetValue();
    BxSetIntValue(BxGetDlgItem(hBox, FORMCW_UPPER), upperWeight->data);
  }
  return TRUE;
}

BX_BOOL formCW_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL formCW_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  if(cw60)
    sprintf(programStateMachineName,"Program");
  else
    sprintf(programStateMachineName,"Program%s",cwSlave[0]);
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCW_cmdLanguage_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLanguage[0], formLanguageProc);
	if(DoModal(hBx)==IDOK)
	{	
		languagechange++;
		if (strcmp(rs_param.mainDialog,"formCW"))
		{
			languagechangeonclose++;
		}
	}
  return TRUE;
}

BX_BOOL formCW_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCW_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCW_cmdSample_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formCWdata[0], formCWdataProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCW_cmdZero_Click(HBOX hBox)
{
  char s[256];
  if(cw60)
    sprintf(s,"checkWeigher");
  else
    sprintf(s,"checkWeigher%s",cwSlave[0]);
  *getMachineValuePtr(getMachineIdx(s),"doZero")=1;
  return TRUE;
}

BX_BOOL formCW_cmdSetScale_Click(HBOX hBox)
{
  char s[256];
  if(cw60)
    sprintf(s,"checkWeigher");
  else
    sprintf(s,"checkWeigher%s",cwSlave[0]);
  *getMachineValuePtr(getMachineIdx(s),"setScale")=1;
  return TRUE;
}

BX_BOOL formCW_cmdStatic_Click(HBOX hBox)
{
  char s[256];
  if(cw60)
    sprintf(s,"checkWeigher");
  else
    sprintf(s,"checkWeigher%s",cwSlave[0]);
  *getMachineValuePtr(getMachineIdx(s),"staticWeighing")=1;
  return TRUE;
}

//SX only used when not cw60

BX_BOOL formCW_S1_Click(HBOX hBox)
{
  char s[256];
  strcpy(cwSlave[0],"S1");
  strcpy(cwSlave[1],"S2");
  strcpy(cwSlave[2],"S3");
  sprintf(programStateMachineName,"Program%s",cwSlave[0]);
  sprintf(s,"checkWeigherCalc%s",cwSlave[0]);
  weight      = getMachineValue(getMachineIdx(s),"weight");
  fweight     = getMachineValue(getMachineIdx(s),"fweight");
  ffweight    = getMachineValue(getMachineIdx(s),"ffweight");

  sprintf(s,"checkWeigher%s",cwSlave[0]);
  avgWeight[0]   = getMachineValue(getMachineIdx(s),"avgWeight");
  calcWeight[0]   = getMachineValue(getMachineIdx(s),"calcWeight");
  if(rs_param.checkWeigher>1)
  {
    sprintf(s,"checkWeigher%s",cwSlave[1]);
    avgWeight[1]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[1]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  if(rs_param.checkWeigher>2)
  {
    sprintf(s,"checkWeigher%s",cwSlave[2]);
    avgWeight[2]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[2]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  
  sprintf(s,"Program%s",cwSlave[0]);
  lowerWeight = getMachineValue(getMachineIdx(s),"lowerWeight");
  upperWeight = getMachineValue(getMachineIdx(s),"upperWeight");
  return TRUE;
}

BX_BOOL formCW_S2_Click(HBOX hBox)
{
  char s[256];
  strcpy(cwSlave[0],"S2");
  strcpy(cwSlave[1],"S1");
  strcpy(cwSlave[2],"S3");
  sprintf(programStateMachineName,"Program%s",cwSlave[0]);
  sprintf(s,"checkWeigherCalc%s",cwSlave[0]);
  weight      = getMachineValue(getMachineIdx(s),"weight");
  fweight     = getMachineValue(getMachineIdx(s),"fweight");
  ffweight    = getMachineValue(getMachineIdx(s),"ffweight");

  sprintf(s,"checkWeigher%s",cwSlave[0]);
  avgWeight[0]   = getMachineValue(getMachineIdx(s),"avgWeight");
  calcWeight[0]   = getMachineValue(getMachineIdx(s),"calcWeight");
  if(rs_param.checkWeigher>1)
  {
    sprintf(s,"checkWeigher%s",cwSlave[1]);
    avgWeight[1]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[1]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  if(rs_param.checkWeigher>2)
  {
    sprintf(s,"checkWeigher%s",cwSlave[2]);
    avgWeight[2]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[2]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }

  sprintf(s,"Program%s",cwSlave[0]);
  lowerWeight = getMachineValue(getMachineIdx(s),"lowerWeight");
  upperWeight = getMachineValue(getMachineIdx(s),"upperWeight");
  return TRUE;
}

BX_BOOL formCW_S3_Click(HBOX hBox)
{
  char s[256];
  strcpy(cwSlave[0],"S3");
  strcpy(cwSlave[1],"S1");
  strcpy(cwSlave[2],"S2");
  sprintf(programStateMachineName,"Program%s",cwSlave[0]);
  sprintf(s,"checkWeigherCalc%s",cwSlave[0]);
  weight      = getMachineValue(getMachineIdx(s),"weight");
  fweight     = getMachineValue(getMachineIdx(s),"fweight");
  ffweight    = getMachineValue(getMachineIdx(s),"ffweight");

  sprintf(s,"checkWeigher%s",cwSlave[0]);
  avgWeight[0]   = getMachineValue(getMachineIdx(s),"avgWeight");
  calcWeight[0]   = getMachineValue(getMachineIdx(s),"calcWeight");
  if(rs_param.checkWeigher>1)
  {
    sprintf(s,"checkWeigher%s",cwSlave[1]);
    avgWeight[1]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[1]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }
  if(rs_param.checkWeigher>2)
  {
    sprintf(s,"checkWeigher%s",cwSlave[2]);
    avgWeight[2]   = getMachineValue(getMachineIdx(s),"avgWeight");
    calcWeight[2]   = getMachineValue(getMachineIdx(s),"calcWeight");
  }

  sprintf(s,"Program%s",cwSlave[0]);
  lowerWeight = getMachineValue(getMachineIdx(s),"lowerWeight");
  upperWeight = getMachineValue(getMachineIdx(s),"upperWeight");
  return TRUE;
}

BX_BOOL formCW_cmdClose_Click(HBOX hBox)
{
	BxEndDialog(hBox, languagechangeonclose);
	languagechangeonclose=0;
  return TRUE;
}

static BX_BOOL formTools_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formCW_cmdMenu_Click(HBOX hBox)
{
  HBOX hBx, ToolBx, hOptions;
	static char checks1[256];
	static char checks2[256];
	static char checks3[256];
	extern BxIcon *icon1;
	extern BxIcon *icon2;
	//extern BxIcon *icon3;
	//extern BxIcon *icon4;
	
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	char *checkptr=getLanguageLineFromIdx(langptr, 20, "checkWeigher");
	sprintf(checks1,"%s S1",checkptr);
	sprintf(checks2,"%s S2",checkptr);
	sprintf(checks3,"%s S3",checkptr);

  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORMCW_CMDMENU), &pBxMainMenu);
  
  if(rs_param.checkWeigher>0 && ! cw60)
    BxMenu_Add(hBx ,checks1, MENU, formCW_S1_Click, TRUE, NULL);
  if(rs_param.checkWeigher>1)
    BxMenu_Add(hBx ,checks2, MENU, formCW_S2_Click, TRUE, NULL);
  if(rs_param.checkWeigher>2)
    BxMenu_Add(hBx ,checks3, MENU, formCW_S3_Click, TRUE, NULL);

  BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, formCW_cmdProgram_Click, TRUE, icon2);
  BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, formCW_cmdSupervisor_Click, TRUE, icon1);
  hOptions = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 18,"Setup"), SUB, NULL, TRUE, NULL);//icon3);
  {
    BxMenu_Add(hOptions, getLanguageLineFromIdx(langptr, 40, "Zero"), MENU, formCW_cmdZero_Click, TRUE, NULL);
		BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 250, "Language"), MENU, formCW_cmdLanguage_Click, TRUE, NULL);
	}
  if(accesslevel>OPERATORLEVEL)
  {
    ToolBx = BxMenu_Add(hBx , getLanguageLineFromIdx(langptr, 19, "Tools"), SUB, NULL, TRUE, NULL);//icon4);
    if(tworkcell->dios.maxidx>0 || tworkcell->loadcells.maxidx>0 || tworkcell->comsks.maxidx>0 || tworkcell->macs.maxidx>0)
    {
      BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 24, "Dist. I/O"), MENU, formTools_cmdDistIO_Click, TRUE, NULL);
    }
		BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 25, "STM control"), MENU, formCW_cmdSTMCtrl_Click, TRUE, NULL);
  	BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 104, "Sample weight"), MENU, formCW_cmdSample_Click, TRUE, NULL);
  	BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 105, "Static weighing"), MENU, formCW_cmdStatic_Click, TRUE, NULL);
		
//    BxMenu_Add(hOptions ,"Set scale", MENU, formCW_cmdSetScale_Click, TRUE, NULL);
  }
  if(strcmp(rs_param.mainDialog,"formCW")!=0)
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54, "Close"), MENU, formCW_cmdClose_Click, TRUE, NULL);
  if(demo == 1)
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
  DoMenu(BxGetDlgItem(hBox, FORMCW_CMDMENU));
	return TRUE;
}

BX_BOOL formCW_cmdSpeed_Click(HBOX hBox)
{
  return TRUE;
}

