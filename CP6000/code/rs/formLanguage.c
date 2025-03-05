//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formLanguage.c
#include "Bx.h"
#include "formLanguage.h"

BOXSTRUCT formLanguage[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formLanguage[1], NULL}
 ,{FORMLANGUAGE_TEXTLABEL2_2,{20,10,269,44},STATIC,"Language settings",BXS_VISIBLE,&formLanguage[2], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDCANCEL,{650,480,779,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[3], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDOK,{500,480,629,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[4], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_6,{490,270,699,409},BUTTON,"Lang6",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[5], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_5,{260,270,469,409},BUTTON,"Lang5",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[6], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_4,{20,270,229,409},BUTTON,"Lang4",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[7], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_1,{20,110,229,249},BUTTON,"Lang1",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[8], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_2,{260,110,469,249},BUTTON,"Lang2",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[9], &formLanguage[0]}
 ,{FORMLANGUAGE_CMDLANG1_3,{490,110,699,249},BUTTON,"Lang3",BBS_PUSHBUTTON|BXS_VISIBLE,&formLanguage[10], &formLanguage[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formLanguage[0]}
};

BX_BOOL formLanguageProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formLanguageUpdate(hBox);
				return formLanguageUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formLanguageInit(hBox);
				return formLanguageUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMLANGUAGE_CMDCANCEL:
             return formLanguage_cmdCancel_Click(hBox);
         case FORMLANGUAGE_CMDOK:
             return formLanguage_cmdOk_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_6:
             return formLanguage_cmdLang1_6_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_5:
             return formLanguage_cmdLang1_5_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_4:
             return formLanguage_cmdLang1_4_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_1:
             return formLanguage_cmdLang1_1_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_2:
             return formLanguage_cmdLang1_2_Click(hBox);
         case FORMLANGUAGE_CMDLANG1_3:
             return formLanguage_cmdLang1_3_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
