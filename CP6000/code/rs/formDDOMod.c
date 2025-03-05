//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDDOMod.c
#include "Bx.h"
#include "formDDOMod.h"

BOXSTRUCT formDDOMod[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formDDOMod[1], NULL}
 ,{FORMDDOMOD_CMDCLOSE,{650,480,779,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formDDOMod[2], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT2,{190,210,619,244},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[3], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT3,{190,260,619,294},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[4], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT4,{190,310,619,344},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[5], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT5,{190,360,619,394},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[6], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT6,{190,410,619,444},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[7], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2,{20,160,49,194},STATIC,"1",BXS_VISIBLE,&formDDOMod[8], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2_2,{20,210,49,244},STATIC,"2",BXS_VISIBLE,&formDDOMod[9], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2_3,{20,260,49,294},STATIC,"3",BXS_VISIBLE,&formDDOMod[10], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2_4,{20,310,49,344},STATIC,"4",BXS_VISIBLE,&formDDOMod[11], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2_5,{20,360,49,394},STATIC,"5",BXS_VISIBLE,&formDDOMod[12], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2_2_6,{20,410,49,444},STATIC,"6",BXS_VISIBLE,&formDDOMod[13], &formDDOMod[0]}
 ,{FORMDDOMOD_TEXTLABEL2_2_2,{20,70,99,104},STATIC,"Name :",BXS_VISIBLE,&formDDOMod[14], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE2,{90,210,139,249},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[15], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE3,{90,260,139,299},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[16], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE4,{90,310,139,349},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[17], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE5,{90,360,139,399},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[18], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE6,{90,410,139,449},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[19], &formDDOMod[0]}
 ,{FORMDDOMOD_CHKSTATE1,{90,160,139,199},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formDDOMod[20], &formDDOMod[0]}
 ,{FORMDDOMOD_LABCONNECT1,{190,160,619,194},STATIC,"Foto",BXS_BORDER|BXS_VISIBLE,&formDDOMod[21], &formDDOMod[0]}
 ,{FORMDDOMOD_LABMODNAME,{190,70,619,104},STATIC,"2D4 - Module",BXS_BORDER|BXS_VISIBLE,&formDDOMod[22], &formDDOMod[0]}
 ,{FORMDDOMOD_LABTYPE,{280,10,529,44},STATIC,"Advantys modules",BSS_CENTER|BXS_VISIBLE,&formDDOMod[23], &formDDOMod[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formDDOMod[0]}
};

BX_BOOL formDDOModProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formDDOModUpdate(hBox);
				return formDDOModUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formDDOModInit(hBox);
				return formDDOModUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMDDOMOD_CMDCLOSE:
             return formDDOMod_cmdClose_Click(hBox);
         case FORMDDOMOD_CHKSTATE2:
             return formDDOMod_chkState2_Click(hBox);
         case FORMDDOMOD_CHKSTATE3:
             return formDDOMod_chkState3_Click(hBox);
         case FORMDDOMOD_CHKSTATE4:
             return formDDOMod_chkState4_Click(hBox);
         case FORMDDOMOD_CHKSTATE5:
             return formDDOMod_chkState5_Click(hBox);
         case FORMDDOMOD_CHKSTATE6:
             return formDDOMod_chkState6_Click(hBox);
         case FORMDDOMOD_CHKSTATE1:
             return formDDOMod_chkState1_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
