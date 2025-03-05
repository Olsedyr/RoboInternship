//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formKeyboardUser.c
#include "Bx.h"
#include "cmd.h"
#include "formKeyboard.h"

static BX_CHAR m_string[256];
static BX_CHAR m_lstring[256];
static BX_BOOL m_shift;
static BX_INT  m_len;
static BX_BOOL m_loginMode = FALSE;

BX_BOOL formKeyboardUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
  BxSendMessage(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSHIFT), BBM_SETICON, (BX_WPARAM)BxSystemResourceLoadBxIcon(0), 0);
  BxSendMessage(BxGetDlgItem(hBox, FORMKEYBOARD_CMDBACKSPACE), BBM_SETICON, (BX_WPARAM)BxSystemResourceLoadBxIcon(1), 0);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1));
	if (m_loginMode)
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_lstring);
	else
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_string);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCANCEL),getLanguageLineFromIdx(langptr, 3, "Cancel"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDENTER));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDENTER),getLanguageLineFromIdx(langptr, 46, "Enter"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDA));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDB));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDC));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDD));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDE));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDF));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDG));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDH));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDI));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDJ));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDK));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDL));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDM));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDN));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDO));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDP));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDQ));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDR));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDS));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDT));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDU));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDV));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDW));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDX));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDY));	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDZ));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD1));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD2));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD3));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD4));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD5));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD6));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD7));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD8));			
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD9));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD0));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOLON));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDAPO));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOMMA));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDDOT));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSLASH));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDHYPHEN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDA), getLanguageLineFromIdx(langptr, 140, "a"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDB), getLanguageLineFromIdx(langptr, 142, "b"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDC), getLanguageLineFromIdx(langptr, 144, "c"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDD), getLanguageLineFromIdx(langptr, 146, "d"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDE), getLanguageLineFromIdx(langptr, 148, "e"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDF), getLanguageLineFromIdx(langptr, 150, "f"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDG), getLanguageLineFromIdx(langptr, 152, "g"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDH), getLanguageLineFromIdx(langptr, 154, "h"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDI), getLanguageLineFromIdx(langptr, 156, "i"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDJ), getLanguageLineFromIdx(langptr, 158, "j"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDK), getLanguageLineFromIdx(langptr, 160, "k"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDL), getLanguageLineFromIdx(langptr, 162, "l"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDM), getLanguageLineFromIdx(langptr, 164, "m"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDN), getLanguageLineFromIdx(langptr, 166, "n"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDO), getLanguageLineFromIdx(langptr, 168, "o"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDP), getLanguageLineFromIdx(langptr, 170, "p"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDQ), getLanguageLineFromIdx(langptr, 172, "q"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDR), getLanguageLineFromIdx(langptr, 174, "r"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDS), getLanguageLineFromIdx(langptr, 176, "s"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDT), getLanguageLineFromIdx(langptr, 178, "t"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDU), getLanguageLineFromIdx(langptr, 180, "u"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDV), getLanguageLineFromIdx(langptr, 182, "v"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDW), getLanguageLineFromIdx(langptr, 184, "w"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDX), getLanguageLineFromIdx(langptr, 186, "x"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDY), getLanguageLineFromIdx(langptr, 188, "y"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDZ), getLanguageLineFromIdx(langptr, 190, "z"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD1), getLanguageLineFromIdx(langptr, 204, "1"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD2), getLanguageLineFromIdx(langptr, 206, "2"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD3), getLanguageLineFromIdx(langptr, 208, "3"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD4), getLanguageLineFromIdx(langptr, 210, "4"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD5), getLanguageLineFromIdx(langptr, 212, "5"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD6), getLanguageLineFromIdx(langptr, 214, "6"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD7), getLanguageLineFromIdx(langptr, 216, "7"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD8), getLanguageLineFromIdx(langptr, 218, "8"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD9), getLanguageLineFromIdx(langptr, 220, "9"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD0), getLanguageLineFromIdx(langptr, 222, "0"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOLON), getLanguageLineFromIdx(langptr, 192, ";"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDAPO), getLanguageLineFromIdx(langptr, 194, "'"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSLASH), getLanguageLineFromIdx(langptr, 196, "/"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOMMA), getLanguageLineFromIdx(langptr, 198, ","));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDDOT), getLanguageLineFromIdx(langptr, 200, "."));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDHYPHEN), getLanguageLineFromIdx(langptr, 202, "-"));
	return TRUE;
}

BX_BOOL IsUTF8_TwoByte(char *s)
{
	if ((0xFF&(s[0]>>7))!=0x00)
		return TRUE;
	return FALSE;
}

BX_BOOL Utf8Length(char *s)
{
	char *ps=s;
	int len=0;
	int utf8=0;
	while (*ps!='\0')
	{
		utf8=IsUTF8_TwoByte(ps);
		len++;
		if (utf8)
		{
			ps++;
		}
		ps++;
	}
	return len;
}

BX_BOOL AddCharToTextField(HBOX hBox,char *c)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	if(Utf8Length(m_string)>=m_len)
  {
		char str[256];
		sprintf(str,"%s %d",getLanguageLineFromIdx(langptr, 224,"String max. length is"),m_len);
    BxMsgBox(hBox,str, getLanguageLineFromIdx(langptr,134,"Error"), 0, getLanguageLineFromIdx(langptr, 74,"Ok"), getLanguageLineFromIdx(langptr, 3,"Cancel"));
		return FALSE;
  }
	sprintf(m_string, "%s%s", m_string, c);
	if(m_loginMode)
	{
	  sprintf(m_lstring, "%s*", m_lstring);
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_lstring);
	}
	else
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_string);
  return TRUE;
}

BX_BOOL formKeyboardUserUpdate(HBOX hBox)
{
 return TRUE;
}

BX_BOOL formKeyboard_cmdW_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDW)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdE_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDE)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdR_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDR)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdT_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDT)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdY_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDY)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdU_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDU)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdP_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDP)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdO_Click(HBOX hBox)
{
AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDO)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdI_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDI)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdColon_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOLON)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdQ_Click(HBOX hBox)
{
AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDQ)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdS_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDS)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdD_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDD)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdF_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDF)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdG_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDG)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdH_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDH)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdJ_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDJ)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdK_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDK)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdL_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDL)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdApo_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDAPO)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdSlash_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSLASH)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdA_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDA)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdZ_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDZ)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdX_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDX)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdC_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDC)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdV_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDV)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdB_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDB)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdN_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDN)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdM_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDM)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdComma_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOMMA)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdDot_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDDOT)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdEnter_Click(HBOX hBox)
{
	BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formKeyboard_cmdHyphen_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDHYPHEN)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd9_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD9)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd8_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD8)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd7_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD7)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd6_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD6)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd5_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD5)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd4_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD4)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd3_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD3)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd2_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD2)));
  return TRUE;
}

BX_BOOL formKeyboard_cmd1_Click(HBOX hBox)
{
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD1)));
  return TRUE;
}

BX_BOOL formKeyboard_cmdSpacebar_Click(HBOX hBox)
{
	AddCharToTextField(hBox," ");
  return TRUE;
}

BX_BOOL formKeyboard_cmdCancel_Click(HBOX hBox)
{
	BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formKeyboard_cmdShift_Click(HBOX hBox)
{	
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	if(m_shift)
	{
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDA), getLanguageLineFromIdx(langptr, 140, "a"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDB), getLanguageLineFromIdx(langptr, 142, "b"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDC), getLanguageLineFromIdx(langptr, 144, "c"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDD), getLanguageLineFromIdx(langptr, 146, "d"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDE), getLanguageLineFromIdx(langptr, 148, "e"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDF), getLanguageLineFromIdx(langptr, 150, "f"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDG), getLanguageLineFromIdx(langptr, 152, "g"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDH), getLanguageLineFromIdx(langptr, 154, "h"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDI), getLanguageLineFromIdx(langptr, 156, "i"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDJ), getLanguageLineFromIdx(langptr, 158, "j"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDK), getLanguageLineFromIdx(langptr, 160, "k"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDL), getLanguageLineFromIdx(langptr, 162, "l"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDM), getLanguageLineFromIdx(langptr, 164, "m"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDN), getLanguageLineFromIdx(langptr, 166, "n"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDO), getLanguageLineFromIdx(langptr, 168, "o"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDP), getLanguageLineFromIdx(langptr, 170, "p"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDQ), getLanguageLineFromIdx(langptr, 172, "q"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDR), getLanguageLineFromIdx(langptr, 174, "r"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDS), getLanguageLineFromIdx(langptr, 176, "s"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDT), getLanguageLineFromIdx(langptr, 178, "t"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDU), getLanguageLineFromIdx(langptr, 180, "u"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDV), getLanguageLineFromIdx(langptr, 182, "v"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDW), getLanguageLineFromIdx(langptr, 184, "w"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDX), getLanguageLineFromIdx(langptr, 186, "x"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDY), getLanguageLineFromIdx(langptr, 188, "y"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDZ), getLanguageLineFromIdx(langptr, 190, "z"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD1), getLanguageLineFromIdx(langptr, 204, "1"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD2), getLanguageLineFromIdx(langptr, 206, "2"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD3), getLanguageLineFromIdx(langptr, 208, "3"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD4), getLanguageLineFromIdx(langptr, 210, "4"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD5), getLanguageLineFromIdx(langptr, 212, "5"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD6), getLanguageLineFromIdx(langptr, 214, "6"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD7), getLanguageLineFromIdx(langptr, 216, "7"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD8), getLanguageLineFromIdx(langptr, 218, "8"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD9), getLanguageLineFromIdx(langptr, 220, "9"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD0), getLanguageLineFromIdx(langptr, 222, "0"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOLON), getLanguageLineFromIdx(langptr, 192, ";"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDAPO), getLanguageLineFromIdx(langptr, 194, "'"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSLASH), getLanguageLineFromIdx(langptr, 196, "/"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOMMA), getLanguageLineFromIdx(langptr, 198, ","));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDDOT), getLanguageLineFromIdx(langptr, 200, "."));
	BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDHYPHEN), getLanguageLineFromIdx(langptr, 202, "-"));
		m_shift = FALSE;
	}
	else
	{
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDA), getLanguageLineFromIdx(langptr, 141, "A"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDB), getLanguageLineFromIdx(langptr, 143, "B"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDC), getLanguageLineFromIdx(langptr, 145, "C"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDD), getLanguageLineFromIdx(langptr, 147, "D"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDE), getLanguageLineFromIdx(langptr, 149, "E"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDF), getLanguageLineFromIdx(langptr, 151, "F"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDG), getLanguageLineFromIdx(langptr, 153, "G"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDH), getLanguageLineFromIdx(langptr, 155, "H"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDI), getLanguageLineFromIdx(langptr, 157, "I"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDJ), getLanguageLineFromIdx(langptr, 159, "J"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDK), getLanguageLineFromIdx(langptr, 161, "K"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDL), getLanguageLineFromIdx(langptr, 163, "L"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDM), getLanguageLineFromIdx(langptr, 165, "M"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDN), getLanguageLineFromIdx(langptr, 167, "N"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDO), getLanguageLineFromIdx(langptr, 169, "O"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDP), getLanguageLineFromIdx(langptr, 171, "P"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDQ), getLanguageLineFromIdx(langptr, 173, "Q"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDR), getLanguageLineFromIdx(langptr, 175, "R"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDS), getLanguageLineFromIdx(langptr, 177, "S"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDT), getLanguageLineFromIdx(langptr, 179, "T"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDU), getLanguageLineFromIdx(langptr, 181, "U"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDV), getLanguageLineFromIdx(langptr, 183, "V"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDW), getLanguageLineFromIdx(langptr, 185, "W"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDX), getLanguageLineFromIdx(langptr, 187, "X"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDY), getLanguageLineFromIdx(langptr, 189, "Y"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDZ), getLanguageLineFromIdx(langptr, 191, "Z"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD1), getLanguageLineFromIdx(langptr, 205, "!"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD2), getLanguageLineFromIdx(langptr, 207, "@"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD3), getLanguageLineFromIdx(langptr, 209, "#"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD4), getLanguageLineFromIdx(langptr, 211, "$"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD5), getLanguageLineFromIdx(langptr, 213, "%"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD6), getLanguageLineFromIdx(langptr, 215, "^"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD7), getLanguageLineFromIdx(langptr, 217, "&"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD8), getLanguageLineFromIdx(langptr, 219, "*"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD9), getLanguageLineFromIdx(langptr, 221, "("));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD0), getLanguageLineFromIdx(langptr, 223, ")"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOLON), getLanguageLineFromIdx(langptr, 193, ":"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDAPO), getLanguageLineFromIdx(langptr, 195, "="));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDSLASH), getLanguageLineFromIdx(langptr, 197, "?"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDCOMMA), getLanguageLineFromIdx(langptr, 199, "<"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDDOT), getLanguageLineFromIdx(langptr, 201, ">"));
		BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMDHYPHEN), getLanguageLineFromIdx(langptr, 203, "_"));
		m_shift = TRUE;
	}
  return TRUE;
}

BX_BOOL formKeyboard_cmdBackSpace_Click(HBOX hBox)
{
	int doublechar=0;
	int curlen = BxStringLength(m_string);
	if (curlen>0)
	{
		doublechar=0;
		if (curlen>1)
		{
			if (IsUTF8_TwoByte(&m_string[curlen-1]))
				doublechar=1;
		}
		m_string[curlen-1-doublechar]='\0';
		if(m_loginMode)
		{
			int curlenl = BxStringLength(m_lstring);
			if (curlenl>0) 
				m_lstring[curlenl-1]='\0';
			BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_lstring);
		}
		else
			BxSetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_TEXTLABEL1), m_string);
	}
  return TRUE;
}

BX_BOOL formKeyboard_cmd0_Click(HBOX hBox)
{	
	AddCharToTextField(hBox,BxGetStringValue(BxGetDlgItem(hBox, FORMKEYBOARD_CMD0)));
  return TRUE;
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

  if (len>0&&len<=255)
		m_len = len;
	else
		m_len=255;
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
    formKeyboard[17].style |= BSS_CENTER;
  }
  else
  {
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
