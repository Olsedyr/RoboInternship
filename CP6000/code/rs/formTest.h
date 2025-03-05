//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTest.h
#if !defined(FORMTEST_H)
#define FORMTEST_H
#include "Bx.h"
#include "formTestUser.h"
#define FORMTEST_TEXTLABEL2_2_2 1
#define FORMTEST_TEXTLABEL1 2
#define FORMTEST_CMDSPEED 3
extern BX_BOOL formTest_cmdSpeed_Click(HBOX hBox);
#define FORMTEST_GROUPBOX1_2_2 4
#define FORMTEST_LAB1_4 5
#define FORMTEST_LABTIME 6
#define FORMTEST_LABWORKCELLSTATE 7
#define FORMTEST_LABINFO 8
#define FORMTEST_TEXTLABEL2_2 9
#define FORMTEST_CMDRUN 10
extern BX_BOOL formTest_cmdRun_Click(HBOX hBox);
#define FORMTEST_CMDSTOP 11
extern BX_BOOL formTest_cmdStop_Click(HBOX hBox);
#define FORMTEST_CMDMENU 12
extern BX_BOOL formTest_cmdMenu_Click(HBOX hBox);
extern BX_CHAR formTestText[][MAXLANGUAGE][255];
extern BOXSTRUCT formTest[];
extern BX_BOOL formTestProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formTestUpdate(HBOX hBox);
extern BX_VOID formTestInit(HBOX hBox);
#endif // FORMTEST_H
