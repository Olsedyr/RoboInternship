//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formContinue.c
#include "Bx.h"
#include "formContinue.h"

BOXSTRUCT formContinue[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formContinue[1], NULL}
 ,{FORMCONTINUE_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2050",BXS_VISIBLE,&formContinue[2], &formContinue[0]}
 ,{FORMCONTINUE_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formContinue[3], &formContinue[0]}
 ,{FORMCONTINUE_GROUPBOX1_2_2,{20,80,779,449},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formContinue[4], &formContinue[0]}
 ,{FORMCONTINUE_LABINFOTYPE,{50,190,739,224},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formContinue[5], &formContinue[0]}
 ,{FORMCONTINUE_LABINFO,{50,280,749,314},STATIC,"Information",BSS_CENTER|BXS_VISIBLE,&formContinue[6], &formContinue[0]}
 ,{FORMCONTINUE_TEXTLABEL1_2,{370,110,439,173},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formContinue[7], &formContinue[0]}
 ,{FORMCONTINUE_CMDCONTINUE,{230,480,359,569},BUTTON,"Fortsæt",BBS_PUSHBUTTON|BXS_VISIBLE,&formContinue[8], &formContinue[0]}
 ,{FORMCONTINUE_CMDSTOP,{470,480,599,569},BUTTON,"Afslut",BBS_PUSHBUTTON|BXS_VISIBLE,&formContinue[9], &formContinue[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formContinue[0]}
};

BX_BOOL formContinueProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formContinueUpdate(hBox);
				return formContinueUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formContinueInit(hBox);
				return formContinueUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCONTINUE_CMDCONTINUE:
             return formContinue_cmdContinue_Click(hBox);
         case FORMCONTINUE_CMDSTOP:
             return formContinue_cmdStop_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
