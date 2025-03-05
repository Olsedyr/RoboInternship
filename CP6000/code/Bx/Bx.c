#include "Bx.h"
//#include "rtx.h"

#include "BxDrivers.h"
#include "BxPrivate.h"
#include "BxResMan.h"


#ifdef DFBDRV
extern BX_INT BxGfxDFBDrv_Shutdown(BX_VOID);
#else
#ifdef SDLDRV
extern BX_INT BxGfxSDLDrv_Shutdown(BX_VOID);
#else
#ifdef FBDRV
extern BX_INT BxGfxFBDrv_Shutdown(BX_VOID);
#else
#ifdef X11
extern BX_INT BxGfxX11Drv_Shutdown(BX_VOID);
#endif
#endif
#endif
#endif

BX_INT BX_LANGUAGE = 0;
BX_INT BX_DEFSTRLEN = 255;
BxFont* DefaultSmallFont;
BxFont* DefaultFont;
BxFont* DefaultButtonFont;

BX_COLORREF BXSYSTEM_PALETTE[25] = {
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_SCROLLBAR         
	BX_RGB(0x00,0x40,0x80),   //BXCOLOR_BACKGROUND        
	BX_RGB(0x00,0x00,0xa0),   //BXCOLOR_ACTIVECAPTION     
	BX_RGB(0x80,0x80,0x80),   //BXCOLOR_INACTIVECAPTION   
	BX_RGB(0x7f,0x7f,0x7f),   //BXCOLOR_MENU              
	BX_RGB(0xa0,0xa0,0xff),   //BXCOLOR_BOX
	BX_RGB(0x7f,0x7f,0x7f),   //BXCOLOR_BOXFRAME       
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_MENUTEXT          
	BX_RGB(0xff,0xff,0xff),   //BXCOLOR_BOXTEXT        
	BX_RGB(0xff,0xff,0xff),   //BXCOLOR_CAPTIONTEXT       
	BX_RGB(0xff,0xff,0xff),   //BXCOLOR_ACTIVEBORDER      
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_INACTIVEBORDER    
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_APPWORKSPACE      
	BX_RGB(0x00,0x00,0x60),   //BXCOLOR_HIGHLIGHT         
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_HIGHLIGHTTEXT     
	BX_RGB(0xff,0xff,0xff),   //BXCOLOR_BTNFACE           
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_BTNSHADOW         
	BX_RGB(0x80,0x80,0x80),   //BXCOLOR_GRAYTEXT          
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_BTNTEXT           
	BX_RGB(0x00,0x00,0x00),   //BXCOLOR_INACTIVECAPTIONTEXT
	BX_RGB(0xff,0xff,0xff),   //BXCOLOR_BTNHIGHLIGHT      
	BX_RGB(55,175,112),				//BXCOLOR_POPUPBOX
	BX_RGB(0xa0,0xa0,0xa0),   //BXCOLOR_MENUBOX
	BX_RGB(0x00,0x00,0x00),
	BX_RGB(0x00,0x00,0x00)
};

extern BX_BITMAP splash;
extern BX_UCHAR splashpal[];
BX_RGBTRIPLE *SPLASH_PAL;
#define SPLASH_WIDTH splash.bmWidth
#define SPLASH_HEIGHT splash.bmHeight

BX_UCHAR *SPLASH_BITS;

BX_VOID CreateSplashImage(BX_VOID)
{
	/*	
	BX_INT x, y;
	BX_UCHAR *data = (BX_UCHAR*)splash.bmBits;
	SPLASH_BITS = (BX_UCHAR*)malloc(SPLASH_WIDTH*SPLASH_HEIGHT*3);
	SPLASH_PAL = (BX_RGBTRIPLE *)splashpal;

	for(y=0;y<SPLASH_HEIGHT;y++)
	{
		for(x=0;x<SPLASH_WIDTH;x++)
		{
			SPLASH_BITS[((SPLASH_WIDTH*3)*y)+(x*3)] = SPLASH_PAL[data[(SPLASH_WIDTH*y)+x]].rgbtBlue;
			SPLASH_BITS[((SPLASH_WIDTH*3)*y)+(x*3)+1] = SPLASH_PAL[data[(SPLASH_WIDTH*y)+x]].rgbtGreen;
			SPLASH_BITS[((SPLASH_WIDTH*3)*y)+(x*3)+2] = SPLASH_PAL[data[(SPLASH_WIDTH*y)+x]].rgbtRed;
		}
	}
*/
}

BX_VOID DeleteSplashImage(BX_VOID)
{
	//	free(SPLASH_BITS);
}

BX_VOID DlgAppInit(BX_VOID);
BX_VOID BxUpdate(BX_VOID);
BX_BOOL BxUpdateFlag = FALSE;
////////////////////////////////////////////////////////////////////////
// Alle driver objecter skal v�e her
////////////////////////////////////////////////////////////////////////
BxGfxDrv* sysGfxDrv;
extern BxGfxDrv BxGfxMEMDrv;
extern BxGfxDrv BxGfxFBDrv;
extern BxGfxDrv BxGfxDFBDrv;
extern BxGfxDrv BxGfxX11Drv;
extern BxGfxDrv BxGfxSDLDrv;
#ifdef BXWIN
extern BxGfxDrv BxGfxWINDrv;
#endif

extern BxGfxDrvInfo FBInfo;
extern FONT Nimbus_14;
extern FONT Arial_14;
extern FONT Arial_7;

BxSysBoxList BoxManager = {0, 0, NULL, NULL, NULL};

HBOX  BXFOCUSBOX = NULL;
HBOX  BXACTIVEBOX = NULL;
HBOX  BXACTIVEDLGBOX = NULL;

extern BX_BOOL BxInitSystemResource(BX_VOID);
//extern BX_BOOL (*BxInitResourceManager)(BX_VOID);
//extern BxResMan * resMan;

BX_LRESULT BxInitSystem(BX_VOID)
{
  BX_RECT rc;
//	sysGfxDrv = &BxGfxSVGADrv;
#ifdef MEMDRV
  sysGfxDrv = &BxGfxMEMDrv;
#endif
#ifdef FBDRV
  sysGfxDrv = &BxGfxFBDrv;
#endif
#ifdef DFBDRV
  sysGfxDrv = &BxGfxDFBDrv;
#endif
#ifdef X11
	sysGfxDrv = &BxGfxX11Drv;
#endif
#ifdef BXWIN
	sysGfxDrv = &BxGfxWINDrv;
#endif 

#ifdef SDLDRV
  sysGfxDrv = &BxGfxSDLDrv;
#endif

	if(sysGfxDrv->Init()!=BX_STATUS_OK)
      return BX_DRIVER_STARTUP_FAILED;

	/* Splash screen */

//	CreateSplashImage();
//  sysGfxDrv->PutBitmap(80, 60, SPLASH_WIDTH, SPLASH_HEIGHT, SPLASH_BITS);
//	DeleteSplashImage();
  rc.left = 0;
  rc.top = 0;
  rc.right = FBInfo.Width;
  rc.bottom = FBInfo.Height;
//  sysGfxDrv->FillRect(&rc, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
  sysGfxDrv->FillRect(&rc, 0, 0);
  sysGfxDrv->CopyArea(&rc);

  DlgAppInit();
  /* Start drivers */
  /* Start drivers end */


//  SystemBoxList = new BxSysBoxList;

	InitFontServer();
#ifdef DFBDRV
	DefaultButtonFont=DefaultFont;
#else
#ifdef SDLDRV
	DefaultButtonFont=DefaultFont;
#else
  DefaultButtonFont=&Nimbus_14;
	DefaultSmallFont=&Arial_7;
#endif
#endif

	BxInitSystemResource();

//	if(BxInitResourceManager)
//		if(!BxInitResourceManager())
//			return BX_ERR_RESOURCEMAN;

	return BX_STATUS_OK;
}

BX_LRESULT BxCloseSystem(BX_VOID)
{
#ifdef DFBDRV
  BxGfxDFBDrv_Shutdown();
#else
#ifdef SDLDRV
  BxGfxSDLDrv_Shutdown();
#else
#ifdef FBDRV
  BxGfxFBDrv_Shutdown();
#else
#ifdef X11
  BxGfxX11Drv_Shutdown();
#endif
#endif
#endif
#endif

	return BX_STATUS_OK;
}

/*
BxBitmap* BxLoadBitmap(BX_UINT ID)
{
	if(resMan)
		return resMan->LoadBxBitmap(ID);
	return NULL;
}

BxIcon* BxLoadIcon(BX_UINT ID)
{
	if(resMan)
		return resMan->LoadBxIcon(ID);
	return NULL;
}

*/
/*
BX_BOOL BxRegistrateBox(BxBox* pBox)
{
  AddTail(&BoxManager, (BX_PVOID)pBox);
  return TRUE;
}

BX_BOOL BxUnRegistrateBox(BxBox* pBox)
{
  return Remove(&BoxManager, (BX_PVOID)pBox);
}
*/
/*
BxBox* BxGetFirstChild(BxBox* pBox, BX_UINT Type)
{
  BxBox *pBx = (BxBox*)SystemBoxList->GetHead();

  if(Type!=ANY)
  {
    while(pBx!=NULL)
    {
      if(pBx->GetParent() == pBox && pBx->m_Type == Type)
        return pBx;
      pBx = (BxBox*)SystemBoxList->GetNext();
    }
  }
  else
  {
    while(pBx!=NULL)
    {
      if(pBx->GetParent() == pBox)
        return pBx;
      pBx = (BxBox*)SystemBoxList->GetNext();
    }
  }

  return NULL;
}

BxBox* BxGetChild(BxBox* pBox, BxBox* pChild, BX_UINT Type)
{
  BxBox* pBx;
  BX_INT currentPos = SystemBoxList->CurrentPosition();

  if(pChild==NULL)
  {
    pBx = BxGetFirstChild(pBox, Type);
    SystemBoxList->SetCurrentPosition(currentPos);
    return pBx;
  }

  pBx = pChild;
  BxFindBox(pBx);
  pBx = (BxBox*)SystemBoxList->GetNext();

  if(Type!=ANY)
  {
    while(pBx != NULL)
    {
      if(pBx->GetParent()==pBox && pBx->m_Type == Type)
      {
        SystemBoxList->SetCurrentPosition(currentPos);
        return pBx;
      }

      pBx = (BxBox*)SystemBoxList->GetNext();
    }
  }
  else
  {
    while(pBx != NULL)
    {
      if(pBx->GetParent()==pBox)
      {
        SystemBoxList->SetCurrentPosition(currentPos);
        return pBx;
      }
      pBx = (BxBox*)SystemBoxList->GetNext();
    }
  }

  SystemBoxList->SetCurrentPosition(currentPos);
  return NULL;
}


BxBox* BxGetChildFromID(BxBox* pBox, BX_INT ID)
{
  BX_INT currentPos = SystemBoxList->CurrentPosition();
  BxBox* pChild = BxGetFirstChild(pBox, ANY);

  while(pChild!=NULL)
  {
    if(pChild->GetBoxID() == ID)
    {
      SystemBoxList->SetCurrentPosition(currentPos);
      return pChild;
    }

    pChild = BxGetChild(pBox, pChild, ANY);
  }
  SystemBoxList->SetCurrentPosition(currentPos);
  return NULL;
}


BX_BOOL BxFindBox(BxBox* pBox)
{
  BxBox *pBx = (BxBox*)SystemBoxList->GetHead();

  while(pBx!=NULL)
  {
    if(pBx==pBox)
      return TRUE;
    pBx = (BxBox*)SystemBoxList->GetNext();
  }
  return FALSE;
}

*/
PBOXSTRUCT BxGetNextBox(PBOXSTRUCT pBox, BX_UINT Flag)
{
	PBOXSTRUCT pBx=pBox;;

	if(Flag == GB_BOXNEXT)
	{
		if(pBox->bNext==NULL)
			pBx = pBox->bParent->bNext;
		else
			pBx = pBox->bNext;
	}

	if(Flag == GB_BOXPREV)
	{
		pBx = pBox->bParent;
		while(pBx->bNext!=pBox)
		{
			pBx = pBx->bNext;
			if(pBx==NULL)
				pBx = pBox->bParent;
		}
		if(pBx == pBox->bParent)
		{
			while(pBx->bNext!=NULL)
				pBx = pBx->bNext;
		}
	}
	return pBx;
}


HBOX BxFindDirtyChild(HBOX pBox)
{
	BOXSTRUCT *tmp = (BOXSTRUCT*)pBox;

	while(tmp->bNext!=NULL)
	{
		tmp = tmp->bNext;
		if(tmp->m_Dirty)
			return(HBOX)tmp;
	}
	return NULL;
}


BxGfxDrv* BxGetGfxDriver(BX_VOID)
{
	return sysGfxDrv;
}

/*
BX_INT BxMessageBox(BxBox* pBx, BX_PSTRING pMessage, BX_PSTRING pCaption, BX_UINT Style)
{
	BxMsgBox *pMBx;
  BX_INT rtn;

  pMBx = new BxMsgBox;

  if(pBx!=NULL)
	{
		if(!pMBx->Create(pBx->GetAppInstance(), pCaption, pMessage, pBx))
			return -1;
	}

  rtn = pMBx->DoModal();
  delete pMBx;

  return rtn;
}
*/
HBOX BxSetActiveDlgBox(HBOX hBx)
{
	PBOXSTRUCT oldABx = (PBOXSTRUCT)BXACTIVEDLGBOX;//, pChild;

	if(oldABx!=NULL)
	{
		BxSendMessage((HBOX)oldABx, BM_ACTIVATE, BX_LOWORD(BA_INACTIVE), (BX_LPARAM)hBx);
	}

	if(hBx!=NULL)
	{
		BxSendMessage(hBx, BM_ACTIVATE, BX_LOWORD(BA_ACTIVE), (BX_LPARAM)oldABx);
/*
		pChild = ((PBOXSTRUCT)hBx)->bNext;
		while(pChild)
		{
		  BxSendMessage(pChild, BM_SHOWBOX, (BX_WPARAM)TRUE, 0);
			pChild = pChild->bNext;
		}
*/
	}

	BXACTIVEDLGBOX = hBx;

	return oldABx;
}


BX_BOOL IsDirty(HBOX pBx)
{
	return ((BOXSTRUCT*)pBx)->m_Dirty;
}

BX_BOOL IsVisible(HBOX pBx)
{
	if(((BOXSTRUCT*)pBx)->style & BXS_VISIBLE)
		return TRUE;

	return FALSE;
}

BX_BOOL IsDisabled(HBOX pBx)
{
	if(((BOXSTRUCT*)pBx)->style & BXS_DISABLED)
		return TRUE;

	return FALSE;
}

HBOX BxGetActiveDlgBox(BX_VOID)
{
	return BXACTIVEDLGBOX;
}

BX_VOID BxUpdate(BX_VOID)
{
	BxUpdateFlag = TRUE;
}
