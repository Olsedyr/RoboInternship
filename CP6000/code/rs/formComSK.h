//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formComSK.h
#if !defined(FORMCOMSK_H)
#define FORMCOMSK_H
#include "Bx.h"
#include "formComSKUser.h"
#define FORMCOMSK_LABMODNAME_2_2 1
#define FORMCOMSK_LABMODNAME_2 2
#define FORMCOMSK_LABMODNAME 3
#define FORMCOMSK_CMDCLOSE 4
extern BX_BOOL formComSK_cmdClose_Click(HBOX hBox);
#define FORMCOMSK_LABMODNAME_3 5
#define FORMCOMSK_LISTBOXIN 6
extern BX_BOOL formComSK_listBoxIn_Click(HBOX hBox);
#define FORMCOMSK_LISTBOXOUT 7
extern BX_BOOL formComSK_listBoxOut_Click(HBOX hBox);
#define FORMCOMSK_LISTBOXINIT 8
extern BX_BOOL formComSK_listBoxInit_Click(HBOX hBox);
extern BX_CHAR formComSKText[][MAXLANGUAGE][255];
extern BOXSTRUCT formComSK[];
extern BX_BOOL formComSKProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formComSKUpdate(HBOX hBox);
extern BX_VOID formComSKInit(HBOX hBox);
#endif // FORMCOMSK_H
