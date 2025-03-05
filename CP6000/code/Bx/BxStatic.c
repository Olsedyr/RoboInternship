#include "BxPrivate.h"

//BX_VOID Static_OnEnable(HBOX hbox, BX_BOOL fEnable) { Static_Enable(hbox, fEnable);}
BX_VOID Static_OnPaint(HBOX hbox);
BX_VOID Static_OnDestroy(HBOX hbox);

CLASSDEF STATIC_CLASS = {
	Box_OnQuit,
	Box_OnCreate,
  Box_OnShowBox,
  	Static_OnDestroy,
	Box_OnEnable,
	Box_OnSetText,
	Box_OnGetText,
	Box_OnGetTextLength,
	Box_OnClose,
	Static_OnPaint,
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

PCLASS hCls_Static = &STATIC_CLASS;

BX_LRESULT DefStaticProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
  BX_PVOID old;

  switch (uMsg)
  {
  case BSTM_SETICON		: 
    old = ((PBOXSTRUCT)hBox)->m_image;
    ((PBOXSTRUCT)hBox)->m_image = (BX_PVOID)wParam;
    ((PBOXSTRUCT)hBox)->style &= ~BSS_TYPEMASK;
    ((PBOXSTRUCT)hBox)->style |= BSS_ICON;
    return (BX_LRESULT)(BX_PICON)old;
    break;
  case BSTM_GETICON		: 
    return (BX_LRESULT)(BX_PICON)((PBOXSTRUCT)hBox)->m_image;
    break;
  case BSTM_SETIMAGE	: 
    old = ((PBOXSTRUCT)hBox)->m_image;
    ((PBOXSTRUCT)hBox)->m_image = (BX_PVOID)wParam;
    ((PBOXSTRUCT)hBox)->style &= ~BSS_TYPEMASK;
    ((PBOXSTRUCT)hBox)->style |= BSS_BITMAP;
    return (BX_LRESULT)(BX_PBITMAP)old;
    break;
  case BSTM_GETIMAGE	: 
    return (BX_LRESULT)(BX_PBITMAP)((PBOXSTRUCT)hBox)->m_image;
    break;
  default:
    return( DefBoxProc( hBox, uMsg, wParam, lParam ) ) ;
  }
  return 0L ;
}


BX_VOID Static_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
  BX_RECT m_txtRect;
  BX_RECT m_opdRect;

  b->m_Dirty = FALSE;

  BxCopyRect(&m_opdRect, &b->rc);
  
  switch(b->style & BSS_TYPEMASK) {
  case BSS_WHITEFRAME:
    m_txtRect.left = b->rc.left;
    m_txtRect.right = b->rc.right;
    m_txtRect.bottom = b->rc.top+20;
    m_opdRect.top = m_txtRect.top = b->rc.top;
    m_opdRect.left = b->rc.left-1;
    m_opdRect.right = b->rc.right+1;
    m_opdRect.bottom  = b->rc.bottom+1;
    break;
  default:
    m_txtRect.left = b->rc.left+2;
    m_txtRect.top = b->rc.top;
    m_txtRect.right = b->rc.right-2;
    m_txtRect.bottom = b->rc.bottom;
  }

  BxUpdateOff();
  
  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
    case BA_INACTIVE:
      switch(b->style & BSS_TYPEMASK) {
      case BSS_WHITEFRAME:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
        BxRoundRect(&b->m_BxDC, &b->rc, 10);
//        BxFrame(&b->m_BxDC, &b->rc, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER], BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxRectangle(&b->m_BxDC, &m_txtRect);
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_MENUTEXT]);
          BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        }
        break;
      case BSS_OWNERDRAW:
        BxRectangle(&b->m_BxDC, &b->rc);
        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
        {
          BxRectangle(&b->m_BxDC, &m_txtRect);
          BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        }
        break;
      case BSS_ICON:
        if(b->m_image)
          BxDrawIcon(&b->m_BxDC, b->rc.left, b->rc.top, (BX_PICON)b->m_image);
        break;
      case BSS_BITMAP:
        if(b->m_image)
          BxDrawBitmap(&b->m_BxDC, b->rc.left, b->rc.top, (BX_PBITMAP)b->m_image, BITMAPTYPE_SOLID);
        break;
      case BSS_RIGHT:
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
          BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_RIGHT);
        break;
      case BSS_CENTER:
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
          BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_CENTER);
        break;
      case BSS_USERITEM:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
        BxRectangle(&b->m_BxDC, &b->rc);
        BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_MENUTEXT]);
        BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
        BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        break;
      default:
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
        {
          if(b->style & BSS_CENTER)
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_CENTER);
          else
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        }
      }
      break;
    case BA_ACTIVE:
      switch(b->style & BSS_TYPEMASK) {
      case BSS_USERITEM:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_HIGHLIGHT]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_HIGHLIGHT]);
        BxRectangle(&b->m_BxDC, &b->rc);
        BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNHIGHLIGHT]);
        BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_HIGHLIGHT]);
        BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        break;
      case BSS_ICON:
        if(b->m_image)
          BxDrawIcon(&b->m_BxDC, b->rc.left, b->rc.top, (BX_PICON)b->m_image);
        break;
      case BSS_BITMAP:
        if(b->m_image)
          BxDrawBitmap(&b->m_BxDC, b->rc.left, b->rc.top, (BX_PBITMAP)b->m_image, BITMAPTYPE_SOLID);
        break;
      default:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
        BxRectangle(&b->m_BxDC, &b->rc);
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
        {
          if(b->style & BSS_CENTER)
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_CENTER);
          else
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        }
        break;
      }
      break;
    case BA_CLICKACTIVE:
      switch(b->style & BSS_TYPEMASK) {
      case BSS_USERITEM:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxRectangle(&b->m_BxDC, &b->rc);
        BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_MENUTEXT]);
        BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER);
        break;
      default:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
        BxRectangle(&b->m_BxDC, &b->rc);
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]!=NULL)
        {
          if(b->style & BSS_CENTER)
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_CENTER);
          else
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER);
        }
        break;
      }
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
  BxSetDirtyArea(&m_opdRect);
}

BX_VOID Static_OnDestroy(HBOX hBox)
{
  if((((PBOXSTRUCT)hBox)->style & BSS_TYPEMASK) == BSS_ICON)
    BxDeleteIcon((BxIcon*)((PBOXSTRUCT)hBox)->m_image);
  if((((PBOXSTRUCT)hBox)->style & BSS_TYPEMASK) == BSS_BITMAP)
    BxDeleteBitmap((BxBitmap*)((PBOXSTRUCT)hBox)->m_image);
}
