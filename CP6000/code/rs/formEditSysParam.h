//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditSysParam.h
#if !defined(FORMEDITSYSPARAM_H)
#define FORMEDITSYSPARAM_H
#include "Bx.h"
#include "formEditSysParamUser.h"
#define FORMEDITSYSPARAM_TEXTLABEL2_2 1
#define FORMEDITSYSPARAM_CMDRETURN 2
extern BX_BOOL formEditSysParam_cmdReturn_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDCANCEL 3
extern BX_BOOL formEditSysParam_cmdCancel_Click(HBOX hBox);
#define FORMEDITSYSPARAM_GROUPBOX1 4
#define FORMEDITSYSPARAM_TEXTLABEL2_4 5
#define FORMEDITSYSPARAM_CMDCMIN 6
extern BX_BOOL formEditSysParam_cmdCMin_Click(HBOX hBox);
#define FORMEDITSYSPARAM_TEXTLABEL2_3 7
#define FORMEDITSYSPARAM_CMDBMIN 8
extern BX_BOOL formEditSysParam_cmdBMin_Click(HBOX hBox);
#define FORMEDITSYSPARAM_TEXTLABEL2_2_2_2_3_3 9
#define FORMEDITSYSPARAM_CMDEMIN 10
extern BX_BOOL formEditSysParam_cmdEMin_Click(HBOX hBox);
#define FORMEDITSYSPARAM_TEXTLABEL2_2_2_2_3_2 11
#define FORMEDITSYSPARAM_CMDAMIN 12
extern BX_BOOL formEditSysParam_cmdAMin_Click(HBOX hBox);
#define FORMEDITSYSPARAM_TEXTLABEL2 13
#define FORMEDITSYSPARAM_CMDDMIN 14
extern BX_BOOL formEditSysParam_cmdDMin_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDAMAX 15
extern BX_BOOL formEditSysParam_cmdAMax_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDBMAX 16
extern BX_BOOL formEditSysParam_cmdBMax_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDCMAX 17
extern BX_BOOL formEditSysParam_cmdCMax_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDDMAX 18
extern BX_BOOL formEditSysParam_cmdDMax_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDEMAX 19
extern BX_BOOL formEditSysParam_cmdEMax_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDBCOFF 20
extern BX_BOOL formEditSysParam_cmdBCOff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDCCOFF 21
extern BX_BOOL formEditSysParam_cmdCCOff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDDCOFF 22
extern BX_BOOL formEditSysParam_cmdDCOff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDECOFF 23
extern BX_BOOL formEditSysParam_cmdECOff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDACOFF 24
extern BX_BOOL formEditSysParam_cmdACOff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDBROFF 25
extern BX_BOOL formEditSysParam_cmdBROff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDCROFF 26
extern BX_BOOL formEditSysParam_cmdCROff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDEROFF 27
extern BX_BOOL formEditSysParam_cmdEROff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDAROFF 28
extern BX_BOOL formEditSysParam_cmdAROff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_CMDDROFF 29
extern BX_BOOL formEditSysParam_cmdDROff_Click(HBOX hBox);
#define FORMEDITSYSPARAM_TEXTLABEL2_5_2 30
#define FORMEDITSYSPARAM_TEXTLABEL2_5_2_2 31
#define FORMEDITSYSPARAM_TEXTLABEL2_5 32
#define FORMEDITSYSPARAM_TEXTLABEL2_6 33
extern BX_CHAR formEditSysParamText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEditSysParam[];
extern BX_BOOL formEditSysParamProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEditSysParamUpdate(HBOX hBox);
extern BX_VOID formEditSysParamInit(HBOX hBox);
#endif // FORMEDITSYSPARAM_H
