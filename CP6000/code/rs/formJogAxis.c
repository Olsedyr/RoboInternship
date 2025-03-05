//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogAxis.c
#include "Bx.h"
#include "formJogAxis.h"

BOXSTRUCT formJogAxis[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formJogAxis[1], NULL}
 ,{FORMJOGAXIS_CMDCANCEL,{660,500,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[2], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDRETURN,{520,500,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[3], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDSLOWSTEP,{230,520,349,579},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[4], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDJOGSPEED,{20,520,209,579},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[5], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2,{20,480,199,514},STATIC,"Speed",BSS_CENTER|BXS_VISIBLE,&formJogAxis[6], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2,{230,480,349,514},STATIC,"Small",BSS_CENTER|BXS_VISIBLE,&formJogAxis[7], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_2,{370,480,489,514},STATIC,"Big",BSS_CENTER|BXS_VISIBLE,&formJogAxis[8], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDFJOGFWDSLOW,{520,410,599,469},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[9], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDBJOGREVSLOW,{200,130,279,189},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[10], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDBJOGREVFAST,{100,130,179,189},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[11], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOD,{710,270,780,329},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[12], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3_5,{10,350,89,384},STATIC,"E",BSS_CENTER|BXS_VISIBLE,&formJogAxis[13], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDAJOGFWDFAST,{620,60,699,119},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[14], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXCMPOS,{290,200,509,259},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[15], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDDJOGFWDSLOW,{520,270,599,329},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[16], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDFJOGREVFAST,{100,410,179,469},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[17], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDEJOGREVFAST,{100,340,179,399},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[18], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOA,{710,60,780,119},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[19], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3_3,{10,210,89,244},STATIC,"C",BSS_CENTER|BXS_VISIBLE,&formJogAxis[20], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOE,{710,340,780,399},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[21], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDAJOGREVFAST,{100,60,179,119},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[22], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXBMPOS,{290,130,509,189},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[23], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXFMPOS,{290,410,509,469},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[24], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOB,{710,130,780,189},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[25], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOC,{710,200,780,259},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[26], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDCJOGREVSLOW,{200,200,279,259},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[27], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDDJOGREVSLOW,{200,270,279,329},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[28], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDFJOGFWDFAST,{620,410,699,469},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[29], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDBJOGFWDSLOW,{520,130,599,189},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[30], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDDJOGFWDFAST,{620,270,699,329},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[31], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDDJOGREVFAST,{100,270,179,329},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[32], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDAJOGFWDSLOW,{520,60,599,119},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[33], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDBJOGFWDFAST,{620,130,699,189},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[34], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3,{10,70,79,104},STATIC,"A",BSS_CENTER|BXS_VISIBLE,&formJogAxis[35], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDEJOGREVSLOW,{200,340,279,399},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[36], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDAJOGREVSLOW,{200,60,279,119},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[37], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3_4,{10,280,89,314},STATIC,"D",BSS_CENTER|BXS_VISIBLE,&formJogAxis[38], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDCJOGFWDFAST,{620,200,699,259},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[39], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXEMPOS,{290,340,509,399},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[40], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDEJOGFWDSLOW,{520,340,599,399},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[41], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXAMPOS,{290,60,509,119},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[42], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3_2,{10,140,89,174},STATIC,"B",BSS_CENTER|BXS_VISIBLE,&formJogAxis[43], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDCJOGREVFAST,{100,200,179,259},BUTTON,"<<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[44], &formJogAxis[0]}
 ,{FORMJOGAXIS_RADIOF,{710,410,780,469},BUTTON,"",BBS_RADIOBOX|BXS_VISIBLE,&formJogAxis[45], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDFJOGREVSLOW,{200,410,279,469},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[46], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2_2_2_3_5_2,{10,420,89,454},STATIC,"F",BSS_CENTER|BXS_VISIBLE,&formJogAxis[47], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDCJOGFWDSLOW,{520,200,599,259},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[48], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDEJOGFWDFAST,{620,340,699,399},BUTTON,">>",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[49], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXDMPOS,{290,270,509,329},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[50], &formJogAxis[0]}
 ,{FORMJOGAXIS_CMDFASTSTEP,{370,520,489,579},BUTTON,"1000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogAxis[51], &formJogAxis[0]}
 ,{FORMJOGAXIS_CHECK_B,{710,10,739,39},BUTTON,"B",BBS_CHECKBOX|BXS_VISIBLE,&formJogAxis[52], &formJogAxis[0]}
 ,{FORMJOGAXIS_TEXTLABEL2_2,{10,10,269,44},STATIC,"roboStacker",BXS_VISIBLE,&formJogAxis[53], &formJogAxis[0]}
 ,{FORMJOGAXIS_CHECK_C,{750,10,779,39},BUTTON,"C",BBS_CHECKBOX|BXS_VISIBLE,&formJogAxis[54], &formJogAxis[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formJogAxis[0]}
};

BX_BOOL formJogAxisProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formJogAxisUpdate(hBox);
				return formJogAxisUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formJogAxisInit(hBox);
				return formJogAxisUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMJOGAXIS_CMDCANCEL:
             return formJogAxis_cmdCancel_Click(hBox);
         case FORMJOGAXIS_CMDRETURN:
             return formJogAxis_cmdReturn_Click(hBox);
         case FORMJOGAXIS_CMDSLOWSTEP:
             return formJogAxis_cmdSlowStep_Click(hBox);
         case FORMJOGAXIS_CMDJOGSPEED:
             return formJogAxis_cmdJogSpeed_Click(hBox);
         case FORMJOGAXIS_CMDFJOGFWDSLOW:
             return formJogAxis_cmdFJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_CMDBJOGREVSLOW:
             return formJogAxis_cmdBJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDBJOGREVFAST:
             return formJogAxis_cmdBJogRevFast_Click(hBox);
         case FORMJOGAXIS_RADIOD:
             return formJogAxis_radioD_Click(hBox);
         case FORMJOGAXIS_CMDAJOGFWDFAST:
             return formJogAxis_cmdAJogFwdFast_Click(hBox);
         case FORMJOGAXIS_TEXCMPOS:
             return formJogAxis_TexCMPOS_Click(hBox);
         case FORMJOGAXIS_CMDDJOGFWDSLOW:
             return formJogAxis_cmdDJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_CMDFJOGREVFAST:
             return formJogAxis_cmdFJogRevFast_Click(hBox);
         case FORMJOGAXIS_CMDEJOGREVFAST:
             return formJogAxis_cmdEJogRevFast_Click(hBox);
         case FORMJOGAXIS_RADIOA:
             return formJogAxis_radioA_Click(hBox);
         case FORMJOGAXIS_RADIOE:
             return formJogAxis_radioE_Click(hBox);
         case FORMJOGAXIS_CMDAJOGREVFAST:
             return formJogAxis_cmdAJogRevFast_Click(hBox);
         case FORMJOGAXIS_TEXBMPOS:
             return formJogAxis_TexBMPOS_Click(hBox);
         case FORMJOGAXIS_TEXFMPOS:
             return formJogAxis_TexFMPOS_Click(hBox);
         case FORMJOGAXIS_RADIOB:
             return formJogAxis_radioB_Click(hBox);
         case FORMJOGAXIS_RADIOC:
             return formJogAxis_radioC_Click(hBox);
         case FORMJOGAXIS_CMDCJOGREVSLOW:
             return formJogAxis_cmdCJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDDJOGREVSLOW:
             return formJogAxis_cmdDJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDFJOGFWDFAST:
             return formJogAxis_cmdFJogFwdFast_Click(hBox);
         case FORMJOGAXIS_CMDBJOGFWDSLOW:
             return formJogAxis_cmdBJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_CMDDJOGFWDFAST:
             return formJogAxis_cmdDJogFwdFast_Click(hBox);
         case FORMJOGAXIS_CMDDJOGREVFAST:
             return formJogAxis_cmdDJogRevFast_Click(hBox);
         case FORMJOGAXIS_CMDAJOGFWDSLOW:
             return formJogAxis_cmdAJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_CMDBJOGFWDFAST:
             return formJogAxis_cmdBJogFwdFast_Click(hBox);
         case FORMJOGAXIS_CMDEJOGREVSLOW:
             return formJogAxis_cmdEJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDAJOGREVSLOW:
             return formJogAxis_cmdAJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDCJOGFWDFAST:
             return formJogAxis_cmdCJogFwdFast_Click(hBox);
         case FORMJOGAXIS_TEXEMPOS:
             return formJogAxis_TexEMPOS_Click(hBox);
         case FORMJOGAXIS_CMDEJOGFWDSLOW:
             return formJogAxis_cmdEJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_TEXAMPOS:
             return formJogAxis_TexAMPOS_Click(hBox);
         case FORMJOGAXIS_CMDCJOGREVFAST:
             return formJogAxis_cmdCJogRevFast_Click(hBox);
         case FORMJOGAXIS_RADIOF:
             return formJogAxis_radioF_Click(hBox);
         case FORMJOGAXIS_CMDFJOGREVSLOW:
             return formJogAxis_cmdFJogRevSlow_Click(hBox);
         case FORMJOGAXIS_CMDCJOGFWDSLOW:
             return formJogAxis_cmdCJogFwdSlow_Click(hBox);
         case FORMJOGAXIS_CMDEJOGFWDFAST:
             return formJogAxis_cmdEJogFwdFast_Click(hBox);
         case FORMJOGAXIS_TEXDMPOS:
             return formJogAxis_TexDMPOS_Click(hBox);
         case FORMJOGAXIS_CMDFASTSTEP:
             return formJogAxis_cmdFastStep_Click(hBox);
         case FORMJOGAXIS_CHECK_B:
             return formJogAxis_check_B_Click(hBox);
         case FORMJOGAXIS_CHECK_C:
             return formJogAxis_check_C_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
