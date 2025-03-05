//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formVision.c
#include "Bx.h"
#include "formVision.h"

BOXSTRUCT formVision[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formVision[1], NULL}
 ,{FORMVISION_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formVision[2], &formVision[0]}
 ,{FORMVISION_CMDRETURN,{650,480,779,579},BUTTON,"Return",BBS_PUSHBUTTON|BXS_VISIBLE,&formVision[3], &formVision[0]}
 ,{FORMVISION_CMDSMALL,{220,290,349,349},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formVision[4], &formVision[0]}
 ,{FORMVISION_TEXTLABEL_3_2,{500,170,619,204},STATIC,"Length:",BXS_VISIBLE,&formVision[5], &formVision[0]}
 ,{FORMVISION_TEXTLABEL2,{30,300,209,334},STATIC,"Smallest item:",BXS_VISIBLE,&formVision[6], &formVision[0]}
 ,{FORMVISION_CMDMINHEIGHT,{220,220,349,279},BUTTON,"250",BBS_PUSHBUTTON|BXS_VISIBLE,&formVision[7], &formVision[0]}
 ,{FORMVISION_TEXTLABEL5,{500,310,619,344},STATIC,"Height:",BXS_VISIBLE,&formVision[8], &formVision[0]}
 ,{FORMVISION_TEXTLABEL5_2,{500,380,619,414},STATIC,"Angle:",BXS_VISIBLE,&formVision[9], &formVision[0]}
 ,{FORMVISION_CMDIPADDRESS,{220,360,449,419},BUTTON,"192.168.0.51",BBS_PUSHBUTTON|BXS_VISIBLE,&formVision[10], &formVision[0]}
 ,{FORMVISION_TEXTLABEL_2,{30,230,209,264},STATIC,"Minimum height:",BXS_VISIBLE,&formVision[11], &formVision[0]}
 ,{FORMVISION_TEXTLABEL_3,{30,90,209,124},STATIC,"Connected:",BXS_VISIBLE,&formVision[12], &formVision[0]}
 ,{FORMVISION_TEXTLABEL,{30,160,209,194},STATIC,"Fps:",BXS_VISIBLE,&formVision[13], &formVision[0]}
 ,{FORMVISION_TEXTLABEL4,{500,240,619,274},STATIC,"Width:",BXS_VISIBLE,&formVision[14], &formVision[0]}
 ,{FORMVISION_TEXTLENGTH,{630,150,759,209},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formVision[15], &formVision[0]}
 ,{FORMVISION_TEXTWIDTH,{630,220,759,279},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formVision[16], &formVision[0]}
 ,{FORMVISION_TEXTHEIGHT,{630,290,759,349},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formVision[17], &formVision[0]}
 ,{FORMVISION_TEXTANGLE,{630,360,759,419},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formVision[18], &formVision[0]}
 ,{FORMVISION_TEXTLABEL3,{30,370,209,404},STATIC,"Ip address:",BXS_VISIBLE,&formVision[19], &formVision[0]}
 ,{FORMVISION_TEXTLABEL3_2,{30,520,209,554},STATIC,"Guided by vision",BXS_VISIBLE,&formVision[20], &formVision[0]}
 ,{FORMVISION_TEXTFPS,{220,150,349,209},STATIC,"0",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formVision[21], &formVision[0]}
 ,{FORMVISION_CHECKCONNECT,{220,90,259,129},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formVision[22], &formVision[0]}
 ,{FORMVISION_CHECKGUIDEDBYVISION,{230,480,359,579},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formVision[23], &formVision[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formVision[0]}
};

BX_BOOL formVisionProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formVisionUpdate(hBox);
				return formVisionUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formVisionInit(hBox);
				return formVisionUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMVISION_CMDRETURN:
             return formVision_cmdReturn_Click(hBox);
         case FORMVISION_CMDSMALL:
             return formVision_cmdSmall_Click(hBox);
         case FORMVISION_CMDMINHEIGHT:
             return formVision_cmdMinHeight_Click(hBox);
         case FORMVISION_CMDIPADDRESS:
             return formVision_cmdIpAddress_Click(hBox);
         case FORMVISION_CHECKCONNECT:
             return formVision_checkConnect_Click(hBox);
         case FORMVISION_CHECKGUIDEDBYVISION:
             return formVision_checkGuidedByVision_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
