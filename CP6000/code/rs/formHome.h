//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formHome.h
#if !defined(FORMHOME_H)
#define FORMHOME_H
#include "Bx.h"
#include "formHomeUser.h"
#define FORMHOME_TEXTLABEL2 1
#define FORMHOME_CMDLOGIN 2
extern BX_BOOL formHome_cmdLogin_Click(HBOX hBox);
#define FORMHOME_TEXTLABEL2_2 3
#define FORMHOME_TEXTLABEL2_2_2 4
extern BX_CHAR formHomeText[][MAXLANGUAGE][255];
extern BOXSTRUCT formHome[];
extern BX_BOOL formHomeProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formHomeUpdate(HBOX hBox);
extern BX_VOID formHomeInit(HBOX hBox);
#endif // FORMHOME_H
