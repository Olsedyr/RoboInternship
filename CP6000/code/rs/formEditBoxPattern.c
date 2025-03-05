//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditBoxPattern.c
#include "Bx.h"
#include "formEditBoxPattern.h"

BOXSTRUCT formEditBoxPattern[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditBoxPattern[1], NULL}
 ,{FORMEDITBOXPATTERN_LABVIEW,{10,10,329,489},STATIC,"",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[2], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_GROUPBOXITEM,{340,100,789,179},STATIC,"Item",BSS_WHITEFRAME|BXS_VISIBLE,&formEditBoxPattern[3], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_LABITEM,{410,130,719,167},STATIC,"Name",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[4], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDITEMPREV,{350,130,399,169},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[5], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDITEMNEXT,{730,130,779,169},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[6], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_GROUPBOXINDEX,{340,500,789,579},STATIC,"Index",BSS_WHITEFRAME|BXS_VISIBLE,&formEditBoxPattern[7], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDINDEXNEXT,{700,530,779,569},BUTTON,"+",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[8], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDINDEXPREV,{350,530,429,569},BUTTON,"-",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[9], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDINDEX,{430,530,699,569},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[10], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_GROUPBOXPATTERN,{340,10,789,89},STATIC,"Pattern",BSS_WHITEFRAME|BXS_VISIBLE,&formEditBoxPattern[11], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDPATTERNNEXT,{730,40,779,79},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[12], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_LABPATTERN,{410,40,719,77},STATIC,"Name",BXS_BORDER|BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[13], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDPATTERNPREV,{350,40,399,79},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[14], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_GROUPBOXPOSITION,{340,190,789,489},STATIC,"Position",BSS_WHITEFRAME|BXS_VISIBLE,&formEditBoxPattern[15], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL4,{350,420,419,454},STATIC,"W",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[16], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL3,{350,380,419,414},STATIC,"V",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[17], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL2,{350,340,419,374},STATIC,"Z",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[18], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL1,{350,300,419,334},STATIC,"Y",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[19], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL,{350,260,419,294},STATIC,"X",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[20], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_TEXTLABEL_2,{350,220,419,255},STATIC,"Layer",BSS_CENTER|BXS_VISIBLE,&formEditBoxPattern[21], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDX,{430,260,729,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[22], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDY,{430,300,729,339},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[23], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDZ,{430,340,729,379},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[24], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDV,{430,380,729,419},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[25], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDW,{430,420,729,459},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[26], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDLAYER,{430,220,729,259},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[27], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDSAVE,{170,500,329,579},BUTTON,"Save",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[28], &formEditBoxPattern[0]}
 ,{FORMEDITBOXPATTERN_CMDCANCEL,{10,500,159,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditBoxPattern[29], &formEditBoxPattern[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditBoxPattern[0]}
};

BX_BOOL formEditBoxPatternProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditBoxPatternUpdate(hBox);
				return formEditBoxPatternUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditBoxPatternInit(hBox);
				return formEditBoxPatternUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITBOXPATTERN_CMDITEMPREV:
             return formEditBoxPattern_cmdItemPrev_Click(hBox);
         case FORMEDITBOXPATTERN_CMDITEMNEXT:
             return formEditBoxPattern_cmdItemNext_Click(hBox);
         case FORMEDITBOXPATTERN_CMDINDEXNEXT:
             return formEditBoxPattern_cmdIndexNext_Click(hBox);
         case FORMEDITBOXPATTERN_CMDINDEXPREV:
             return formEditBoxPattern_cmdIndexPrev_Click(hBox);
         case FORMEDITBOXPATTERN_CMDINDEX:
             return formEditBoxPattern_cmdIndex_Click(hBox);
         case FORMEDITBOXPATTERN_CMDPATTERNNEXT:
             return formEditBoxPattern_cmdPatternNext_Click(hBox);
         case FORMEDITBOXPATTERN_CMDPATTERNPREV:
             return formEditBoxPattern_cmdPatternPrev_Click(hBox);
         case FORMEDITBOXPATTERN_CMDX:
             return formEditBoxPattern_cmdX_Click(hBox);
         case FORMEDITBOXPATTERN_CMDY:
             return formEditBoxPattern_cmdY_Click(hBox);
         case FORMEDITBOXPATTERN_CMDZ:
             return formEditBoxPattern_cmdZ_Click(hBox);
         case FORMEDITBOXPATTERN_CMDV:
             return formEditBoxPattern_cmdV_Click(hBox);
         case FORMEDITBOXPATTERN_CMDW:
             return formEditBoxPattern_cmdW_Click(hBox);
         case FORMEDITBOXPATTERN_CMDLAYER:
             return formEditBoxPattern_cmdLayer_Click(hBox);
         case FORMEDITBOXPATTERN_CMDSAVE:
             return formEditBoxPattern_cmdSave_Click(hBox);
         case FORMEDITBOXPATTERN_CMDCANCEL:
             return formEditBoxPattern_cmdCancel_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
