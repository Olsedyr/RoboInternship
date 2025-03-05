//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogIk.h
#if !defined(FORMJOGIK_H)
#define FORMJOGIK_H
#include "Bx.h"
#include "formJogIkUser.h"
#define FORMJOGIK_TEXTLABEL2_2 1
#define FORMJOGIK_TEXTLABEL2_2_2 2
#define FORMJOGIK_CMDJOGSPEED 3
extern BX_BOOL formJogIk_cmdJogSpeed_Click(HBOX hBox);
#define FORMJOGIK_CMDZLEFT 4
extern BX_BOOL formJogIk_cmdZLeft_Click(HBOX hBox);
#define FORMJOGIK_CMDZRIGHT 5
extern BX_BOOL formJogIk_cmdZRight_Click(HBOX hBox);
#define FORMJOGIK_CMDDOWN 6
extern BX_BOOL formJogIk_cmdDown_Click(HBOX hBox);
#define FORMJOGIK_CMDLEFT 7
extern BX_BOOL formJogIk_cmdLeft_Click(HBOX hBox);
#define FORMJOGIK_CMDUP 8
extern BX_BOOL formJogIk_cmdUp_Click(HBOX hBox);
#define FORMJOGIK_CMDRIGHT 9
extern BX_BOOL formJogIk_cmdRight_Click(HBOX hBox);
#define FORMJOGIK_TEXTTILTANGLE 10
#define FORMJOGIK_TEXTLABEL_2_2 11
#define FORMJOGIK_TEXTLABEL_2 12
#define FORMJOGIK_TEXTTURNANGLE 13
#define FORMJOGIK_CMDTILTLEFT 14
extern BX_BOOL formJogIk_cmdTiltLeft_Click(HBOX hBox);
#define FORMJOGIK_CMDTURNRIGHT 15
extern BX_BOOL formJogIk_cmdTurnRight_Click(HBOX hBox);
#define FORMJOGIK_CMDTURNLEFT 16
extern BX_BOOL formJogIk_cmdTurnLeft_Click(HBOX hBox);
#define FORMJOGIK_CMDTILTRIGHT 17
extern BX_BOOL formJogIk_cmdTiltRight_Click(HBOX hBox);
#define FORMJOGIK_TEXCMPOS 18
#define FORMJOGIK_TEXTLABEL2_2_2_2_3 19
#define FORMJOGIK_TEXBMPOS 20
#define FORMJOGIK_TEXTLABEL2_2_2_2_3_2 21
#define FORMJOGIK_TEXAMPOS 22
#define FORMJOGIK_TEXTLABEL2_2_2_2_3_3 23
#define FORMJOGIK_TEXTLABEL2 24
#define FORMJOGIK_CMDIKSTEP 25
extern BX_BOOL formJogIk_cmdIkStep_Click(HBOX hBox);
#define FORMJOGIK_CMDIKTCPIDX 26
extern BX_BOOL formJogIk_cmdIkTcpIdx_Click(HBOX hBox);
#define FORMJOGIK_CMDCANCEL 27
extern BX_BOOL formJogIk_cmdCancel_Click(HBOX hBox);
#define FORMJOGIK_TEXTLABELIKTCPIDX 28
extern BX_CHAR formJogIkText[][MAXLANGUAGE][255];
extern BOXSTRUCT formJogIk[];
extern BX_BOOL formJogIkProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formJogIkUpdate(HBOX hBox);
extern BX_VOID formJogIkInit(HBOX hBox);
#endif // FORMJOGIK_H
