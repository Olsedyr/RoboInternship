#include "BxPrivate.h"
#include "BxUser.h"
#include "BxEvent.h"

extern BX_VOID BxRequestRectPaint(HBOX hBx, BX_PRECT pRc);

extern BOXSTRUCT formMainBox[];

BX_BOOL DialogProc(

	HBOX  hboxDlg,	// handle to dialog box
	BX_UINT  uMsg,	    // message
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)
{
	return TRUE;
}

BX_INT DialogBox(

	PINSTANCE  hInstance,	// handle to application instance
	BX_UINT  lpTemplate,		// identifies dialog box template
	HBOX  hParent,			// handle to owner Box
	BXDLGPROC  lpDialogFunc 	// pointer to dialog box procedure  
)
{

	return 0;
}

BX_BOOL IsEndDialog(HBOX hBox)
{
	PBOXSTRUCT pBox = (PBOXSTRUCT)hBox;
	PINSTANCESTRUCT pInstance = (PINSTANCESTRUCT)pBox->hInstance;

	return pInstance->endDialog;
}

BX_BOOL BxEndDialog(HBOX hBox, BX_INT nResult)
{
	PBOXSTRUCT pBox = (PBOXSTRUCT)hBox;
	PINSTANCESTRUCT pInstance = (PINSTANCESTRUCT)pBox->hInstance;

	pBox->MsgResult = nResult;
	pInstance->endDialog = TRUE;
	
	return TRUE;
}


BX_INT GetDialogResult(HBOX hBox)
{
	PBOXSTRUCT pBox = (PBOXSTRUCT)hBox;

	return pBox->MsgResult;
}

HBOX BxCreateDialog(
  PINSTANCE hInstance, 
  PBOXSTRUCT b,		
  BXDLGPROC  lpDialogFunc 	// pointer to dialog box procedure  
)
{
  HBOX hBox;
  //BX_RECT tRect;
	BX_RECT bRect;

  if(b==NULL) return NULL;

  if(b->style & BXS_CENTER)
  {
    if(b->bParent != NULL)
    {
//      SetRect(&tRect, b->rc.left,b->rc.top,b->rc.right,b->rc.bottom);
//      BxGetBoxRect(b->bParent, &bRect);
//      
//      b->rc.left = bRect.left+(RectWidth(&bRect)/2)-RectWidth(&tRect)/2;
//      b->rc.right = b->rc.left + RectWidth(&tRect);
//      b->rc.top = bRect.top+(RectHeight(&bRect)/2)-RectHeight(&tRect)/2;
//      b->rc.bottom = b->rc.top + RectHeight(&tRect);
    }
  }

  hBox = BxCreateBox(hInstance, b, (BXPROC) lpDialogFunc);

  BxGetBoxRect(hBox, &bRect);

  b = b->bNext;
  while(b != NULL)
  {
    b->rc.left += bRect.left;		
    b->rc.top  += bRect.top;		
    b->rc.right += bRect.left;		
    b->rc.bottom += bRect.top;		
    BxCreateBox(hInstance, b, NULL);
    b = b->bNext;
  }

  BxSendMessage(hBox, BM_INITDIALOG, 0, 0);

  ShowDialogBox(hBox);
  BxUpdateView(hBox);

  return hBox;
}


BX_VOID DestroyDialogBox(HBOX hBox)
{
	PBOXSTRUCT n, b = (PBOXSTRUCT)hBox;
	BX_RECT bRect;

	BxGetBoxRect(b, &bRect);

	n = b->bNext;
	while(n != NULL)
	{
		if (n->type==LIST)
		{
			BXLISTSTRUCT *pBxList = (BXLISTSTRUCT *)n->m_userData;
			n->bNext = pBxList->m_ScrollBarStruct.m_Dec.bNext;
		}
		DestroyBox(n);
		n->rc.left -= bRect.left;		
		n->rc.top  -= bRect.top;		
		n->rc.right -= bRect.left;		
		n->rc.bottom -= bRect.top;		
		n = n->bNext;
	}
	DestroyBox(b);
}


BX_VOID HideDialogBox(HBOX hBox)
{
	PBOXSTRUCT n, b = (PBOXSTRUCT)hBox;

	n = b->bNext;

	while(n != NULL)
	{
		BxSendMessage(n, BM_SHOWBOX, (BX_WPARAM)FALSE, 0);
		n = n->bNext;
	}

	BxSendMessage(hBox, BM_SHOWBOX, (BX_WPARAM)FALSE, 0);
}

HBOX BxGetDlgItem(HBOX hBx, BX_INT Id)
{
	PBOXSTRUCT pBx = hBx;

	while(pBx)
	{
		if(pBx->ID==Id) 
			return (HBOX)pBx;
		pBx = pBx->bNext;
	}
	return (HBOX)pBx;
}

BX_VOID ShowDialogBox(HBOX hBox)
{
	PBOXSTRUCT b = (PBOXSTRUCT)hBox;

	while(b != NULL)
	{
		BxSendMessage(b, BM_PAINT, 0, 0);
		b = b->bNext;
	}
}

BX_INT DoModal(HBOX hBx)
{
	BX_MSG msg;
	PINSTANCESTRUCT pInstance;
	HBOX oldBx, pUpBx;
	//BX_RECT pntRc;
	PBOXSTRUCT b;

	b = ((PBOXSTRUCT)hBx)->bNext;
	if(b!=NULL)
	{
	  while( b->type != BUTTON || IsDisabled((HBOX)b) || ((PBOXSTRUCT)BxGetParent(b))->type != DIALOG)
		{
      b = b->bNext;
      if(b==NULL)
        break;
    }

	  if(b!=NULL)
		{
      ((PBOXSTRUCT)hBx)->m_oldFocus = BxSetFocus((HBOX)b);
		  SetActiveBox((HBOX)b, FALSE);
    }
	}

	((PBOXSTRUCT)hBx)->m_oldActive = BxSetActiveDlgBox(hBx);

	while(BxGetDlgMessage(&msg, hBx, 0, 0))
	{
		if(msg.message != BM_NULL)
		{
			BxTranslateMessage( &msg );
			BxDispatchMessage( &msg );
		}
		else
		{
			BxWaitEvent();
			if(BxUpdateFlag)
			{ 
				BxUpdateFlag = FALSE;
				pUpBx = BxGetActiveDlgBox();
				if(pUpBx)
					BxSendMessage(pUpBx, BM_UPDATE, 0, 0);
			}
		}
	}
  if(((PBOXSTRUCT)hBx)->m_oldActive!=NULL) // not top box
  {
    oldBx = BxSetActiveDlgBox(((PBOXSTRUCT)hBx)->m_oldActive);
    //BxGetBoxRect(oldBx, &pntRc);
    //BxRequestRectPaint(BxGetActiveDlgBox(), &pntRc);
		
		ShowDialogBox(BxGetActiveDlgBox());
	  BxSetFocus(((PBOXSTRUCT)oldBx)->m_oldFocus);
	  SetActiveBox(((PBOXSTRUCT)oldBx)->m_oldFocus, FALSE);
	  pInstance = (PINSTANCESTRUCT)((PBOXSTRUCT)BxGetActiveDlgBox())->hInstance;
	  pInstance->endDialog = FALSE;
	  BxSendMessage(BxGetActiveDlgBox(), BM_UPDATE, 0, 0);
  }
	return ((PBOXSTRUCT)hBx)->MsgResult;
}
