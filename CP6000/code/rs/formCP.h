//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCP.h
#if !defined(FORMCP_H)
#define FORMCP_H
#include "Bx.h"
#include "formCPUser.h"
#define FORMCP_TEXTLABEL2_2 1
#define FORMCP_CMDRUN 2
extern BX_BOOL formCP_cmdRun_Click(HBOX hBox);
#define FORMCP_CMDSTOP 3
extern BX_BOOL formCP_cmdStop_Click(HBOX hBox);
#define FORMCP_CMDMENU 4
extern BX_BOOL formCP_cmdMenu_Click(HBOX hBox);
#define FORMCP_TEXTLABEL1 5
#define FORMCP_GROUPBOX1_2_2 6
#define FORMCP_LABWORKCELLSTATE 7
#define FORMCP_LABINFO 8
#define FORMCP_LABERROR2 9
#define FORMCP_LABERROR1 10
#define FORMCP_LABTIME 11
#define FORMCP_LABPRODPERMIN 12
#define FORMCP_LAB1_4 13
extern BX_CHAR formCPText[][MAXLANGUAGE][255];
extern BOXSTRUCT formCP[];
extern BX_BOOL formCPProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formCPUpdate(HBOX hBox);
extern BX_VOID formCPInit(HBOX hBox);
#endif // FORMCP_H
