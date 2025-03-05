//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formKeyboard.h
#if !defined(FORMKEYBOARD_H)
#define FORMKEYBOARD_H
#include "Bx.h"
#include "formKeyboardUser.h"
#define FORMKEYBOARD_CMD2 1
extern BX_BOOL formKeyboard_cmd2_Click(HBOX hBox);
#define FORMKEYBOARD_CMD3 2
extern BX_BOOL formKeyboard_cmd3_Click(HBOX hBox);
#define FORMKEYBOARD_CMD4 3
extern BX_BOOL formKeyboard_cmd4_Click(HBOX hBox);
#define FORMKEYBOARD_CMD5 4
extern BX_BOOL formKeyboard_cmd5_Click(HBOX hBox);
#define FORMKEYBOARD_CMD6 5
extern BX_BOOL formKeyboard_cmd6_Click(HBOX hBox);
#define FORMKEYBOARD_CMD7 6
extern BX_BOOL formKeyboard_cmd7_Click(HBOX hBox);
#define FORMKEYBOARD_CMD8 7
extern BX_BOOL formKeyboard_cmd8_Click(HBOX hBox);
#define FORMKEYBOARD_CMD9 8
extern BX_BOOL formKeyboard_cmd9_Click(HBOX hBox);
#define FORMKEYBOARD_CMD0 9
extern BX_BOOL formKeyboard_cmd0_Click(HBOX hBox);
#define FORMKEYBOARD_CMDQ 10
extern BX_BOOL formKeyboard_cmdQ_Click(HBOX hBox);
#define FORMKEYBOARD_CMDW 11
extern BX_BOOL formKeyboard_cmdW_Click(HBOX hBox);
#define FORMKEYBOARD_CMDE 12
extern BX_BOOL formKeyboard_cmdE_Click(HBOX hBox);
#define FORMKEYBOARD_CMDR 13
extern BX_BOOL formKeyboard_cmdR_Click(HBOX hBox);
#define FORMKEYBOARD_CMDT 14
extern BX_BOOL formKeyboard_cmdT_Click(HBOX hBox);
#define FORMKEYBOARD_CMDY 15
extern BX_BOOL formKeyboard_cmdY_Click(HBOX hBox);
#define FORMKEYBOARD_CMDU 16
extern BX_BOOL formKeyboard_cmdU_Click(HBOX hBox);
#define FORMKEYBOARD_CMDI 17
extern BX_BOOL formKeyboard_cmdI_Click(HBOX hBox);
#define FORMKEYBOARD_CMDO 18
extern BX_BOOL formKeyboard_cmdO_Click(HBOX hBox);
#define FORMKEYBOARD_CMDP 19
extern BX_BOOL formKeyboard_cmdP_Click(HBOX hBox);
#define FORMKEYBOARD_CMDCOLON 20
extern BX_BOOL formKeyboard_cmdColon_Click(HBOX hBox);
#define FORMKEYBOARD_TEXTLABEL1 21
#define FORMKEYBOARD_CMD1 22
extern BX_BOOL formKeyboard_cmd1_Click(HBOX hBox);
#define FORMKEYBOARD_CMDENTER 23
extern BX_BOOL formKeyboard_cmdEnter_Click(HBOX hBox);
#define FORMKEYBOARD_CMDCANCEL 24
extern BX_BOOL formKeyboard_cmdCancel_Click(HBOX hBox);
#define FORMKEYBOARD_CMDA 25
extern BX_BOOL formKeyboard_cmdA_Click(HBOX hBox);
#define FORMKEYBOARD_CMDS 26
extern BX_BOOL formKeyboard_cmdS_Click(HBOX hBox);
#define FORMKEYBOARD_CMDD 27
extern BX_BOOL formKeyboard_cmdD_Click(HBOX hBox);
#define FORMKEYBOARD_CMDF 28
extern BX_BOOL formKeyboard_cmdF_Click(HBOX hBox);
#define FORMKEYBOARD_CMDG 29
extern BX_BOOL formKeyboard_cmdG_Click(HBOX hBox);
#define FORMKEYBOARD_CMDH 30
extern BX_BOOL formKeyboard_cmdH_Click(HBOX hBox);
#define FORMKEYBOARD_CMDJ 31
extern BX_BOOL formKeyboard_cmdJ_Click(HBOX hBox);
#define FORMKEYBOARD_CMDK 32
extern BX_BOOL formKeyboard_cmdK_Click(HBOX hBox);
#define FORMKEYBOARD_CMDL 33
extern BX_BOOL formKeyboard_cmdL_Click(HBOX hBox);
#define FORMKEYBOARD_CMDAPO 34
extern BX_BOOL formKeyboard_cmdApo_Click(HBOX hBox);
#define FORMKEYBOARD_CMDSLASH 35
extern BX_BOOL formKeyboard_cmdSlash_Click(HBOX hBox);
#define FORMKEYBOARD_CMDZ 36
extern BX_BOOL formKeyboard_cmdZ_Click(HBOX hBox);
#define FORMKEYBOARD_CMDX 37
extern BX_BOOL formKeyboard_cmdX_Click(HBOX hBox);
#define FORMKEYBOARD_CMDC 38
extern BX_BOOL formKeyboard_cmdC_Click(HBOX hBox);
#define FORMKEYBOARD_CMDV 39
extern BX_BOOL formKeyboard_cmdV_Click(HBOX hBox);
#define FORMKEYBOARD_CMDB 40
extern BX_BOOL formKeyboard_cmdB_Click(HBOX hBox);
#define FORMKEYBOARD_CMDN 41
extern BX_BOOL formKeyboard_cmdN_Click(HBOX hBox);
#define FORMKEYBOARD_CMDM 42
extern BX_BOOL formKeyboard_cmdM_Click(HBOX hBox);
#define FORMKEYBOARD_CMDCOMMA 43
extern BX_BOOL formKeyboard_cmdComma_Click(HBOX hBox);
#define FORMKEYBOARD_CMDDOT 44
extern BX_BOOL formKeyboard_cmdDot_Click(HBOX hBox);
#define FORMKEYBOARD_CMDHYPHEN 45
extern BX_BOOL formKeyboard_cmdHyphen_Click(HBOX hBox);
#define FORMKEYBOARD_CMDSPACEBAR 46
extern BX_BOOL formKeyboard_cmdSpacebar_Click(HBOX hBox);
#define FORMKEYBOARD_CMDSHIFT 47
extern BX_BOOL formKeyboard_cmdShift_Click(HBOX hBox);
#define FORMKEYBOARD_CMDBACKSPACE 48
extern BX_BOOL formKeyboard_cmdBackSpace_Click(HBOX hBox);
extern BX_CHAR formKeyboardText[][MAXLANGUAGE][255];
extern BOXSTRUCT formKeyboard[];
extern BX_BOOL formKeyboardProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formKeyboardUpdate(HBOX hBox);
extern BX_VOID formKeyboardInit(HBOX hBox);
#endif // FORMKEYBOARD_H
