//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formScopeDataCode.c
#include "Bx.h"
#include "formScopeData.h"

BXSCROLLBARSTRUCT formScopeData_scrollBar1Scroll;
BX_VOID formScopeDataInit(HBOX hBox)
{
  BxScrollBar_Create(BxGetDlgItem(hBox, FORMSCOPEDATA_SCROLLBAR1), &formScopeData_scrollBar1Scroll, BSB_VERTICAL);
}

BX_VOID formScopeDataUpdate(HBOX hBox)
{
}

