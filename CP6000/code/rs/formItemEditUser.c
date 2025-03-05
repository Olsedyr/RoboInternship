//Copyright (C) 2008 by MPN A/S - Guided by vision(R)
// Lukas
// formItemEditUser.c
#include "Bx.h"
#include "formItemEdit.h"
#include "rs.h"
#include "cmd.h"

extern char *itemName;

BX_BOOL formItemEditUserInit(HBOX hBox,BX_LPARAM lParam)
{
 	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  BxAssignStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_GROUPBOX1));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_GROUPBOX1), getLanguageLineFromIdx(langptr, 260, "Item"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_TEXTLABELNAME));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_TEXTLABELNAME), itemName);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDRETURN));
	BxSetStringValue(BxGetDlgItem(hBox,FORMITEMEDIT_CMDRETURN), getLanguageLineFromIdx(langptr, 74, "Ok"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDCANCEL), getLanguageLineFromIdx(langptr, 3, "Cancel"));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDX));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDY));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDZ));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDSY));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGY));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDMY));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGX));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDWEIGHT));
  return TRUE;
}

BX_BOOL formItemEditUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formItemEdit_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formItemEdit_cmdReturn_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formItemEdit_cmdmy_Click(HBOX hBox)
{
   BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDMY)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDMY), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmdgx_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGX)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGX), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmdweight_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDWEIGHT)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDWEIGHT), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmdgy_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGY)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDGY), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmdsy_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDSY)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDSY), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmddz_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDZ)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDZ), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmddy_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDY)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDY), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formItemEdit_cmddx_Click(HBOX hBox)
{
     BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDX)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMITEMEDIT_CMDDX), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

