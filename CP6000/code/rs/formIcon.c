//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formIcon.c
#include "Bx.h"
#include "formIcon.h"

BOXSTRUCT formIcon[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formIcon[1], NULL}
 ,{FORMICON_LABYES,{50,20,67,38},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[2], &formIcon[0]}
 ,{FORMICON_LABNO,{30,20,46,36},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[3], &formIcon[0]}
 ,{FORMICON_LABSHUTDOWN,{710,30,731,51},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[4], &formIcon[0]}
 ,{FORMICON_LABWARNING,{650,20,697,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[5], &formIcon[0]}
 ,{FORMICON_LABPROGRAM,{430,20,489,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[6], &formIcon[0]}
 ,{FORMICON_LABVISION,{250,20,297,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[7], &formIcon[0]}
 ,{FORMICON_LABTOOLS_2,{190,20,237,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[8], &formIcon[0]}
 ,{FORMICON_LABTOOLS,{130,20,177,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[9], &formIcon[0]}
 ,{FORMICON_LABUNLOCK,{70,20,117,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[10], &formIcon[0]}
 ,{FORMICON_LABSCOPE,{30,80,89,127},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[11], &formIcon[0]}
 ,{FORMICON_LABOPTION,{370,20,417,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[12], &formIcon[0]}
 ,{FORMICON_LABBOX,{310,20,357,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[13], &formIcon[0]}
 ,{FORMICON_LABBAGS,{500,20,549,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[14], &formIcon[0]}
 ,{FORMICON_LABPALMBOX,{570,20,617,67},STATIC,"",BSS_BITMAP|BXS_VISIBLE,&formIcon[15], &formIcon[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formIcon[0]}
};

BX_BOOL formIconProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formIconUpdate(hBox);
				return formIconUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formIconInit(hBox);
				return formIconUserInit(hBox,lParam);
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
