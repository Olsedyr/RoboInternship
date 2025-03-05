//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formBxIconsCode.c
#include "Bx.h"
#include "formBxIcons.h"

BX_VOID formBxIconsInit(HBOX hBox)
{
  //PIXMAP ID = 1
  BxSendMessage(BxGetDlgItem(hBox, FORMBXICONS_LABNO), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(1, "data/bx.bxr"), 0);
  //PIXMAP ID = 2
  BxSendMessage(BxGetDlgItem(hBox, FORMBXICONS_LABYES), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(2, "data/bx.bxr"), 0);
  //ICON ID = 0
  BxSendMessage(BxGetDlgItem(hBox, FORMBXICONS_LABQUESTION), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(0, "data/bx.bxr"), 0);
}

BX_VOID formBxIconsUpdate(HBOX hBox)
{
}

