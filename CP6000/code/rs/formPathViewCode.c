//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathViewCode.c
#include "Bx.h"
#include "formPathView.h"

BXSCROLLBARSTRUCT formPathView_scrollTan1Scroll;
BXSCROLLBARSTRUCT formPathView_scrollTan2Scroll;
BX_VOID formPathViewInit(HBOX hBox)
{
  BxScrollBar_Create(BxGetDlgItem(hBox, FORMPATHVIEW_SCROLLTAN1), &formPathView_scrollTan1Scroll, BSB_VERTICAL);
  BxScrollBar_Create(BxGetDlgItem(hBox, FORMPATHVIEW_SCROLLTAN2), &formPathView_scrollTan2Scroll, BSB_VERTICAL);
}

BX_VOID formPathViewUpdate(HBOX hBox)
{
}

