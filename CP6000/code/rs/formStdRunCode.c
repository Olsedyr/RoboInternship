//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formStdRunCode.c
#include "Bx.h"
#include "formStdRun.h"

BX_VOID formStdRunInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMSTDRUN_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formStdRunUpdate(HBOX hBox)
{
}

