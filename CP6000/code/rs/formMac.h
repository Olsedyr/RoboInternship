//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMac.h
#if !defined(FORMMAC_H)
#define FORMMAC_H
#include "Bx.h"
#include "formMacUser.h"
#define FORMMAC_CMDCLOSE 1
extern BX_BOOL formMac_cmdClose_Click(HBOX hBox);
#define FORMMAC_LABMODNAME 2
#define FORMMAC_LABMODNAME_3 3
#define FORMMAC_LABMODNAME_2_2 4
#define FORMMAC_LABMODNAME_2 5
#define FORMMAC_LISTBOXIN 6
extern BX_BOOL formMac_listBoxIn_Click(HBOX hBox);
#define FORMMAC_LISTBOXINIT 7
extern BX_BOOL formMac_listBoxInit_Click(HBOX hBox);
#define FORMMAC_LISTBOXOUT 8
extern BX_BOOL formMac_listBoxOut_Click(HBOX hBox);
extern BX_CHAR formMacText[][MAXLANGUAGE][255];
extern BOXSTRUCT formMac[];
extern BX_BOOL formMacProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formMacUpdate(HBOX hBox);
extern BX_VOID formMacInit(HBOX hBox);
#endif // FORMMAC_H
