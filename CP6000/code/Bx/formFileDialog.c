//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formFileDialog.c
#include "Bx.h"
#include "formFileDialog.h"

BOXSTRUCT formFileDialog[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formFileDialog[1], NULL}
 ,{FORMFILEDIALOG_CMDMENU,{650,490,779,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formFileDialog[2], &formFileDialog[0]}
 ,{FORMFILEDIALOG_LISTDIR,{410,70,779,469},LIST,"",BXS_VISIBLE,&formFileDialog[3], &formFileDialog[0]}
 ,{FORMFILEDIALOG_LISTFILE,{20,70,389,469},LIST,"",BXS_VISIBLE,&formFileDialog[4], &formFileDialog[0]}
 ,{FORMFILEDIALOG_CMDFILENAME,{20,10,779,59},BUTTON,"Filename",BBS_PUSHBUTTON|BXS_VISIBLE,&formFileDialog[5], &formFileDialog[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formFileDialog[0]}
};

BX_BOOL formFileDialogProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formFileDialogUpdate(hBox);
				return formFileDialogUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formFileDialogInit(hBox);
				return formFileDialogUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMFILEDIALOG_CMDMENU:
             return formFileDialog_cmdMenu_Click(hBox);
         case FORMFILEDIALOG_LISTDIR:
             return formFileDialog_listDir_Click(hBox);
         case FORMFILEDIALOG_LISTFILE:
             return formFileDialog_listFile_Click(hBox);
         case FORMFILEDIALOG_CMDFILENAME:
             return formFileDialog_cmdFilename_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
