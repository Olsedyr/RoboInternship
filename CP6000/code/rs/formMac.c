//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMac.c
#include "Bx.h"
#include "formMac.h"

BOXSTRUCT formMac[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formMac[1], NULL}
 ,{FORMMAC_CMDCLOSE,{650,100,779,199},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formMac[2], &formMac[0]}
 ,{FORMMAC_LABMODNAME,{10,10,279,45},STATIC,"Mac",BXS_VISIBLE,&formMac[3], &formMac[0]}
 ,{FORMMAC_LABMODNAME_3,{410,250,499,274},STATIC,"Out data:",BXS_VISIBLE,&formMac[4], &formMac[0]}
 ,{FORMMAC_LABMODNAME_2_2,{10,250,99,274},STATIC,"Init data:",BXS_VISIBLE,&formMac[5], &formMac[0]}
 ,{FORMMAC_LABMODNAME_2,{290,20,379,44},STATIC,"In data:",BXS_VISIBLE,&formMac[6], &formMac[0]}
 ,{FORMMAC_LISTBOXIN,{10,50,629,249},LIST,"",BXS_VISIBLE,&formMac[7], &formMac[0]}
 ,{FORMMAC_LISTBOXINIT,{10,280,389,589},LIST,"",BXS_VISIBLE,&formMac[8], &formMac[0]}
 ,{FORMMAC_LISTBOXOUT,{410,280,789,589},LIST,"",BXS_VISIBLE,&formMac[9], &formMac[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formMac[0]}
};

BX_BOOL formMacProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formMacUpdate(hBox);
				return formMacUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formMacInit(hBox);
				return formMacUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMAC_CMDCLOSE:
             return formMac_cmdClose_Click(hBox);
         case FORMMAC_LISTBOXIN:
             return formMac_listBoxIn_Click(hBox);
         case FORMMAC_LISTBOXINIT:
             return formMac_listBoxInit_Click(hBox);
         case FORMMAC_LISTBOXOUT:
             return formMac_listBoxOut_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
