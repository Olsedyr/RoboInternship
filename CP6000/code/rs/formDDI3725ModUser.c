// formDDI3725ModUser.c
#include "Bx.h"
#include "formDDI3725Mod.h"
#include "cmd.h"

extern volatile int dioIndex;
extern volatile int modIndex;
int connectOffset=0;
static char namestr[256]="Name :";

static BX_BOOL refresh(HBOX hBox)
{
  char str[256];
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABTYPE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABMODNAME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT6));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB6));
  
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABTYPE),tworkcell->dios.dio[dioIndex].iotab[modIndex].typeStr);
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABMODNAME),  tworkcell->dios.dio[dioIndex].iotab[modIndex].module_name);
	
  if(connectOffset<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1), TRUE);
    sprintf(str,"%d",connectOffset+1);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB1), str);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT1), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB1), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT1), "");
  }

  if((connectOffset+1)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2), TRUE);
    sprintf(str,"%d",connectOffset+2);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB2), str);
	  BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT2), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB2), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT2), "");
  }

  if((connectOffset+2)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3), TRUE);
    sprintf(str,"%d",connectOffset+3);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB3), str);
	  BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT3), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB3), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT3), "");
  }
  
  if((connectOffset+3)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4), TRUE);
    sprintf(str,"%d",connectOffset+4);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB4), str);
	  BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT4), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB4), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT4), "");
  }
  
  if((connectOffset+4)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5), TRUE);
    sprintf(str,"%d",connectOffset+5);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB5), str);
	  BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT5), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB5), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT5), "");
  }
  
  if((connectOffset+5)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6), TRUE);
    sprintf(str,"%d",connectOffset+6);	
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB6), str);
	  BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT6), tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5].key);
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6),getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5])); 
  }
  else
  {
	  BxEnableBox(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6), FALSE);
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LAB6), "");
    BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_LABCONNECT6), "");
  }
  
  

	return TRUE;
}

BX_BOOL formDDI3725ModUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	sprintf(namestr,"%s :",getLanguageLineFromIdx(langptr, 87, "Name"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_TEXTLABEL2_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_TEXTLABEL2_2_2), namestr);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_CMDNEXT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMDDI3725MOD_CMDNEXT), getLanguageLineFromIdx(langptr, 94, "Next")); 
  refresh(hBox);
	return TRUE;
}

BX_BOOL formDDI3725ModUserUpdate(HBOX hBox)
{
  if(connectOffset<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0]));
  if((connectOffset+1)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1]));
  if((connectOffset+2)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2]));
  if((connectOffset+3)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3]));
  if((connectOffset+4)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4]));
  if((connectOffset+5)<tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx)
    BxSetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6), getConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5]));
 
  return TRUE;
}

BX_BOOL formDDI3725Mod_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}

BX_BOOL formDDI3725Mod_cmdNext_Click(HBOX hBox)
{
  connectOffset+=6;
  if(connectOffset>=tworkcell->dios.dio[dioIndex].iotab[modIndex].maxidx) connectOffset=0;
  refresh(hBox);
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState1_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+0], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE1)) );
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState2_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+1], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE2)) );
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState3_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+2], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE3)) );
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState4_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+3], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE4)) );
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState5_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+4], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE5)) );
  return TRUE;
}

BX_BOOL formDDI3725Mod_chkState6_Click(HBOX hBox)
{
  if(tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5].connectType==OBITDATA)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6)) );
  else if(tworkcell->dios.dio[dioIndex].simulate==1)
    setConnectValueInt(&tworkcell->dios.dio[dioIndex].iotab[modIndex].connect[connectOffset+5], BxGetCheck(BxGetDlgItem(hBox, FORMDDI3725MOD_CHKSTATE6)) );
  return TRUE;
}

