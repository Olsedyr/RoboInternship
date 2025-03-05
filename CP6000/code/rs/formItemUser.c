//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formItemUser.c
#include "Bx.h"
#include "formItem.h"
#include "cmd.h"
#include "formItemEdit.h"

char *itemName=NULL;

BX_BOOL formItemUserInit(HBOX hBox,BX_LPARAM lParam)
{
  int i=0;
  //tmpnItems *items = &tworkcell->items
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];

	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_TEXTLABEL2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_TEXTLABEL2_2), getLanguageLineFromIdx(langptr, 260, "Item"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDCREATE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDCREATE), getLanguageLineFromIdx(langptr, 269, "Create"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDDELETE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDDELETE), getLanguageLineFromIdx(langptr, 270, "Delete"));
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDDELETE),TRUE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDEDIT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDEDIT), getLanguageLineFromIdx(langptr, 80, "Edit"));
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDEDIT), TRUE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDADD));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDADD), getLanguageLineFromIdx(langptr, 271, "Add"));
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDADD), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDREMOVE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDREMOVE), getLanguageLineFromIdx(langptr, 272, "Remove"));
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDREMOVE), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDOK));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDOK), getLanguageLineFromIdx(langptr, 79, "Choose"));
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDOK), FALSE);
	BxAssignStringValue(BxGetDlgItem(hBox, FORMITEM_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMITEM_CMDCANCEL), getLanguageLineFromIdx(langptr, 4, "Abort"));

  //sort order important for formProgramCtrlUser.c, uses BxList_GetSelected to index items.
	for (i=0;i<tworkcell->items.maxidx;i++)
    BxList_AddString(BxGetDlgItem(hBox, FORMITEM_LISTBOX),(char*)tworkcell->items.item[i].name);
  return TRUE;
}

BX_BOOL formItemUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formItem_listBox_Click(HBOX hBox)
{
	BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDOK), TRUE);
	//BxEnableBox(BxGetDlgItem(hBox, FORMITEM_CMDREMOVE), TRUE);
  return TRUE;
}

BX_BOOL formItem_cmdCreate_Click(HBOX hBox)
{
	char newname[128];
  tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  char str[512];
	newname[0]='\0';
  
  //check if there's enough mem allocated:
  if(tworkcell->items.maxidx >= MAXITEMS)
  {
    sprintf(str,"%s %s",
            getLanguageLineFromIdx(langptr, 93,"Max"),
            getLanguageLineFromIdx(langptr, 260,"Item"));
    BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
             getLanguageLineFromIdx(langptr, 74,"Ok"),
             getLanguageLineFromIdx(langptr, 3,"Cancel"));
    return FALSE;
  }
  
  
  if(BxVirtualKeyboard( hBox, "", 32)==IDOK)
  {
    strcpy(newname,BxVirtualKeyboard_GetString());
    //TODO: invalid chars
  }
  else
    return FALSE;
  
  if (strlen(newname)>0)
  {
    tmpnItem *item = (tmpnItem*)&tworkcell->items.item[tworkcell->items.maxidx];
    
    sprintf(item->name,"%s",newname);
    
    //check if name already exists
    if(getItem(item->name,(tmpnWorkcell*)tworkcell) != NULL)
    {
      sprintf(str,"%s '%s' %s",
              getLanguageLineFromIdx(langptr, 87,"Name"),
              item->name,
              getLanguageLineFromIdx(langptr, 281,"exists"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      
      return FALSE;
    }
    sprintf(item->filename,"%s/item/%s.item",rs_systempath,newname);
    
    //check if file already exists
    FILE *file;
    if ((file = fopen(item->filename, "r")))
    {
      fclose(file);
      sprintf(str,"%s '%s.item' %s",
              getLanguageLineFromIdx(langptr, 282,"File"),
              item->name,
              getLanguageLineFromIdx(langptr, 281,"exists"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      //TODO overwrite existing file?
      return FALSE;
    }
    strcpy(item->type,"BOX");
    
    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 284,"Length (x)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->dim.x = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 285,"GripLength (gx)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->gx = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 286,"Height (y)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->dim.y = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 287,"Width (z)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->dim.z = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 288,"Stackheight (sy)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->sy = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 289,"Gripheight (gy)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->gy = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 290,"Moveheight (my)"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->my = BxVirtNumBox_GetFloatValue();

    if(BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 291,"Weight"),
                getLanguageLineFromIdx(langptr, 79,"Choose"),0,
                getLanguageLineFromIdx(langptr, 74,"Ok"),
                getLanguageLineFromIdx(langptr, 3,"Cancel")) == IDCANCEL) return FALSE;
    BxVirtNumBox_SetFloatValue(0.0);
    while(VirtNumKeyBox( hBox ) != IDOK){}
    item->weight = BxVirtNumBox_GetFloatValue();
    
    item->user = 1;
    
    if(!tmpnItemSave(item))
    {
      sprintf(str,"%s %s",
              getLanguageLineFromIdx(langptr, 261,"Save"),
              getLanguageLineFromIdx(langptr, 134,"Error"));
      BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      return FALSE;
    }
    
    BxList_AddString(BxGetDlgItem(hBox, FORMITEM_LISTBOX),item->name);
      
    FILE *fp = fopen((char*)tworkcell->filename,"a"); //append
    if(fp==NULL)
    {
      //clean up, delete string from listbox
      BxList_DeleteString(BxGetDlgItem(hBox, FORMITEM_LISTBOX), BxList_GetCount(BxGetDlgItem(hBox, FORMITEM_LISTBOX)) - 1);
      BxMsgBox(hBox,getLanguageLineFromIdx(langptr, 134,"Error"),
               getLanguageLineFromIdx(langptr, 134,"Error"),0,
               getLanguageLineFromIdx(langptr, 74,"Ok"),
               getLanguageLineFromIdx(langptr, 3,"Cancel"));
      return FALSE;
    }
    fprintf(fp,"ITEM %s.item\n", item->name);
    fclose(fp);
  }
  tworkcell->items.maxidx++;
  return TRUE;
}

BX_BOOL formItem_cmdDelete_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formItem_cmdEdit_Click(HBOX hBox)
{
    HBOX hBx;
    tmpnItem *item;
    int index = BxList_GetSelected(BxGetDlgItem(hBox, FORMITEM_LISTBOX));
    tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
    char str[256];
	  if(index >= 0)
      {  
        item=(&tworkcell->items.item[index]);
				if (item!=NULL)
				{
          itemName=(char *)BxList_GetString(BxGetDlgItem(hBox, FORMITEM_LISTBOX),index);
          hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formItemEdit[0], formItemEditProc);
					BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDX), item->dim.x);
				  BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDY), item->dim.y);
					BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDZ), item->dim.z);
					BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDSY), item->sy);
					BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDGY), item->gy);
          BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDMY), item->my);
          BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDGX), item->gx);
          BxSetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDWEIGHT), item->weight);
					if(DoModal(hBx)==IDOK)
					{
            item->dim.x = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDX));
					  item->dim.y = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDY));
				  	item->dim.z = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDDZ));
				   	item->sy = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDSY));
				  	item->gy = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDGY));
            item->my = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDMY));
            item->gx = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDGX));
            item->weight = BxGetFloatValue(BxGetDlgItem(hBx, FORMITEMEDIT_CMDWEIGHT));
            if(!tmpnItemSave(item))
            {
              sprintf(str,"%s %s",
              getLanguageLineFromIdx(langptr, 261,"Save"),
              getLanguageLineFromIdx(langptr, 134,"Error"));
              BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 134,"Error"),0,
              getLanguageLineFromIdx(langptr, 74,"Ok"),
              getLanguageLineFromIdx(langptr, 3,"Cancel"));
              return FALSE;
            }
          }
			  }
	  	}
  return TRUE;
}

BX_BOOL formItem_cmdAdd_Click(HBOX hBox)
{
  //BxList_AddString(BxGetDlgItem(hBox, FORMITEM_LISTBOX),"");
  //BxList_SetString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), sn++, s); 
  return TRUE;
}

BX_BOOL formItem_cmdRemove_Click(HBOX hBox)
{
  //BxList_GetSelected
  //BxList_DeleteString(BxGetDlgItem(hBox, FORMITEM_LISTBOX),idx);
  return TRUE;
}

BX_BOOL formItem_cmdOk_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formItem_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

