//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditTcp.h
#if !defined(FORMEDITTCP_H)
#define FORMEDITTCP_H
#include "Bx.h"
#include "formEditTcpUser.h"
#define FORMEDITTCP_TEXTLABEL2_2 1
#define FORMEDITTCP_CMDCANCEL 2
extern BX_BOOL formEditTcp_cmdCancel_Click(HBOX hBox);
#define FORMEDITTCP_CMDRETURN 3
extern BX_BOOL formEditTcp_cmdReturn_Click(HBOX hBox);
#define FORMEDITTCP_GROUPBOX1 4
#define FORMEDITTCP_TEXTLABEL2_5_2 5
#define FORMEDITTCP_CMDEROFF 6
extern BX_BOOL formEditTcp_cmdEROff_Click(HBOX hBox);
#define FORMEDITTCP_CMDDROFF 7
extern BX_BOOL formEditTcp_cmdDROff_Click(HBOX hBox);
#define FORMEDITTCP_CMDCROFF 8
extern BX_BOOL formEditTcp_cmdCROff_Click(HBOX hBox);
#define FORMEDITTCP_CMDBROFF 9
extern BX_BOOL formEditTcp_cmdBROff_Click(HBOX hBox);
#define FORMEDITTCP_CMDAROFF 10
extern BX_BOOL formEditTcp_cmdAROff_Click(HBOX hBox);
#define FORMEDITTCP_CMDACOFF 11
extern BX_BOOL formEditTcp_cmdACOff_Click(HBOX hBox);
#define FORMEDITTCP_CMDBCOFF 12
extern BX_BOOL formEditTcp_cmdBCOff_Click(HBOX hBox);
#define FORMEDITTCP_CMDCCOFF 13
extern BX_BOOL formEditTcp_cmdCCOff_Click(HBOX hBox);
#define FORMEDITTCP_CMDDCOFF 14
extern BX_BOOL formEditTcp_cmdDCOff_Click(HBOX hBox);
#define FORMEDITTCP_CMDECOFF 15
extern BX_BOOL formEditTcp_cmdECOff_Click(HBOX hBox);
#define FORMEDITTCP_TEXTLABEL2 16
#define FORMEDITTCP_TEXTLABEL2_2_2_2_3_2 17
#define FORMEDITTCP_TEXTLABEL2_2_2_2_3_3 18
#define FORMEDITTCP_TEXTLABEL2_3 19
#define FORMEDITTCP_TEXTLABEL2_4 20
#define FORMEDITTCP_TEXTLABEL2_5_2_2 21
extern BX_CHAR formEditTcpText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEditTcp[];
extern BX_BOOL formEditTcpProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEditTcpUpdate(HBOX hBox);
extern BX_VOID formEditTcpInit(HBOX hBox);
#endif // FORMEDITTCP_H
