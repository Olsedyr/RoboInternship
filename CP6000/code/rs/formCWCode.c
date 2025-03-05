//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCWCode.c
#include "Bx.h"
#include "formCW.h"

BX_VOID formCWInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMCW_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formCWUpdate(HBOX hBox)
{
}

