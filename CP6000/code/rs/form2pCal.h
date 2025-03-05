//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form2pCal.h
#if !defined(FORM2PCAL_H)
#define FORM2PCAL_H
#include "Bx.h"
#include "form2pCalUser.h"
#define FORM2PCAL_TEXTLABEL2_2 1
#define FORM2PCAL_TEXTLABEL2 2
#define FORM2PCAL_TEXTMESSAGE 3
#define FORM2PCAL_TEXTMSG 4
#define FORM2PCAL_CMDLEFTTOP 5
extern BX_BOOL form2pCal_cmdLeftTop_Click(HBOX hBox);
#define FORM2PCAL_CMDRIGHTBOTTOM 6
extern BX_BOOL form2pCal_cmdRightBottom_Click(HBOX hBox);
#define FORM2PCAL_CMDCONTINUE 7
extern BX_BOOL form2pCal_cmdContinue_Click(HBOX hBox);
extern BX_CHAR form2pCalText[][MAXLANGUAGE][255];
extern BOXSTRUCT form2pCal[];
extern BX_BOOL form2pCalProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID form2pCalUpdate(HBOX hBox);
extern BX_VOID form2pCalInit(HBOX hBox);
#endif // FORM2PCAL_H
