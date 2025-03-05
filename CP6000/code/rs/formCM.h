//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCM.h
#if !defined(FORMCM_H)
#define FORMCM_H
#include "Bx.h"
#include "formCMUser.h"
#define FORMCM_TEXTLABEL1 1
#define FORMCM_GROUPBOX1_2_2 2
#define FORMCM_LABTIME 3
#define FORMCM_LABERROR2 4
#define FORMCM_LABERROR1 5
#define FORMCM_LABWORKCELLSTATE 6
#define FORMCM_LABINFO 7
#define FORMCM_LABPRODPERMIN 8
#define FORMCM_LABCASECOUNT 9
#define FORMCM_LAB1_4 10
#define FORMCM_LABHEAD 11
#define FORMCM_CMDRUN 12
extern BX_BOOL formCM_cmdRun_Click(HBOX hBox);
#define FORMCM_CMDSTOP 13
extern BX_BOOL formCM_cmdStop_Click(HBOX hBox);
#define FORMCM_CMDMENU 14
extern BX_BOOL formCM_cmdMenu_Click(HBOX hBox);
extern BX_CHAR formCMText[][MAXLANGUAGE][255];
extern BOXSTRUCT formCM[];
extern BX_BOOL formCMProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formCMUpdate(HBOX hBox);
extern BX_VOID formCMInit(HBOX hBox);
#endif // FORMCM_H
