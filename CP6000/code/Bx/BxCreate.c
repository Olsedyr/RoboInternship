#include "BxPrivate.h"

BX_BOOL DestroyBox(
	HBOX  hbox 	// handle of Box to destroy  
)
{
	// 	BxSendMessage(hbox, BM_CLEAR, 0, 0);
	return BxPostMessage(hbox, BM_DESTROY, 0, 0);
}

BX_BOOL BxShowBox(HBOX hBox, BX_INT nCmdShow )
{ 
	switch(nCmdShow) {
		case TRUE:
			return BxPostMessage(hBox, BM_SHOWBOX, (BX_WPARAM)TRUE, 0);
		case FALSE:
			return BxPostMessage(hBox, BM_SHOWBOX, (BX_WPARAM)FALSE, 0);
	}
	return FALSE;
}

BX_BOOL CloseBox(
	HBOX  hbox 	// handle of Box to minimize
)
{
	return BxPostMessage(hbox, BM_CLOSE, 0, 0);
}	


BX_BOOL BxEnableBox(HBOX hBox, BX_BOOL bEnable)
{
	BOXSTRUCT *b = hBox;

	if(b==NULL)
		return FALSE;

	BxSendMessage(hBox, BM_ENABLE, (BX_WPARAM)(BX_BOOL)(bEnable), 0L);
	return TRUE;
}

BX_BOOL
IsBoxEnabled(
	HBOX hBox)
{
	BOXSTRUCT *b = hBox;

	if(b==NULL)
		return FALSE;

	if(b->style & BXS_DISABLED)
		return FALSE;
	return TRUE;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//// 									SetBoxText										///////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

BX_BOOL
BxSetBoxText(
	HBOX hBox,
	BX_PSTRING lpString)
{
	BxSendMessage(hBox, BM_SETTEXT, 0, (BX_LPARAM)lpString);
	return TRUE;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//// 									GetBoxText										///////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
BX_INT
BxGetBoxText(
	HBOX hBox,
	BX_PSTRING lpString,
	BX_INT nMaxCount)
{
	BOXSTRUCT *b = hBox;

	if(hBox==NULL)
		return 0;

	BxStringNCopy((BX_CHAR*)lpString, (const BX_CHAR*)&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], nMaxCount);
	return BxStringLength((BX_CHAR*)lpString);
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//// 									GetBoxTextLength							///////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
BX_INT
BxGetBoxTextLength(
	HBOX hBox)
{
	BOXSTRUCT *b = hBox;

	if(hBox==NULL)
		return 0;

	return BxStringLength((BX_CHAR*)&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]);
}

/**/
BOXSTRUCT *GetBoxStruct(BX_UINT Index)
{
	return NULL; //&BOXLIST[Index];
}

/**/
HBOX BxCreateBox(PINSTANCE hInstance, BOXSTRUCT *b, BXPROC __BoxProc)
{
	HBOX hbox = b;
	PINSTANCESTRUCT pInstance = (PINSTANCESTRUCT) hInstance;

	pInstance->endDialog = FALSE;
	b->hInstance = hInstance;
	b->boxProc = __BoxProc;

	if(b->userLevel < MIN_USER_LEVEL || b->userLevel > MAX_USER_LEVEL)
		b->userLevel = DEFAULT_USER_LEVEL;

	BxCreateDC(&b->m_BxDC);

	b->m_BxDC.m_clipRect.left = b->rc.left+1;
	b->m_BxDC.m_clipRect.top = b->rc.top+1;
	b->m_BxDC.m_clipRect.right = b->rc.right-1;
	b->m_BxDC.m_clipRect.bottom = b->rc.bottom-1;

	BxSetFont(&b->m_BxDC, DefaultFont);

	//  b->m_userData = NULL;
    
	switch(b->type) {
		case DEFBOX :
			b->hCls = hCls_DefBox; 
			BxSetFont(&b->m_BxDC, DefaultFont);
			BxSetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
			break;

		case DIALOG :
			b->hCls = hCls_DefBox; 
			BxSetFont(&b->m_BxDC, DefaultFont);
			BxSetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
			break;

		case BUTTON :
			switch(b->style & BBS_TYPEMASK) {
				case BBS_CHECKBOX:
				case BBS_RADIOBOX:
					b->hCls = hCls_CheckBox;
					if(b->boxProc==NULL)
						b->boxProc = DefPushButtonProc;
					BxSetFont(&b->m_BxDC, DefaultButtonFont);
					BxSetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
					break;

				default: // BBS_PUSHBUTTON
					b->hCls = hCls_Button;
          if(b->boxProc==NULL)
            b->boxProc = DefPushButtonProc;
          if(b->style & BBS_ICON || b->style & BBS_BITMAP)
          {
            BxSetFont(&b->m_BxDC, DefaultButtonFont);
            BxSetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
          }
          else
          {
            BxSetFont(&b->m_BxDC, DefaultButtonFont);
            BxSetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
          }
			}
			break;

	case STATIC :
	case LIST :
			b->hCls = hCls_Static;
			if(b->boxProc==NULL)
				b->boxProc = DefStaticProc;
      if((b->style & BSS_TYPEMASK) == BSS_WHITEFRAME)
			  BxSetFont(&b->m_BxDC, DefaultSmallFont);
      else
			  BxSetFont(&b->m_BxDC, DefaultButtonFont);
//		    SetTextAlign(&b->m_BxDC, BX_TA_LEFT | BX_TA_TOP);
			break;

		case EDIT :
			b->hCls = hCls_Edit;
			if(b->boxProc==NULL)
				b->boxProc = DefEditProc;
			BxSetFont(&b->m_BxDC, DefaultButtonFont);
			break;
		default :
			return (NULL);
	}

	if(BxSendMessage(hbox, BM_CREATE, 0L, 0L))
		return (hbox);
	else
		return (NULL);
}


HBOX BxSetFocus( HBOX hBox )
{
	HBOX hTmp = BXFOCUSBOX;

  if(hBox == NULL) return NULL;
  
  if(BXFOCUSBOX!=NULL)
		BxSendMessage(BXFOCUSBOX, BM_KILLFOCUS, (BX_WPARAM)(HBOX)hBox, 0);

	BxSendMessage(hBox, BM_SETFOCUS, (BX_WPARAM)(HBOX)BXFOCUSBOX, 0);

	BXFOCUSBOX = hBox;

	return hTmp;
}

HBOX BxGetFocus( BX_VOID )
{
	return BXFOCUSBOX;

}
