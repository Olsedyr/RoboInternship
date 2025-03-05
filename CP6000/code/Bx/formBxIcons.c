//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formBxIcons.c
#include "Bx.h"
#include "formBxIcons.h"

BOXSTRUCT formBxIcons[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formBxIcons[1], NULL}
 ,{FORMBXICONS_LABNO,{30,20,46,36},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formBxIcons[2], &formBxIcons[0]}
 ,{FORMBXICONS_LABYES,{50,20,67,38},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formBxIcons[3], &formBxIcons[0]}
 ,{FORMBXICONS_LABQUESTION,{80,20,111,51},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formBxIcons[4], &formBxIcons[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formBxIcons[0]}
};

BX_BOOL formBxIconsProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formBxIconsUpdate(hBox);
				return formBxIconsUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formBxIconsInit(hBox);
				return formBxIconsUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
