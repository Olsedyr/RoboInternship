//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formInterrupt.c
#include "Bx.h"
#include "formInterrupt.h"

BOXSTRUCT formInterrupt[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formInterrupt[1], NULL}
 ,{FORMINTERRUPT_TEXTLABEL2,{640,10,789,44},STATIC,"Version 0.0.1",BSS_RIGHT|BXS_VISIBLE,&formInterrupt[2], &formInterrupt[0]}
 ,{FORMINTERRUPT_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formInterrupt[3], &formInterrupt[0]}
 ,{FORMINTERRUPT_TXTALERT,{30,130,759,164},STATIC,"roboStacker er stoppet!",BSS_CENTER|BXS_VISIBLE,&formInterrupt[4], &formInterrupt[0]}
 ,{FORMINTERRUPT_TXTSOLUTION,{60,310,749,344},STATIC,"Fjern nødstop og tryk reset.",BSS_CENTER|BXS_VISIBLE,&formInterrupt[5], &formInterrupt[0]}
 ,{FORMINTERRUPT_TXTREASON,{60,230,749,264},STATIC,"Nødstop er aktiveret.",BSS_CENTER|BXS_VISIBLE,&formInterrupt[6], &formInterrupt[0]}
 ,{FORMINTERRUPT_CMDCONTINUE,{650,490,779,579},BUTTON,"Continue",BBS_PUSHBUTTON|BXS_VISIBLE,&formInterrupt[7], &formInterrupt[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formInterrupt[0]}
};

BX_BOOL formInterruptProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formInterruptUpdate(hBox);
				return formInterruptUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formInterruptInit(hBox);
				return formInterruptUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMINTERRUPT_CMDCONTINUE:
             return formInterrupt_cmdContinue_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
