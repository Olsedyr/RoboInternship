//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formComSK.c
#include "Bx.h"
#include "formComSK.h"

BOXSTRUCT formComSK[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formComSK[1], NULL}
 ,{FORMCOMSK_LABMODNAME_2_2,{290,30,379,54},STATIC,"Init data:",BXS_VISIBLE,&formComSK[2], &formComSK[0]}
 ,{FORMCOMSK_LABMODNAME_2,{10,250,99,274},STATIC,"In data:",BXS_VISIBLE,&formComSK[3], &formComSK[0]}
 ,{FORMCOMSK_LABMODNAME,{10,10,279,45},STATIC,"ComSK",BXS_VISIBLE,&formComSK[4], &formComSK[0]}
 ,{FORMCOMSK_CMDCLOSE,{650,100,779,199},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formComSK[5], &formComSK[0]}
 ,{FORMCOMSK_LABMODNAME_3,{410,250,499,274},STATIC,"Out data:",BXS_VISIBLE,&formComSK[6], &formComSK[0]}
 ,{FORMCOMSK_LISTBOXIN,{10,280,389,589},LIST,"",BXS_VISIBLE,&formComSK[7], &formComSK[0]}
 ,{FORMCOMSK_LISTBOXOUT,{410,280,789,589},LIST,"",BXS_VISIBLE,&formComSK[8], &formComSK[0]}
 ,{FORMCOMSK_LISTBOXINIT,{10,60,629,249},LIST,"",BXS_VISIBLE,&formComSK[9], &formComSK[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formComSK[0]}
};

BX_BOOL formComSKProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formComSKUpdate(hBox);
				return formComSKUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formComSKInit(hBox);
				return formComSKUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCOMSK_CMDCLOSE:
             return formComSK_cmdClose_Click(hBox);
         case FORMCOMSK_LISTBOXIN:
             return formComSK_listBoxIn_Click(hBox);
         case FORMCOMSK_LISTBOXOUT:
             return formComSK_listBoxOut_Click(hBox);
         case FORMCOMSK_LISTBOXINIT:
             return formComSK_listBoxInit_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
