//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formOffsetPath.h
#if !defined(FORMOFFSETPATH_H)
#define FORMOFFSETPATH_H
#include "Bx.h"
#include "formOffsetPathUser.h"
#define FORMOFFSETPATH_TEXTLABEL2_2 1
#define FORMOFFSETPATH_CMDCANCEL 2
extern BX_BOOL formOffsetPath_cmdCancel_Click(HBOX hBox);
#define FORMOFFSETPATH_CMDRETURN 3
extern BX_BOOL formOffsetPath_cmdReturn_Click(HBOX hBox);
#define FORMOFFSETPATH_CMDJOGIK 4
extern BX_BOOL formOffsetPath_cmdJogIk_Click(HBOX hBox);
#define FORMOFFSETPATH_CMDZ 5
extern BX_BOOL formOffsetPath_cmdZ_Click(HBOX hBox);
#define FORMOFFSETPATH_CMDX 6
extern BX_BOOL formOffsetPath_cmdX_Click(HBOX hBox);
#define FORMOFFSETPATH_CMDV 7
extern BX_BOOL formOffsetPath_cmdV_Click(HBOX hBox);
#define FORMOFFSETPATH_TEXTLABEL_2_2 8
#define FORMOFFSETPATH_TEXTLABEL2_2_2_2_3_3 9
#define FORMOFFSETPATH_TEXTLABEL_2 10
#define FORMOFFSETPATH_TEXTLABEL2_2_2_2_3 11
#define FORMOFFSETPATH_CMDY 12
extern BX_BOOL formOffsetPath_cmdY_Click(HBOX hBox);
#define FORMOFFSETPATH_TEXTLABEL2_2_2_2_3_2 13
#define FORMOFFSETPATH_CMDW 14
extern BX_BOOL formOffsetPath_cmdW_Click(HBOX hBox);
extern BX_CHAR formOffsetPathText[][MAXLANGUAGE][255];
extern BOXSTRUCT formOffsetPath[];
extern BX_BOOL formOffsetPathProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formOffsetPathUpdate(HBOX hBox);
extern BX_VOID formOffsetPathInit(HBOX hBox);
#endif // FORMOFFSETPATH_H
