//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSetIO.h
#if !defined(FORMSETIO_H)
#define FORMSETIO_H
#include "Bx.h"
#include "formSetIOUser.h"
#define FORMSETIO_TEXTLABEL2_2 1
#define FORMSETIO_CMDRETURN 2
extern BX_BOOL formSetIO_cmdReturn_Click(HBOX hBox);
#define FORMSETIO_CHECK_9 3
extern BX_BOOL formSetIO_check_9_Click(HBOX hBox);
#define FORMSETIO_CHECK_10 4
extern BX_BOOL formSetIO_check_10_Click(HBOX hBox);
#define FORMSETIO_CHECK_11 5
extern BX_BOOL formSetIO_check_11_Click(HBOX hBox);
#define FORMSETIO_CHECK_12 6
extern BX_BOOL formSetIO_check_12_Click(HBOX hBox);
#define FORMSETIO_CHECK_13 7
extern BX_BOOL formSetIO_check_13_Click(HBOX hBox);
#define FORMSETIO_CHECK_14 8
extern BX_BOOL formSetIO_check_14_Click(HBOX hBox);
#define FORMSETIO_CHECK_15 9
extern BX_BOOL formSetIO_check_15_Click(HBOX hBox);
#define FORMSETIO_CHECK_16 10
extern BX_BOOL formSetIO_check_16_Click(HBOX hBox);
#define FORMSETIO_CHECK_8 11
extern BX_BOOL formSetIO_check_8_Click(HBOX hBox);
#define FORMSETIO_CHECK_7 12
extern BX_BOOL formSetIO_check_7_Click(HBOX hBox);
#define FORMSETIO_CHECK_6 13
extern BX_BOOL formSetIO_check_6_Click(HBOX hBox);
#define FORMSETIO_CHECK_5 14
extern BX_BOOL formSetIO_check_5_Click(HBOX hBox);
#define FORMSETIO_CHECK_4 15
extern BX_BOOL formSetIO_check_4_Click(HBOX hBox);
#define FORMSETIO_CHECK_3 16
extern BX_BOOL formSetIO_check_3_Click(HBOX hBox);
#define FORMSETIO_CHECK_2 17
extern BX_BOOL formSetIO_check_2_Click(HBOX hBox);
#define FORMSETIO_CHECK_1 18
extern BX_BOOL formSetIO_check_1_Click(HBOX hBox);
extern BX_CHAR formSetIOText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSetIO[];
extern BX_BOOL formSetIOProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSetIOUpdate(HBOX hBox);
extern BX_VOID formSetIOInit(HBOX hBox);
#endif // FORMSETIO_H
