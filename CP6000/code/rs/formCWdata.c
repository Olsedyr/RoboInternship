//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCWdata.c
#include "Bx.h"
#include "formCWdata.h"

BOXSTRUCT formCWdata[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formCWdata[1], NULL}
 ,{FORMCWDATA_FILTER,{10,500,109,589},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formCWdata[2], &formCWdata[0]}
 ,{FORMCWDATA_DATA,{10,10,789,449},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formCWdata[3], &formCWdata[0]}
 ,{FORMCWDATA_CAPTURE,{550,500,649,589},BUTTON,"Capture",BBS_CHECKBOX|BXS_VISIBLE,&formCWdata[4], &formCWdata[0]}
 ,{FORMCWDATA_CMDSTARTVALUE,{120,500,219,589},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formCWdata[5], &formCWdata[0]}
 ,{FORMCWDATA_CMDLENGTHVALUE,{230,500,329,589},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formCWdata[6], &formCWdata[0]}
 ,{FORMCWDATA_CMDMENU,{670,500,789,589},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formCWdata[7], &formCWdata[0]}
 ,{FORMCWDATA_TEXT,{10,460,789,489},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formCWdata[8], &formCWdata[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formCWdata[0]}
};

BX_BOOL formCWdataProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formCWdataUpdate(hBox);
				return formCWdataUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formCWdataInit(hBox);
				return formCWdataUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCWDATA_FILTER:
             return formCWdata_Filter_Click(hBox);
         case FORMCWDATA_CAPTURE:
             return formCWdata_Capture_Click(hBox);
         case FORMCWDATA_CMDSTARTVALUE:
             return formCWdata_cmdStartValue_Click(hBox);
         case FORMCWDATA_CMDLENGTHVALUE:
             return formCWdata_cmdLengthValue_Click(hBox);
         case FORMCWDATA_CMDMENU:
             return formCWdata_cmdMenu_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
