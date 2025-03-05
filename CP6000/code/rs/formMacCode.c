//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMacCode.c
#include "Bx.h"
#include "formMac.h"

BXLISTSTRUCT formMac_listBoxInList;
BXLISTSTRUCT formMac_listBoxInitList;
BXLISTSTRUCT formMac_listBoxOutList;
BX_VOID formMacInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMMAC_LISTBOXIN), &formMac_listBoxInList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT), &formMac_listBoxInitList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT), &formMac_listBoxOutList, 0);
}

BX_VOID formMacUpdate(HBOX hBox)
{
}

