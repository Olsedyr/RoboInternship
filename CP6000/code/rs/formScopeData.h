//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formScopeData.h
#if !defined(FORMSCOPEDATA_H)
#define FORMSCOPEDATA_H
#include "Bx.h"
#include "formScopeDataUser.h"
#define FORMSCOPEDATA_CMDMENU 1
extern BX_BOOL formScopeData_cmdMenu_Click(HBOX hBox);
#define FORMSCOPEDATA_SCROLLBAR1 2
extern BX_BOOL formScopeData_scrollBar1_Click(HBOX hBox);
#define FORMSCOPEDATA_TEXT 3
#define FORMSCOPEDATA_TEXTLABEL2 4
#define FORMSCOPEDATA_CMDINDEX 5
extern BX_BOOL formScopeData_cmdIndex_Click(HBOX hBox);
#define FORMSCOPEDATA_CAPTURE 6
extern BX_BOOL formScopeData_Capture_Click(HBOX hBox);
#define FORMSCOPEDATA_TEXTLABEL1 7
#define FORMSCOPEDATA_FT 8
extern BX_BOOL formScopeData_FT_Click(HBOX hBox);
#define FORMSCOPEDATA_TEXTLABEL4 9
#define FORMSCOPEDATA_TEXTLABEL3 10
#define FORMSCOPEDATA_DT 11
extern BX_BOOL formScopeData_DT_Click(HBOX hBox);
#define FORMSCOPEDATA_DATA 12
extern BX_CHAR formScopeDataText[][MAXLANGUAGE][255];
extern BOXSTRUCT formScopeData[];
extern BX_BOOL formScopeDataProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formScopeDataUpdate(HBOX hBox);
extern BX_VOID formScopeDataInit(HBOX hBox);
#endif // FORMSCOPEDATA_H
