//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditBoxPattern.h
#if !defined(FORMEDITBOXPATTERN_H)
#define FORMEDITBOXPATTERN_H
#include "Bx.h"
#include "formEditBoxPatternUser.h"
#define FORMEDITBOXPATTERN_LABVIEW 1
#define FORMEDITBOXPATTERN_GROUPBOXITEM 2
#define FORMEDITBOXPATTERN_LABITEM 3
#define FORMEDITBOXPATTERN_CMDITEMPREV 4
extern BX_BOOL formEditBoxPattern_cmdItemPrev_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDITEMNEXT 5
extern BX_BOOL formEditBoxPattern_cmdItemNext_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_GROUPBOXINDEX 6
#define FORMEDITBOXPATTERN_CMDINDEXNEXT 7
extern BX_BOOL formEditBoxPattern_cmdIndexNext_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDINDEXPREV 8
extern BX_BOOL formEditBoxPattern_cmdIndexPrev_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDINDEX 9
extern BX_BOOL formEditBoxPattern_cmdIndex_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_GROUPBOXPATTERN 10
#define FORMEDITBOXPATTERN_CMDPATTERNNEXT 11
extern BX_BOOL formEditBoxPattern_cmdPatternNext_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_LABPATTERN 12
#define FORMEDITBOXPATTERN_CMDPATTERNPREV 13
extern BX_BOOL formEditBoxPattern_cmdPatternPrev_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_GROUPBOXPOSITION 14
#define FORMEDITBOXPATTERN_TEXTLABEL4 15
#define FORMEDITBOXPATTERN_TEXTLABEL3 16
#define FORMEDITBOXPATTERN_TEXTLABEL2 17
#define FORMEDITBOXPATTERN_TEXTLABEL1 18
#define FORMEDITBOXPATTERN_TEXTLABEL 19
#define FORMEDITBOXPATTERN_TEXTLABEL_2 20
#define FORMEDITBOXPATTERN_CMDX 21
extern BX_BOOL formEditBoxPattern_cmdX_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDY 22
extern BX_BOOL formEditBoxPattern_cmdY_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDZ 23
extern BX_BOOL formEditBoxPattern_cmdZ_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDV 24
extern BX_BOOL formEditBoxPattern_cmdV_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDW 25
extern BX_BOOL formEditBoxPattern_cmdW_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDLAYER 26
extern BX_BOOL formEditBoxPattern_cmdLayer_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDSAVE 27
extern BX_BOOL formEditBoxPattern_cmdSave_Click(HBOX hBox);
#define FORMEDITBOXPATTERN_CMDCANCEL 28
extern BX_BOOL formEditBoxPattern_cmdCancel_Click(HBOX hBox);
extern BX_CHAR formEditBoxPatternText[][MAXLANGUAGE][255];
extern BOXSTRUCT formEditBoxPattern[];
extern BX_BOOL formEditBoxPatternProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formEditBoxPatternUpdate(HBOX hBox);
extern BX_VOID formEditBoxPatternInit(HBOX hBox);
#endif // FORMEDITBOXPATTERN_H
