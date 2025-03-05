//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFixPoints.c
#include "Bx.h"
#include "formFixPoints.h"

BOXSTRUCT formFixPoints[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formFixPoints[1], NULL}
 ,{FORMFIXPOINTS_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formFixPoints[2], &formFixPoints[0]}
 ,{FORMFIXPOINTS_CMDMENU,{650,480,779,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formFixPoints[3], &formFixPoints[0]}
 ,{FORMFIXPOINTS_LISTBOX,{20,60,629,579},LIST,"",BXS_VISIBLE,&formFixPoints[4], &formFixPoints[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formFixPoints[0]}
};

BX_BOOL formFixPointsProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formFixPointsUpdate(hBox);
				return formFixPointsUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formFixPointsInit(hBox);
				return formFixPointsUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMFIXPOINTS_CMDMENU:
             return formFixPoints_cmdMenu_Click(hBox);
         case FORMFIXPOINTS_LISTBOX:
             return formFixPoints_listBox_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
