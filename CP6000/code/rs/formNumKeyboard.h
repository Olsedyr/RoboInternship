//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formNumKeyboard.h
#if !defined(FORMNUMKEYBOARD_H)
#define FORMNUMKEYBOARD_H
#include "Bx.h"
#include "formNumKeyboardUser.h"
#define FORMNUMKEYBOARD_CMDENTER 1
extern BX_BOOL formNumKeyboard_cmdEnter_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMDCANCEL 2
extern BX_BOOL formNumKeyboard_cmdCancel_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMSNEG 3
extern BX_BOOL formNumKeyboard_cmsNeg_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMDCOMMA 4
extern BX_BOOL formNumKeyboard_cmdComma_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMDZERO 5
extern BX_BOOL formNumKeyboard_cmdZero_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD1 6
extern BX_BOOL formNumKeyboard_cmd1_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD7 7
extern BX_BOOL formNumKeyboard_cmd7_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD5 8
extern BX_BOOL formNumKeyboard_cmd5_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD3 9
extern BX_BOOL formNumKeyboard_cmd3_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD9 10
extern BX_BOOL formNumKeyboard_cmd9_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD2 11
extern BX_BOOL formNumKeyboard_cmd2_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMDMINUS 12
extern BX_BOOL formNumKeyboard_cmdMinus_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD4 13
extern BX_BOOL formNumKeyboard_cmd4_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD8 14
extern BX_BOOL formNumKeyboard_cmd8_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMD6 15
extern BX_BOOL formNumKeyboard_cmd6_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMSCLEAR 16
extern BX_BOOL formNumKeyboard_cmsClear_Click(HBOX hBox);
#define FORMNUMKEYBOARD_CMDPLUS 17
extern BX_BOOL formNumKeyboard_cmdPlus_Click(HBOX hBox);
#define FORMNUMKEYBOARD_TEXTLABEL1 18
extern BX_CHAR formNumKeyboardText[][MAXLANGUAGE][255];
extern BOXSTRUCT formNumKeyboard[];
extern BX_BOOL formNumKeyboardProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formNumKeyboardUpdate(HBOX hBox);
extern BX_VOID formNumKeyboardInit(HBOX hBox);
#endif // FORMNUMKEYBOARD_H
