//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDDOMod.h
#if !defined(FORMDDOMOD_H)
#define FORMDDOMOD_H
#include "Bx.h"
#include "formDDOModUser.h"
#define FORMDDOMOD_CMDCLOSE 1
extern BX_BOOL formDDOMod_cmdClose_Click(HBOX hBox);
#define FORMDDOMOD_LABCONNECT2 2
#define FORMDDOMOD_LABCONNECT3 3
#define FORMDDOMOD_LABCONNECT4 4
#define FORMDDOMOD_LABCONNECT5 5
#define FORMDDOMOD_LABCONNECT6 6
#define FORMDDOMOD_TEXTLABEL2_2_2_2 7
#define FORMDDOMOD_TEXTLABEL2_2_2_2_2 8
#define FORMDDOMOD_TEXTLABEL2_2_2_2_3 9
#define FORMDDOMOD_TEXTLABEL2_2_2_2_4 10
#define FORMDDOMOD_TEXTLABEL2_2_2_2_5 11
#define FORMDDOMOD_TEXTLABEL2_2_2_2_6 12
#define FORMDDOMOD_TEXTLABEL2_2_2 13
#define FORMDDOMOD_CHKSTATE2 14
extern BX_BOOL formDDOMod_chkState2_Click(HBOX hBox);
#define FORMDDOMOD_CHKSTATE3 15
extern BX_BOOL formDDOMod_chkState3_Click(HBOX hBox);
#define FORMDDOMOD_CHKSTATE4 16
extern BX_BOOL formDDOMod_chkState4_Click(HBOX hBox);
#define FORMDDOMOD_CHKSTATE5 17
extern BX_BOOL formDDOMod_chkState5_Click(HBOX hBox);
#define FORMDDOMOD_CHKSTATE6 18
extern BX_BOOL formDDOMod_chkState6_Click(HBOX hBox);
#define FORMDDOMOD_CHKSTATE1 19
extern BX_BOOL formDDOMod_chkState1_Click(HBOX hBox);
#define FORMDDOMOD_LABCONNECT1 20
#define FORMDDOMOD_LABMODNAME 21
#define FORMDDOMOD_LABTYPE 22
extern BX_CHAR formDDOModText[][MAXLANGUAGE][255];
extern BOXSTRUCT formDDOMod[];
extern BX_BOOL formDDOModProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formDDOModUpdate(HBOX hBox);
extern BX_VOID formDDOModInit(HBOX hBox);
#endif // FORMDDOMOD_H
