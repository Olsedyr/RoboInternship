//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItem.c
#include "Bx.h"
#include "formItem.h"

BOXSTRUCT formItem[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formItem[1], NULL}
 ,{FORMITEM_TEXTLABEL2_2,{10,10,229,44},STATIC,"Items",BXS_VISIBLE,&formItem[2], &formItem[0]}
 ,{FORMITEM_LISTBOX,{10,60,649,459},LIST,"",BXS_VISIBLE,&formItem[3], &formItem[0]}
 ,{FORMITEM_CMDCREATE,{10,490,139,579},BUTTON,"Opret ny",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[4], &formItem[0]}
 ,{FORMITEM_CMDDELETE,{150,490,279,579},BUTTON,"Slet",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[5], &formItem[0]}
 ,{FORMITEM_CMDEDIT,{290,490,419,579},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[6], &formItem[0]}
 ,{FORMITEM_CMDADD,{660,60,789,149},BUTTON,"Tilføj",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[7], &formItem[0]}
 ,{FORMITEM_CMDREMOVE,{660,160,789,249},BUTTON,"Fjern",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[8], &formItem[0]}
 ,{FORMITEM_CMDOK,{660,490,789,579},BUTTON,"Vælg",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[9], &formItem[0]}
 ,{FORMITEM_CMDCANCEL,{520,490,649,579},BUTTON,"Afbryd",BBS_PUSHBUTTON|BXS_VISIBLE,&formItem[10], &formItem[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formItem[0]}
};

BX_BOOL formItemProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formItemUpdate(hBox);
				return formItemUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formItemInit(hBox);
				return formItemUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMITEM_LISTBOX:
             return formItem_listBox_Click(hBox);
         case FORMITEM_CMDCREATE:
             return formItem_cmdCreate_Click(hBox);
         case FORMITEM_CMDDELETE:
             return formItem_cmdDelete_Click(hBox);
         case FORMITEM_CMDEDIT:
             return formItem_cmdEdit_Click(hBox);
         case FORMITEM_CMDADD:
             return formItem_cmdAdd_Click(hBox);
         case FORMITEM_CMDREMOVE:
             return formItem_cmdRemove_Click(hBox);
         case FORMITEM_CMDOK:
             return formItem_cmdOk_Click(hBox);
         case FORMITEM_CMDCANCEL:
             return formItem_cmdCancel_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
