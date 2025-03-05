//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItemEdit.c
#include "Bx.h"
#include "formItemEdit.h"

BOXSTRUCT formItemEdit[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formItemEdit[1], NULL}
 ,{FORMITEMEDIT_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[2], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[3], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2,{20,10,249,45},STATIC,"CP6000",BXS_VISIBLE,&formItemEdit[4], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3,{80,110,149,144},STATIC,"dx",BSS_CENTER|BXS_VISIBLE,&formItemEdit[5], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_2,{80,180,149,214},STATIC,"dy",BSS_CENTER|BXS_VISIBLE,&formItemEdit[6], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3,{80,250,149,284},STATIC,"dz",BSS_CENTER|BXS_VISIBLE,&formItemEdit[7], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_2,{80,320,149,355},STATIC,"sy",BSS_CENTER|BXS_VISIBLE,&formItemEdit[8], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_2_2,{80,390,149,425},STATIC,"gy",BSS_CENTER|BXS_VISIBLE,&formItemEdit[9], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_4,{470,110,539,144},STATIC,"my",BSS_CENTER|BXS_VISIBLE,&formItemEdit[10], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_2_2,{470,180,539,214},STATIC,"gx",BSS_CENTER|BXS_VISIBLE,&formItemEdit[11], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABEL2_2_2_2_3_3_3,{470,250,539,284},STATIC,"wieght",BSS_CENTER|BXS_VISIBLE,&formItemEdit[12], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDMY,{540,100,729,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[13], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDGX,{540,170,729,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[14], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDWEIGHT,{540,240,729,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[15], &formItemEdit[0]}
 ,{FORMITEMEDIT_GROUPBOX1,{390,10,729,79},STATIC,"Frame",BSS_WHITEFRAME|BXS_VISIBLE,&formItemEdit[16], &formItemEdit[0]}
 ,{FORMITEMEDIT_TEXTLABELNAME,{400,30,709,65},STATIC,"ItemName",BSS_CENTER|BXS_VISIBLE,&formItemEdit[17], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDGY,{150,380,339,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[18], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDSY,{150,310,339,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[19], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDDZ,{150,240,339,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[20], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDDY,{150,170,339,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[21], &formItemEdit[0]}
 ,{FORMITEMEDIT_CMDDX,{150,100,339,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formItemEdit[22], &formItemEdit[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formItemEdit[0]}
};

BX_BOOL formItemEditProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formItemEditUpdate(hBox);
				return formItemEditUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formItemEditInit(hBox);
				return formItemEditUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMITEMEDIT_CMDCANCEL:
             return formItemEdit_cmdCancel_Click(hBox);
         case FORMITEMEDIT_CMDRETURN:
             return formItemEdit_cmdReturn_Click(hBox);
         case FORMITEMEDIT_CMDMY:
             return formItemEdit_cmdmy_Click(hBox);
         case FORMITEMEDIT_CMDGX:
             return formItemEdit_cmdgx_Click(hBox);
         case FORMITEMEDIT_CMDWEIGHT:
             return formItemEdit_cmdweight_Click(hBox);
         case FORMITEMEDIT_CMDGY:
             return formItemEdit_cmdgy_Click(hBox);
         case FORMITEMEDIT_CMDSY:
             return formItemEdit_cmdsy_Click(hBox);
         case FORMITEMEDIT_CMDDZ:
             return formItemEdit_cmddz_Click(hBox);
         case FORMITEMEDIT_CMDDY:
             return formItemEdit_cmddy_Click(hBox);
         case FORMITEMEDIT_CMDDX:
             return formItemEdit_cmddx_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
