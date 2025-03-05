//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSads.c
#include "Bx.h"
#include "formSads.h"

BOXSTRUCT formSads[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSads[1], NULL}
 ,{FORMSADS_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formSads[2], &formSads[0]}
 ,{FORMSADS_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[3], &formSads[0]}
 ,{FORMSADS_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[4], &formSads[0]}
 ,{FORMSADS_GROUPBOX1,{30,70,769,460},STATIC,"Speed/Accel/Decel",BSS_WHITEFRAME|BXS_VISIBLE,&formSads[5], &formSads[0]}
 ,{FORMSADS_CMDSRAMA,{500,320,609,389},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[6], &formSads[0]}
 ,{FORMSADS_CMDDECELA,{470,170,639,239},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[7], &formSads[0]}
 ,{FORMSADS_TEXTLABEL2_2_2_2_2_2,{500,270,609,304},STATIC,"Sramp",BSS_CENTER|BXS_VISIBLE,&formSads[8], &formSads[0]}
 ,{FORMSADS_TEXTLABEL2_2_2_2_2,{470,120,629,154},STATIC,"Decel",BSS_CENTER|BXS_VISIBLE,&formSads[9], &formSads[0]}
 ,{FORMSADS_CMDACCELA,{130,170,299,239},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[10], &formSads[0]}
 ,{FORMSADS_TEXTLABEL2_2_2_2,{120,120,309,154},STATIC,"Accel",BSS_CENTER|BXS_VISIBLE,&formSads[11], &formSads[0]}
 ,{FORMSADS_TEXTLABEL2_2_2,{120,270,309,304},STATIC,"Speed",BSS_CENTER|BXS_VISIBLE,&formSads[12], &formSads[0]}
 ,{FORMSADS_CMDSPEEDA,{130,320,299,389},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formSads[13], &formSads[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSads[0]}
};

BX_BOOL formSadsProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSadsUpdate(hBox);
				return formSadsUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSadsInit(hBox);
				return formSadsUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSADS_CMDCANCEL:
             return formSads_cmdCancel_Click(hBox);
         case FORMSADS_CMDRETURN:
             return formSads_cmdReturn_Click(hBox);
         case FORMSADS_CMDSRAMA:
             return formSads_cmdSramA_Click(hBox);
         case FORMSADS_CMDDECELA:
             return formSads_cmdDecelA_Click(hBox);
         case FORMSADS_CMDACCELA:
             return formSads_cmdAccelA_Click(hBox);
         case FORMSADS_CMDSPEEDA:
             return formSads_cmdSpeedA_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
