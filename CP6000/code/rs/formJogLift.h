//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogLift.h
#if !defined(FORMJOGLIFT_H)
#define FORMJOGLIFT_H
#include "Bx.h"
#include "formJogLiftUser.h"
#define FORMJOGLIFT_CMDUP 1
extern BX_BOOL formJogLift_cmdUp_Click(HBOX hBox);
#define FORMJOGLIFT_CMDDOWN 2
extern BX_BOOL formJogLift_cmdDown_Click(HBOX hBox);
#define FORMJOGLIFT_CMDSTEP 3
extern BX_BOOL formJogLift_cmdStep_Click(HBOX hBox);
#define FORMJOGLIFT_CMDCANCEL 4
extern BX_BOOL formJogLift_cmdCancel_Click(HBOX hBox);
#define FORMJOGLIFT_VALUELABELCURPOS 5
#define FORMJOGLIFT_TEXTLABELMESSAGE1 6
#define FORMJOGLIFT_TEXTLABELMESSAGE2 7
#define FORMJOGLIFT_TEXTLABELSTEP 8
#define FORMJOGLIFT_TEXTLABELNAME 9
extern BX_CHAR formJogLiftText[][MAXLANGUAGE][255];
extern BOXSTRUCT formJogLift[];
extern BX_BOOL formJogLiftProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formJogLiftUpdate(HBOX hBox);
extern BX_VOID formJogLiftInit(HBOX hBox);
#endif // FORMJOGLIFT_H
