//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditCPPattern.c
#include "Bx.h"
#include "formEditCPPattern.h"

BOXSTRUCT formEditCPPattern[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditCPPattern[1], NULL}
 ,{FORMEDITCPPATTERN_CMDCANCEL,{10,510,139,589},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[2], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELMAXPUSH,{370,10,789,45},STATIC,"Number of pushes in layer",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[3], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDMAXPUSH,{520,50,639,109},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[4], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELGETTIME,{370,120,789,155},STATIC,"Minimum time between products",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[5], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDGETTIME,{520,160,639,219},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[6], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDSAVE,{150,510,279,589},BUTTON,"Save",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[7], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELPPP,{420,230,739,265},STATIC,"Products per push",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[8], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_LISTBOXPPP,{420,270,739,489},LIST,"",BXS_VISIBLE,&formEditCPPattern[9], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_GROUPBOXNAME,{40,10,319,79},STATIC,"CP Pattern",BSS_WHITEFRAME|BXS_VISIBLE,&formEditCPPattern[10], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELCNAME,{50,30,309,65},STATIC,"cppTest",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[11], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_GROUPBOXLAYERIDX,{40,90,169,159},STATIC,"layeridx",BSS_WHITEFRAME|BXS_VISIBLE,&formEditCPPattern[12], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELLAYERIDX,{50,110,159,145},STATIC,"idx",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[13], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_GROUPBOXPPPIDX,{190,90,319,159},STATIC,"pppidx",BSS_WHITEFRAME|BXS_VISIBLE,&formEditCPPattern[14], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELPPPIDX,{200,110,309,145},STATIC,"idx",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[15], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_GROUPBOXPRODUCTCOUNT,{40,410,319,489},STATIC,"Number of products",BSS_WHITEFRAME|BXS_VISIBLE,&formEditCPPattern[16], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELPRODUCTCOUNT,{50,436,309,475},STATIC,"idx",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[17], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELMAXLAYERS,{40,230,319,265},STATIC,"Number of layers",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[18], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDLAYER,{480,540,679,579},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[19], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDNEXTLAYER,{690,540,739,579},BUTTON,">",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[20], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_TEXTLABELLAYER,{420,500,739,535},STATIC,"Select layer",BSS_CENTER|BXS_VISIBLE,&formEditCPPattern[21], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDPREVLAYER,{420,540,469,579},BUTTON,"<",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[22], &formEditCPPattern[0]}
 ,{FORMEDITCPPATTERN_CMDMAXLAYERS,{130,270,229,319},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditCPPattern[23], &formEditCPPattern[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditCPPattern[0]}
};

BX_BOOL formEditCPPatternProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditCPPatternUpdate(hBox);
				return formEditCPPatternUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditCPPatternInit(hBox);
				return formEditCPPatternUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITCPPATTERN_CMDCANCEL:
             return formEditCPPattern_cmdCancel_Click(hBox);
         case FORMEDITCPPATTERN_CMDMAXPUSH:
             return formEditCPPattern_cmdMaxpush_Click(hBox);
         case FORMEDITCPPATTERN_CMDGETTIME:
             return formEditCPPattern_cmdGettime_Click(hBox);
         case FORMEDITCPPATTERN_CMDSAVE:
             return formEditCPPattern_cmdSave_Click(hBox);
         case FORMEDITCPPATTERN_LISTBOXPPP:
             return formEditCPPattern_listBoxPPP_Click(hBox);
         case FORMEDITCPPATTERN_CMDLAYER:
             return formEditCPPattern_cmdLayer_Click(hBox);
         case FORMEDITCPPATTERN_CMDNEXTLAYER:
             return formEditCPPattern_cmdNextLayer_Click(hBox);
         case FORMEDITCPPATTERN_CMDPREVLAYER:
             return formEditCPPattern_cmdPrevLayer_Click(hBox);
         case FORMEDITCPPATTERN_CMDMAXLAYERS:
             return formEditCPPattern_cmdMaxLayers_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
