//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditPPPUser.c
#include "Bx.h"
#include "cmd.h"
#include "formEditPPP.h"

BX_BOOL formEditPPPUserInit(HBOX hBox,BX_LPARAM lParam)
{
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDRETURN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDRETURN), getLanguageLineFromIdx(langptr, 74, "Ok"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDCANCEL), getLanguageLineFromIdx(langptr, 3, "Cancel"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITPPP_GROUPBOX1));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITPPP_GROUPBOX1), getLanguageLineFromIdx(langptr, 114, "Frame"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITPPP_TEXTLABELNAME));
  //BxSetStringValue(BxGetDlgItem(hBox, FORMEDITPPP_TEXTLABELNAME), );
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPPP));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPACC));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPSPEED));
  return TRUE;
}

BX_BOOL formEditPPPUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formEditPPP_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formEditPPP_cmdReturn_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formEditPPP_cmdPPP_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(BxGetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPPP)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPPP), BxVirtNumBox_GetValue());
  }

  /*tmpnCPPatternItem *item = &editcppattern->items[selectedLayer];
  BxVirtNumBox_SetValue(item->ppps[listidx]);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    int newppp = BxVirtNumBox_GetValue();
    if(newppp > 0){
      item->ppps[listidx] = newppp;
      formEditCPPattern_UpdateEditables(hBox);
    }*/
  return TRUE;
}

BX_BOOL formEditPPP_cmdPACC_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(BxGetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPACC)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPACC), BxVirtNumBox_GetValue());
  }
  return TRUE;
}

BX_BOOL formEditPPP_cmdPSPEED_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(BxGetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPSPEED)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetIntValue(BxGetDlgItem(hBox, FORMEDITPPP_CMDPSPEED), BxVirtNumBox_GetValue());
  }
  return TRUE;
}

