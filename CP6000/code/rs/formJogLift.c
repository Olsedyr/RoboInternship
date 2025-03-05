//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogLift.c
#include "Bx.h"
#include "formJogLift.h"

BOXSTRUCT formJogLift[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formJogLift[1], NULL}
 ,{FORMJOGLIFT_CMDUP,{360,70,439,139},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogLift[2], &formJogLift[0]}
 ,{FORMJOGLIFT_CMDDOWN,{360,220,439,289},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogLift[3], &formJogLift[0]}
 ,{FORMJOGLIFT_CMDSTEP,{10,480,129,579},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogLift[4], &formJogLift[0]}
 ,{FORMJOGLIFT_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogLift[5], &formJogLift[0]}
 ,{FORMJOGLIFT_VALUELABELCURPOS,{310,160,489,199},STATIC,"0.000",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formJogLift[6], &formJogLift[0]}
 ,{FORMJOGLIFT_TEXTLABELMESSAGE1,{10,320,789,355},STATIC,"Message 1",BSS_CENTER|BXS_VISIBLE,&formJogLift[7], &formJogLift[0]}
 ,{FORMJOGLIFT_TEXTLABELMESSAGE2,{10,370,789,405},STATIC,"Message 2",BSS_CENTER|BXS_VISIBLE,&formJogLift[8], &formJogLift[0]}
 ,{FORMJOGLIFT_TEXTLABELSTEP,{10,440,129,475},STATIC,"Step (mm)",BSS_CENTER|BXS_VISIBLE,&formJogLift[9], &formJogLift[0]}
 ,{FORMJOGLIFT_TEXTLABELNAME,{10,10,99,45},STATIC,"Jog Lift",BXS_VISIBLE,&formJogLift[10], &formJogLift[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formJogLift[0]}
};

BX_BOOL formJogLiftProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formJogLiftUpdate(hBox);
				return formJogLiftUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formJogLiftInit(hBox);
				return formJogLiftUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMJOGLIFT_CMDUP:
             return formJogLift_cmdUp_Click(hBox);
         case FORMJOGLIFT_CMDDOWN:
             return formJogLift_cmdDown_Click(hBox);
         case FORMJOGLIFT_CMDSTEP:
             return formJogLift_cmdStep_Click(hBox);
         case FORMJOGLIFT_CMDCANCEL:
             return formJogLift_cmdCancel_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
