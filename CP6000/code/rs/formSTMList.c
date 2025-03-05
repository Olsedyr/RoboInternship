//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMList.c
#include "Bx.h"
#include "formSTMList.h"

BOXSTRUCT formSTMList[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSTMList[1], NULL}
 ,{FORMSTMLIST_LISTBOX,{20,60,629,579},LIST,"",BXS_VISIBLE,&formSTMList[2], &formSTMList[0]}
 ,{FORMSTMLIST_CMDCLOSE,{650,480,779,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMList[3], &formSTMList[0]}
 ,{FORMSTMLIST_TEXTLABEL2_2,{10,10,369,45},STATIC,"Statemachines",BXS_VISIBLE,&formSTMList[4], &formSTMList[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSTMList[0]}
};

BX_BOOL formSTMListProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSTMListUpdate(hBox);
				return formSTMListUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSTMListInit(hBox);
				return formSTMListUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSTMLIST_LISTBOX:
             return formSTMList_listBox_Click(hBox);
         case FORMSTMLIST_CMDCLOSE:
             return formSTMList_cmdClose_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
