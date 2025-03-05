//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCWdata.h
#if !defined(FORMCWDATA_H)
#define FORMCWDATA_H
#include "Bx.h"
#include "formCWdataUser.h"
#define FORMCWDATA_FILTER 1
extern BX_BOOL formCWdata_Filter_Click(HBOX hBox);
#define FORMCWDATA_DATA 2
#define FORMCWDATA_CAPTURE 3
extern BX_BOOL formCWdata_Capture_Click(HBOX hBox);
#define FORMCWDATA_CMDSTARTVALUE 4
extern BX_BOOL formCWdata_cmdStartValue_Click(HBOX hBox);
#define FORMCWDATA_CMDLENGTHVALUE 5
extern BX_BOOL formCWdata_cmdLengthValue_Click(HBOX hBox);
#define FORMCWDATA_CMDMENU 6
extern BX_BOOL formCWdata_cmdMenu_Click(HBOX hBox);
#define FORMCWDATA_TEXT 7
extern BX_CHAR formCWdataText[][MAXLANGUAGE][255];
extern BOXSTRUCT formCWdata[];
extern BX_BOOL formCWdataProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formCWdataUpdate(HBOX hBox);
extern BX_VOID formCWdataInit(HBOX hBox);
#endif // FORMCWDATA_H
