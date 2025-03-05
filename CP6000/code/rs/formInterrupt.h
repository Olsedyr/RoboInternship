//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formInterrupt.h
#if !defined(FORMINTERRUPT_H)
#define FORMINTERRUPT_H
#include "Bx.h"
#include "formInterruptUser.h"
#define FORMINTERRUPT_TEXTLABEL2 1
#define FORMINTERRUPT_TEXTLABEL2_2 2
#define FORMINTERRUPT_TXTALERT 3
#define FORMINTERRUPT_TXTSOLUTION 4
#define FORMINTERRUPT_TXTREASON 5
#define FORMINTERRUPT_CMDCONTINUE 6
extern BX_BOOL formInterrupt_cmdContinue_Click(HBOX hBox);
extern BX_CHAR formInterruptText[][MAXLANGUAGE][255];
extern BOXSTRUCT formInterrupt[];
extern BX_BOOL formInterruptProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formInterruptUpdate(HBOX hBox);
extern BX_VOID formInterruptInit(HBOX hBox);
#endif // FORMINTERRUPT_H
