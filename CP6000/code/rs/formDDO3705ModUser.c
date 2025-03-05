// formDDO3705ModUser.c
#include "Bx.h"
#include "formDDO3705Mod.h"
#include "cmd.h"

extern volatile int modIndex;
static int connectOffset=0;

char namestr[256]="Name :";

static BX_BOOL refresh(HBOX hBox)
{
  char str[256];
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABTYPE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABMODNAME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT6));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB6));
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	sprintf(namestr,"%s :",getLanguageLineFromIdx(langptr, 87, "Name"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_TEXTLABEL2_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDOMOD_TEXTLABEL2_2_2), namestr);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_CMDNEXT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_CMDNEXT), getLanguageLineFromIdx(langptr, 94, "Next")); 
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABTYPE),tworkcell->dios.dio[0].iotab[modIndex].typeStr);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABMODNAME), tworkcell->dios.dio[0].iotab[modIndex].module_name);

  sprintf(str,"%d",connectOffset*6+0);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB1), str);
  sprintf(str,"%d",connectOffset*6+1);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB2), str);
  sprintf(str,"%d",connectOffset*6+2);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB3), str);
  sprintf(str,"%d",connectOffset*6+3);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB4), str);
  sprintf(str,"%d",connectOffset*6+4);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB5), str);
  sprintf(str,"%d",connectOffset*6+5);	
  BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LAB6), str);
  
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT1), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+0].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT2), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+1].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT3), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+2].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT4), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+3].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT5), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+4].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDO3705MOD_LABCONNECT6), tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+5].key);
  
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+0]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+1]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+2]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+3]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+4]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+5]));
 
  return TRUE;
}

BX_BOOL formDDO3705ModUserInit(HBOX hBox,BX_LPARAM lParam)
{
  refresh(hBox); 
  return TRUE;
}

BX_BOOL formDDO3705ModUserUpdate(HBOX hBox)
{
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+0]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+1]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+2]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+3]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+4]));
  BxSetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+5]));
 
 return TRUE;
}

BX_BOOL formDDO3705Mod_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}

BX_BOOL formDDO3705Mod_cmdNext_Click(HBOX hBox)
{
  connectOffset+=6;
  if(connectOffset>=tworkcell->dios.dio[0].iotab[modIndex].maxidx) connectOffset=0;
  refresh(hBox);
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState1_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+0].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+0], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE1)) );
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState2_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+1].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+1], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE2)) );
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState3_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+2].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+2], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE3)) );
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState4_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+3].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+3], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE4)) );
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState5_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+4].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+4], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE5)) );
  return TRUE;
}

BX_BOOL formDDO3705Mod_chkState6_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+5].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[0].iotab[modIndex].connect[connectOffset*6+5], BxGetCheck(BxGetDlgItem(hBox, FORMDDO3705MOD_CHKSTATE6)) );
  return TRUE;
}

