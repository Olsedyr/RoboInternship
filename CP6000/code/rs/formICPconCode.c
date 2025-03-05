//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formICPconCode.c
#include "Bx.h"
#include "formICPcon.h"

BXLISTSTRUCT formICPcon_listBoxInList;
BXLISTSTRUCT formICPcon_listBoxOutList;
BX_VOID formICPconInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMICPCON_LISTBOXIN), &formICPcon_listBoxInList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT), &formICPcon_listBoxOutList, 0);
}

BX_VOID formICPconUpdate(HBOX hBox)
{
}

