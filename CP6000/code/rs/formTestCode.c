//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTestCode.c
#include "Bx.h"
#include "formTest.h"

BX_VOID formTestInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMTEST_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formTestUpdate(HBOX hBox)
{
}

