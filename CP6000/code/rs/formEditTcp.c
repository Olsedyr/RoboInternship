//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditTcp.c
#include "Bx.h"
#include "formEditTcp.h"

BOXSTRUCT formEditTcp[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditTcp[1], NULL}
 ,{FORMEDITTCP_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formEditTcp[2], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[3], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[4], &formEditTcp[0]}
 ,{FORMEDITTCP_GROUPBOX1,{150,50,639,459},STATIC,"TCP",BSS_WHITEFRAME|BXS_VISIBLE,&formEditTcp[5], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_5_2,{260,70,399,104},STATIC,"Case",BSS_CENTER|BXS_VISIBLE,&formEditTcp[6], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDEROFF,{270,390,389,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[7], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDDROFF,{270,320,389,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[8], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDCROFF,{270,250,389,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[9], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDBROFF,{270,180,389,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[10], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDAROFF,{270,110,389,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[11], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDACOFF,{460,110,579,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[12], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDBCOFF,{460,180,579,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[13], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDCCOFF,{460,250,579,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[14], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDDCOFF,{460,320,579,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[15], &formEditTcp[0]}
 ,{FORMEDITTCP_CMDECOFF,{460,390,579,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditTcp[16], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2,{180,120,249,154},STATIC,"X",BSS_CENTER|BXS_VISIBLE,&formEditTcp[17], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_2_2_2_3_2,{180,190,249,224},STATIC,"Y",BSS_CENTER|BXS_VISIBLE,&formEditTcp[18], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_2_2_2_3_3,{180,260,249,294},STATIC,"Z",BSS_CENTER|BXS_VISIBLE,&formEditTcp[19], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_3,{180,330,249,364},STATIC,"V",BSS_CENTER|BXS_VISIBLE,&formEditTcp[20], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_4,{180,400,249,434},STATIC,"W",BSS_CENTER|BXS_VISIBLE,&formEditTcp[21], &formEditTcp[0]}
 ,{FORMEDITTCP_TEXTLABEL2_5_2_2,{450,70,589,104},STATIC,"Bag",BSS_CENTER|BXS_VISIBLE,&formEditTcp[22], &formEditTcp[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditTcp[0]}
};

BX_BOOL formEditTcpProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditTcpUpdate(hBox);
				return formEditTcpUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditTcpInit(hBox);
				return formEditTcpUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITTCP_CMDCANCEL:
             return formEditTcp_cmdCancel_Click(hBox);
         case FORMEDITTCP_CMDRETURN:
             return formEditTcp_cmdReturn_Click(hBox);
         case FORMEDITTCP_CMDEROFF:
             return formEditTcp_cmdEROff_Click(hBox);
         case FORMEDITTCP_CMDDROFF:
             return formEditTcp_cmdDROff_Click(hBox);
         case FORMEDITTCP_CMDCROFF:
             return formEditTcp_cmdCROff_Click(hBox);
         case FORMEDITTCP_CMDBROFF:
             return formEditTcp_cmdBROff_Click(hBox);
         case FORMEDITTCP_CMDAROFF:
             return formEditTcp_cmdAROff_Click(hBox);
         case FORMEDITTCP_CMDACOFF:
             return formEditTcp_cmdACOff_Click(hBox);
         case FORMEDITTCP_CMDBCOFF:
             return formEditTcp_cmdBCOff_Click(hBox);
         case FORMEDITTCP_CMDCCOFF:
             return formEditTcp_cmdCCOff_Click(hBox);
         case FORMEDITTCP_CMDDCOFF:
             return formEditTcp_cmdDCOff_Click(hBox);
         case FORMEDITTCP_CMDECOFF:
             return formEditTcp_cmdECOff_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
