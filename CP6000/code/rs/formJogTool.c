//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formJogTool.c
#include "Bx.h"
#include "formJogTool.h"

BOXSTRUCT formJogTool[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formJogTool[1], NULL}
 ,{FORMJOGTOOL_GROUPBOX2,{410,20,749,439},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formJogTool[2], &formJogTool[0]}
 ,{FORMJOGTOOL_TEXTLABELSTEPMM,{520,320,639,354},STATIC,"Step",BSS_CENTER|BXS_VISIBLE,&formJogTool[3], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDSTEPMM,{510,360,649,429},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[4], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDZRIGHT,{620,260,699,329},BUTTON,"Right",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[5], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDZLEFT,{460,260,539,329},BUTTON,"Left",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[6], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDDOWN,{540,170,619,239},BUTTON,"Down",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[7], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDIN,{460,110,539,179},BUTTON,"In",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[8], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDOUT,{620,110,699,179},BUTTON,"Out",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[9], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDUP,{540,50,619,119},BUTTON,"Up",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[10], &formJogTool[0]}
 ,{FORMJOGTOOL_GROUPBOX1,{40,20,379,439},STATIC,"",BSS_WHITEFRAME|BXS_VISIBLE,&formJogTool[11], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDRESETTURNTILT,{140,240,279,319},BUTTON,"Reset",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[12], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDSTEPDEG,{140,360,279,429},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[13], &formJogTool[0]}
 ,{FORMJOGTOOL_TEXTLABELSTEPDEG,{150,320,269,354},STATIC,"Step",BSS_CENTER|BXS_VISIBLE,&formJogTool[14], &formJogTool[0]}
 ,{FORMJOGTOOL_TEXTLABELTURN,{120,80,299,115},STATIC,"Turn",BSS_CENTER|BXS_VISIBLE,&formJogTool[15], &formJogTool[0]}
 ,{FORMJOGTOOL_TEXTLABELTILT,{120,170,299,205},STATIC,"Tilt",BSS_CENTER|BXS_VISIBLE,&formJogTool[16], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDTILTLEFT,{70,150,149,219},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[17], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDTURNLEFT,{70,60,149,129},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[18], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDTURNRIGHT,{270,60,349,129},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[19], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDTILTRIGHT,{270,150,349,219},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[20], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDCANCEL,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[21], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDJOGSPEED,{300,480,489,579},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[22], &formJogTool[0]}
 ,{FORMJOGTOOL_CMDRELEASE,{10,480,169,579},BUTTON,"Release",BBS_PUSHBUTTON|BXS_VISIBLE,&formJogTool[23], &formJogTool[0]}
 ,{FORMJOGTOOL_TEXTLABELSPEED,{300,440,489,475},STATIC,"Speed",BSS_CENTER|BXS_VISIBLE,&formJogTool[24], &formJogTool[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formJogTool[0]}
};

BX_BOOL formJogToolProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formJogToolUpdate(hBox);
				return formJogToolUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formJogToolInit(hBox);
				return formJogToolUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMJOGTOOL_CMDSTEPMM:
             return formJogTool_cmdStepMM_Click(hBox);
         case FORMJOGTOOL_CMDZRIGHT:
             return formJogTool_cmdZRight_Click(hBox);
         case FORMJOGTOOL_CMDZLEFT:
             return formJogTool_cmdZLeft_Click(hBox);
         case FORMJOGTOOL_CMDDOWN:
             return formJogTool_cmdDown_Click(hBox);
         case FORMJOGTOOL_CMDIN:
             return formJogTool_cmdIn_Click(hBox);
         case FORMJOGTOOL_CMDOUT:
             return formJogTool_cmdOut_Click(hBox);
         case FORMJOGTOOL_CMDUP:
             return formJogTool_cmdUp_Click(hBox);
         case FORMJOGTOOL_CMDRESETTURNTILT:
             return formJogTool_cmdResetTurnTilt_Click(hBox);
         case FORMJOGTOOL_CMDSTEPDEG:
             return formJogTool_cmdStepDeg_Click(hBox);
         case FORMJOGTOOL_CMDTILTLEFT:
             return formJogTool_cmdTiltLeft_Click(hBox);
         case FORMJOGTOOL_CMDTURNLEFT:
             return formJogTool_cmdTurnLeft_Click(hBox);
         case FORMJOGTOOL_CMDTURNRIGHT:
             return formJogTool_cmdTurnRight_Click(hBox);
         case FORMJOGTOOL_CMDTILTRIGHT:
             return formJogTool_cmdTiltRight_Click(hBox);
         case FORMJOGTOOL_CMDCANCEL:
             return formJogTool_cmdCancel_Click(hBox);
         case FORMJOGTOOL_CMDJOGSPEED:
             return formJogTool_cmdJogSpeed_Click(hBox);
         case FORMJOGTOOL_CMDRELEASE:
             return formJogTool_cmdRelease_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
