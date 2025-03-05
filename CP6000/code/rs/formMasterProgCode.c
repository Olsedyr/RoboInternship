//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMasterProgCode.c
#include "Bx.h"
#include "formMasterProg.h"

BXLISTSTRUCT formMasterProg_listBoxList;
BXLISTSTRUCT formMasterProg_listBox_2List;
BX_VOID formMasterProgInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMMASTERPROG_LISTBOX), &formMasterProg_listBoxList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMMASTERPROG_LISTBOX_2), &formMasterProg_listBox_2List, 0);
}

BX_VOID formMasterProgUpdate(HBOX hBox)
{
}

