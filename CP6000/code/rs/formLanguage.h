//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formLanguage.h
#if !defined(FORMLANGUAGE_H)
#define FORMLANGUAGE_H
#include "Bx.h"
#include "formLanguageUser.h"
#define FORMLANGUAGE_TEXTLABEL2_2 1
#define FORMLANGUAGE_CMDCANCEL 2
extern BX_BOOL formLanguage_cmdCancel_Click(HBOX hBox);
#define FORMLANGUAGE_CMDOK 3
extern BX_BOOL formLanguage_cmdOk_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_6 4
extern BX_BOOL formLanguage_cmdLang1_6_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_5 5
extern BX_BOOL formLanguage_cmdLang1_5_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_4 6
extern BX_BOOL formLanguage_cmdLang1_4_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_1 7
extern BX_BOOL formLanguage_cmdLang1_1_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_2 8
extern BX_BOOL formLanguage_cmdLang1_2_Click(HBOX hBox);
#define FORMLANGUAGE_CMDLANG1_3 9
extern BX_BOOL formLanguage_cmdLang1_3_Click(HBOX hBox);
extern BX_CHAR formLanguageText[][MAXLANGUAGE][255];
extern BOXSTRUCT formLanguage[];
extern BX_BOOL formLanguageProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formLanguageUpdate(HBOX hBox);
extern BX_VOID formLanguageInit(HBOX hBox);
#endif // FORMLANGUAGE_H
