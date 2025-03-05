//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formAdjBoxFramesCode.c
#include "Bx.h"
#include "formAdjBoxFrames.h"

BXLISTSTRUCT formAdjBoxFrames_listBoxList;
BX_VOID formAdjBoxFramesInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMADJBOXFRAMES_LISTBOX), &formAdjBoxFrames_listBoxList, 0);
}

BX_VOID formAdjBoxFramesUpdate(HBOX hBox)
{
}

