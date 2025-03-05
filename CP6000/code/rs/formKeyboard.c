//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formKeyboard.c
#include "Bx.h"
#include "formKeyboard.h"

BOXSTRUCT formKeyboard[] = {
 {10000,{0,0,862,600},DIALOG,"",BXS_VISIBLE,&formKeyboard[1], NULL}
 ,{FORMKEYBOARD_CMD2,{80,100,139,159},BUTTON,"2",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[2], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD3,{150,100,209,159},BUTTON,"3",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[3], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD4,{220,100,279,159},BUTTON,"4",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[4], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD5,{290,100,349,159},BUTTON,"5",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[5], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD6,{360,100,419,159},BUTTON,"6",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[6], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD7,{430,100,489,159},BUTTON,"7",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[7], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD8,{500,100,559,159},BUTTON,"8",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[8], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD9,{570,100,629,159},BUTTON,"9",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[9], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD0,{640,100,699,159},BUTTON,"0",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[10], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDQ,{20,170,79,229},BUTTON,"Q",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[11], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDW,{90,170,149,229},BUTTON,"W",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[12], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDE,{160,170,219,229},BUTTON,"E",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[13], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDR,{230,170,289,229},BUTTON,"R",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[14], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDT,{300,170,359,229},BUTTON,"T",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[15], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDY,{370,170,429,229},BUTTON,"Y",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[16], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDU,{440,170,499,229},BUTTON,"U",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[17], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDI,{510,170,569,229},BUTTON,"I",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[18], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDO,{580,170,639,229},BUTTON,"O",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[19], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDP,{650,170,709,229},BUTTON,"P",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[20], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDCOLON,{720,170,779,229},BUTTON,":",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[21], &formKeyboard[0]}
 ,{FORMKEYBOARD_TEXTLABEL1,{50,20,779,59},STATIC,"0",BXS_BORDER|BXS_VISIBLE,&formKeyboard[22], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMD1,{10,100,69,159},BUTTON,"1",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[23], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDENTER,{500,490,619,579},BUTTON,"Enter",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[24], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDCANCEL,{640,490,759,579},BUTTON,"Cancel",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[25], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDA,{30,240,89,299},BUTTON,"A",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[26], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDS,{100,240,159,299},BUTTON,"S",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[27], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDD,{170,240,229,299},BUTTON,"D",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[28], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDF,{240,240,299,299},BUTTON,"F",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[29], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDG,{310,240,369,299},BUTTON,"G",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[30], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDH,{380,240,439,299},BUTTON,"H",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[31], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDJ,{450,240,509,299},BUTTON,"J",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[32], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDK,{520,240,579,299},BUTTON,"K",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[33], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDL,{590,240,649,299},BUTTON,"L",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[34], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDAPO,{660,240,719,299},BUTTON,"'",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[35], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDSLASH,{730,240,789,299},BUTTON,"/",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[36], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDZ,{60,310,119,369},BUTTON,"Z",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[37], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDX,{130,310,189,369},BUTTON,"X",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[38], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDC,{200,310,259,369},BUTTON,"C",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[39], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDV,{270,310,329,369},BUTTON,"V",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[40], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDB,{340,310,399,369},BUTTON,"B",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[41], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDN,{410,310,469,369},BUTTON,"N",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[42], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDM,{480,310,539,369},BUTTON,"M",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[43], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDCOMMA,{550,310,609,369},BUTTON,",",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[44], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDDOT,{620,310,679,369},BUTTON,".",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[45], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDHYPHEN,{690,310,749,369},BUTTON,"-",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[46], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDSPACEBAR,{220,380,659,439},BUTTON,"",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[47], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDSHIFT,{90,380,209,439},BUTTON,"",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[48], &formKeyboard[0]}
 ,{FORMKEYBOARD_CMDBACKSPACE,{710,100,789,159},BUTTON,"",BBS_PUSHBUTTON|BXS_VISIBLE,&formKeyboard[49], &formKeyboard[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formKeyboard[0]}
};

BX_BOOL formKeyboardProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formKeyboardUpdate(hBox);
				return formKeyboardUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formKeyboardInit(hBox);
				return formKeyboardUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMKEYBOARD_CMD2:
             return formKeyboard_cmd2_Click(hBox);
         case FORMKEYBOARD_CMD3:
             return formKeyboard_cmd3_Click(hBox);
         case FORMKEYBOARD_CMD4:
             return formKeyboard_cmd4_Click(hBox);
         case FORMKEYBOARD_CMD5:
             return formKeyboard_cmd5_Click(hBox);
         case FORMKEYBOARD_CMD6:
             return formKeyboard_cmd6_Click(hBox);
         case FORMKEYBOARD_CMD7:
             return formKeyboard_cmd7_Click(hBox);
         case FORMKEYBOARD_CMD8:
             return formKeyboard_cmd8_Click(hBox);
         case FORMKEYBOARD_CMD9:
             return formKeyboard_cmd9_Click(hBox);
         case FORMKEYBOARD_CMD0:
             return formKeyboard_cmd0_Click(hBox);
         case FORMKEYBOARD_CMDQ:
             return formKeyboard_cmdQ_Click(hBox);
         case FORMKEYBOARD_CMDW:
             return formKeyboard_cmdW_Click(hBox);
         case FORMKEYBOARD_CMDE:
             return formKeyboard_cmdE_Click(hBox);
         case FORMKEYBOARD_CMDR:
             return formKeyboard_cmdR_Click(hBox);
         case FORMKEYBOARD_CMDT:
             return formKeyboard_cmdT_Click(hBox);
         case FORMKEYBOARD_CMDY:
             return formKeyboard_cmdY_Click(hBox);
         case FORMKEYBOARD_CMDU:
             return formKeyboard_cmdU_Click(hBox);
         case FORMKEYBOARD_CMDI:
             return formKeyboard_cmdI_Click(hBox);
         case FORMKEYBOARD_CMDO:
             return formKeyboard_cmdO_Click(hBox);
         case FORMKEYBOARD_CMDP:
             return formKeyboard_cmdP_Click(hBox);
         case FORMKEYBOARD_CMDCOLON:
             return formKeyboard_cmdColon_Click(hBox);
         case FORMKEYBOARD_CMD1:
             return formKeyboard_cmd1_Click(hBox);
         case FORMKEYBOARD_CMDENTER:
             return formKeyboard_cmdEnter_Click(hBox);
         case FORMKEYBOARD_CMDCANCEL:
             return formKeyboard_cmdCancel_Click(hBox);
         case FORMKEYBOARD_CMDA:
             return formKeyboard_cmdA_Click(hBox);
         case FORMKEYBOARD_CMDS:
             return formKeyboard_cmdS_Click(hBox);
         case FORMKEYBOARD_CMDD:
             return formKeyboard_cmdD_Click(hBox);
         case FORMKEYBOARD_CMDF:
             return formKeyboard_cmdF_Click(hBox);
         case FORMKEYBOARD_CMDG:
             return formKeyboard_cmdG_Click(hBox);
         case FORMKEYBOARD_CMDH:
             return formKeyboard_cmdH_Click(hBox);
         case FORMKEYBOARD_CMDJ:
             return formKeyboard_cmdJ_Click(hBox);
         case FORMKEYBOARD_CMDK:
             return formKeyboard_cmdK_Click(hBox);
         case FORMKEYBOARD_CMDL:
             return formKeyboard_cmdL_Click(hBox);
         case FORMKEYBOARD_CMDAPO:
             return formKeyboard_cmdApo_Click(hBox);
         case FORMKEYBOARD_CMDSLASH:
             return formKeyboard_cmdSlash_Click(hBox);
         case FORMKEYBOARD_CMDZ:
             return formKeyboard_cmdZ_Click(hBox);
         case FORMKEYBOARD_CMDX:
             return formKeyboard_cmdX_Click(hBox);
         case FORMKEYBOARD_CMDC:
             return formKeyboard_cmdC_Click(hBox);
         case FORMKEYBOARD_CMDV:
             return formKeyboard_cmdV_Click(hBox);
         case FORMKEYBOARD_CMDB:
             return formKeyboard_cmdB_Click(hBox);
         case FORMKEYBOARD_CMDN:
             return formKeyboard_cmdN_Click(hBox);
         case FORMKEYBOARD_CMDM:
             return formKeyboard_cmdM_Click(hBox);
         case FORMKEYBOARD_CMDCOMMA:
             return formKeyboard_cmdComma_Click(hBox);
         case FORMKEYBOARD_CMDDOT:
             return formKeyboard_cmdDot_Click(hBox);
         case FORMKEYBOARD_CMDHYPHEN:
             return formKeyboard_cmdHyphen_Click(hBox);
         case FORMKEYBOARD_CMDSPACEBAR:
             return formKeyboard_cmdSpacebar_Click(hBox);
         case FORMKEYBOARD_CMDSHIFT:
             return formKeyboard_cmdShift_Click(hBox);
         case FORMKEYBOARD_CMDBACKSPACE:
             return formKeyboard_cmdBackSpace_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
