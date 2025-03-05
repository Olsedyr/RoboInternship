//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formCPPatternUser.c
#include "Bx.h"
#include "formCPPattern.h"
#include "formEditCPPattern.h"
#include "cmd.h"

extern tmpnCPPattern *editcppattern;

BX_BOOL formCPPatternUserInit(HBOX hBox,BX_LPARAM lParam)
{
  int i=0;
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_TEXTLABEL2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_TEXTLABEL2_2), getLanguageLineFromIdx(langptr, 262, "Pattern"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDCREATE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDCREATE), getLanguageLineFromIdx(langptr, 269, "Create"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDDELETE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDDELETE), getLanguageLineFromIdx(langptr, 270, "Delete"));
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDDELETE), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDEDIT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDEDIT), getLanguageLineFromIdx(langptr, 80, "Edit"));
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDEDIT), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDADD));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDADD), getLanguageLineFromIdx(langptr, 271, "Add"));
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDADD), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDREMOVE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDREMOVE), getLanguageLineFromIdx(langptr, 272, "Remove"));
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDREMOVE), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDOK));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDOK), getLanguageLineFromIdx(langptr, 79, "Choose"));
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDOK), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMCPPATTERN_CMDCANCEL), getLanguageLineFromIdx(langptr, 4, "Abort"));

  //sort order important for formProgramCtrlUser.c, uses BxList_GetSelected to index cppatterns.
	for (i=0;i<tworkcell->cppatterns.maxidx;i++)
    BxList_AddString(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX),tworkcell->cppatterns.cppattern[i].name);
  return TRUE;
}

BX_BOOL formCPPatternUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formCPPattern_cmdAdd_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formCPPattern_cmdRemove_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formCPPattern_cmdCreate_Click(HBOX hBox)
{
	char newname[128];
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  char str[512];
	newname[0]='\0';

  if(BxVirtualKeyboard( hBox, "", 32)==IDOK)
  {
    strcpy(newname,BxVirtualKeyboard_GetString());
    //TODO: invalid chars
  }
  else
    return FALSE;

  if (strlen(newname)>0)
  {
    tmpnCPPattern cpp;
    sprintf(cpp.name,"%s",newname);
    
    //check if name already exists
    if(getCPPattern(cpp.name,(tmpnWorkcell*)tworkcell) != NULL)
    {
      sprintf(str,"%s '%s' %s",
              getLanguageLineFromIdx(langptr, 87,"Name"),
              cpp.name,
              getLanguageLineFromIdx(langptr, 281,"exists"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      
      return FALSE;
    }
    sprintf(cpp.filename,"%s/cppattern/%s.cppattern",rs_systempath,newname);

    //check if file already exists
    FILE *file;
    if ((file = fopen(cpp.filename, "r")))
    {
      fclose(file);
      sprintf(str,"%s '%s.cppattern' %s",
              getLanguageLineFromIdx(langptr, 282,"File"),
              cpp.name,
              getLanguageLineFromIdx(langptr, 281,"exists"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      //TODO overwrite existing file?
      return FALSE;
    }
    cpp.maxidx = 1;
    cpp.user = 1;
    cpp.items = (tmpnCPPatternItem*)malloc(sizeof(tmpnCPPatternItem));
    cpp.items[0].layer = 0;
    cpp.items[0].maxpush = 1;
    cpp.items[0].gettime = 100000;
    cpp.items[0].ppps = (int*)malloc(sizeof(int));
    cpp.items[0].ppps[0] = 1;
    cpp.items[0].paccs = (int*)malloc(sizeof(int));
    cpp.items[0].paccs[0] = 100;
    cpp.items[0].pspeeds = (int*)malloc(sizeof(int));
    cpp.items[0].pspeeds[0] = 100;

    if(!tmpnCPPatternSave(&cpp))
    {
      free(cpp.items[0].ppps);
      free(cpp.items[0].paccs);
      free(cpp.items[0].pspeeds);
      free(cpp.items);
      sprintf(str,"%s %s",
              getLanguageLineFromIdx(langptr, 261,"Save"),
              getLanguageLineFromIdx(langptr, 134,"Error"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      return FALSE;
    }
    
    free(cpp.items[0].ppps);
    free(cpp.items[0].paccs);
    free(cpp.items[0].pspeeds);
    free(cpp.items);
    
    if(tmpnCPPatternLoad(cpp.filename, (tmpnCPPatterns*)&tworkcell->cppatterns))
    {
      tmpnCPPattern * cppl = &tworkcell->cppatterns.cppattern[tworkcell->cppatterns.maxidx - 1];
      BxList_AddString(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX),cppl->name);
      
      FILE *fp = fopen((char*)tworkcell->filename,"a"); //append
      if(fp==NULL)
      {
        //clean up, delete string from listbox, unload pattern
        BxList_DeleteString(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX), BxList_GetCount(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX)) - 1);
        free(cppl->items[0].ppps);
	free(cppl->items[0].paccs);
	free(cppl->items[0].pspeeds);
        free(cppl->items);
        tworkcell->cppatterns.maxidx--;
        tworkcell->cppatterns.cppattern = (tmpnCPPattern*)realloc(tworkcell->cppatterns.cppattern,sizeof(tmpnCPPattern)*(tworkcell->cppatterns.maxidx));
        BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 134,"Error"),
                 getLanguageLineFromIdx(langptr, 134,"Error"),0,
                 getLanguageLineFromIdx(langptr, 74,"Ok"),
                 getLanguageLineFromIdx(langptr, 3,"Cancel"));
        return FALSE;
      }
      fprintf(fp,"CPPATTERN %s.cppattern\n", cpp.name);
      fclose(fp);
    }
  }
  return TRUE;
}

BX_BOOL formCPPattern_cmdDelete_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formCPPattern_cmdEdit_Click(HBOX hBox)
{
  HBOX hBx;
  int selnum = BxList_GetSelected(BxGetDlgItem(hBox, FORMCPPATTERN_LISTBOX));

  if ((editcppattern=&tworkcell->cppatterns.cppattern[selnum]) != NULL)
  {
    hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formEditCPPattern[0], formEditCPPatternProc);
    DoModal(hBx);
  }
  return TRUE;
}

BX_BOOL formCPPattern_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formCPPattern_cmdOk_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formCPPattern_listBox_Click(HBOX hBox)
{
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDEDIT), TRUE);
	BxEnableBox(BxGetDlgItem(hBox, FORMCPPATTERN_CMDOK), TRUE);
  return TRUE;
}
