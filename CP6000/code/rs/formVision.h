//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formVision.h
#if !defined(FORMVISION_H)
#define FORMVISION_H
#include "Bx.h"
#include "formVisionUser.h"
#define FORMVISION_TEXTLABEL2_2 1
#define FORMVISION_CMDRETURN 2
extern BX_BOOL formVision_cmdReturn_Click(HBOX hBox);
#define FORMVISION_CMDSMALL 3
extern BX_BOOL formVision_cmdSmall_Click(HBOX hBox);
#define FORMVISION_TEXTLABEL_3_2 4
#define FORMVISION_TEXTLABEL2 5
#define FORMVISION_CMDMINHEIGHT 6
extern BX_BOOL formVision_cmdMinHeight_Click(HBOX hBox);
#define FORMVISION_TEXTLABEL5 7
#define FORMVISION_TEXTLABEL5_2 8
#define FORMVISION_CMDIPADDRESS 9
extern BX_BOOL formVision_cmdIpAddress_Click(HBOX hBox);
#define FORMVISION_TEXTLABEL_2 10
#define FORMVISION_TEXTLABEL_3 11
#define FORMVISION_TEXTLABEL 12
#define FORMVISION_TEXTLABEL4 13
#define FORMVISION_TEXTLENGTH 14
#define FORMVISION_TEXTWIDTH 15
#define FORMVISION_TEXTHEIGHT 16
#define FORMVISION_TEXTANGLE 17
#define FORMVISION_TEXTLABEL3 18
#define FORMVISION_TEXTLABEL3_2 19
#define FORMVISION_TEXTFPS 20
#define FORMVISION_CHECKCONNECT 21
extern BX_BOOL formVision_checkConnect_Click(HBOX hBox);
#define FORMVISION_CHECKGUIDEDBYVISION 22
extern BX_BOOL formVision_checkGuidedByVision_Click(HBOX hBox);
extern BX_CHAR formVisionText[][MAXLANGUAGE][255];
extern BOXSTRUCT formVision[];
extern BX_BOOL formVisionProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formVisionUpdate(HBOX hBox);
extern BX_VOID formVisionInit(HBOX hBox);
#endif // FORMVISION_H
