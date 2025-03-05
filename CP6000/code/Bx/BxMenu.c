/***************************************************************************
                          BxMenu.c  -  description
                             -------------------
    begin                : Mon Aug 11 2003
    copyright            : (C) 2003 by lms
    email                : lms@maercher.com
 ***************************************************************************/
#include "BxPrivate.h"
#include "BxGdi.h"
#include "BxEvent.h"

static BX_INT __internalDoMenu(HBOX hBox);
extern BX_BOOL GrapBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc);
extern BX_BOOL PutBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc);
extern BX_BOOL GreyFramebuffer(BX_VOID);


HBOX BxMenu_Create( HBOX hBox, BXMENUSTRUCT *pBxMenu)
{
  BOXSTRUCT *mdlg, *bs = (BOXSTRUCT *)hBox;
  BXMENUSTRUCT *pMnu;
  
  if(pBxMenu==NULL)
    return NULL;

  if(hBox==NULL)
    return NULL;

  pBxMenu->Mnu = (PBOXSTRUCT)BxMemAlloc(sizeof(BOXSTRUCT));
  if(pBxMenu->Mnu==NULL)
    return NULL;

  mdlg = (PBOXSTRUCT)pBxMenu->Mnu;
  
  pMnu = (BXMENUSTRUCT *)BxMemAlloc(sizeof(BXMENUSTRUCT));
  if(pMnu==NULL)
    return NULL;

  pMnu->type = MENU;
  pMnu->mnufunc = NULL;

  mdlg->ID    = 1000 + bs->ID;
  mdlg->rc.left    = bs->rc.left;
  mdlg->rc.top     = bs->rc.top;
  mdlg->rc.right   = bs->rc.right;
  mdlg->rc.bottom  = bs->rc.bottom;
  mdlg->type       = DIALOG;
  mdlg->lpBoxStr = NULL;
  mdlg->style = BXS_VISIBLE;
  mdlg->bNext      = NULL;
  mdlg->bParent    = bs;
  mdlg->userLevel  = bs->userLevel;
  mdlg->boxState   = 0;
  
  bs->m_menuData = (BX_PVOID)pBxMenu;
  mdlg->m_menuData = (BX_PVOID)pMnu;

  return (HBOX)mdlg;
}


HBOX BxMenu_Add( HBOX hBox, BX_PSTRING pMnuTxt, BX_INT type, BX_BOOL(*connect)(HBOX hBox), BX_BOOL state, BxIcon *pIco)
{
  BOXSTRUCT *mnu, *mdlg, *ptr;
  BXMENUSTRUCT *pBxMenu = (BXMENUSTRUCT*)((PBOXSTRUCT)hBox)->m_menuData;
  BXMENUSTRUCT *pMnu;
  BX_INT idcnt=0;  
  //BX_INT mxcnt=0;  
  //BX_INT col_num=0;
	
  if(hBox==NULL)
    return NULL;

  if(pBxMenu->type==SUB)
  {
    mnu = (PBOXSTRUCT)BxMenu_Add( pBxMenu->Mnu, pMnuTxt, type, connect, state, pIco);
    return (HBOX)mnu;
  }
  
  pMnu = (BXMENUSTRUCT *)BxMemAlloc(sizeof(BXMENUSTRUCT));
  if(pMnu==NULL)
    return NULL;

  mnu = (PBOXSTRUCT)BxMemAlloc(sizeof(BOXSTRUCT));
  if(mnu==NULL)
    return FALSE;

  pMnu->type = type;
  pMnu->mnufunc = connect;
    
  mdlg = (PBOXSTRUCT)hBox;
  ptr = mdlg->bNext;
  if(ptr!=NULL)
  {
    idcnt++;
    while(ptr->bNext!=NULL)
    {
      idcnt++;
      ptr = ptr->bNext;
    }
  }

  mnu->MsgResult = 0;
  mnu->ID    = idcnt + mdlg->ID;

  /* overwritten in AdjustMenuGeometry
  if((idcnt+1)*MINMENUHEIGHT > 596) // midlertidigt
  {
    col_num = 596 / ((idcnt+1)*MINMENUHEIGHT);
    mxcnt = 596 / MINMENUHEIGHT;
  }
  
  mnu->rc.left    = 1 + (col_num * MINMENUWIDTH);
  mnu->rc.right   = (col_num * MINMENUWIDTH) + MINMENUWIDTH - 1;
  mdlg->rc.right   = mdlg->rc.left + MINMENUWIDTH + 1;
  mdlg->rc.top = mdlg->rc.bottom - ((idcnt+1)*MINMENUHEIGHT);
  mnu->rc.bottom  = ((idcnt-(mxcnt*col_num))+1)*(MINMENUHEIGHT);
  mnu->rc.top     = mnu->rc.bottom - MINMENUHEIGHT;
  */

  mnu->type       = BUTTON;
  mnu->lpBoxStr = (BX_PSTRING)BxMemAlloc(BxStringLength(pMnuTxt) + 2);
  BxStringCopy(mnu->lpBoxStr, pMnuTxt);
  if(state)
    mnu->style = BBS_PUSHBUTTON|BXS_VISIBLE;
  else
    mnu->style = BBS_PUSHBUTTON|BXS_VISIBLE|BXS_DISABLED;
  mnu->bNext      = NULL;
  mnu->bParent    = mdlg;
  mnu->userLevel  = mdlg->userLevel;
  mnu->boxState   = 0;

  if(pIco!=NULL)
  {
    mnu->style |= BBS_ICON;
    mnu->m_image = (BX_PVOID)pIco;
  }

  mnu->m_menuData = pMnu;

  if(ptr==NULL)
    mdlg->bNext = mnu;
  else
    ptr->bNext = mnu;
  
  if(type==SUB)
  {
    BxMenu_Create((HBOX)mnu, pMnu);
    pMnu->mnufunc = NULL;

    if(!(mnu->style & BBS_ICON))
    {
      mnu->style |= BBS_BITMAP;
      mnu->m_image = (BX_PVOID)BxSystemResourceLoadBxBitmap(20);
    }
  }

  return (HBOX)mnu;
}


BX_BOOL BxMenu_EndMenu(HBOX hBox, BX_INT nResult)
{
  PBOXSTRUCT pBox = (PBOXSTRUCT)hBox;

  pBox->MsgResult = nResult;

  return TRUE;
}


BX_INT BxMenu_Destroy(HBOX hBox)
{
  BOXSTRUCT *mnu, *mdlg, *ptr, *bs = (BOXSTRUCT *)hBox;
  BXMENUSTRUCT *pBxMenu = (BXMENUSTRUCT*)bs->m_menuData;
  BXMENUSTRUCT *pMnu;
  
  mdlg = (PBOXSTRUCT)pBxMenu->Mnu;
  ptr = mdlg->bNext;
  while(ptr!=NULL)
  {
    pMnu = (BXMENUSTRUCT*)ptr->m_menuData;
    mnu = ptr;
    ptr = ptr->bNext;
		//    if(mnu->style & BBS_ICON)
		//      BxDeleteIcon((BxIcon*)mnu->m_image);
		//    if(mnu->style & BBS_BITMAP)
		//      BxDeleteBitmap((BxBitmap*)mnu->m_image);
		if (pMnu->type==SUB)
		{
			BxMenu_Destroy(mnu);
		}
    BxMemFree(mnu->lpBoxStr);
    BxMemFree(mnu->m_menuData);
		BxMemFree(mnu);
	}
 	BxMemFree(mdlg->m_menuData);
  BxMemFree(mdlg);
  return 0;
}

static BX_VOID MenuDialog_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
  BX_RECT shadow;
  
  BxCopyRect(&shadow, &b->rc);
  shadow.left -= 40;
  shadow.top -= 40;
  BxSetAlpha(&b->m_BxDC, FALSE);
	// BxSetAlphaLevel(&b->m_BxDC, 200);
  b->m_Dirty = FALSE;
  ShowCursor(FALSE);
  if(b->style & BXS_VISIBLE)
  {
    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
    BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_MENUBOX]);
//    BxRoundRect(&b->m_BxDC, &shadow, 2);
//    BxSetAlpha(&b->m_BxDC, FALSE);
    BxRoundRect(&b->m_BxDC, &b->rc, 2);

    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_CAPTIONTEXT]);
    BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_ACTIVECAPTION]);
    if(b->lpBoxStr!=NULL)
      BxTextOut(&b->m_BxDC, b->rc.left+2, b->rc.top+10, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], BxStringLength(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]));

  }
  else
  {
    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxRoundRect(&b->m_BxDC, &b->rc, 2);
  }
  BxSetDirtyArea(&b->rc);
  //BxSetAlpha(&b->m_BxDC, FALSE);
}

BX_BOOL BxMenuProc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)
{
  BX_BOOL rtn = TRUE;
  BXMENUSTRUCT *pMnu;

  switch(uMsg)
  {
    case BM_PAINT:
      BxUpdateOff();
      MenuDialog_OnPaint( hBox );
      BxUpdateOn();
      break;
    case BM_UPDATE:
      return TRUE;
      break;
    case BM_INITDIALOG:
      return TRUE;
      break;
    case BM_CLOSE:
			((BXMENUSTRUCT*)((PBOXSTRUCT)BxGetParent(hBox))->m_menuData)->mnufunc = NULL;
      BxEndDialog(hBox, FALSE);
      return FALSE;
      break;
    case BM_COMMAND:
    {
      switch(BX_LOWORD(wParam))
      {
        case IDCANCEL:
					BxEndDialog(hBox, IDCANCEL);
					return FALSE;
          break;
			default:
				pMnu = (BXMENUSTRUCT*)((PBOXSTRUCT)lParam)->m_menuData;
				if(pMnu->type==SUB)
				{
					rtn = __internalDoMenu((HBOX)lParam);
					((BXMENUSTRUCT*)((PBOXSTRUCT)BxGetParent(hBox))->m_menuData)->mnufunc = pMnu->mnufunc;
					if(rtn!=FALSE)
					{
						BxEndDialog(hBox, rtn);
						return FALSE;
					}
				}
				else
				{
					((BXMENUSTRUCT*)((PBOXSTRUCT)BxGetParent(hBox))->m_menuData)->mnufunc = pMnu->mnufunc;
					BxEndDialog(hBox, rtn);
					return FALSE;
				}
				return TRUE;
      }
      break;
    }
	default:
    return(DefBoxProc(hBox,uMsg,wParam,lParam));
  }
  return 0L;
}

static BX_VOID MenuButton_Paint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
  BX_RECT irc;

  BxCopyRect(&irc, &b->rc);
  irc.left += (MENUICONWIDTH+20);

  b->m_Dirty = FALSE;

//  BxSetAlpha(&b->m_BxDC, TRUE);
//  BxSetAlphaLevel(&b->m_BxDC, 175);

  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
      case BA_INACTIVE:
        switch(b->style & BBS_TYPEMASK) {
          default:
            if(b->style & BXS_DISABLED)
              BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
            else
//              BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
              BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
            BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
            BxRoundRect(&b->m_BxDC, &b->rc, 2);
            if(b->style & BXS_DISABLED)
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
            else
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);

            if(b->style & BBS_ICON)
            {
              if(b->m_image)
                BxDrawIcon(&b->m_BxDC, b->rc.left+5, b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
            }
            else if(b->style & BBS_BITMAP)
            {
              if(b->m_image)
                BxDrawBitmap(&b->m_BxDC, b->rc.left+5, b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_TRANSPARENT);
            }
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &irc, DT_VCENTER | DT_LEFT);
            break;
        }
        break;
      case BA_ACTIVE:
        switch(b->style & BBS_TYPEMASK) {
          default:
            BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
            //BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
            BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNFACE]);
            BxRoundRect(&b->m_BxDC, &b->rc, 2);
            if(b->style & BXS_DISABLED)
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
            else
              BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNTEXT]);
            //BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNHIGHLIGHT]);
            //BxSetBkColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOX]);
            if(b->style & BBS_ICON)
            {
              if((BX_PICON)b->m_image)
                BxDrawIcon(&b->m_BxDC, b->rc.left+5, b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
            }
            else if(b->style & BBS_BITMAP)
            {
              if(b->m_image)
                BxDrawBitmap(&b->m_BxDC, b->rc.left+5, b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_TRANSPARENT);
            }
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &irc, DT_VCENTER | DT_LEFT);
            break;
        }
        break;
      case BA_CLICKACTIVE:
        switch(b->style & BBS_TYPEMASK) {
          default:
            BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
            BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_HIGHLIGHT]);
            BxRoundRect(&b->m_BxDC, &b->rc, 2);
            BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BTNHIGHLIGHT]);
            if(b->style & BBS_ICON)
            {
              if((BX_PICON)b->m_image)
                BxDrawIcon(&b->m_BxDC, 1+b->rc.left+5, 1+b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PICON)b->m_image)->icoBits->bmHeight/2), (BX_PICON)b->m_image);
            }
            else if(b->style & BBS_BITMAP)
            {
              if(b->m_image)
                BxDrawBitmap(&b->m_BxDC, b->rc.left+5, b->rc.top+(BxRectHeight(&b->rc)/2)-(((BX_PBITMAP)b->m_image)->bmHeight/2), (BX_PBITMAP)b->m_image, BITMAPTYPE_TRANSPARENT);
            }
            BxDrawText(&b->m_BxDC, &b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN], strlen(&b->lpBoxStr[BX_LANGUAGE*BX_DEFSTRLEN]), &irc, DT_VCENTER | DT_LEFT);
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
  BxSetDirtyArea(&b->rc);
//  BxSetAlpha(&b->m_BxDC, FALSE);
}

static BX_LRESULT DefMenuButtonProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
  switch (uMsg)
  {
  case BM_PAINT   :
    MenuButton_Paint( hBox );
    break;
  default:
    return( DefPushButtonProc( hBox, uMsg, wParam, lParam ) ) ;
  }
  return 0L ;
}

HBOX BxCreateMenuDialog(
  PINSTANCE hInstance,
  PBOXSTRUCT b,
  BXDLGPROC  lpDialogFunc 	// pointer to dialog box procedure
)
{
  HBOX hBox;
  BX_RECT bRect;

  if(b==NULL) return NULL;

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
    b->boxProc = DefMenuButtonProc;

    b = b->bNext;
  }

  BxSendMessage(hBox, BM_INITDIALOG, 0, 0);

  ShowDialogBox(hBox);
  BxUpdateView(hBox);

  return hBox;
}

BX_VOID AdjustMenuGeometry(HBOX hBox)
{
  BOXSTRUCT *mdlg, *ptr, *bs = (BOXSTRUCT *)hBox;
  BXMENUSTRUCT *pBxMnu = (BXMENUSTRUCT*)bs->m_menuData;
  BX_INT idcnt=0, i=0, j=0;
  BX_INT minlen = MINMENUWIDTH;
  BX_INT tmin;
  BX_INT col_num=0;
  BX_INT mxcnt=0;
	// BX_INT ilen=0;
  
  mdlg = (PBOXSTRUCT)pBxMnu->Mnu;

  ptr = mdlg->bNext;
  while(ptr!=NULL)
  {
    idcnt++;
/*
    if(ptr->style & BBS_ICON)
    {
      if((BX_PICON)ptr->m_image)
        ilen = MENUICONWIDTH+20;
      else
        ilen = 0;
    }
    else if(ptr->style & BBS_BITMAP)
    {
      if((BX_PBITMAP)ptr->m_image)
        ilen = MENUICONWIDTH+20;
      else
        ilen = 0;
    }
    else
      ilen = 0;
*/      
    tmin = FontStringLength(ptr->lpBoxStr ,DefaultButtonFont) + MENUICONWIDTH+20;  //Box DC is not defined yet.
    if(tmin > minlen)
      minlen = tmin;

    ptr = ptr->bNext;
  }

  mdlg->rc.right = bs->rc.right;

  if((idcnt+1)*MINMENUHEIGHT > 596) // midlertidigt
  {
    col_num = ((idcnt)*MINMENUHEIGHT) / 596;
    mxcnt = 596 / MINMENUHEIGHT;
  }
//  mdlg->rc.left = mdlg->rc.right - minlen - 10 - 2 - (col_num * MINMENUWIDTH);
  mdlg->rc.left = mdlg->rc.right - minlen - 10 - 2 - (col_num * (minlen + 10 + 2)) - 2;

  ptr = mdlg->bNext;
  j = 0;
  while(ptr!=NULL)
  {
    if(mxcnt > 0)
      j = i/mxcnt;
    ptr->rc.left = 2 + (j*(minlen + 10 + 2));
    ptr->rc.right = ptr->rc.left + (minlen + 10 + 2) - 2;
    ptr->rc.top = 2 + ((i - (j*mxcnt))*MINMENUHEIGHT);
    ptr->rc.bottom = ptr->rc.top + MINMENUHEIGHT - 2;
    i++;
    ptr = ptr->bNext;
  }

  if(mxcnt > 0)
  {
    mdlg->rc.top = 1;
    if(col_num < 1)
      mdlg->rc.bottom = mdlg->rc.top + (idcnt*(MINMENUHEIGHT)) + 1;
    else
      mdlg->rc.bottom = mdlg->rc.top + (mxcnt*(MINMENUHEIGHT)) + 2;
  }
  else
  {
    mdlg->rc.top = bs->rc.bottom - (idcnt*(MINMENUHEIGHT));
    mdlg->rc.bottom = mdlg->rc.top + (idcnt*(MINMENUHEIGHT)) + 2;
  }

  if(pBxMnu->type==SUB)
  {
    mdlg->rc.right = bs->rc.left - 2;
    mdlg->rc.left = mdlg->rc.right - minlen - 10 - 2 - (col_num * (minlen + 10 + 2)) - 2;

    if(mdlg->rc.right - minlen - 10 - 2 - (col_num * (minlen + 10 + 2)) - 2 <= 0)
    {
      mdlg->rc.left = 1;
      mdlg->rc.right = mdlg->rc.left + minlen + 10 + 2 + (col_num * (minlen + 10 + 2)) + 2;
    }

    if(mdlg->rc.bottom - (idcnt*(MINMENUHEIGHT)) < 0)
    {
      mdlg->rc.top = 1;
      if(col_num < 1)
        mdlg->rc.bottom = mdlg->rc.top + (idcnt*(MINMENUHEIGHT)) + 1;
      else
        mdlg->rc.bottom = mdlg->rc.top + (mxcnt*(MINMENUHEIGHT)) + 2;
    }

  }
}

static BX_INT __internalDoMenu(HBOX hBox)
{
  BX_MSG msg;
  PINSTANCESTRUCT pInstance;
  HBOX oldBx, pUpBx;
  PBOXSTRUCT b;
  HBOX hBx;
  BX_PBITMAP pBgBmp;
  
  AdjustMenuGeometry(hBox);

  b = (BOXSTRUCT *)((BXMENUSTRUCT*)((BOXSTRUCT *)hBox)->m_menuData)->Mnu;
  pBgBmp = BxCreateCompatibleBitmap(BxRectWidth(&b->rc)+1, BxRectHeight(&b->rc)+1, NULL);
  if(pBgBmp)
    GrapBGFramebuffer(pBgBmp, &b->rc);
    
  hBx = BxCreateMenuDialog(((BOXSTRUCT *)hBox)->hInstance, (BOXSTRUCT *)((BXMENUSTRUCT*)((BOXSTRUCT *)hBox)->m_menuData)->Mnu, BxMenuProc);

  b = ((PBOXSTRUCT)hBx)->bNext;
  if(b!=NULL)
  {
    while((b->type != BUTTON && b != NULL) || IsDisabled((HBOX)b) || ((PBOXSTRUCT)BxGetParent(b))->type != DIALOG)
      b = b->bNext;

    if(b!=NULL)
    {
      ((PBOXSTRUCT)hBx)->m_oldFocus = BxSetFocus((HBOX)b);
      SetActiveBox((HBOX)b, FALSE);
    }
  }

  ((PBOXSTRUCT)hBx)->m_oldActive = BxSetActiveDlgBox(hBx);

  while(BxGetDlgMessage(&msg, hBx, 0, 0))
  {
    if(msg.message == BM_LBUTTONDOWN)
    {
      if(!BxPointInRect(&((PBOXSTRUCT)hBx)->rc, BX_LOWORD(msg.lParam), BX_HIWORD(msg.lParam)))
      {
        BxPostMessage(((PBOXSTRUCT)hBx)->m_oldActive, msg.message, msg.wParam, msg.lParam);
        msg.message = BM_CLOSE;
      }
    }
    if(msg.message != BM_NULL)
    {
      BxTranslateMessage( &msg ) ;
      BxDispatchMessage( &msg ) ;
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

  if(pBgBmp)
  {
    b = (BOXSTRUCT *)((BXMENUSTRUCT*)((BOXSTRUCT *)hBox)->m_menuData)->Mnu;
    PutBGFramebuffer(pBgBmp, &b->rc);
    BxDeleteBitmap(pBgBmp);
  }

  if(((PBOXSTRUCT)hBx)->m_oldActive!=NULL) // not top box
  {
    oldBx = BxSetActiveDlgBox(((PBOXSTRUCT)hBx)->m_oldActive);
//    BxGetBoxRect(oldBx, &pntRc);

//    RequestRectPaint(BxGetActiveDlgBox(), &pntRc);
    ShowDialogBox(BxGetActiveDlgBox());
    BxSetFocus(((PBOXSTRUCT)oldBx)->m_oldFocus);
    SetActiveBox(((PBOXSTRUCT)oldBx)->m_oldFocus, FALSE);
    pInstance = (PINSTANCESTRUCT)((PBOXSTRUCT)BxGetActiveDlgBox())->hInstance;
    pInstance->endDialog = FALSE;
    BxSendMessage(BxGetActiveDlgBox(), BM_UPDATE, 0, 0);
  }

  return ((PBOXSTRUCT)hBx)->MsgResult;
}

BX_INT DoMenu(HBOX hBox)
{
	BX_INT res;
  BX_MSG msg;
  PINSTANCESTRUCT pInstance;
  HBOX oldBx, pUpBx;
  PBOXSTRUCT b;
  HBOX hBx;

  GreyFramebuffer();
  
  AdjustMenuGeometry(hBox);

  hBx = BxCreateMenuDialog(((BOXSTRUCT *)hBox)->hInstance, (BOXSTRUCT *)((BXMENUSTRUCT*)((BOXSTRUCT *)hBox)->m_menuData)->Mnu, BxMenuProc);

  b = ((PBOXSTRUCT)hBx)->bNext;
  if(b!=NULL)
  {
    while((b->type != BUTTON && b != NULL) || IsDisabled((HBOX)b) || ((PBOXSTRUCT)BxGetParent(b))->type != DIALOG)
      b = b->bNext;

    if(b!=NULL)
    {
      ((PBOXSTRUCT)hBx)->m_oldFocus = BxSetFocus((HBOX)b);
      SetActiveBox((HBOX)b, FALSE);
    }
  }

  ((PBOXSTRUCT)hBx)->m_oldActive = BxSetActiveDlgBox(hBx);

  while(BxGetDlgMessage(&msg, hBx, 0, 0))
  {
    if(msg.message == BM_LBUTTONDOWN)
      if(!BxPointInRect(&((PBOXSTRUCT)hBx)->rc, BX_LOWORD(msg.lParam), BX_HIWORD(msg.lParam)))
        msg.message = BM_CLOSE;
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
		//    BxGetBoxRect(oldBx, &pntRc);

		//    RequestRectPaint(BxGetActiveDlgBox(), &pntRc);
	  ShowDialogBox(BxGetActiveDlgBox());
	  BxSetFocus(((PBOXSTRUCT)oldBx)->m_oldFocus);
    SetActiveBox(((PBOXSTRUCT)oldBx)->m_oldFocus, FALSE);
	  pInstance = (PINSTANCESTRUCT)((PBOXSTRUCT)BxGetActiveDlgBox())->hInstance;
	  pInstance->endDialog = FALSE;
	  BxSendMessage(BxGetActiveDlgBox(), BM_UPDATE, 0, 0);
  }

  if(((BXMENUSTRUCT*)((PBOXSTRUCT)hBox)->m_menuData)->mnufunc!=NULL)
  {
    ((BXMENUSTRUCT*)((PBOXSTRUCT)hBox)->m_menuData)->mnufunc(BxGetActiveDlgBox());
    ((BXMENUSTRUCT*)((PBOXSTRUCT)hBox)->m_menuData)->mnufunc=NULL;
  }

  res = ((PBOXSTRUCT)hBx)->MsgResult;
  BxMenu_Destroy(hBox);

  return res;
}
