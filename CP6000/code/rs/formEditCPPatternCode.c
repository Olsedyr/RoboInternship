//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditCPPatternCode.c
#include "Bx.h"
#include "formEditCPPattern.h"

BXLISTSTRUCT formEditCPPattern_listBoxPPPList;
BX_VOID formEditCPPatternInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMEDITCPPATTERN_LISTBOXPPP), &formEditCPPattern_listBoxPPPList, 0);
}

BX_VOID formEditCPPatternUpdate(HBOX hBox)
{
}

