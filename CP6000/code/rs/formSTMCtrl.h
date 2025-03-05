//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMCtrl.h
#if !defined(FORMSTMCTRL_H)
#define FORMSTMCTRL_H
#include "Bx.h"
#include "formSTMCtrlUser.h"
#define FORMSTMCTRL_CMDCLOSE 1
extern BX_BOOL formSTMCtrl_cmdClose_Click(HBOX hBox);
#define FORMSTMCTRL_LISTBOX 2
extern BX_BOOL formSTMCtrl_listBox_Click(HBOX hBox);
#define FORMSTMCTRL_GROUPBOX2 3
#define FORMSTMCTRL_LABSTATE 4
#define FORMSTMCTRL_GROUPBOX1 5
#define FORMSTMCTRL_LABNAME 6
#define FORMSTMCTRL_CMDRESTART 7
extern BX_BOOL formSTMCtrl_cmdRestart_Click(HBOX hBox);
#define FORMSTMCTRL_CMDSCOPE 8
extern BX_BOOL formSTMCtrl_cmdScope_Click(HBOX hBox);
#define FORMSTMCTRL_CMDEDIT 9
extern BX_BOOL formSTMCtrl_cmdEdit_Click(HBOX hBox);
#define FORMSTMCTRL_CMDHALT 10
extern BX_BOOL formSTMCtrl_cmdHalt_Click(HBOX hBox);
extern BX_CHAR formSTMCtrlText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSTMCtrl[];
extern BX_BOOL formSTMCtrlProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSTMCtrlUpdate(HBOX hBox);
extern BX_VOID formSTMCtrlInit(HBOX hBox);
#endif // FORMSTMCTRL_H
