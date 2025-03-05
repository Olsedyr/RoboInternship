//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFixPointsCode.c
#include "Bx.h"
#include "formFixPoints.h"

BXLISTSTRUCT formFixPoints_listBoxList;
BX_VOID formFixPointsInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMFIXPOINTS_LISTBOX), &formFixPoints_listBoxList, 0);
}

BX_VOID formFixPointsUpdate(HBOX hBox)
{
}

