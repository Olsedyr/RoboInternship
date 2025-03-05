//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDemo.c
#include "Bx.h"
#include "formDemo.h"

BOXSTRUCT formDemo[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formDemo[1], NULL}
 ,{FORMDEMO_TEXTLABEL1,{330,20,459,64},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formDemo[2], &formDemo[0]}
 ,{FORMDEMO_CMDRS,{120,160,329,259},BUTTON,"roboStacker",BBS_PUSHBUTTON|BXS_VISIBLE,&formDemo[3], &formDemo[0]}
 ,{FORMDEMO_CMDCW,{450,160,659,259},BUTTON,"checkWeigher",BBS_PUSHBUTTON|BXS_VISIBLE,&formDemo[4], &formDemo[0]}
 ,{FORMDEMO_CMDCP,{120,330,329,429},BUTTON,"casePacker",BBS_PUSHBUTTON|BXS_VISIBLE,&formDemo[5], &formDemo[0]}
 ,{FORMDEMO_CMDCM,{450,330,659,429},BUTTON,"caseMagazine",BBS_PUSHBUTTON|BXS_VISIBLE,&formDemo[6], &formDemo[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formDemo[0]}
};

BX_BOOL formDemoProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formDemoUpdate(hBox);
				return formDemoUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formDemoInit(hBox);
				return formDemoUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMDEMO_CMDRS:
             return formDemo_cmdRS_Click(hBox);
         case FORMDEMO_CMDCW:
             return formDemo_cmdCW_Click(hBox);
         case FORMDEMO_CMDCP:
             return formDemo_cmdCP_Click(hBox);
         case FORMDEMO_CMDCM:
             return formDemo_cmdCM_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
