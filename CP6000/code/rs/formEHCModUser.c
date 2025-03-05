/****************************************************************************
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
****************************************************************************/
#include "Bx.h"
#include "formEHCMod.h"
#include "cmd.h"

extern volatile int dioIndex;
extern volatile int modIndex;
static char namestr[256]="Name :";

BX_BOOL formEHCModUserInit(HBOX hBox,BX_LPARAM lParam)
{

	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	sprintf(namestr,"%s :",getLanguageLineFromIdx(langptr, 87, "Name"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_TEXTLABEL2_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_TEXTLABEL2_2_2), namestr);

  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABTYPE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABMODNAME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD6));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD5));

  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD1));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD2));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD3));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD4));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD5));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD6));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD1));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD2));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD3));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD4));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD5));
	
  BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABTYPE), "EHC3020");
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABMODNAME),  stb->module_name);

	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD1),getConnectPtr(stb,"InWord1")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD2),getConnectPtr(stb,"InWord2")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD3),getConnectPtr(stb,"InWord3")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD4),getConnectPtr(stb,"InWord4")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD5),getConnectPtr(stb,"InWord5")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABIWORD6),getConnectPtr(stb,"InWord6")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD1),getConnectPtr(stb,"OutWord1")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD2),getConnectPtr(stb,"OutWord2")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD3),getConnectPtr(stb,"OutWord3")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD4),getConnectPtr(stb,"OutWord4")->key);
	BxSetStringValue(BxGetDlgItem(hBox, FORMEHCMOD_LABOWORD5),getConnectPtr(stb,"OutWord5")->key);

  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD1),getConnectValue(getConnectPtr(stb,"InWord1")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD2),getConnectValue(getConnectPtr(stb,"InWord2")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD3),getConnectValue(getConnectPtr(stb,"InWord3")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD4),getConnectValue(getConnectPtr(stb,"InWord4")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD5),getConnectValue(getConnectPtr(stb,"InWord5")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD6),getConnectValue(getConnectPtr(stb,"InWord6")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD1),getConnectValue(getConnectPtr(stb,"OutWord1")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD2),getConnectValue(getConnectPtr(stb,"OutWord2")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD3),getConnectValue(getConnectPtr(stb,"OutWord3")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD4),getConnectValue(getConnectPtr(stb,"OutWord4")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD5),getConnectValue(getConnectPtr(stb,"OutWord5")));

 return TRUE;
}

BX_BOOL formEHCModUserUpdate(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];

  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD1),getConnectValue(getConnectPtr(stb,"InWord1")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD2),getConnectValue(getConnectPtr(stb,"InWord2")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD3),getConnectValue(getConnectPtr(stb,"InWord3")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD4),getConnectValue(getConnectPtr(stb,"InWord4")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD5),getConnectValue(getConnectPtr(stb,"InWord5")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_IWORD6),getConnectValue(getConnectPtr(stb,"InWord6")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD1),getConnectValue(getConnectPtr(stb,"OutWord1")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD2),getConnectValue(getConnectPtr(stb,"OutWord2")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD3),getConnectValue(getConnectPtr(stb,"OutWord3")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD4),getConnectValue(getConnectPtr(stb,"OutWord4")));
  BxSetIntValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD5),getConnectValue(getConnectPtr(stb,"OutWord5")));
  
  return TRUE;
}

BX_BOOL formEHCMod_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}

BX_BOOL formEHCMod_OWord1_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD1)));
  BxVirtNumBox_SetFloatLimits(0, 65535.0);

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD1), BxVirtNumBox_GetFloatValue());
    setConnectValueInt(getConnectPtr(stb,"OutWord1"),BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEHCMod_OWord2_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD2)));
  BxVirtNumBox_SetFloatLimits(0, 65535.0);

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD2), BxVirtNumBox_GetFloatValue());
    setConnectValueInt(getConnectPtr(stb,"OutWord2"),BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEHCMod_OWord3_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD3)));
  BxVirtNumBox_SetFloatLimits(0, 65535.0);

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD3), BxVirtNumBox_GetFloatValue());
    setConnectValueInt(getConnectPtr(stb,"OutWord3"),BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEHCMod_OWord4_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD4)));
  BxVirtNumBox_SetFloatLimits(0, 65535.0);

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD4), BxVirtNumBox_GetFloatValue());
    setConnectValueInt(getConnectPtr(stb,"OutWord4"),BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEHCMod_OWord5_Click(HBOX hBox)
{
  stbstruct *stb;
  stb=&tworkcell->dios.dio[dioIndex].iotab[modIndex];
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD5)));
  BxVirtNumBox_SetFloatLimits(0, 65535.0);

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEHCMOD_OWORD5), BxVirtNumBox_GetFloatValue());
    setConnectValueInt(getConnectPtr(stb,"OutWord5"),BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

