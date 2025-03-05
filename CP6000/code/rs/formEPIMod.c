//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEPIMod.c
#include "Bx.h"
#include "formEPIMod.h"

BOXSTRUCT formEPIMod[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEPIMod[1], NULL}
 ,{FORMEPIMOD_CMDCLOSE,{650,480,779,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formEPIMod[2], &formEPIMod[0]}
 ,{FORMEPIMOD_LABCONNECT2,{190,210,619,244},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formEPIMod[3], &formEPIMod[0]}
 ,{FORMEPIMOD_LABCONNECT3,{190,260,619,294},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formEPIMod[4], &formEPIMod[0]}
 ,{FORMEPIMOD_LABCONNECT4,{190,310,619,344},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formEPIMod[5], &formEPIMod[0]}
 ,{FORMEPIMOD_LABMODNAME,{190,70,619,104},STATIC,"2D4 - Module",BXS_BORDER|BXS_VISIBLE,&formEPIMod[6], &formEPIMod[0]}
 ,{FORMEPIMOD_LABTYPE,{280,10,529,44},STATIC,"Advantys modules",BSS_CENTER|BXS_VISIBLE,&formEPIMod[7], &formEPIMod[0]}
 ,{FORMEPIMOD_LABCONNECT1,{190,160,619,194},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formEPIMod[8], &formEPIMod[0]}
 ,{FORMEPIMOD_LABSTATE1,{640,160,779,194},STATIC,"Running",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEPIMod[9], &formEPIMod[0]}
 ,{FORMEPIMOD_LABSTATE2,{640,210,779,244},STATIC,"Running",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEPIMod[10], &formEPIMod[0]}
 ,{FORMEPIMOD_LABSTATE3,{640,260,779,294},STATIC,"Running",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEPIMod[11], &formEPIMod[0]}
 ,{FORMEPIMOD_LABSTATE4,{640,310,779,344},STATIC,"Running",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEPIMod[12], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_2,{20,160,49,194},STATIC,"1",BXS_VISIBLE,&formEPIMod[13], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_2_2,{20,210,49,244},STATIC,"2",BXS_VISIBLE,&formEPIMod[14], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_2_3,{20,260,49,294},STATIC,"3",BXS_VISIBLE,&formEPIMod[15], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_2_4,{20,310,49,344},STATIC,"4",BXS_VISIBLE,&formEPIMod[16], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE1,{60,160,109,199},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[17], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE1_2,{130,160,179,199},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[18], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE2,{60,210,109,249},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[19], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE2_2,{130,210,179,249},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[20], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE3,{60,260,109,299},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[21], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE3_2,{130,260,179,299},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[22], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE4,{60,310,109,349},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[23], &formEPIMod[0]}
 ,{FORMEPIMOD_CHKSTATE4_2,{130,310,179,349},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formEPIMod[24], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2,{20,70,99,104},STATIC,"Name :",BXS_VISIBLE,&formEPIMod[25], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_3,{50,120,99,154},STATIC,"Fwd",BXS_VISIBLE,&formEPIMod[26], &formEPIMod[0]}
 ,{FORMEPIMOD_TEXTLABEL2_2_2_3_2,{120,120,169,154},STATIC,"Rev",BXS_VISIBLE,&formEPIMod[27], &formEPIMod[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEPIMod[0]}
};

BX_BOOL formEPIModProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEPIModUpdate(hBox);
				return formEPIModUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEPIModInit(hBox);
				return formEPIModUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEPIMOD_CMDCLOSE:
             return formEPIMod_cmdClose_Click(hBox);
         case FORMEPIMOD_CHKSTATE1:
             return formEPIMod_chkState1_Click(hBox);
         case FORMEPIMOD_CHKSTATE1_2:
             return formEPIMod_chkState1_2_Click(hBox);
         case FORMEPIMOD_CHKSTATE2:
             return formEPIMod_chkState2_Click(hBox);
         case FORMEPIMOD_CHKSTATE2_2:
             return formEPIMod_chkState2_2_Click(hBox);
         case FORMEPIMOD_CHKSTATE3:
             return formEPIMod_chkState3_Click(hBox);
         case FORMEPIMOD_CHKSTATE3_2:
             return formEPIMod_chkState3_2_Click(hBox);
         case FORMEPIMOD_CHKSTATE4:
             return formEPIMod_chkState4_Click(hBox);
         case FORMEPIMOD_CHKSTATE4_2:
             return formEPIMod_chkState4_2_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
