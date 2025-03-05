//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formStartup.c
#include "Bx.h"
#include "formStartup.h"

BOXSTRUCT formStartup[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formStartup[1], NULL}
 ,{FORMSTARTUP_LABPROGRESS,{60,280,720,360},STATIC,"Progress bar",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formStartup[2], &formStartup[0]}
 ,{FORMSTARTUP_TEXTMESSAGE,{70,230,719,264},STATIC,"roboStacker RS2000",BSS_CENTER|BXS_VISIBLE,&formStartup[3], &formStartup[0]}
 ,{FORMSTARTUP_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formStartup[4], &formStartup[0]}
 ,{FORMSTARTUP_TEXTLABEL2,{640,10,789,44},STATIC,"Version 0.0.1",BSS_RIGHT|BXS_VISIBLE,&formStartup[5], &formStartup[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formStartup[0]}
};

BX_BOOL formStartupProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formStartupUpdate(hBox);
				return formStartupUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formStartupInit(hBox);
				return formStartupUserInit(hBox,lParam);
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
