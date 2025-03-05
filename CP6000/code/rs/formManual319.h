//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual319.h
#if !defined(FORMMANUAL319_H)
#define FORMMANUAL319_H
#include "Bx.h"
#include "formManual319User.h"
#define FORMMANUAL319_TEXTLABELFILLED 1
#define FORMMANUAL319_CMD2_1REV 2
extern BX_BOOL formManual319_cmd2_1Rev_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_1FWD 3
extern BX_BOOL formManual319_cmd2_1Fwd_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_2FWD 4
extern BX_BOOL formManual319_cmd2_2Fwd_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_2REV 5
extern BX_BOOL formManual319_cmd2_2Rev_Click(HBOX hBox);
#define FORMMANUAL319_CMDCANCEL 6
extern BX_BOOL formManual319_cmdCancel_Click(HBOX hBox);
#define FORMMANUAL319_GROUPBOX1_2_2 7
#define FORMMANUAL319_CMD2_3FWD 8
extern BX_BOOL formManual319_cmd2_3Fwd_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_3REV 9
extern BX_BOOL formManual319_cmd2_3Rev_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_3DOWN 10
extern BX_BOOL formManual319_cmd2_3Down_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_3CENTER 11
extern BX_BOOL formManual319_cmd2_3Center_Click(HBOX hBox);
#define FORMMANUAL319_CMD2_3UP 12
extern BX_BOOL formManual319_cmd2_3Up_Click(HBOX hBox);
extern BX_CHAR formManual319Text[][MAXLANGUAGE][255];
extern BOXSTRUCT formManual319[];
extern BX_BOOL formManual319Proc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formManual319Update(HBOX hBox);
extern BX_VOID formManual319Init(HBOX hBox);
#endif // FORMMANUAL319_H
