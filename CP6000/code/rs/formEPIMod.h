//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEPIMod.h
#if !defined(FORMEPIMOD_H)
#define FORMEPIMOD_H
#include "Bx.h"
#include "formEPIModUser.h"
#define FORMEPIMOD_CMDCLOSE 1
extern BX_BOOL formEPIMod_cmdClose_Click(HBOX hBox);
#define FORMEPIMOD_LABCONNECT2 2
#define FORMEPIMOD_LABCONNECT3 3
#define FORMEPIMOD_LABCONNECT4 4
#define FORMEPIMOD_LABMODNAME 5
#define FORMEPIMOD_LABTYPE 6
#define FORMEPIMOD_LABCONNECT1 7
#define FORMEPIMOD_LABSTATE1 8
#define FORMEPIMOD_LABSTATE2 9
#define FORMEPIMOD_LABSTATE3 10
#define FORMEPIMOD_LABSTATE4 11
#define FORMEPIMOD_TEXTLABEL2_2_2_2 12
#define FORMEPIMOD_TEXTLABEL2_2_2_2_2 13
#define FORMEPIMOD_TEXTLABEL2_2_2_2_3 14
#define FORMEPIMOD_TEXTLABEL2_2_2_2_4 15
#define FORMEPIMOD_CHKSTATE1 16
extern BX_BOOL formEPIMod_chkState1_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE1_2 17
extern BX_BOOL formEPIMod_chkState1_2_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE2 18
extern BX_BOOL formEPIMod_chkState2_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE2_2 19
extern BX_BOOL formEPIMod_chkState2_2_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE3 20
extern BX_BOOL formEPIMod_chkState3_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE3_2 21
extern BX_BOOL formEPIMod_chkState3_2_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE4 22
extern BX_BOOL formEPIMod_chkState4_Click(HBOX hBox);
#define FORMEPIMOD_CHKSTATE4_2 23
extern BX_BOOL formEPIMod_chkState4_2_Click(HBOX hBox);
#define FORMEPIMOD_TEXTLABEL2_2_2 24
#define FORMEPIMOD_TEXTLABEL2_2_2_3 25
#define FORMEPIMOD_TEXTLABEL2_2_2_3_2 26
extern BX_CHAR formEPIModText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEPIMod[];
extern BX_BOOL formEPIModProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEPIModUpdate(HBOX hBox);
extern BX_VOID formEPIModInit(HBOX hBox);
#endif // FORMEPIMOD_H
