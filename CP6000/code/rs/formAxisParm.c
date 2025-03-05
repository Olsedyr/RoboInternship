//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formAxisParm.c
#include "Bx.h"
#include "formAxisParm.h"

BOXSTRUCT formAxisParm[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formAxisParm[1], NULL}
 ,{FORMAXISPARM_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formAxisParm[2], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_9,{280,70,390,104},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[3], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_16,{530,70,640,104},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[4], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_9,{390,70,519,99},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[5], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_16,{640,70,769,99},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[6], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_17,{640,110,769,139},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[7], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_10,{280,110,390,144},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[8], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_17,{530,110,640,138},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[9], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_10,{390,110,519,139},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[10], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_2,{30,110,140,144},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[11], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_2,{140,110,269,139},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[12], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_18,{530,150,640,184},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[13], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_11,{280,150,390,184},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[14], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_3,{30,150,140,184},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[15], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_18,{640,150,769,179},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[16], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_3,{140,150,269,179},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[17], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_11,{390,150,519,179},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[18], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_12,{280,190,390,224},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[19], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_4,{140,190,269,219},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[20], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_19,{530,190,640,224},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[21], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_4,{30,190,140,224},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[22], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_19,{640,190,769,219},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[23], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_12,{390,190,519,219},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[24], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_13,{390,230,519,259},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[25], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_5,{30,230,140,264},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[26], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_20,{640,230,769,259},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[27], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_13,{280,230,390,264},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[28], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_5,{140,230,269,259},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[29], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_20,{530,230,640,264},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[30], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_14,{280,270,390,304},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[31], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_14,{390,270,519,299},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[32], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_6,{30,270,140,304},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[33], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_21,{530,270,640,304},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[34], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_21,{640,270,769,299},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[35], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_6,{140,270,269,299},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[36], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_22,{640,310,769,339},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[37], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_15,{280,310,390,344},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[38], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_15,{390,310,519,339},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[39], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_7,{140,310,269,339},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[40], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_7,{30,310,140,344},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[41], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_8,{140,350,269,379},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[42], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_8,{30,350,140,384},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[43], &formAxisParm[0]}
 ,{FORMAXISPARM_GROUPBOX1,{30,400,620,579},STATIC,"Bank 1",BSS_WHITEFRAME|BXS_VISIBLE,&formAxisParm[44], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_2,{40,459,122,493},STATIC,"NTYPE",BXS_VISIBLE,&formAxisParm[45], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_3,{40,499,122,533},STATIC,"MPOS",BXS_VISIBLE,&formAxisParm[46], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_4,{40,540,122,574},STATIC,"DPOS",BXS_VISIBLE,&formAxisParm[47], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_1,{40,419,122,453},STATIC,"MTYPE",BXS_VISIBLE,&formAxisParm[48], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_5__DOCTYPE_UI_SELECTION__UI_SELECTION___WIDGET_CLASS__QLABEL________PROPERTY_NAME__NAME____________CSTRING_TEXTBANK1_1__CSTRING________PROPERTY_______PROPERTY_NAME__GEOMETRY____________RECT_______________X_10__X_______________Y_19__Y_______________WIDTH_83__WIDTH_______________HEIGHT_35__HEIGHT____________RECT________PROPERTY_______PROPERTY_NAME__PALETTEFOREGROUNDCOLOR____________COLOR_______________RED_255__RED_______________GREEN_255__GREEN_______________BLUE_255__BLUE____________COLOR________PROPERTY_______PROPERTY_NAME__FONT____________FONT_______________FAMILY_HELVETICA__URW___FAMILY_______________POINTSIZE_18__POINTSIZE____________FONT________PROPERTY_______PROPERTY_NAME__FRAMESHAPE____________ENUM_NOFRAME__ENUM________PROPERTY_______PROPERTY_NAME__FRAMESHADOW____________ENUM_PLAIN__ENUM________PROPERTY_______PROPERTY_NAME__TEXT____________STRING_MTYPE__STRING________PROPERTY_______PROPERTY_NAME__ALIGNMENT____________SET_ALIGNVCENTER__SET________PROPERTY____WIDGET____UI_SELECTION__,{310,420,399,454},STATIC,"FE",BXS_VISIBLE,&formAxisParm[49], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_2,{140,460,269,494},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[50], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_3,{140,500,269,534},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[51], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_4,{140,540,269,574},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[52], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_7,{450,500,579,534},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[53], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_6,{450,460,579,494},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[54], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_5,{450,420,579,454},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[55], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_7,{310,500,422,534},STATIC,"VPSPEED",BXS_VISIBLE,&formAxisParm[56], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANK1_6,{310,460,404,494},STATIC,"STATUS",BXS_VISIBLE,&formAxisParm[57], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTBANKV_1,{140,420,269,454},STATIC,"value",BSS_RIGHT|BXS_VISIBLE,&formAxisParm[58], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_22,{530,310,640,344},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[59], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL_1,{30,70,140,104},STATIC,"Parameter",BXS_VISIBLE,&formAxisParm[60], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDPARAM_1,{140,70,269,99},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[61], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDRETURN,{640,490,769,579},BUTTON,"Return",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[62], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDSAVE,{640,360,769,449},BUTTON,"Save",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[63], &formAxisParm[0]}
 ,{FORMAXISPARM_TEXTLABEL2_2_2,{330,10,389,44},STATIC,"Axis",BXS_VISIBLE,&formAxisParm[64], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDAXISNUM,{480,10,549,59},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[65], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDAXISNUMMINUS,{400,10,469,59},BUTTON,"-",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[66], &formAxisParm[0]}
 ,{FORMAXISPARM_CMDAXISNUMPLUS,{560,10,629,59},BUTTON,"+",BBS_PUSHBUTTON|BXS_VISIBLE,&formAxisParm[67], &formAxisParm[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formAxisParm[0]}
};

BX_BOOL formAxisParmProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formAxisParmUpdate(hBox);
				return formAxisParmUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formAxisParmInit(hBox);
				return formAxisParmUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMAXISPARM_CMDPARAM_9:
             return formAxisParm_cmdParam_9_Click(hBox);
         case FORMAXISPARM_CMDPARAM_16:
             return formAxisParm_cmdParam_16_Click(hBox);
         case FORMAXISPARM_CMDPARAM_17:
             return formAxisParm_cmdParam_17_Click(hBox);
         case FORMAXISPARM_CMDPARAM_10:
             return formAxisParm_cmdParam_10_Click(hBox);
         case FORMAXISPARM_CMDPARAM_2:
             return formAxisParm_cmdParam_2_Click(hBox);
         case FORMAXISPARM_CMDPARAM_18:
             return formAxisParm_cmdParam_18_Click(hBox);
         case FORMAXISPARM_CMDPARAM_3:
             return formAxisParm_cmdParam_3_Click(hBox);
         case FORMAXISPARM_CMDPARAM_11:
             return formAxisParm_cmdParam_11_Click(hBox);
         case FORMAXISPARM_CMDPARAM_4:
             return formAxisParm_cmdParam_4_Click(hBox);
         case FORMAXISPARM_CMDPARAM_19:
             return formAxisParm_cmdParam_19_Click(hBox);
         case FORMAXISPARM_CMDPARAM_12:
             return formAxisParm_cmdParam_12_Click(hBox);
         case FORMAXISPARM_CMDPARAM_13:
             return formAxisParm_cmdParam_13_Click(hBox);
         case FORMAXISPARM_CMDPARAM_20:
             return formAxisParm_cmdParam_20_Click(hBox);
         case FORMAXISPARM_CMDPARAM_5:
             return formAxisParm_cmdParam_5_Click(hBox);
         case FORMAXISPARM_CMDPARAM_14:
             return formAxisParm_cmdParam_14_Click(hBox);
         case FORMAXISPARM_CMDPARAM_21:
             return formAxisParm_cmdParam_21_Click(hBox);
         case FORMAXISPARM_CMDPARAM_6:
             return formAxisParm_cmdParam_6_Click(hBox);
         case FORMAXISPARM_CMDPARAM_22:
             return formAxisParm_cmdParam_22_Click(hBox);
         case FORMAXISPARM_CMDPARAM_15:
             return formAxisParm_cmdParam_15_Click(hBox);
         case FORMAXISPARM_CMDPARAM_7:
             return formAxisParm_cmdParam_7_Click(hBox);
         case FORMAXISPARM_CMDPARAM_8:
             return formAxisParm_cmdParam_8_Click(hBox);
         case FORMAXISPARM_CMDPARAM_1:
             return formAxisParm_cmdParam_1_Click(hBox);
         case FORMAXISPARM_CMDRETURN:
             return formAxisParm_cmdReturn_Click(hBox);
         case FORMAXISPARM_CMDSAVE:
             return formAxisParm_cmdSave_Click(hBox);
         case FORMAXISPARM_CMDAXISNUM:
             return formAxisParm_cmdAxisNum_Click(hBox);
         case FORMAXISPARM_CMDAXISNUMMINUS:
             return formAxisParm_cmdAxisNumMinus_Click(hBox);
         case FORMAXISPARM_CMDAXISNUMPLUS:
             return formAxisParm_cmdAxisNumPlus_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
