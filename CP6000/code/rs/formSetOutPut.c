//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSetOutPut.c
#include "Bx.h"
#include "formSetOutPut.h"

BOXSTRUCT formSetOutPut[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSetOutPut[1], NULL}
 ,{FORMSETOUTPUT_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formSetOutPut[2], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formSetOutPut[3], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formSetOutPut[4], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_GROUPBOX1,{60,61,610,250},STATIC,"Output",BSS_WHITEFRAME|BXS_VISIBLE,&formSetOutPut[5], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_TEXTLABEL2,{410,81,529,115},STATIC,"State",BSS_CENTER|BXS_VISIBLE,&formSetOutPut[6], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_TEXTLABEL2_2_2,{100,81,279,115},STATIC,"Number",BSS_CENTER|BXS_VISIBLE,&formSetOutPut[7], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CMDOUTPUTNUM,{130,131,249,230},BUTTON,"15",BBS_PUSHBUTTON|BXS_VISIBLE,&formSetOutPut[8], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CHKOUTPUT,{420,141,519,230},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formSetOutPut[9], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_GROUPBOX1_2,{60,271,610,460},STATIC,"Input",BSS_WHITEFRAME|BXS_VISIBLE,&formSetOutPut[10], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_TEXTLABEL2_2_2_2,{100,291,279,325},STATIC,"Number",BSS_CENTER|BXS_VISIBLE,&formSetOutPut[11], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_TEXTLABEL2_3,{410,291,529,325},STATIC,"State",BSS_CENTER|BXS_VISIBLE,&formSetOutPut[12], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CMDINPUTNUM,{130,341,249,440},BUTTON,"15",BBS_PUSHBUTTON|BXS_VISIBLE,&formSetOutPut[13], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_CHKINPUT,{420,351,519,440},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formSetOutPut[14], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_RADIOOUTPUT,{650,140,719,209},BUTTON,"Output",BBS_RADIOBOX|BXS_VISIBLE,&formSetOutPut[15], &formSetOutPut[0]}
 ,{FORMSETOUTPUT_RADIOINPUT,{650,350,729,419},BUTTON,"Input",BBS_RADIOBOX|BXS_VISIBLE,&formSetOutPut[16], &formSetOutPut[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSetOutPut[0]}
};

BX_BOOL formSetOutPutProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSetOutPutUpdate(hBox);
				return formSetOutPutUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSetOutPutInit(hBox);
				return formSetOutPutUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSETOUTPUT_CMDCANCEL:
             return formSetOutPut_cmdCancel_Click(hBox);
         case FORMSETOUTPUT_CMDRETURN:
             return formSetOutPut_cmdReturn_Click(hBox);
         case FORMSETOUTPUT_CMDOUTPUTNUM:
             return formSetOutPut_cmdOutPutNum_Click(hBox);
         case FORMSETOUTPUT_CHKOUTPUT:
             return formSetOutPut_chkOutput_Click(hBox);
         case FORMSETOUTPUT_CMDINPUTNUM:
             return formSetOutPut_cmdInPutNum_Click(hBox);
         case FORMSETOUTPUT_CHKINPUT:
             return formSetOutPut_chkInput_Click(hBox);
         case FORMSETOUTPUT_RADIOOUTPUT:
             return formSetOutPut_radioOutput_Click(hBox);
         case FORMSETOUTPUT_RADIOINPUT:
             return formSetOutPut_radioInput_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
