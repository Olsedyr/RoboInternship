//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual321.h
#if !defined(FORMMANUAL321_H)
#define FORMMANUAL321_H
#include "Bx.h"
#include "formManual321User.h"
#define FORMMANUAL321_CMDCANCEL 1
extern BX_BOOL formManual321_cmdCancel_Click(HBOX hBox);
#define FORMMANUAL321_GROUPBOX1 2
#define FORMMANUAL321_CMD4_10REV 3
extern BX_BOOL formManual321_cmd4_10Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_10UP 4
extern BX_BOOL formManual321_cmd4_10Up_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_10CENTER 5
extern BX_BOOL formManual321_cmd4_10Center_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_10FWD 6
extern BX_BOOL formManual321_cmd4_10Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_10DOWN 7
extern BX_BOOL formManual321_cmd4_10Down_Click(HBOX hBox);
#define FORMMANUAL321_GROUPBOX1_2 8
#define FORMMANUAL321_CMD4_7FWD 9
extern BX_BOOL formManual321_cmd4_7Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_7UP 10
extern BX_BOOL formManual321_cmd4_7Up_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_7DOWN 11
extern BX_BOOL formManual321_cmd4_7Down_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_7REV 12
extern BX_BOOL formManual321_cmd4_7Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_7CENTER 13
extern BX_BOOL formManual321_cmd4_7Center_Click(HBOX hBox);
#define FORMMANUAL321_TEXTLABELCARDBOARD 14
#define FORMMANUAL321_TEXTLABELFILLED 15
#define FORMMANUAL321_TEXTLABELFILLED_2 16
#define FORMMANUAL321_GROUPBOX1_2_2 17
#define FORMMANUAL321_CMD4_3UP 18
extern BX_BOOL formManual321_cmd4_3Up_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_3DOWN 19
extern BX_BOOL formManual321_cmd4_3Down_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_3FWD 20
extern BX_BOOL formManual321_cmd4_3Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_3CENTER 21
extern BX_BOOL formManual321_cmd4_3Center_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_3REV 22
extern BX_BOOL formManual321_cmd4_3Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_2FWD 23
extern BX_BOOL formManual321_cmd4_2Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_2REV 24
extern BX_BOOL formManual321_cmd4_2Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_1REV 25
extern BX_BOOL formManual321_cmd4_1Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_1FWD 26
extern BX_BOOL formManual321_cmd4_1Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_6REV 27
extern BX_BOOL formManual321_cmd4_6Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_6FWD 28
extern BX_BOOL formManual321_cmd4_6Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_5REV 29
extern BX_BOOL formManual321_cmd4_5Rev_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_5FWD 30
extern BX_BOOL formManual321_cmd4_5Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_11FWD 31
extern BX_BOOL formManual321_cmd4_11Fwd_Click(HBOX hBox);
#define FORMMANUAL321_CMD4_12FWD 32
extern BX_BOOL formManual321_cmd4_12Fwd_Click(HBOX hBox);
extern BX_CHAR formManual321Text[][MAXLANGUAGE][255];
extern BOXSTRUCT formManual321[];
extern BX_BOOL formManual321Proc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formManual321Update(HBOX hBox);
extern BX_VOID formManual321Init(HBOX hBox);
#endif // FORMMANUAL321_H
