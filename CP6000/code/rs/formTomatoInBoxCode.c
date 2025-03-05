//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTomatoInBoxCode.c
#include "Bx.h"
#include "formTomatoInBox.h"

BX_VOID formTomatoInBoxInit(HBOX hBox)
{
  //PIXMAP ID = 14
  BxSendMessage(BxGetDlgItem(hBox, FORMTOMATOINBOX_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(14, "data/robostacker.bxr"), 0);
}

BX_VOID formTomatoInBoxUpdate(HBOX hBox)
{
}

