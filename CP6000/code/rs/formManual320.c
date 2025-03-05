//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual320.c
#include "Bx.h"
#include "formManual320.h"

BOXSTRUCT formManual320[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formManual320[1], NULL}
 ,{FORMMANUAL320_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[2], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_1FWD,{510,440,589,509},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[3], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_9FWD,{140,440,219,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[4], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_8FWD,{140,350,219,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[5], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_2FWD,{510,350,589,419},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[6], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_2REV,{400,350,479,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[7], &formManual320[0]}
 ,{FORMMANUAL320_GROUPBOX1,{40,60,309,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual320[8], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_6REV,{70,90,149,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[9], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_6FWD,{70,240,149,309},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[10], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_6UP,{200,90,279,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[11], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_6CENTER,{190,170,289,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[12], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_6DOWN,{200,250,279,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[13], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_1REV,{400,440,479,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[14], &formManual320[0]}
 ,{FORMMANUAL320_TEXTLABELFILLED,{80,10,269,45},STATIC,"Filled Cans/Jars",BSS_CENTER|BXS_VISIBLE,&formManual320[15], &formManual320[0]}
 ,{FORMMANUAL320_GROUPBOX1_2,{360,60,629,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual320[16], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_3REV,{390,240,469,309},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[17], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_3CENTER,{510,170,609,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[18], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_3UP,{520,90,599,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[19], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_3FWD,{390,90,469,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[20], &formManual320[0]}
 ,{FORMMANUAL320_CMD3_3DOWN,{520,250,599,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual320[21], &formManual320[0]}
 ,{FORMMANUAL320_TEXTLABELCARDBOARD,{400,10,589,45},STATIC,"Cardboard",BSS_CENTER|BXS_VISIBLE,&formManual320[22], &formManual320[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formManual320[0]}
};

BX_BOOL formManual320Proc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formManual320Update(hBox);
				return formManual320UserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formManual320Init(hBox);
				return formManual320UserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMANUAL320_CMDCANCEL:
             return formManual320_cmdCancel_Click(hBox);
         case FORMMANUAL320_CMD3_1FWD:
             return formManual320_cmd3_1Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_9FWD:
             return formManual320_cmd3_9Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_8FWD:
             return formManual320_cmd3_8Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_2FWD:
             return formManual320_cmd3_2Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_2REV:
             return formManual320_cmd3_2Rev_Click(hBox);
         case FORMMANUAL320_CMD3_6REV:
             return formManual320_cmd3_6Rev_Click(hBox);
         case FORMMANUAL320_CMD3_6FWD:
             return formManual320_cmd3_6Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_6UP:
             return formManual320_cmd3_6Up_Click(hBox);
         case FORMMANUAL320_CMD3_6CENTER:
             return formManual320_cmd3_6Center_Click(hBox);
         case FORMMANUAL320_CMD3_6DOWN:
             return formManual320_cmd3_6Down_Click(hBox);
         case FORMMANUAL320_CMD3_1REV:
             return formManual320_cmd3_1Rev_Click(hBox);
         case FORMMANUAL320_CMD3_3REV:
             return formManual320_cmd3_3Rev_Click(hBox);
         case FORMMANUAL320_CMD3_3CENTER:
             return formManual320_cmd3_3Center_Click(hBox);
         case FORMMANUAL320_CMD3_3UP:
             return formManual320_cmd3_3Up_Click(hBox);
         case FORMMANUAL320_CMD3_3FWD:
             return formManual320_cmd3_3Fwd_Click(hBox);
         case FORMMANUAL320_CMD3_3DOWN:
             return formManual320_cmd3_3Down_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
