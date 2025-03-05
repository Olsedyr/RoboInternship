//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formUploadProg.h
#if !defined(FORMUPLOADPROG_H)
#define FORMUPLOADPROG_H
#include "Bx.h"
#include "formUploadProgUser.h"
#define FORMUPLOADPROG_LABPROGRESS 1
#define FORMUPLOADPROG_TEXTLABEL2_2 2
#define FORMUPLOADPROG_TEXTMESSAGE 3
extern BX_CHAR formUploadProgText[][MAXLANGUAGE][255];
extern BOXSTRUCT formUploadProg[];
extern BX_BOOL formUploadProgProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formUploadProgUpdate(HBOX hBox);
extern BX_VOID formUploadProgInit(HBOX hBox);
#endif // FORMUPLOADPROG_H
