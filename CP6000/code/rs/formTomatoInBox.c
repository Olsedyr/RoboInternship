//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formTomatoInBox.c
#include "Bx.h"
#include "formTomatoInBox.h"

BOXSTRUCT formTomatoInBox[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formTomatoInBox[1], NULL}
 ,{FORMTOMATOINBOX_TEXTLABEL1,{660,10,788,54},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formTomatoInBox[2], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2050",BXS_VISIBLE,&formTomatoInBox[3], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDMENU,{670,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[4], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDSPEED,{10,490,119,579},BUTTON,"50.0",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[5], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDLAG,{130,490,239,579},BUTTON,"7",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[6], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDNUMBOX,{250,490,359,579},BUTTON,"500",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[7], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_TEXTLABEL2_2_2,{10,450,119,484},STATIC,"Hastighed",BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[8], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_TEXTLABEL2_2_3,{130,450,229,484},STATIC,"Lag",BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[9], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LAB1_2,{250,450,349,484},STATIC,"Kasser",BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[10], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDRUN,{390,490,509,579},BUTTON,"Kør",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[11], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_CMDSTOP,{520,490,639,579},BUTTON,"Stop",BBS_PUSHBUTTON|BXS_VISIBLE,&formTomatoInBox[12], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_GROUPBOX1_2_2,{10,70,789,429},STATIC,"Information",BSS_WHITEFRAME|BXS_VISIBLE,&formTomatoInBox[13], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LAB1_3,{40,360,179,394},STATIC,"Antal paller:",BXS_VISIBLE,&formTomatoInBox[14], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LABINFO,{40,210,739,244},STATIC,"Information",BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[15], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LABINFOTYPE,{50,150,739,184},STATIC,"Information type",BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[16], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LAB1,{40,300,179,334},STATIC,"Antal kasser:",BXS_VISIBLE,&formTomatoInBox[17], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LAB1_4,{460,300,529,334},STATIC,"Tid:",BXS_VISIBLE,&formTomatoInBox[18], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LABTIME,{560,290,759,339},STATIC,"00:00:00",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[19], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LABNUMBOX,{210,295,349,344},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[20], &formTomatoInBox[0]}
 ,{FORMTOMATOINBOX_LABNUMPALLET,{210,355,349,404},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formTomatoInBox[21], &formTomatoInBox[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formTomatoInBox[0]}
};

BX_BOOL formTomatoInBoxProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formTomatoInBoxUpdate(hBox);
				return formTomatoInBoxUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formTomatoInBoxInit(hBox);
				return formTomatoInBoxUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMTOMATOINBOX_CMDMENU:
             return formTomatoInBox_cmdMenu_Click(hBox);
         case FORMTOMATOINBOX_CMDSPEED:
             return formTomatoInBox_cmdSpeed_Click(hBox);
         case FORMTOMATOINBOX_CMDLAG:
             return formTomatoInBox_cmdLag_Click(hBox);
         case FORMTOMATOINBOX_CMDNUMBOX:
             return formTomatoInBox_cmdNumBox_Click(hBox);
         case FORMTOMATOINBOX_CMDRUN:
             return formTomatoInBox_cmdRun_Click(hBox);
         case FORMTOMATOINBOX_CMDSTOP:
             return formTomatoInBox_cmdStop_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
