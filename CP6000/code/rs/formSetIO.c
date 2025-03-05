//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formSetIO.c
#include "Bx.h"
#include "formSetIO.h"

BOXSTRUCT formSetIO[] = {
 {10000,{0,0,799,599},DIALOG,"",BXS_VISIBLE,&formSetIO[1], NULL}
 ,{FORMSETIO_TEXTLABEL2_2,{10,10,259,44},STATIC,"roboStacker RS2000",BXS_VISIBLE,&formSetIO[2], &formSetIO[0]}
 ,{FORMSETIO_CMDRETURN,{650,480,779,579},BUTTON,"Ok",BBS_PUSHBUTTON|BXS_VISIBLE,&formSetIO[3], &formSetIO[0]}
 ,{FORMSETIO_CHECK_9,{390,70,729,119},BUTTON,"9",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[4], &formSetIO[0]}
 ,{FORMSETIO_CHECK_10,{390,130,729,179},BUTTON,"10",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[5], &formSetIO[0]}
 ,{FORMSETIO_CHECK_11,{390,190,729,239},BUTTON,"11",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[6], &formSetIO[0]}
 ,{FORMSETIO_CHECK_12,{390,250,729,299},BUTTON,"12",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[7], &formSetIO[0]}
 ,{FORMSETIO_CHECK_13,{390,310,729,359},BUTTON,"13",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[8], &formSetIO[0]}
 ,{FORMSETIO_CHECK_14,{390,370,729,419},BUTTON,"14",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[9], &formSetIO[0]}
 ,{FORMSETIO_CHECK_15,{390,430,629,479},BUTTON,"15",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[10], &formSetIO[0]}
 ,{FORMSETIO_CHECK_16,{390,490,629,539},BUTTON,"16",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[11], &formSetIO[0]}
 ,{FORMSETIO_CHECK_8,{30,490,349,539},BUTTON,"8",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[12], &formSetIO[0]}
 ,{FORMSETIO_CHECK_7,{30,430,349,479},BUTTON,"7",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[13], &formSetIO[0]}
 ,{FORMSETIO_CHECK_6,{30,370,349,419},BUTTON,"6",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[14], &formSetIO[0]}
 ,{FORMSETIO_CHECK_5,{30,310,349,359},BUTTON,"5",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[15], &formSetIO[0]}
 ,{FORMSETIO_CHECK_4,{30,250,349,299},BUTTON,"4",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[16], &formSetIO[0]}
 ,{FORMSETIO_CHECK_3,{30,190,349,239},BUTTON,"3",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[17], &formSetIO[0]}
 ,{FORMSETIO_CHECK_2,{30,130,349,179},BUTTON,"2",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[18], &formSetIO[0]}
 ,{FORMSETIO_CHECK_1,{30,70,349,119},BUTTON,"1",BBS_CHECKBOX|BXS_VISIBLE,&formSetIO[19], &formSetIO[0]}
 ,{BXID_STATIC,{0,0,0,0},STATIC,"",0,NULL, &formSetIO[0]}
};

BX_BOOL formSetIOProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
 switch(uMsg)
	{
		case BM_UPDATE:
			{
				formSetIOUpdate(hBox);
				return formSetIOUserUpdate(hBox);
				break;
			}
		case BM_INITDIALOG:
			{
				formSetIOInit(hBox);
				return formSetIOUserInit(hBox,lParam);
				break;
			}
		case BM_COMMAND:
			{
				switch(BX_LOWORD(wParam))
				{
         case FORMSETIO_CMDRETURN:
             return formSetIO_cmdReturn_Click(hBox);
         case FORMSETIO_CHECK_9:
             return formSetIO_check_9_Click(hBox);
         case FORMSETIO_CHECK_10:
             return formSetIO_check_10_Click(hBox);
         case FORMSETIO_CHECK_11:
             return formSetIO_check_11_Click(hBox);
         case FORMSETIO_CHECK_12:
             return formSetIO_check_12_Click(hBox);
         case FORMSETIO_CHECK_13:
             return formSetIO_check_13_Click(hBox);
         case FORMSETIO_CHECK_14:
             return formSetIO_check_14_Click(hBox);
         case FORMSETIO_CHECK_15:
             return formSetIO_check_15_Click(hBox);
         case FORMSETIO_CHECK_16:
             return formSetIO_check_16_Click(hBox);
         case FORMSETIO_CHECK_8:
             return formSetIO_check_8_Click(hBox);
         case FORMSETIO_CHECK_7:
             return formSetIO_check_7_Click(hBox);
         case FORMSETIO_CHECK_6:
             return formSetIO_check_6_Click(hBox);
         case FORMSETIO_CHECK_5:
             return formSetIO_check_5_Click(hBox);
         case FORMSETIO_CHECK_4:
             return formSetIO_check_4_Click(hBox);
         case FORMSETIO_CHECK_3:
             return formSetIO_check_3_Click(hBox);
         case FORMSETIO_CHECK_2:
             return formSetIO_check_2_Click(hBox);
         case FORMSETIO_CHECK_1:
             return formSetIO_check_1_Click(hBox);
				}
				break;
			}
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return 0L;
}
