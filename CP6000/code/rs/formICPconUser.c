//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formICPconUser.c
#include "Bx.h"
#include "cmd.h"
#include "formICPcon.h"

extern volatile int dioIndex;
extern volatile int modIndex;

BX_BOOL formICPconUserInit(HBOX hBox,BX_LPARAM lParam)
{
  int i;
  icpconstruct *icpcon;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMICPCON_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMICPCON_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME_2), getLanguageLineFromIdx(langptr, 102, "In data:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME_3));
	BxSetStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME_3), getLanguageLineFromIdx(langptr, 103, "Out data:"));
  icpcon = &tworkcell->icpcons.icpcon[dioIndex].iotab[modIndex];
  
  BxAssignStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME));
  BxSetStringValue(BxGetDlgItem(hBox, FORMICPCON_LABMODNAME), icpcon->module_name);
	for(i=0; i<icpcon->numOfInBits; i++)
	{
    char s[256*2];
		sprintf(s,"%s %d", icpcon->inconnect[i].key, 1&(icpcon->idata>>icpcon->inconnect[i].bitpos));
		BxList_AddString(BxGetDlgItem(hBox, FORMICPCON_LISTBOXIN), s);
	}
  for(i=0; i<icpcon->numOfOutBits; i++)
	{
    char s[256*2];
		sprintf(s,"%s %d", icpcon->outconnect[i].key, 1&(icpcon->odata>>icpcon->outconnect[i].bitpos));
		BxList_AddString(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT), s);
	}
  return TRUE;
			}

BX_BOOL formICPconUserUpdate(HBOX hBox)
{
  int i;
  icpconstruct *icpcon;
  icpcon = &tworkcell->icpcons.icpcon[dioIndex].iotab[modIndex];
  
  for(i=0; i<icpcon->numOfInBits; i++){
    if(i < BxList_GetCount(BxGetDlgItem(hBox, FORMICPCON_LISTBOXIN)))
		{
      char s[256*2];
			sprintf(s,"%s %d", icpcon->inconnect[i].key, 1&(icpcon->idata>>icpcon->inconnect[i].bitpos));
			BxList_SetString(BxGetDlgItem(hBox, FORMICPCON_LISTBOXIN), i, s);
    }
  }
  for(i=0; i<icpcon->numOfOutBits; i++){
    if(i < BxList_GetCount(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT)))
		{
      char s[256*2];
			sprintf(s,"%s %d", icpcon->outconnect[i].key, 1&(icpcon->odata>>icpcon->outconnect[i].bitpos));
			BxList_SetString(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT), i, s);
    }
  }
	BxList_Update(BxGetDlgItem(hBox, FORMICPCON_LISTBOXIN));
	BxList_Update(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT));
  return TRUE;
}

BX_BOOL formICPcon_listBoxIn_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formICPcon_listBoxOut_Click(HBOX hBox)
{
  icpconstruct *icpcon;
  icpcon = &tworkcell->icpcons.icpcon[dioIndex].iotab[modIndex];
  int sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT));
  
  if(sel < icpcon->numOfOutBits)
	{
		BxVirtNumBox_SetLimits(0, 1);
		BxVirtNumBox_SetValue(1&(icpcon->odata>>icpcon->outconnect[sel].bitpos));
		if(VirtNumKeyBox( hBox ) == IDOK)
		{
			char s[256*2];
			icpcon->odata&=~(1<<icpcon->outconnect[sel].bitpos);
			icpcon->odata|=BxVirtNumBox_GetValue()<<icpcon->outconnect[sel].bitpos;
			sprintf(s,"%s %d", icpcon->outconnect[sel].key, 1&(icpcon->odata>>icpcon->outconnect[sel].bitpos));
			BxList_SetString(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT), sel, s);
			BxList_Update(BxGetDlgItem(hBox, FORMICPCON_LISTBOXOUT));
		}
  }
  return TRUE;
}

BX_BOOL formICPcon_cmdClose_Click(HBOX hBox)
{  
	BxEndDialog(hBox, 0);
  return TRUE;
}
