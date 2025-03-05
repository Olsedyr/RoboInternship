//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPedalBox.h
#if !defined(FORMPEDALBOX_H)
#define FORMPEDALBOX_H
#include "Bx.h"
#include "formPedalBoxUser.h"
#define FORMPEDALBOX_CMDSPEED 1
extern BX_BOOL formPedalBox_cmdSpeed_Click(HBOX hBox);
#define FORMPEDALBOX_TEXTLABEL2_2 2
#define FORMPEDALBOX_TEXTLABEL2_2_2 3
#define FORMPEDALBOX_GROUPBOX1 4
#define FORMPEDALBOX_CMDLAYERA5 5
extern BX_BOOL formPedalBox_cmdLayerA5_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA4 6
extern BX_BOOL formPedalBox_cmdLayerA4_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA1 7
extern BX_BOOL formPedalBox_cmdLayerA1_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA2 8
extern BX_BOOL formPedalBox_cmdLayerA2_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA6 9
extern BX_BOOL formPedalBox_cmdLayerA6_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA8 10
extern BX_BOOL formPedalBox_cmdLayerA8_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA3 11
extern BX_BOOL formPedalBox_cmdLayerA3_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERA7 12
extern BX_BOOL formPedalBox_cmdLayerA7_Click(HBOX hBox);
#define FORMPEDALBOX_TEXTLABEL_5 13
#define FORMPEDALBOX_TEXTLABEL 14
#define FORMPEDALBOX_TEXTLABEL_8 15
#define FORMPEDALBOX_TEXTLABEL_3 16
#define FORMPEDALBOX_TEXTLABEL_2 17
#define FORMPEDALBOX_TEXTLABEL_7 18
#define FORMPEDALBOX_TEXTLABEL_4 19
#define FORMPEDALBOX_TEXTLABEL_6 20
#define FORMPEDALBOX_CMDBOXA1 21
extern BX_BOOL formPedalBox_cmdBoxA1_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXA3 22
extern BX_BOOL formPedalBox_cmdBoxA3_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXA0 23
extern BX_BOOL formPedalBox_cmdBoxA0_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXA2 24
extern BX_BOOL formPedalBox_cmdBoxA2_Click(HBOX hBox);
#define FORMPEDALBOX_GROUPBOX2 25
#define FORMPEDALBOX_CMDLAYERC3 26
extern BX_BOOL formPedalBox_cmdLayerC3_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC8 27
extern BX_BOOL formPedalBox_cmdLayerC8_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC6 28
extern BX_BOOL formPedalBox_cmdLayerC6_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC2 29
extern BX_BOOL formPedalBox_cmdLayerC2_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC5 30
extern BX_BOOL formPedalBox_cmdLayerC5_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC4 31
extern BX_BOOL formPedalBox_cmdLayerC4_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC1 32
extern BX_BOOL formPedalBox_cmdLayerC1_Click(HBOX hBox);
#define FORMPEDALBOX_CMDLAYERC7 33
extern BX_BOOL formPedalBox_cmdLayerC7_Click(HBOX hBox);
#define FORMPEDALBOX_TEXTLABEL_4_2 34
#define FORMPEDALBOX_TEXTLABEL_3_2 35
#define FORMPEDALBOX_TEXTLABEL_7_2 36
#define FORMPEDALBOX_TEXTLABEL_8_2 37
#define FORMPEDALBOX_TEXTLABEL_9 38
#define FORMPEDALBOX_TEXTLABEL_2_2 39
#define FORMPEDALBOX_TEXTLABEL_5_2 40
#define FORMPEDALBOX_TEXTLABEL_6_2 41
#define FORMPEDALBOX_CMDBOXC3 42
extern BX_BOOL formPedalBox_cmdBoxC3_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXC1 43
extern BX_BOOL formPedalBox_cmdBoxC1_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXC0 44
extern BX_BOOL formPedalBox_cmdBoxC0_Click(HBOX hBox);
#define FORMPEDALBOX_CMDBOXC2 45
extern BX_BOOL formPedalBox_cmdBoxC2_Click(HBOX hBox);
#define FORMPEDALBOX_LABPROGRESS_2 46
#define FORMPEDALBOX_LABPROGRESS 47
#define FORMPEDALBOX_CMDMENU 48
extern BX_BOOL formPedalBox_cmdMenu_Click(HBOX hBox);
#define FORMPEDALBOX_CMDRUN 49
extern BX_BOOL formPedalBox_cmdRun_Click(HBOX hBox);
#define FORMPEDALBOX_CMDSET 50
extern BX_BOOL formPedalBox_cmdSet_Click(HBOX hBox);
extern BX_CHAR formPedalBoxText[][MAXLANGUAGE][255];
extern BOXSTRUCT formPedalBox[];
extern BX_BOOL formPedalBoxProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formPedalBoxUpdate(HBOX hBox);
extern BX_VOID formPedalBoxInit(HBOX hBox);
#endif // FORMPEDALBOX_H
