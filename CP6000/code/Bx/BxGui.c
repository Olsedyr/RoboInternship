#include "BxPrivate.h"

BX_VOID ShowCursor(BX_BOOL bShow) {}

BX_BOOL BxPointInRect(BX_RECT* m_rc, BX_INT x, BX_INT y)
{
  if(m_rc->left <= x && m_rc->right >= x &&
     m_rc->top <= y && m_rc->bottom >= y)
    return TRUE;
  else
    return FALSE;
}

BX_BOOL BxRectInRect(BX_PRECT pRc, BX_PRECT pClRc)
{

	if(BxPointInRect(pRc, pClRc->left, pClRc->top))
		return TRUE;
	if(BxPointInRect(pRc, pClRc->right, pClRc->top))
		return TRUE;
	if(BxPointInRect(pRc, pClRc->left, pClRc->bottom))
		return TRUE;
	if(BxPointInRect(pRc, pClRc->right, pClRc->bottom))
		return TRUE;

	if(BxPointInRect(pClRc, pRc->left, pRc->top))
		return TRUE;
	if(BxPointInRect(pClRc, pRc->right, pRc->top))
		return TRUE;
	if(BxPointInRect(pClRc, pRc->left, pRc->bottom))
		return TRUE;
	if(BxPointInRect(pClRc, pRc->right, pRc->bottom))
		return TRUE;

	return FALSE;	
}
 
BX_BOOL BxMergeRects(BX_PRECT pRc1, BX_PRECT pRc2, BX_PRECT pdstRc)
{
	if(BxRectInRect(pRc1, pRc2))
	{ 
		pdstRc->left = BXMIN(pRc1->left, pRc2->left);
		pdstRc->top = BXMIN(pRc1->top, pRc2->top);
		pdstRc->right = BXMAX(pRc1->right, pRc2->right);
		pdstRc->bottom = BXMAX(pRc1->bottom, pRc2->bottom);
		return TRUE;
	}
	return FALSE;	
}
 

BX_BOOL BxSetRect( BX_PRECT lprc, BX_INT xLeft, BX_INT yTop, BX_INT xRight, BX_INT yBottom ) 
{
	lprc->left = xLeft;
	lprc->top = yTop;
	lprc->right = xRight;
	lprc->bottom = yBottom;
	return TRUE;
}

BX_VOID BxCopyRect(BX_PRECT pRc1, BX_PRECT pRc2)
{
	pRc1->left		= pRc2->left;
	pRc1->top			= pRc2->top;
	pRc1->right		= pRc2->right;
	pRc1->bottom	= pRc2->bottom;
}

BX_INT BxRectWidth( BX_PRECT prc ) 
{
	return BXABS(prc->right - prc->left);
}

BX_INT BxRectHeight( BX_PRECT prc ) 
{
	return BXABS(prc->bottom - prc->top);
}

BX_VOID BxRectCenter( BX_PRECT prc, BX_PPOINT pp ) 
{
  pp->x = prc->left + BxRectWidth(prc)/2;
  pp->y = prc->top + BxRectHeight(prc)/2;
}

BX_INT BxRectCenterX( BX_PRECT prc ) 
{
  return (prc->left + BxRectWidth(prc)/2);
}

BX_INT BxRectCenterY( BX_PRECT prc ) 
{
  return (prc->top + BxRectHeight(prc)/2);
}

