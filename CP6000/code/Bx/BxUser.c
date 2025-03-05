
#include "BxPrivate.h"
#include "BxEvent.h"

extern BX_BOOL IsDirty(HBOX pBx);
extern BX_VOID DestroyDialogBox(HBOX hBox);
/*********  Globals**********/

static BX_INT ActiveUserLevel = DEFAULT_USER_LEVEL;

BX_INT BxSetUserLevel(BX_INT NewUserLevel)
{
  BX_INT oldUserLevel = ActiveUserLevel;

  if(NewUserLevel >= MIN_USER_LEVEL && NewUserLevel <= MAX_USER_LEVEL)
    ActiveUserLevel = NewUserLevel;

  return oldUserLevel;
}

BX_INT BxGetUserLevel(BX_VOID)
{
	return ActiveUserLevel;
}

HBOX SetActiveBox(HBOX hBx, BX_BOOL clicked)
{
	HBOX preActive = BXACTIVEBOX;

  if(hBx==NULL)
    return NULL;
    
  if(preActive!=NULL)
	{
		BxSendMessage(preActive, BM_ACTIVATE, BX_LOWORD(BA_INACTIVE), (BX_LPARAM)hBx);
	}

	BXACTIVEBOX = hBx;

	if(clicked)
		BxSendMessage(hBx, BM_ACTIVATE, BX_LOWORD(BA_CLICKACTIVE), (BX_LPARAM)NULL);
	else
		BxSendMessage(hBx, BM_ACTIVATE, BX_LOWORD(BA_ACTIVE), (BX_LPARAM)NULL);

	return preActive;
}

BxDC* BxGetBoxDC(HBOX hBx)
{
	return &((PBOXSTRUCT)hBx)->m_BxDC;
}

HBOX BxGetParent(HBOX hBx)
{
	return (HBOX)((PBOXSTRUCT)hBx)->bParent;
}

PINSTANCE GetAppInstance(HBOX hBx)
{
	return ((BOXSTRUCT*)hBx)->hInstance;
}

BX_VOID BxRequestPaint(HBOX hBx)
{
  if(hBx==NULL) return;
	((PBOXSTRUCT)hBx)->m_Dirty = TRUE;
	if(((PINSTANCESTRUCT)GetAppInstance(hBx))!=NULL)
	{
		((PINSTANCESTRUCT)GetAppInstance(hBx))->m_PaintFlag = TRUE;
		BxSetEvent();
	}
}

BX_VOID BxRequestRectPaint(HBOX hBx, BX_PRECT pRc)
{
	PBOXSTRUCT b = (PBOXSTRUCT)hBx;

	if(pRc==NULL)
		BxRequestPaint(hBx);

	b = b->bNext;
	while(b)
	{
		if(BxRectInRect(pRc, &b->rc))
			BxRequestPaint((HBOX)b);
		b = b->bNext;
	}
}

static BX_BOOL IsPaint(HBOX hbox)
{
	BOXSTRUCT *b = hbox;
	INSTANCESTRUCT *hInstance = b->hInstance;

	return hInstance->m_PaintFlag;
}
static BX_VOID ClearPaintFlag(HBOX hbox)
{
	((PINSTANCESTRUCT)GetAppInstance(hbox))->m_PaintFlag = FALSE;
}

BX_VOID BxGetBoxRect(HBOX hBx, BX_PRECT pRc)
{
	if(hBx==NULL) return;

	pRc->left = ((PBOXSTRUCT)hBx)->rc.left;
	pRc->top = ((PBOXSTRUCT)hBx)->rc.top;
	pRc->right = ((PBOXSTRUCT)hBx)->rc.right;
	pRc->bottom = ((PBOXSTRUCT)hBx)->rc.bottom;
}

BX_BOOL IsChild(HBOX hBoxParent, HBOX hBox)
{
	PBOXSTRUCT a = (PBOXSTRUCT)hBoxParent, b = (PBOXSTRUCT)hBox;

	a = a->bNext;
	while(a!=NULL)
	{
		if(a == b)
			return TRUE;
		a = a->bNext;
	}
	return FALSE;
}


HBOX HitTest(BX_UINT x, BX_UINT y)
{
	BOXSTRUCT *hit, *b = BXACTIVEDLGBOX;

	hit = b;
	b = b->bNext;
	while(b!=NULL)
	{
		if(IsVisible((HBOX)b) && !IsDisabled((HBOX)b) && b->type != STATIC && b->type != LIST && BxPointInRect(&b->rc, x, y))
			hit = b;
		b = b->bNext;
	}
	return hit;
}

BX_LRESULT BoxProc(

	HBOX  hBox,	// handle of box
	BX_UINT  uMsg,	// message identifier
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)
{
	BOXSTRUCT *b = hBox;

    // if client_socket and if msg == BM_PAINT or msg == BM_CLEAR then
    //   send to client_socket msg, hBox, wParam, lParam

	return b->boxProc(hBox, uMsg, wParam, lParam);
}	


BX_LRESULT DefBoxProc(

	HBOX  hBox,	// handle of box
	BX_UINT  uMsg,	// message identifier
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)
{
	BOXSTRUCT *b = hBox;
	CLASSDEF  *cls = b->hCls;

	switch(uMsg) {
		HANDLE_MSG(hBox,BM_QUIT, cls->Cls_OnQuit); return 0L; break;
		HANDLE_MSG(hBox,BM_CREATE, cls->Cls_OnCreate); break;
		HANDLE_MSG(hBox,BM_SHOWBOX, cls->Cls_OnShowBox); break;
		HANDLE_MSG(hBox,BM_DESTROY, cls->Cls_OnDestroy); break;
		HANDLE_MSG(hBox,BM_ENABLE, cls->Cls_OnEnable); break;
		HANDLE_MSG(hBox,BM_SETTEXT, cls->Cls_OnSetText); break;
		HANDLE_MSG(hBox,BM_GETTEXT, cls->Cls_OnGetText); break;
		HANDLE_MSG(hBox,BM_GETTEXTLENGTH, cls->Cls_OnGetTextLength); break;
		HANDLE_MSG(hBox,BM_CLOSE, cls->Cls_OnClose); break;
		HANDLE_MSG(hBox,BM_PAINT, cls->Cls_OnPaint); break;
		HANDLE_MSG(hBox,BM_NCPAINT, cls->Cls_OnNCPaint); break;
		HANDLE_MSG(hBox,BM_NCHITTEST, cls->Cls_OnNCHitTest); break;
		HANDLE_MSG(hBox,BM_ACTIVATE, cls->Cls_OnActivate); break;
		HANDLE_MSG(hBox,BM_SETFOCUS, cls->Cls_OnSetFocus); break;
		HANDLE_MSG(hBox,BM_KILLFOCUS, cls->Cls_OnKillFocus); break;
		HANDLE_MSG(hBox,BM_KEYDOWN, cls->Cls_OnKeyDown); break;
		HANDLE_MSG(hBox,BM_KEYUP, cls->Cls_OnKeyUp); break;
		HANDLE_MSG(hBox,BM_CHAR, cls->Cls_OnChar); break;
		HANDLE_MSG(hBox,BM_DEADCHAR, cls->Cls_OnDeadChar); break;
		HANDLE_MSG(hBox,BM_SYSKEYDOWN, cls->Cls_OnSysKeyDown); break;
		HANDLE_MSG(hBox,BM_SYSKEYUP, cls->Cls_OnSysKeyUp); break;
		HANDLE_MSG(hBox,BM_SYSCHAR, cls->Cls_OnSysChar); break;
		HANDLE_MSG(hBox,BM_SYSDEADCHAR, cls->Cls_OnSysDeadChar); break;
		HANDLE_MSG(hBox,BM_MOUSEMOVE, cls->Cls_OnMouseMove); break;
		HANDLE_MSG(hBox,BM_LBUTTONDOWN, cls->Cls_OnLButtonDown); break;
//  HANDLE_MSG(hBox,BM_LBUTTONDBLCLK, cls->Cls_OnLButtonDblClk); break;
		HANDLE_MSG(hBox,BM_LBUTTONUP, cls->Cls_OnLButtonUp); break;
//  HANDLE_MSG(hBox,BM_NCMOUSEMOVE, cls->Cls_OnNCMouseMove); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONDOWN, cls->Cls_OnNCLButtonDown); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONDBLCLK, cls->Cls_OnNCLButtonDblClk); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONUP, cls->Cls_OnNCLButtonUp); break;
//  HANDLE_MSG(hBox,BM_MOUSEACTIVATE, cls->Cls_OnMouseActivate); break;
		HANDLE_MSG(hBox,BM_CUT, cls->Cls_OnCut); break;
		HANDLE_MSG(hBox,BM_CLEAR, cls->Cls_OnClear); break;
		HANDLE_MSG(hBox,BM_SETCURSOR, cls->Cls_OnSetCursor); break;
		HANDLE_MSG(hBox,BM_SYSCOMMAND, cls->Cls_OnSysCommand); break;

	}
	return 0L;
}	


BX_LRESULT DefDlgBoxProc(

	HBOX  hBox,	// handle of box
	BX_UINT  uMsg,	// message identifier
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)
{
	BOXSTRUCT *b = hBox;
	CLASSDEF  *cls = b->hCls;

	if(b->dlgProc(hBox, uMsg, wParam, lParam)==TRUE)
		return 0L;

	switch(uMsg) {
		HANDLE_MSG(hBox,BM_QUIT, cls->Cls_OnQuit); return 0L; break;
		HANDLE_MSG(hBox,BM_CREATE, cls->Cls_OnCreate); break;
		HANDLE_MSG(hBox,BM_SHOWBOX, cls->Cls_OnShowBox); break;
		HANDLE_MSG(hBox,BM_DESTROY, cls->Cls_OnDestroy); break;
		HANDLE_MSG(hBox,BM_ENABLE, cls->Cls_OnEnable); break;
		HANDLE_MSG(hBox,BM_SETTEXT, cls->Cls_OnSetText); break;
		HANDLE_MSG(hBox,BM_GETTEXT, cls->Cls_OnGetText); break;
		HANDLE_MSG(hBox,BM_GETTEXTLENGTH, cls->Cls_OnGetTextLength); break;
		HANDLE_MSG(hBox,BM_CLOSE, cls->Cls_OnClose); break;
		HANDLE_MSG(hBox,BM_PAINT, cls->Cls_OnPaint); break;
		HANDLE_MSG(hBox,BM_NCPAINT, cls->Cls_OnNCPaint); break;
		HANDLE_MSG(hBox,BM_NCHITTEST, cls->Cls_OnNCHitTest); break;
		HANDLE_MSG(hBox,BM_ACTIVATE, cls->Cls_OnActivate); break;
		HANDLE_MSG(hBox,BM_SETFOCUS, cls->Cls_OnSetFocus); break;
		HANDLE_MSG(hBox,BM_KILLFOCUS, cls->Cls_OnKillFocus); break;
		HANDLE_MSG(hBox,BM_KEYDOWN, cls->Cls_OnKeyDown); break;
		HANDLE_MSG(hBox,BM_KEYUP, cls->Cls_OnKeyUp); break;
		HANDLE_MSG(hBox,BM_CHAR, cls->Cls_OnChar); break;
		HANDLE_MSG(hBox,BM_DEADCHAR, cls->Cls_OnDeadChar); break;
		HANDLE_MSG(hBox,BM_SYSKEYDOWN, cls->Cls_OnSysKeyDown); break;
		HANDLE_MSG(hBox,BM_SYSKEYUP, cls->Cls_OnSysKeyUp); break;
		HANDLE_MSG(hBox,BM_SYSCHAR, cls->Cls_OnSysChar); break;
		HANDLE_MSG(hBox,BM_SYSDEADCHAR, cls->Cls_OnSysDeadChar); break;
		HANDLE_MSG(hBox,BM_MOUSEMOVE, cls->Cls_OnMouseMove); break;
		HANDLE_MSG(hBox,BM_LBUTTONDOWN, cls->Cls_OnLButtonDown); break;
//  HANDLE_MSG(hBox,BM_LBUTTONDBLCLK, cls->Cls_OnLButtonDblClk); break;
		HANDLE_MSG(hBox,BM_LBUTTONUP, cls->Cls_OnLButtonUp); break;
//  HANDLE_MSG(hBox,BM_NCMOUSEMOVE, cls->Cls_OnNCMouseMove); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONDOWN, cls->Cls_OnNCLButtonDown); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONDBLCLK, cls->Cls_OnNCLButtonDblClk); break;
//  HANDLE_MSG(hBox,BM_NCLBUTTONUP, cls->Cls_OnNCLButtonUp); break;
//  HANDLE_MSG(hBox,BM_MOUSEACTIVATE, cls->Cls_OnMouseActivate); break;
		HANDLE_MSG(hBox,BM_CUT, cls->Cls_OnCut); break;
		HANDLE_MSG(hBox,BM_CLEAR, cls->Cls_OnClear); break;
		HANDLE_MSG(hBox,BM_SETCURSOR, cls->Cls_OnSetCursor); break;
		HANDLE_MSG(hBox,BM_SYSCOMMAND, cls->Cls_OnSysCommand); break;

	}
	return 0L;
}	


BX_BOOL GetMsgFromInstance(HBOX hBox, BX_PMSG lpmsg)
{
	BX_INT i;
	BOXSTRUCT *b = hBox;
	INSTANCESTRUCT *hInstance = b->hInstance;

	if(hInstance->msgInQueue <= 0)
		return FALSE;

	lpmsg->hbox = hInstance->InstanceMsg[0].hbox;
	lpmsg->message = hInstance->InstanceMsg[0].message;
	lpmsg->wParam = hInstance->InstanceMsg[0].wParam;
	lpmsg->lParam = hInstance->InstanceMsg[0].lParam;
	lpmsg->time = hInstance->InstanceMsg[0].time;
	lpmsg->pt.x = hInstance->InstanceMsg[0].pt.x;
	lpmsg->pt.y = hInstance->InstanceMsg[0].pt.y;

	for(i=0;i<hInstance->msgInQueue;i++)
		hInstance->InstanceMsg[i] = hInstance->InstanceMsg[i+1];
	hInstance->msgInQueue--;

	return TRUE;
}


BX_BOOL PeekMsgFromInstance(HBOX hBox, BX_PMSG lpmsg, BX_INT bRemoveMsg)
{
	BX_INT i;
	BOXSTRUCT *b = hBox;
	INSTANCESTRUCT *hInstance = b->hInstance;

	if(hInstance->msgInQueue <= 0)
		return FALSE;

	for(i=0;i<hInstance->msgInQueue;i++)
	{
		lpmsg->hbox = hInstance->InstanceMsg[i].hbox;
		lpmsg->message = hInstance->InstanceMsg[i].message;
		lpmsg->wParam = hInstance->InstanceMsg[i].wParam;
		lpmsg->lParam = hInstance->InstanceMsg[i].lParam;
		lpmsg->time = hInstance->InstanceMsg[i].time;
		lpmsg->pt.x = hInstance->InstanceMsg[i].pt.x;
		lpmsg->pt.y = hInstance->InstanceMsg[i].pt.y;
		if(hBox == lpmsg->hbox || IsChild(hBox, lpmsg->hbox))
			goto remove_msg;
	}
	return FALSE;

remove_msg:
	if(!(bRemoveMsg & PM_REMOVE))
		return TRUE;

	for(;i<hInstance->msgInQueue;i++)
		hInstance->InstanceMsg[i] = hInstance->InstanceMsg[i+1];
	hInstance->msgInQueue--;

	return TRUE;
}



BX_BOOL BxPostMessage(

	HBOX  hbox,	// handle of destination box
	BX_UINT  uMsg,	// message to post 
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)	
{
	BOXSTRUCT *b = hbox;
	INSTANCESTRUCT *hInstance = b->hInstance;

	if(hInstance->msgInQueue < MAX_BOX_MSG )
	{
		hInstance->InstanceMsg[hInstance->msgInQueue].hbox = hbox;
		hInstance->InstanceMsg[hInstance->msgInQueue].message = uMsg;
		hInstance->InstanceMsg[hInstance->msgInQueue].wParam = wParam;
		hInstance->InstanceMsg[hInstance->msgInQueue].lParam = lParam;
//    hInstance->InstanceMsg[hInstance->msgInQueue].time = (DWORD)time(NULL);
		hInstance->InstanceMsg[hInstance->msgInQueue].pt.x = 0;
		hInstance->InstanceMsg[hInstance->msgInQueue].pt.y = 0;
		hInstance->msgInQueue++;
		return TRUE;
	}
	return FALSE;
}

BX_LRESULT BxSendMessage(

	HBOX  hbox,	// handle of destination Box
	BX_UINT  uMsg,	// message to send
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
)
{
	return BoxProc(hbox, uMsg, wParam, lParam);
}

BX_BOOL BxPeekMessage( 

	BX_PMSG lpMsg, 
	HBOX hBox, 
	BX_UINT uMsgFilterMin, 
	BX_UINT uMsgFilterMax, 
	BX_UINT bRemoveMsg 
)
{
	HBOX pChild;
	lpMsg->hbox = hBox;

	if(PeekMsgFromInstance(hBox, lpMsg, bRemoveMsg))
	{
		return TRUE;
	}

	if(IsPaint(hBox))
	{
		if(IsDirty(hBox))
		{
			lpMsg->hbox = hBox;
			lpMsg->message = BM_PAINT;
			lpMsg->wParam = 0;
			lpMsg->lParam = 0;
			lpMsg->time = 0;
			lpMsg->pt.x = 0;
			lpMsg->pt.y = 0;
			return TRUE;
		}

		pChild = BxFindDirtyChild(hBox);
		if(pChild != NULL)
		{
			lpMsg->hbox = pChild;
			lpMsg->message = BM_PAINT;
			lpMsg->wParam = 0;
			lpMsg->lParam = 0;
			lpMsg->time = 0;
			lpMsg->pt.x = 0;
			lpMsg->pt.y = 0;
			return TRUE;
		}
		ClearPaintFlag(hBox);
	}
	return FALSE;
}

BX_BOOL BxGetMessage(

	BX_PMSG  pMsg,	// address of structure with message
	HBOX  hbox,	// handle of box
	BX_UINT  uMsgFilterMin,	// first message
	BX_UINT  uMsgFilterMax 	// last message
)	
{
	BX_EVENTSTRUCT ev;
	HBOX pChild;

	pMsg->hbox = hbox;

	if(GetMsgFromInstance(hbox, pMsg))
	{
		if(pMsg->message == BM_QUIT)
		{
//	DispatchMessage(lpmsg);
			return FALSE;
		}
		return TRUE;
	}

	if(BxGetSystemEvent(&ev))
	{
		BxConvertEventToMessage(pMsg, &ev);
		if(ev.type == BX_MOUSE_EVENT)
			pMsg->hbox = HitTest(BX_LOWORD(pMsg->lParam), BX_HIWORD(pMsg->lParam));

		if(ev.type == BX_KBD_EVENT)
			pMsg->hbox = BXFOCUSBOX;

		return TRUE;
	}

	if(IsPaint(hbox))
	{
		if(IsDirty(hbox))
		{
			pMsg->hbox = hbox;
			pMsg->message = BM_PAINT;
			pMsg->wParam = 0;
			pMsg->lParam = 0;
			pMsg->time = 0;
			pMsg->pt.x = 0;
			pMsg->pt.y = 0;
			return TRUE;
		}

		pChild = BxFindDirtyChild(hbox);
		if(pChild != NULL)
		{
			pMsg->hbox = pChild;
			pMsg->message = BM_PAINT;
			pMsg->wParam = 0;
			pMsg->lParam = 0;
			pMsg->time = 0;
			pMsg->pt.x = 0;
			pMsg->pt.y = 0;
			return TRUE;
		}
    BxUpdateView(hbox);
		ClearPaintFlag(hbox);
	}

	pMsg->message = BM_NULL;

	return TRUE;
}


BX_INT TranlateVirtualKey(BX_INT vkKey, BX_BOOL Shift)
{
/*	if(Shift)
		return ShiftTranslationTable[vkKey]);
	else
		return TranslationTable[vkKey];
*/
	return 0;
}

static BX_BOOL SHIFTKEY = FALSE;

BX_BOOL BxTranslateMessage(CONST BX_MSG* lpMsg)
{

	BX_CHAR tC;

	if(lpMsg->message == BM_KEYDOWN)
	{
		if((BX_INT)lpMsg->wParam == VK_SHIFT)
		{
			SHIFTKEY = TRUE;
			return TRUE;
		}

		if((BX_INT)lpMsg->wParam == VK_BACK)
		{
			return TRUE;
		}

//	  tC = TranslateVirtualKey((INT)lpMsg->wParam, SHIFTKEY);
		tC = (BX_CHAR)lpMsg->wParam;

		if(tC != 0)
		{
			BxPostMessage(lpMsg->hbox, BM_CHAR, 
				(BX_WPARAM)tC,
				(BX_LPARAM)lpMsg->lParam);
			return TRUE;
		}
		if(lpMsg->message == BM_KEYUP)
		{
			if((BX_INT)lpMsg->wParam == VK_SHIFT)
			{
				SHIFTKEY = FALSE;
				return TRUE;
			}
			if((BX_INT)lpMsg->wParam == VK_BACK)
			{
				return TRUE;
			}
		}

		return TRUE;
	}

	return FALSE;
}

BX_BOOL BxGetDlgMessage(

	BX_PMSG  pMsg,	// address of structure with message

	HBOX  hbox,	// handle of box
	BX_UINT  uMsgFilterMin,	// first message
	BX_UINT  uMsgFilterMax 	// last message
)	
{
	BX_EVENTSTRUCT ev;
	HBOX pChild;

	pMsg->hbox = hbox;

	if(IsEndDialog(hbox))
	{
		BOXSTRUCT *b = hbox;
		INSTANCESTRUCT *hInstance = b->hInstance;
		DestroyDialogBox(hbox);
		hInstance->m_PaintFlag=FALSE;
		while(BxPeekMessage(pMsg, hbox, 0, 0, PM_REMOVE))
		{
			BxTranslateMessage( pMsg ) ;
			BxDispatchMessage(pMsg);
		}
		return FALSE;
	}

	if(GetMsgFromInstance(hbox, pMsg))
	{
		return TRUE;
	}

	if(BxGetSystemEvent(&ev))
	{
		BxConvertEventToMessage(pMsg, &ev);
		if(ev.type == BX_MOUSE_EVENT)
			pMsg->hbox = HitTest(BX_LOWORD(pMsg->lParam), BX_HIWORD(pMsg->lParam));

		if(ev.type == BX_KBD_EVENT)
			pMsg->hbox = BXFOCUSBOX;

		return TRUE;
	}

	if(IsPaint(hbox))
	{
		if(IsDirty(hbox))
		{
			pMsg->hbox = hbox;
			pMsg->message = BM_PAINT;
			pMsg->wParam = 0;
			pMsg->lParam = 0;
			pMsg->time = 0;
			pMsg->pt.x = 0;
			pMsg->pt.y = 0;
			return TRUE;
		}

    pChild = BxFindDirtyChild(hbox);
		if(pChild != NULL)
		{
			pMsg->hbox = pChild;
			pMsg->message = BM_PAINT;
			pMsg->wParam = 0;
			pMsg->lParam = 0;
			pMsg->time = 0;
			pMsg->pt.x = 0;
			pMsg->pt.y = 0;
			return TRUE;
		}
    BxUpdateView(hbox);
		ClearPaintFlag(hbox);
	}

	pMsg->message = BM_NULL;

	return TRUE;
}


BX_LONG BxDispatchMessage(
													CONST BX_MSG  *lpmsg 	// address of structure with message
													)
{
	if(lpmsg->message != BM_NULL)
		return BoxProc(lpmsg->hbox, lpmsg->message, lpmsg->wParam, lpmsg->lParam);
	return 0;
}	

BX_INT BxGetBoxID(HBOX hBox)
{
  if(hBox != NULL)
    return ((PBOXSTRUCT)hBox)->ID;
  return -1;
}
