#include "Bx.h"
#include "formKeyboard.h"

static BX_CHAR vStr[MAXLANGUAGE][255];
static BX_PSTRING m_string;
static BX_CHAR vlStr[MAXLANGUAGE][255];
static BX_PSTRING m_lstring;
static BX_BOOL    m_shift;
static BX_INT     m_len;
static BX_BOOL    m_loginMode = FALSE;

void formKeyboardUserUpdate(HBOX hBox)
{
}
void formKeyboardUserInit(HBOX hBox)
{
  BxSendMessage(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSHIFT), BBM_SETICON, (BX_WPARAM)BxSystemResourceLoadBxIcon(0), 0);
  BxSendMessage(BxGetDlgItem(hBox, FORMKEYBOARD_CMDBKSP), BBM_SETICON, (BX_WPARAM)BxSystemResourceLoadBxIcon(1), 0);
}
void formKeyboard_BxButton2_Click(HBOX  hBox)
{
}
void formKeyboard_cmdEnter_Click(HBOX  hBox)
{
  char str[255];
  if(BxStringLength(m_string)>m_len)
  {
    //sprintf(str,GetLabelMessageFromID(FORMLABELS_M102),m_len);
    sprintf(str,"String to long max %d",m_len);
    //BxMsgBox(hBox,str,GetLabelMessageFromID(FORMLABELS_MESSAGE),0);
    BxMsgBox(hBox,str,"Error",0,"Ok","Cancel");
  }
  else
  {
    BxEndDialog(hBox, IDOK);
  }
}

void formKeyboard_cmdShift_Click(HBOX  hBox)
{
	int i;

	if(m_shift)
	{
		for(i=0;i<29;i++)
		{
			formKeyboard[21+i].lpBoxStr[+(BX_LANGUAGE*255)] += 32;
			BxRequestPaint((HBOX)&formKeyboard[21+i]);
		}
		formKeyboard[28].lpBoxStr[0+(BX_LANGUAGE*255)] = '#';
		BxRequestPaint((HBOX)&formKeyboard[28]);
		formKeyboard[18].lpBoxStr[0+(BX_LANGUAGE*255)] -= 50;
		BxRequestPaint((HBOX)&formKeyboard[18]);
		formKeyboard[19].lpBoxStr[0+(BX_LANGUAGE*255)] -= 12;
		BxRequestPaint((HBOX)&formKeyboard[19]);
		formKeyboard[20].lpBoxStr[0+(BX_LANGUAGE*255)] -= 15;
		BxRequestPaint((HBOX)&formKeyboard[20]);
		m_shift = FALSE;
	}
	else
	{
		for(i=0;i<29;i++)
		{
			formKeyboard[21+i].lpBoxStr[0+(BX_LANGUAGE*255)] -= 32;
			BxRequestPaint((HBOX)&formKeyboard[21+i]);
		}
		formKeyboard[28].lpBoxStr[0+(BX_LANGUAGE*255)] = '/';
		BxRequestPaint((HBOX)&formKeyboard[28]);
		formKeyboard[18].lpBoxStr[0+(BX_LANGUAGE*255)] += 50;
		BxRequestPaint((HBOX)&formKeyboard[18]);

		formKeyboard[19].lpBoxStr[0+(BX_LANGUAGE*255)] += 12;
		BxRequestPaint((HBOX)&formKeyboard[19]);
		formKeyboard[20].lpBoxStr[0+(BX_LANGUAGE*255)] += 15;
		BxRequestPaint((HBOX)&formKeyboard[20]);
		m_shift = TRUE;
	}
}
void formKeyboard_cmdBkSp_Click(HBOX  hBox)
{
	char tmp[255] = "";

	if(strlen(m_string)>0)
	{
		BxStringNCopy(tmp, m_string, strlen(m_string)-1);
		sprintf(m_string,"%s", tmp);
		BxRequestPaint((HBOX)&formKeyboard[17]);
  }
  if(m_loginMode)
	{
	  if(strlen(m_lstring)>0)
  	{
		  BxStringNCopy(tmp, m_lstring, strlen(m_lstring)-1);
		  sprintf(m_lstring,"%s", tmp);
      BxRequestPaint((HBOX)&formKeyboard[17]);
		}
	}
}
void formKeyboard_cmd0_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[6].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd9_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[7].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd8_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[8].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd7_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[9].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd6_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[10].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd5_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[11].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd4_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[12].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd3_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[13].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd2_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[14].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmd1_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[15].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdSpace_Click(HBOX  hBox)
{
	sprintf(m_string, "%s ", m_string);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdStreg_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[18].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdPunktum_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[19].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdKomma_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[20].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdM_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[21].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdN_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[22].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdB_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[23].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdV_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[24].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdC_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[25].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdX_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[26].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdZ_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[27].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdL2_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[28].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdL1_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[29].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdL_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[30].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdK_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[31].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdJ_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[32].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdH_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[33].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdG_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[34].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdF_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[35].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdD_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[36].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdS_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[37].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdL3_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[38].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdP_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[39].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdO_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[40].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdI_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[41].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdU_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[42].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdY_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[43].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);

	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdT_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[44].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdR_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[45].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdE_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[46].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdW_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[47].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdA_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[48].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}
void formKeyboard_cmdQ_Click(HBOX  hBox)
{
	sprintf(m_string, "%s%s", m_string, &formKeyboard[49].lpBoxStr[BX_LANGUAGE*255]);
	if(m_loginMode)
	  sprintf(m_lstring, "%s*", m_lstring);
	BxRequestPaint((HBOX)&formKeyboard[17]);
}


BX_PSTRING BxVirtualKeyboard_GetString(BX_VOID)
{
	return m_string;
}

BX_VOID BxVirtualKeyboard_LoginMode(BX_VOID)
{
	m_loginMode = TRUE;
}

BX_INT BxVirtualKeyboard( HBOX hBox, BX_PSTRING initStr, int len)
{
  HBOX hvkeybox;
  BX_INT rtnVal;

  if(hBox == NULL)
    return -1;

  m_string = &vStr[BX_LANGUAGE][0];
  m_lstring = &vlStr[BX_LANGUAGE][0];
  
  m_len = len;
  formKeyboard[0].bParent = (PBOXSTRUCT)hBox;

  if(initStr)
  {
    strncpy(m_string, initStr, 127);
    strncpy(m_lstring, initStr, 127);
  }
  else
  {
    BxStringCopy(m_string, "");
    BxStringCopy(m_lstring, "");
  }

    
  if(m_loginMode)
  {
    formKeyboard[17].lpBoxStr = &vlStr[0][0];
    formKeyboard[17].style |= BSS_CENTER;
  }
  else
  {
    formKeyboard[17].lpBoxStr = &vStr[0][0];
    formKeyboard[17].style &= ~BSS_CENTER;
  }

  hvkeybox = BxCreateDialog(GetAppInstance(hBox), &formKeyboard[0], (BXDLGPROC)formKeyboardProc);
  if(m_shift)
    formKeyboard_cmdShift_Click(&formKeyboard[0]);
  rtnVal = DoModal(hvkeybox);

  formKeyboard[0].bParent = NULL;

  ShowDialogBox(hBox);
  BxUpdateView(hBox);

  m_loginMode = FALSE;
  return rtnVal;
}
