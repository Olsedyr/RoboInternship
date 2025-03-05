//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathEditorCode.c
#include "Bx.h"
#include "formPathEditor.h"

BXLISTSTRUCT formPathEditor_listBoxList;
BX_VOID formPathEditorInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMPATHEDITOR_LISTBOX), &formPathEditor_listBoxList, 0);
}

BX_VOID formPathEditorUpdate(HBOX hBox)
{
}

