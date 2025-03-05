//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formManual321.c
#include "Bx.h"
#include "formManual321.h"

BOXSTRUCT formManual321[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formManual321[1], NULL}
 ,{FORMMANUAL321_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[2], &formManual321[0]}
 ,{FORMMANUAL321_GROUPBOX1,{490,60,709,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual321[3], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_10REV,{500,90,579,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[4], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_10UP,{610,90,689,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[5], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_10CENTER,{600,170,699,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[6], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_10FWD,{500,250,579,319},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[7], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_10DOWN,{610,250,689,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[8], &formManual321[0]}
 ,{FORMMANUAL321_GROUPBOX1_2,{250,60,469,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual321[9], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_7FWD,{260,90,339,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[10], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_7UP,{370,90,449,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[11], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_7DOWN,{370,250,449,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[12], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_7REV,{260,250,339,319},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[13], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_7CENTER,{360,170,459,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[14], &formManual321[0]}
 ,{FORMMANUAL321_TEXTLABELCARDBOARD,{260,10,449,45},STATIC,"Cardboard",BSS_CENTER|BXS_VISIBLE,&formManual321[15], &formManual321[0]}
 ,{FORMMANUAL321_TEXTLABELFILLED,{30,10,219,45},STATIC,"Depalletizer",BSS_CENTER|BXS_VISIBLE,&formManual321[16], &formManual321[0]}
 ,{FORMMANUAL321_TEXTLABELFILLED_2,{510,10,699,45},STATIC,"Palletizer",BSS_CENTER|BXS_VISIBLE,&formManual321[17], &formManual321[0]}
 ,{FORMMANUAL321_GROUPBOX1_2_2,{10,60,229,329},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formManual321[18], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_3UP,{130,90,209,159},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[19], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_3DOWN,{130,250,209,319},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[20], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_3FWD,{20,90,99,159},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[21], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_3CENTER,{120,170,219,239},BUTTON,"Center",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[22], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_3REV,{20,250,99,319},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[23], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_2FWD,{130,350,209,419},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[24], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_2REV,{20,350,99,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[25], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_1REV,{20,440,99,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[26], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_1FWD,{130,440,209,509},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[27], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_6REV,{260,350,339,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[28], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_6FWD,{370,350,449,419},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[29], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_5REV,{260,440,339,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[30], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_5FWD,{370,440,449,509},BUTTON,"^",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[31], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_11FWD,{560,350,639,419},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[32], &formManual321[0]}
 ,{FORMMANUAL321_CMD4_12FWD,{560,440,639,509},BUTTON,"v",BBS_PUSHBUTTON|BXS_VISIBLE,&formManual321[33], &formManual321[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formManual321[0]}
};

BX_BOOL formManual321Proc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formManual321Update(hBox);
				return formManual321UserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formManual321Init(hBox);
				return formManual321UserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMANUAL321_CMDCANCEL:
             return formManual321_cmdCancel_Click(hBox);
         case FORMMANUAL321_CMD4_10REV:
             return formManual321_cmd4_10Rev_Click(hBox);
         case FORMMANUAL321_CMD4_10UP:
             return formManual321_cmd4_10Up_Click(hBox);
         case FORMMANUAL321_CMD4_10CENTER:
             return formManual321_cmd4_10Center_Click(hBox);
         case FORMMANUAL321_CMD4_10FWD:
             return formManual321_cmd4_10Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_10DOWN:
             return formManual321_cmd4_10Down_Click(hBox);
         case FORMMANUAL321_CMD4_7FWD:
             return formManual321_cmd4_7Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_7UP:
             return formManual321_cmd4_7Up_Click(hBox);
         case FORMMANUAL321_CMD4_7DOWN:
             return formManual321_cmd4_7Down_Click(hBox);
         case FORMMANUAL321_CMD4_7REV:
             return formManual321_cmd4_7Rev_Click(hBox);
         case FORMMANUAL321_CMD4_7CENTER:
             return formManual321_cmd4_7Center_Click(hBox);
         case FORMMANUAL321_CMD4_3UP:
             return formManual321_cmd4_3Up_Click(hBox);
         case FORMMANUAL321_CMD4_3DOWN:
             return formManual321_cmd4_3Down_Click(hBox);
         case FORMMANUAL321_CMD4_3FWD:
             return formManual321_cmd4_3Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_3CENTER:
             return formManual321_cmd4_3Center_Click(hBox);
         case FORMMANUAL321_CMD4_3REV:
             return formManual321_cmd4_3Rev_Click(hBox);
         case FORMMANUAL321_CMD4_2FWD:
             return formManual321_cmd4_2Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_2REV:
             return formManual321_cmd4_2Rev_Click(hBox);
         case FORMMANUAL321_CMD4_1REV:
             return formManual321_cmd4_1Rev_Click(hBox);
         case FORMMANUAL321_CMD4_1FWD:
             return formManual321_cmd4_1Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_6REV:
             return formManual321_cmd4_6Rev_Click(hBox);
         case FORMMANUAL321_CMD4_6FWD:
             return formManual321_cmd4_6Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_5REV:
             return formManual321_cmd4_5Rev_Click(hBox);
         case FORMMANUAL321_CMD4_5FWD:
             return formManual321_cmd4_5Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_11FWD:
             return formManual321_cmd4_11Fwd_Click(hBox);
         case FORMMANUAL321_CMD4_12FWD:
             return formManual321_cmd4_12Fwd_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
