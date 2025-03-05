//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDistIOCode.c
#include "Bx.h"
#include "formDistIO.h"

BXLISTSTRUCT formDistIO_listBoxList;
BX_VOID formDistIOInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMDISTIO_LISTBOX), &formDistIO_listBoxList, 0);
}

BX_VOID formDistIOUpdate(HBOX hBox)
{
}

