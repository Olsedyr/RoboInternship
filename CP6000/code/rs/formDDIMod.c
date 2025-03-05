//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDDIMod.c
#include "Bx.h"
#include "formDDIMod.h"

BOXSTRUCT formDDIMod[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formDDIMod[1], NULL}
 ,{FORMDDIMOD_CMDCLOSE,{650,480,779,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formDDIMod[2], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT1,{190,160,619,194},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[3], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT2,{190,210,619,244},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[4], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT3,{190,260,619,294},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[5], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT4,{190,310,619,344},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[6], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT5,{190,360,619,394},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[7], &formDDIMod[0]}
 ,{FORMDDIMOD_LABCONNECT6,{190,410,619,444},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDIMod[8], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2,{20,160,49,194},STATIC,"1",BXS_VISIBLE,&formDDIMod[9], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2_2,{20,210,49,244},STATIC,"2",BXS_VISIBLE,&formDDIMod[10], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2_3,{20,260,49,294},STATIC,"3",BXS_VISIBLE,&formDDIMod[11], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2_4,{20,310,49,344},STATIC,"4",BXS_VISIBLE,&formDDIMod[12], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2_5,{20,360,49,394},STATIC,"5",BXS_VISIBLE,&formDDIMod[13], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2_2_6,{20,410,49,444},STATIC,"6",BXS_VISIBLE,&formDDIMod[14], &formDDIMod[0]}
 ,{FORMDDIMOD_LABMODNAME,{190,70,619,104},STATIC,"2D4 - Module",BXS_BORDER|BXS_VISIBLE,&formDDIMod[15], &formDDIMod[0]}
 ,{FORMDDIMOD_TEXTLABEL2_2_2,{20,70,99,104},STATIC,"Name :",BXS_VISIBLE,&formDDIMod[16], &formDDIMod[0]}
 ,{FORMDDIMOD_LABTYPE,{280,10,529,44},STATIC,"Advantys modules",BSS_CENTER|BXS_VISIBLE,&formDDIMod[17], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE1,{90,160,139,199},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[18], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE2,{90,210,139,249},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[19], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE3,{90,260,139,299},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[20], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE4,{90,310,139,349},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[21], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE5,{90,360,139,399},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[22], &formDDIMod[0]}
 ,{FORMDDIMOD_CHKSTATE6,{90,410,139,449},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDIMod[23], &formDDIMod[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formDDIMod[0]}
};

BX_BOOL formDDIModProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formDDIModUpdate(hBox);
				return formDDIModUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formDDIModInit(hBox);
				return formDDIModUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMDDIMOD_CMDCLOSE:
             return formDDIMod_cmdClose_Click(hBox);
         case FORMDDIMOD_CHKSTATE1:
             return formDDIMod_chkState1_Click(hBox);
         case FORMDDIMOD_CHKSTATE2:
             return formDDIMod_chkState2_Click(hBox);
         case FORMDDIMOD_CHKSTATE3:
             return formDDIMod_chkState3_Click(hBox);
         case FORMDDIMOD_CHKSTATE4:
             return formDDIMod_chkState4_Click(hBox);
         case FORMDDIMOD_CHKSTATE5:
             return formDDIMod_chkState5_Click(hBox);
         case FORMDDIMOD_CHKSTATE6:
             return formDDIMod_chkState6_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
