//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditFrame.c
#include "Bx.h"
#include "formEditFrame.h"

BOXSTRUCT formEditFrame[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditFrame[1], NULL}
 ,{FORMEDITFRAME_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[2], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2,{20,10,249,45},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formEditFrame[3], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDW,{170,380,359,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[4], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3_2_2,{80,390,149,425},STATIC,"W",BSS_CENTER|BXS_VISIBLE,&formEditFrame[5], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDV,{170,310,359,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[6], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3_2,{80,320,149,355},STATIC,"V",BSS_CENTER|BXS_VISIBLE,&formEditFrame[7], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDZ,{170,240,359,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[8], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2_2_2_3_3,{80,250,149,284},STATIC,"Z",BSS_CENTER|BXS_VISIBLE,&formEditFrame[9], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDY,{170,170,359,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[10], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2_2_2_3_2,{80,180,149,214},STATIC,"Y",BSS_CENTER|BXS_VISIBLE,&formEditFrame[11], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDX,{170,100,359,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[12], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABEL2_2_2_2_3,{80,110,149,144},STATIC,"X",BSS_CENTER|BXS_VISIBLE,&formEditFrame[13], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDTHISPOS,{50,480,349,579},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[14], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[15], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDCURPOSZ,{390,240,639,299},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[16], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDCURPOSY,{390,170,639,229},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[17], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDCURPOSX,{390,100,639,159},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[18], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDCURPOSV,{390,310,639,369},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[19], &formEditFrame[0]}
 ,{FORMEDITFRAME_CMDCURPOSW,{390,380,639,439},BUTTON,"Current position",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditFrame[20], &formEditFrame[0]}
 ,{FORMEDITFRAME_GROUPBOX1,{390,10,729,79},STATIC,"Frame",BSS_WHITEFRAME|BXS_VISIBLE,&formEditFrame[21], &formEditFrame[0]}
 ,{FORMEDITFRAME_TEXTLABELNAME,{400,30,709,65},STATIC,"PalletB0",BSS_CENTER|BXS_VISIBLE,&formEditFrame[22], &formEditFrame[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditFrame[0]}
};

BX_BOOL formEditFrameProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditFrameUpdate(hBox);
				return formEditFrameUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditFrameInit(hBox);
				return formEditFrameUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITFRAME_CMDCANCEL:
             return formEditFrame_cmdCancel_Click(hBox);
         case FORMEDITFRAME_CMDW:
             return formEditFrame_cmdW_Click(hBox);
         case FORMEDITFRAME_CMDV:
             return formEditFrame_cmdV_Click(hBox);
         case FORMEDITFRAME_CMDZ:
             return formEditFrame_cmdZ_Click(hBox);
         case FORMEDITFRAME_CMDY:
             return formEditFrame_cmdY_Click(hBox);
         case FORMEDITFRAME_CMDX:
             return formEditFrame_cmdX_Click(hBox);
         case FORMEDITFRAME_CMDTHISPOS:
             return formEditFrame_cmdThisPos_Click(hBox);
         case FORMEDITFRAME_CMDRETURN:
             return formEditFrame_cmdReturn_Click(hBox);
         case FORMEDITFRAME_CMDCURPOSZ:
             return formEditFrame_cmdCurPosZ_Click(hBox);
         case FORMEDITFRAME_CMDCURPOSY:
             return formEditFrame_cmdCurPosY_Click(hBox);
         case FORMEDITFRAME_CMDCURPOSX:
             return formEditFrame_cmdCurPosX_Click(hBox);
         case FORMEDITFRAME_CMDCURPOSV:
             return formEditFrame_cmdCurPosV_Click(hBox);
         case FORMEDITFRAME_CMDCURPOSW:
             return formEditFrame_cmdCurPosW_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
