//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formOffsetPath.c
#include "Bx.h"
#include "formOffsetPath.h"

BOXSTRUCT formOffsetPath[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formOffsetPath[1], NULL}
 ,{FORMOFFSETPATH_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formOffsetPath[2], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[3], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[4], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDJOGIK,{70,470,199,569},BUTTON,"Set",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[5], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDZ,{300,220,489,279},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[6], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDX,{300,80,489,139},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[7], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDV,{300,290,489,349},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[8], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_TEXTLABEL_2_2,{220,370,289,404},STATIC,"W",BSS_CENTER|BXS_VISIBLE,&formOffsetPath[9], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_TEXTLABEL2_2_2_2_3_3,{220,230,289,264},STATIC,"Z",BSS_CENTER|BXS_VISIBLE,&formOffsetPath[10], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_TEXTLABEL_2,{220,300,289,334},STATIC,"V",BSS_CENTER|BXS_VISIBLE,&formOffsetPath[11], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_TEXTLABEL2_2_2_2_3,{220,100,289,134},STATIC,"X",BSS_CENTER|BXS_VISIBLE,&formOffsetPath[12], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDY,{300,150,489,209},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[13], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_TEXTLABEL2_2_2_2_3_2,{220,170,289,204},STATIC,"Y",BSS_CENTER|BXS_VISIBLE,&formOffsetPath[14], &formOffsetPath[0]}
 ,{FORMOFFSETPATH_CMDW,{300,360,489,419},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formOffsetPath[15], &formOffsetPath[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formOffsetPath[0]}
};

BX_BOOL formOffsetPathProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formOffsetPathUpdate(hBox);
				return formOffsetPathUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formOffsetPathInit(hBox);
				return formOffsetPathUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMOFFSETPATH_CMDCANCEL:
             return formOffsetPath_cmdCancel_Click(hBox);
         case FORMOFFSETPATH_CMDRETURN:
             return formOffsetPath_cmdReturn_Click(hBox);
         case FORMOFFSETPATH_CMDJOGIK:
             return formOffsetPath_cmdJogIk_Click(hBox);
         case FORMOFFSETPATH_CMDZ:
             return formOffsetPath_cmdZ_Click(hBox);
         case FORMOFFSETPATH_CMDX:
             return formOffsetPath_cmdX_Click(hBox);
         case FORMOFFSETPATH_CMDV:
             return formOffsetPath_cmdV_Click(hBox);
         case FORMOFFSETPATH_CMDY:
             return formOffsetPath_cmdY_Click(hBox);
         case FORMOFFSETPATH_CMDW:
             return formOffsetPath_cmdW_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
