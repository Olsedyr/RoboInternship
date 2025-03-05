//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMsgBoxCode.c
#include "Bx.h"
#include "formMsgBox.h"

BX_VOID formMsgBoxInit(HBOX hBox)
{
  //ICON ID = 0
  BxSendMessage(BxGetDlgItem(hBox, FORMMSGBOX_TEXTLABEL2), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(0, "data/bx.bxr"), 0);
}

BX_VOID formMsgBoxUpdate(HBOX hBox)
{
}

