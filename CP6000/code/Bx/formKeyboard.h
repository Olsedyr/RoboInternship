#if !defined(FORMKEYBOARD_H)
#define FORMKEYBOARD_H
////////////////////////////////////////////////////// 
// 
// formKeyboard.h: interface for formKeyboard
// 
////////////////////////////////////////////////////// 
#include "Bx.h"
#include "formKeyboardUser.h"
#define FORMKEYBOARD_BXBUTTON2 1
#define FORMKEYBOARD_BXBUTTON1 2
#define FORMKEYBOARD_CMDENTER 3
#define FORMKEYBOARD_CMDSHIFT 4
#define FORMKEYBOARD_CMDBKSP 5
#define FORMKEYBOARD_CMD0 6
#define FORMKEYBOARD_CMD9 7
#define FORMKEYBOARD_CMD8 8
#define FORMKEYBOARD_CMD7 9
#define FORMKEYBOARD_CMD6 10
#define FORMKEYBOARD_CMD5 11
#define FORMKEYBOARD_CMD4 12
#define FORMKEYBOARD_CMD3 13
#define FORMKEYBOARD_CMD2 14
#define FORMKEYBOARD_CMD1 15
#define FORMKEYBOARD_CMDSPACE 16
#define FORMKEYBOARD_LABTEXT 17
#define FORMKEYBOARD_CMDSTREG 18
#define FORMKEYBOARD_CMDPUNKTUM 19
#define FORMKEYBOARD_CMDKOMMA 20
#define FORMKEYBOARD_CMDM 21
#define FORMKEYBOARD_CMDN 22
#define FORMKEYBOARD_CMDB 23
#define FORMKEYBOARD_CMDV 24
#define FORMKEYBOARD_CMDC 25
#define FORMKEYBOARD_CMDX 26
#define FORMKEYBOARD_CMDZ 27
#define FORMKEYBOARD_CMDL2 28
#define FORMKEYBOARD_CMDL1 29
#define FORMKEYBOARD_CMDL 30
#define FORMKEYBOARD_CMDK 31
#define FORMKEYBOARD_CMDJ 32
#define FORMKEYBOARD_CMDH 33
#define FORMKEYBOARD_CMDG 34
#define FORMKEYBOARD_CMDF 35
#define FORMKEYBOARD_CMDD 36
#define FORMKEYBOARD_CMDS 37
#define FORMKEYBOARD_CMDL3 38
#define FORMKEYBOARD_CMDP 39
#define FORMKEYBOARD_CMDO 40
#define FORMKEYBOARD_CMDI 41
#define FORMKEYBOARD_CMDU 42
#define FORMKEYBOARD_CMDY 43
#define FORMKEYBOARD_CMDT 44
#define FORMKEYBOARD_CMDR 45
#define FORMKEYBOARD_CMDE 46
#define FORMKEYBOARD_CMDW 47
#define FORMKEYBOARD_CMDA 48
#define FORMKEYBOARD_CMDQ 49
extern char formKeyboardText[][MAXLANGUAGE][255];
extern BOXSTRUCT formKeyboard[];
extern void formKeyboardMain(PINSTANCE hInstance);
extern BX_BOOL formKeyboardUpdate(HBOX hBox);
extern BX_BOOL formKeyboardInit(HBOX hBox);
extern BX_BOOL formKeyboardProc(HBOX hBox, BX_UINT uMsg
           ,BX_WPARAM wParam, BX_LPARAM lParam);
extern void formKeyboard_BxButton2_Click(HBOX hBox);
extern void formKeyboard_BxButton1_Click(HBOX hBox);
extern void formKeyboard_cmdEnter_Click(HBOX hBox);
extern void formKeyboard_cmdShift_Click(HBOX hBox);
extern void formKeyboard_cmdBkSp_Click(HBOX hBox);
extern void formKeyboard_cmd0_Click(HBOX hBox);
extern void formKeyboard_cmd9_Click(HBOX hBox);
extern void formKeyboard_cmd8_Click(HBOX hBox);
extern void formKeyboard_cmd7_Click(HBOX hBox);
extern void formKeyboard_cmd6_Click(HBOX hBox);
extern void formKeyboard_cmd5_Click(HBOX hBox);
extern void formKeyboard_cmd4_Click(HBOX hBox);
extern void formKeyboard_cmd3_Click(HBOX hBox);
extern void formKeyboard_cmd2_Click(HBOX hBox);
extern void formKeyboard_cmd1_Click(HBOX hBox);
extern void formKeyboard_cmdSpace_Click(HBOX hBox);
extern void formKeyboard_cmdStreg_Click(HBOX hBox);
extern void formKeyboard_cmdPunktum_Click(HBOX hBox);
extern void formKeyboard_cmdKomma_Click(HBOX hBox);
extern void formKeyboard_cmdM_Click(HBOX hBox);
extern void formKeyboard_cmdN_Click(HBOX hBox);
extern void formKeyboard_cmdB_Click(HBOX hBox);
extern void formKeyboard_cmdV_Click(HBOX hBox);
extern void formKeyboard_cmdC_Click(HBOX hBox);
extern void formKeyboard_cmdX_Click(HBOX hBox);
extern void formKeyboard_cmdZ_Click(HBOX hBox);
extern void formKeyboard_cmdL2_Click(HBOX hBox);
extern void formKeyboard_cmdL1_Click(HBOX hBox);
extern void formKeyboard_cmdL_Click(HBOX hBox);
extern void formKeyboard_cmdK_Click(HBOX hBox);
extern void formKeyboard_cmdJ_Click(HBOX hBox);
extern void formKeyboard_cmdH_Click(HBOX hBox);
extern void formKeyboard_cmdG_Click(HBOX hBox);
extern void formKeyboard_cmdF_Click(HBOX hBox);
extern void formKeyboard_cmdD_Click(HBOX hBox);
extern void formKeyboard_cmdS_Click(HBOX hBox);
extern void formKeyboard_cmdL3_Click(HBOX hBox);
extern void formKeyboard_cmdP_Click(HBOX hBox);
extern void formKeyboard_cmdO_Click(HBOX hBox);
extern void formKeyboard_cmdI_Click(HBOX hBox);
extern void formKeyboard_cmdU_Click(HBOX hBox);
extern void formKeyboard_cmdY_Click(HBOX hBox);
extern void formKeyboard_cmdT_Click(HBOX hBox);
extern void formKeyboard_cmdR_Click(HBOX hBox);
extern void formKeyboard_cmdE_Click(HBOX hBox);
extern void formKeyboard_cmdW_Click(HBOX hBox);
extern void formKeyboard_cmdA_Click(HBOX hBox);
extern void formKeyboard_cmdQ_Click(HBOX hBox);
#ifdef DEFREVISION
char idFORMKEYBOARD_H[]="$Header: /home/cvsroot/sandbox/Bx/formKeyboard.h,v 1.3 2006/06/26 13:57:02 lms Exp $";
#endif
#endif//FORMKEYBOARD_H
