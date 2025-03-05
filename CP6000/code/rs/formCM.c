//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCM.c
#include "Bx.h"
#include "formCM.h"

BOXSTRUCT formCM[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formCM[1], NULL}
 ,{FORMCM_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formCM[2], &formCM[0]}
 ,{FORMCM_GROUPBOX1_2_2,{10,60,789,479},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formCM[3], &formCM[0]}
 ,{FORMCM_LABTIME,{630,430,769,469},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formCM[4], &formCM[0]}
 ,{FORMCM_LABERROR2,{30,340,769,375},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCM[5], &formCM[0]}
 ,{FORMCM_LABERROR1,{30,300,769,335},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCM[6], &formCM[0]}
 ,{FORMCM_LABWORKCELLSTATE,{30,80,769,114},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formCM[7], &formCM[0]}
 ,{FORMCM_LABINFO,{30,380,769,414},STATIC,"message",BSS_CENTER|BXS_VISIBLE,&formCM[8], &formCM[0]}
 ,{FORMCM_LABPRODPERMIN,{30,120,769,199},STATIC,"00:00:00",BSS_CENTER|BXS_VISIBLE,&formCM[9], &formCM[0]}
 ,{FORMCM_LABCASECOUNT,{30,210,769,289},STATIC,"00:00:00",BSS_CENTER|BXS_VISIBLE,&formCM[10], &formCM[0]}
 ,{FORMCM_LAB1_4,{540,430,619,469},STATIC,"Tid:",BSS_CENTER|BXS_VISIBLE,&formCM[11], &formCM[0]}
 ,{FORMCM_LABHEAD,{10,10,259,44},STATIC,"Case Magazine KM600",BXS_VISIBLE,&formCM[12], &formCM[0]}
 ,{FORMCM_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formCM[13], &formCM[0]}
 ,{FORMCM_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formCM[14], &formCM[0]}
 ,{FORMCM_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formCM[15], &formCM[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formCM[0]}
};

BX_BOOL formCMProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formCMUpdate(hBox);
				return formCMUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formCMInit(hBox);
				return formCMUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCM_CMDRUN:
             return formCM_cmdRun_Click(hBox);
         case FORMCM_CMDSTOP:
             return formCM_cmdStop_Click(hBox);
         case FORMCM_CMDMENU:
             return formCM_cmdMenu_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
