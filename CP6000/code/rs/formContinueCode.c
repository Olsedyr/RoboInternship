//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formContinueCode.c
#include "Bx.h"
#include "formContinue.h"

BX_VOID formContinueInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMCONTINUE_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
  //ICON ID = 16
  BxSendMessage(BxGetDlgItem(hBox, FORMCONTINUE_TEXTLABEL1_2), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(16, "data/robostacker.bxr"), 0);
}

BX_VOID formContinueUpdate(HBOX hBox)
{
}

