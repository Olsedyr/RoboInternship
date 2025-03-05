//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formNumKeyboard.c
#include "Bx.h"
#include "formNumKeyboard.h"

BOXSTRUCT formNumKeyboard[] = {
 {10000,{0,0,800,600},DIALOG,"",BXS_VISIBLE,&formNumKeyboard[1], NULL}
 ,{FORMNUMKEYBOARD_CMDENTER,{510,480,639,579},BUTTON,"Enter",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[2], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMDCANCEL,{650,480,779,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[3], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMSNEG,{510,370,639,459},BUTTON,"+/-",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[4], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMDCOMMA,{370,370,499,459},BUTTON,",",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[5], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMDZERO,{90,370,359,459},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[6], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD1,{90,270,219,359},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[7], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD7,{90,70,219,159},BUTTON,"7",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[8], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD5,{230,170,359,259},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[9], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD3,{370,270,499,359},BUTTON,"3",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[10], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD9,{370,70,499,159},BUTTON,"9",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[11], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD2,{230,270,359,359},BUTTON,"2",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[12], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMDMINUS,{510,170,639,259},BUTTON,"-",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[13], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD4,{90,170,219,259},BUTTON,"4",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[14], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD8,{230,70,359,159},BUTTON,"8",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[15], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMD6,{370,170,499,259},BUTTON,"6",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[16], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMSCLEAR,{510,270,639,359},BUTTON,"Clear",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[17], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_CMDPLUS,{510,70,639,159},BUTTON,"+",BBS_PUSHBUTTON|BXS_VISIBLE,&formNumKeyboard[18], &formNumKeyboard[0]}
 ,{FORMNUMKEYBOARD_TEXTLABEL1,{90,20,639,59},STATIC,"0",BXS_BORDER|BXS_VISIBLE,&formNumKeyboard[19], &formNumKeyboard[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formNumKeyboard[0]}
};

BX_BOOL formNumKeyboardProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formNumKeyboardUpdate(hBox);
				return formNumKeyboardUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formNumKeyboardInit(hBox);
				return formNumKeyboardUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMNUMKEYBOARD_CMDENTER:
             return formNumKeyboard_cmdEnter_Click(hBox);
         case FORMNUMKEYBOARD_CMDCANCEL:
             return formNumKeyboard_cmdCancel_Click(hBox);
         case FORMNUMKEYBOARD_CMSNEG:
             return formNumKeyboard_cmsNeg_Click(hBox);
         case FORMNUMKEYBOARD_CMDCOMMA:
             return formNumKeyboard_cmdComma_Click(hBox);
         case FORMNUMKEYBOARD_CMDZERO:
             return formNumKeyboard_cmdZero_Click(hBox);
         case FORMNUMKEYBOARD_CMD1:
             return formNumKeyboard_cmd1_Click(hBox);
         case FORMNUMKEYBOARD_CMD7:
             return formNumKeyboard_cmd7_Click(hBox);
         case FORMNUMKEYBOARD_CMD5:
             return formNumKeyboard_cmd5_Click(hBox);
         case FORMNUMKEYBOARD_CMD3:
             return formNumKeyboard_cmd3_Click(hBox);
         case FORMNUMKEYBOARD_CMD9:
             return formNumKeyboard_cmd9_Click(hBox);
         case FORMNUMKEYBOARD_CMD2:
             return formNumKeyboard_cmd2_Click(hBox);
         case FORMNUMKEYBOARD_CMDMINUS:
             return formNumKeyboard_cmdMinus_Click(hBox);
         case FORMNUMKEYBOARD_CMD4:
             return formNumKeyboard_cmd4_Click(hBox);
         case FORMNUMKEYBOARD_CMD8:
             return formNumKeyboard_cmd8_Click(hBox);
         case FORMNUMKEYBOARD_CMD6:
             return formNumKeyboard_cmd6_Click(hBox);
         case FORMNUMKEYBOARD_CMSCLEAR:
             return formNumKeyboard_cmsClear_Click(hBox);
         case FORMNUMKEYBOARD_CMDPLUS:
             return formNumKeyboard_cmdPlus_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
