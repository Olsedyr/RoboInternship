#include "BxPrivate.h"
#include <math.h>

HBOX PUSHED = NULL;

BX_BOOL Button_OnCreate(HBOX hbox);
//BX_BOOL Button_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_INT Status);
//BX_VOID Button_OnEnable(HBOX hbox, BX_BOOL fEnable) { Button_Enable(hbox, fEnable);}
//BX_VOID Button_OnSetText(HBOX hbox, BX_PSTRING lpszText) { Button_SetText(hbox, lpszText); }
BX_VOID Button_OnDestroy(HBOX hbox);
BX_VOID Button_OnPaint(HBOX hbox);
BX_VOID Button_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized);

BX_VOID Button_OnKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);

BX_VOID Button_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
BX_VOID Button_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y);

CLASSDEF PUSHBUTTON_CLASS = {
	Box_OnQuit,
	Button_OnCreate,
	Box_OnShowBox,
	Box_OnDestroy,
	Box_OnEnable,
	Box_OnSetText,
	Box_OnGetText,
	Box_OnGetTextLength,
	Box_OnClose,
	Button_OnPaint,
	Box_OnNCPaint,
	Box_OnNCHitTest,
	Button_OnActivate,
	Box_OnSetFocus,
	Box_OnKillFocus,
	Button_OnKeyDown,
	Box_OnKeyUp,
	Box_OnChar,
	Box_OnDeadChar,
	Box_OnSysKeyDown,
	Box_OnSysKeyUp,
	Box_OnSysChar,
	Box_OnSysDeadChar,
	Box_OnMouseMove,
	Button_OnLButtonDown,
	Button_OnLButtonUp,
	Box_OnNCMouseMove,
	Box_OnNCLButtonDown,
	Box_OnNCLButtonUp,
	Box_OnMouseActivate,
	Box_OnCut,
	Box_OnClear,
	Box_OnSetCursor,
	Box_OnSysCommand,
};

PCLASS hCls_Button = &PUSHBUTTON_CLASS;


BX_BOOL BxGetCheck(HBOX hBx)
{
	return Button_GetCheck(hBx);
}

BX_VOID BxSetCheck(HBOX hBx, BX_BOOL check)
{
	if(((PBOXSTRUCT)hBx)->style & BBS_CHECKBOX || ((PBOXSTRUCT)hBx)->style & BBS_RADIOBOX) 
	{
		if (Button_GetCheck(hBx) != check)
		{
			Button_SetCheck(hBx, check);
			BxRequestPaint(hBx);
		}
	}
}

/**/
BX_LRESULT DefPushButtonProc( HBOX hBox, BX_UINT uMsg,
  BX_WPARAM wParam, BX_LPARAM lParam )
{
  PBOXSTRUCT b = hBox, ra;
  BX_PVOID old;

  switch (uMsg) {
	case BBM_SETIMAGE	: 
	case BBM_SETBITMAP :
    old = ((PBOXSTRUCT)hBox)->m_image;
    ((PBOXSTRUCT)hBox)->m_image = (BX_PVOID)wParam;
    ((PBOXSTRUCT)hBox)->style &= 0xFFFFFF3FL;
    ((PBOXSTRUCT)hBox)->style |= BBS_BITMAP;
    return (BX_LRESULT)(BX_PBITMAP)old;
	case BBM_SETICON:
		old = ((PBOXSTRUCT)hBox)->m_image;
		((PBOXSTRUCT)hBox)->m_image = (BX_PVOID)wParam;
		((PBOXSTRUCT)hBox)->style &= 0xFFFFFF3FL;
		((PBOXSTRUCT)hBox)->style |= BBS_ICON;
		return (BX_LRESULT)(BX_PICON)old;
	case BBM_GETIMAGE: 
		return (BX_LRESULT)((PBOXSTRUCT)hBox)->m_image;
	case BBM_GETBITMAP		:
		return (BX_LRESULT)(BX_PBITMAP)((PBOXSTRUCT)hBox)->m_image;
		break;
	case BBM_SETSTATE:
		if(wParam)
			b->boxState |= BST_PUSHED;
		else
		{
			if(b->boxState & BST_PUSHED)
				b->boxState ^= BST_PUSHED;
		}
		break;		
	case BBM_GETSTATE:
		return (BX_LRESULT)b->boxState;
		break;
///////////////////////////////////////////////////
		case BBM_SETCHECK:
			if(b->style & BBS_CHECKBOX)
			{
				if(wParam == BST_CHECKED)
				{
					b->boxState |= BST_CHECKED;
					break;
				}
			}
			if(b->style & BBS_RADIOBOX)
			{
				if(wParam == BST_CHECKED)
				{
					ra = b->bParent->bNext;
					while(ra)
					{
						if(ra->type == BUTTON && ra->style & BBS_RADIOBOX)
							BxSetCheck(ra, FALSE);
						ra = ra->bNext;
					}
					b->boxState |= BST_CHECKED;
					break;
				}
			}
			if(wParam == BST_UNCHECKED)
			{
				if(b->boxState & BST_CHECKED)
					b->boxState ^= BST_CHECKED;
			}
			break;
		case BBM_GETCHECK:
			if(b->boxState & BST_CHECKED) 
				return (BX_LRESULT)BST_CHECKED;
			else 
				return (BX_LRESULT)BST_UNCHECKED;
			break;
/////////////////////////////////////////////////////
		default:
			return( DefBoxProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_VOID Button_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized)
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



BX_VOID Button_OnPaint(HBOX hbox)
{
	BOXSTRUCT *b = hbox;
  BX_RECT rc;

  rc.top = b->rc.top + 1;
  rc.bottom = b->rc.bottom - 1;
  rc.left = b->rc.left + 1;
  rc.right = b->rc.right - 1;
  
  BxUpdateOff();
  b->m_Dirty = FALSE;

  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
      case BA_INACTIVE:
        switch(b->style & BBS_TYPEMASK) {
          case BBS_USERBUTTON:
						BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
						BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
            BxRoundRect(&b->m_BxDC, &b->rc, 4);
						if(b->style & BXS_DISABLED)
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
						else
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
						BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
						BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);
						break;
					default:
						if(b->style & BXS_DISABLED)
							BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
						else
							BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
						BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
                        BxRoundRect(&b->m_BxDC, &b->rc, 4);
						if(b->style & BXS_DISABLED)
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
						else
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
						if(b->style & BBS_ICON)
						{
							if(b->m_image)
							{
								BxDrawIcon(&b->m_BxDC, b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmWidth/2), b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
							}
						  BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);
						}
						else if(b->style & BBS_BITMAP)
						{
							if(b->m_image)
							{
							  BxDrawBitmap(&b->m_BxDC, b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmWidth/2), b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_SOLID);
							}
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);
						}
						else
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);
						break;
				}
				break;
			case BA_ACTIVE:
				switch(b->style & BBS_TYPEMASK) {
					case BBS_USERBUTTON:
						BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
						BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
            BxRoundRect(&b->m_BxDC, &b->rc, 4);
            if(b->style & BXS_DISABLED)
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
						else
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
						BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
						BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);
						break;
          default:
            BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
            BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
            BxRoundRect(&b->m_BxDC, &b->rc, 4);
            if(b->style & BXS_DISABLED)
							BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
						else
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
            BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
						if(b->style & BBS_ICON)
						{
							if((BX_PICON)b->m_image)
							{
								BxDrawIcon(&b->m_BxDC, b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmWidth/2), b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
							}
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);
						}
						else if(b->style & BBS_BITMAP)
						{
							if(b->m_image)
							{
								BxDrawBitmap(&b->m_BxDC, b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmWidth/2), b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_SOLID);
							}
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);
						}
						else
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);
						break;
				}
				break;
			case BA_CLICKACTIVE:
				switch(b->style & BBS_TYPEMASK) {
					case BBS_USERBUTTON:
						BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
						BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
                        BxRoundRect(&b->m_BxDC, &b->rc, 4);
						BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNHIGHLIGHT]);
						BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
						BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);
						break;
					default:
						BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
						BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_HIGHLIGHT]);
                        BxRoundRect(&b->m_BxDC, &b->rc, 4);
						BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNHIGHLIGHT]);
						if(b->style & BBS_ICON)
						{
							if((BX_PICON)b->m_image)
								BxDrawIcon(&b->m_BxDC, 1+b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmWidth/2), 1+b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);
						}
						else if(b->style & BBS_BITMAP)
						{
							if(b->m_image)
								BxDrawBitmap(&b->m_BxDC, b->rc.left+(BxRectWidth(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmWidth/2), b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_SOLID);
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_BOTTOM | DT_CENTER);					
						}
						else
							BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &b->rc, DT_VCENTER | DT_CENTER);

						break;
				}
				break;
		}
	}
	else
	{
		BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
		BxRoundRect(&b->m_BxDC, &b->rc, 4);
	}
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}

// sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
BX_VOID Button_OnKeyDown(HBOX hbox, BX_UINT vChar, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags)
{
	PBOXSTRUCT pBx = (PBOXSTRUCT)hbox;
	PBOXSTRUCT pTmpBx = (PBOXSTRUCT)hbox;
	PBOXSTRUCT pCloseBx = (PBOXSTRUCT)hbox;


	double dist = 65535.0;

	switch(vChar) {

		case VK_RIGHT:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(BxRectCenterX(&pTmpBx->rc) > BxRectCenterX(&pBx->rc) &&
					dist > sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
						(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))))

					)
				{
					if(pTmpBx->type == BUTTON && IsVisible((HBOX)pTmpBx) && !IsDisabled((HBOX)pTmpBx))

					{
						pCloseBx = pTmpBx;
						dist = sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
								(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))));
					}
				}

				pTmpBx = pTmpBx->bNext;



			}

			pBx = pCloseBx;

			BxSetFocus((HBOX)pBx);
			SetActiveBox((HBOX)pBx, FALSE);
			break;

		case VK_DOWN:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(pTmpBx->rc.top > pBx->rc.top &&
					dist > sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
						(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))))
					)

				{
					if(pTmpBx->type == BUTTON && IsVisible((HBOX)pTmpBx) && !IsDisabled((HBOX)pTmpBx))
					{
						pCloseBx = pTmpBx;
						dist = sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
								(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))));
					}
				}

				pTmpBx = pTmpBx->bNext;
			}

			pBx = pCloseBx;

			BxSetFocus((HBOX)pBx);
			SetActiveBox((HBOX)pBx, FALSE);
			break;

		case VK_LEFT:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(BxRectCenterX(&pTmpBx->rc) < BxRectCenterX(&pBx->rc) &&
					dist > sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+

						(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))))
					)
				{
					if(pTmpBx->type == BUTTON && IsVisible((HBOX)pTmpBx) && !IsDisabled((HBOX)pTmpBx))
					{
						pCloseBx = pTmpBx;
						dist = sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
								(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))));
					}
				}


				pTmpBx = pTmpBx->bNext;
			}

			pBx = pCloseBx;

			BxSetFocus((HBOX)pBx);
			SetActiveBox((HBOX)pBx, FALSE);
			break;

		case VK_UP:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(pTmpBx->rc.top < pBx->rc.top &&
					dist > sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
						(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))))
					)
				{
					if(pTmpBx->type == BUTTON && IsVisible((HBOX)pTmpBx) && !IsDisabled((HBOX)pTmpBx))
					{
						pCloseBx = pTmpBx;
						dist = sqrt((((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc))*((double)BxRectCenterX(&pBx->rc) - (double)BxRectCenterX(&pTmpBx->rc)))+
								(((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))*((double)BxRectCenterY(&pBx->rc) - (double)BxRectCenterY(&pTmpBx->rc))));
					}
				}

				pTmpBx = pTmpBx->bNext;
			}

			pBx = pCloseBx;

			BxSetFocus((HBOX)pBx);
			SetActiveBox((HBOX)pBx, FALSE);
			break;
		case VK_TAB:
      if(pBx->bNext==NULL)
        pTmpBx = pBx->bParent->bNext;
      else
        pTmpBx = pBx->bNext;
			while(pTmpBx->type != BUTTON || !IsVisible((HBOX)pTmpBx) || IsDisabled((HBOX)pTmpBx))
			{
			  pTmpBx = pTmpBx->bNext;
        if(pTmpBx == NULL)

          pTmpBx = pBx->bParent->bNext;
			}
			pBx = pTmpBx;
			BxSetFocus((HBOX)pBx);
			SetActiveBox((HBOX)pBx, FALSE);
			break;
		case VK_RETURN:
			if(pBx->userLevel <= BxGetUserLevel())
				BxPostMessage(BxGetParent(hbox), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)hbox)->ID, 0), (BX_LPARAM)hbox);
//      BxUpdateView(GetParent(hbox));
			break;

		case VK_ESCAPE:
			BxPostMessage(BxGetParent(hbox), BM_COMMAND, BX_MAKEWPARAM(IDCANCEL, 0), (BX_LPARAM)hbox);
//      BxUpdateView(GetParent(hbox));

			break;
	}
}


BX_BOOL Button_OnCreate(HBOX hbox)
{
	BOXSTRUCT *b = hbox;

	b->boxState |= BA_INACTIVE;


	return (TRUE);
}


BX_VOID Button_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y)
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

BX_VOID Button_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y)
{
	BOXSTRUCT *b = hbox;

	if(b->style & BXS_DISABLED || b->userLevel > BxGetUserLevel() )
		return;

	BxSetFocus(hbox);
	SetActiveBox(hbox, TRUE);
}


BX_VOID Button_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y)
{
	BOXSTRUCT *b = hbox;

	if(b->style & BXS_DISABLED || b->userLevel > BxGetUserLevel() )
		return;

	SetActiveBox(hbox, FALSE);
	BxPostMessage(BxGetParent(hbox), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)hbox)->ID, 0), (BX_LPARAM)hbox);
//  BxUpdateView(GetParent(hbox));
}

BX_VOID Button_OnSetFocus(HBOX hbox, HBOX hboxOldFocus)
{

}

BX_VOID Button_OnKillFocus(HBOX hbox, HBOX hboxNewFocus)
{


}

BX_VOID Button_OnDestroy(HBOX hBox)
{
  if(((PBOXSTRUCT)hBox)->style & BBS_ICON)
    BxDeleteIcon((BxIcon*)((PBOXSTRUCT)hBox)->m_image);
  if(((PBOXSTRUCT)hBox)->style & BBS_BITMAP)
    BxDeleteBitmap((BxBitmap*)((PBOXSTRUCT)hBox)->m_image);
}
