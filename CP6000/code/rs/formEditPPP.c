//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditPPP.c
#include "Bx.h"
#include "formEditPPP.h"

BOXSTRUCT formEditPPP[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditPPP[1], NULL}
 ,{FORMEDITPPP_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditPPP[2], &formEditPPP[0]}
 ,{FORMEDITPPP_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditPPP[3], &formEditPPP[0]}
 ,{FORMEDITPPP_TEXTLABEL2_2_2_2_3_3,{158,290,307,325},STATIC,"PSPEED",BSS_CENTER|BXS_VISIBLE,&formEditPPP[4], &formEditPPP[0]}
 ,{FORMEDITPPP_TEXTLABEL2_2_2_2_3_2,{180,200,279,235},STATIC,"PACC",BSS_CENTER|BXS_VISIBLE,&formEditPPP[5], &formEditPPP[0]}
 ,{FORMEDITPPP_GROUPBOX1,{390,10,729,79},STATIC,"Push",BSS_WHITEFRAME|BXS_VISIBLE,&formEditPPP[6], &formEditPPP[0]}
 ,{FORMEDITPPP_TEXTLABELNAME,{400,30,709,65},STATIC,"0",BSS_CENTER|BXS_VISIBLE,&formEditPPP[7], &formEditPPP[0]}
 ,{FORMEDITPPP_TEXTLABEL2_2,{20,10,249,45},STATIC,"CP6000",BXS_VISIBLE,&formEditPPP[8], &formEditPPP[0]}
 ,{FORMEDITPPP_TEXTLABEL2_2_2_2_3,{180,120,279,155},STATIC,"PPP",BSS_CENTER|BXS_VISIBLE,&formEditPPP[9], &formEditPPP[0]}
 ,{FORMEDITPPP_CMDPPP,{320,110,509,169},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditPPP[10], &formEditPPP[0]}
 ,{FORMEDITPPP_CMDPACC,{320,200,509,259},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditPPP[11], &formEditPPP[0]}
 ,{FORMEDITPPP_CMDPSPEED,{320,280,509,339},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditPPP[12], &formEditPPP[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditPPP[0]}
};

BX_BOOL formEditPPPProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditPPPUpdate(hBox);
				return formEditPPPUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditPPPInit(hBox);
				return formEditPPPUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITPPP_CMDCANCEL:
             return formEditPPP_cmdCancel_Click(hBox);
         case FORMEDITPPP_CMDRETURN:
             return formEditPPP_cmdReturn_Click(hBox);
         case FORMEDITPPP_CMDPPP:
             return formEditPPP_cmdPPP_Click(hBox);
         case FORMEDITPPP_CMDPACC:
             return formEditPPP_cmdPACC_Click(hBox);
         case FORMEDITPPP_CMDPSPEED:
             return formEditPPP_cmdPSPEED_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
