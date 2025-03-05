#include "BxPrivate.h"

BX_BOOL CheckBox_OnCreate(HBOX hbox);
BX_VOID CheckBox_OnPaint(HBOX hbox);
BX_VOID CheckBox_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized);

BX_VOID CheckBox_OnKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);

BX_VOID CheckBox_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
BX_VOID CheckBox_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y);



CLASSDEF CHECKBOX_CLASS = {
	Box_OnQuit,
	CheckBox_OnCreate,
	Box_OnShowBox,
	Box_OnDestroy,
	Box_OnEnable,
	Box_OnSetText,
	Box_OnGetText,
	Box_OnGetTextLength,
	Box_OnClose,
	CheckBox_OnPaint,
	Box_OnNCPaint,
	Box_OnNCHitTest,
	CheckBox_OnActivate,
	Box_OnSetFocus,
	Box_OnKillFocus,
	CheckBox_OnKeyDown,
	Box_OnKeyUp,
	Box_OnChar,
	Box_OnDeadChar,
	Box_OnSysKeyDown,
	Box_OnSysKeyUp,
	Box_OnSysChar,
	Box_OnSysDeadChar,
	Box_OnMouseMove,
	CheckBox_OnLButtonDown,
	CheckBox_OnLButtonUp,
	Box_OnNCMouseMove,
	Box_OnNCLButtonDown,
	Box_OnNCLButtonUp,
	Box_OnMouseActivate,
	Box_OnCut,
	Box_OnClear,
	Box_OnSetCursor,
	Box_OnSysCommand,
};

PCLASS hCls_CheckBox = &CHECKBOX_CLASS;

BX_VOID CheckBox_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized)
{
  BOXSTRUCT *b = hbox;

	b->boxState &= 0xFE0F;

	switch(state) {
		case BA_ACTIVE:
			b->boxState |= BA_ACTIVE;
			break;
		case BA_INACTIVE:
			b->boxState |= BA_INACTIVE;
			break;
		case BA_CLICKACTIVE:
			b->boxState |= BA_CLICKACTIVE;
			break;
	}
  BxRequestPaint(hbox);
}

  
BX_VOID RadioBox_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
	BX_RECT m_ChkRc, m_textRc;
	BX_PSTRING m_Text = &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN];

  b->m_Dirty = FALSE;
  BxUpdateOff();

  BxSetRect(&m_ChkRc, b->rc.left, b->rc.top, b->rc.left+32, b->rc.top+32);
  BxSetRect(&m_textRc, m_ChkRc.right+5,b->rc.top, b->rc.right, b->rc.bottom);

  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
    case BA_INACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    case BA_ACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    case BA_CLICKACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    }
  }
  else
  {
    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxRectangle(&b->m_BxDC, &b->rc);
  }
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}

BX_VOID CheckBox_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
	BX_RECT m_ChkRc, m_textRc;
	BX_PSTRING m_Text = &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN];

	if(b->style & BBS_RADIOBOX)
	{
		RadioBox_OnPaint(hbox);
		return;
	}

  b->m_Dirty = FALSE;

  BxSetRect(&m_ChkRc, b->rc.left, b->rc.top, b->rc.left+32, b->rc.top+32);
  BxSetRect(&m_textRc, m_ChkRc.right+5,b->rc.top, b->rc.right, b->rc.bottom);

  BxUpdateOff();

  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
    case BA_INACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    case BA_ACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
//      SetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    case BA_CLICKACTIVE:
      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
      if(BxGetCheck(hbox))
        BxSetBrush(&b->m_BxDC, BX_RGB(0x00,0xff,0x00));
      else
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
//      SetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);
      BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
      BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 4);
//      BxRectangle(&b->m_BxDC, &b->rc);
      BxDrawText(&b->m_BxDC, m_Text, strlen(m_Text), &b->rc, DT_VCENTER | DT_CENTER);
      break;
    }
  }
  else
  {
    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxRectangle(&b->m_BxDC, &b->rc);
  }
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}


BX_VOID CheckBox_OnKeyDown(HBOX hbox, BX_UINT vChar, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags)
{
	PBOXSTRUCT pBx = (PBOXSTRUCT)hbox;

  switch(vChar){
  case VK_RETURN:
    if(pBx->userLevel <= BxGetUserLevel())
    {
		  if(pBx->style & BBS_CHECKBOX)
		  {
			  if(BxGetCheck(hbox))
				  BxSetCheck(hbox, FALSE);
			  else
				  BxSetCheck(hbox, TRUE);
		  }
		  if(pBx->style & BBS_RADIOBOX)
			  BxSetCheck(hbox, TRUE);
		  
      BxRequestPaint(hbox);
      BxPostMessage(BxGetParent(hbox), BM_COMMAND, BX_MAKEWPARAM(pBx->ID, 0), (BX_LPARAM)hbox);
//      BxUpdateView(GetParent(hbox));
    }
    break;
  default:
    Button_OnKeyDown(hbox, vChar, fDown, cRepeat, flags);
  }
}


BX_BOOL CheckBox_OnCreate(HBOX hbox)
{
  BOXSTRUCT *b = hbox;

  b->boxState |= BA_INACTIVE;

  return (TRUE);
}


BX_VOID CheckBox_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y)
{
/*
	if(ACTIVEBOX != hbox)
	{
		if(Button_GetState(hbox) & BST_PUSHED)
		{
			BxSendMessage(ACTIVEBOX, BM_ACTIVATE, MAKEWPARAM(BA_INACTIVE, 0), (BX_LPARAM)hbox);
			BxSendMessage(hbox, BM_ACTIVATE, MAKEWPARAM(BA_ACTIVE, 0), (BX_LPARAM)NULL);
			ACTIVEBOX = hbox;
		}
	}
*/
}

BX_VOID CheckBox_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y)
{
  BOXSTRUCT *b = hbox;

  if(b->style & BXS_DISABLED || b->userLevel > BxGetUserLevel() )
    return;

  BxSetFocus(hbox);
  SetActiveBox(hbox, TRUE);
}


BX_VOID CheckBox_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y)
{
  BOXSTRUCT *pBx = hbox;

  if(pBx->style & BXS_DISABLED || pBx->userLevel > BxGetUserLevel() )
    return;

 	if(pBx->style & BBS_CHECKBOX)
	{
		if(BxGetCheck(hbox))
			BxSetCheck(hbox, FALSE);
		else
			BxSetCheck(hbox, TRUE);
	}
	if(pBx->style & BBS_RADIOBOX)
		BxSetCheck(hbox, TRUE);

	BxRequestPaint(hbox);
  BxPostMessage(BxGetParent(hbox), BM_COMMAND, BX_MAKEWPARAM(pBx->ID, 0), (BX_LPARAM)hbox);
//  BxUpdateView(GetParent(hbox));
}
