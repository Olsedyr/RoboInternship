//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgram.h
#if !defined(FORMPROGRAM_H)
#define FORMPROGRAM_H
#include "Bx.h"
#include "formProgramUser.h"
#define FORMPROGRAM_TEXTLABEL2_2 1
#define FORMPROGRAM_LISTBOX 2
extern BX_BOOL formProgram_listBox_Click(HBOX hBox);
#define FORMPROGRAM_CMDCANCEL 3
extern BX_BOOL formProgram_cmdCancel_Click(HBOX hBox);
#define FORMPROGRAM_CMDOK 4
extern BX_BOOL formProgram_cmdOk_Click(HBOX hBox);
#define FORMPROGRAM_CMDEDIT 5
extern BX_BOOL formProgram_cmdEdit_Click(HBOX hBox);
#define FORMPROGRAM_CMDDELETE 6
extern BX_BOOL formProgram_cmdDelete_Click(HBOX hBox);
#define FORMPROGRAM_CMDNEW 7
extern BX_BOOL formProgram_cmdNew_Click(HBOX hBox);
extern BX_CHAR formProgramText[][MAXLANGUAGE][255];
extern BOXSTRUCT formProgram[];
extern BX_BOOL formProgramProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formProgramUpdate(HBOX hBox);
extern BX_VOID formProgramInit(HBOX hBox);
#endif // FORMPROGRAM_H
