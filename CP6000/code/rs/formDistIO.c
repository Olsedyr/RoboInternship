//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDistIO.c
#include "Bx.h"
#include "formDistIO.h"

BOXSTRUCT formDistIO[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formDistIO[1], NULL}
 ,{FORMDISTIO_CMDCLOSE,{650,480,779,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formDistIO[2], &formDistIO[0]}
 ,{FORMDISTIO_TEXTLABEL2_2,{10,10,259,44},STATIC,"Modules",BXS_VISIBLE,&formDistIO[3], &formDistIO[0]}
 ,{FORMDISTIO_LISTBOX,{20,60,629,579},LIST,"",BXS_VISIBLE,&formDistIO[4], &formDistIO[0]}
 ,{FORMDISTIO_CHKADVANTYS,{660,30,769,99},BUTTON,"Advantys",BBS_CHECKBOX|BXS_VISIBLE,&formDistIO[5], &formDistIO[0]}
 ,{FORMDISTIO_CHKLOADCELL,{660,120,769,189},BUTTON,"LoadCell",BBS_CHECKBOX|BXS_VISIBLE,&formDistIO[6], &formDistIO[0]}
 ,{FORMDISTIO_CHKCOMSK,{660,210,769,279},BUTTON,"ComSK",BBS_CHECKBOX|BXS_VISIBLE,&formDistIO[7], &formDistIO[0]}
 ,{FORMDISTIO_CHKMAC,{660,300,769,369},BUTTON,"Mac",BBS_CHECKBOX|BXS_VISIBLE,&formDistIO[8], &formDistIO[0]}
 ,{FORMDISTIO_CHKICPCON,{660,390,769,459},BUTTON,"ICPcon",BBS_CHECKBOX|BXS_VISIBLE,&formDistIO[9], &formDistIO[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formDistIO[0]}
};

BX_BOOL formDistIOProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formDistIOUpdate(hBox);
				return formDistIOUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formDistIOInit(hBox);
				return formDistIOUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMDISTIO_CMDCLOSE:
             return formDistIO_cmdClose_Click(hBox);
         case FORMDISTIO_LISTBOX:
             return formDistIO_listBox_Click(hBox);
         case FORMDISTIO_CHKADVANTYS:
             return formDistIO_chkAdvantys_Click(hBox);
         case FORMDISTIO_CHKLOADCELL:
             return formDistIO_chkLoadCell_Click(hBox);
         case FORMDISTIO_CHKCOMSK:
             return formDistIO_chkComSK_Click(hBox);
         case FORMDISTIO_CHKMAC:
             return formDistIO_chkMac_Click(hBox);
         case FORMDISTIO_CHKICPCON:
             return formDistIO_chkICPcon_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
