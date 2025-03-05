//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formPedalBox.c
#include "Bx.h"
#include "formPedalBox.h"

BOXSTRUCT formPedalBox[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formPedalBox[1], NULL}
 ,{FORMPEDALBOX_CMDSPEED,{10,490,139,579},BUTTON,"Speed",BBS_PUSHBUTTON|BXS_VISIBLE,&formPedalBox[2], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2050",BXS_VISIBLE,&formPedalBox[3], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL2_2_2,{10,450,139,479},STATIC,"Hastighed",BSS_CENTER|BXS_VISIBLE,&formPedalBox[4], &formPedalBox[0]}
 ,{FORMPEDALBOX_GROUPBOX1,{21,61,390,430},STATIC,"Palle A",BSS_WHITEFRAME|BXS_VISIBLE,&formPedalBox[5], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA5,{101,221,150,250},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[6], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA4,{101,261,150,290},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[7], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA1,{101,381,150,410},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[8], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA2,{101,341,150,370},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[9], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA6,{101,181,150,210},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[10], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA8,{101,101,150,130},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[11], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA3,{101,301,150,330},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[12], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERA7,{101,141,150,170},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[13], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_5,{50,220,79,254},STATIC,"5",BXS_VISIBLE,&formPedalBox[14], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL,{50,380,79,414},STATIC,"1",BXS_VISIBLE,&formPedalBox[15], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_8,{50,100,79,134},STATIC,"8",BXS_VISIBLE,&formPedalBox[16], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_3,{50,300,79,334},STATIC,"3",BXS_VISIBLE,&formPedalBox[17], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_2,{50,340,79,374},STATIC,"2",BXS_VISIBLE,&formPedalBox[18], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_7,{50,140,79,174},STATIC,"7",BXS_VISIBLE,&formPedalBox[19], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_4,{50,260,79,294},STATIC,"4",BXS_VISIBLE,&formPedalBox[20], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_6,{50,180,79,214},STATIC,"6",BXS_VISIBLE,&formPedalBox[21], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXA1,{191,151,270,250},BUTTON,"Kasse 2",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[22], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXA3,{281,151,360,250},BUTTON,"Kasse 4",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[23], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXA0,{191,261,270,360},BUTTON,"Kasse 1",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[24], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXA2,{281,261,360,360},BUTTON,"Kasse 3",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[25], &formPedalBox[0]}
 ,{FORMPEDALBOX_GROUPBOX2,{420,60,779,429},STATIC,"Palle C",BSS_WHITEFRAME|BXS_VISIBLE,&formPedalBox[26], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC3,{660,300,709,329},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[27], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC8,{660,100,709,129},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[28], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC6,{660,180,709,209},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[29], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC2,{660,340,709,369},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[30], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC5,{660,220,709,249},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[31], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC4,{660,260,709,289},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[32], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC1,{660,380,709,409},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[33], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDLAYERC7,{660,140,709,169},BUTTON,"",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[34], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_4_2,{740,260,769,294},STATIC,"4",BXS_VISIBLE,&formPedalBox[35], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_3_2,{740,300,769,334},STATIC,"3",BXS_VISIBLE,&formPedalBox[36], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_7_2,{740,140,769,174},STATIC,"7",BXS_VISIBLE,&formPedalBox[37], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_8_2,{740,100,769,134},STATIC,"8",BXS_VISIBLE,&formPedalBox[38], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_9,{740,380,769,414},STATIC,"1",BXS_VISIBLE,&formPedalBox[39], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_2_2,{740,340,769,374},STATIC,"2",BXS_VISIBLE,&formPedalBox[40], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_5_2,{740,220,769,254},STATIC,"5",BXS_VISIBLE,&formPedalBox[41], &formPedalBox[0]}
 ,{FORMPEDALBOX_TEXTLABEL_6_2,{740,180,769,214},STATIC,"6",BXS_VISIBLE,&formPedalBox[42], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXC3,{450,150,529,249},BUTTON,"Kasse 4",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[43], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXC1,{540,150,619,249},BUTTON,"Kasse 2",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[44], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXC0,{540,260,619,359},BUTTON,"Kasse 1",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[45], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDBOXC2,{450,260,529,359},BUTTON,"Kasse 3",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[46], &formPedalBox[0]}
 ,{FORMPEDALBOX_LABPROGRESS_2,{580,461,629,580},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formPedalBox[47], &formPedalBox[0]}
 ,{FORMPEDALBOX_LABPROGRESS,{520,461,569,580},STATIC,"",BXS_BORDER|BXS_VISIBLE,&formPedalBox[48], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDMENU,{660,490,789,579},BUTTON,"Menu",BBS_PUSHBUTTON|BXS_VISIBLE,&formPedalBox[49], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDRUN,{180,490,310,580},BUTTON,"Start",BBS_CHECKBOX|BXS_VISIBLE,&formPedalBox[50], &formPedalBox[0]}
 ,{FORMPEDALBOX_CMDSET,{350,490,479,579},BUTTON,"Fra",BBS_PUSHBUTTON|BXS_VISIBLE,&formPedalBox[51], &formPedalBox[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formPedalBox[0]}
};

BX_BOOL formPedalBoxProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formPedalBoxUpdate(hBox);
				return formPedalBoxUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formPedalBoxInit(hBox);
				return formPedalBoxUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMPEDALBOX_CMDSPEED:
             return formPedalBox_cmdSpeed_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA5:
             return formPedalBox_cmdLayerA5_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA4:
             return formPedalBox_cmdLayerA4_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA1:
             return formPedalBox_cmdLayerA1_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA2:
             return formPedalBox_cmdLayerA2_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA6:
             return formPedalBox_cmdLayerA6_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA8:
             return formPedalBox_cmdLayerA8_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA3:
             return formPedalBox_cmdLayerA3_Click(hBox);
         case FORMPEDALBOX_CMDLAYERA7:
             return formPedalBox_cmdLayerA7_Click(hBox);
         case FORMPEDALBOX_CMDBOXA1:
             return formPedalBox_cmdBoxA1_Click(hBox);
         case FORMPEDALBOX_CMDBOXA3:
             return formPedalBox_cmdBoxA3_Click(hBox);
         case FORMPEDALBOX_CMDBOXA0:
             return formPedalBox_cmdBoxA0_Click(hBox);
         case FORMPEDALBOX_CMDBOXA2:
             return formPedalBox_cmdBoxA2_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC3:
             return formPedalBox_cmdLayerC3_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC8:
             return formPedalBox_cmdLayerC8_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC6:
             return formPedalBox_cmdLayerC6_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC2:
             return formPedalBox_cmdLayerC2_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC5:
             return formPedalBox_cmdLayerC5_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC4:
             return formPedalBox_cmdLayerC4_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC1:
             return formPedalBox_cmdLayerC1_Click(hBox);
         case FORMPEDALBOX_CMDLAYERC7:
             return formPedalBox_cmdLayerC7_Click(hBox);
         case FORMPEDALBOX_CMDBOXC3:
             return formPedalBox_cmdBoxC3_Click(hBox);
         case FORMPEDALBOX_CMDBOXC1:
             return formPedalBox_cmdBoxC1_Click(hBox);
         case FORMPEDALBOX_CMDBOXC0:
             return formPedalBox_cmdBoxC0_Click(hBox);
         case FORMPEDALBOX_CMDBOXC2:
             return formPedalBox_cmdBoxC2_Click(hBox);
         case FORMPEDALBOX_CMDMENU:
             return formPedalBox_cmdMenu_Click(hBox);
         case FORMPEDALBOX_CMDRUN:
             return formPedalBox_cmdRun_Click(hBox);
         case FORMPEDALBOX_CMDSET:
             return formPedalBox_cmdSet_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
