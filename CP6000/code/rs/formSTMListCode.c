//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMListCode.c
#include "Bx.h"
#include "formSTMList.h"

BXLISTSTRUCT formSTMList_listBoxList;
BX_VOID formSTMListInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMSTMLIST_LISTBOX), &formSTMList_listBoxList, 0);
}

BX_VOID formSTMListUpdate(HBOX hBox)
{
}

