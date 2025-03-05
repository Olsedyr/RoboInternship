//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDemoCode.c
#include "Bx.h"
#include "formDemo.h"

BX_VOID formDemoInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMDEMO_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formDemoUpdate(HBOX hBox)
{
}

