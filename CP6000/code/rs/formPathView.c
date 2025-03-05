//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPathView.c
#include "Bx.h"
#include "formPathView.h"

BOXSTRUCT formPathView[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formPathView[1], NULL}
 ,{FORMPATHVIEW_CMDPREV,{560,50,649,169},BUTTON,"Prev",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathView[2], &formPathView[0]}
 ,{FORMPATHVIEW_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formPathView[3], &formPathView[0]}
 ,{FORMPATHVIEW_CMDNEXT,{560,290,649,409},BUTTON,"Next",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathView[4], &formPathView[0]}
 ,{FORMPATHVIEW_LABVIEW,{10,50,550,410},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formPathView[5], &formPathView[0]}
 ,{FORMPATHVIEW_GROUPBOX1,{10,430,790,589},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formPathView[6], &formPathView[0]}
 ,{FORMPATHVIEW_SCROLLTAN1,{40,450,99,579},STATIC,"",BXS_VISIBLE,&formPathView[7], &formPathView[0]}
 ,{FORMPATHVIEW_SCROLLTAN2,{120,450,179,579},STATIC,"",BXS_VISIBLE,&formPathView[8], &formPathView[0]}
 ,{FORMPATHVIEW_CMDMENU,{640,490,769,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formPathView[9], &formPathView[0]}
 ,{FORMPATHVIEW_RADIOYZ,{470,490,560,579},BUTTON,"YZ",BBS_RADIOBOX|BXS_VISIBLE,&formPathView[10], &formPathView[0]}
 ,{FORMPATHVIEW_RADIOXY,{250,490,340,579},BUTTON,"XY",BBS_RADIOBOX|BXS_VISIBLE,&formPathView[11], &formPathView[0]}
 ,{FORMPATHVIEW_RADIOXZ,{360,490,450,579},BUTTON,"XZ",BBS_RADIOBOX|BXS_VISIBLE,&formPathView[12], &formPathView[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formPathView[0]}
};

BX_BOOL formPathViewProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formPathViewUpdate(hBox);
				return formPathViewUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formPathViewInit(hBox);
				return formPathViewUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMPATHVIEW_CMDPREV:
             return formPathView_cmdPrev_Click(hBox);
         case FORMPATHVIEW_CMDNEXT:
             return formPathView_cmdNext_Click(hBox);
         case FORMPATHVIEW_SCROLLTAN1:
             return formPathView_scrollTan1_Click(hBox);
         case FORMPATHVIEW_SCROLLTAN2:
             return formPathView_scrollTan2_Click(hBox);
         case FORMPATHVIEW_CMDMENU:
             return formPathView_cmdMenu_Click(hBox);
         case FORMPATHVIEW_RADIOYZ:
             return formPathView_radioYZ_Click(hBox);
         case FORMPATHVIEW_RADIOXY:
             return formPathView_radioXY_Click(hBox);
         case FORMPATHVIEW_RADIOXZ:
             return formPathView_radioXZ_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
