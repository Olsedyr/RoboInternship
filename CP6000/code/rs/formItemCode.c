//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItemCode.c
#include "Bx.h"
#include "formItem.h"

BXLISTSTRUCT formItem_listBoxList;
BX_VOID formItemInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMITEM_LISTBOX), &formItem_listBoxList, 0);
}

BX_VOID formItemUpdate(HBOX hBox)
{
}

