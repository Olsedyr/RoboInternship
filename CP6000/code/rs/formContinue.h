//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formContinue.h
#if !defined(FORMCONTINUE_H)
#define FORMCONTINUE_H
#include "Bx.h"
#include "formContinueUser.h"
#define FORMCONTINUE_TEXTLABEL2_2 1
#define FORMCONTINUE_TEXTLABEL1 2
#define FORMCONTINUE_GROUPBOX1_2_2 3
#define FORMCONTINUE_LABINFOTYPE 4
#define FORMCONTINUE_LABINFO 5
#define FORMCONTINUE_TEXTLABEL1_2 6
#define FORMCONTINUE_CMDCONTINUE 7
extern BX_BOOL formContinue_cmdContinue_Click(HBOX hBox);
#define FORMCONTINUE_CMDSTOP 8
extern BX_BOOL formContinue_cmdStop_Click(HBOX hBox);
extern BX_CHAR formContinueText[][MAXLANGUAGE][255];
extern BOXSTRUCT formContinue[];
extern BX_BOOL formContinueProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formContinueUpdate(HBOX hBox);
extern BX_VOID formContinueInit(HBOX hBox);
#endif // FORMCONTINUE_H
