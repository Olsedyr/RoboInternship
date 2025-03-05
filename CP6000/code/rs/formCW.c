//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCW.c
#include "Bx.h"
#include "formCW.h"

BOXSTRUCT formCW[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formCW[1], NULL}
 ,{FORMCW_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formCW[2], &formCW[0]}
 ,{FORMCW_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formCW[3], &formCW[0]}
 ,{FORMCW_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formCW[4], &formCW[0]}
 ,{FORMCW_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formCW[5], &formCW[0]}
 ,{FORMCW_TEXTLABEL2_2,{10,10,259,44},STATIC,"checkWeigher CW5000",BXS_VISIBLE,&formCW[6], &formCW[0]}
 ,{FORMCW_LOWER,{10,520,179,579},BUTTON,"440",BBS_PUSHBUTTON|BXS_VISIBLE,&formCW[7], &formCW[0]}
 ,{FORMCW_UPPER,{180,520,349,579},BUTTON,"550",BBS_PUSHBUTTON|BXS_VISIBLE,&formCW[8], &formCW[0]}
 ,{FORMCW_TEXTLABEL2_2_2_3,{10,480,349,515},STATIC,"Nedre < Vægt < Øvre",BSS_CENTER|BXS_VISIBLE,&formCW[9], &formCW[0]}
 ,{FORMCW_GROUPBOX1_2_2,{10,60,789,479},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formCW[10], &formCW[0]}
 ,{FORMCW_LABTIME,{630,430,769,469},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formCW[11], &formCW[0]}
 ,{FORMCW_LABWEIGHT,{30,120,769,299},STATIC,"00:00:00",BSS_CENTER|BXS_VISIBLE,&formCW[12], &formCW[0]}
 ,{FORMCW_LABERROR1,{30,300,769,335},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCW[13], &formCW[0]}
 ,{FORMCW_LABWORKCELLSTATE,{30,80,769,114},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formCW[14], &formCW[0]}
 ,{FORMCW_LABINFO,{30,380,769,414},STATIC,"message",BSS_CENTER|BXS_VISIBLE,&formCW[15], &formCW[0]}
 ,{FORMCW_LABERROR2,{30,340,769,375},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&formCW[16], &formCW[0]}
 ,{FORMCW_LABWEIGHT_2,{30,430,529,467},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formCW[17], &formCW[0]}
 ,{FORMCW_LAB1_4,{540,430,619,469},STATIC,"Tid:",BSS_CENTER|BXS_VISIBLE,&formCW[18], &formCW[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formCW[0]}
};

BX_BOOL formCWProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formCWUpdate(hBox);
				return formCWUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formCWInit(hBox);
				return formCWUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMCW_CMDMENU:
             return formCW_cmdMenu_Click(hBox);
         case FORMCW_CMDSTOP:
             return formCW_cmdStop_Click(hBox);
         case FORMCW_CMDRUN:
             return formCW_cmdRun_Click(hBox);
         case FORMCW_LOWER:
             return formCW_Lower_Click(hBox);
         case FORMCW_UPPER:
             return formCW_Upper_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
