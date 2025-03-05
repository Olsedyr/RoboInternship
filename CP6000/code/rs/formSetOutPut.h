//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSetOutPut.h
#if !defined(FORMSETOUTPUT_H)
#define FORMSETOUTPUT_H
#include "Bx.h"
#include "formSetOutPutUser.h"
#define FORMSETOUTPUT_TEXTLABEL2_2 1
#define FORMSETOUTPUT_CMDCANCEL 2
extern BX_BOOL formSetOutPut_cmdCancel_Click(HBOX hBox);
#define FORMSETOUTPUT_CMDRETURN 3
extern BX_BOOL formSetOutPut_cmdReturn_Click(HBOX hBox);
#define FORMSETOUTPUT_GROUPBOX1 4
#define FORMSETOUTPUT_TEXTLABEL2 5
#define FORMSETOUTPUT_TEXTLABEL2_2_2 6
#define FORMSETOUTPUT_CMDOUTPUTNUM 7
extern BX_BOOL formSetOutPut_cmdOutPutNum_Click(HBOX hBox);
#define FORMSETOUTPUT_CHKOUTPUT 8
extern BX_BOOL formSetOutPut_chkOutput_Click(HBOX hBox);
#define FORMSETOUTPUT_GROUPBOX1_2 9
#define FORMSETOUTPUT_TEXTLABEL2_2_2_2 10
#define FORMSETOUTPUT_TEXTLABEL2_3 11
#define FORMSETOUTPUT_CMDINPUTNUM 12
extern BX_BOOL formSetOutPut_cmdInPutNum_Click(HBOX hBox);
#define FORMSETOUTPUT_CHKINPUT 13
extern BX_BOOL formSetOutPut_chkInput_Click(HBOX hBox);
#define FORMSETOUTPUT_RADIOOUTPUT 14
extern BX_BOOL formSetOutPut_radioOutput_Click(HBOX hBox);
#define FORMSETOUTPUT_RADIOINPUT 15
extern BX_BOOL formSetOutPut_radioInput_Click(HBOX hBox);
extern BX_CHAR formSetOutPutText[][MAXLANGUAGE][255];
extern BOXSTRUCT formSetOutPut[];
extern BX_BOOL formSetOutPutProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formSetOutPutUpdate(HBOX hBox);
extern BX_VOID formSetOutPutInit(HBOX hBox);
#endif // FORMSETOUTPUT_H
