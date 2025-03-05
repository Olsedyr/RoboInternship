//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathEditor.c
#include "Bx.h"
#include "formPathEditor.h"

BOXSTRUCT formPathEditor[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formPathEditor[1], NULL}
 ,{FORMPATHEDITOR_GROUPBOX1,{10,430,790,589},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formPathEditor[2], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDMENU,{640,490,769,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[3], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDSPEED,{70,490,199,579},BUTTON,"Speed",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[4], &formPathEditor[0]}
 ,{FORMPATHEDITOR_TEXTLABEL2_2_2,{70,450,199,484},STATIC,"Speed",BSS_CENTER|BXS_VISIBLE,&formPathEditor[5], &formPathEditor[0]}
 ,{FORMPATHEDITOR_TEXTRATE,{220,450,349,484},STATIC,"Rate",BSS_CENTER|BXS_VISIBLE,&formPathEditor[6], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDRATE,{220,490,349,579},BUTTON,"Rate",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[7], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDVIEW,{430,490,559,579},BUTTON,"View",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[8], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDNEXT,{699,240,788,359},BUTTON,"Next",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[9], &formPathEditor[0]}
 ,{FORMPATHEDITOR_CMDPREV,{700,110,789,229},BUTTON,"Prev",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathEditor[10], &formPathEditor[0]}
 ,{FORMPATHEDITOR_LISTBOX,{10,110,689,359},LIST,"",BXS_VISIBLE,&formPathEditor[11], &formPathEditor[0]}
 ,{FORMPATHEDITOR_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formPathEditor[12], &formPathEditor[0]}
 ,{FORMPATHEDITOR_TEXTLABEL2_2_3,{10,60,79,94},STATIC,"Name",BXS_VISIBLE,&formPathEditor[13], &formPathEditor[0]}
 ,{FORMPATHEDITOR_TEXTNAME,{100,60,789,94},STATIC,"FileName",BXS_BORDER|BXS_VISIBLE,&formPathEditor[14], &formPathEditor[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formPathEditor[0]}
};

BX_BOOL formPathEditorProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formPathEditorUpdate(hBox);
				return formPathEditorUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formPathEditorInit(hBox);
				return formPathEditorUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMPATHEDITOR_CMDMENU:
             return formPathEditor_cmdMenu_Click(hBox);
         case FORMPATHEDITOR_CMDSPEED:
             return formPathEditor_cmdSpeed_Click(hBox);
         case FORMPATHEDITOR_CMDRATE:
             return formPathEditor_cmdRate_Click(hBox);
         case FORMPATHEDITOR_CMDVIEW:
             return formPathEditor_cmdView_Click(hBox);
         case FORMPATHEDITOR_CMDNEXT:
             return formPathEditor_cmdNext_Click(hBox);
         case FORMPATHEDITOR_CMDPREV:
             return formPathEditor_cmdPrev_Click(hBox);
         case FORMPATHEDITOR_LISTBOX:
             return formPathEditor_listBox_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
