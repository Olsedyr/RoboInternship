//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formAdjBoxFrames.c
#include "Bx.h"
#include "formAdjBoxFrames.h"

BOXSTRUCT formAdjBoxFrames[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formAdjBoxFrames[1], NULL}
 ,{FORMADJBOXFRAMES_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formAdjBoxFrames[2], &formAdjBoxFrames[0]}
 ,{FORMADJBOXFRAMES_CMDMENU,{650,480,779,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formAdjBoxFrames[3], &formAdjBoxFrames[0]}
 ,{FORMADJBOXFRAMES_LISTBOX,{20,60,629,579},LIST,"",BXS_VISIBLE,&formAdjBoxFrames[4], &formAdjBoxFrames[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formAdjBoxFrames[0]}
};

BX_BOOL formAdjBoxFramesProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formAdjBoxFramesUpdate(hBox);
				return formAdjBoxFramesUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formAdjBoxFramesInit(hBox);
				return formAdjBoxFramesUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMADJBOXFRAMES_CMDMENU:
             return formAdjBoxFrames_cmdMenu_Click(hBox);
         case FORMADJBOXFRAMES_LISTBOX:
             return formAdjBoxFrames_listBox_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
