//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSads.h
#if !defined(FORMSADS_H)
#define FORMSADS_H
#include "Bx.h"
#include "formSadsUser.h"
#define FORMSADS_TEXTLABEL2_2 1
#define FORMSADS_CMDCANCEL 2
extern BX_BOOL formSads_cmdCancel_Click(HBOX hBox);
#define FORMSADS_CMDRETURN 3
extern BX_BOOL formSads_cmdReturn_Click(HBOX hBox);
#define FORMSADS_GROUPBOX1 4
#define FORMSADS_CMDSRAMA 5
extern BX_BOOL formSads_cmdSramA_Click(HBOX hBox);
#define FORMSADS_CMDDECELA 6
extern BX_BOOL formSads_cmdDecelA_Click(HBOX hBox);
#define FORMSADS_TEXTLABEL2_2_2_2_2_2 7
#define FORMSADS_TEXTLABEL2_2_2_2_2 8
#define FORMSADS_CMDACCELA 9
extern BX_BOOL formSads_cmdAccelA_Click(HBOX hBox);
#define FORMSADS_TEXTLABEL2_2_2_2 10
#define FORMSADS_TEXTLABEL2_2_2 11
#define FORMSADS_CMDSPEEDA 12
extern BX_BOOL formSads_cmdSpeedA_Click(HBOX hBox);
extern BX_CHAR formSadsText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSads[];
extern BX_BOOL formSadsProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSadsUpdate(HBOX hBox);
extern BX_VOID formSadsInit(HBOX hBox);
#endif // FORMSADS_H
