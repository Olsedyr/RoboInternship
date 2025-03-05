//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formComSKCode.c
#include "Bx.h"
#include "formComSK.h"

BXLISTSTRUCT formComSK_listBoxInList;
BXLISTSTRUCT formComSK_listBoxOutList;
BXLISTSTRUCT formComSK_listBoxInitList;
BX_VOID formComSKInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXIN), &formComSK_listBoxInList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXOUT), &formComSK_listBoxOutList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXINIT), &formComSK_listBoxInitList, 0);
}

BX_VOID formComSKUpdate(HBOX hBox)
{
}

