//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCMCode.c
#include "Bx.h"
#include "formCM.h"

BX_VOID formCMInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMCM_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formCMUpdate(HBOX hBox)
{
}

