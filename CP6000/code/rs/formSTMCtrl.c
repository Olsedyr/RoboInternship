//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSTMCtrl.c
#include "Bx.h"
#include "formSTMCtrl.h"

BOXSTRUCT formSTMCtrl[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSTMCtrl[1], NULL}
 ,{FORMSTMCTRL_CMDCLOSE,{670,490,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMCtrl[2], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_LISTBOX,{20,110,649,579},LIST,"",BXS_VISIBLE,&formSTMCtrl[3], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_GROUPBOX2,{350,20,649,89},STATIC,"State",BSS_WHITEFRAME|BXS_VISIBLE,&formSTMCtrl[4], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_LABSTATE,{360,40,639,75},STATIC,"IDLE",BSS_CENTER|BXS_VISIBLE,&formSTMCtrl[5], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_GROUPBOX1,{30,20,329,89},STATIC,"Name",BSS_WHITEFRAME|BXS_VISIBLE,&formSTMCtrl[6], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_LABNAME,{40,40,319,75},STATIC,"Sektor33",BSS_CENTER|BXS_VISIBLE,&formSTMCtrl[7], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_CMDRESTART,{670,110,789,199},BUTTON,"Restart",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMCtrl[8], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_CMDSCOPE,{670,220,789,339},BUTTON,"Scope",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMCtrl[9], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_CMDEDIT,{670,360,789,449},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMCtrl[10], &formSTMCtrl[0]}
 ,{FORMSTMCTRL_CMDHALT,{670,10,789,99},BUTTON,"Halt",BBS_PUSHBUTTON|BXS_VISIBLE,&formSTMCtrl[11], &formSTMCtrl[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSTMCtrl[0]}
};

BX_BOOL formSTMCtrlProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSTMCtrlUpdate(hBox);
				return formSTMCtrlUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSTMCtrlInit(hBox);
				return formSTMCtrlUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSTMCTRL_CMDCLOSE:
             return formSTMCtrl_cmdClose_Click(hBox);
         case FORMSTMCTRL_LISTBOX:
             return formSTMCtrl_listBox_Click(hBox);
         case FORMSTMCTRL_CMDRESTART:
             return formSTMCtrl_cmdRestart_Click(hBox);
         case FORMSTMCTRL_CMDSCOPE:
             return formSTMCtrl_cmdScope_Click(hBox);
         case FORMSTMCTRL_CMDEDIT:
             return formSTMCtrl_cmdEdit_Click(hBox);
         case FORMSTMCTRL_CMDHALT:
             return formSTMCtrl_cmdHalt_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
