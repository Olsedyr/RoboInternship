//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMasterProg.c
#include "Bx.h"
#include "formMasterProg.h"

BOXSTRUCT formMasterProg[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formMasterProg[1], NULL}
 ,{FORMMASTERPROG_CMDOK,{660,490,789,579},BUTTON,"OK",BBS_PUSHBUTTON|BXS_VISIBLE,&formMasterProg[2], &formMasterProg[0]}
 ,{FORMMASTERPROG_TEXTLABEL2_2,{10,10,229,44},STATIC,"Robot",BXS_VISIBLE,&formMasterProg[3], &formMasterProg[0]}
 ,{FORMMASTERPROG_LISTBOX,{10,60,359,459},LIST,"",BXS_VISIBLE,&formMasterProg[4], &formMasterProg[0]}
 ,{FORMMASTERPROG_CMDCANCEL,{520,490,649,579},BUTTON,"Afbryd",BBS_PUSHBUTTON|BXS_VISIBLE,&formMasterProg[5], &formMasterProg[0]}
 ,{FORMMASTERPROG_CMDEDIT,{380,490,509,579},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formMasterProg[6], &formMasterProg[0]}
 ,{FORMMASTERPROG_TEXTLABEL2_3,{380,10,599,44},STATIC,"KassePakkere",BXS_VISIBLE,&formMasterProg[7], &formMasterProg[0]}
 ,{FORMMASTERPROG_LISTBOX_2,{380,60,729,459},LIST,"",BXS_VISIBLE,&formMasterProg[8], &formMasterProg[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formMasterProg[0]}
};

BX_BOOL formMasterProgProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formMasterProgUpdate(hBox);
				return formMasterProgUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formMasterProgInit(hBox);
				return formMasterProgUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMASTERPROG_CMDOK:
             return formMasterProg_cmdOk_Click(hBox);
         case FORMMASTERPROG_LISTBOX:
             return formMasterProg_listBox_Click(hBox);
         case FORMMASTERPROG_CMDCANCEL:
             return formMasterProg_cmdCancel_Click(hBox);
         case FORMMASTERPROG_CMDEDIT:
             return formMasterProg_cmdEdit_Click(hBox);
         case FORMMASTERPROG_LISTBOX_2:
             return formMasterProg_listBox_2_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
