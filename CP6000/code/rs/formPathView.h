//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathView.h
#if !defined(FORMPATHVIEW_H)
#define FORMPATHVIEW_H
#include "Bx.h"
#include "formPathViewUser.h"
#define FORMPATHVIEW_CMDPREV 1
extern BX_BOOL formPathView_cmdPrev_Click(HBOX hBox);
#define FORMPATHVIEW_TEXTLABEL2_2 2
#define FORMPATHVIEW_CMDNEXT 3
extern BX_BOOL formPathView_cmdNext_Click(HBOX hBox);
#define FORMPATHVIEW_LABVIEW 4
#define FORMPATHVIEW_GROUPBOX1 5
#define FORMPATHVIEW_SCROLLTAN1 6
extern BX_BOOL formPathView_scrollTan1_Click(HBOX hBox);
#define FORMPATHVIEW_SCROLLTAN2 7
extern BX_BOOL formPathView_scrollTan2_Click(HBOX hBox);
#define FORMPATHVIEW_CMDMENU 8
extern BX_BOOL formPathView_cmdMenu_Click(HBOX hBox);
#define FORMPATHVIEW_RADIOYZ 9
extern BX_BOOL formPathView_radioYZ_Click(HBOX hBox);
#define FORMPATHVIEW_RADIOXY 10
extern BX_BOOL formPathView_radioXY_Click(HBOX hBox);
#define FORMPATHVIEW_RADIOXZ 11
extern BX_BOOL formPathView_radioXZ_Click(HBOX hBox);
extern BX_CHAR formPathViewText[][MAXLANGUAGE][255];
extern BOXSTRUCT formPathView[];
extern BX_BOOL formPathViewProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formPathViewUpdate(HBOX hBox);
extern BX_VOID formPathViewInit(HBOX hBox);
#endif // FORMPATHVIEW_H
