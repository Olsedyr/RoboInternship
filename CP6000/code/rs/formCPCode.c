//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCPCode.c
#include "Bx.h"
#include "formCP.h"

BX_VOID formCPInit(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORMCP_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID formCPUpdate(HBOX hBox)
{
}

