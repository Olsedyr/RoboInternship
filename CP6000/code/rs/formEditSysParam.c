//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditSysParam.c
#include "Bx.h"
#include "formEditSysParam.h"

BOXSTRUCT formEditSysParam[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formEditSysParam[1], NULL}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formEditSysParam[2], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDRETURN,{520,480,649,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[3], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDCANCEL,{660,480,789,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[4], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_GROUPBOX1,{10,50,779,459},STATIC,"Limits",BSS_WHITEFRAME|BXS_VISIBLE,&formEditSysParam[5], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_4,{30,400,99,434},STATIC,"E",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[6], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDCMIN,{110,250,239,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[7], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_3,{30,330,99,364},STATIC,"D",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[8], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDBMIN,{110,180,239,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[9], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_2_2_2_3_3,{30,260,99,294},STATIC,"C",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[10], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDEMIN,{110,390,239,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[11], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_2_2_2_3_2,{30,190,99,224},STATIC,"B",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[12], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDAMIN,{110,110,239,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[13], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2,{30,120,99,154},STATIC,"A",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[14], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDDMIN,{110,320,239,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[15], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDAMAX,{250,110,369,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[16], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDBMAX,{250,180,369,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[17], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDCMAX,{250,250,369,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[18], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDDMAX,{250,320,369,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[19], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDEMAX,{250,390,369,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[20], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDBCOFF,{600,180,719,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[21], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDCCOFF,{600,250,719,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[22], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDDCOFF,{600,320,719,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[23], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDECOFF,{600,390,719,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[24], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDACOFF,{600,110,719,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[25], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDBROFF,{430,180,549,229},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[26], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDCROFF,{430,250,549,299},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[27], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDEROFF,{430,390,549,439},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[28], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDAROFF,{430,110,549,159},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[29], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_CMDDROFF,{430,320,549,369},BUTTON,"0.0000",BBS_PUSHBUTTON|BXS_VISIBLE,&formEditSysParam[30], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_5_2,{420,70,559,104},STATIC,"Robot offset",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[31], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_5_2_2,{590,70,729,104},STATIC,"Calib offset",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[32], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_5,{130,70,199,104},STATIC,"Min",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[33], &formEditSysParam[0]}
 ,{FORMEDITSYSPARAM_TEXTLABEL2_6,{260,70,329,104},STATIC,"Max",BSS_CENTER|BXS_VISIBLE,&formEditSysParam[34], &formEditSysParam[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formEditSysParam[0]}
};

BX_BOOL formEditSysParamProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formEditSysParamUpdate(hBox);
				return formEditSysParamUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formEditSysParamInit(hBox);
				return formEditSysParamUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMEDITSYSPARAM_CMDRETURN:
             return formEditSysParam_cmdReturn_Click(hBox);
         case FORMEDITSYSPARAM_CMDCANCEL:
             return formEditSysParam_cmdCancel_Click(hBox);
         case FORMEDITSYSPARAM_CMDCMIN:
             return formEditSysParam_cmdCMin_Click(hBox);
         case FORMEDITSYSPARAM_CMDBMIN:
             return formEditSysParam_cmdBMin_Click(hBox);
         case FORMEDITSYSPARAM_CMDEMIN:
             return formEditSysParam_cmdEMin_Click(hBox);
         case FORMEDITSYSPARAM_CMDAMIN:
             return formEditSysParam_cmdAMin_Click(hBox);
         case FORMEDITSYSPARAM_CMDDMIN:
             return formEditSysParam_cmdDMin_Click(hBox);
         case FORMEDITSYSPARAM_CMDAMAX:
             return formEditSysParam_cmdAMax_Click(hBox);
         case FORMEDITSYSPARAM_CMDBMAX:
             return formEditSysParam_cmdBMax_Click(hBox);
         case FORMEDITSYSPARAM_CMDCMAX:
             return formEditSysParam_cmdCMax_Click(hBox);
         case FORMEDITSYSPARAM_CMDDMAX:
             return formEditSysParam_cmdDMax_Click(hBox);
         case FORMEDITSYSPARAM_CMDEMAX:
             return formEditSysParam_cmdEMax_Click(hBox);
         case FORMEDITSYSPARAM_CMDBCOFF:
             return formEditSysParam_cmdBCOff_Click(hBox);
         case FORMEDITSYSPARAM_CMDCCOFF:
             return formEditSysParam_cmdCCOff_Click(hBox);
         case FORMEDITSYSPARAM_CMDDCOFF:
             return formEditSysParam_cmdDCOff_Click(hBox);
         case FORMEDITSYSPARAM_CMDECOFF:
             return formEditSysParam_cmdECOff_Click(hBox);
         case FORMEDITSYSPARAM_CMDACOFF:
             return formEditSysParam_cmdACOff_Click(hBox);
         case FORMEDITSYSPARAM_CMDBROFF:
             return formEditSysParam_cmdBROff_Click(hBox);
         case FORMEDITSYSPARAM_CMDCROFF:
             return formEditSysParam_cmdCROff_Click(hBox);
         case FORMEDITSYSPARAM_CMDEROFF:
             return formEditSysParam_cmdEROff_Click(hBox);
         case FORMEDITSYSPARAM_CMDAROFF:
             return formEditSysParam_cmdAROff_Click(hBox);
         case FORMEDITSYSPARAM_CMDDROFF:
             return formEditSysParam_cmdDROff_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
