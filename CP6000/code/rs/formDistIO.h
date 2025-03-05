//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDistIO.h
#if !defined(FORMDISTIO_H)
#define FORMDISTIO_H
#include "Bx.h"
#include "formDistIOUser.h"
#define FORMDISTIO_CMDCLOSE 1
extern BX_BOOL formDistIO_cmdClose_Click(HBOX hBox);
#define FORMDISTIO_TEXTLABEL2_2 2
#define FORMDISTIO_LISTBOX 3
extern BX_BOOL formDistIO_listBox_Click(HBOX hBox);
#define FORMDISTIO_CHKADVANTYS 4
extern BX_BOOL formDistIO_chkAdvantys_Click(HBOX hBox);
#define FORMDISTIO_CHKLOADCELL 5
extern BX_BOOL formDistIO_chkLoadCell_Click(HBOX hBox);
#define FORMDISTIO_CHKCOMSK 6
extern BX_BOOL formDistIO_chkComSK_Click(HBOX hBox);
#define FORMDISTIO_CHKMAC 7
extern BX_BOOL formDistIO_chkMac_Click(HBOX hBox);
#define FORMDISTIO_CHKICPCON 8
extern BX_BOOL formDistIO_chkICPcon_Click(HBOX hBox);
extern BX_CHAR formDistIOText[][MAXLANGUAGE][255];
extern BOXSTRUCT formDistIO[];
extern BX_BOOL formDistIOProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formDistIOUpdate(HBOX hBox);
extern BX_VOID formDistIOInit(HBOX hBox);
#endif // FORMDISTIO_H
