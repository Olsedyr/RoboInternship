//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#include <unistd.h>
#include <time.h>
#include <sys/timeb.h>
#include "Bx.h"
#include "formStdRun.h"
#include "formCW.h"
#include "formAxisParm.h"
#include "formHome.h"
#include "formJogAxis.h"
#include "formJogIk.h"
#include "formJogTool.h"
#include "formFixPoints.h"
#include "formOffsetPath.h"
#include "formSetIO.h"
#include "formDistIO.h"
#include "formProgram.h"
#include "formEditSysParam.h"
#include "formSysParam.h"
#include "formEditTcp.h"
#include "formAdjBoxFrames.h"
#include "formEditBoxPattern.h"
#include "formLogger.h"
#include "formSetDebug.h"
#include "formStatus.h"
#include "formContinue.h"
#include "formSTMList.h"
#include "formLanguage.h"
#include "formManual319.h"
#include "formManual320.h"
#include "formManual321.h"
#include "robostackerBxr.h"
#include "cmd.h"
#include "rs.h"
#include "stm.h" 
//
extern int supervisorLogin(HBOX hBox);
extern BX_BOOL formDemo_cmdDemoClose_Click(HBOX hBox);
extern char mcstm[256];
extern int demo;
char wstr[256]="WorkCell";
static BXMENUSTRUCT pBxMainMenu;
static time_t starttid;
static time_t sluttid;

static BX_PSTRING hstr = "Hastighed";
static BX_PSTRING ehstr = "";

extern volatile int dioIndex;
extern char programStateMachineName[256];
char *programName;

extern volatile int trioUpAndRunning;
extern volatile int bxUpAndRunning;
extern volatile int stmUpAndRunning;

static int robotstm=-1;
static int staterobot_followerror=-1;
static int staterobot_idle = -1;
static int staterobot_halt = -1;
static int staterobot_reset = -1;
static int staterobot_emergency = -1;
static int staterobot_supervisor = -1;
static int staterobot_mc_comerror = -1;
static int staterobot_simulate_mc = -1;
static int staterobot_running = -1;
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
static int *axist=NULL;
static int *mpnstate=NULL;
static int *supervisorlevel=NULL;
static int *continueknap=NULL;
static int framesstm = -1;
static int pallestablerstm = -1;
static int pallemagasinstm = -1;
static int shuttlestm = -1;
static int *userpalletout=NULL;
static int *userPalletAOut=NULL;
static int *userPalletBOut=NULL;
static int *userPalletStackerOut=NULL;//Søris
static int *restartPallestabler=NULL;//Søris
static int *restartPallemagasin=NULL;//Søris
static int *restartShuttle=NULL;//Harndrup
static int *userClearRoboError=NULL;//used to continue after followerror and emergency stop when workcell is RUNNING
static int *itemCounter=NULL;
static int *userSetcBItem=NULL;
static int gotScissorSecureReset = 0;
static int *caitem=NULL;
static int *cbitem=NULL;
static int *reversebutton1=NULL;
static int *reversebutton2=NULL;

static int languagechange=0;

BX_BOOL formStdRunUserInit(HBOX hBox,BX_LPARAM lParam)
{
  char s[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	

	BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_GROUPBOX1_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU));
	BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
	hstr = getLanguageLineFromIdx(langptr, 15, "Speed");
	BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
	
  if(accesslevel>OPERATORLEVEL)
  {
		//    BxShowBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), TRUE);
    BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2));
    BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2), hstr);
  }
  else
  {
		// BxShowBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), FALSE);
    BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2));
    BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2), ehstr);
  }
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), 100.0 * GetSpeedFactor());

  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABWORKCELLSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABROBOTSTATE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABINFO));

  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_LABTIME));
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABTIME), "00:00:00");
  time(&starttid);

  BxAssignStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2));

  sprintf(s,"%s %s",GetRSType(),GetRSVersion());
  BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2),s);
  
  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
  
	robotstm = getMachineIdx("Robot");
	staterobot_followerror = getStateIdx(robotstm, "ST_FOLLOWERROR");
	staterobot_idle = getStateIdx(robotstm, "ST_IDLE");
	staterobot_halt = getStateIdx(robotstm, "ST_HALT");
	staterobot_reset = getStateIdx(robotstm, "ST_RESET");
	staterobot_emergency = getStateIdx(robotstm, "ST_EMERGENCY");
	staterobot_supervisor = getStateIdx(robotstm, "ST_SUPERVISOR");
	staterobot_mc_comerror = getStateIdx(robotstm, "ST_MC_COMERROR");
	staterobot_simulate_mc = getStateIdx(robotstm, "ST_SIMULATE_MC");
	staterobot_running = getStateIdx(robotstm, "ST_RUNNING");
	wstm = getMachineIdx(wstr);
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
	axist = getMachineValuePtr(robotstm,"axis_t");
  mpnstate = getMachineValuePtr(robotstm,"mpnstate");
	supervisorlevel = getMachineValuePtr(robotstm,"supervisorlevel");
	if (rs_param.roboStacker>1)
	{
		framesstm = getMachineIdx("Frames");
		userClearRoboError = getMachineValuePtr(getMachineIdx("RoboError"),"userClearRoboError");

    //search for scissor secure
    tmpnStateMachine *stm;
    int i,j;
    for(i=0;i<tworkcell->statemachines.maxidx && gotScissorSecureReset == 0;i++)
    {
      stm = &tworkcell->statemachines.statemachine[i];
      for(j=0;j<stm->numoutput;j++)
      {
        if (stm->output[j].iotype==OUTPUT)
        {
          if(strcmp(stm->output[j].name, "scissorSecureReset")==0)
          {
            gotScissorSecureReset = 1;
          }
        }
      }
    }

		itemCounter = getMachineValuePtr(framesstm,"itemCounter");
    userSetcBItem = getMachineValuePtr(getMachineIdx("ProgramB2"),"userSetcBItem");
		userpalletout = getMachineValuePtr(framesstm,"userPalletOut");
		userPalletAOut = getMachineValuePtr(framesstm,"userPalletAOut");
		userPalletBOut = getMachineValuePtr(framesstm,"userPalletBOut");

		pallestablerstm = getMachineIdx("Pallestabler");
    if(pallestablerstm != -1)
    {
      userPalletStackerOut = getMachineValuePtr(pallestablerstm,"userPalletOut");
      restartPallestabler = getMachineValuePtr(pallestablerstm,"restart");
    }
    pallemagasinstm = getMachineIdx("Pallemagasin");
    if(pallemagasinstm != -1)
    {
      printf("PalleMagasin stm: %d", pallemagasinstm);
      restartPallemagasin = getMachineValuePtr(pallemagasinstm,"userPMrestart");
      printf("%d", *restartPallemagasin);
    } 
    shuttlestm = getMachineIdx("Shuttle");
    if(shuttlestm != -1)
    {
      printf("Shuttle stm: %d", shuttlestm);
      restartShuttle = getMachineValuePtr(shuttlestm,"userShuttleRestart");
      printf("%d", *restartShuttle);
    } 
    caitem = getMachineValuePtr(framesstm,"cAItem");
		cbitem = getMachineValuePtr(framesstm,"cBItem");
		int reversibles=0;
		for (i=0;i<tworkcell->statemachines.maxidx;i++)
		{
			for (j=0;j<tworkcell->statemachines.statemachine[i].numvalue;j++)
			{
				if (!strcmp(tworkcell->statemachines.statemachine[i].value[j].name,"reverseButton"))
				{
					if (reversibles==0)
					{
						reversebutton1=&tworkcell->statemachines.statemachine[i].value[j].data;
						reversibles++;
					}
					else 
					{
						reversebutton2=&tworkcell->statemachines.statemachine[i].value[j].data;
						reversibles++;
						break;
					}
				}
			}
			if (reversibles>1) break;
		}
	}
	return TRUE;
}

BX_BOOL formStdRunUserUpdate(HBOX hBox)
{
  //  HBOX hBx6;
  int t, m, s;
  char workcellstr[256];
  char robotstr[512];
  char msgtype[256];
  char msgstr[256];
  char tidstr[256];
  char infostr[256];
  char robotstate[256];
  char numstr[256];
  int numOfError;
	//	int *palletB_cBItems;
  int stmErrorCode;
  int stmMessageCode;
	BX_BOOL menuEn,runEn,stopEn;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	if (languagechange>0)
	{
		languagechange=0;
		BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_GROUPBOX1_2_2), getLanguageLineFromIdx(langptr, 16, "Information"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), getLanguageLineFromIdx(langptr, 17, "Menu"));
		hstr = getLanguageLineFromIdx(langptr, 15, "Speed");
		BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), getLanguageLineFromIdx(langptr, 13, "Stop"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), getLanguageLineFromIdx(langptr, 14, "Go"));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABWORKCELLSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABROBOTSTATE));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR1));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR2));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABINFO));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_LABTIME));
		BxRequestPaint(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2));
	}
  sprintf(programStateMachineName,"Program%d",rs_param.workcellid);
	
  if(accesslevel>OPERATORLEVEL
		 ||rs_param.workcellid==305
		 ||rs_param.workcellid==306
		 ||rs_param.workcellid==309)
  {
    //BxShowBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), TRUE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2), hstr);
  }
  else
  {
		BxSetStringValue(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL2_2_2), ehstr);
		//BxShowBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), FALSE);
  }
	BxSetFloatValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), 100.0 * GetSpeedFactor());
	stmMessageCode = getStateMachineMessage();
  if(stmMessageCode>0)
  {
    setStateTekst(infostr,stmMessageCode,0);
  }
  else sprintf(infostr,"%s","");

  sprintf(msgstr,"%s","");
  sprintf(msgtype,"%s","");

//***************************************************************************
//* roboError = why have we stopped                                         *
//***************************************************************************
  numOfError=0;
  while(getStateMachineError(numOfError)>0)
    numOfError++;

	stmErrorCode=getStateMachineError(0);
	if(stmErrorCode>0)
	{
		setStateTekst(msgtype,stmErrorCode,0);
    sprintf(numstr,"   (nr=%d)",stmErrorCode);
    strcat(msgtype,numstr);
		setStateTekst(msgstr,stmErrorCode,1);
		if (strlen(msgstr)==0)
		{
			stmErrorCode=getStateMachineError(1);
			if(stmErrorCode>0)
			{
				setStateTekst(msgstr,stmErrorCode,0);
        sprintf(numstr,"(nr=%d)",stmErrorCode);
        strcat(msgstr,numstr);
			}
		}
    //sprintf(numstr," (%d)",numOfError);
    //strcat(msgstr,numstr);
	}

//***************************************************************************
// Robot.statemachine                                                       *
//***************************************************************************

	if(testState(robotstm,staterobot_halt))
	{
		char *language_line = getLanguageLineFromIdx(langptr, 121, "Robot not ready");
    sprintf(robotstate, "%s", language_line);
	}
  else if(testState(robotstm,staterobot_idle)||testState(robotstm,staterobot_idle))
	{
    char *language_line = getLanguageLineFromIdx(langptr, 122,"Awaiting command");
		sprintf(robotstate,"%s", language_line);
	}
	else if (testState(robotstm,staterobot_followerror))
	{
		// check for follow error.
		int val = GetErrorAxis();
		sprintf(robotstate,"%s %d",getLanguageLineFromIdx(langptr, 123,"Follow error on axis"),val);
	}
	else if (testState(robotstm,staterobot_emergency))
	{
    if(*mpnstate >= 40 && *mpnstate < 7200)
    {
      //new messages based on pmpnstate in ZPOWERUP.bas
      //more detailed progress information
      //trio.c::startUp() sequence:
      //step 1: mpn_command_startup 2
      //step 2:
      //v1: SetUnitsAndDefaults (mpn_cmd) mpn_command_set_units_and_defaults 3
      //v2: SetAxisParamValues (ctrl_cmd) ctrl_command_axisvalues            14
      //step 3: ResetAxis mpn_command_resetaxis 5
      //step 4: SetHomeAll mpn_command_set_mpn_home_all 8

      //case 40: ZPOWERUP.bas: GOSUB mpnstartup
      if(*mpnstate == 40) //mpn_command_startup 2
        sprintf(robotstate,"mpnstartup");
      else if(*mpnstate >= 41 && *mpnstate <= 46)
        sprintf(robotstate,"%s: %s %c",
                getLanguageLineFromIdx(langptr,128,"Starting"),
                getLanguageLineFromIdx(langptr,45,"Axis"),
                *mpnstate + 24); //ascii for A=65 (*mpnstate for A=41)
   
      else if(*mpnstate == 50) //mpn_command_set_units_and_defaults 3
        sprintf(robotstate,"set_units_and_defaults");
      else if(*mpnstate >= 51 && *mpnstate <= 56)
        sprintf(robotstate,"%s: %s %c",
                getLanguageLineFromIdx(langptr,302,"Setting units and defaults"),
                getLanguageLineFromIdx(langptr,45,"Axis"),
                *mpnstate + 14); //ascii for A=65 (*mpnstate for A=51)
      else if(*mpnstate == 57)
        sprintf(robotstate,"%s: %s %c",
                getLanguageLineFromIdx(langptr,302,"Setting units and defaults"),
                getLanguageLineFromIdx(langptr,45,"Axis"),
                'T');
      else if(*mpnstate == 58)
        sprintf(robotstate,"%s: %s %c%c",
                getLanguageLineFromIdx(langptr,302,"Setting units and defaults"),
                getLanguageLineFromIdx(langptr,45,"Axis"),
                'V','T');
      /* pmpncommand=4 not in use?
      else if(*mpnstate == 60)
        sprintf(robotstate,"set_defpos");
      else if(*mpnstate >= 61 && *mpnstate <= 66)
        sprintf(robotstate,"%s %c",
                getLanguageLineFromIdx(langptr,45,"Axis"),
                *mpnstate + 4); //ascii for A=65 (*mpnstate for A=61)
      */
      
      else if(*mpnstate == 70) //mpn_command_resetaxis 5
        sprintf(robotstate,"resetaxis");
      else if(*mpnstate >= 71 && *mpnstate <= 76)
        sprintf(robotstate,"%s %c",
                getLanguageLineFromIdx(langptr,303,"Resetting axis"),
                *mpnstate - 6); //ascii for A=65 (*mpnstate for A=71)

      else if(*mpnstate == 80) //mpn_command_set_mpn_home_all 8
        sprintf(robotstate,"resetaxis");
      else if(*mpnstate >= 81 && *mpnstate <= 86)
        sprintf(robotstate,"%s: %s %c",
                getLanguageLineFromIdx(langptr,304, "Finding zero position"),
                getLanguageLineFromIdx(langptr,45,"Axis"),
                *mpnstate - 16); //ascii for A=65 (*mpnstate for A=81)
    
        //700X Unable to reset drive axis X
        //702X "DL.ER - No slm module detected"
        //703X "DL.ER - No Drive Detected"
        //704X "Motor Object incompatible with initialisation routine version"
        //705X "SL.ER 2 - Motor Data Checksum Incorrect"
        //706X "SL.ER 1 - Encoder Data Checksum Incorrect"
        //707X "SL.ER 4 - Motor Default gains not available"
        //708X "SL.ER 64 - Wrong version of performance object loaded"
        //709X "SL.ER 8 - CT-Coder Failed"
        //710X "Ctc - CT-Coder Failed"
        //711X "Dr.Si - Motor / Drive Current Mismatch is too large"
      else if(*mpnstate >= 7001 && *mpnstate <= 7006)
        sprintf(robotstate, "%s: %s %c",
                "Unable to reset drive","Axis",
                *mpnstate - 6936); //ascii for A=65 (*mpnstate for A=7001)
      else if(*mpnstate >= 7021 && *mpnstate <= 7026)
        sprintf(robotstate, "%s: %s %c",
                "No SLM module detected","Axis",
                *mpnstate - 6956); //ascii for A=65 (*mpnstate for A=7021)
      else if(*mpnstate >= 7031 && *mpnstate <= 7036)
        sprintf(robotstate, "%s: %s %c",
                "No drive detected","Axis",
                *mpnstate - 6966); //ascii for A=65 (*mpnstate for A=7031)
      else if(*mpnstate >= 7041 && *mpnstate <= 7046)
        sprintf(robotstate, "%s: %s %c",
                "Motor Object incompatible with initialisation routine version","Axis",
                *mpnstate - 6976); //ascii for A=65 (*mpnstate for A=7041)
      else if(*mpnstate >= 7051 && *mpnstate <= 7056)
        sprintf(robotstate, "%s: %s %c",
                "Motor data checksum incorrect","Axis",
                *mpnstate - 6986); //ascii for A=65 (*mpnstate for A=7051)
      else if(*mpnstate >= 7061 && *mpnstate <= 7066)
        sprintf(robotstate, "%s: %s %c",
                "Encoder data checksum incorrect","Axis",
                *mpnstate - 6996); //ascii for A=65 (*mpnstate for A=7061)
      else if(*mpnstate >= 7071 && *mpnstate <= 7076)
        sprintf(robotstate, "%s: %s %c",
                "Motor default gains not available","Axis",
                *mpnstate - 7006); //ascii for A=65 (*mpnstate for A=7071)
      else if(*mpnstate >= 7081 && *mpnstate <= 7086)
        sprintf(robotstate, "%s: %s %c",
                "Wrong version of performance object loaded","Axis",
                *mpnstate - 7016); //ascii for A=65 (*mpnstate for A=7081)
      else if(*mpnstate >= 7091 && *mpnstate <= 7096)//doesn't seem to exist in ZPOWERUP.bas
        sprintf(robotstate, "%s: %s %c",
                "CT-Coder failed","Axis",
                *mpnstate - 7026); //ascii for A=65 (*mpnstate for A=7091)
      else if(*mpnstate >= 7101 && *mpnstate <= 7106)
        sprintf(robotstate, "%s: %s %c",
                "CT-Coder failed","Axis",
                *mpnstate - 7036); //ascii for A=65 (*mpnstate for A=7101)
      else if(*mpnstate >= 7111 && *mpnstate <= 7116)
        sprintf(robotstate, "%s: %s %c",
                "Motor/drive current mismatch is too large","Axis",
                *mpnstate - 7046); //ascii for A=65 (*mpnstate for A=7111)
      else
        sprintf(robotstate,"Unknown robotstate");
    }
    else
      //old style
      //char *language_line = getLanguageLineFromIdx(langptr, 124,"The robot's emergency stop is activated");
      sprintf(robotstate, getLanguageLineFromIdx(langptr, 124,"The robot's emergency stop is activated"));
  }
	else if (testState(robotstm,staterobot_supervisor))
	{
    char *language_line = getLanguageLineFromIdx(langptr, 125,"The robot can't start due to power failure. Call supervisor.");
		sprintf(robotstate,"%s", language_line);
		
		if (accesslevel>MANAGERLEVEL)
			*supervisorlevel=1;
	}
	else if (testState(robotstm,staterobot_mc_comerror))
	{
    char *language_line = getLanguageLineFromIdx(langptr, 126,"Communication error with Trio");
		sprintf(robotstate,"%s",language_line);
	}
	else if (testState(robotstm,staterobot_simulate_mc))
	{
    char *language_line = getLanguageLineFromIdx(langptr, 127,"Motion-controller simulation");
		sprintf(robotstate,"%s",language_line);
	}
	else if (testState(robotstm,staterobot_running))
	{
		if (mpnstate != NULL)
			setStateTekst(robotstate,*mpnstate,0);
	}
	else 
	{
		sprintf(robotstate,"%s=%i",getLanguageLineFromIdx(langptr, 86,"State"),tworkcell->statemachines.statemachine[robotstm].istate);
	}
  //tal er kun til nørder
  if((accesslevel>OPERATORLEVEL)&&(axist != NULL)&&(mpnstate != NULL))
  {
//    int valA,valB; 
//    valA= atoi(getCounterValue("cAItems"));
//    valB= atoi(getCounterValue("cBItems"));
//    sprintf(robotstr,"%s (%d) %d cItems: (%i,%i)(0,%d)",robotstate,*mpnstate,*axist,valA,valB,*palletB_cBItems);

    sprintf(robotstr,"%s (%d) %d",robotstate,*mpnstate,*axist);
  }
  else
  {
    sprintf(robotstr,"%s",robotstate);
  }

  {
//***************************************************************************
//* mcstm.statemachine                                                   *
//***************************************************************************
 	  programName = getProgramName(programStateMachineName);
		
		//if(!stmUpAndRunning||!bxUpAndRunning)
		if(!stmUpAndRunning)
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 121,"Robot not ready"));
    } 
		else if(testState(wstm,statew_idle))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 97,"Ready"));
    } 
		else if(testState(wstm,statew_starting))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 128,"Starting"));
    }
		else if(testState(wstm,statew_restarting))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 129,"Continuing"));
    }
    else if(testState(wstm,statew_running))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 130,"Running"));
    }
    else if(testState(wstm,statew_stopping))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 131,"Stopping"));
    }
    else if(testState(wstm,statew_pausing))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 132,"Preparing pause"));
    }
    else if(testState(wstm,statew_paused))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 133,"Paused"));
    }
    else if(testState(wstm,statew_error))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 134,"Error"));
    }
    else if(testState(wstm,statew_halt))
    {
      sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 135,"Halted"));
    }
		else
		{
			sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programName,getLanguageLineFromIdx(langptr, 134,"Error"));
		}
  }
  
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABWORKCELLSTATE), workcellstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABROBOTSTATE), robotstr);
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR1), msgtype);
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABERROR2), msgstr);     
  BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABINFO), infostr);     

	menuEn=FALSE;
	runEn=TRUE;
	stopEn=TRUE;
  
  sprintf(tidstr, "00:00:00");
  if(isRunning(wstr))
  {
    time(&sluttid);
    t = difftime(sluttid, starttid)/3600.0;
    m = (difftime(sluttid, starttid)-(t*3600.0))/60.0;
    s = (difftime(sluttid, starttid)-(t*3600.0))-(m*60.0);
    sprintf(tidstr, "%02d:%02d:%02d", t, m, s);
  }

  if(itemCounter!=NULL)
  {
    char outstring[256];	
    sprintf(outstring,"Total %d",*itemCounter);
    BxSetBoxText(BxGetDlgItem(hBox, FORMSTDRUN_LABTIME), outstring);
  }

  getButtonState(wstr, "Emergency", &menuEn, &runEn, &stopEn);
  if(testState(robotstm,staterobot_supervisor)&&accesslevel<=MANAGERLEVEL)
	{
		menuEn=TRUE;
		stopEn=FALSE;
		runEn=FALSE;
	}
  if(accesslevel<=OPERATORLEVEL)
  {
		menuEn=TRUE;
  }
  
	if (!testState(robotstm,staterobot_idle)&&!testState(robotstm,staterobot_simulate_mc))
		runEn=FALSE;
	BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), menuEn);
	BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), runEn);
	BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), stopEn);
  return TRUE;
}

BX_BOOL formStdRun_cmdSpeed_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED)));
  BxVirtNumBox_SetFloatLimits(1.0, 100.0);
	
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMSTDRUN_CMDSPEED), BxVirtNumBox_GetFloatValue());
    speedFactor = BxVirtNumBox_GetFloatValue()*0.01;
  }
  return TRUE;
}

BX_BOOL formStdRun_cmdRun_Click(HBOX hBox)
{
  if(testState(wstm,statew_idle)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN));
    time(&starttid);
    rs_param.lag=0; //always start with init script
    *continueknap=1;
  }
  return TRUE;
}

BX_BOOL formStdRun_cmdStop_Click(HBOX hBox)
{
  if(testState(wstm,statew_running)
		 ||testState(wstm,statew_paused)
		 ||testState(wstm,statew_error))
  {
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), FALSE);
    BxEnableBox(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), FALSE);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), BM_PAINT, 0, 0);
    BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN), BM_PAINT, 0, 0);
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDSTOP));
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU));
    BxUpdateView(BxGetDlgItem(hBox, FORMSTDRUN_CMDRUN));
    *continueknap=1;
  }
	return TRUE;
}

BX_BOOL formTools_cmdAxis_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formAxisParm[0], formAxisParmProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdInOut_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSetIO[0], formSetIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formStd_cmdManual_Click(HBOX hBox)
{
  HBOX hBx;
  if(rs_param.workcellid == 320)
    hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formManual320[0], formManual320Proc);
  else if(rs_param.workcellid == 321)
    hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formManual321[0], formManual321Proc);
  else if(rs_param.workcellid == 319)
    hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formManual319[0], formManual319Proc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdSTMCtrl_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSTMList[0], formSTMListProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdJogAxis_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formJogAxis[0], formJogAxisProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdJogIk_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formJogIk[0], formJogIkProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdJogTool_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formJogTool[0], formJogToolProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdFixPoints_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formFixPoints[0], formFixPointsProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdStatus_Click(HBOX hBox)
{
  HBOX hBx;

  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formStatus[0], formStatusProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdSystem_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSysParam[0], formSysParamProc);
  if(DoModal(hBx)==IDOK)
  {
    SaveRSSystemData(&rs_param);
  }
  return TRUE;
}

BX_BOOL formTools_cmdLanguage_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLanguage[0], formLanguageProc);
	if(DoModal(hBx)==IDOK)
	{	
		languagechange++;
	}
  return TRUE;
}

BX_BOOL formTools_cmdLog_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formLogger[0], formLoggerProc);
  DoModal(hBx);
  return TRUE;
}

/*
BX_BOOL formTools_cmdCalOffset_Click(HBOX hBox)
{
  HBOX hBx;
  tmpnVector aktpos;

  aktpos.x = trobot->m_worldPoint.x;
  aktpos.y = trobot->m_worldPoint.y;
  aktpos.z = trobot->m_worldPoint.z;
  aktpos.v = trobot->m_worldPoint.v;
  aktpos.w = trobot->m_worldPoint.w;

  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formOffsetPath[0], formOffsetPathProc);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDX), aktpos.x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDY), aktpos.y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDZ), aktpos.z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDV), aktpos.v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDW), aktpos.w);

  if(DoModal(hBx)==IDOK)
  {
    CalOffset.x =  BxGetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDX)) - aktpos.x;
    CalOffset.y =  BxGetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDY)) - aktpos.y;
    CalOffset.z =  BxGetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDZ)) - aktpos.z;
    CalOffset.v =  BxGetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDV)) - aktpos.v;
    CalOffset.w =  BxGetFloatValue(BxGetDlgItem(hBx, FORMOFFSETPATH_CMDW)) - aktpos.w;
  }
  return TRUE;
}
*/
BX_BOOL formTools_cmdAutoHome_Click(HBOX hBox)
{
  if(autoHomeSensor()==0)
    SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeA_Click(HBOX hBox)
{
  trobot->m_mpnhome.a=moveToHomeSensor(axis_a);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeB_Click(HBOX hBox)
{
  trobot->m_mpnhome.b=moveToHomeSensor(axis_b);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeC_Click(HBOX hBox)
{
  trobot->m_mpnhome.c=moveToHomeSensor(axis_c);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeD_Click(HBOX hBox)
{
  trobot->m_mpnhome.d=moveToHomeSensor(axis_d);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeE_Click(HBOX hBox)
{
  trobot->m_mpnhome.e=moveToHomeSensor(axis_e);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdMoveHomeF_Click(HBOX hBox)
{
  trobot->m_mpnhome.f=moveToHomeSensor(axis_f);
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroA_Click(HBOX hBox)
{
  float currentposition;
  currentposition = GetMPos(axis_a); //or DPos?
  trobot->m_jointCalib.a=0.0-trobot->m_sign.name.a*currentposition;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroB_Click(HBOX hBox)
{
  float currentposition;
  currentposition = GetMPos(axis_b); //or DPos?
  trobot->m_jointCalib.b=90.0-trobot->m_sign.name.b*currentposition;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroC_Click(HBOX hBox)
{
  float currentposition;
  currentposition = GetMPos(axis_c); //or DPos?
  trobot->m_jointCalib.c=trobot->m_sign.name.c*currentposition;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroD_Click(HBOX hBox)
{
  float a,b,c,d,e,f;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
  f = GetMPos(axis_f); //or DPos?
  trobot->m_jointCalib.d=0.0;
  trobot->m_jointCalib.e=0.0;
  trobot->m_jointCalib.f=0.0;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.d=trobot->m_sign.name.d*trobot->m_worldPoint.v;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroE_Click(HBOX hBox)
{
  float a,b,c,d,e,f;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
  f = GetMPos(axis_f); //or DPos?
  trobot->m_jointCalib.e=0.0;
  trobot->m_jointCalib.f=0.0;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.e=trobot->m_sign.name.e*trobot->m_worldPoint.w;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}
BX_BOOL formTools_cmdSetZeroF_Click(HBOX hBox)
{
  float a,b,c,d,e,f;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
  f = GetMPos(axis_f); //or DPos?
  trobot->m_jointCalib.f=0.0;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.f=trobot->m_sign.name.f*trobot->m_worldPoint.u;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}

BX_BOOL formTools_cmdSetZeroTool_Click(HBOX hBox)
{
  float a,b,c,d,e,f;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
  f = GetMPos(axis_f); //or DPos?
  trobot->m_jointCalib.d=0.0;
  trobot->m_jointCalib.e=0.0;
  trobot->m_jointCalib.f=0.0;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.d=trobot->m_sign.name.d*trobot->m_worldPoint.v;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.e=trobot->m_sign.name.e*trobot->m_worldPoint.w;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.f=trobot->m_sign.name.f*trobot->m_worldPoint.u;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}

BX_BOOL formTools_cmdSetTool90_Click(HBOX hBox)
{
  float a,b,c,d,e,f;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
  f = GetMPos(axis_f); //or DPos?
  trobot->m_jointCalib.d=0.0;
  trobot->m_jointCalib.e=0.0;
  trobot->m_jointCalib.f=0.0;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.d=trobot->m_sign.name.d*(trobot->m_worldPoint.v-90.0);
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.e=trobot->m_sign.name.e*trobot->m_worldPoint.w;
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,f,2); //use tcp "zero"
  trobot->m_jointCalib.f=trobot->m_sign.name.f*trobot->m_worldPoint.u;
  SaveCalibrationParam(&rs_param);
  return TRUE;
}

BX_BOOL formTools_cmdSetupSysParam_Click(HBOX hBox)
{
  HBOX hBx;

  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formEditSysParam[0], formEditSysParamProc);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAMIN), trobot->m_min.x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBMIN), trobot->m_min.y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCMIN), trobot->m_min.z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDMIN), trobot->m_min.v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEMIN), trobot->m_min.w);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAMAX), trobot->m_max.x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBMAX), trobot->m_max.y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCMAX), trobot->m_max.z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDMAX), trobot->m_max.v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEMAX), trobot->m_max.w);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAROFF), trobot->m_localTrans.x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBROFF), trobot->m_localTrans.y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCROFF), trobot->m_localTrans.z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDROFF), trobot->m_localTrans.v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEROFF), trobot->m_localTrans.w);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDACOFF), trobot->m_jointCalib.a);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBCOFF), trobot->m_jointCalib.b);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCCOFF), trobot->m_jointCalib.c);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDCOFF), trobot->m_jointCalib.d);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDECOFF), trobot->m_jointCalib.e);

  if(DoModal(hBx)==IDOK)
  {
    trobot->m_min.x = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAMIN));
    trobot->m_min.y = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBMIN));
    trobot->m_min.z = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCMIN));
    trobot->m_min.v = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDMIN));
    trobot->m_min.w = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEMIN));
    trobot->m_max.x = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAMAX));
    trobot->m_max.y = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBMAX));
    trobot->m_max.z = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCMAX));
    trobot->m_max.v = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDMAX));
    trobot->m_max.w = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEMAX));

    trobot->m_localTrans.x = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDAROFF));
    trobot->m_localTrans.y = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBROFF));
    trobot->m_localTrans.z = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCROFF));
    trobot->m_localTrans.v = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDROFF));
    trobot->m_localTrans.w = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDEROFF));

    trobot->m_jointCalib.a = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDACOFF));
    trobot->m_jointCalib.b = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDBCOFF));
    trobot->m_jointCalib.c = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDCCOFF));
    trobot->m_jointCalib.d = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDDCOFF));
    trobot->m_jointCalib.e = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITSYSPARAM_CMDECOFF));

    SaveCalibrationParam(&rs_param);
  }
  return TRUE;
}


BX_BOOL formTools_cmdDebug_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formSetDebug[0], formSetDebugProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formStd_cmdProgram_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgram[0], formProgramProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formStd_cmdCW_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formCW[0], formCWProc);
  languagechange=DoModal(hBx);
  return TRUE;
}

BX_BOOL formEditBoxPattern_Click(HBOX hBox)
{
  HBOX hBx;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formEditBoxPattern[0], formEditBoxPatternProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formTools_cmdCalTcp_Click(HBOX hBox)
{
  HBOX hBx;

  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formEditTcp[0], formEditTcpProc);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDAROFF), trobot->m_tcp[caseGripper].x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDBROFF), trobot->m_tcp[caseGripper].y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDCROFF), trobot->m_tcp[caseGripper].z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDDROFF), trobot->m_tcp[caseGripper].v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDEROFF), trobot->m_tcp[caseGripper].w);

  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDACOFF), trobot->m_tcp[bagGripper].x);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDBCOFF), trobot->m_tcp[bagGripper].y);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDCCOFF), trobot->m_tcp[bagGripper].z);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDDCOFF), trobot->m_tcp[bagGripper].v);
  BxSetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDECOFF), trobot->m_tcp[bagGripper].w);

  if(DoModal(hBx)==IDOK)
  {

    trobot->m_tcp[caseGripper].x = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDAROFF));
    trobot->m_tcp[caseGripper].y = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDBROFF));
    trobot->m_tcp[caseGripper].z = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDCROFF));
    trobot->m_tcp[caseGripper].v = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDDROFF));
    trobot->m_tcp[caseGripper].w = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDEROFF));

    trobot->m_tcp[bagGripper].x = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDACOFF));
    trobot->m_tcp[bagGripper].y = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDBCOFF));
    trobot->m_tcp[bagGripper].z = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDCCOFF));
    trobot->m_tcp[bagGripper].v = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDDCOFF));
    trobot->m_tcp[bagGripper].w = BxGetFloatValue(BxGetDlgItem(hBx, FORMEDITTCP_CMDECOFF));

    SaveCalibrationParam(&rs_param);
  }
  return TRUE;
}
BX_BOOL formTools_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

BX_BOOL formStd_RebootKassePakker_Click(HBOX hBox)
{
  setMachineState("KassePakkerBottom","ST_STARTDUMP");
  setMachineState("KassePakkerTop","ST_STARTDUMP");
  return TRUE;
}

BX_BOOL formStd_PalleUd_Click(HBOX hBox)
{  
	if (userpalletout != NULL)
	{
		*userpalletout = 1;
	}
	else
	{	
		initCounter("cBItems","wBItems");
	}
  formStdRun_cmdRun_Click(hBox);
  return TRUE;
}

BX_BOOL formStd_PalleUdA_Click(HBOX hBox)
{  
	if (userPalletAOut != NULL)
	{
		*userPalletAOut = 1;
	}
	else
	{	
		initCounter("cAItems","wAItems");
	}
  formStdRun_cmdRun_Click(hBox);
  return TRUE;
}

BX_BOOL formStd_PalleUdB_Click(HBOX hBox)
{  
	if (userPalletBOut != NULL)
	{
		*userPalletBOut = 1;
	}
	else
	{	
		initCounter("cAItems","wAItems");
	}
  formStdRun_cmdRun_Click(hBox);
  return TRUE;
}

BX_BOOL formStd_ReversePalletA_Click(HBOX hBox)
{
	if (reversebutton1 != NULL)
	{
		*reversebutton1 = 1;
		while (*reversebutton1!=0) usleep(500000);
	}
  return TRUE;
}

BX_BOOL formStd_ReversePalletB_Click(HBOX hBox)
{
	if (reversebutton2 != NULL)
	{
		*reversebutton2 = 1;
		while (*reversebutton2!=0) usleep(500000);
	}
  return TRUE;
}

BX_BOOL formStd_PalleUdStabler_Click(HBOX hBox)
{  
	if (userPalletStackerOut != NULL)
	{
		*userPalletStackerOut = 1;
	}
  return TRUE;
}

BX_BOOL formStd_RestartPallestabler_Click(HBOX hBox)
{  
	if (restartPallestabler != NULL)
	{
		*restartPallestabler = 1;
	}
  return TRUE;
}

BX_BOOL formStd_RestartPallemagasin_Click(HBOX hBox)
{  
	if (restartPallemagasin != NULL)
	{
		*restartPallemagasin = 1;
	}
  return TRUE;
}

BX_BOOL formStd_RestartShuttle_Click(HBOX hBox)
{  
	if (restartShuttle != NULL)
	{
		*restartShuttle = 1;
	}
  return TRUE;
}

BX_BOOL formStd_userClearRoboError_Click(HBOX hBox)
{  
	if (userClearRoboError != NULL)
	{
		*userClearRoboError = 1;
	}
  return TRUE;
}

BX_BOOL formStd_scissorSecureReset_Click(HBOX hBox)
{
  tmpnStateMachine *stm;
  int i,j,k;
  int stateidx;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    stm = &tworkcell->statemachines.statemachine[i];
    for(j=0;j<stm->numoutput;j++)
    {
      if (stm->output[j].iotype==OUTPUT)
      {
        if(strcmp(stm->output[j].name, "scissorSecureReset")==0)
        {
          //force stm to halt
          //printf("Halting %d\n",i);
          stateidx=getStateIdx(i,"ST_HALT");
          if (stateidx>=0)
            setState(i, stateidx);
          
          //yv1,yv2,pump
          for(k=0;k<stm->numoutput;k++)
          {
            if (stm->output[k].iotype==OUTPUT)
            {
              if(strcmp(stm->output[k].name, "pump")==0)
                setConnectValueInt(stm->output[k].connect,0);
              if(strcmp(stm->output[k].name, "yv1")==0)
                setConnectValueInt(stm->output[k].connect,1);
              if(strcmp(stm->output[k].name, "yv2")==0)
                setConnectValueInt(stm->output[k].connect,1);
            }
          }

          //wait
          usleep(1000000);

          //set reset output
          setConnectValueInt(stm->output[j].connect,1);
          
          //wait
          usleep(500000);

          //unset reset output
          setConnectValueInt(stm->output[j].connect,0);

          //force stm to idle
          //printf("Idling %d\n",i);
          stateidx=getStateIdx(i,"ST_IDLE");
          if (stateidx>=0)
            setState(i, stateidx);
        }
      }
    }
  }
  return TRUE;
}

BX_BOOL formStd_userSetcBItem_Click(HBOX hBox)
{  
	if (userSetcBItem != NULL)
	{
    BxVirtNumBox_SetValue(0);
    //BxVirtNumBox_SetFloatLimits(1.0, 100.0);
    if(VirtNumKeyBox( hBox ) == IDOK)
    {
      if(testState(wstm,statew_idle) || testState(wstm,statew_paused))
      {
        *userSetcBItem = (int) BxVirtNumBox_GetValue();
        *cbitem = *userSetcBItem;
        if(itemCounter!=NULL)
          *itemCounter = *userSetcBItem; 
      }
    }
	}
  return TRUE;
}

BX_BOOL formStd_cAItems_Click(HBOX hBox)
{
 char str[256];

 if(testState(wstm,statew_idle)
		||testState(wstm,statew_error))
 {
	 if (rs_param.roboStacker < 2)
	 {
		 BxVirtNumBox_SetValue(atoi(getCounterValue("cAItems")));
		 if(VirtNumKeyBox( hBox ) == IDOK)
		 {
			 sprintf(str,"%d",(int)BxVirtNumBox_GetValue());
			 initCounter("cAItems",str);
		 }
	 }
	 else if (caitem != NULL)
	 {
		 BxVirtNumBox_SetValue(*caitem);
		 if(VirtNumKeyBox( hBox ) == IDOK)
		 {
			 *caitem = (int)BxVirtNumBox_GetValue();
		 }
	 }
 }
 return TRUE;
}

BX_BOOL formStd_cBItems_Click(HBOX hBox)
{
  char str[256];
	
	if(testState(wstm,statew_idle)
		 ||testState(wstm,statew_error))
	{
		if (rs_param.roboStacker < 2)
		{
			BxVirtNumBox_SetValue(atoi(getCounterValue("cBItems")));
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				sprintf(str,"%d",(int)BxVirtNumBox_GetValue());
				initCounter("cBItems",str);
			}
		}
		else
		{
			BxVirtNumBox_SetValue(*cbitem);
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				*cbitem = (int)BxVirtNumBox_GetValue();
			}
		}
	}
  return TRUE;
}

BX_BOOL formTools_cmdDistIO_Click(HBOX hBox)
{
  HBOX hBx;
  //dioIndex=0;
  hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formDistIO[0], formDistIOProc);
  DoModal(hBx);
  return TRUE;
}

BX_BOOL formStdRun_cmdMenu_Click(HBOX hBox)
{
	extern BxIcon *icon1;
	extern BxIcon *icon2;
	//extern BxIcon *icon3;
	//extern BxIcon *icon4;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  HBOX hBx, ToolBx, ToolJogBx, hOptions, hCalib, hInfo, hSetZero,hPalletOut,hReverse, hSetHome;

  hBx = BxMenu_Create(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU), &pBxMainMenu);
	if ((testState(robotstm,staterobot_supervisor)&&accesslevel<=MANAGERLEVEL)
      || (!testState(emergstm,stateemerg_poweron)&&accesslevel<OPERATORLEVEL)
      || ((!(testState(wstm,statew_halt)
             ||testState(wstm,statew_idle)
             ||testState(wstm,statew_paused)))&&accesslevel<=OPERATORLEVEL)
      )
	{	
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12, "Login"), MENU, formTools_cmdSupervisor_Click, TRUE,icon1);
    if(demo == 1)
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
		DoMenu(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU));
		return TRUE;
	}
  if(rs_param.checkWeigher>0)
  {
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 20,"checkWeigher"), MENU, formStd_cmdCW_Click, TRUE, NULL);
  }
	if (rs_param.workcellid==312)
	{
		hPalletOut = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 2,"Send out pallet"), SUB, NULL, TRUE, NULL);
		BxMenu_Add(hPalletOut ,"A", MENU, formStd_PalleUdA_Click, TRUE, NULL);
		BxMenu_Add(hPalletOut ,"B", MENU, formStd_PalleUdB_Click, TRUE, NULL);
	}
	else
	{
		BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 2,"Send out pallet"), MENU, formStd_PalleUd_Click, TRUE, NULL);
		if(pallestablerstm != -1)
    {
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 265,"PS: Pallet out"), MENU, formStd_PalleUdStabler_Click, TRUE, NULL);
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 266,"Restart Palletstacker"), MENU, formStd_RestartPallestabler_Click, TRUE, NULL);
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 302,"Restart Palletmagasin"), MENU, formStd_RestartPallemagasin_Click, TRUE, NULL);
    }
    if(shuttlestm != -1)
    {
      BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 303,"Restart Shuttle"), MENU, formStd_RestartShuttle_Click, TRUE, NULL);
    }
  }
	if (reversebutton1!=NULL)
	{
		if (reversebutton2!=NULL)
		{
			hReverse = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 268,"Reverse pallet"), SUB, NULL, TRUE, NULL);
			BxMenu_Add(hReverse ,"A", MENU, formStd_ReversePalletA_Click, TRUE, NULL);
			BxMenu_Add(hReverse ,"B", MENU, formStd_ReversePalletB_Click, TRUE, NULL);
		}
		else
		{
			BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 268,"Reverse pallet"), MENU, formStd_ReversePalletA_Click, TRUE, NULL);
		}
	}
	
	BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 1,"Program"), MENU, formStd_cmdProgram_Click, TRUE, icon2);
	BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 12,"Login"), MENU, formTools_cmdSupervisor_Click, TRUE, icon1);
	
  if(accesslevel>OPERATORLEVEL)
  {
    hOptions = BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 18,"Setup"), SUB, NULL, TRUE, NULL);//icon3);
		ToolBx = BxMenu_Add(hBx , getLanguageLineFromIdx(langptr, 19, "Tools"), SUB, NULL, TRUE, NULL);//icon4);
    ToolJogBx = BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 21, "Jog axis"), SUB, NULL, TRUE, NULL);
    BxMenu_Add(ToolJogBx ,getLanguageLineFromIdx(langptr, 293, "Jog Tool"), MENU, formTools_cmdJogTool_Click, TRUE, NULL);
    BxMenu_Add(ToolJogBx ,getLanguageLineFromIdx(langptr, 22, "Jog I.K."), MENU, formTools_cmdJogIk_Click, TRUE, NULL);
    BxMenu_Add(ToolJogBx ,getLanguageLineFromIdx(langptr, 31, "Jog Manual"), MENU, formTools_cmdJogAxis_Click, TRUE, NULL);

    if(accesslevel>=SERVICELEVEL)
    {
      if(gotScissorSecureReset)
        BxMenu_Add(ToolBx , getLanguageLineFromIdx(langptr, 300, "Reset Scissor Secure"), MENU, formStd_scissorSecureReset_Click, TRUE, NULL);
      if(userClearRoboError!=NULL)
        BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 267,"ClearRobotError"), MENU, formStd_userClearRoboError_Click, TRUE, NULL);
      if(userSetcBItem != NULL)
        BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 292,"Set number of items"), MENU, formStd_userSetcBItem_Click, TRUE, NULL);
      if(rs_param.workcellid == 319 ||
         rs_param.workcellid == 320 ||
         rs_param.workcellid == 321)
        BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 301,"Manual"), MENU, formStd_cmdManual_Click, TRUE, NULL);
    }

    BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 23, "Robot I/O"), MENU, formTools_cmdInOut_Click, TRUE, NULL);
		
    if(tworkcell->dios.maxidx>0 || tworkcell->loadcells.maxidx>0 || tworkcell->comsks.maxidx>0 || tworkcell->macs.maxidx>0)
    {
      BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 24, "Dist. I/O"), MENU, formTools_cmdDistIO_Click, TRUE, NULL);
    }
    BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 25, "STM control"), MENU, formTools_cmdSTMCtrl_Click, TRUE, NULL);
		
    hInfo = BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 26, "Info"), SUB, NULL, TRUE, NULL);
    BxMenu_Add(hInfo ,getLanguageLineFromIdx(langptr, 28, "Log"), MENU, formTools_cmdLog_Click, TRUE, NULL);
    if(accesslevel>SERVICELEVEL)
      BxMenu_Add(ToolBx ,getLanguageLineFromIdx(langptr, 30, "Axis parameter"), MENU, formTools_cmdAxis_Click, TRUE, NULL);
      BxMenu_Add(hInfo ,getLanguageLineFromIdx(langptr, 27, "Stats"), MENU, formTools_cmdStatus_Click, TRUE, NULL);    
      BxMenu_Add(hInfo ,getLanguageLineFromIdx(langptr, 29, "Debug"), MENU, formTools_cmdDebug_Click, TRUE, NULL);    
      BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 0, "System"), MENU, formTools_cmdSystem_Click, TRUE, NULL);
    BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 250, "Language"), MENU, formTools_cmdLanguage_Click, TRUE, NULL);
    if(accesslevel>SERVICELEVEL){
      hCalib = BxMenu_Add(hOptions ,getLanguageLineFromIdx(langptr, 32, "Calibrate"), SUB, NULL, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 33, "Adjust frames"), MENU, formTools_cmdFixPoints_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 257, "Patterns"), MENU, formEditBoxPattern_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 34, "Calibrate TCP"), MENU, formTools_cmdCalTcp_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 35, "Setup system parameters"), MENU, formTools_cmdSetupSysParam_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 36, "AutoHome"), MENU, formTools_cmdAutoHome_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 37, "ZeroTool"), MENU, formTools_cmdSetZeroTool_Click, TRUE, NULL);
      BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 38, "Tool90"), MENU, formTools_cmdSetTool90_Click, TRUE, NULL);
    }
    if(accesslevel>=MANAGERLEVEL)
    {
      if(accesslevel==MAXLEVEL)
      {
        hSetHome = BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 39, "Home"), SUB, NULL, TRUE, NULL);
        BxMenu_Add(hSetHome ,"A", MENU, formTools_cmdMoveHomeA_Click, TRUE, NULL);
        BxMenu_Add(hSetHome ,"B", MENU, formTools_cmdMoveHomeB_Click, TRUE, NULL);
        BxMenu_Add(hSetHome ,"C", MENU, formTools_cmdMoveHomeC_Click, TRUE, NULL);
        BxMenu_Add(hSetHome ,"D", MENU, formTools_cmdMoveHomeD_Click, TRUE, NULL);
        BxMenu_Add(hSetHome ,"E", MENU, formTools_cmdMoveHomeE_Click, TRUE, NULL);
        BxMenu_Add(hSetHome ,"F", MENU, formTools_cmdMoveHomeF_Click, TRUE, NULL);
      }
      hSetZero = BxMenu_Add(hCalib ,getLanguageLineFromIdx(langptr, 40, "Zero"), SUB, NULL, TRUE, NULL);
      BxMenu_Add(hSetZero ,"A", MENU, formTools_cmdSetZeroA_Click, TRUE, NULL);
      if(accesslevel==MAXLEVEL)
      {
        BxMenu_Add(hSetZero ,"B", MENU, formTools_cmdSetZeroB_Click, TRUE, NULL);
        BxMenu_Add(hSetZero ,"C", MENU, formTools_cmdSetZeroC_Click, TRUE, NULL);
        BxMenu_Add(hSetZero ,"F", MENU, formTools_cmdSetZeroF_Click, TRUE, NULL);
      }
      BxMenu_Add(hSetZero ,"D", MENU, formTools_cmdSetZeroD_Click, TRUE, NULL);
      BxMenu_Add(hSetZero ,"E", MENU, formTools_cmdSetZeroE_Click, TRUE, NULL);
    }
  }
  if(demo == 1)
    BxMenu_Add(hBx ,getLanguageLineFromIdx(langptr, 54,"Close"), MENU, formDemo_cmdDemoClose_Click, TRUE, NULL);
  DoMenu(BxGetDlgItem(hBox, FORMSTDRUN_CMDMENU));
  return TRUE;
}

