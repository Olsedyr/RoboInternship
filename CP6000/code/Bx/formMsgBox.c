//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMsgBox.c
#include "Bx.h"
#include "formMsgBox.h"

BOXSTRUCT formMsgBox[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formMsgBox[1], NULL}
 ,{FORMMSGBOX_CMDCANCEL,{650,490,779,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formMsgBox[2], &formMsgBox[0]}
 ,{FORMMSGBOX_CMDOK,{510,490,639,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formMsgBox[3], &formMsgBox[0]}
 ,{FORMMSGBOX_TEXTCAPTION,{21,40,770,70},STATIC,"Caption",BSS_CENTER|BXS_VISIBLE,&formMsgBox[4], &formMsgBox[0]}
 ,{FORMMSGBOX_TEXTLABEL2,{380,140,411,179},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formMsgBox[5], &formMsgBox[0]}
 ,{FORMMSGBOX_TEXTMSGTEXT,{20,240,769,270},STATIC,"MessageText",BSS_CENTER|BXS_VISIBLE,&formMsgBox[6], &formMsgBox[0]}
 ,{FORMMSGBOX_TEXTMSGTEXT_2,{20,290,769,320},STATIC,"MessageText",BSS_CENTER|BXS_VISIBLE,&formMsgBox[7], &formMsgBox[0]}
 ,{FORMMSGBOX_TEXTMSGTEXT_3,{20,340,769,370},STATIC,"MessageText",BSS_CENTER|BXS_VISIBLE,&formMsgBox[8], &formMsgBox[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formMsgBox[0]}
};

BX_BOOL formMsgBoxProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formMsgBoxUpdate(hBox);
				return formMsgBoxUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formMsgBoxInit(hBox);
				return formMsgBoxUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMMSGBOX_CMDCANCEL:
             return formMsgBox_cmdCancel_Click(hBox);
         case FORMMSGBOX_CMDOK:
             return formMsgBox_cmdOk_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
