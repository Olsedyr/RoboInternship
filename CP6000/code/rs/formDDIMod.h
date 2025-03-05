//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDDIMod.h
#if !defined(FORMDDIMOD_H)
#define FORMDDIMOD_H
#include "Bx.h"
#include "formDDIModUser.h"
#define FORMDDIMOD_CMDCLOSE 1
extern BX_BOOL formDDIMod_cmdClose_Click(HBOX hBox);
#define FORMDDIMOD_LABCONNECT1 2
#define FORMDDIMOD_LABCONNECT2 3
#define FORMDDIMOD_LABCONNECT3 4
#define FORMDDIMOD_LABCONNECT4 5
#define FORMDDIMOD_LABCONNECT5 6
#define FORMDDIMOD_LABCONNECT6 7
#define FORMDDIMOD_TEXTLABEL2_2_2_2 8
#define FORMDDIMOD_TEXTLABEL2_2_2_2_2 9
#define FORMDDIMOD_TEXTLABEL2_2_2_2_3 10
#define FORMDDIMOD_TEXTLABEL2_2_2_2_4 11
#define FORMDDIMOD_TEXTLABEL2_2_2_2_5 12
#define FORMDDIMOD_TEXTLABEL2_2_2_2_6 13
#define FORMDDIMOD_LABMODNAME 14
#define FORMDDIMOD_TEXTLABEL2_2_2 15
#define FORMDDIMOD_LABTYPE 16
#define FORMDDIMOD_CHKSTATE1 17
extern BX_BOOL formDDIMod_chkState1_Click(HBOX hBox);
#define FORMDDIMOD_CHKSTATE2 18
extern BX_BOOL formDDIMod_chkState2_Click(HBOX hBox);
#define FORMDDIMOD_CHKSTATE3 19
extern BX_BOOL formDDIMod_chkState3_Click(HBOX hBox);
#define FORMDDIMOD_CHKSTATE4 20
extern BX_BOOL formDDIMod_chkState4_Click(HBOX hBox);
#define FORMDDIMOD_CHKSTATE5 21
extern BX_BOOL formDDIMod_chkState5_Click(HBOX hBox);
#define FORMDDIMOD_CHKSTATE6 22
extern BX_BOOL formDDIMod_chkState6_Click(HBOX hBox);
extern BX_CHAR formDDIModText[][MAXLANGUAGE][255];
extern BOXSTRUCT formDDIMod[];
extern BX_BOOL formDDIModProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formDDIModUpdate(HBOX hBox);
extern BX_VOID formDDIModInit(HBOX hBox);
#endif // FORMDDIMOD_H
