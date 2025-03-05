//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formIcon.h
#if !defined(FORMICON_H)
#define FORMICON_H
#include "Bx.h"
#include "formIconUser.h"
#define FORMICON_LABYES 1
#define FORMICON_LABNO 2
#define FORMICON_LABSHUTDOWN 3
#define FORMICON_LABWARNING 4
#define FORMICON_LABPROGRAM 5
#define FORMICON_LABVISION 6
#define FORMICON_LABTOOLS_2 7
#define FORMICON_LABTOOLS 8
#define FORMICON_LABUNLOCK 9
#define FORMICON_LABSCOPE 10
#define FORMICON_LABOPTION 11
#define FORMICON_LABBOX 12
#define FORMICON_LABBAGS 13
#define FORMICON_LABPALMBOX 14
extern BX_CHAR formIconText[][MAXLANGUAGE][255];
extern BOXSTRUCT formIcon[];
extern BX_BOOL formIconProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formIconUpdate(HBOX hBox);
extern BX_VOID formIconInit(HBOX hBox);
#endif // FORMICON_H
