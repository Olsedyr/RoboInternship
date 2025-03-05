//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSysParam.c
#include "Bx.h"
#include "formSysParam.h"

BOXSTRUCT formSysParam[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSysParam[1], NULL}
 ,{FORMSYSPARAM_TEXTLABEL2_4,{220,250,469,284},STATIC,"Old ethernet version",BSS_CENTER|BXS_VISIBLE,&formSysParam[2], &formSysParam[0]}
 ,{FORMSYSPARAM_CHECKETHERNETVERSION,{500,240,549,289},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formSysParam[3], &formSysParam[0]}
 ,{FORMSYSPARAM_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formSysParam[4], &formSysParam[0]}
 ,{FORMSYSPARAM_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formSysParam[5], &formSysParam[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSysParam[0]}
};

BX_BOOL formSysParamProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSysParamUpdate(hBox);
				return formSysParamUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSysParamInit(hBox);
				return formSysParamUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSYSPARAM_CHECKETHERNETVERSION:
             return formSysParam_checkEthernetVersion_Click(hBox);
         case FORMSYSPARAM_CMDRETURN:
             return formSysParam_cmdReturn_Click(hBox);
         case FORMSYSPARAM_CMDCANCEL:
             return formSysParam_cmdCancel_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
