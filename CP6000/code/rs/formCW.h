//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCW.h
#if !defined(FORMCW_H)
#define FORMCW_H
#include "Bx.h"
#include "formCWUser.h"
#define FORMCW_TEXTLABEL1 1
#define FORMCW_CMDMENU 2
extern BX_BOOL formCW_cmdMenu_Click(HBOX hBox);
#define FORMCW_CMDSTOP 3
extern BX_BOOL formCW_cmdStop_Click(HBOX hBox);
#define FORMCW_CMDRUN 4
extern BX_BOOL formCW_cmdRun_Click(HBOX hBox);
#define FORMCW_TEXTLABEL2_2 5
#define FORMCW_LOWER 6
extern BX_BOOL formCW_Lower_Click(HBOX hBox);
#define FORMCW_UPPER 7
extern BX_BOOL formCW_Upper_Click(HBOX hBox);
#define FORMCW_TEXTLABEL2_2_2_3 8
#define FORMCW_GROUPBOX1_2_2 9
#define FORMCW_LABTIME 10
#define FORMCW_LABWEIGHT 11
#define FORMCW_LABERROR1 12
#define FORMCW_LABWORKCELLSTATE 13
#define FORMCW_LABINFO 14
#define FORMCW_LABERROR2 15
#define FORMCW_LABWEIGHT_2 16
#define FORMCW_LAB1_4 17
extern BX_CHAR formCWText[][MAXLANGUAGE][255];
extern BOXSTRUCT formCW[];
extern BX_BOOL formCWProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formCWUpdate(HBOX hBox);
extern BX_VOID formCWInit(HBOX hBox);
#endif // FORMCW_H
