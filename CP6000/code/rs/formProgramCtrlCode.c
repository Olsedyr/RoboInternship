//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgramCtrlCode.c
#include "Bx.h"
#include "formProgramCtrl.h"

BXLISTSTRUCT formProgramCtrl_listBoxList;
BX_VOID formProgramCtrlInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), &formProgramCtrl_listBoxList, 0);
}

BX_VOID formProgramCtrlUpdate(HBOX hBox)
{
}

