/****************************************************************************
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
****************************************************************************/
#include "Bx.h"
#include "formEPIMod.h"

#include "cmd.h"

extern volatile int dioIndex;
extern volatile int modIndex;
static char namestr[256]="Name :";
static char *readystr=NULL;
static char *notreadystr=NULL;
static char *trippedstr=NULL;

BX_BOOL formEPIModUserInit(HBOX hBox,BX_LPARAM lParam)
{
  stbstruct *stb;

	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	sprintf(namestr,"%s :",getLanguageLineFromIdx(langptr, 87, "Name"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2), namestr);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2_3));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2_3), getLanguageLineFromIdx(langptr, 95, "Fwd."));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2_3_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_TEXTLABEL2_2_2_3_2), getLanguageLineFromIdx(langptr, 96, "Rev."));
	readystr=getLanguageLineFromIdx(langptr, 97, "Ready");
	notreadystr=getLanguageLineFromIdx(langptr, 98, "Not ready");
	trippedstr=getLanguageLineFromIdx(langptr, 99, "Tripped");
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABTYPE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABMODNAME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4));
  
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABTYPE), "EPI2145");
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABMODNAME), stb->module_name);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT1), stb->connect[0].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT2), stb->connect[2].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT3), stb->connect[4].key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABCONNECT4), stb->connect[6].key);
	

  if(getConnectValue(getConnectPtr(stb,"Ready1")))        
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped1")))	
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), trippedstr);
  else 																										
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready2")))        
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped2")))	
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), trippedstr);
  else 																										
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready3")))        
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped3")))	
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), trippedstr);
  else 																										
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready4")))        
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped4")))	
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), trippedstr);
  else 																										
		BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), notreadystr);
		
	BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1), stb->idata[4] & 0x0001 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2), stb->idata[4]  & 0x0005 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3), stb->idata[4]  & 0x0010 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4), stb->idata[4]  & 0x0040 ? TRUE : FALSE);
	
	BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1_2), stb->idata[4] & 0x0002 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2_2), stb->idata[4]  & 0x0008 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3_2), stb->idata[4]  & 0x0020 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4_2), stb->idata[4]  & 0x0080 ? TRUE : FALSE);
	
	return TRUE;
}

BX_BOOL formEPIModUserUpdate(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  
  if(getConnectValue(getConnectPtr(stb,"Ready1")))        
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped1")))	
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), trippedstr);
  else 																										
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE1), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready2")))        
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped2")))	
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), trippedstr);
  else 																										
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE2), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready3")))        
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped3")))	
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), trippedstr);
  else 																										
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE3), notreadystr);
  if(getConnectValue(getConnectPtr(stb,"Ready4")))        
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), readystr);
	else if(getConnectValue(getConnectPtr(stb,"Tripped4")))	
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), trippedstr);
  else 																										
    BxSetStringValue(BxGetDlgItem(hBox, FORMEPIMOD_LABSTATE4), notreadystr);
	
	BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1),   (stb->idata[4]) & 0x0001 ? TRUE : FALSE);
	BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1_2), (stb->idata[4]) & 0x0002 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2),   (stb->idata[4]) & 0x0004 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2_2), (stb->idata[4]) & 0x0008 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3),   (stb->idata[4]) & 0x0010 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3_2), (stb->idata[4]) & 0x0020 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4),   (stb->idata[4]) & 0x0040 ? TRUE : FALSE);
  BxSetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4_2), (stb->idata[4]) & 0x0080 ? TRUE : FALSE);
	
  return TRUE;
}

BX_BOOL formEPIMod_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}

BX_BOOL formEPIMod_chkState1_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1))==TRUE)
    stb->odata[0] |= 0x01;
	else
    stb->odata[0] &= 0xFE;
  return TRUE;
}
BX_BOOL formEPIMod_chkState1_2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE1_2))==TRUE)
    stb->odata[0] |= 0x02;
	else
    stb->odata[0] &= 0xFD;
  return TRUE;
}
BX_BOOL formEPIMod_chkState2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];

  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2))==TRUE)
    stb->odata[0] |= 0x04;
	else
    stb->odata[0] &= 0xFB;
  return TRUE;
}
BX_BOOL formEPIMod_chkState2_2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE2_2))==TRUE)
    stb->odata[0] |= 0x08;
	else
    stb->odata[0] &= 0xF7;
  return TRUE;
}


BX_BOOL formEPIMod_chkState3_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3))==TRUE)
    stb->odata[0] |= 0x10;
	else
    stb->odata[0] &= 0xEF;
  return TRUE;
}
BX_BOOL formEPIMod_chkState3_2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE3_2))==TRUE)
    stb->odata[0] |= 0x20;
	else
    stb->odata[0] &= 0xDF;
  return TRUE;
}


BX_BOOL formEPIMod_chkState4_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4))==TRUE)
    stb->odata[0] |= 0x40;
	else
    stb->odata[0] &= 0xBF;
  return TRUE;
}

BX_BOOL formEPIMod_chkState4_2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  if(BxGetCheck(BxGetDlgItem(hBox, FORMEPIMOD_CHKSTATE4_2))==TRUE)
    stb->odata[0] |= 0x80;
	else
    stb->odata[0] &= 0x7F;
  return TRUE;
}


BX_VOID formEPIMod_SetModule(BX_INT modNum)
{
  modIndex = modNum;
}
