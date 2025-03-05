#include "Bx.h"
#include "BxPrivate.h"

BX_LRESULT DefPBarProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	switch (uMsg)
	{
	case BM_PAINT		: 
    BxProgressBar_Paint( hBox );
    break;
	default:
			 return( DefStaticProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}



BX_BOOL BxProgressBar_Create( HBOX hBox, BXPROGRESSBARSTRUCT *pBxBar, BX_DWORD Style)
{
  BxDC* pDC;
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hBox;

  if(pBxBar==NULL)
		return FALSE;

  if(hBox==NULL)
		return FALSE;
  
  pBxBar->m_Pos = pBxBar->m_Lower = 0;
	pBxBar->m_Upper = 100;
	pBxBar->m_Step = 1;
	pBxBar->m_StepSize = 1.0;
	pBxBar->m_Style = Style;

	pBxBar->hBx = hBox;

  if(m_Bar->lpBoxStr != NULL)
    sprintf(&m_Bar->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], "%d%%", pBxBar->m_Pos);

  m_Bar->boxProc = DefPBarProc;
  m_Bar->m_userData = pBxBar;

  pDC = BxGetBoxDC(hBox);

//  SetFont(pDC, DefaultFont);

  BxSetPen(pDC, BX_RGB(0x0, 0x0, 0x0));
  BxSetBrush(pDC, BX_RGB(0x7f, 0x7f, 0x7f));
  BxSetTextColor(pDC, BX_RGB(0xff, 0xff, 0xff));
  BxSetBkColor(pDC, BX_RGB(0x00, 0x00, 0x7f));
  BxSetTextAlign(pDC, BX_TA_CENTER | BX_TA_TOP);

  if(pBxBar->m_Style & BPB_HORIZONTAL)
		pBxBar->m_StepSize = ((double)BxRectWidth( &m_Bar->rc )-2.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower);
	else
		pBxBar->m_StepSize = ((double)BxRectHeight( &m_Bar->rc )-2.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower);

	return TRUE;
}


BX_VOID BxProgressBar_SetRange( HBOX hbox, BX_INT Lower, BX_INT Upper)


{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;

  if(Upper <= Lower) return;

	pBxBar->m_Lower = Lower;
	pBxBar->m_Upper = Upper;

  if(pBxBar->m_Style & BPB_HORIZONTAL)
		pBxBar->m_StepSize = (((double)BxRectWidth( &m_Bar->rc ))-2.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower);
	else
		pBxBar->m_StepSize = (((double)BxRectHeight( &m_Bar->rc ))-2.0)/(double)(pBxBar->m_Upper - pBxBar->m_Lower);

	BxRequestPaint(hbox);

}


BX_INT BxProgressBar_SetPos( HBOX hbox, BX_INT Pos)
{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldPos = pBxBar->m_Pos;

	if(pBxBar->m_Lower <= Pos && pBxBar->m_Upper >= Pos)
		pBxBar->m_Pos = Pos;

	if ( oldPos != Pos )
    BxRequestPaint(hbox);

	return oldPos;
}

BX_INT BxProgressBar_GetPos( HBOX hbox )
{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldPos = pBxBar->m_Pos;

	return oldPos;
}

BX_INT BxProgressBar_SetStep( HBOX hbox, BX_INT Step)
{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldStep = pBxBar->m_Step;

	if(Step >= 0);
		pBxBar->m_Step = Step;

	return oldStep;
}

BX_INT BxProgressBar_StepIt( HBOX hbox )
{
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)((BOXSTRUCT*)hbox)->m_userData;
	BX_INT oldPos = pBxBar->m_Pos;

	if(pBxBar->m_Pos < pBxBar->m_Upper)
  {
    if(pBxBar->m_Pos + pBxBar->m_Step > pBxBar->m_Upper)
		  pBxBar->m_Pos = pBxBar->m_Upper;
    else
		  pBxBar->m_Pos += pBxBar->m_Step;
  }
	else
		pBxBar->m_Pos = 0;

	if ( oldPos != pBxBar->m_Pos )
    BxRequestPaint(hbox);

  return oldPos;
}

BX_VOID BxProgressBar_Paint( HBOX hbox)
{
  BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox;
  BxDC* pDC;
  BX_RECT hlRc, hlRc2, m_txtRect;
  BXPROGRESSBARSTRUCT *pBxBar = (BXPROGRESSBARSTRUCT *)m_Bar->m_userData;

  if(pBxBar->m_Style & BPB_HORIZONTAL)
  {
		  BxSetRect(&hlRc, m_Bar->rc.left+1, m_Bar->rc.top+1, m_Bar->rc.left+(BX_WORD)(pBxBar->m_StepSize*(double)pBxBar->m_Pos), m_Bar->rc.bottom-1);
		  BxSetRect(&hlRc2, m_Bar->rc.left+1+(BX_WORD)(pBxBar->m_StepSize*(double)pBxBar->m_Pos), m_Bar->rc.top+1, m_Bar->rc.right-1, m_Bar->rc.bottom-1);
  }
	else
  {
		  BxSetRect(&hlRc, m_Bar->rc.left+1, m_Bar->rc.bottom-1-(BX_WORD)(pBxBar->m_StepSize*(double)pBxBar->m_Pos), m_Bar->rc.right-1, m_Bar->rc.bottom-1);
		  BxSetRect(&hlRc2, m_Bar->rc.left+1, m_Bar->rc.top+1, m_Bar->rc.right-1, m_Bar->rc.bottom-1-(BX_WORD)(pBxBar->m_StepSize*(double)pBxBar->m_Pos));
  }
	
  pDC = BxGetBoxDC(pBxBar->hBx);

  if((pBxBar->m_Style & BPB_TYPEMASK) == BPB_VOLUME)
  {
    if(m_Bar->lpBoxStr != NULL)
      sprintf(&m_Bar->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], "%d", pBxBar->m_Pos);
  }
  else
  {
    if(m_Bar->lpBoxStr != NULL)
      sprintf(&m_Bar->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], "%d%%", pBxBar->m_Pos);
  }

//  BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
//  BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
  BxFrame(pDC, &m_Bar->rc, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER], BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);

  BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
  BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
  BxRectangle(pDC, &hlRc);
  BxSetPen(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
  BxSetBrush(pDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
  BxRectangle(pDC, &hlRc2);
  
	m_txtRect.left = m_Bar->rc.left+2;
	m_txtRect.top = m_Bar->rc.top;
	m_txtRect.right = m_Bar->rc.right-2;
	m_txtRect.bottom = m_Bar->rc.bottom;
  if(m_Bar->lpBoxStr != NULL)
    BxDrawText(pDC, &m_Bar->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], BxStringLength(&m_Bar->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &m_txtRect, DT_VCENTER | DT_CENTER);
	m_Bar->m_Dirty = FALSE;
  
  BxSetDirtyArea(&m_Bar->rc);
}

