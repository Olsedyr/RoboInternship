//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual320.h
#if !defined(FORMMANUAL320_H)
#define FORMMANUAL320_H
#include "Bx.h"
#include "formManual320User.h"
#define FORMMANUAL320_CMDCANCEL 1
extern BX_BOOL formManual320_cmdCancel_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_1FWD 2
extern BX_BOOL formManual320_cmd3_1Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_9FWD 3
extern BX_BOOL formManual320_cmd3_9Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_8FWD 4
extern BX_BOOL formManual320_cmd3_8Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_2FWD 5
extern BX_BOOL formManual320_cmd3_2Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_2REV 6
extern BX_BOOL formManual320_cmd3_2Rev_Click(HBOX hBox);
#define FORMMANUAL320_GROUPBOX1 7
#define FORMMANUAL320_CMD3_6REV 8
extern BX_BOOL formManual320_cmd3_6Rev_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_6FWD 9
extern BX_BOOL formManual320_cmd3_6Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_6UP 10
extern BX_BOOL formManual320_cmd3_6Up_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_6CENTER 11
extern BX_BOOL formManual320_cmd3_6Center_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_6DOWN 12
extern BX_BOOL formManual320_cmd3_6Down_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_1REV 13
extern BX_BOOL formManual320_cmd3_1Rev_Click(HBOX hBox);
#define FORMMANUAL320_TEXTLABELFILLED 14
#define FORMMANUAL320_GROUPBOX1_2 15
#define FORMMANUAL320_CMD3_3REV 16
extern BX_BOOL formManual320_cmd3_3Rev_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_3CENTER 17
extern BX_BOOL formManual320_cmd3_3Center_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_3UP 18
extern BX_BOOL formManual320_cmd3_3Up_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_3FWD 19
extern BX_BOOL formManual320_cmd3_3Fwd_Click(HBOX hBox);
#define FORMMANUAL320_CMD3_3DOWN 20
extern BX_BOOL formManual320_cmd3_3Down_Click(HBOX hBox);
#define FORMMANUAL320_TEXTLABELCARDBOARD 21
extern BX_CHAR formManual320Text[][MAXLANGUAGE][255];
extern BOXSTRUCT formManual320[];
extern BX_BOOL formManual320Proc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formManual320Update(HBOX hBox);
extern BX_VOID formManual320Init(HBOX hBox);
#endif // FORMMANUAL320_H
