//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form900.h
#if !defined(FORM900_H)
#define FORM900_H
#include "Bx.h"
#include "form900User.h"
#define FORM900_CMDRUN 1
extern BX_BOOL form900_cmdRun_Click(HBOX hBox);
#define FORM900_CMDSTOP 2
extern BX_BOOL form900_cmdStop_Click(HBOX hBox);
#define FORM900_CMDMENU 3
extern BX_BOOL form900_cmdMenu_Click(HBOX hBox);
#define FORM900_TEXTLABEL1 4
#define FORM900_GROUPBOX1_2_2 5
#define FORM900_LABTIME 6
#define FORM900_LAB1_4 7
#define FORM900_LABWORKCELLSTATE 8
#define FORM900_LABERROR1 9
#define FORM900_LABERROR2 10
#define FORM900_LABINFO 11
#define FORM900_TEXTLABEL2_2 12
extern BX_CHAR form900Text[][MAXLANGUAGE][255];
extern BOXSTRUCT form900[];
extern BX_BOOL form900Proc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID form900Update(HBOX hBox);
extern BX_VOID form900Init(HBOX hBox);
#endif // FORM900_H
