//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formBxIcons.h
#if !defined(FORMBXICONS_H)
#define FORMBXICONS_H
#include "Bx.h"
#include "formBxIconsUser.h"
#define FORMBXICONS_LABNO 1
#define FORMBXICONS_LABYES 2
#define FORMBXICONS_LABQUESTION 3
extern BX_CHAR formBxIconsText[][MAXLANGUAGE][255];
extern BOXSTRUCT formBxIcons[];
extern BX_BOOL formBxIconsProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formBxIconsUpdate(HBOX hBox);
extern BX_VOID formBxIconsInit(HBOX hBox);
#endif // FORMBXICONS_H
