//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCP.c
#include "Bx.h"
#include "formCP.h"

BOXSTRUCT formCP[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formCP[1], NULL}
 ,{FORMCP_TEXTLABEL2_2,{10,10,259,44},STATIC,"casePacker CP6000",BXS_VISIBLE,&formCP[2], &formCP[0]}
 ,{FORMCP_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formCP[3], &formCP[0]}
 ,{FORMCP_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formCP[4], &formCP[0]}
 ,{FORMCP_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formCP[5], &formCP[0]}
 ,{FORMCP_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formCP[6], &formCP[0]}
 ,{FORMCP_GROUPBOX1_2_2,{10,60,789,479},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formCP[7], &formCP[0]}
 ,{FORMCP_LABWORKCELLSTATE,{30,80,769,114},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formCP[8], &formCP[0]}
 ,{FORMCP_LABINFO,{30,380,769,414},STATIC,"message",BSS_CENTER|BXS_VISIBLE,&formCP[9], &formCP[0]}
 ,{FORMCP_LABERROR2,{30,340,769,375},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCP[10], &formCP[0]}
 ,{FORMCP_LABERROR1,{30,300,769,335},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCP[11], &formCP[0]}
 ,{FORMCP_LABTIME,{630,430,769,469},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formCP[12], &formCP[0]}
 ,{FORMCP_LABPRODPERMIN,{30,120,769,299},STATIC,"00:00:00",BSS_CENTER|BXS_VISIBLE,&formCP[13], &formCP[0]}
 ,{FORMCP_LAB1_4,{540,430,619,469},STATIC,"Tid:",BSS_CENTER|BXS_VISIBLE,&formCP[14], &formCP[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formCP[0]}
};

BX_BOOL formCPProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formCPUpdate(hBox);
				return formCPUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formCPInit(hBox);
				return formCPUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCP_CMDRUN:
             return formCP_cmdRun_Click(hBox);
         case FORMCP_CMDSTOP:
             return formCP_cmdStop_Click(hBox);
         case FORMCP_CMDMENU:
             return formCP_cmdMenu_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
