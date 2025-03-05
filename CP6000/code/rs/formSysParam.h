//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSysParam.h
#if !defined(FORMSYSPARAM_H)
#define FORMSYSPARAM_H
#include "Bx.h"
#include "formSysParamUser.h"
#define FORMSYSPARAM_TEXTLABEL2_4 1
#define FORMSYSPARAM_CHECKETHERNETVERSION 2
extern BX_BOOL formSysParam_checkEthernetVersion_Click(HBOX hBox);
#define FORMSYSPARAM_CMDRETURN 3
extern BX_BOOL formSysParam_cmdReturn_Click(HBOX hBox);
#define FORMSYSPARAM_CMDCANCEL 4
extern BX_BOOL formSysParam_cmdCancel_Click(HBOX hBox);
extern BX_CHAR formSysParamText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSysParam[];
extern BX_BOOL formSysParamProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSysParamUpdate(HBOX hBox);
extern BX_VOID formSysParamInit(HBOX hBox);
#endif // FORMSYSPARAM_H
