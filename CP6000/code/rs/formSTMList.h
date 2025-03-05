//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMList.h
#if !defined(FORMSTMLIST_H)
#define FORMSTMLIST_H
#include "Bx.h"
#include "formSTMListUser.h"
#define FORMSTMLIST_LISTBOX 1
extern BX_BOOL formSTMList_listBox_Click(HBOX hBox);
#define FORMSTMLIST_CMDCLOSE 2
extern BX_BOOL formSTMList_cmdClose_Click(HBOX hBox);
#define FORMSTMLIST_TEXTLABEL2_2 3
extern BX_CHAR formSTMListText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSTMList[];
extern BX_BOOL formSTMListProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSTMListUpdate(HBOX hBox);
extern BX_VOID formSTMListInit(HBOX hBox);
#endif // FORMSTMLIST_H
