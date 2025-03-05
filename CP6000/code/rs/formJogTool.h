//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogTool.h
#if !defined(FORMJOGTOOL_H)
#define FORMJOGTOOL_H
#include "Bx.h"
#include "formJogToolUser.h"
#define FORMJOGTOOL_GROUPBOX2 1
#define FORMJOGTOOL_TEXTLABELSTEPMM 2
#define FORMJOGTOOL_CMDSTEPMM 3
extern BX_BOOL formJogTool_cmdStepMM_Click(HBOX hBox);
#define FORMJOGTOOL_CMDZRIGHT 4
extern BX_BOOL formJogTool_cmdZRight_Click(HBOX hBox);
#define FORMJOGTOOL_CMDZLEFT 5
extern BX_BOOL formJogTool_cmdZLeft_Click(HBOX hBox);
#define FORMJOGTOOL_CMDDOWN 6
extern BX_BOOL formJogTool_cmdDown_Click(HBOX hBox);
#define FORMJOGTOOL_CMDIN 7
extern BX_BOOL formJogTool_cmdIn_Click(HBOX hBox);
#define FORMJOGTOOL_CMDOUT 8
extern BX_BOOL formJogTool_cmdOut_Click(HBOX hBox);
#define FORMJOGTOOL_CMDUP 9
extern BX_BOOL formJogTool_cmdUp_Click(HBOX hBox);
#define FORMJOGTOOL_GROUPBOX1 10
#define FORMJOGTOOL_CMDRESETTURNTILT 11
extern BX_BOOL formJogTool_cmdResetTurnTilt_Click(HBOX hBox);
#define FORMJOGTOOL_CMDSTEPDEG 12
extern BX_BOOL formJogTool_cmdStepDeg_Click(HBOX hBox);
#define FORMJOGTOOL_TEXTLABELSTEPDEG 13
#define FORMJOGTOOL_TEXTLABELTURN 14
#define FORMJOGTOOL_TEXTLABELTILT 15
#define FORMJOGTOOL_CMDTILTLEFT 16
extern BX_BOOL formJogTool_cmdTiltLeft_Click(HBOX hBox);
#define FORMJOGTOOL_CMDTURNLEFT 17
extern BX_BOOL formJogTool_cmdTurnLeft_Click(HBOX hBox);
#define FORMJOGTOOL_CMDTURNRIGHT 18
extern BX_BOOL formJogTool_cmdTurnRight_Click(HBOX hBox);
#define FORMJOGTOOL_CMDTILTRIGHT 19
extern BX_BOOL formJogTool_cmdTiltRight_Click(HBOX hBox);
#define FORMJOGTOOL_CMDCANCEL 20
extern BX_BOOL formJogTool_cmdCancel_Click(HBOX hBox);
#define FORMJOGTOOL_CMDJOGSPEED 21
extern BX_BOOL formJogTool_cmdJogSpeed_Click(HBOX hBox);
#define FORMJOGTOOL_CMDRELEASE 22
extern BX_BOOL formJogTool_cmdRelease_Click(HBOX hBox);
#define FORMJOGTOOL_TEXTLABELSPEED 23
extern BX_CHAR formJogToolText[][MAXLANGUAGE][255];
extern BOXSTRUCT formJogTool[];
extern BX_BOOL formJogToolProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formJogToolUpdate(HBOX hBox);
extern BX_VOID formJogToolInit(HBOX hBox);
#endif // FORMJOGTOOL_H
