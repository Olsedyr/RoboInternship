//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgramCtrl.c
#include "Bx.h"
#include "formProgramCtrl.h"

BOXSTRUCT formProgramCtrl[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formProgramCtrl[1], NULL}
 ,{FORMPROGRAMCTRL_CMDEDIT,{670,360,789,449},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgramCtrl[2], &formProgramCtrl[0]}
 ,{FORMPROGRAMCTRL_CMDCLOSE,{670,490,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgramCtrl[3], &formProgramCtrl[0]}
 ,{FORMPROGRAMCTRL_LISTBOX,{20,110,649,579},LIST,"",BXS_VISIBLE,&formProgramCtrl[4], &formProgramCtrl[0]}
 ,{FORMPROGRAMCTRL_GROUPBOX2,{30,20,449,89},STATIC,"Program",BSS_WHITEFRAME|BXS_VISIBLE,&formProgramCtrl[5], &formProgramCtrl[0]}
 ,{FORMPROGRAMCTRL_LABSTATE,{100,40,379,75},STATIC,"Bags2.5Kg",BSS_CENTER|BXS_VISIBLE,&formProgramCtrl[6], &formProgramCtrl[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formProgramCtrl[0]}
};

BX_BOOL formProgramCtrlProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formProgramCtrlUpdate(hBox);
				return formProgramCtrlUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formProgramCtrlInit(hBox);
				return formProgramCtrlUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMPROGRAMCTRL_CMDEDIT:
             return formProgramCtrl_cmdEdit_Click(hBox);
         case FORMPROGRAMCTRL_CMDCLOSE:
             return formProgramCtrl_cmdClose_Click(hBox);
         case FORMPROGRAMCTRL_LISTBOX:
             return formProgramCtrl_listBox_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
