//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogIk.c
#include "Bx.h"
#include "formJogIk.h"

BOXSTRUCT formJogIk[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formJogIk[1], NULL}
 ,{FORMJOGIK_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formJogIk[2], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL2_2_2,{20,440,199,474},STATIC,"Speed",BSS_CENTER|BXS_VISIBLE,&formJogIk[3], &formJogIk[0]}
 ,{FORMJOGIK_CMDJOGSPEED,{20,480,209,579},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[4], &formJogIk[0]}
 ,{FORMJOGIK_CMDZLEFT,{520,350,599,419},BUTTON,"Z-",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[5], &formJogIk[0]}
 ,{FORMJOGIK_CMDZRIGHT,{680,350,759,419},BUTTON,"Z+",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[6], &formJogIk[0]}
 ,{FORMJOGIK_CMDDOWN,{600,180,679,249},BUTTON,"Y-",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[7], &formJogIk[0]}
 ,{FORMJOGIK_CMDLEFT,{520,110,599,179},BUTTON,"X-",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[8], &formJogIk[0]}
 ,{FORMJOGIK_CMDUP,{600,40,679,109},BUTTON,"Y+",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[9], &formJogIk[0]}
 ,{FORMJOGIK_CMDRIGHT,{680,110,759,179},BUTTON,"X+",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[10], &formJogIk[0]}
 ,{FORMJOGIK_TEXTTILTANGLE,{150,370,319,400},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogIk[11], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL_2_2,{150,330,319,364},STATIC,"Tilt",BSS_CENTER|BXS_VISIBLE,&formJogIk[12], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL_2,{150,230,319,264},STATIC,"Turn",BSS_CENTER|BXS_VISIBLE,&formJogIk[13], &formJogIk[0]}
 ,{FORMJOGIK_TEXTTURNANGLE,{150,270,319,300},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogIk[14], &formJogIk[0]}
 ,{FORMJOGIK_CMDTILTLEFT,{50,350,129,419},BUTTON,"Left",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[15], &formJogIk[0]}
 ,{FORMJOGIK_CMDTURNRIGHT,{350,250,429,319},BUTTON,"Right",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[16], &formJogIk[0]}
 ,{FORMJOGIK_CMDTURNLEFT,{50,250,129,319},BUTTON,"Left",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[17], &formJogIk[0]}
 ,{FORMJOGIK_CMDTILTRIGHT,{350,350,429,419},BUTTON,"Right",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[18], &formJogIk[0]}
 ,{FORMJOGIK_TEXCMPOS,{150,170,319,209},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogIk[19], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL2_2_2_2_3,{50,70,119,104},STATIC,"X",BSS_CENTER|BXS_VISIBLE,&formJogIk[20], &formJogIk[0]}
 ,{FORMJOGIK_TEXBMPOS,{150,120,319,159},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogIk[21], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL2_2_2_2_3_2,{50,120,119,154},STATIC,"Y",BSS_CENTER|BXS_VISIBLE,&formJogIk[22], &formJogIk[0]}
 ,{FORMJOGIK_TEXAMPOS,{150,70,319,109},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogIk[23], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL2_2_2_2_3_3,{50,170,119,204},STATIC,"Z",BSS_CENTER|BXS_VISIBLE,&formJogIk[24], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABEL2,{220,440,339,474},STATIC,"Step",BSS_CENTER|BXS_VISIBLE,&formJogIk[25], &formJogIk[0]}
 ,{FORMJOGIK_CMDIKSTEP,{220,480,339,579},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[26], &formJogIk[0]}
 ,{FORMJOGIK_CMDIKTCPIDX,{370,480,489,579},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[27], &formJogIk[0]}
 ,{FORMJOGIK_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogIk[28], &formJogIk[0]}
 ,{FORMJOGIK_TEXTLABELIKTCPIDX,{370,440,489,474},STATIC,"tcp idx",BSS_CENTER|BXS_VISIBLE,&formJogIk[29], &formJogIk[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formJogIk[0]}
};

BX_BOOL formJogIkProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formJogIkUpdate(hBox);
				return formJogIkUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formJogIkInit(hBox);
				return formJogIkUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMJOGIK_CMDJOGSPEED:
             return formJogIk_cmdJogSpeed_Click(hBox);
         case FORMJOGIK_CMDZLEFT:
             return formJogIk_cmdZLeft_Click(hBox);
         case FORMJOGIK_CMDZRIGHT:
             return formJogIk_cmdZRight_Click(hBox);
         case FORMJOGIK_CMDDOWN:
             return formJogIk_cmdDown_Click(hBox);
         case FORMJOGIK_CMDLEFT:
             return formJogIk_cmdLeft_Click(hBox);
         case FORMJOGIK_CMDUP:
             return formJogIk_cmdUp_Click(hBox);
         case FORMJOGIK_CMDRIGHT:
             return formJogIk_cmdRight_Click(hBox);
         case FORMJOGIK_CMDTILTLEFT:
             return formJogIk_cmdTiltLeft_Click(hBox);
         case FORMJOGIK_CMDTURNRIGHT:
             return formJogIk_cmdTurnRight_Click(hBox);
         case FORMJOGIK_CMDTURNLEFT:
             return formJogIk_cmdTurnLeft_Click(hBox);
         case FORMJOGIK_CMDTILTRIGHT:
             return formJogIk_cmdTiltRight_Click(hBox);
         case FORMJOGIK_CMDIKSTEP:
             return formJogIk_cmdIkStep_Click(hBox);
         case FORMJOGIK_CMDIKTCPIDX:
             return formJogIk_cmdIkTcpIdx_Click(hBox);
         case FORMJOGIK_CMDCANCEL:
             return formJogIk_cmdCancel_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
