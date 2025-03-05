//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgramCode.c
#include "Bx.h"
#include "formProgram.h"

BXLISTSTRUCT formProgram_listBoxList;
BX_VOID formProgramInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMPROGRAM_LISTBOX), &formProgram_listBoxList, 0);
}

BX_VOID formProgramUpdate(HBOX hBox)
{
}

