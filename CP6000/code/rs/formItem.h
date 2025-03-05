//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItem.h
#if !defined(FORMITEM_H)
#define FORMITEM_H
#include "Bx.h"
#include "formItemUser.h"
#define FORMITEM_TEXTLABEL2_2 1
#define FORMITEM_LISTBOX 2
extern BX_BOOL formItem_listBox_Click(HBOX hBox);
#define FORMITEM_CMDCREATE 3
extern BX_BOOL formItem_cmdCreate_Click(HBOX hBox);
#define FORMITEM_CMDDELETE 4
extern BX_BOOL formItem_cmdDelete_Click(HBOX hBox);
#define FORMITEM_CMDEDIT 5
extern BX_BOOL formItem_cmdEdit_Click(HBOX hBox);
#define FORMITEM_CMDADD 6
extern BX_BOOL formItem_cmdAdd_Click(HBOX hBox);
#define FORMITEM_CMDREMOVE 7
extern BX_BOOL formItem_cmdRemove_Click(HBOX hBox);
#define FORMITEM_CMDOK 8
extern BX_BOOL formItem_cmdOk_Click(HBOX hBox);
#define FORMITEM_CMDCANCEL 9
extern BX_BOOL formItem_cmdCancel_Click(HBOX hBox);
extern BX_CHAR formItemText[][MAXLANGUAGE][255];
extern BOXSTRUCT formItem[];
extern BX_BOOL formItemProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formItemUpdate(HBOX hBox);
extern BX_VOID formItemInit(HBOX hBox);
#endif // FORMITEM_H
