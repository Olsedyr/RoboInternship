//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFixPoints.h
#if !defined(FORMFIXPOINTS_H)
#define FORMFIXPOINTS_H
#include "Bx.h"
#include "formFixPointsUser.h"
#define FORMFIXPOINTS_TEXTLABEL2_2 1
#define FORMFIXPOINTS_CMDMENU 2
extern BX_BOOL formFixPoints_cmdMenu_Click(HBOX hBox);
#define FORMFIXPOINTS_LISTBOX 3
extern BX_BOOL formFixPoints_listBox_Click(HBOX hBox);
extern BX_CHAR formFixPointsText[][MAXLANGUAGE][255];
extern BOXSTRUCT formFixPoints[];
extern BX_BOOL formFixPointsProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formFixPointsUpdate(HBOX hBox);
extern BX_VOID formFixPointsInit(HBOX hBox);
#endif // FORMFIXPOINTS_H
