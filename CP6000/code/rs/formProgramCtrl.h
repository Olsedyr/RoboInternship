//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgramCtrl.h
#if !defined(FORMPROGRAMCTRL_H)
#define FORMPROGRAMCTRL_H
#include "Bx.h"
#include "formProgramCtrlUser.h"
#define FORMPROGRAMCTRL_CMDEDIT 1
extern BX_BOOL formProgramCtrl_cmdEdit_Click(HBOX hBox);
#define FORMPROGRAMCTRL_CMDCLOSE 2
extern BX_BOOL formProgramCtrl_cmdClose_Click(HBOX hBox);
#define FORMPROGRAMCTRL_LISTBOX 3
extern BX_BOOL formProgramCtrl_listBox_Click(HBOX hBox);
#define FORMPROGRAMCTRL_GROUPBOX2 4
#define FORMPROGRAMCTRL_LABSTATE 5
extern BX_CHAR formProgramCtrlText[][MAXLANGUAGE][255];
extern BOXSTRUCT formProgramCtrl[];
extern BX_BOOL formProgramCtrlProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formProgramCtrlUpdate(HBOX hBox);
extern BX_VOID formProgramCtrlInit(HBOX hBox);
#endif // FORMPROGRAMCTRL_H
