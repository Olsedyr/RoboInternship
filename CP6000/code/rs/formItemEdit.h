//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItemEdit.h
#if !defined(FORMITEMEDIT_H)
#define FORMITEMEDIT_H
#include "Bx.h"
#include "formItemEditUser.h"
#define FORMITEMEDIT_CMDCANCEL 1
extern BX_BOOL formItemEdit_cmdCancel_Click(HBOX hBox);
#define FORMITEMEDIT_CMDRETURN 2
extern BX_BOOL formItemEdit_cmdReturn_Click(HBOX hBox);
#define FORMITEMEDIT_TEXTLABEL2_2 3
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3 4
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_2 5
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3 6
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_2 7
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_2_2 8
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_4 9
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_2_2 10
#define FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_3 11
#define FORMITEMEDIT_CMDMY 12
extern BX_BOOL formItemEdit_cmdmy_Click(HBOX hBox);
#define FORMITEMEDIT_CMDGX 13
extern BX_BOOL formItemEdit_cmdgx_Click(HBOX hBox);
#define FORMITEMEDIT_CMDWEIGHT 14
extern BX_BOOL formItemEdit_cmdweight_Click(HBOX hBox);
#define FORMITEMEDIT_GROUPBOX1 15
#define FORMITEMEDIT_TEXTLABELNAME 16
#define FORMITEMEDIT_CMDGY 17
extern BX_BOOL formItemEdit_cmdgy_Click(HBOX hBox);
#define FORMITEMEDIT_CMDSY 18
extern BX_BOOL formItemEdit_cmdsy_Click(HBOX hBox);
#define FORMITEMEDIT_CMDDZ 19
extern BX_BOOL formItemEdit_cmddz_Click(HBOX hBox);
#define FORMITEMEDIT_CMDDY 20
extern BX_BOOL formItemEdit_cmddy_Click(HBOX hBox);
#define FORMITEMEDIT_CMDDX 21
extern BX_BOOL formItemEdit_cmddx_Click(HBOX hBox);
extern BX_CHAR formItemEditText[][MAXLANGUAGE][255];
extern BOXSTRUCT formItemEdit[];
extern BX_BOOL formItemEditProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formItemEditUpdate(HBOX hBox);
extern BX_VOID formItemEditInit(HBOX hBox);
#endif // FORMITEMEDIT_H
