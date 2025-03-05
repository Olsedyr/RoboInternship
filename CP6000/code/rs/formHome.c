//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formHome.c
#include "Bx.h"
#include "formHome.h"

BOXSTRUCT formHome[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formHome[1], NULL}
 ,{FORMHOME_TEXTLABEL2,{640,10,789,44},STATIC,"Version 0.0.1",BSS_RIGHT|BXS_VISIBLE,&formHome[2], &formHome[0]}
 ,{FORMHOME_CMDLOGIN,{650,490,779,579},BUTTON,"Login",BBS_PUSHBUTTON|BXS_VISIBLE,&formHome[3], &formHome[0]}
 ,{FORMHOME_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formHome[4], &formHome[0]}
 ,{FORMHOME_TEXTLABEL2_2_2,{70,240,729,274},STATIC,"Robotten kan ikke starte pga. strømudfald, Tilkald supervisor.",BSS_CENTER|BXS_VISIBLE,&formHome[5], &formHome[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formHome[0]}
};

BX_BOOL formHomeProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formHomeUpdate(hBox);
				return formHomeUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formHomeInit(hBox);
				return formHomeUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMHOME_CMDLOGIN:
             return formHome_cmdLogin_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
