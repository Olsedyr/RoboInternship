//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFileDialogCode.c
#include "Bx.h"
#include "formFileDialog.h"

BXLISTSTRUCT formFileDialog_listDirList;
BXLISTSTRUCT formFileDialog_listFileList;
BX_VOID formFileDialogInit(HBOX hBox)
{
  BxList_Create(BxGetDlgItem(hBox, FORMFILEDIALOG_LISTDIR), &formFileDialog_listDirList, 0);
  BxList_Create(BxGetDlgItem(hBox, FORMFILEDIALOG_LISTFILE), &formFileDialog_listFileList, 0);
}

BX_VOID formFileDialogUpdate(HBOX hBox)
{
}

