//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formICPcon.h
#if !defined(FORMICPCON_H)
#define FORMICPCON_H
#include "Bx.h"
#include "formICPconUser.h"
#define FORMICPCON_LABMODNAME 1
#define FORMICPCON_LISTBOXIN 2
extern BX_BOOL formICPcon_listBoxIn_Click(HBOX hBox);
#define FORMICPCON_LABMODNAME_2 3
#define FORMICPCON_LABMODNAME_3 4
#define FORMICPCON_CMDCLOSE 5
extern BX_BOOL formICPcon_cmdClose_Click(HBOX hBox);
#define FORMICPCON_LISTBOXOUT 6
extern BX_BOOL formICPcon_listBoxOut_Click(HBOX hBox);
extern BX_CHAR formICPconText[][MAXLANGUAGE][255];
extern BOXSTRUCT formICPcon[];
extern BX_BOOL formICPconProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formICPconUpdate(HBOX hBox);
extern BX_VOID formICPconInit(HBOX hBox);
#endif // FORMICPCON_H
