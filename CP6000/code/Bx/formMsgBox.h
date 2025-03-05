//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMsgBox.h
#if !defined(FORMMSGBOX_H)
#define FORMMSGBOX_H
#include "Bx.h"
#include "formMsgBoxUser.h"
#define FORMMSGBOX_CMDCANCEL 1
extern BX_BOOL formMsgBox_cmdCancel_Click(HBOX hBox);
#define FORMMSGBOX_CMDOK 2
extern BX_BOOL formMsgBox_cmdOk_Click(HBOX hBox);
#define FORMMSGBOX_TEXTCAPTION 3
#define FORMMSGBOX_TEXTLABEL2 4
#define FORMMSGBOX_TEXTMSGTEXT 5
#define FORMMSGBOX_TEXTMSGTEXT_2 6
#define FORMMSGBOX_TEXTMSGTEXT_3 7
extern BX_CHAR formMsgBoxText[][MAXLANGUAGE][255];
extern BOXSTRUCT formMsgBox[];
extern BX_BOOL formMsgBoxProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formMsgBoxUpdate(HBOX hBox);
extern BX_VOID formMsgBoxInit(HBOX hBox);
#endif // FORMMSGBOX_H
