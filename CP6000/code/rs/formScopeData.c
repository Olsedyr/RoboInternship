//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formScopeData.c
#include "Bx.h"
#include "formScopeData.h"

BOXSTRUCT formScopeData[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formScopeData[1], NULL}
 ,{FORMSCOPEDATA_CMDMENU,{670,500,789,589},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formScopeData[2], &formScopeData[0]}
 ,{FORMSCOPEDATA_SCROLLBAR1,{10,10,60,449},STATIC,"",BXS_VISIBLE,&formScopeData[3], &formScopeData[0]}
 ,{FORMSCOPEDATA_TEXT,{10,460,789,489},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formScopeData[4], &formScopeData[0]}
 ,{FORMSCOPEDATA_TEXTLABEL2,{10,490,99,530},STATIC,"Index",BXS_VISIBLE,&formScopeData[5], &formScopeData[0]}
 ,{FORMSCOPEDATA_CMDINDEX,{10,540,89,589},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formScopeData[6], &formScopeData[0]}
 ,{FORMSCOPEDATA_CAPTURE,{560,540,619,589},BUTTON,"Capture",BBS_CHECKBOX|BXS_VISIBLE,&formScopeData[7], &formScopeData[0]}
 ,{FORMSCOPEDATA_TEXTLABEL1,{550,490,639,530},STATIC,"Capture",BXS_VISIBLE,&formScopeData[8], &formScopeData[0]}
 ,{FORMSCOPEDATA_FT,{450,540,509,589},BUTTON,"FT",BBS_CHECKBOX|BXS_VISIBLE,&formScopeData[9], &formScopeData[0]}
 ,{FORMSCOPEDATA_TEXTLABEL4,{390,490,429,530},STATIC,"DT",BXS_VISIBLE,&formScopeData[10], &formScopeData[0]}
 ,{FORMSCOPEDATA_TEXTLABEL3,{470,490,509,530},STATIC,"FT",BXS_VISIBLE,&formScopeData[11], &formScopeData[0]}
 ,{FORMSCOPEDATA_DT,{370,540,429,589},BUTTON,"DT",BBS_CHECKBOX|BXS_VISIBLE,&formScopeData[12], &formScopeData[0]}
 ,{FORMSCOPEDATA_DATA,{60,10,789,449},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formScopeData[13], &formScopeData[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formScopeData[0]}
};

BX_BOOL formScopeDataProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formScopeDataUpdate(hBox);
				return formScopeDataUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formScopeDataInit(hBox);
				return formScopeDataUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSCOPEDATA_CMDMENU:
             return formScopeData_cmdMenu_Click(hBox);
         case FORMSCOPEDATA_SCROLLBAR1:
             return formScopeData_scrollBar1_Click(hBox);
         case FORMSCOPEDATA_CMDINDEX:
             return formScopeData_cmdIndex_Click(hBox);
         case FORMSCOPEDATA_CAPTURE:
             return formScopeData_Capture_Click(hBox);
         case FORMSCOPEDATA_FT:
             return formScopeData_FT_Click(hBox);
         case FORMSCOPEDATA_DT:
             return formScopeData_DT_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
