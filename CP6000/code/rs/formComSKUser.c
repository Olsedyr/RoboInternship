//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formComSKUser.c
#include "Bx.h"
#include "formComSK.h"

#include "cmd.h"

extern volatile int dioIndex;
extern volatile int modIndex;

BX_BOOL formComSKUserInit(HBOX hBox,BX_LPARAM lParam)
{
  int i;
  comskstruct *comsk;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCOMSK_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCOMSK_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_2_2), getLanguageLineFromIdx(langptr, 101, "Init. data:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_2), getLanguageLineFromIdx(langptr, 102, "In data:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_3));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME_3), getLanguageLineFromIdx(langptr, 103, "Out data:"));
  comsk = &tworkcell->comsks.comsk[dioIndex].iotab[modIndex];
  
  BxAssignStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME));
  BxSetStringValue(BxGetDlgItem(hBox, FORMCOMSK_LABMODNAME), comsk->module_name);
  
  for(i=0; i<comsk->numOfInitWords; i++){
    char s[256*2];
    sprintf(s,"%s %0.4f", comsk->initdata[i].key, comsk->initdata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXINIT), s);	
	}
  for(i=0; i<comsk->numOfInWords; i++){
    char s[256*2];
    sprintf(s,"%s %0.4f", comsk->idata[i].key, comsk->idata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXIN), s);  
  }
  for(i=0; i<comsk->numOfOutWords; i++){
    char s[256*2];
    sprintf(s,"%s %0.4f", comsk->odata[i].key, comsk->odata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXOUT), s);  
  }
  return TRUE;
}

BX_BOOL formComSKUserUpdate(HBOX hBox)
{
  int i;
  comskstruct *comsk;
  comsk = &tworkcell->comsks.comsk[dioIndex].iotab[modIndex];
  
  for(i=0; i<comsk->numOfInWords; i++){
    if(i < BxList_GetCount(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXIN))){
      char s[256*2];
      sprintf(s,"%s %0.4f", comsk->idata[i].key, comsk->idata[i].fdata);
      BxList_SetString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXIN), i, s);
    }
  }
	BxList_Update(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXIN));
	return TRUE;
}

BX_BOOL formComSK_listBoxInit_Click(HBOX hBox)
{
  comskstruct *comsk;
  comsk = &tworkcell->comsks.comsk[dioIndex].iotab[modIndex];
  int sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXINIT));
  
  if(sel < comsk->numOfInitWords){
    BxVirtNumBox_SetFloatValue(comsk->initdata[sel].fdata);
    if(VirtNumKeyBox( hBox ) == IDOK)
    {
      char s[256*2];
      comsk->initdata[sel].fdata = BxVirtNumBox_GetFloatValue();
      sprintf(s,"%s %0.4f", comsk->initdata[sel].key, comsk->initdata[sel].fdata);
      BxList_SetString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXINIT), sel, s);
			BxList_Update(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXINIT));
    }
  }
  return TRUE;
}

BX_BOOL formComSK_listBoxIn_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formComSK_listBoxOut_Click(HBOX hBox)
{
  comskstruct *comsk;
  comsk = &tworkcell->comsks.comsk[dioIndex].iotab[modIndex];
  int sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXOUT));
  
  if(sel < comsk->numOfOutWords){
    BxVirtNumBox_SetFloatValue(comsk->odata[sel].fdata);
    if(VirtNumKeyBox( hBox ) == IDOK)
    {
      char s[256*2];
      comsk->odata[sel].fdata = BxVirtNumBox_GetFloatValue();
      sprintf(s,"%s %0.4f", comsk->odata[sel].key, comsk->odata[sel].fdata);
      BxList_SetString(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXOUT), sel, s);
			BxList_Update(BxGetDlgItem(hBox, FORMCOMSK_LISTBOXOUT));
    }
  }
  return TRUE;
}

BX_BOOL formComSK_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}

