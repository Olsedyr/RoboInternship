//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual319.c
#include "Bx.h"
#include "formManual319.h"

BOXSTRUCT formManual319[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formManual319[1], NULL}
 ,{FORMMANUAL319_TEXTLABELFILLED,{290,10,479,45},STATIC,"Filled Cans/Jars",BSS_CENTER|BXS_VISIBLE,&formManual319[2], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_1REV,{290,440,369,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[3], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_1FWD,{400,440,479,509},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[4], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_2FWD,{400,350,479,419},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[5], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_2REV,{290,350,369,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[6], &formManual319[0]}
 ,{FORMMANUAL319_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[7], &formManual319[0]}
 ,{FORMMANUAL319_GROUPBOX1_2_2,{280,60,499,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual319[8], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_3FWD,{290,90,369,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[9], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_3REV,{290,250,369,319},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[10], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_3DOWN,{400,250,479,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[11], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_3CENTER,{390,170,489,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[12], &formManual319[0]}
 ,{FORMMANUAL319_CMD2_3UP,{400,90,479,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual319[13], &formManual319[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formManual319[0]}
};

BX_BOOL formManual319Proc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formManual319Update(hBox);
				return formManual319UserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formManual319Init(hBox);
				return formManual319UserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMANUAL319_CMD2_1REV:
             return formManual319_cmd2_1Rev_Click(hBox);
         case FORMMANUAL319_CMD2_1FWD:
             return formManual319_cmd2_1Fwd_Click(hBox);
         case FORMMANUAL319_CMD2_2FWD:
             return formManual319_cmd2_2Fwd_Click(hBox);
         case FORMMANUAL319_CMD2_2REV:
             return formManual319_cmd2_2Rev_Click(hBox);
         case FORMMANUAL319_CMDCANCEL:
             return formManual319_cmdCancel_Click(hBox);
         case FORMMANUAL319_CMD2_3FWD:
             return formManual319_cmd2_3Fwd_Click(hBox);
         case FORMMANUAL319_CMD2_3REV:
             return formManual319_cmd2_3Rev_Click(hBox);
         case FORMMANUAL319_CMD2_3DOWN:
             return formManual319_cmd2_3Down_Click(hBox);
         case FORMMANUAL319_CMD2_3CENTER:
             return formManual319_cmd2_3Center_Click(hBox);
         case FORMMANUAL319_CMD2_3UP:
             return formManual319_cmd2_3Up_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
