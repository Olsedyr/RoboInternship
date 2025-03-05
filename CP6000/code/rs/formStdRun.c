//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formStdRun.c
#include "Bx.h"
#include "formStdRun.h"

BOXSTRUCT formStdRun[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formStdRun[1], NULL}
 ,{FORMSTDRUN_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2050",BXS_VISIBLE,&formStdRun[2], &formStdRun[0]}
 ,{FORMSTDRUN_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formStdRun[3], &formStdRun[0]}
 ,{FORMSTDRUN_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formStdRun[4], &formStdRun[0]}
 ,{FORMSTDRUN_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formStdRun[5], &formStdRun[0]}
 ,{FORMSTDRUN_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formStdRun[6], &formStdRun[0]}
 ,{FORMSTDRUN_TEXTLABEL2_2_2,{10,450,119,485},STATIC,"Hastighed",BSS_CENTER|BXS_VISIBLE,&formStdRun[7], &formStdRun[0]}
 ,{FORMSTDRUN_CMDSPEED,{10,490,119,579},BUTTON,"50.0",BBS_PUSHBUTTON|BXS_VISIBLE,&formStdRun[8], &formStdRun[0]}
 ,{FORMSTDRUN_GROUPBOX1_2_2,{10,70,789,449},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formStdRun[9], &formStdRun[0]}
 ,{FORMSTDRUN_LABWORKCELLSTATE,{30,110,769,144},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formStdRun[10], &formStdRun[0]}
 ,{FORMSTDRUN_LABERROR1,{30,210,769,244},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formStdRun[11], &formStdRun[0]}
 ,{FORMSTDRUN_LABERROR2,{30,250,769,284},STATIC,"Information",BSS_CENTER|BXS_VISIBLE,&formStdRun[12], &formStdRun[0]}
 ,{FORMSTDRUN_LABINFO,{30,310,769,344},STATIC,"Information",BSS_CENTER|BXS_VISIBLE,&formStdRun[13], &formStdRun[0]}
 ,{FORMSTDRUN_LABROBOTSTATE,{30,150,769,184},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formStdRun[14], &formStdRun[0]}
 ,{FORMSTDRUN_LABTIME,{30,390,769,429},STATIC,"Produkter: 9       Paller: 3             Tid: 01:23:33",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formStdRun[15], &formStdRun[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formStdRun[0]}
};

BX_BOOL formStdRunProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formStdRunUpdate(hBox);
				return formStdRunUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formStdRunInit(hBox);
				return formStdRunUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSTDRUN_CMDMENU:
             return formStdRun_cmdMenu_Click(hBox);
         case FORMSTDRUN_CMDSTOP:
             return formStdRun_cmdStop_Click(hBox);
         case FORMSTDRUN_CMDRUN:
             return formStdRun_cmdRun_Click(hBox);
         case FORMSTDRUN_CMDSPEED:
             return formStdRun_cmdSpeed_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
