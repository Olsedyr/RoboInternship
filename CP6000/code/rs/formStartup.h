//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formStartup.h
#if !defined(FORMSTARTUP_H)
#define FORMSTARTUP_H
#include "Bx.h"
#include "formStartupUser.h"
#define FORMSTARTUP_LABPROGRESS 1
#define FORMSTARTUP_TEXTMESSAGE 2
#define FORMSTARTUP_TEXTLABEL2_2 3
#define FORMSTARTUP_TEXTLABEL2 4
extern BX_CHAR formStartupText[][MAXLANGUAGE][255];
extern BOXSTRUCT formStartup[];
extern BX_BOOL formStartupProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formStartupUpdate(HBOX hBox);
extern BX_VOID formStartupInit(HBOX hBox);
#endif // FORMSTARTUP_H
