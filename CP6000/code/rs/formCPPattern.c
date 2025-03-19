//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCPPattern.c
#include "Bx.h"
#include "formCPPattern.h"

BOXSTRUCT formCPPattern[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formCPPattern[1], NULL}
 ,{FORMCPPATTERN_CMDCREATE,{10,490,139,579},BUTTON,"Opret ny",BBS_PUSHBUTTON|BXS_VISIBLE,&formCPPattern[2], &formCPPattern[0]}
 ,{FORMCPPATTERN_CMDDELETE,{150,490,279,579},BUTTON,"Slet",BBS_PUSHBUTTON|BXS_VISIBLE,&formCPPattern[3], &formCPPattern[0]}
 ,{FORMCPPATTERN_CMDEDIT,{290,490,419,579},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formCPPattern[4], &formCPPattern[0]}
 ,{FORMCPPATTERN_CMDCANCEL,{520,490,649,579},BUTTON,"Afbryd",BBS_PUSHBUTTON|BXS_VISIBLE,&formCPPattern[5], &formCPPattern[0]}
 ,{FORMCPPATTERN_CMDOK,{660,490,789,579},BUTTON,"Vælg",BBS_PUSHBUTTON|BXS_VISIBLE,&formCPPattern[6], &formCPPattern[0]}
 ,{FORMCPPATTERN_TEXTLABEL2_2,{10,10,229,44},STATIC,"CP Patterns",BXS_VISIBLE,&formCPPattern[7], &formCPPattern[0]}
 ,{FORMCPPATTERN_LISTBOX,{10,60,649,459},LIST,"",BXS_VISIBLE,&formCPPattern[8], &formCPPattern[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formCPPattern[0]}
};

BX_BOOL formCPPatternProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formCPPatternUpdate(hBox);
				return formCPPatternUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formCPPatternInit(hBox);
				return formCPPatternUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCPPATTERN_CMDADD:
             return formCPPattern_cmdAdd_Click(hBox);
         case FORMCPPATTERN_CMDREMOVE:
             return formCPPattern_cmdRemove_Click(hBox);
         case FORMCPPATTERN_CMDCREATE:
             return formCPPattern_cmdCreate_Click(hBox);
         case FORMCPPATTERN_CMDDELETE:
             return formCPPattern_cmdDelete_Click(hBox);
         case FORMCPPATTERN_CMDEDIT:
             return formCPPattern_cmdEdit_Click(hBox);
         case FORMCPPATTERN_CMDCANCEL:
             return formCPPattern_cmdCancel_Click(hBox);
         case FORMCPPATTERN_CMDOK:
             return formCPPattern_cmdOk_Click(hBox);
         case FORMCPPATTERN_LISTBOX:
             return formCPPattern_listBox_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
