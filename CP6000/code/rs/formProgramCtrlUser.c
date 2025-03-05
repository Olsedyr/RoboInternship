//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formProgramCtrlUser.c
#include "Bx.h"
#include "cmd.h"
#include "formProgramCtrl.h"
#include "formItem.h"
#include "formCPPattern.h"


extern volatile int prgIndex;
extern volatile int prgstateIndex;

BX_BOOL formProgramCtrlUserInit(HBOX hBox,BX_LPARAM lParam)
{
	int i,j;
	int nitem;
	int nmax=0;
	int private=1;
	int level=0;
	tmpnStateMachine *prgstm;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_GROUPBOX2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_GROUPBOX2), getLanguageLineFromIdx(langptr, 1, "Program"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_CMDEDIT));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_CMDEDIT), getLanguageLineFromIdx(langptr, 80, "Edit"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LABSTATE));
	prgstm=&tworkcell->statemachines.statemachine[prgIndex];
	for (i=0;i<prgstm->numstate;i++)
	{
		if (!strncmp(prgstm->state[i].name,"PROGRAM_",8))
		{
			// Get max number of adjustable values
			nitem=0;
			private=1;
			level=0;
			for (j=0;j<prgstm->state[i].maxprgidx;j++)
			{
				if (prgstm->state[i].prg[j].type==TEST)
					level++;
				else if (prgstm->state[i].prg[j].type==ENDTEST)
					level--;
				else if (!level&&prgstm->state[i].prg[j].type==SET)
				{
					if (((SETSTRUCT*)prgstm->state[i].prg[j].data)->src.type==NUMBER)
					{
						if (!strncmp(((SETSTRUCT*)prgstm->state[i].prg[j].data)->dest.valstring,"usersection",11))
						{
							if (((SETSTRUCT*)prgstm->state[i].prg[j].data)->src.subtype==0)
							{
								if (((SETSTRUCT*)prgstm->state[i].prg[j].data)->src.number==1)
									private=0;
								else if (((SETSTRUCT*)prgstm->state[i].prg[j].data)->src.number==0)
									private=1;
							}
						}
						else if (!private) nitem++;
					}
				}
        else if (!level&&prgstm->state[i].prg[j].type==SETITEM)
        {
          if (!private) nitem++;
        }
        else if (!level&&prgstm->state[i].prg[j].type==SETCPPATTERN)
        {
          if (!private) nitem++;
        }
			}
			if (nitem>nmax) nmax=nitem;
		}
	}
	for (i=0;i<nmax;i++)
	{
		BxList_AddString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX),"");
	}
	return TRUE;
}

BX_BOOL formProgramCtrlUserUpdate(HBOX hBox)
{
	int i;
	int sn;
	char *name;
	int private;
	int level;
	char s[128];
	tmpnStateMachine *prgstm;
	prgstm=&tworkcell->statemachines.statemachine[prgIndex];
 	name=&prgstm->state[prgstateIndex].name[8]; 
 	BxSetStringValue(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LABSTATE), name);
	sn=0;
	private=1;
	level=0;
	for (i=0;i<prgstm->state[prgstateIndex].maxprgidx;i++)
 	{
		if (prgstm->state[prgstateIndex].prg[i].type==TEST)
			level++;
		else if (prgstm->state[prgstateIndex].prg[i].type==ENDTEST)
			level--;
		else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SET)
		{ 
			if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.type==NUMBER)
			{
				if (!strncmp(((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest.valstring,"usersection",11))	
				{			
					if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.subtype==0)
					{
						if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number==1)
							private=0;
						else if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number==0)
							private=1;
					}
				}
				else if (!private)
				{
					if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.subtype==0)
					{
						sprintf(s,"%s %d",((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest.valstring,((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number);
					}
					else if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.subtype==1)
					{
						sprintf(s,"%s %0.4f",((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest.valstring,((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.fnumber);
					}
					BxList_SetString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), sn++, s); 
				}
			}
		}
    else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SETITEM)
    {
      if (!private)
      {
        SETITEMSTRUCT *setitem = ((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data);
        sprintf(s,"%s %s",setitem->dest,setitem->src);
        BxList_SetString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), sn++, s);
      }
    }
    else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SETCPPATTERN)
    {
      if (!private)
      {
        SETCPPATTERNSTRUCT *setcppattern = ((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data);
        sprintf(s,"%s %s",setcppattern->dest,setcppattern->src);
        BxList_SetString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), sn++, s);
      }
    }
 	}
	BxList_Update(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX));
	return TRUE;
}

BX_BOOL formProgramCtrl_cmdEdit_Click(HBOX hBox)
{
	tmpnStateMachine *prgstm;
	BX_PSTRING str;
	char tname[256];
	char vname[256];
	BX_INT outval=0;
	BX_FLOAT foutval=0.0;
	int valnum;
	int ret,i;
	int level=0;
	valnum = BxList_GetSelected(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX));
  if (valnum<0) return TRUE;
	
	prgstm=&tworkcell->statemachines.statemachine[prgIndex];
	str = BxList_GetString(BxGetDlgItem(hBox, FORMPROGRAMCTRL_LISTBOX), valnum);
	ret = sscanf(str, "%s %s",tname,vname);
	if (ret!=2) return TRUE;
	level=0;
	for(i=0;i<prgstm->state[prgstateIndex].maxprgidx;i++)
	{
		if (prgstm->state[prgstateIndex].prg[i].type==TEST)
			level++;
		else if (prgstm->state[prgstateIndex].prg[i].type==ENDTEST)
			level--;
		else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SET)
		{ 
			if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.type==NUMBER)
			{
				if (!strcmp(((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest.valstring,tname))	
				{
					if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.subtype==0)
					{
						outval=((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number;
            BxVirtNumBox_SetValue(outval);
            if(VirtNumKeyBox( hBox ) == IDOK)
            {
              ((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number = BxVirtNumBox_GetValue();
              if (!SaveProgramVal(prgIndex,&prgstm->state[prgstateIndex].prg[i],prgstm->state[prgstateIndex].name))
              {
                if(rs_param.statemachine_debug>0)
                  printf("Program-val %s could not be saved.\n",tname);
                ((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.number = outval; 
              }
            }
						break;
					}
					else if (((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.subtype==1)
					{
						foutval=((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.fnumber;
            BxVirtNumBox_SetFloatValue(foutval);
            if(VirtNumKeyBox( hBox ) == IDOK)
            {
              ((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.fnumber = BxVirtNumBox_GetFloatValue();
              if (!SaveProgramVal(prgIndex,&prgstm->state[prgstateIndex].prg[i],prgstm->state[prgstateIndex].name))
              {
                if(rs_param.statemachine_debug>0)
                  printf("Program-val %s could not be saved.\n",tname);
                ((SETSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src.fnumber = foutval; 
              }
            }
						break;
					}
				}
			}
		}
    else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SETITEM)
    {
      if (!strcmp(((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest,tname))
      {
        HBOX hBx;
        hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formItem[0], formItemProc);
        if(DoModal(hBx)==IDOK)
        {
          char str[256];
          int selnum = BxList_GetSelected(BxGetDlgItem(hBx, FORMITEM_LISTBOX));
          if (selnum<0) return TRUE;
          
          tmpnItem *selectedItem=(tmpnItem*)&tworkcell->items.item[selnum];
          sprintf(str, "item%s",selectedItem->name);
          if(!strcmp(str,vname))//no change
            return TRUE;

          //look through prgstm to see if item<name> exists
          int matchIdx = -1;
          int j;
          for(j=0;j<prgstm->numvalue;j++)
          {
            if(prgstm->value[j].type == ITEM && !strcmp(prgstm->value[j].name,str))
            {
              matchIdx = j;
              break;
            }
          }
          if(matchIdx == -1)
          {
            //Add Item=item<name> <name> to prgstm
            if(!SaveItemVal(prgstm->name, str, selectedItem->name))
              return FALSE;
          }
          
          // change SETITEM
          char tempItemName[256];
          tmpnItem *tempItem = ((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcItem;
          strcpy(tempItemName, ((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src);

          strcpy(((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src, str);
          ((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcItem = selectedItem;
          if (!SaveProgramVal(prgIndex,&prgstm->state[prgstateIndex].prg[i],prgstm->state[prgstateIndex].name))
          {
            if(rs_param.statemachine_debug>0)
              printf("Program-val %s could not be saved.\n",tname);
            strcpy(((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src, tempItemName);
            ((SETITEMSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcItem = tempItem;
          }
        }
      }
    }
    else if (!level&&prgstm->state[prgstateIndex].prg[i].type==SETCPPATTERN)
    {
      if (!strcmp(((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->dest,tname))
      {
        HBOX hBx;
        hBx = BxCreateDialog(((BOXSTRUCT *)hBox)->hInstance, &formCPPattern[0], formCPPatternProc);
        if(DoModal(hBx)==IDOK)
        {
          char str[256];
          int selnum = BxList_GetSelected(BxGetDlgItem(hBx, FORMCPPATTERN_LISTBOX));
          if (selnum<0) return TRUE;
          
          tmpnCPPattern *selectedCpp=(tmpnCPPattern*)&tworkcell->cppatterns.cppattern[selnum];
          sprintf(str, "cpp%s",selectedCpp->name);
          if(!strcmp(str,vname))//no change
            return TRUE;

          //look through prgstm to see if cpp<name> exists
          int matchIdx = -1;
          int j;
          for(j=0;j<prgstm->numvalue;j++)
          {
            if(prgstm->value[j].type == CPPATTERN && !strcmp(prgstm->value[j].name,str))
            {
              matchIdx = j;
              break;
            }
          }
          if(matchIdx == -1)
          {
            //Add CPPattern=cpp<name> <name> to prgstm
            if(!SaveCPPatternVal(prgstm->name, str, selectedCpp->name))
              return FALSE;
          }
          
          // change SETCPPATTERN
          char tempCPPatternName[256];
          tmpnCPPattern *tempCPPattern = ((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcCPPattern;
          strcpy(tempCPPatternName, ((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src);

          strcpy(((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src, str);
          ((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcCPPattern = selectedCpp;
          if (!SaveProgramVal(prgIndex,&prgstm->state[prgstateIndex].prg[i],prgstm->state[prgstateIndex].name))
          {
            if(rs_param.statemachine_debug>0)
              printf("Program-val %s could not be saved.\n",tname);
            strcpy(((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->src, tempCPPatternName);
            ((SETCPPATTERNSTRUCT*)prgstm->state[prgstateIndex].prg[i].data)->srcCPPattern = tempCPPattern;
          }
        }
      }
    }
	}
  return TRUE;
}

BX_BOOL formProgramCtrl_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formProgramCtrl_listBox_Click(HBOX hBox)
{
  return TRUE;
}

