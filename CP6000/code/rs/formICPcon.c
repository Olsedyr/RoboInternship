//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formICPcon.c
#include "Bx.h"
#include "formICPcon.h"

BOXSTRUCT formICPcon[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formICPcon[1], NULL}
 ,{FORMICPCON_LABMODNAME,{10,10,99,45},STATIC,"ICPcon",BXS_VISIBLE,&formICPcon[2], &formICPcon[0]}
 ,{FORMICPCON_LISTBOXIN,{10,60,379,579},LIST,"",BXS_VISIBLE,&formICPcon[3], &formICPcon[0]}
 ,{FORMICPCON_LABMODNAME_2,{160,30,249,54},STATIC,"In data:",BXS_VISIBLE,&formICPcon[4], &formICPcon[0]}
 ,{FORMICPCON_LABMODNAME_3,{550,30,639,54},STATIC,"Out data:",BXS_VISIBLE,&formICPcon[5], &formICPcon[0]}
 ,{FORMICPCON_CMDCLOSE,{640,480,769,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formICPcon[6], &formICPcon[0]}
 ,{FORMICPCON_LISTBOXOUT,{400,60,779,449},LIST,"",BXS_VISIBLE,&formICPcon[7], &formICPcon[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formICPcon[0]}
};

BX_BOOL formICPconProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formICPconUpdate(hBox);
				return formICPconUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formICPconInit(hBox);
				return formICPconUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMICPCON_LISTBOXIN:
             return formICPcon_listBoxIn_Click(hBox);
         case FORMICPCON_CMDCLOSE:
             return formICPcon_cmdClose_Click(hBox);
         case FORMICPCON_LISTBOXOUT:
             return formICPcon_listBoxOut_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
