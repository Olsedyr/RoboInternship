//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDemo.h
#if !defined(FORMDEMO_H)
#define FORMDEMO_H
#include "Bx.h"
#include "formDemoUser.h"
#define FORMDEMO_TEXTLABEL1 1
#define FORMDEMO_CMDRS 2
extern BX_BOOL formDemo_cmdRS_Click(HBOX hBox);
#define FORMDEMO_CMDCW 3
extern BX_BOOL formDemo_cmdCW_Click(HBOX hBox);
#define FORMDEMO_CMDCP 4
extern BX_BOOL formDemo_cmdCP_Click(HBOX hBox);
#define FORMDEMO_CMDCM 5
extern BX_BOOL formDemo_cmdCM_Click(HBOX hBox);
extern BX_CHAR formDemoText[][MAXLANGUAGE][255];
extern BOXSTRUCT formDemo[];
extern BX_BOOL formDemoProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formDemoUpdate(HBOX hBox);
extern BX_VOID formDemoInit(HBOX hBox);
#endif // FORMDEMO_H
