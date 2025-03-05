//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form900Code.c
#include "Bx.h"
#include "form900.h"

BX_VOID form900Init(HBOX hBox)
{
  //PIXMAP ID = 15
  BxSendMessage(BxGetDlgItem(hBox, FORM900_TEXTLABEL1), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(15, "data/robostacker.bxr"), 0);
}

BX_VOID form900Update(HBOX hBox)
{
}

