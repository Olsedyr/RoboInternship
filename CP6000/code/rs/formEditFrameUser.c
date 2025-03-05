/****************************************************************************
* Copyright (C) 2006 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
// formEditFrameUser.c
#include "Bx.h"
#include "rs.h"
#include "cmd.h"
#include "formEditFrame.h"


extern char *fixpointsFrameName;

BX_BOOL formEditFrameUserInit(HBOX hBox,BX_LPARAM lParam)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDRETURN));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDRETURN), getLanguageLineFromIdx(langptr, 74, "Ok"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCANCEL));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCANCEL), getLanguageLineFromIdx(langptr, 3, "Cancel"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDTHISPOS));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDTHISPOS), getLanguageLineFromIdx(langptr, 225, "Set all to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSX));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSX), getLanguageLineFromIdx(langptr, 113, "Set to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSY));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSY), getLanguageLineFromIdx(langptr, 113, "Set to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSZ));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSZ), getLanguageLineFromIdx(langptr, 113, "Set to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSV));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSV), getLanguageLineFromIdx(langptr, 113, "Set to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSW));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDCURPOSW), getLanguageLineFromIdx(langptr, 113, "Set to current position"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_GROUPBOX1));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_GROUPBOX1), getLanguageLineFromIdx(langptr, 114, "Frame"));
	BxAssignStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_TEXTLABELNAME));
	BxSetStringValue(BxGetDlgItem(hBox, FORMEDITFRAME_TEXTLABELNAME), fixpointsFrameName);
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX), 0.0);
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY), 0.0);
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ), 0.0);
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV), 0.0);
  BxAssignFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW));
  BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW), 0.0);
  return TRUE;
}

BX_BOOL formEditFrameUserUpdate(HBOX hBox)
{
 return TRUE;
}

BX_BOOL formEditFrame_cmdReturn_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDOK);
  return TRUE;
}

BX_BOOL formEditFrame_cmdThisPos_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s (x=%0.2f, y=%0.2f, z=%0.2f, v=%0.2f, w=%0.2f)?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.x,trobot->m_worldPoint.y,trobot->m_worldPoint.z,trobot->m_worldPoint.v,trobot->m_worldPoint.w); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX), trobot->m_worldPoint.x);
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY), trobot->m_worldPoint.y);
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ), trobot->m_worldPoint.z);
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV), trobot->m_worldPoint.v);
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW), trobot->m_worldPoint.w);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCurPosX_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s x=%0.2f?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.x); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX), trobot->m_worldPoint.x);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCurPosY_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s y=%0.2f?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.y); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY), trobot->m_worldPoint.y);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCurPosZ_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s z=%0.2f?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.z); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ), trobot->m_worldPoint.z);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCurPosV_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s v=%0.2f?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.v); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV), trobot->m_worldPoint.v);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCurPosW_Click(HBOX hBox)
{
	char str[512];
  float a,b,c,d,e;
  a = GetMPos(axis_a); //or DPos?
  b = GetMPos(axis_b); //or DPos?
  c = GetMPos(axis_c); //or DPos?
  d = GetMPos(axis_d); //or DPos?
  e = GetMPos(axis_e); //or DPos?
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  tmpnComputeFK((tmpnRobot*)trobot,a,b,c,d,e,0.0,trobot->m_tcpidx); //use tcp "zero"
	sprintf(str,"%s %s \"%s\" %s %s %d %s w=%0.2f?",getLanguageLineFromIdx(langptr, 115, "Do you want to set"),getLanguageLineFromIdx(langptr, 114, "Frame"),fixpointsFrameName,getLanguageLineFromIdx(langptr, 117,"with"),getLanguageLineFromIdx(langptr, 77,"TCP idx"),trobot->m_tcpidx,getLanguageLineFromIdx(langptr, 116,"to"),trobot->m_worldPoint.w); 
	if (BxMsgBox(hBox,str,getLanguageLineFromIdx(langptr, 118,"Warning"),0,getLanguageLineFromIdx(langptr, 74,"Ok"),getLanguageLineFromIdx(langptr, 3,"Cancel"))!=IDOK) return FALSE;
	BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW), trobot->m_worldPoint.w);
  return TRUE;
}

BX_BOOL formEditFrame_cmdCancel_Click(HBOX hBox)
{
  BxEndDialog(hBox, IDCANCEL);
  return TRUE;
}

BX_BOOL formEditFrame_cmdW_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDW), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEditFrame_cmdV_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDV), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEditFrame_cmdZ_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDZ), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEditFrame_cmdY_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDY), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

BX_BOOL formEditFrame_cmdX_Click(HBOX hBox)
{
  BxVirtNumBox_SetFloatValue(BxGetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX)));

  if(VirtNumKeyBox( hBox ) == IDOK)
  {
    BxSetFloatValue(BxGetDlgItem(hBox, FORMEDITFRAME_CMDX), BxVirtNumBox_GetFloatValue());
  }
  return TRUE;
}

