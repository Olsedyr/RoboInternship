//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFileDialog.h
#if !defined(FORMFILEDIALOG_H)
#define FORMFILEDIALOG_H
#include "Bx.h"
#include "formFileDialogUser.h"
#define FORMFILEDIALOG_CMDMENU 1
extern BX_BOOL formFileDialog_cmdMenu_Click(HBOX hBox);
#define FORMFILEDIALOG_LISTDIR 2
extern BX_BOOL formFileDialog_listDir_Click(HBOX hBox);
#define FORMFILEDIALOG_LISTFILE 3
extern BX_BOOL formFileDialog_listFile_Click(HBOX hBox);
#define FORMFILEDIALOG_CMDFILENAME 4
extern BX_BOOL formFileDialog_cmdFilename_Click(HBOX hBox);
extern BX_CHAR formFileDialogText[][MAXLANGUAGE][255];
extern BOXSTRUCT formFileDialog[];
extern BX_BOOL formFileDialogProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formFileDialogUpdate(HBOX hBox);
extern BX_VOID formFileDialogInit(HBOX hBox);
#endif // FORMFILEDIALOG_H
