//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formStdRun.h
#if !defined(FORMSTDRUN_H)
#define FORMSTDRUN_H
#include "Bx.h"
#include "formStdRunUser.h"
#define FORMSTDRUN_TEXTLABEL2_2 1
#define FORMSTDRUN_TEXTLABEL1 2
#define FORMSTDRUN_CMDMENU 3
extern BX_BOOL formStdRun_cmdMenu_Click(HBOX hBox);
#define FORMSTDRUN_CMDSTOP 4
extern BX_BOOL formStdRun_cmdStop_Click(HBOX hBox);
#define FORMSTDRUN_CMDRUN 5
extern BX_BOOL formStdRun_cmdRun_Click(HBOX hBox);
#define FORMSTDRUN_TEXTLABEL2_2_2 6
#define FORMSTDRUN_CMDSPEED 7
extern BX_BOOL formStdRun_cmdSpeed_Click(HBOX hBox);
#define FORMSTDRUN_GROUPBOX1_2_2 8
#define FORMSTDRUN_LABWORKCELLSTATE 9
#define FORMSTDRUN_LABERROR1 10
#define FORMSTDRUN_LABERROR2 11
#define FORMSTDRUN_LABINFO 12
#define FORMSTDRUN_LABROBOTSTATE 13
#define FORMSTDRUN_LABTIME 14
extern BX_CHAR formStdRunText[][MAXLANGUAGE][255];
extern BOXSTRUCT formStdRun[];
extern BX_BOOL formStdRunProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formStdRunUpdate(HBOX hBox);
extern BX_VOID formStdRunInit(HBOX hBox);
#endif // FORMSTDRUN_H
