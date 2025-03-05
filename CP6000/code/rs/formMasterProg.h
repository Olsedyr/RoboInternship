//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMasterProg.h
#if !defined(FORMMASTERPROG_H)
#define FORMMASTERPROG_H
#include "Bx.h"
#include "formMasterProgUser.h"
#define FORMMASTERPROG_CMDOK 1
extern BX_BOOL formMasterProg_cmdOk_Click(HBOX hBox);
#define FORMMASTERPROG_TEXTLABEL2_2 2
#define FORMMASTERPROG_LISTBOX 3
extern BX_BOOL formMasterProg_listBox_Click(HBOX hBox);
#define FORMMASTERPROG_CMDCANCEL 4
extern BX_BOOL formMasterProg_cmdCancel_Click(HBOX hBox);
#define FORMMASTERPROG_CMDEDIT 5
extern BX_BOOL formMasterProg_cmdEdit_Click(HBOX hBox);
#define FORMMASTERPROG_TEXTLABEL2_3 6
#define FORMMASTERPROG_LISTBOX_2 7
extern BX_BOOL formMasterProg_listBox_2_Click(HBOX hBox);
extern BX_CHAR formMasterProgText[][MAXLANGUAGE][255];
extern BOXSTRUCT formMasterProg[];
extern BX_BOOL formMasterProgProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formMasterProgUpdate(HBOX hBox);
extern BX_VOID formMasterProgInit(HBOX hBox);
#endif // FORMMASTERPROG_H
