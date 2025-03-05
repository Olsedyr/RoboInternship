//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTomatoInBox.h
#if !defined(FORMTOMATOINBOX_H)
#define FORMTOMATOINBOX_H
#include "Bx.h"
#include "formTomatoInBoxUser.h"
#define FORMTOMATOINBOX_TEXTLABEL1 1
#define FORMTOMATOINBOX_TEXTLABEL2_2 2
#define FORMTOMATOINBOX_CMDMENU 3
extern BX_BOOL formTomatoInBox_cmdMenu_Click(HBOX hBox);
#define FORMTOMATOINBOX_CMDSPEED 4
extern BX_BOOL formTomatoInBox_cmdSpeed_Click(HBOX hBox);
#define FORMTOMATOINBOX_CMDLAG 5
extern BX_BOOL formTomatoInBox_cmdLag_Click(HBOX hBox);
#define FORMTOMATOINBOX_CMDNUMBOX 6
extern BX_BOOL formTomatoInBox_cmdNumBox_Click(HBOX hBox);
#define FORMTOMATOINBOX_TEXTLABEL2_2_2 7
#define FORMTOMATOINBOX_TEXTLABEL2_2_3 8
#define FORMTOMATOINBOX_LAB1_2 9
#define FORMTOMATOINBOX_CMDRUN 10
extern BX_BOOL formTomatoInBox_cmdRun_Click(HBOX hBox);
#define FORMTOMATOINBOX_CMDSTOP 11
extern BX_BOOL formTomatoInBox_cmdStop_Click(HBOX hBox);
#define FORMTOMATOINBOX_GROUPBOX1_2_2 12
#define FORMTOMATOINBOX_LAB1_3 13
#define FORMTOMATOINBOX_LABINFO 14
#define FORMTOMATOINBOX_LABINFOTYPE 15
#define FORMTOMATOINBOX_LAB1 16
#define FORMTOMATOINBOX_LAB1_4 17
#define FORMTOMATOINBOX_LABTIME 18
#define FORMTOMATOINBOX_LABNUMBOX 19
#define FORMTOMATOINBOX_LABNUMPALLET 20
extern BX_CHAR formTomatoInBoxText[][MAXLANGUAGE][255];
extern BOXSTRUCT formTomatoInBox[];
extern BX_BOOL formTomatoInBoxProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formTomatoInBoxUpdate(HBOX hBox);
extern BX_VOID formTomatoInBoxInit(HBOX hBox);
#endif // FORMTOMATOINBOX_H
