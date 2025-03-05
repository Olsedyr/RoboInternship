//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formUploadProg.c
#include "Bx.h"
#include "formUploadProg.h"

BOXSTRUCT formUploadProg[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formUploadProg[1], NULL}
 ,{FORMUPLOADPROG_LABPROGRESS,{60,280,720,360},STATIC,"Progress bar",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formUploadProg[2], &formUploadProg[0]}
 ,{FORMUPLOADPROG_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formUploadProg[3], &formUploadProg[0]}
 ,{FORMUPLOADPROG_TEXTMESSAGE,{70,230,719,264},STATIC,"Setup motion....",BSS_CENTER|BXS_VISIBLE,&formUploadProg[4], &formUploadProg[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formUploadProg[0]}
};

BX_BOOL formUploadProgProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formUploadProgUpdate(hBox);
				return formUploadProgUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formUploadProgInit(hBox);
				return formUploadProgUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
