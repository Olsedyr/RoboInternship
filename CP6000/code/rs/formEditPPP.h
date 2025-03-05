//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditPPP.h
#if !defined(FORMEDITPPP_H)
#define FORMEDITPPP_H
#include "Bx.h"
#include "formEditPPPUser.h"
#define FORMEDITPPP_CMDCANCEL 1
extern BX_BOOL formEditPPP_cmdCancel_Click(HBOX hBox);
#define FORMEDITPPP_CMDRETURN 2
extern BX_BOOL formEditPPP_cmdReturn_Click(HBOX hBox);
#define FORMEDITPPP_TEXTLABEL2_2_2_2_3_3 3
#define FORMEDITPPP_TEXTLABEL2_2_2_2_3_2 4
#define FORMEDITPPP_GROUPBOX1 5
#define FORMEDITPPP_TEXTLABELNAME 6
#define FORMEDITPPP_TEXTLABEL2_2 7
#define FORMEDITPPP_TEXTLABEL2_2_2_2_3 8
#define FORMEDITPPP_CMDPPP 9
extern BX_BOOL formEditPPP_cmdPPP_Click(HBOX hBox);
#define FORMEDITPPP_CMDPACC 10
extern BX_BOOL formEditPPP_cmdPACC_Click(HBOX hBox);
#define FORMEDITPPP_CMDPSPEED 11
extern BX_BOOL formEditPPP_cmdPSPEED_Click(HBOX hBox);
extern BX_CHAR formEditPPPText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEditPPP[];
extern BX_BOOL formEditPPPProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEditPPPUpdate(HBOX hBox);
extern BX_VOID formEditPPPInit(HBOX hBox);
#endif // FORMEDITPPP_H
