//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form900.c
#include "Bx.h"
#include "form900.h"

BOXSTRUCT form900[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&form900[1], NULL}
 ,{FORM900_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&form900[2], &form900[0]}
 ,{FORM900_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&form900[3], &form900[0]}
 ,{FORM900_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&form900[4], &form900[0]}
 ,{FORM900_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&form900[5], &form900[0]}
 ,{FORM900_GROUPBOX1_2_2,{10,60,789,479},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&form900[6], &form900[0]}
 ,{FORM900_LABTIME,{630,430,769,469},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&form900[7], &form900[0]}
 ,{FORM900_LAB1_4,{540,430,619,469},STATIC,"Tid:",BSS_CENTER|BXS_VISIBLE,&form900[8], &form900[0]}
 ,{FORM900_LABWORKCELLSTATE,{30,80,769,114},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&form900[9], &form900[0]}
 ,{FORM900_LABERROR1,{30,270,769,305},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&form900[10], &form900[0]}
 ,{FORM900_LABERROR2,{30,320,769,355},STATIC,"ERROR",BSS_CENTER|BXS_VISIBLE,&form900[11], &form900[0]}
 ,{FORM900_LABINFO,{30,370,769,404},STATIC,"message",BSS_CENTER|BXS_VISIBLE,&form900[12], &form900[0]}
 ,{FORM900_TEXTLABEL2_2,{10,10,279,45},STATIC,"900 Series",BXS_VISIBLE,&form900[13], &form900[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &form900[0]}
};

BX_BOOL form900Proc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				form900Update(hBox);
				return form900UserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				form900Init(hBox);
				return form900UserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORM900_CMDRUN:
             return form900_cmdRun_Click(hBox);
         case FORM900_CMDSTOP:
             return form900_cmdStop_Click(hBox);
         case FORM900_CMDMENU:
             return form900_cmdMenu_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
