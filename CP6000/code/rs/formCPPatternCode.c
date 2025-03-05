//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCPPatternCode.c
#include "Bx.h"
#include "formCPPattern.h"

BXLISTSTRUCT formCPPattern_listBoxList;
BX_VOID formCPPatternInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX), &formCPPattern_listBoxList, 0);
}

BX_VOID formCPPatternUpdate(HBOX hBox)
{
}

