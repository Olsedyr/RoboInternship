// formProgramUser.c
#include "Bx.h"
#include "rs.h"
#include "formProgram.h"
#include "formProgramCtrl.h"
#include "cmd.h"
#include "stm.h"

static int useprogramstm=-1;
static int numofprogramstates=0;
char programStateMachineName[256]="Program";
extern char mcstm[256];

int prgToIdxMap[50];

volatile int prgIndex;
volatile int prgstateIndex;

BX_BOOL formProgramUserInit(HBOX hBox, BX_LPARAM lParam)
{
 // load all program names into the scroll box from database
  int i;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	

	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_TEXTLABEL2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_TEXTLABEL2_2), getLanguageLineFromIdx(langptr, 78, "Programs"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDCANCEL), getLanguageLineFromIdx(langptr, 4, "Abort"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDOK));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDOK), getLanguageLineFromIdx(langptr, 79, "Choose"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDEDIT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDEDIT), getLanguageLineFromIdx(langptr, 80, "Edit"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDDELETE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDDELETE), getLanguageLineFromIdx(langptr, 81, "Delete prog."));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDNEW));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAM_CMDNEW), getLanguageLineFromIdx(langptr, 82, "Make copy"));

	useprogramstm = getMachineIdx(programStateMachineName);
	if (useprogramstm==-1)
	{
		for (i=0;i<tworkcell->scripts.maxidx;i++)
		{
			BxList_AddString(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), (char*)tworkcell->scripts.item[i].name);
		}
		BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDEDIT), FALSE);
	}
	else
	{
		numofprogramstates=0;
		for (i=0;i<tworkcell->statemachines.statemachine[useprogramstm].numstate;i++)
		{
			char *name;
			name=tworkcell->statemachines.statemachine[useprogramstm].state[i].name;
			if(!strncmp(name,"PROGRAM_",8))
			{
				BxList_AddString(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), name+8);
				prgToIdxMap[numofprogramstates++]=i;
			}
		}
		if(accesslevel>OPERATORLEVEL)
			BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDEDIT), TRUE);
		else
			BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDEDIT), FALSE);
	}
	if(accesslevel>SERVICELEVEL)
		BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDNEW), TRUE);
	else
		BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDNEW), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMPROGRAM_CMDDELETE), FALSE);
  return TRUE;
}

BX_BOOL formProgramUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formProgram_cmdEdit_Click(HBOX hBox)
{
	HBOX hBx;
	BX_INT valnum=-1;
	valnum = BxList_GetSelected(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX));
  if (valnum<0) return TRUE;
	prgIndex = useprogramstm;
	prgstateIndex = prgToIdxMap[valnum];
	hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formProgramCtrl[0], formProgramCtrlProc);
	DoModal(hBx);
	return TRUE;
}

BX_BOOL formProgram_cmdNew_Click(HBOX hBox)
{
	char newname[128];
	char prgnewname[256];
	newname[0]='\0';
  int sel;
  sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX));
  if ((sel >= 0)&&(useprogramstm>=0))
  {
		tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[useprogramstm];
		if(BxVirtualKeyboard( hBox, "", 32)==IDOK)
		{
			strcpy(newname,BxVirtualKeyboard_GetString());
		}
		else 
		{
			return FALSE;
		}		
		if (strlen(newname)>0)
		{
			sprintf(prgnewname,"PROGRAM_%s",newname);
			BxList_AddString(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), prgnewname+8);
			AddProgram(useprogramstm,newname,sel);
			pthread_mutex_lock(&stm->change_mtx);
			tmpnStateMachineLoad(stm->filename, stm, 0);
			tmpnStateLoad(stm->filename, stm, 0);
			SetupSTMLink1(&tworkcell->statemachines.statemachine[useprogramstm]);
			SetupSTMLink2(&tworkcell->statemachines.statemachine[useprogramstm]);
			pthread_cond_broadcast(&stm->change);
			pthread_mutex_unlock(&stm->change_mtx);
			// AddProgram added two states :
			prgToIdxMap[numofprogramstates++]=tworkcell->statemachines.statemachine[useprogramstm].numstate-2;
		}
	}
	return TRUE;
}

BX_BOOL formProgram_cmdDelete_Click(HBOX hBox)
{
	int sel;
	char str[256];
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX));
  if ((sel>=0)&&(useprogramstm>=0))
  {
		tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[useprogramstm];
		sprintf(str,"%s \"%s\"?",getLanguageLineFromIdx(langptr, 120, "Do you want to delete the program"),BxList_GetString(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), sel));
		if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118, "Warning"),0,getLanguageLineFromIdx(langptr, 74, "Ok"),getLanguageLineFromIdx(langptr, 3, "Cancel"))!=IDOK) return FALSE;
		BxList_DeleteString(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), sel);
		pthread_mutex_lock(&stm->change_mtx);
		// delete in filesys code and code structs
		//DeleteProgram(useprogram,sel);
		tmpnStateMachineLoad(stm->filename, stm, 0);
		SetupSTMLink1(&tworkcell->statemachines.statemachine[useprogramstm]);
		SetupSTMLink2(&tworkcell->statemachines.statemachine[useprogramstm]);
		pthread_cond_broadcast(&stm->change);
		pthread_mutex_unlock(&stm->change_mtx);
		numofprogramstates--;
	}
	return TRUE;
}

BX_BOOL formProgram_cmdOk_Click(HBOX hBox)
{
  int sel;
  sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX));
  if (sel >= 0)
  {
    if (useprogramstm==-1)
		{
      //this is only used by mc.c 'oldstyle script execution'
      if(rs_param.scriptExec==1)
        setMachineState(mcstm,"ST_STOPPING");
			strcpy(rs_param.script, (const char*)tworkcell->scripts.item[sel].name);
		}
		else 
    {
      if(rs_param.scriptExec==1)
      {
        setMachineState(mcstm,"ST_STOPPING");
			  strcpy(rs_param.script, (const char*)tworkcell->scripts.item[sel].name);
      }
      
      tmpnStateMachineValue *value = getMachineValue(useprogramstm,"programidx");
      value->data = sel;
      if(value->type == CONSTANT)//remember choosen program after reset
        SaveConstVal(programStateMachineName,"programidx",value);
			setMachineState(programStateMachineName,"ST_RESET");
		}
    BxEndDialog(hBox, IDOK);
    return FALSE;
  }
  return TRUE;
}

BX_BOOL formProgram_listBox_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formProgram_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return FALSE;
}

