//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMCtrlCode.c
#include "Bx.h"
#include "formSTMCtrl.h"

BXLISTSTRUCT formSTMCtrl_listBoxList;
BX_VOID formSTMCtrlInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMSTMCTRL_LISTBOX), &formSTMCtrl_listBoxList, 0);
}

BX_VOID formSTMCtrlUpdate(HBOX hBox)
{
}

