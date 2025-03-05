#include "BxPrivate.h"
#include "Bx.h"
#include <math.h>

static BX_VOID update_List(HBOX hBox)
{
	BXLISTSTRUCT *pBxList = (BXLISTSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
	//BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTUNITSTRUCT *pLst;
	BX_INT i;

  // Find index
	pLst = pBxList->m_First;
	for( i = 0; i < pBxList->m_ViewPos; i++)
	{
		if ( pLst == NULL )
			return;
		pLst = pLst->m_Next;
	}

	for( i = 0; i < pBxList->m_NumView; i++)
	{
		pBxList->m_LabTab[i].boxState &= 0xFF8F;
		if ( pLst != NULL )
		{
			pBxList->m_LabTab[i].lpBoxStr = pLst->m_Str;

			if(pBxList->m_Pos == i + pBxList->m_ViewPos)
				pBxList->m_LabTab[i].boxState |= BA_CLICKACTIVE;
			else
				pBxList->m_LabTab[i].boxState |= BA_INACTIVE;

			pLst = pLst->m_Next;
		}
		else
		{
			pBxList->m_LabTab[i].lpBoxStr = NULL;
			pBxList->m_LabTab[i].boxState |= BA_INACTIVE;
		}
    BxRequestPaint(&pBxList->m_LabTab[i]);
	}
}

static BX_VOID destroy_List(HBOX hBox)
{
	BXLISTSTRUCT *pBxList = (BXLISTSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTUNITSTRUCT *nLst, *pLst;

	b->bNext = pBxList->m_ScrollBarStruct.m_Dec.bNext;

  // Find index
	pLst = pBxList->m_First;
	while (pLst!=NULL)
	{
		nLst = pLst;
		pLst = pLst->m_Next;
		BxMemFree(nLst);
	}
	pBxList->m_First = pBxList->m_Last = pBxList->m_Ptr = NULL;
}

static BX_LRESULT DefListProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	BXLISTSTRUCT *pBxList = (BXLISTSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
	//BOXSTRUCT *b = (BOXSTRUCT *)hBox;

	switch (uMsg)
	{
		case BM_VSCROLL		: 
			if(pBxList->m_ViewPos != BX_HIWORD(wParam))
			{
				pBxList->m_ViewPos = BX_HIWORD(wParam);
				update_List(hBox);
			}
			break;
		case BM_DESTROY:
			destroy_List(hBox);
			break;
		default:
			return( DefStaticProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}


static BX_VOID paint_ListLabel( HBOX hbox)
{
	BOXSTRUCT *b = hbox;
	BX_RECT m_txtRect;

	b->m_Dirty = FALSE;
  BxUpdateOff();

	m_txtRect.left = b->rc.left+2;
	m_txtRect.top = b->rc.top;
	m_txtRect.right = b->rc.right-2;
	m_txtRect.bottom = b->rc.bottom;

	if(b->style & BXS_VISIBLE)
	{
		switch(b->boxState & BBS_STATEMASK) {
			case BA_CLICKACTIVE:
				BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
				BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
				BxRectangle(&b->m_BxDC, &b->rc);
				if(b->style & BXS_DISABLED)
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
				else
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

				if(b->lpBoxStr!=NULL)
				{
					if(b->style & BSS_CENTER)
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
					else
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER);
				}
				break;
			case BA_ACTIVE:
				BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
				BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
				BxRectangle(&b->m_BxDC, &b->rc);
				if(b->style & BXS_DISABLED)
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
				else
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);

				if(b->lpBoxStr!=NULL)
				{
					if(b->style & BSS_CENTER)
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
					else
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER);
				}
				break;
			case BA_INACTIVE:
				BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
				BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
				BxRectangle(&b->m_BxDC, &b->rc);
				if(b->style & BXS_DISABLED)
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
				else
					BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);

				if(b->lpBoxStr!=NULL)
				{
					if(b->style & BSS_CENTER)
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER | DT_CENTER);
					else
						BxDrawText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_VCENTER);
				}
				break;
		}
	}
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}

// sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
static BX_VOID ListLabel_OnKeyDown(HBOX hbox, BX_UINT vChar, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags)
{
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)((BOXSTRUCT*)BxGetParent(hbox))->m_userData;
	PBOXSTRUCT pBx = (PBOXSTRUCT)hbox;
	PBOXSTRUCT pTmpBx = (PBOXSTRUCT)hbox;
	PBOXSTRUCT pCloseBx = (PBOXSTRUCT)hbox;
	double dist = 65535.0;

	switch(vChar) {
		case VK_RIGHT:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(pTmpBx->rc.left > pBx->rc.left &&
					dist > sqrt((((double)pBx->rc.left - (double)pTmpBx->rc.left)*((double)pBx->rc.left - (double)pTmpBx->rc.left))+
						(((double)pBx->rc.top - (double)pTmpBx->rc.top)*((double)pBx->rc.top - (double)pTmpBx->rc.top)))
					)
				{
					if(pTmpBx->type == BUTTON && IsVisible((HBOX)pTmpBx) && !IsDisabled((HBOX)pTmpBx))
					{
						pCloseBx = pTmpBx;
						dist = sqrt((((double)pBx->rc.left - (double)pTmpBx->rc.left)*((double)pBx->rc.left - (double)pTmpBx->rc.left))+
								(((double)pBx->rc.top - (double)pTmpBx->rc.top)*((double)pBx->rc.top - (double)pTmpBx->rc.top)));
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
			if((pBx->ID - 2000 - MAX_LABELS_IN_LIST - pBx->bParent->ID) == pList->m_NumView-1)
			{
				if(pList->m_ViewPos < pList->m_NumView)
				{
					pList->m_ViewPos++;
					BxScrollBar_SetPos( (HBOX)&pList->m_ScrollBar, pList->m_ViewPos);
					SetActiveBox((HBOX)pBx, FALSE);
					update_List(BxGetParent(hbox));
					break;
				}
			}
			else
			{
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
			}
			break;

		case VK_LEFT:
			pTmpBx = pBx->bParent->bNext;

			while(pTmpBx!=NULL)
			{
				if(pTmpBx->rc.left < pBx->rc.left &&
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

			if((pBx->ID - 2000 - MAX_LABELS_IN_LIST - pBx->bParent->ID) == 0)
			{
				if(pList->m_ViewPos > 0)
				{
					pList->m_ViewPos--;
					BxScrollBar_SetPos( (HBOX)&pList->m_ScrollBar, pList->m_ViewPos);
					SetActiveBox((HBOX)pBx, FALSE);
					update_List(BxGetParent(hbox));
        //break;
				}
			}
			else
			{
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
			}
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
    //if(pBx->userLevel <= BxGetUserLevel())
			if( pList->m_ViewPos + (pBx->ID - 2000 - MAX_LABELS_IN_LIST - ((BOXSTRUCT*)BxGetParent(hbox))->ID) < pList->m_Items )
			{
				pList->m_Pos = pList->m_ViewPos + (pBx->ID - 2000 - MAX_LABELS_IN_LIST - ((BOXSTRUCT*)BxGetParent(hbox))->ID);
				BxSetFocus(hbox);
				update_List(BxGetParent(hbox));






				BxPostMessage(BxGetParent(BxGetParent(hbox)), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)BxGetParent(hbox))->ID, 0), (BX_LPARAM)hbox);
//        BxUpdateView(BxGetParent(BxGetParent(hbox)));
			}
			break;
		case VK_ESCAPE:
			BxPostMessage(BxGetParent(BxGetParent(hbox)), BM_COMMAND, BX_MAKEWPARAM(IDCANCEL, 0), (BX_LPARAM)hbox);
//      BxUpdateView(BxGetParent(BxGetParent(hbox)));
			break;
	}
}

static BX_LRESULT ListLabelProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	BXLISTSTRUCT *pBxList = (BXLISTSTRUCT *)((BOXSTRUCT*)BxGetParent(hBox))->m_userData;
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;


	switch (uMsg)
	{
		case BM_PAINT	 : 
			paint_ListLabel( hBox );
			break;
		case BM_LBUTTONDOWN :
			if( pBxList->m_ViewPos + (b->ID - 2000 - MAX_LABELS_IN_LIST - ((BOXSTRUCT*)BxGetParent(hBox))->ID) < pBxList->m_Items )
			{
				pBxList->m_Pos = pBxList->m_ViewPos + (b->ID - 2000 - MAX_LABELS_IN_LIST - ((BOXSTRUCT*)BxGetParent(hBox))->ID);
				BxSetFocus(hBox);
				update_List(BxGetParent(hBox));
			}
			break;
		case BM_LBUTTONUP :
			if( pBxList->m_ViewPos + (b->ID - 2000 - MAX_LABELS_IN_LIST - ((BOXSTRUCT*)BxGetParent(hBox))->ID) < pBxList->m_Items )
			{
				BxPostMessage(BxGetParent(BxGetParent(hBox)), BM_COMMAND, BX_MAKEWPARAM(((PBOXSTRUCT)BxGetParent(hBox))->ID, 0), (BX_LPARAM)hBox);
//        BxUpdateView(BxGetParent(BxGetParent(hBox)));
			}
			break;
		case BM_KEYDOWN :
			ListLabel_OnKeyDown(hBox, (BX_UINT)wParam, TRUE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam));

			break;
		default:
			return( DefPushButtonProc( hBox, uMsg, wParam, lParam ) ) ;
	}
	return 0L ;
}

BX_BOOL BxList_Create( HBOX hBox, BXLISTSTRUCT *pBxList, BX_DWORD Style)
{
	BOXSTRUCT *m_Bar = (BOXSTRUCT *)hBox;
	BX_INT num_lab, lab_height, i;

	if(pBxList==NULL)
		return FALSE;

	if(hBox==NULL)

		return FALSE;

	pBxList->m_Items      = 0;
	pBxList->m_Pos        = -1;
	pBxList->m_ViewPos    = 0;

	num_lab = BxRectHeight(&m_Bar->rc)/MIN_LISTLABEL_HEIGHT;
	pBxList->m_NumView    = num_lab;

	lab_height = BxRectHeight(&m_Bar->rc)/num_lab;

	for( i = 0; i < num_lab && i < MAX_LABELS_IN_LIST; i++ )
	{
		pBxList->m_LabTab[i].ID = 2000 + MAX_LABELS_IN_LIST + m_Bar->ID + i;
		pBxList->m_LabTab[i].rc.left    = m_Bar->rc.left + 1;
		pBxList->m_LabTab[i].rc.top     = (m_Bar->rc.top + 1) + (i*lab_height);
		pBxList->m_LabTab[i].rc.right   = m_Bar->rc.right - (MIN_SCROLLBAR_WIDTH + 2);
		pBxList->m_LabTab[i].rc.bottom  = pBxList->m_LabTab[i].rc.top + lab_height - 1;
		pBxList->m_LabTab[i].type = BUTTON;
		pBxList->m_LabTab[i].style      = BBS_PUSHBUTTON | BXS_VISIBLE;
		pBxList->m_LabTab[i].bNext      = &pBxList->m_LabTab[i+1];
		pBxList->m_LabTab[i].bParent    = m_Bar;
		pBxList->m_LabTab[i].userLevel  = m_Bar->userLevel;

		BxCreateBox(GetAppInstance(hBox), &pBxList->m_LabTab[i], ListLabelProc);
	}
	pBxList->m_LabTab[i-1].bNext      = &pBxList->m_ScrollBar;

	pBxList->m_ScrollBar.ID    = 2000 + m_Bar->ID;
	pBxList->m_ScrollBar.rc.left    = m_Bar->rc.right - MIN_SCROLLBAR_WIDTH;

	pBxList->m_ScrollBar.rc.top     = m_Bar->rc.top    + 1;
	pBxList->m_ScrollBar.rc.right   = m_Bar->rc.right  - 1;
	pBxList->m_ScrollBar.rc.bottom  = m_Bar->rc.bottom  - 1;
	pBxList->m_ScrollBar.type       = STATIC;
//  pBxList->m_ScrollBar.lpBoxStr   = dec;
	pBxList->m_ScrollBar.style      = BXS_BORDER | BXS_VISIBLE;
	pBxList->m_ScrollBar.bNext      = m_Bar->bNext;
//	pBxList->m_ScrollBar.bParent    = m_Bar->bParent;
	pBxList->m_ScrollBar.bParent    = m_Bar;
	pBxList->m_ScrollBar.userLevel  = m_Bar->userLevel;

	BxCreateBox(GetAppInstance(hBox), &pBxList->m_ScrollBar, NULL);

	m_Bar->boxProc = DefListProc;

	m_Bar->m_userData = pBxList;
	m_Bar->bNext = &pBxList->m_LabTab[0];
	BxScrollBar_Create( &pBxList->m_ScrollBar, &pBxList->m_ScrollBarStruct, BSB_VERTICAL | BSB_NOCAPTION);
	BxScrollBar_SetRange( &pBxList->m_ScrollBar, 0, pBxList->m_Items);

	return TRUE;
}

/* static BX_VOID BxList_Paint( HBOX hbox) */
/* { */
/* 	BOXSTRUCT *m_Bar = (BOXSTRUCT *)hbox; */
/* 	BxDC* pDC; */
/* 	BXLISTSTRUCT *pBxBar = (BXLISTSTRUCT *)m_Bar->m_userData; */

/* 	pDC = BxGetBoxDC(&pBxBar->m_ScrollBar); */

/*   BxSetDirtyArea(&m_Bar->rc); */
/* 	m_Bar->m_Dirty = FALSE; */
/* } */

BX_BOOL BxList_AddString( HBOX hBox, BX_PSTRING lpStr)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	BXLISTUNITSTRUCT *nLst;

	if(lpStr == NULL)
		return FALSE;


	nLst = (BXLISTUNITSTRUCT*)BxMemAlloc(sizeof(BXLISTUNITSTRUCT));

	if ( nLst == NULL ) // out of memory
		return FALSE;

	nLst->m_Next = NULL;

	nLst->m_Prev = NULL;
	BxStringCopy(nLst->m_Str, lpStr);

	if (pList->m_First == NULL)
	{
		pList->m_First = pList->m_Last = pList->m_Ptr = nLst;
	}
	else
	{
		nLst->m_Prev = pList->m_Last;
		pList->m_Last->m_Next = nLst;
		pList->m_Last = nLst;
	}
	pList->m_Items++;

	if(pList->m_Items - pList->m_NumView > 0)
		BxScrollBar_SetRange( &pList->m_ScrollBar, 0, pList->m_Items - pList->m_NumView);

	update_List(hBox);
	return TRUE;
}

BX_BOOL BxList_InsertString( HBOX hBox, BX_INT index, BX_PSTRING lpStr)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	BXLISTUNITSTRUCT *nLst, *pLst;
	BX_INT i;

	if(hBox==NULL)
		return FALSE;

	if(index < 0)
		return FALSE;

  // Find index
	pLst = pList->m_First;
	for( i = 0; i < index; i++)
	{
		if ( pLst == NULL )
			return FALSE;
		pLst = pLst->m_Next;
	}

	nLst = (BXLISTUNITSTRUCT*)BxMemAlloc(sizeof(BXLISTUNITSTRUCT));

	if ( nLst == NULL ) // out of memory
		return FALSE;

	nLst->m_Next = NULL;
	nLst->m_Prev = NULL;
	BxStringCopy(nLst->m_Str, lpStr);

  if(pList->m_First == NULL)
  {
    pList->m_First = pList->m_Last = pList->m_Ptr = nLst;
  }

	else if (pLst == pList->m_First)
	{
		pList->m_First->m_Prev = nLst;
		nLst->m_Next = pList->m_First;
		pList->m_First = nLst;
	}
	else
	{
		pLst->m_Prev->m_Next = nLst;
		nLst->m_Prev = pLst->m_Prev;
		pLst->m_Prev = nLst;
		nLst->m_Next = pLst;
	}

	pList->m_Items++;

	if(pList->m_Items - pList->m_NumView > 0)
		BxScrollBar_SetRange( &pList->m_ScrollBar, 0, pList->m_Items - pList->m_NumView);

	update_List(hBox);

	return TRUE;
}

BX_BOOL BxList_DeleteString( HBOX hBox, BX_INT index)
{

	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	BXLISTUNITSTRUCT *nLst;
	BX_INT i;

	if(hBox==NULL)
		return FALSE;

	if(index < 0)
		return FALSE;

	if(pList->m_First == NULL)

		return FALSE;

  // Find index
	nLst = pList->m_First;
	for( i = 0; i < index; i++)
	{
		if ( nLst == NULL )
			return FALSE;
		nLst = nLst->m_Next;
	}

  // Index found now delete it
	if ( nLst == pList->m_First ) // if the first
	{
    if(pList->m_First == pList->m_Last)
    {
      pList->m_First = NULL;
      pList->m_Last = NULL;
    }
    else
    {
      pList->m_First = pList->m_First->m_Next;
      pList->m_First->m_Prev = NULL;
    }
	}
	else 
	{
		if ( nLst == pList->m_Last ) // if the last
		{
			pList->m_Last = pList->m_Last->m_Prev;
			pList->m_Last->m_Next = NULL;
		}
		else
		{
			nLst->m_Prev->m_Next = nLst->m_Next;
			nLst->m_Next->m_Prev = nLst->m_Prev;
		}
	}

	BxMemFree( nLst );

	pList->m_Items--;

	if(pList->m_Items>= 0)
	  pList->m_ViewPos    = 0;


	pList->m_Pos = -1;

 if(pList->m_Items - pList->m_NumView >= 0)
		BxScrollBar_SetRange( &pList->m_ScrollBar, 0, pList->m_Items - pList->m_NumView);

	update_List(hBox);

	return TRUE;
}


BX_INT BxList_GetSelected(HBOX hBox)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;

	return pList->m_Pos;
}

BX_INT BxList_GetCount(HBOX hBox)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;

	return pList->m_Items;

}

BX_PSTRING BxList_GetString(HBOX hBox, BX_INT index)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	BXLISTUNITSTRUCT *nLst;
	BX_INT i;

	if(hBox==NULL)
		return NULL;

	if(index < 0)
		return NULL;

	if(pList->m_First == NULL)
		return NULL;

  // Find index
	nLst = pList->m_First;
	for( i = 0; i < index; i++)
	{
		if ( nLst == NULL )
			return NULL;
		nLst = nLst->m_Next;
	}

	return nLst->m_Str;
}

BX_INT BxList_SetString(HBOX hBox, BX_INT index, BX_PSTRING pStr)
{
	BOXSTRUCT *b = (BOXSTRUCT *)hBox;
	BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	BXLISTUNITSTRUCT *nLst;
	BX_INT i;

	if(hBox==NULL)
		return FALSE;

	if(index < 0)
		return FALSE;

	if(pList->m_First == NULL)
		return FALSE;

  // Find index
	nLst = pList->m_First;
	for( i = 0; i < index; i++)
	{
		if ( nLst == NULL )
			return FALSE;
		nLst = nLst->m_Next;
	}

	BxStringCopy(nLst->m_Str, pStr);

	return TRUE;

}

BX_VOID BxList_Update(HBOX hBox)
{
	update_List(hBox);
}

BX_INT BxList_SetSelected(HBOX hBox, BX_INT index)
{
  BOXSTRUCT *b = (BOXSTRUCT *)hBox;
  BXLISTSTRUCT *pList = (BXLISTSTRUCT *)b->m_userData;
	//  BX_INT oldPos = pList->m_Pos;
  
  pList->m_Pos = index;

  if(pList->m_Items - pList->m_NumView > 0)
  {
    if( pList->m_Pos-pList->m_NumView >= 0 )
      pList->m_ViewPos = pList->m_Pos-pList->m_NumView+1;
    else
      pList->m_ViewPos = 0;
    BxScrollBar_SetPos( &pList->m_ScrollBar, pList->m_Pos-pList->m_NumView+1);
  }

  update_List(hBox);

  return 0;
}
