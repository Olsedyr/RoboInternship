//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formEditCPPatternUser.c
#include "Bx.h"
#include "formEditCPPattern.h"
#include "cmd.h"
#include "formEditPPP.h"

tmpnCPPattern *editcppattern = NULL;
int selectedLayer = 0;
BX_BOOL formEditCPPattern_UpdateEditables(HBOX hBox)
{
  char s[256];
  int i,j;
  int prodcount = 0;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

  if(selectedLayer >= editcppattern->maxidx)
    selectedLayer = editcppattern->maxidx - 1;
  
  BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDMAXLAYERS), editcppattern->maxidx);
  BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDLAYER), selectedLayer);
  BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDMAXPUSH), editcppattern->items[selectedLayer].maxpush);
  BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDGETTIME), editcppattern->items[selectedLayer].gettime);
  
  for(i=0;i<editcppattern->maxidx;i++)
    for(j=0;j<editcppattern->items[i].maxpush;j++)
    {
      prodcount += editcppattern->items[i].ppps[j];
    }
  BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPRODUCTCOUNT), prodcount);
  
  while(BxList_GetCount(BxGetDlgItem(hBox, FORMEDITCPPATTERN_LISTBOXPPP)) > 0)
    BxList_DeleteString(BxGetDlgItem(hBox, FORMEDITCPPATTERN_LISTBOXPPP), 0);
  
  for(i=0;i<editcppattern->items[selectedLayer].maxpush;i++)
  {
    sprintf(s,"%s %d: %d a=%d v=%d", getLanguageLineFromIdx(langptr, 279, "Push"), i, editcppattern->items[selectedLayer].ppps[i], editcppattern->items[selectedLayer].paccs[i], editcppattern->items[selectedLayer].pspeeds[i]);
    BxList_AddString(BxGetDlgItem(hBox, FORMEDITCPPATTERN_LISTBOXPPP), s);
  }

  return TRUE;
}

BX_BOOL formEditCPPatternUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPPPIDX));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELLAYERIDX));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_GROUPBOXNAME));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_GROUPBOXNAME), getLanguageLineFromIdx(langptr, 87, "Name"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELCNAME));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELCNAME), editcppattern->name);
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELLAYER));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELLAYER), getLanguageLineFromIdx(langptr, 278, "Select layer"));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDLAYER));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELMAXPUSH));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELMAXPUSH),
                   getLanguageLineFromIdx(langptr, 273, "Number of pushes in layer"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELGETTIME));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELGETTIME),
                   getLanguageLineFromIdx(langptr, 274, "Minimum time between products"));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDMAXPUSH));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDGETTIME));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_GROUPBOXPRODUCTCOUNT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_GROUPBOXPRODUCTCOUNT),
                   getLanguageLineFromIdx(langptr, 277, "Number of products"));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPRODUCTCOUNT));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDCANCEL), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDSAVE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDSAVE), getLanguageLineFromIdx(langptr, 261, "Save"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELMAXLAYERS));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELMAXLAYERS), getLanguageLineFromIdx(langptr, 275, "Number of layers"));
  BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPPP));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPPP), getLanguageLineFromIdx(langptr, 276, "Products per push"));
  BxAssignIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_CMDMAXLAYERS));

  
  selectedLayer = 0;
  formEditCPPattern_UpdateEditables(hBox);

  return TRUE;
}

BX_BOOL formEditCPPatternUserUpdate(HBOX hBox)
{
  if(editcppattern != NULL)
  {
    BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELPPPIDX), editcppattern->selectedPPP);
    BxSetIntValue(BxGetDlgItem(hBox, FORMEDITCPPATTERN_TEXTLABELLAYERIDX), editcppattern->selectedItem);
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdMaxLayers_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(editcppattern->maxidx);
  BxVirtNumBox_SetLimits(1, 10);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    int i,j;
    int newmaxidx = BxVirtNumBox_GetValue();
    if(editcppattern->maxidx < newmaxidx)
    {
      //create new layer(s), copy of last layer in pattern
      int diff = newmaxidx - editcppattern->maxidx;
      editcppattern->items = (tmpnCPPatternItem*)realloc(editcppattern->items,sizeof(tmpnCPPatternItem)*(editcppattern->maxidx + diff));
      
      for(i=0;i<diff;i++)
      {
        tmpnCPPatternItem *item = &editcppattern->items[editcppattern->maxidx];
        item->layer = editcppattern->maxidx;
        //printf("newlayernum: %d\n", item->layer);
        item->maxpush = editcppattern->items[editcppattern->maxidx - 1].maxpush;
        //printf("newlayer maxpush: %d\n", item->maxpush);
        item->gettime = editcppattern->items[editcppattern->maxidx - 1].gettime;
        //printf("newlayer gettime: %d\n", item->gettime);
        
        item->ppps = (int*)malloc(sizeof(int)*item->maxpush);
        item->paccs = (int*)malloc(sizeof(int)*item->maxpush);
        item->pspeeds = (int*)malloc(sizeof(int)*item->maxpush);
        for(j=0;j<item->maxpush;j++)
        {
          item->ppps[j] = editcppattern->items[editcppattern->maxidx - 1].ppps[j];
	  item->paccs[j] = editcppattern->items[editcppattern->maxidx - 1].paccs[j];
	  item->pspeeds[j] = editcppattern->items[editcppattern->maxidx - 1].pspeeds[j];
        }
        editcppattern->maxidx++;
      }
    }
    else if(editcppattern->maxidx > newmaxidx)
    {
      //delete last layer(s)
      int diff = editcppattern->maxidx - newmaxidx;
      for(i=0;i<diff;i++)
      {
        if(editcppattern->selectedItem >= editcppattern->maxidx - 1)
        {
          tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
          char str[256];
          sprintf(str,"%s %s",
                  getLanguageLineFromIdx(langptr, 259,"Layer"),
                  getLanguageLineFromIdx(langptr, 280,"in use. Reset and try again"));
          BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
                   getLanguageLineFromIdx(langptr, 74,"Ok"),
                   getLanguageLineFromIdx(langptr, 3,"Cancel"));
          formEditCPPattern_UpdateEditables(hBox);
          return TRUE;
        }
        editcppattern->maxidx--;
        free(editcppattern->items[editcppattern->maxidx].ppps);
	free(editcppattern->items[editcppattern->maxidx].paccs);
	free(editcppattern->items[editcppattern->maxidx].pspeeds);
      }
      editcppattern->items = (tmpnCPPatternItem*)realloc(editcppattern->items,sizeof(tmpnCPPatternItem)*(editcppattern->maxidx));
    }
    else
      return TRUE;
    formEditCPPattern_UpdateEditables(hBox);
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdPrevLayer_Click(HBOX hBox)
{
  if(selectedLayer > 0)
  {
    selectedLayer--;
    formEditCPPattern_UpdateEditables(hBox);
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdNextLayer_Click(HBOX hBox)
{
  if(selectedLayer < editcppattern->maxidx - 1)
  {
    selectedLayer++;
    formEditCPPattern_UpdateEditables(hBox);
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdLayer_Click(HBOX hBox)
{
  BxVirtNumBox_SetValue(selectedLayer);
  
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    int newlayer = BxVirtNumBox_GetValue();
    if(newlayer >= 0 && newlayer < editcppattern->maxidx)
    {
      selectedLayer = newlayer;
      formEditCPPattern_UpdateEditables(hBox);
    }
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdMaxpush_Click(HBOX hBox)
{
  tmpnCPPatternItem *item = &editcppattern->items[selectedLayer];
  BxVirtNumBox_SetValue(item->maxpush);
  BxVirtNumBox_SetLimits(1, 10);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    int i;
    int newmaxpush = BxVirtNumBox_GetValue();
    if(item->maxpush < newmaxpush)
    {
      //create new ppp(s), copy of last ppp in layer
      int diff = newmaxpush - item->maxpush;
      
      item->ppps = (int*)realloc(item->ppps, sizeof(int)*(item->maxpush + diff));
      item->paccs = (int*)realloc(item->paccs, sizeof(int)*(item->maxpush + diff));
      item->pspeeds = (int*)realloc(item->pspeeds, sizeof(int)*(item->maxpush + diff));

      for(i=0;i<diff;i++)
      {
        item->ppps[item->maxpush] = item->ppps[item->maxpush - 1];
	item->paccs[item->maxpush] = item->paccs[item->maxpush - 1];
	item->pspeeds[item->maxpush] = item->pspeeds[item->maxpush - 1];
        item->maxpush++;
      }
    }
    else if(item->maxpush > newmaxpush)
    {
      //delete last ppp(s)
      int diff = item->maxpush - newmaxpush;
      for(i=0;i<diff;i++)
      {
        if(editcppattern->selectedItem == selectedLayer && editcppattern->selectedPPP >= item->maxpush - 1)
        {
          tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
          char str[256];
          sprintf(str,"%s %s",
                  getLanguageLineFromIdx(langptr, 279,"Push"), 
                  getLanguageLineFromIdx(langptr, 280,"in use. Reset and try again"));
          BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
                   getLanguageLineFromIdx(langptr, 74,"Ok"),
                   getLanguageLineFromIdx(langptr, 3,"Cancel"));
          formEditCPPattern_UpdateEditables(hBox);
          return TRUE;
        }
        item->maxpush--;
      }
      item->ppps = (int*)realloc(item->ppps, sizeof(int)*(item->maxpush));
      item->paccs = (int*)realloc(item->paccs, sizeof(int)*(item->maxpush));
      item->pspeeds = (int*)realloc(item->pspeeds, sizeof(int)*(item->maxpush));
    }
    else
      return TRUE;
    formEditCPPattern_UpdateEditables(hBox);
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdGettime_Click(HBOX hBox)
{
  tmpnCPPatternItem *item = &editcppattern->items[selectedLayer];
  BxVirtNumBox_SetValue(item->gettime);
  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    int newgettime = BxVirtNumBox_GetValue();
    if(newgettime >= 0){
      item->gettime = newgettime;
      formEditCPPattern_UpdateEditables(hBox);
    }
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_listBoxPPP_Click(HBOX hBox)
{
  HBOX hBx;
  tmpnCPPatternItem *item = &editcppattern->items[selectedLayer];
  int listidx = BxList_GetSelected(BxGetDlgItem(hBox, FORMEDITCPPATTERN_LISTBOXPPP));
  if(listidx >= 0)
  {
    if(item!=NULL)
    {
      hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formEditPPP[0], formEditPPPProc);
      BxSetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPPP), item->ppps[listidx]);	
      BxSetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPACC), item->paccs[listidx]);
      BxSetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPSPEED), item->pspeeds[listidx]);
      if(DoModal(hBx)==IDOK)
      {
        int newppp = BxGetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPPP));
        int newpacc = BxGetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPACC));
        int newpspeed = BxGetIntValue(BxGetDlgItem(hBx, FORMEDITPPP_CMDPSPEED));
        if(newppp > 0)
          item->ppps[listidx] = newppp;
        if((newpacc >= 0)&&(newpacc <= 100))
          item->paccs[listidx] = newpacc;
        if((newpspeed >= 0)&&(newpspeed <= 100))
          item->pspeeds[listidx] = newpspeed;
        formEditCPPattern_UpdateEditables(hBox);
      }
    }
  }
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, FALSE);
  return TRUE;
}

BX_BOOL formEditCPPattern_cmdSave_Click(HBOX hBox)
{
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  char str[256];

  if(editcppattern->user == 0)
  {
    BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 283,"Only user created file can be saved/deleted"),
             getLanguageLineFromIdx(langptr, 134,"Error"),0,
             getLanguageLineFromIdx(langptr, 74,"Ok"),
             getLanguageLineFromIdx(langptr, 3,"Cancel"));
    return FALSE;
  }
  if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 261,"Save"),
              getLanguageLineFromIdx(langptr, 16,"Information"),0,
              getLanguageLineFromIdx(langptr, 74,"Ok"),
              getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDOK)
  {
    if(!tmpnCPPatternSave(editcppattern))
    {
      sprintf(str,"%s %s",
              getLanguageLineFromIdx(langptr, 261,"Save"),
              getLanguageLineFromIdx(langptr, 134,"Error"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
    }
  }
  return TRUE;
}
