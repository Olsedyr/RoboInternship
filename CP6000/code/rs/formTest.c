//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTest.c
#include "Bx.h"
#include "formTest.h"

BOXSTRUCT formTest[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formTest[1], NULL}
 ,{FORMTEST_TEXTLABEL2_2_2,{10,490,119,518},STATIC,"Hastighed",BSS_CENTER|BXS_VISIBLE,&formTest[2], &formTest[0]}
 ,{FORMTEST_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formTest[3], &formTest[0]}
 ,{FORMTEST_CMDSPEED,{10,520,119,579},BUTTON,"50.0",BBS_PUSHBUTTON|BXS_VISIBLE,&formTest[4], &formTest[0]}
 ,{FORMTEST_GROUPBOX1_2_2,{10,60,789,479},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formTest[5], &formTest[0]}
 ,{FORMTEST_LAB1_4,{540,430,619,469},STATIC,"Tid:",BSS_CENTER|BXS_VISIBLE,&formTest[6], &formTest[0]}
 ,{FORMTEST_LABTIME,{630,430,769,469},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formTest[7], &formTest[0]}
 ,{FORMTEST_LABWORKCELLSTATE,{30,80,769,114},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formTest[8], &formTest[0]}
 ,{FORMTEST_LABINFO,{30,380,769,414},STATIC,"Information",BSS_CENTER|BXS_VISIBLE,&formTest[9], &formTest[0]}
 ,{FORMTEST_TEXTLABEL2_2,{10,10,259,44},STATIC,"test",BXS_VISIBLE,&formTest[10], &formTest[0]}
 ,{FORMTEST_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formTest[11], &formTest[0]}
 ,{FORMTEST_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formTest[12], &formTest[0]}
 ,{FORMTEST_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formTest[13], &formTest[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formTest[0]}
};

BX_BOOL formTestProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formTestUpdate(hBox);
				return formTestUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formTestInit(hBox);
				return formTestUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMTEST_CMDSPEED:
             return formTest_cmdSpeed_Click(hBox);
         case FORMTEST_CMDRUN:
             return formTest_cmdRun_Click(hBox);
         case FORMTEST_CMDSTOP:
             return formTest_cmdStop_Click(hBox);
         case FORMTEST_CMDMENU:
             return formTest_cmdMenu_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
