//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formLanguageUser.c
#include "Bx.h"
#include "robostackerBxr.h"
#include "formLanguage.h"

#include "cmd.h"

static int curlangtemp=0;

static BX_PBITMAP denmark=NULL,uk=NULL,germany=NULL,spain=NULL,russia=NULL,poland=NULL;

static void SetIcon(HBOX hBox,char *langname)
{
	if (!strcmp(langname,"Dansk")||!strcmp(langname,"Danish"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)denmark, 0);
	}
	else if (!strcmp(langname,"English"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)uk, 0);
	}
	else if (!strcmp(langname,"Deutsch")||!strcmp(langname,"German"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)germany, 0);
	}
	else if (!strcmp(langname,"Español")||!strcmp(langname,"Castellano")||!strcmp(langname,"Spanish"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)spain, 0);
	}
	else if (!strcmp(langname,"Russian")||!strcmp(langname,"Russkiy_yazyk")||!strcmp(langname,"Русский"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)russia, 0);
	}
  else if (!strcmp(langname,"Polski")||!strcmp(langname,"Polish"))
	{
		BxSendMessage(hBox, BBM_SETIMAGE, (BX_WPARAM)poland, 0);
	}
}

BX_BOOL formLanguageUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	if (denmark==NULL)
		denmark=BxLoadImage("data/denmark.png");
	if (uk==NULL)
		uk=BxLoadImage("data/uk.png");
	if (germany==NULL)
		germany=BxLoadImage("data/germany.png");
	if (spain==NULL)
		spain=BxLoadImage("data/spain.png");
	if (russia==NULL)
		russia=BxLoadImage("data/russia.png");
  if (poland==NULL)
		poland=BxLoadImage("data/poland.png");
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDOK));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDOK), getLanguageLineFromIdx(langptr, 74, "Ok"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDCANCEL), getLanguageLineFromIdx(langptr, 3, "Cancel"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_TEXTLABEL2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_TEXTLABEL2_2), getLanguageLineFromIdx(langptr, 249, "Language settings"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1), "");
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2), "");
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3), "");
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4), "");
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5), "");
	BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6), "");
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5), FALSE);
	BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6), FALSE);
	if (tworkcell->languages.numoflanguages>0)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1), (char *)tworkcell->languages.language[0].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_1),(char *)tworkcell->languages.language[0].name);
	}
	if (tworkcell->languages.numoflanguages>1)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2), (char *)tworkcell->languages.language[1].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_2),(char *)tworkcell->languages.language[1].name);
	}
	if (tworkcell->languages.numoflanguages>2)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3), (char *)tworkcell->languages.language[2].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_3),(char *)tworkcell->languages.language[2].name);
	}
	if (tworkcell->languages.numoflanguages>3)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4), (char *)tworkcell->languages.language[3].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_4),(char *)tworkcell->languages.language[3].name);
	}
	if (tworkcell->languages.numoflanguages>4)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5), (char *)tworkcell->languages.language[4].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_5),(char *)tworkcell->languages.language[4].name);
	}
	if (tworkcell->languages.numoflanguages>5)
	{
		BxEnableBox(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6), TRUE);
		BxAssignStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6));
		BxSetStringValue(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6), (char *)tworkcell->languages.language[5].name);
		SetIcon(BxGetDlgItem(hBox, FORMLANGUAGE_CMDLANG1_6),(char *)tworkcell->languages.language[5].name);
	}
	return TRUE;
}

BX_BOOL formLanguageUserUpdate(HBOX hBox)
{
	return TRUE;
}

BX_BOOL formLanguage_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formLanguage_cmdOk_Click(HBOX hBox)
{
	int i;
	tworkcell->languages.currentLanguage=curlangtemp;
	for (i=0;i<tworkcell->statetekstlist.numofStateTeksts;i++)
	{
		if (!strcmp((char*)tworkcell->languages.language[curlangtemp].name,(char*)tworkcell->statetekstlist.stateteksts[i].name))
		{
			tworkcell->statetekstlist.currentStateTekst=i;
			break;
		}
	}
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_1_Click(HBOX hBox)
{
	curlangtemp=0;
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_2_Click(HBOX hBox)
{
	curlangtemp=1;
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_3_Click(HBOX hBox)
{
	curlangtemp=2;
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_4_Click(HBOX hBox)
{
	curlangtemp=3;
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_5_Click(HBOX hBox)
{
	curlangtemp=4;
  return TRUE;
}

BX_BOOL formLanguage_cmdLang1_6_Click(HBOX hBox)
{
	curlangtemp=5;
  return TRUE;
}
