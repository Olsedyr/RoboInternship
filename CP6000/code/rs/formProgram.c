//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgram.c
#include "Bx.h"
#include "formProgram.h"

BOXSTRUCT formProgram[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formProgram[1], NULL}
 ,{FORMPROGRAM_TEXTLABEL2_2,{10,10,229,44},STATIC,"Programmer",BXS_VISIBLE,&formProgram[2], &formProgram[0]}
 ,{FORMPROGRAM_LISTBOX,{10,60,649,459},LIST,"",BXS_VISIBLE,&formProgram[3], &formProgram[0]}
 ,{FORMPROGRAM_CMDCANCEL,{520,490,649,579},BUTTON,"Afbryd",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgram[4], &formProgram[0]}
 ,{FORMPROGRAM_CMDOK,{660,490,789,579},BUTTON,"Vælg",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgram[5], &formProgram[0]}
 ,{FORMPROGRAM_CMDEDIT,{660,360,789,449},BUTTON,"Edit",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgram[6], &formProgram[0]}
 ,{FORMPROGRAM_CMDDELETE,{660,160,789,249},BUTTON,"Slet Program",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgram[7], &formProgram[0]}
 ,{FORMPROGRAM_CMDNEW,{660,60,789,149},BUTTON,"Lav Kopi",BBS_PUSHBUTTON|BXS_VISIBLE,&formProgram[8], &formProgram[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formProgram[0]}
};

BX_BOOL formProgramProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formProgramUpdate(hBox);
				return formProgramUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formProgramInit(hBox);
				return formProgramUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMPROGRAM_LISTBOX:
             return formProgram_listBox_Click(hBox);
         case FORMPROGRAM_CMDCANCEL:
             return formProgram_cmdCancel_Click(hBox);
         case FORMPROGRAM_CMDOK:
             return formProgram_cmdOk_Click(hBox);
         case FORMPROGRAM_CMDEDIT:
             return formProgram_cmdEdit_Click(hBox);
         case FORMPROGRAM_CMDDELETE:
             return formProgram_cmdDelete_Click(hBox);
         case FORMPROGRAM_CMDNEW:
             return formProgram_cmdNew_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
