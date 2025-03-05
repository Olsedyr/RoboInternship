//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formLoadCellUser.c
#include "Bx.h"
#include "formLoadCell.h"

#include "cmd.h"

extern volatile int dioIndex;
extern volatile int modIndex;
static char namestr[256]="Name :";

BX_BOOL formLoadCellUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
  tmpnLoadCell *lc;

  lc=(tmpnLoadCell *)&tworkcell->loadcells.loadcell[modIndex];

  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABTYPE));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABMODNAME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD1));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD2));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD3));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD4));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD5));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD6));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD7));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD8));

  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD1));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD2));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD3));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD4));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD5));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD6));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD7));
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD8));
	sprintf(namestr,"%s :",getLanguageLineFromIdx(langptr, 87, "Name"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_TEXTLABEL2_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_TEXTLABEL2_2_2), namestr);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMLOADCELL_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABTYPE),  getLanguageLineFromIdx(langptr, 100, "Loadcell module"));
	BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABMODNAME),  lc->ipaddr);


  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD1), lc->iotab[0].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD2), lc->iotab[1].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD3), lc->iotab[2].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD4), lc->iotab[3].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD5), lc->iotab[4].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD6), lc->iotab[5].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD7), lc->iotab[6].key);
  BxSetStringValue(BxGetDlgItem(hBox, FORMLOADCELL_LABIWORD8), lc->iotab[7].key);

  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD1),lc->iotab[0].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD2),lc->iotab[1].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD3),lc->iotab[2].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD4),lc->iotab[3].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD5),lc->iotab[4].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD6),lc->iotab[5].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD7),lc->iotab[6].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD8),lc->iotab[7].fdata);

  return TRUE;
}

BX_BOOL formLoadCellUserUpdate(HBOX hBox)
{  
  tmpnLoadCell *lc;
  lc=(tmpnLoadCell *)&tworkcell->loadcells.loadcell[modIndex];

  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD1),lc->iotab[0].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD2),lc->iotab[1].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD3),lc->iotab[2].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD4),lc->iotab[3].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD5),lc->iotab[4].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD6),lc->iotab[5].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD7),lc->iotab[6].fdata);
  BxSetFloatValue(BxGetDlgItem(hBox, FORMLOADCELL_IWORD8),lc->iotab[7].fdata);
  
  return TRUE;
}

BX_BOOL formLoadCell_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}
