//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formMacUser.c
#include "Bx.h"
#include "cmd.h"
#include "formMac.h"

extern volatile int dioIndex;
extern volatile int modIndex;

BX_BOOL formMacUserInit(HBOX hBox,BX_LPARAM lParam)
{
  int i;
  macstruct *mac;
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];	
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMAC_CMDCLOSE));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMAC_CMDCLOSE), getLanguageLineFromIdx(langptr, 54, "Close"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_2_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_2_2), getLanguageLineFromIdx(langptr, 101, "Init. data:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_2));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_2), getLanguageLineFromIdx(langptr, 102, "In data:"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_3));
	BxSetStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME_3), getLanguageLineFromIdx(langptr, 103, "Out data:"));
  mac = &tworkcell->macs.mac[dioIndex].iotab[modIndex];
  
  BxAssignStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME));
  BxSetStringValue(BxGetDlgItem(hBox, FORMMAC_LABMODNAME), mac->module_name);
  
  for(i=0; i<mac->numOfInitWords; i++)
	{
    char s[256*2];
		if (mac->initdata[i].type==MAC_LONGINT||mac->initdata[i].type==MAC_SHORTINT||mac->initdata[i].type==MAC_SHORTUINT)
			sprintf(s,"%s %d", mac->initdata[i].key, mac->initdata[i].data);
		else if (mac->initdata[i].type==MAC_CMD)
		{
			char cmdstr[32];
			sprintf(cmdstr,"%s","unknowncmd");
			if (mac->initdata[i].reg==0x54)
			{
				sprintf(cmdstr,"%s","EnterSafeMode");
			}
			else if (mac->initdata[i].reg==0x55)
			{
				sprintf(cmdstr,"%s","ExitSafeMode");
			}
			else if (mac->initdata[i].reg==0x56)
			{
				sprintf(cmdstr,"%s","SaveToFlash");
			}
			else if (mac->initdata[i].reg==0x57)
			{
				sprintf(cmdstr,"%s","SoftWareReset");
			}
			sprintf(s,"MAC_CMD %s", cmdstr);
		}
		else
			sprintf(s,"%s %0.4f", mac->initdata[i].key, mac->initdata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT), s);	
	}
  for(i=0; i<mac->numOfInWords; i++)
	{
    char s[256*2];
		if (mac->idata[i].type==MAC_LONGINT||mac->idata[i].type==MAC_SHORTINT||mac->idata[i].type==MAC_SHORTUINT)
			sprintf(s,"%s %d", mac->idata[i].key, mac->idata[i].data);
		else
			sprintf(s,"%s %0.4f", mac->idata[i].key, mac->idata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMMAC_LISTBOXIN), s);  
  }
  for(i=0; i<mac->numOfOutWords; i++)
	{
    char s[256*2];
		if (mac->odata[i].type==MAC_LONGINT||mac->odata[i].type==MAC_SHORTINT||mac->odata[i].type==MAC_SHORTUINT)
			sprintf(s,"%s %d", mac->odata[i].key, mac->odata[i].data);
		else
			sprintf(s,"%s %0.4f", mac->odata[i].key, mac->odata[i].fdata);
    BxList_AddString(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT), s);  
  }
  return TRUE;
}

BX_BOOL formMacUserUpdate(HBOX hBox)
{
  int i;
  macstruct *mac;
  mac = &tworkcell->macs.mac[dioIndex].iotab[modIndex];
  
  for(i=0; i<mac->numOfInWords; i++){
    if(i < BxList_GetCount(BxGetDlgItem(hBox, FORMMAC_LISTBOXIN))){
      char s[256*2];
			if (mac->idata[i].type==MAC_LONGINT||mac->idata[i].type==MAC_SHORTINT||mac->idata[i].type==MAC_SHORTUINT)
				sprintf(s,"%s %d", mac->idata[i].key, mac->idata[i].data);
			else
				sprintf(s,"%s %0.4f", mac->idata[i].key, mac->idata[i].fdata);
      BxList_SetString(BxGetDlgItem(hBox, FORMMAC_LISTBOXIN), i, s);
    }
  }
	BxList_Update(BxGetDlgItem(hBox, FORMMAC_LISTBOXIN));
	return TRUE;
}

BX_BOOL formMac_listBoxInit_Click(HBOX hBox)
{
  macstruct *mac;
  mac = &tworkcell->macs.mac[dioIndex].iotab[modIndex];
  int sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT));
  
  if(sel < mac->numOfInitWords){
		if (mac->initdata[sel].type==MAC_LONGINT||mac->initdata[sel].type==MAC_SHORTINT||mac->initdata[sel].type==MAC_SHORTUINT)
		{
			BxVirtNumBox_SetValue(mac->initdata[sel].data);
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				char s[256*2];
				int olddata=mac->initdata[sel].data;
				mac->initdata[sel].data = BxVirtNumBox_GetValue();
				if( SaveMacInitVal((tmpnMac *) &tworkcell->macs.mac[dioIndex], modIndex, sel))
				{
					sprintf(s,"%s %d", mac->initdata[sel].key, mac->initdata[sel].data);
					BxList_SetString(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT), sel, s);
					BxList_Update(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT));
				}
				else 
				{
					mac->initdata[sel].data = olddata;
				}
			}
		}
		else
		{
			BxVirtNumBox_SetFloatValue(mac->initdata[sel].fdata);
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				char s[256*2];
				float olddata;
				mac->initdata[sel].fdata = BxVirtNumBox_GetFloatValue();
				if (SaveMacInitVal((tmpnMac *) &tworkcell->macs.mac[dioIndex], modIndex, sel))
				{
					sprintf(s,"%s %0.4f", mac->initdata[sel].key, mac->initdata[sel].fdata);
					BxList_SetString(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT), sel, s);
					BxList_Update(BxGetDlgItem(hBox, FORMMAC_LISTBOXINIT));
				}
				else 
				{
					mac->initdata[sel].data = olddata;
				}
			}
		}
  }
  return TRUE;
}

BX_BOOL formMac_listBoxIn_Click(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formMac_listBoxOut_Click(HBOX hBox)
{
  macstruct *mac;
  mac = &tworkcell->macs.mac[dioIndex].iotab[modIndex];
  int sel = BxList_GetSelected(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT));
  
  if(sel < mac->numOfOutWords)
	{
		if (mac->odata[sel].type==MAC_LONGINT||mac->odata[sel].type==MAC_SHORTINT||mac->odata[sel].type==MAC_SHORTUINT)
		{
			BxVirtNumBox_SetValue(mac->odata[sel].data);
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				char s[256*2];
				mac->odata[sel].data = BxVirtNumBox_GetValue();
				mac->odata[sel].userchange = 1;
				sprintf(s,"%s %d", mac->odata[sel].key, mac->odata[sel].data);
				BxList_SetString(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT), sel, s);
				BxList_Update(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT));
			}
		}
		else
		{
			BxVirtNumBox_SetFloatValue(mac->odata[sel].fdata);
			if(VirtNumKeyBox( hBox ) == IDOK)
			{
				char s[256*2];
				mac->odata[sel].fdata = BxVirtNumBox_GetFloatValue();
				mac->odata[sel].userchange = 1;
				sprintf(s,"%s %0.4f", mac->odata[sel].key, mac->odata[sel].fdata);
				BxList_SetString(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT), sel, s);
				BxList_Update(BxGetDlgItem(hBox, FORMMAC_LISTBOXOUT));
			}
		}
  }
  return TRUE;
}

BX_BOOL formMac_cmdClose_Click(HBOX hBox)
{
  BxEndDialog(hBox, 0);
  return TRUE;
}
