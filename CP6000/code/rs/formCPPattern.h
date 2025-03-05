//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCPPattern.h
#if !defined(FORMCPPATTERN_H)
#define FORMCPPATTERN_H
#include "Bx.h"
#include "formCPPatternUser.h"
#define FORMCPPATTERN_CMDADD 1
extern BX_BOOL formCPPattern_cmdAdd_Click(HBOX hBox);
#define FORMCPPATTERN_CMDREMOVE 2
extern BX_BOOL formCPPattern_cmdRemove_Click(HBOX hBox);
#define FORMCPPATTERN_CMDCREATE 3
extern BX_BOOL formCPPattern_cmdCreate_Click(HBOX hBox);
#define FORMCPPATTERN_CMDDELETE 4
extern BX_BOOL formCPPattern_cmdDelete_Click(HBOX hBox);
#define FORMCPPATTERN_CMDEDIT 5
extern BX_BOOL formCPPattern_cmdEdit_Click(HBOX hBox);
#define FORMCPPATTERN_CMDCANCEL 6
extern BX_BOOL formCPPattern_cmdCancel_Click(HBOX hBox);
#define FORMCPPATTERN_CMDOK 7
extern BX_BOOL formCPPattern_cmdOk_Click(HBOX hBox);
#define FORMCPPATTERN_TEXTLABEL2_2 8
#define FORMCPPATTERN_LISTBOX 9
extern BX_BOOL formCPPattern_listBox_Click(HBOX hBox);
extern BX_CHAR formCPPatternText[][MAXLANGUAGE][255];
extern BOXSTRUCT formCPPattern[];
extern BX_BOOL formCPPatternProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formCPPatternUpdate(HBOX hBox);
extern BX_VOID formCPPatternInit(HBOX hBox);
#endif // FORMCPPATTERN_H
