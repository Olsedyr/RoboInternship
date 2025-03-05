//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathEditor.h
#if !defined(FORMPATHEDITOR_H)
#define FORMPATHEDITOR_H
#include "Bx.h"
#include "formPathEditorUser.h"
#define FORMPATHEDITOR_GROUPBOX1 1
#define FORMPATHEDITOR_CMDMENU 2
extern BX_BOOL formPathEditor_cmdMenu_Click(HBOX hBox);
#define FORMPATHEDITOR_CMDSPEED 3
extern BX_BOOL formPathEditor_cmdSpeed_Click(HBOX hBox);
#define FORMPATHEDITOR_TEXTLABEL2_2_2 4
#define FORMPATHEDITOR_TEXTRATE 5
#define FORMPATHEDITOR_CMDRATE 6
extern BX_BOOL formPathEditor_cmdRate_Click(HBOX hBox);
#define FORMPATHEDITOR_CMDVIEW 7
extern BX_BOOL formPathEditor_cmdView_Click(HBOX hBox);
#define FORMPATHEDITOR_CMDNEXT 8
extern BX_BOOL formPathEditor_cmdNext_Click(HBOX hBox);
#define FORMPATHEDITOR_CMDPREV 9
extern BX_BOOL formPathEditor_cmdPrev_Click(HBOX hBox);
#define FORMPATHEDITOR_LISTBOX 10
extern BX_BOOL formPathEditor_listBox_Click(HBOX hBox);
#define FORMPATHEDITOR_TEXTLABEL2_2 11
#define FORMPATHEDITOR_TEXTLABEL2_2_3 12
#define FORMPATHEDITOR_TEXTNAME 13
extern BX_CHAR formPathEditorText[][MAXLANGUAGE][255];
extern BOXSTRUCT formPathEditor[];
extern BX_BOOL formPathEditorProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formPathEditorUpdate(HBOX hBox);
extern BX_VOID formPathEditorInit(HBOX hBox);
#endif // FORMPATHEDITOR_H
