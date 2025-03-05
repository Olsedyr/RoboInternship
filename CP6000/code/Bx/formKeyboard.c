//////////////////////////////////////////////////////
// 
// formKeyboard.c
// 
////////////////////////////////////////////////////// 

#include "Bx.h"
#include "formKeyboard.h"
char formKeyboardText[][MAXLANGUAGE][255] = {
	{""
	,""
	,""
	,""
	 ,""}
	,{"Help"
	,"Hjælp"
	,"Hilfe"
	,"Aiuto"
	,"Aide"}  //BxButton2 = FORMKEYBOARD_BXBUTTON2
	,{"Close"
	,"Luk"
	,"Schließ"
	,"Chiuso"
	,"Fermer"}  //BxButton1 = FORMKEYBOARD_BXBUTTON1
	,{"OK"
	,"OK"
	,"OK"
	,"Ok"
	,"Ok"}  //cmdEnter = FORMKEYBOARD_CMDENTER
	,{" "
	," "
	,""
	,"x"
	,"x"}  //cmdShift = FORMKEYBOARD_CMDSHIFT
	,{" "
	," "
	,""
	,"x"
	,"x"}  //cmdBkSp = FORMKEYBOARD_CMDBKSP
	,{"0"
	,"0"
	,"0"
	,"0"
	,"0"}  //cmd0 = FORMKEYBOARD_CMD0
	,{"9"
	,"9"
	,"9"
	,"9"
	,"9"}  //cmd9 = FORMKEYBOARD_CMD9
	,{"8"
	,"8"
	,"8"
	,"8"
	,"8"}  //cmd8 = FORMKEYBOARD_CMD8
	,{"7"
	,"7"
	,"7"
	,"7"
	,"7"}  //cmd7 = FORMKEYBOARD_CMD7
	,{"6"
	,"6"
	,"6"
	,"6"
	,"6"}  //cmd6 = FORMKEYBOARD_CMD6
	,{"5"
	,"5"
	,"5"
	,"5"
	,"5"}  //cmd5 = FORMKEYBOARD_CMD5
	,{"4"
	,"4"
	,"4"
	,"4"
	,"4"}  //cmd4 = FORMKEYBOARD_CMD4
	,{"3"
	,"3"
	,"3"
	,"3"
	,"3"}  //cmd3 = FORMKEYBOARD_CMD3
	,{"2"
	,"2"
	,"2"
	,"2"
	,"2"}  //cmd2 = FORMKEYBOARD_CMD2
	,{"1"
	,"1"
	,"1"
	,"1"
	,"1"}  //cmd1 = FORMKEYBOARD_CMD1
	,{" "
	," "
	,""
	,"x"
	,"x"}  //cmdSpace = FORMKEYBOARD_CMDSPACE
	,{""
	,""
	,""
	,""
	,""}  //labText = FORMKEYBOARD_LABTEXT
	,{"-"
	,"-"
	,"-"
	,"-"
	,"-"}  //cmdStreg = FORMKEYBOARD_CMDSTREG
	,{"."
	,"."
	,"."
	,"."
	,"."}  //cmdPunktum = FORMKEYBOARD_CMDPUNKTUM
	,{","
	,","
	,","
	,","
	,","}  //cmdKomma = FORMKEYBOARD_CMDKOMMA
	,{"m"
	,"m"
	,"m"
	,"m"
	,"m"}  //cmdM = FORMKEYBOARD_CMDM
	,{"n"
	,"n"
	,"n"
	,"n"
	,"n"}  //cmdN = FORMKEYBOARD_CMDN
	,{"b"
	,"b"
	,"b"
	,"b"
	,"b"}  //cmdB = FORMKEYBOARD_CMDB
	,{"v"
	,"v"
	,"v"
	,"v"
	,"v"}  //cmdV = FORMKEYBOARD_CMDV
	,{"c"
	,"c"
	,"c"
	,"c"
	,"c"}  //cmdC = FORMKEYBOARD_CMDC
	,{"x"
	,"x"
	,"x"
	,"x"
	,"x"}  //cmdX = FORMKEYBOARD_CMDX
	,{"z"
	,"z"
	,"z"
	,"z"
	,"z"}  //cmdZ = FORMKEYBOARD_CMDZ
	,{"/"
	,"ø"
	,"ö"
	,"/"
	,"/"}  //cmdL2 = FORMKEYBOARD_CMDL2
	,{"'"
	,"æ"
	,"ä"
	,"'"
	,"x"}  //cmdL1 = FORMKEYBOARD_CMDL1
	,{"l"
	,"l"
	,"l"
	,"I"
	,"l"}  //cmdL = FORMKEYBOARD_CMDL
	,{"k"
	,"k"
	,"k"
	,"k"
	,"k"}  //cmdK = FORMKEYBOARD_CMDK
	,{"j"
	,"j"
	,"j"
	,"j"
	,"j"}  //cmdJ = FORMKEYBOARD_CMDJ
	,{"h"
	,"h"
	,"h"
	,"h"
	,"h"}  //cmdH = FORMKEYBOARD_CMDH
	,{"g"
	,"g"
	,"g"
	,"g"
	,"g"}  //cmdG = FORMKEYBOARD_CMDG
	,{"f"
	,"f"
	,"f"
	,"f"
	,"f"}  //cmdF = FORMKEYBOARD_CMDF
	,{"d"
	,"d"
	,"d"
	,"d"
	,"d"}  //cmdD = FORMKEYBOARD_CMDD
	,{"s"
	,"s"
	,"s"
	,"s"
	,"s"}  //cmdS = FORMKEYBOARD_CMDS
	,{":"
	,"å"
	,"ü"
	,":"
	,":"}  //cmdL3 = FORMKEYBOARD_CMDL3
	,{"p"
	,"p"
	,"p"
	,"p"
	,"p"}  //cmdP = FORMKEYBOARD_CMDP
	,{"o"
	,"o"
	,"o"
	,"o"
	,"o"}  //cmdO = FORMKEYBOARD_CMDO
	,{"i"
	,"i"
	,"i"
	,"i"
	,"i"}  //cmdI = FORMKEYBOARD_CMDI
	,{"u"
	,"u"
	,"u"
	,"u"
	,"u"}  //cmdU = FORMKEYBOARD_CMDU
	,{"y"
	,"y"
	,"y"
	,"y"
	,"y"}  //cmdY = FORMKEYBOARD_CMDY
	,{"t"
	,"t"
	,"t"
	,"t"
	,"t"}  //cmdT = FORMKEYBOARD_CMDT
	,{"r"
	,"r"
	,"r"
	,"r"
	,"r"}  //cmdR = FORMKEYBOARD_CMDR
	,{"e"
	,"e"
	,"e"
	,"e"
	,"e"}  //cmdE = FORMKEYBOARD_CMDE
	,{"w"
	,"w"
	,"w"
	,"w"
	,"w"}  //cmdW = FORMKEYBOARD_CMDW
	,{"a"
	,"a"
	,"a"
	,"a"
	,"a"}  //cmdA = FORMKEYBOARD_CMDA
	,{"q"
	,"q"
	,"q"
	,"q"
	,"q"}  //cmdQ = FORMKEYBOARD_CMDQ
};

BOXSTRUCT formKeyboard[] = {
	{10000,{0,0,799,599},DIALOG,&formKeyboardText[0][0][0],BXS_VISIBLE,&formKeyboard[1],NULL,0}
	,{FORMKEYBOARD_BXBUTTON2,{8,520,113,593},BUTTON,&formKeyboardText[1][0][0],BBS_PUSHBUTTON| BXS_DISABLED,&formKeyboard[2],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_BXBUTTON1,{688,520,793,593},BUTTON,&formKeyboardText[2][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[3],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDENTER,{576,520,681,593},BUTTON,&formKeyboardText[3][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[4],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDSHIFT,{96,376,209,433},BUTTON,&formKeyboardText[4][0][0],BBS_PUSHBUTTON| BBS_ICON| BXS_VISIBLE,&formKeyboard[5],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDBKSP,{664,120,769,177},BUTTON,&formKeyboardText[5][0][0],BBS_PUSHBUTTON| BBS_ICON| BXS_VISIBLE,&formKeyboard[6],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD0,{600,120,657,177},BUTTON,&formKeyboardText[6][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[7],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD9,{536,120,593,177},BUTTON,&formKeyboardText[7][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[8],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD8,{472,120,529,177},BUTTON,&formKeyboardText[8][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[9],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD7,{408,120,465,177},BUTTON,&formKeyboardText[9][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[10],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD6,{344,120,401,177},BUTTON,&formKeyboardText[10][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[11],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD5,{280,120,337,177},BUTTON,&formKeyboardText[11][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[12],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD4,{216,120,273,177},BUTTON,&formKeyboardText[12][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[13],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD3,{152,120,209,177},BUTTON,&formKeyboardText[13][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[14],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD2,{88,120,145,177},BUTTON,&formKeyboardText[14][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[15],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMD1,{24,120,81,177},BUTTON,&formKeyboardText[15][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[16],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDSPACE,{216,376,617,433},BUTTON,&formKeyboardText[16][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[17],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_LABTEXT,{24,32,769,89},STATIC,&formKeyboardText[17][0][0],0| BXS_BORDER| BXS_VISIBLE,&formKeyboard[18],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDSTREG,{648,312,705,369},BUTTON,&formKeyboardText[18][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[19],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDPUNKTUM,{584,312,641,369},BUTTON,&formKeyboardText[19][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[20],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDKOMMA,{520,312,577,369},BUTTON,&formKeyboardText[20][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[21],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDM,{456,312,513,369},BUTTON,&formKeyboardText[21][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[22],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDN,{392,312,449,369},BUTTON,&formKeyboardText[22][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[23],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDB,{328,312,385,369},BUTTON,&formKeyboardText[23][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[24],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDV,{264,312,321,369},BUTTON,&formKeyboardText[24][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[25],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDC,{200,312,257,369},BUTTON,&formKeyboardText[25][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[26],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDX,{136,312,193,369},BUTTON,&formKeyboardText[26][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[27],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDZ,{72,312,129,369},BUTTON,&formKeyboardText[27][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[28],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDL2,{688,248,745,305},BUTTON,&formKeyboardText[28][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[29],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDL1,{624,248,681,305},BUTTON,&formKeyboardText[29][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[30],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDL,{560,248,617,305},BUTTON,&formKeyboardText[30][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[31],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDK,{496,248,553,305},BUTTON,&formKeyboardText[31][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[32],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDJ,{432,248,489,305},BUTTON,&formKeyboardText[32][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[33],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDH,{368,248,425,305},BUTTON,&formKeyboardText[33][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[34],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDG,{304,248,361,305},BUTTON,&formKeyboardText[34][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[35],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDF,{240,248,297,305},BUTTON,&formKeyboardText[35][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[36],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDD,{176,248,233,305},BUTTON,&formKeyboardText[36][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[37],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDS,{112,248,169,305},BUTTON,&formKeyboardText[37][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[38],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDL3,{672,184,729,241},BUTTON,&formKeyboardText[38][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[39],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDP,{608,184,665,241},BUTTON,&formKeyboardText[39][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[40],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDO,{544,184,601,241},BUTTON,&formKeyboardText[40][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[41],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDI,{480,184,537,241},BUTTON,&formKeyboardText[41][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[42],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDU,{416,184,473,241},BUTTON,&formKeyboardText[42][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[43],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDY,{352,184,409,241},BUTTON,&formKeyboardText[43][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[44],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDT,{288,184,345,241},BUTTON,&formKeyboardText[44][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[45],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDR,{224,184,281,241},BUTTON,&formKeyboardText[45][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[46],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDE,{160,184,217,241},BUTTON,&formKeyboardText[46][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[47],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDW,{96,184,153,241},BUTTON,&formKeyboardText[47][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[48],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDA,{48,248,105,305},BUTTON,&formKeyboardText[48][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,&formKeyboard[49],&formKeyboard[0],BROWSERLEVEL}
	,{FORMKEYBOARD_CMDQ,{32,184,89,241},BUTTON,&formKeyboardText[49][0][0],BBS_PUSHBUTTON| BXS_VISIBLE,NULL,&formKeyboard[0],BROWSERLEVEL}
};

int hardcopyformKeyboard=FALSE;
BX_BOOL SaveDIB(char* filename, long BW, long BH);
void formKeyboardUserUpdate(HBOX hBox);
void formKeyboardUserInit(HBOX hBox);
BX_BOOL formKeyboardInit(HBOX hBox);
BX_BOOL formKeyboardProc(HBOX hBox, BX_UINT uMsg
	,BX_WPARAM wParam, BX_LPARAM lParam)
{
	switch(uMsg)
	{ 
		case BM_UPDATE:
			{
				formKeyboardUserUpdate(hBox);
				return TRUE;
				break;
			}
		case BM_INITDIALOG:
			{
				formKeyboardInit(hBox);
				formKeyboardUserInit(hBox);
				formKeyboardUpdate(hBox);
				return TRUE;
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
					case FORMKEYBOARD_BXBUTTON2:
						formKeyboard_BxButton2_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_BXBUTTON1:
						formKeyboard_BxButton1_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDENTER:
						formKeyboard_cmdEnter_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDSHIFT:
						formKeyboard_cmdShift_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDBKSP:
						formKeyboard_cmdBkSp_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD0:
						formKeyboard_cmd0_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD9:
						formKeyboard_cmd9_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD8:
						formKeyboard_cmd8_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD7:
						formKeyboard_cmd7_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD6:
						formKeyboard_cmd6_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD5:
						formKeyboard_cmd5_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD4:
						formKeyboard_cmd4_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD3:
						formKeyboard_cmd3_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD2:
						formKeyboard_cmd2_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMD1:
						formKeyboard_cmd1_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDSPACE:
						formKeyboard_cmdSpace_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDSTREG:
						formKeyboard_cmdStreg_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDPUNKTUM:
						formKeyboard_cmdPunktum_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDKOMMA:
						formKeyboard_cmdKomma_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDM:
						formKeyboard_cmdM_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDN:
						formKeyboard_cmdN_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDB:
						formKeyboard_cmdB_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDV:
						formKeyboard_cmdV_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDC:
						formKeyboard_cmdC_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDX:
						formKeyboard_cmdX_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDZ:
						formKeyboard_cmdZ_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDL2:
						formKeyboard_cmdL2_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDL1:
						formKeyboard_cmdL1_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDL:
						formKeyboard_cmdL_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDK:
						formKeyboard_cmdK_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDJ:
						formKeyboard_cmdJ_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDH:
						formKeyboard_cmdH_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDG:
						formKeyboard_cmdG_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDF:
						formKeyboard_cmdF_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDD:
						formKeyboard_cmdD_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDS:
						formKeyboard_cmdS_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDL3:
						formKeyboard_cmdL3_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDP:
						formKeyboard_cmdP_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDO:
						formKeyboard_cmdO_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDI:
						formKeyboard_cmdI_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDU:
						formKeyboard_cmdU_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDY:
						formKeyboard_cmdY_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDT:
						formKeyboard_cmdT_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDR:
						formKeyboard_cmdR_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDE:
						formKeyboard_cmdE_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDW:
						formKeyboard_cmdW_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDA:
						formKeyboard_cmdA_Click(hBox);
						return TRUE;
					case FORMKEYBOARD_CMDQ:
						formKeyboard_cmdQ_Click(hBox);
						return TRUE;
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
