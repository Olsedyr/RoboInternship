#include "Bx.h"
#include "BxPrivate.h"

#define MINBARSIZE 4.0

BX_VOID BxScrollBar_Destroy( HBOX hbox);
char *inc = "";
char *dec = "";
char bar[10];

static BX_VOID adjust_SlideBar_position(HBOX hBox, BX_WORD x, BX_WORD y)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
	// BOXSTRUCT *b = (BOXSTRUCT *)hBox;
  int BarSize = (int)pBxBar->m_StepSize;

  if(pBxBar->m_Style & BSB_HORIZONTAL)
  {
    if(x >= pBxBar->m_SlideRect.left && x <= pBxBar->m_SlideRect.right)
    {

      if(BarSize < BxRectWidth(&pBxBar->m_SlideRect)/MINBARSIZE) BarSize = BxRectWidth(&pBxBar->m_SlideRect)/MINBARSIZE;

      pBxBar->m_SlideBarRect.left += (x-pBxBar->m_oldP.x);

      pBxBar->m_oldP.x = x;
      pBxBar->m_oldP.y = y;
 
      if(pBxBar->m_SlideBarRect.left < pBxBar->m_SlideRect.left)
        pBxBar->m_SlideBarRect.left = pBxBar->m_SlideRect.left;

      if(pBxBar->m_SlideBarRect.left + (unsigned short)BarSize > pBxBar->m_SlideRect.right)
        pBxBar->m_SlideBarRect.left = pBxBar->m_SlideRect.right - (unsigned short)BarSize;

      pBxBar->m_SlideBarRect.right = pBxBar->m_SlideBarRect.left + (unsigned short)BarSize;
  
      pBxBar->m_Pos = (int)((double)(pBxBar->m_Upper - pBxBar->m_Lower) * ((double)(pBxBar->m_SlideBarRect.left - pBxBar->m_SlideRect.left)/(double)(BxRectWidth(&pBxBar->m_SlideRect)-BarSize)));
    }
  }
  else
  {
    if(y >= pBxBar->m_SlideRect.top && y <= pBxBar->m_SlideRect.bottom)
    {

      if(BarSize < BxRectHeight(&pBxBar->m_SlideRect)/MINBARSIZE) BarSize = BxRectHeight(&pBxBar->m_SlideRect)/MINBARSIZE;

      pBxBar->m_SlideBarRect.top += (y-pBxBar->m_oldP.y);

      pBxBar->m_oldP.x = x;
      pBxBar->m_oldP.y = y;
 
      if(pBxBar->m_SlideBarRect.top < pBxBar->m_SlideRect.top)
        pBxBar->m_SlideBarRect.top = pBxBar->m_SlideRect.top;

      if(pBxBar->m_SlideBarRect.top + (unsigned short)BarSize > pBxBar->m_SlideRect.bottom)
        pBxBar->m_SlideBarRect.top = pBxBar->m_SlideRect.bottom - (unsigned short)BarSize;

      pBxBar->m_SlideBarRect.bottom = pBxBar->m_SlideBarRect.top + (unsigned short)BarSize;
  
      pBxBar->m_Pos = (int)((double)(pBxBar->m_Upper - pBxBar->m_Lower) * ((double)(pBxBar->m_SlideBarRect.top - pBxBar->m_SlideRect.top)/(double)(BxRectHeight(&pBxBar->m_SlideRect)-BarSize)));
    }
  }

  if(pBxBar->m_Bar.lpBoxStr != NULL)
  {
    sprintf(pBxBar->m_Bar.lpBoxStr, "%d", pBxBar->m_Pos);
  }
  pBxBar->m_oldP.x = x;
  pBxBar->m_oldP.y = y;

  BxRequestPaint(&pBxBar->m_Bar);
}

static BX_VOID update_SlideBar(HBOX hBox)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
  //BOXSTRUCT *b = (BOXSTRUCT *)hBox;
  int BarSize = (int)pBxBar->m_StepSize;

  if(pBxBar->m_Style & BSB_HORIZONTAL)
  {
    if(BarSize < BxRectWidth(&pBxBar->m_SlideRect)/MINBARSIZE) BarSize = BxRectWidth(&pBxBar->m_SlideRect)/MINBARSIZE;
  
    pBxBar->m_SlideBarRect.left = pBxBar->m_SlideRect.left + (unsigned short)((double)pBxBar->m_Pos * ((double)BxRectWidth( &pBxBar->m_SlideRect )-BarSize)/(double)(pBxBar->m_Upper - pBxBar->m_Lower));

    if(pBxBar->m_SlideBarRect.left + (unsigned short)BarSize > pBxBar->m_SlideRect.right)
      pBxBar->m_SlideBarRect.left = pBxBar->m_SlideRect.right - (unsigned short)BarSize;

    pBxBar->m_SlideBarRect.right = pBxBar->m_SlideBarRect.left + BarSize;
  }
  else
  {
    if(BarSize < BxRectHeight(&pBxBar->m_SlideRect)/MINBARSIZE) BarSize = BxRectHeight(&pBxBar->m_SlideRect)/MINBARSIZE;
  
    pBxBar->m_SlideBarRect.top = pBxBar->m_SlideRect.top + (unsigned short)((double)pBxBar->m_Pos * ((double)BxRectHeight( &pBxBar->m_SlideRect )-BarSize)/(double)(pBxBar->m_Upper - pBxBar->m_Lower));

    if(pBxBar->m_SlideBarRect.top + (unsigned short)BarSize > pBxBar->m_SlideRect.bottom)
      pBxBar->m_SlideBarRect.top = pBxBar->m_SlideRect.bottom - (unsigned short)BarSize;

    pBxBar->m_SlideBarRect.bottom = pBxBar->m_SlideBarRect.top + BarSize;
  }
  
  if(pBxBar->m_Bar.lpBoxStr != NULL)
  {
    sprintf(pBxBar->m_Bar.lpBoxStr, "%d", pBxBar->m_Pos);
  }

  BxRequestPaint(&pBxBar->m_Bar);
}

static BX_VOID BxScrollBar_Paint( HBOX hbox)
{
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;
  BxDC* pDC;
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)m_Bar->m_userData;
  BX_RECT m_txtRect, shadowRc;

  pDC = BxGetBoxDC(&pBxBar->m_Bar);

  BxRoundRect(pDC, &pBxBar->m_SlideRect, 4);

  if(m_Bar->style & BXS_VISIBLE)
  {
    BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
//    BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
    BxSetBrush(pDC, BX_RGB(0xd0, 0xd0, 0xd0));
    BxRoundRect(pDC, &pBxBar->m_SlideRect, 4);

    BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
    BxSetBrush(pDC, BX_RGB(0x7f, 0x7f, 0x7f));
    //  BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
    //  BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
    BxRoundRect(pDC, &pBxBar->m_SlideBarRect, 4);

    shadowRc.left = pBxBar->m_SlideBarRect.left + 1;
    shadowRc.top = pBxBar->m_SlideBarRect.top;
    shadowRc.right = pBxBar->m_SlideBarRect.right;
    shadowRc.bottom = pBxBar->m_SlideBarRect.bottom - 1;
  
    BxSetPen(pDC, BX_RGB(0xff, 0xff, 0xff));
    //  BxSetBrush(pDC, BX_RGB(0x7f, 0x7f, 0x7f));
    //  BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
    BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
    BxRoundRect(pDC, &shadowRc, 4);

    shadowRc.left = pBxBar->m_SlideBarRect.left + 2;
    shadowRc.top = pBxBar->m_SlideBarRect.top + 2;
    shadowRc.right = pBxBar->m_SlideBarRect.right - 2;
    shadowRc.bottom = pBxBar->m_SlideBarRect.bottom - 2;

    switch(m_Bar->boxState & BBS_STATEMASK) {
      case BA_INACTIVE:
           //  BxSetPen(pDC, BX_RGB(0xff, 0xff, 0xff));
           //  BxSetBrush(pDC, BX_RGB(0x7f, 0x7f, 0x7f));
           BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
           BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
           BxRoundRect(pDC, &shadowRc, 4);

           if(!(pBxBar->m_Style & BSB_NOCAPTION))
           {
             m_txtRect.left = pBxBar->m_SlideRect.left+2;
             m_txtRect.top = pBxBar->m_SlideRect.top;
             m_txtRect.right = pBxBar->m_SlideRect.right-2;
             m_txtRect.bottom = pBxBar->m_SlideRect.bottom;
             BxDrawText(pDC, pBxBar->m_Bar.lpBoxStr, BxStringLength(pBxBar->m_Bar.lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
           }
           break;
	  case BA_ACTIVE:
           BxSetPen(pDC, BX_RGB(0x0, 0x0, 0x0));
           BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
           BxRoundRect(pDC, &shadowRc, 4);

           if(!(pBxBar->m_Style & BSB_NOCAPTION))
           {
             m_txtRect.left = pBxBar->m_SlideRect.left+2;
             m_txtRect.top = pBxBar->m_SlideRect.top;
             m_txtRect.right = pBxBar->m_SlideRect.right-2;
             m_txtRect.bottom = pBxBar->m_SlideRect.bottom;
             BxDrawText(pDC, pBxBar->m_Bar.lpBoxStr, BxStringLength(pBxBar->m_Bar.lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
           }
           break;
      case BA_CLICKACTIVE:     
           BxSetPen(pDC, BX_RGB(0x0, 0x0, 0x0));
           BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
           BxRoundRect(pDC, &shadowRc, 4);

           if(!(pBxBar->m_Style & BSB_NOCAPTION))
           {
             m_txtRect.left = pBxBar->m_SlideRect.left+2;
             m_txtRect.top = pBxBar->m_SlideRect.top;
             m_txtRect.right = pBxBar->m_SlideRect.right-2;
             m_txtRect.bottom = pBxBar->m_SlideRect.bottom;
             BxDrawText(pDC, pBxBar->m_Bar.lpBoxStr, BxStringLength(pBxBar->m_Bar.lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
           }
    }
  }
  m_Bar->m_Dirty = FALSE;
  BxSetDirtyArea(&m_Bar->rc);
}



BX_LRESULT DefScrollSlideBarProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
  BOXSTRUCT *b = (BOXSTRUCT *)hBox;

  switch (uMsg)
	{
	case BM_LBUTTONDOWN		:
      pBxBar->m_oldP.x =  BX_LOWORD(lParam);
      pBxBar->m_oldP.y =  BX_HIWORD(lParam);
        
	  DefPushButtonProc( hBox, uMsg, wParam, lParam ) ;
    break;
	case BM_MOUSEMOVE		:
      adjust_SlideBar_position(hBox, BX_LOWORD(lParam), BX_HIWORD(lParam));
      BxSendMessage(b->bParent->bParent, BM_VSCROLL , BX_MAKELONG(BSB_THUMBPOSITION, pBxBar->m_Pos), (BX_LPARAM)hBox);
    break;
	case BM_PAINT		:
      BxUpdateOff();
      BxScrollBar_Paint( hBox );
      BxUpdateOn();

    break;
	default:
			 return( DefPushButtonProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_LRESULT DefScrollIncProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	switch (uMsg)
	{
	default:
			 return( DefPushButtonProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_LRESULT DefScrollDecProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	switch (uMsg)
	{
	default:
			 return( DefPushButtonProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_LRESULT DefScrollBarProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
  BOXSTRUCT *b = (BOXSTRUCT *)hBox;
  BX_WORD cmd;

	switch (uMsg)
	{
    case BM_COMMAND:
    {
      cmd = BX_LOWORD(wParam) - b->ID;
      switch(cmd)
      {
      case 1000: // Inc
        if(pBxBar->m_Pos > pBxBar->m_Lower)
        {
          pBxBar->m_Pos -= pBxBar->m_Step;
          update_SlideBar(hBox);
          BxSendMessage(b->bParent, BM_VSCROLL , BX_MAKELONG(BSB_LINEUP, pBxBar->m_Pos), (BX_LPARAM)hBox);
          BxPostMessage(BxGetParent(hBox), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)hBox)->ID, 0), (BX_LPARAM)hBox);
//          BxUpdateView(GetParent(hBox));
        }
        break;
      case 1001: // Bar
        BxPostMessage(BxGetParent(hBox), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)hBox)->ID, 0), (BX_LPARAM)hBox);
//        BxUpdateView(GetParent(hBox));
        break;
      case 1002: // Dec
        if(pBxBar->m_Pos < pBxBar->m_Upper)
        {
          pBxBar->m_Pos += pBxBar->m_Step;
          update_SlideBar(hBox);
          BxSendMessage(b->bParent, BM_VSCROLL , BX_MAKELONG(BSB_LINEDOWN, pBxBar->m_Pos), (BX_LPARAM)hBox);
          BxPostMessage(BxGetParent(hBox), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)hBox)->ID, 0), (BX_LPARAM)hBox);
//          BxUpdateView(GetParent(hBox));
        }
        break;
      }
    }
    break;
	case BM_DESTROY	: 
    BxScrollBar_Destroy( hBox );
    break;
	default:
			 return( DefStaticProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_BOOL BxScrollBar_Create( HBOX hBox, BXSCROLLBARSTRUCT *pBxSBar, BX_DWORD Style)
{
  BxDC* pDC;
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hBox;

  if(pBxSBar==NULL)
		return FALSE;

  if(hBox==NULL)
		return FALSE;

  pBxSBar->m_Pos = pBxSBar->m_Lower = 0;
  pBxSBar->m_Upper = 1;
  pBxSBar->m_Step = 1;
  pBxSBar->m_StepSize = 1.0;
  pBxSBar->m_Style = Style;

  pBxSBar->hBx = hBox;

  pBxSBar->m_Inc.ID         = 1000 + m_Bar->ID;
  if(pBxSBar->m_Style & BSB_HORIZONTAL)
  {
    pBxSBar->m_Inc.rc.left    = m_Bar->rc.left   + 1;
    pBxSBar->m_Inc.rc.top     = m_Bar->rc.top    + 1;
    pBxSBar->m_Inc.rc.right   = m_Bar->rc.left  + (unsigned short)((double)BxRectWidth( &m_Bar->rc )*0.10);
    pBxSBar->m_Inc.rc.bottom  = m_Bar->rc.bottom  - 1;
  }
  else
  {
    pBxSBar->m_Inc.rc.left    = m_Bar->rc.left   + 1;
    pBxSBar->m_Inc.rc.top     = m_Bar->rc.top    + 1;
    pBxSBar->m_Inc.rc.right   = m_Bar->rc.right  - 1;
    pBxSBar->m_Inc.rc.bottom  = pBxSBar->m_Inc.rc.top + (unsigned short)((double)BxRectHeight( &m_Bar->rc )*0.20);
  }
  pBxSBar->m_Inc.type       = BUTTON;
  pBxSBar->m_Inc.lpBoxStr   = dec;

  pBxSBar->m_Inc.style      = BBS_BITMAP | BBS_PUSHBUTTON | BXS_VISIBLE;
  pBxSBar->m_Inc.bNext      = &pBxSBar->m_Bar;
//  pBxSBar->m_Inc.bParent    = m_Bar->bParent;
  pBxSBar->m_Inc.bParent    = m_Bar;
  pBxSBar->m_Inc.userLevel  = m_Bar->userLevel;

  BxCreateBox(GetAppInstance(hBox), &pBxSBar->m_Inc, DefScrollIncProc);
  if(pBxSBar->m_Style & BSB_HORIZONTAL)
    BxSendMessage(&pBxSBar->m_Inc, BBM_SETBITMAP, (BX_WPARAM)BxSystemResourceLoadBxBitmap(20), 0);
  else
    BxSendMessage(&pBxSBar->m_Inc, BBM_SETBITMAP, (BX_WPARAM)BxSystemResourceLoadBxBitmap(22), 0);
  
  pBxSBar->m_Bar.ID         = 1001 + m_Bar->ID;
  if(pBxSBar->m_Style & BSB_HORIZONTAL)
  {
    pBxSBar->m_Bar.rc.left    = pBxSBar->m_Inc.rc.right + 1;
    pBxSBar->m_Bar.rc.top     = m_Bar->rc.top  + 1; 
//    pBxSBar->m_Bar.rc.right   = m_Bar->rc.right  - 1;
    pBxSBar->m_Bar.rc.bottom  = m_Bar->rc.bottom  - 1;
  }
  else
  {
    pBxSBar->m_Bar.rc.left    = m_Bar->rc.left   + 1;
    pBxSBar->m_Bar.rc.top     = pBxSBar->m_Inc.rc.bottom  + 2;
    pBxSBar->m_Bar.rc.right   = m_Bar->rc.right  - 1;
    pBxSBar->m_Bar.rc.bottom  = pBxSBar->m_Bar.rc.top + (unsigned short)((double)BxRectHeight( &m_Bar->rc )*0.6) - 4;
  }
  
  pBxSBar->m_Bar.type       = BUTTON;
  pBxSBar->m_Bar.lpBoxStr   = bar;
  pBxSBar->m_Bar.style      = BBS_PUSHBUTTON | BXS_VISIBLE;
  pBxSBar->m_Bar.bNext      = &pBxSBar->m_Dec;
  pBxSBar->m_Bar.bParent    = m_Bar;
//  pBxSBar->m_Bar.bParent    = m_Bar->bParent;
  pBxSBar->m_Bar.userLevel  = m_Bar->userLevel;
  pBxSBar->m_Bar.m_userData = pBxSBar;

  BxCreateBox(GetAppInstance(hBox), &pBxSBar->m_Bar, DefScrollSlideBarProc);

  pBxSBar->m_Dec.ID    = 1002 + m_Bar->ID;
  if(pBxSBar->m_Style & BSB_HORIZONTAL)
  {
    pBxSBar->m_Dec.rc.left    = m_Bar->rc.right - (unsigned short)((double)BxRectWidth( &m_Bar->rc )*0.10);
    pBxSBar->m_Dec.rc.top     = m_Bar->rc.top + 1;
    pBxSBar->m_Dec.rc.right   = m_Bar->rc.right  - 1;
    pBxSBar->m_Dec.rc.bottom  = m_Bar->rc.bottom - 1;
    pBxSBar->m_Bar.rc.right   = pBxSBar->m_Dec.rc.left - 1;
  }
  else
  {
    pBxSBar->m_Dec.rc.left    = m_Bar->rc.left   + 1;
    pBxSBar->m_Dec.rc.top     = m_Bar->rc.bottom - (unsigned short)((double)BxRectHeight( &m_Bar->rc )*0.20);
    pBxSBar->m_Dec.rc.right   = m_Bar->rc.right  - 1;
    pBxSBar->m_Dec.rc.bottom  = m_Bar->rc.bottom - 1;
  }
  
  pBxSBar->m_Dec.type       = BUTTON;
  pBxSBar->m_Dec.lpBoxStr   = inc;
  pBxSBar->m_Dec.style      = BBS_BITMAP | BBS_PUSHBUTTON | BXS_VISIBLE;
  pBxSBar->m_Dec.bNext      = m_Bar->bNext;
  pBxSBar->m_Dec.bParent    = m_Bar;
//  pBxSBar->m_Dec.bParent    = m_Bar->bParent;

  pBxSBar->m_Dec.userLevel  = m_Bar->userLevel;

  BxCreateBox(GetAppInstance(hBox), &pBxSBar->m_Dec, DefScrollDecProc);
  if(pBxSBar->m_Style & BSB_HORIZONTAL)
    BxSendMessage(&pBxSBar->m_Dec, BBM_SETBITMAP, (BX_WPARAM)BxSystemResourceLoadBxBitmap(21), 0);
  else
    BxSendMessage(&pBxSBar->m_Dec, BBM_SETBITMAP, (BX_WPARAM)BxSystemResourceLoadBxBitmap(23), 0);
  
  m_Bar->bNext = &pBxSBar->m_Inc;

  if(pBxSBar->m_Style & BSB_HORIZONTAL)
  {
    pBxSBar->m_SlideRect.left = pBxSBar->m_Inc.rc.right;
    pBxSBar->m_SlideRect.right = pBxSBar->m_Dec.rc.left;
    pBxSBar->m_SlideRect.top = m_Bar->rc.top;
    pBxSBar->m_SlideRect.bottom = m_Bar->rc.bottom;

    pBxSBar->m_SlideBarRect.left = pBxSBar->m_SlideRect.left;
    pBxSBar->m_SlideBarRect.right = pBxSBar->m_SlideRect.right;
    pBxSBar->m_SlideBarRect.top = pBxSBar->m_SlideRect.top;
    pBxSBar->m_SlideBarRect.bottom = pBxSBar->m_SlideRect.bottom;

    pBxSBar->m_oldP.x = pBxSBar->m_SlideRect.left;
    pBxSBar->m_oldP.y = pBxSBar->m_SlideRect.top;
  }
  else
  {
    pBxSBar->m_SlideRect.left = m_Bar->rc.left;
    pBxSBar->m_SlideRect.right = m_Bar->rc.right;
    pBxSBar->m_SlideRect.top = pBxSBar->m_Inc.rc.bottom;
    pBxSBar->m_SlideRect.bottom = pBxSBar->m_Bar.rc.bottom;

    pBxSBar->m_SlideBarRect.left = m_Bar->rc.left + 2;
    pBxSBar->m_SlideBarRect.right = m_Bar->rc.right - 2;
    pBxSBar->m_SlideBarRect.top = pBxSBar->m_Inc.rc.bottom;
    pBxSBar->m_SlideBarRect.bottom = pBxSBar->m_Bar.rc.bottom;

    pBxSBar->m_oldP.x = pBxSBar->m_SlideRect.left;
    pBxSBar->m_oldP.y = pBxSBar->m_SlideRect.top;
  }
  
  if(pBxSBar->m_Bar.lpBoxStr != NULL)
    sprintf(pBxSBar->m_Bar.lpBoxStr, "%d", pBxSBar->m_Pos);

  m_Bar->boxProc = DefScrollBarProc;
  m_Bar->m_userData = pBxSBar;

  pDC = BxGetBoxDC(hBox);

  BxSetPen(pDC, BX_RGB(0x0, 0x0, 0x0));
  BxSetBrush(pDC, BX_RGB(0x7f, 0x7f, 0x7f));

  if(pBxSBar->m_Style & BSB_HORIZONTAL)
		pBxSBar->m_StepSize = ((double)BxRectWidth( &pBxSBar->m_SlideRect )-3.0)/(double)(pBxSBar->m_Upper - pBxSBar->m_Lower);
	else
		pBxSBar->m_StepSize = ((double)(BxRectHeight( &pBxSBar->m_SlideRect )-BxRectHeight( &pBxSBar->m_SlideBarRect ))-3.0)/(double)(pBxSBar->m_Upper - pBxSBar->m_Lower);

  return TRUE;
}

BX_VOID BxScrollBar_Destroy( HBOX hbox)
{
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;
  BXSCROLLBARSTRUCT *pBxSBar = (BXSCROLLBARSTRUCT *)m_Bar->m_userData;

  m_Bar->bNext = pBxSBar->m_Dec.bNext;
}

BX_VOID BxScrollBar_SetRange( HBOX hbox, BX_INT Lower, BX_INT Upper)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	//  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;

  if(Upper < Lower) return;

	pBxBar->m_Lower = Lower;
	pBxBar->m_Upper = Upper;

  if(pBxBar->m_Style & BSB_HORIZONTAL)
		pBxBar->m_StepSize = ((double)BxRectWidth( &pBxBar->m_SlideRect )-3.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower + 1);
	else
		pBxBar->m_StepSize = ((double)BxRectHeight( &pBxBar->m_SlideRect )-3.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower + 1);

  if ( pBxBar->m_Pos > pBxBar->m_Upper)
    pBxBar->m_Pos = pBxBar->m_Upper;

  update_SlideBar(hbox);
}

BX_INT BxScrollBar_SetPos( HBOX hbox, BX_INT Pos)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldPos = pBxBar->m_Pos;

	if(pBxBar->m_Lower <= Pos && pBxBar->m_Upper >= Pos)
		pBxBar->m_Pos = Pos;

	if ( oldPos != Pos )
    update_SlideBar(hbox);

	return oldPos;
}

BX_INT BxScrollBar_GetPos( HBOX hbox)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	return pBxBar->m_Pos;
}


BX_INT BxScrollBar_GetLower( HBOX hbox)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	//  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;

	return pBxBar->m_Lower;
}

BX_INT BxScrollBar_GetUpper( HBOX hbox)
{
  BXSCROLLBARSTRUCT *pBxBar = (BXSCROLLBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	//  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;

	return pBxBar->m_Upper;
}


/*
BX_INT BxProgressBar_SetStep( HBOX hbox, BX_INT Step)
{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldStep = pBxBar->m_Step;

	if(Step >= 0);
		pBxBar->m_Step = Step;

	return oldStep;
}

*/

