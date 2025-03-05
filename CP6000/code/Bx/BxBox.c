#include "BxPrivate.h"

BX_VOID Box_OnQuit(HBOX hbox, BX_INT exitCode){}
BX_BOOL Box_OnCreate(HBOX hbox);
BX_BOOL Box_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_INT Status);
BX_VOID Box_OnDestroy(HBOX hbox);
BX_VOID Box_OnEnable(HBOX hbox, BX_BOOL fEnable);
BX_VOID Box_OnSetText(HBOX hbox, BX_PSTRING lpszText);
BX_INT  Box_OnGetText(HBOX hbox, BX_INT cchTextMax, BX_PSTRING lpszText);
BX_INT  Box_OnGetTextLength(HBOX hbox);
BX_VOID Box_OnClose(HBOX hbox){}
BX_VOID Box_OnPaint(HBOX hbox);
BX_VOID Box_OnNCPaint(HBOX hbox, PRGN hrgn){}
BX_UINT Box_OnNCHitTest(HBOX hbox, BX_INT x, BX_INT y){ return 0;}
BX_VOID Box_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized){}

BX_VOID Box_OnSetFocus(HBOX hbox, HBOX hboxOldFocus) {};
BX_VOID Box_OnKillFocus(HBOX hbox, HBOX hboxNewFocus) {};
BX_VOID Box_OnKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags){}
BX_VOID Box_OnKeyUp(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags){}
BX_VOID Box_OnChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat){}
BX_VOID Box_OnDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat){}
BX_VOID Box_OnSysKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags){}
BX_VOID Box_OnSysKeyUp(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags){}
BX_VOID Box_OnSysChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat){}
BX_VOID Box_OnSysDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat){}
BX_VOID Box_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y);
BX_VOID Box_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
BX_VOID Box_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y);

BX_VOID Box_OnNCMouseMove(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest){}
BX_VOID Box_OnNCLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y, BX_UINT codeHitTest){}
BX_VOID Box_OnNCLButtonUp(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest){}
BX_INT  Box_OnMouseActivate(HBOX hbox, HBOX hboxTopLevel, BX_UINT codeHitTest, BX_UINT msg){ return 0;}
BX_VOID Box_OnCut(HBOX hbox){}
BX_VOID Box_OnClear(HBOX hbox);

BX_BOOL Box_OnSetCursor(HBOX hbox, HBOX hboxCursor, BX_UINT codeHitTest, BX_UINT msg){ return TRUE;}
BX_VOID Box_OnSysCommand(HBOX hbox, BX_UINT cmd, BX_INT x, BX_INT y)			   {}

CLASSDEF BOX_CLASS = {
	Box_OnQuit,
	Box_OnCreate,
	Box_OnShowBox,
	Box_OnDestroy,
	Box_OnEnable,
	Box_OnSetText,
	Box_OnGetText,
	Box_OnGetTextLength,
	Box_OnClose,
	Box_OnPaint,
	Box_OnNCPaint,
	Box_OnNCHitTest,
	Box_OnActivate,
	Box_OnSetFocus,
	Box_OnKillFocus,
	Box_OnKeyDown,
	Box_OnKeyUp,
	Box_OnChar,
	Box_OnDeadChar,
	Box_OnSysKeyDown,
	Box_OnSysKeyUp,
	Box_OnSysChar,
	Box_OnSysDeadChar,
	Box_OnMouseMove,
	Box_OnLButtonDown,
	Box_OnLButtonUp,
	Box_OnNCMouseMove,
	Box_OnNCLButtonDown,
	Box_OnNCLButtonUp,
	Box_OnMouseActivate,
	Box_OnCut,
	Box_OnClear,
	Box_OnSetCursor,
	Box_OnSysCommand,
};

PCLASS hCls_DefBox = &BOX_CLASS;


BX_VOID Box_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
	BX_INT i;
	BX_RECT tRc, rc;

  rc.top = b->rc.top + 1;
  rc.bottom = b->rc.bottom - 4;
  rc.left = b->rc.left + 2;
  rc.right = b->rc.right - 1;
  BxUpdateOff();
  b->m_Dirty = FALSE;
  ShowCursor(FALSE);
  if(b->style & BXS_VISIBLE)
  {
    if(b->style & BXS_POPUP)
    {

      BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
      BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxSetRect(&tRc, 
        b->rc.left+BxRectWidth(&b->rc)/2, 
        b->rc.top+(BxRectHeight(&b->rc)/2)-2, 
        b->rc.right-BxRectWidth(&b->rc)/2, 
        b->rc.bottom-(BxRectHeight(&b->rc)/2)+2); 
			for(i=0;i<BxRectWidth(&b->rc)/2;i+=16)
		  {
				BxRectangle(&b->m_BxDC, &tRc);
				BxSleep(10);
				tRc.left-=16;
				tRc.right+=16;
			}
			tRc.left = b->rc.left;
			tRc.right = b->rc.right;
			for(i=4;i<BxRectHeight(&b->rc)/2;i+=16)
		  {
				BxRectangle(&b->m_BxDC, &tRc);
				BxSleep(10);
				tRc.top-=16;
				tRc.bottom+=16;
			}

			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_POPUPBOX]);
			BxRectangle(&b->m_BxDC, &b->rc);
		}
		else
		{
			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
      BxRoundRect(&b->m_BxDC, &b->rc, 5);
//			BxRectangle(&b->m_BxDC, &b->rc);
//		  BxFrame(&b->m_BxDC, &rc, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER], BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);

			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_CAPTIONTEXT]);
			BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
      if(b->lpBoxStr!=NULL)
        BxTextOut(&b->m_BxDC, b->rc.left+2, b->rc.top+10, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], BxStringLength(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]));
		}

//  m_CaptionDirty = FALSE;
	}
	else
	{
		BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxRoundRect(&b->m_BxDC, &b->rc, 5);
//		BxRectangle(&b->m_BxDC, &b->rc);
	}
	ShowCursor(TRUE);
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}

BX_VOID Box_OnClear(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
	BX_INT i;
	BX_RECT tRc, cRc;

  b->m_Dirty = FALSE;

	ShowCursor(FALSE);

	if(b->style & BXS_POPUP)
	{

		BxSetRect(&tRc, b->rc.left, b->rc.top, b->rc.right, b->rc.bottom);
		BxCopyRect(&cRc, &tRc);
		for(i=BxRectHeight(&b->rc)/2;i>=4; i-=16)
		{
			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxRectangle(&b->m_BxDC, &tRc);
			BxSleep(10);
			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxRectangle(&b->m_BxDC, &cRc);
			tRc.top+=16;
			tRc.bottom-=16;
			BxCopyRect(&cRc, &tRc);
		}
		BxSetRect(&tRc, b->rc.left, b->rc.top+(BxRectHeight(&b->rc)/2)-2, b->rc.right, b->rc.bottom-(BxRectHeight(&b->rc)/2)+2); 
		BxCopyRect(&cRc, &tRc);

		for(i=BxRectWidth(&b->rc)/2;i>0; i-=16)
	  {
			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxRectangle(&b->m_BxDC, &tRc);
			BxSleep(10);
			BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
			BxRectangle(&b->m_BxDC, &cRc);
			tRc.left+=16;
			tRc.right-=16;
			BxCopyRect(&cRc, &tRc);
		}

		BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxRectangle(&b->m_BxDC, &b->rc);
	}
	else
	{
		BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxRoundRect(&b->m_BxDC, &b->rc, 10);
//		BxRectangle(&b->m_BxDC, &b->rc);
	}
	ShowCursor(TRUE);
  BxSetDirtyArea(&b->rc);
}


BX_BOOL Box_OnCreate(HBOX hbox)
{
  BOXSTRUCT *b = hbox;

  b->boxState |= BA_INACTIVE;
/*
  if(b->style & BXS_CENTER)
  {
    if(b->bParent != NULL)
    {
      tRect.SetRect(rect.left,rect.top,rect.right,rect.bottom);
      pParent->GetBoxRect(&bRect);
      
      rect.left = bRect.left+(bRect.Width()/2)-tRect.Width()/2;
      rect.right = rect.left + tRect.Width();
      rect.top = bRect.top+(bRect.Height()/2)-tRect.Height()/2;
      rect.bottom = rect.top + tRect.Height();
    }
  }
*/
  return (TRUE);
}

BX_VOID Box_OnEnable(HBOX hbox, BX_BOOL fEnable)
{
  BOXSTRUCT *b = hbox;
	BX_BOOL prevState;

	if(b->style & BXS_DISABLED)
		prevState = FALSE;
	else
		prevState = TRUE;


	if(fEnable==TRUE)
  {
		if(prevState == FALSE)
      b->style &= ~BXS_DISABLED;
  }
	else
    b->style |= BXS_DISABLED;

  if(prevState != fEnable)
    BxRequestPaint(hbox);
}

BX_BOOL Box_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_INT Status)
{
  BOXSTRUCT *b = hbox;
	BX_BOOL prevState;

	if(b->style & BXS_VISIBLE)
		prevState = TRUE;
	else
		prevState = FALSE;

	if(fShow==TRUE)
		b->style |= BXS_VISIBLE;
	else
  {
		if(prevState == TRUE)
      b->style &= ~BXS_VISIBLE;
  }


  if(prevState != fShow)
    BxRequestPaint(hbox);

	return prevState;
}


BX_VOID Box_OnSetText(HBOX hbox, BX_PSTRING lpszText)
{
  BOXSTRUCT *b = hbox;
	
  if(lpszText!=NULL)
  {
    if( BxStringCompare(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], lpszText) != 0)
    {
      BxStringCopy(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], lpszText);
	    BxRequestPaint(hbox);
    }
  }
}

BX_INT  Box_OnGetText(HBOX hbox, BX_INT cchTextMax, BX_PSTRING lpszText)
{
  BOXSTRUCT *b = hbox;

  if (lpszText!=NULL)
  {
    BxStringNCopy(lpszText, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], cchTextMax);
  }
  return BxStringLength(lpszText);
}

BX_INT  Box_OnGetTextLength(HBOX hbox)
{ 
  BOXSTRUCT *b = hbox;

  return BxStringLength(b->lpBoxStr);
}

BX_VOID Box_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y)
{
/*
	if(BXACTIVEBOX != hbox)
	{
	    BxSendMessage(BXACTIVEBOX, BM_ACTIVATE, MAKEWPARAM(BA_INACTIVE, 0), (BX_LPARAM)hbox);
		BXACTIVEBOX = hbox;
	}
*/
}



BX_VOID Box_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y)
{
/*
	if(BXACTIVEBOX != hbox)
	{
    if(BXACTIVEBOX != NULL)
		  BxSendMessage(ACTIVEBOX, BM_ACTIVATE, MAKEWPARAM(BA_INACTIVE, 0), (BX_LPARAM)hbox);
		BxSendMessage(hbox, BM_ACTIVATE, MAKEWPARAM(BA_CLICKACTIVE, 0), (BX_LPARAM)ACTIVEBOX);
    ACTIVEBOX = hbox;
	}
	else
	{
		BxSendMessage(hbox, BM_ACTIVATE, MAKEWPARAM(BA_CLICKACTIVE, 0), (BX_LPARAM)NULL);
	}
*/
}

#include "BxUser.h"
BX_VOID Box_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y)
{
  //to switch switch active when e.g. button pressed and mouse moved to form
  //e.g. used by formManualXXXUser.c to reset activated button
	BOXSTRUCT *b = hbox;
  
	if(b->style & BXS_DISABLED || b->userLevel > BxGetUserLevel() )
		return;
  
	BxSetFocus(hbox);
	SetActiveBox(hbox, TRUE);
}

BX_VOID Box_OnDestroy(HBOX hBox)
{
}
