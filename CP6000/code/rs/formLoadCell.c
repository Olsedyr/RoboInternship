//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formLoadCell.c
#include "Bx.h"
#include "formLoadCell.h"

BOXSTRUCT formLoadCell[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formLoadCell[1], NULL}
 ,{FORMLOADCELL_TEXTLABEL2_2_2,{60,60,139,94},STATIC,"Name :",BXS_VISIBLE,&formLoadCell[2], &formLoadCell[0]}
 ,{FORMLOADCELL_CMDCLOSE,{660,480,789,579},BUTTON,"Close",BBS_PUSHBUTTON|BXS_VISIBLE,&formLoadCell[3], &formLoadCell[0]}
 ,{FORMLOADCELL_LABTYPE,{280,10,529,44},STATIC,"LoadCell Module",BSS_CENTER|BXS_VISIBLE,&formLoadCell[4], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_6,{20,160,49,194},STATIC,"2",BXS_VISIBLE,&formLoadCell[5], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_3,{20,120,49,154},STATIC,"1",BXS_VISIBLE,&formLoadCell[6], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_2_2,{20,200,49,234},STATIC,"3",BXS_VISIBLE,&formLoadCell[7], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_3_2,{20,240,49,274},STATIC,"4",BXS_VISIBLE,&formLoadCell[8], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_4_2,{20,280,49,314},STATIC,"5",BXS_VISIBLE,&formLoadCell[9], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_4_2_2,{20,320,49,354},STATIC,"6",BXS_VISIBLE,&formLoadCell[10], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_4_2_3,{20,360,49,394},STATIC,"7",BXS_VISIBLE,&formLoadCell[11], &formLoadCell[0]}
 ,{FORMLOADCELL_TEXTLABEL2_2_2_2_2_4_2_4,{20,400,49,434},STATIC,"8",BXS_VISIBLE,&formLoadCell[12], &formLoadCell[0]}
 ,{FORMLOADCELL_LABMODNAME,{190,60,619,94},STATIC,"Module name",BXS_BORDER|BXS_VISIBLE,&formLoadCell[13], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD1,{60,120,169,154},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[14], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD2,{60,160,169,194},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[15], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD3,{60,200,169,234},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[16], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD4,{60,240,169,274},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[17], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD5,{60,280,169,314},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[18], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD8,{60,400,169,434},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[19], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD7,{60,360,169,394},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[20], &formLoadCell[0]}
 ,{FORMLOADCELL_IWORD6,{60,320,169,354},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[21], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD1,{190,120,619,154},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[22], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD2,{190,160,619,194},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[23], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD3,{190,200,619,234},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[24], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD4,{190,240,619,274},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[25], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD5,{190,280,619,314},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[26], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD6,{190,320,619,354},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[27], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD7,{190,360,619,394},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[28], &formLoadCell[0]}
 ,{FORMLOADCELL_LABIWORD8,{190,400,619,434},STATIC,"Load",BXS_BORDER|BXS_VISIBLE,&formLoadCell[29], &formLoadCell[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formLoadCell[0]}
};

BX_BOOL formLoadCellProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formLoadCellUpdate(hBox);
				return formLoadCellUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formLoadCellInit(hBox);
				return formLoadCellUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMLOADCELL_CMDCLOSE:
             return formLoadCell_cmdClose_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
