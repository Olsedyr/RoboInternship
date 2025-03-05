//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// form2pCal.c
#include "Bx.h"
#include "form2pCal.h"

BOXSTRUCT form2pCal[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&form2pCal[1], NULL}
 ,{FORM2PCAL_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&form2pCal[2], &form2pCal[0]}
 ,{FORM2PCAL_TEXTLABEL2,{640,10,789,44},STATIC,"Version 0.0.1",BSS_RIGHT|BXS_VISIBLE,&form2pCal[3], &form2pCal[0]}
 ,{FORM2PCAL_TEXTMESSAGE,{70,180,719,214},STATIC,"Touch screen calibration.",BSS_CENTER|BXS_VISIBLE,&form2pCal[4], &form2pCal[0]}
 ,{FORM2PCAL_TEXTMSG,{70,240,719,274},STATIC,"Touch screen calibration.",BSS_CENTER|BXS_VISIBLE,&form2pCal[5], &form2pCal[0]}
 ,{FORM2PCAL_CMDLEFTTOP,{70,70,119,119},BUTTON,"+",BBS_PUSHBUTTON|BXS_VISIBLE,&form2pCal[6], &form2pCal[0]}
 ,{FORM2PCAL_CMDRIGHTBOTTOM,{690,490,739,539},BUTTON,"+",BBS_PUSHBUTTON|BXS_VISIBLE,&form2pCal[7], &form2pCal[0]}
 ,{FORM2PCAL_CMDCONTINUE,{330,480,459,569},BUTTON,"Continue",BBS_PUSHBUTTON|BXS_VISIBLE,&form2pCal[8], &form2pCal[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &form2pCal[0]}
};

BX_BOOL form2pCalProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				form2pCalUpdate(hBox);
				return form2pCalUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				form2pCalInit(hBox);
				return form2pCalUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORM2PCAL_CMDLEFTTOP:
             return form2pCal_cmdLeftTop_Click(hBox);
         case FORM2PCAL_CMDRIGHTBOTTOM:
             return form2pCal_cmdRightBottom_Click(hBox);
         case FORM2PCAL_CMDCONTINUE:
             return form2pCal_cmdContinue_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
