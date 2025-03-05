//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formAdjBoxFrames.h
#if !defined(FORMADJBOXFRAMES_H)
#define FORMADJBOXFRAMES_H
#include "Bx.h"
#include "formAdjBoxFramesUser.h"
#define FORMADJBOXFRAMES_TEXTLABEL2_2 1
#define FORMADJBOXFRAMES_CMDMENU 2
extern BX_BOOL formAdjBoxFrames_cmdMenu_Click(HBOX hBox);
#define FORMADJBOXFRAMES_LISTBOX 3
extern BX_BOOL formAdjBoxFrames_listBox_Click(HBOX hBox);
extern BX_CHAR formAdjBoxFramesText[][MAXLANGUAGE][255];
extern BOXSTRUCT formAdjBoxFrames[];
extern BX_BOOL formAdjBoxFramesProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formAdjBoxFramesUpdate(HBOX hBox);
extern BX_VOID formAdjBoxFramesInit(HBOX hBox);
#endif // FORMADJBOXFRAMES_H
