//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogAxis.h
#if !defined(FORMJOGAXIS_H)
#define FORMJOGAXIS_H
#include "Bx.h"
#include "formJogAxisUser.h"
#define FORMJOGAXIS_CMDCANCEL 1
extern BX_BOOL formJogAxis_cmdCancel_Click(HBOX hBox);
#define FORMJOGAXIS_CMDRETURN 2
extern BX_BOOL formJogAxis_cmdReturn_Click(HBOX hBox);
#define FORMJOGAXIS_CMDSLOWSTEP 3
extern BX_BOOL formJogAxis_cmdSlowStep_Click(HBOX hBox);
#define FORMJOGAXIS_CMDJOGSPEED 4
extern BX_BOOL formJogAxis_cmdJogSpeed_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2 5
#define FORMJOGAXIS_TEXTLABEL2_2_2_2 6
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_2 7
#define FORMJOGAXIS_CMDFJOGFWDSLOW 8
extern BX_BOOL formJogAxis_cmdFJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDBJOGREVSLOW 9
extern BX_BOOL formJogAxis_cmdBJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDBJOGREVFAST 10
extern BX_BOOL formJogAxis_cmdBJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_RADIOD 11
extern BX_BOOL formJogAxis_radioD_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3_5 12
#define FORMJOGAXIS_CMDAJOGFWDFAST 13
extern BX_BOOL formJogAxis_cmdAJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_TEXCMPOS 14
extern BX_BOOL formJogAxis_TexCMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_CMDDJOGFWDSLOW 15
extern BX_BOOL formJogAxis_cmdDJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDFJOGREVFAST 16
extern BX_BOOL formJogAxis_cmdFJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_CMDEJOGREVFAST 17
extern BX_BOOL formJogAxis_cmdEJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_RADIOA 18
extern BX_BOOL formJogAxis_radioA_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3_3 19
#define FORMJOGAXIS_RADIOE 20
extern BX_BOOL formJogAxis_radioE_Click(HBOX hBox);
#define FORMJOGAXIS_CMDAJOGREVFAST 21
extern BX_BOOL formJogAxis_cmdAJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_TEXBMPOS 22
extern BX_BOOL formJogAxis_TexBMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_TEXFMPOS 23
extern BX_BOOL formJogAxis_TexFMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_RADIOB 24
extern BX_BOOL formJogAxis_radioB_Click(HBOX hBox);
#define FORMJOGAXIS_RADIOC 25
extern BX_BOOL formJogAxis_radioC_Click(HBOX hBox);
#define FORMJOGAXIS_CMDCJOGREVSLOW 26
extern BX_BOOL formJogAxis_cmdCJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDDJOGREVSLOW 27
extern BX_BOOL formJogAxis_cmdDJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDFJOGFWDFAST 28
extern BX_BOOL formJogAxis_cmdFJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_CMDBJOGFWDSLOW 29
extern BX_BOOL formJogAxis_cmdBJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDDJOGFWDFAST 30
extern BX_BOOL formJogAxis_cmdDJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_CMDDJOGREVFAST 31
extern BX_BOOL formJogAxis_cmdDJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_CMDAJOGFWDSLOW 32
extern BX_BOOL formJogAxis_cmdAJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDBJOGFWDFAST 33
extern BX_BOOL formJogAxis_cmdBJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3 34
#define FORMJOGAXIS_CMDEJOGREVSLOW 35
extern BX_BOOL formJogAxis_cmdEJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDAJOGREVSLOW 36
extern BX_BOOL formJogAxis_cmdAJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3_4 37
#define FORMJOGAXIS_CMDCJOGFWDFAST 38
extern BX_BOOL formJogAxis_cmdCJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_TEXEMPOS 39
extern BX_BOOL formJogAxis_TexEMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_CMDEJOGFWDSLOW 40
extern BX_BOOL formJogAxis_cmdEJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_TEXAMPOS 41
extern BX_BOOL formJogAxis_TexAMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3_2 42
#define FORMJOGAXIS_CMDCJOGREVFAST 43
extern BX_BOOL formJogAxis_cmdCJogRevFast_Click(HBOX hBox);
#define FORMJOGAXIS_RADIOF 44
extern BX_BOOL formJogAxis_radioF_Click(HBOX hBox);
#define FORMJOGAXIS_CMDFJOGREVSLOW 45
extern BX_BOOL formJogAxis_cmdFJogRevSlow_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2_2_2_3_5_2 46
#define FORMJOGAXIS_CMDCJOGFWDSLOW 47
extern BX_BOOL formJogAxis_cmdCJogFwdSlow_Click(HBOX hBox);
#define FORMJOGAXIS_CMDEJOGFWDFAST 48
extern BX_BOOL formJogAxis_cmdEJogFwdFast_Click(HBOX hBox);
#define FORMJOGAXIS_TEXDMPOS 49
extern BX_BOOL formJogAxis_TexDMPOS_Click(HBOX hBox);
#define FORMJOGAXIS_CMDFASTSTEP 50
extern BX_BOOL formJogAxis_cmdFastStep_Click(HBOX hBox);
#define FORMJOGAXIS_CHECK_B 51
extern BX_BOOL formJogAxis_check_B_Click(HBOX hBox);
#define FORMJOGAXIS_TEXTLABEL2_2 52
#define FORMJOGAXIS_CHECK_C 53
extern BX_BOOL formJogAxis_check_C_Click(HBOX hBox);
extern BX_CHAR formJogAxisText[][MAXLANGUAGE][255];
extern BOXSTRUCT formJogAxis[];
extern BX_BOOL formJogAxisProc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);
extern BX_VOID formJogAxisUpdate(HBOX hBox);
extern BX_VOID formJogAxisInit(HBOX hBox);
#endif // FORMJOGAXIS_H
