//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditFrame.h
#if !defined(FORMEDITFRAME_H)
#define FORMEDITFRAME_H
#include "Bx.h"
#include "formEditFrameUser.h"
#define FORMEDITFRAME_CMDCANCEL 1
extern BX_BOOL formEditFrame_cmdCancel_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2 2
#define FORMEDITFRAME_CMDW 3
extern BX_BOOL formEditFrame_cmdW_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3_2_2 4
#define FORMEDITFRAME_CMDV 5
extern BX_BOOL formEditFrame_cmdV_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3_2 6
#define FORMEDITFRAME_CMDZ 7
extern BX_BOOL formEditFrame_cmdZ_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3 8
#define FORMEDITFRAME_CMDY 9
extern BX_BOOL formEditFrame_cmdY_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2_2_2_3_2 10
#define FORMEDITFRAME_CMDX 11
extern BX_BOOL formEditFrame_cmdX_Click(HBOX hBox);
#define FORMEDITFRAME_TEXTLABEL2_2_2_2_3 12
#define FORMEDITFRAME_CMDTHISPOS 13
extern BX_BOOL formEditFrame_cmdThisPos_Click(HBOX hBox);
#define FORMEDITFRAME_CMDRETURN 14
extern BX_BOOL formEditFrame_cmdReturn_Click(HBOX hBox);
#define FORMEDITFRAME_CMDCURPOSZ 15
extern BX_BOOL formEditFrame_cmdCurPosZ_Click(HBOX hBox);
#define FORMEDITFRAME_CMDCURPOSY 16
extern BX_BOOL formEditFrame_cmdCurPosY_Click(HBOX hBox);
#define FORMEDITFRAME_CMDCURPOSX 17
extern BX_BOOL formEditFrame_cmdCurPosX_Click(HBOX hBox);
#define FORMEDITFRAME_CMDCURPOSV 18
extern BX_BOOL formEditFrame_cmdCurPosV_Click(HBOX hBox);
#define FORMEDITFRAME_CMDCURPOSW 19
extern BX_BOOL formEditFrame_cmdCurPosW_Click(HBOX hBox);
#define FORMEDITFRAME_GROUPBOX1 20
#define FORMEDITFRAME_TEXTLABELNAME 21
extern BX_CHAR formEditFrameText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEditFrame[];
extern BX_BOOL formEditFrameProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEditFrameUpdate(HBOX hBox);
extern BX_VOID formEditFrameInit(HBOX hBox);
#endif // FORMEDITFRAME_H
