#include "BxPrivate.h"

#define MAX_DIRTY_AREA 100
static BX_RECT dirtyAreaTab[MAX_DIRTY_AREA];
static int dirtyAreaTabCount=0;

extern int FontStringLength(char *s,FONT *font);
extern int FontStringHeight(char *s,FONT *font);
static char masktable[8] = {(char)0x80,(char)0x40,(char)0x20,(char)0x10,
                            (char)0x08,(char)0x04,(char)0x02,(char)0x01};

BX_BOOL BxCreateDC(BxDC* dc)
{
  dc->m_GfxDrv = BxGetGfxDriver();

  if(dc->m_GfxDrv==NULL)
    return FALSE;

  dc->m_CurrentPen =        BX_RGB(0xFF,0xFF,0xFF);
  dc->m_CurrentBrush =      BX_RGB(0x0,0x0,0xFF);
  dc->m_CurrentTextColor =  BX_RGB(0xFF,0xFF,0xFF);
  dc->m_CurrentBkColor =    BX_RGB(0x0,0x0,0xFF);
  dc->m_TextAlign = BX_TA_LEFT | BX_TA_TOP;
  dc->m_CurrentFont = DefaultFont;
  dc->m_AlphaOn = FALSE;
  dc->m_AlphaLevel = 0;
//  dc->m_CurrentBitmap = NULL;

  return TRUE;
}

BxDC* BxCreateMemDC( BX_VOID ) 
{
  BxDC* dc = NULL;

	dc = (BxDC*)BxMemAlloc(sizeof(BxDC));

  dc->m_GfxDrv = &BxGfxMEMDrv;

  if(dc->m_GfxDrv==NULL)
    return FALSE;

  dc->m_CurrentPen =        BX_RGB(0xFF,0xFF,0xFF);
  dc->m_CurrentBrush =      BX_RGB(0x0,0x0,0xFF);
  dc->m_CurrentTextColor =  BX_RGB(0xFF,0xFF,0xFF);
  dc->m_CurrentBkColor =    BX_RGB(0x0,0x0,0xFF);
  dc->m_TextAlign = BX_TA_LEFT | BX_TA_TOP;
  dc->m_CurrentFont = DefaultFont;
  dc->m_AlphaOn = FALSE;
  dc->m_AlphaLevel = 0;
//  dc->m_CurrentBitmap = NULL;

  return dc;
}

BX_BOOL BxDeleteDC(BxDC* dc)
{
	if ( dc == NULL )
		return FALSE;

	BxMemFree( dc );

  return TRUE;
}

BxDC* BxGetDC( HBOX hBox ) 
{
  return &((BOXSTRUCT*)hBox)->m_BxDC;
}

BX_BOOL BxSetAlpha( BxDC* pDC, BX_BOOL mode )
{
  BX_BOOL cmode = pDC->m_AlphaOn;
  
  pDC->m_AlphaOn = mode;
  
  return cmode;
}

BX_BOOL BxIsAlphaOn( BxDC *pDC )
{
  return pDC->m_AlphaOn;
}

BX_BYTE BxSetAlphaLevel( BxDC* pDC, BX_BYTE level )
{
  BX_BYTE clevel = pDC->m_AlphaLevel;
  
  pDC->m_AlphaLevel = level;
  
  return clevel;
}
        
BX_BYTE BxGetAlphaLevel( BxDC* pDC )
{
  return pDC->m_AlphaLevel;
}
        

BX_VOID BxRectangle(BxDC* pDC, BX_RECT * pRect)
{
  BxSetClipRect(&pDC->m_clipRect);
  pDC->m_GfxDrv->Rectangle(pRect, pDC->m_CurrentPen, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255 );
}

BX_VOID BxFrame(BxDC* pDC, BX_RECT * pRect, BX_COLORREF color1, BX_COLORREF color2)
{
  BxSetClipRect(&pDC->m_clipRect);
  pDC->m_GfxDrv->Line(pRect->left, pRect->top, pRect->left, pRect->bottom, color1, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->left, pRect->top, pRect->right, pRect->top, color1, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->right, pRect->top, pRect->right, pRect->bottom, color2, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->left, pRect->bottom, pRect->right, pRect->bottom, color2, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
}

BX_VOID BxRoundRect(BxDC* pDC, BX_RECT * pRect, BX_INT r)
{
  BX_RECT Rc;
  int x, y, d, sx, sy;

  BxSetClipRect(&pDC->m_clipRect);

  if (r < 1) {
    return;
  }
  sy = sx = r+1;
  x = 0;
  y = r;
  d = 1 - r;

  pDC->m_GfxDrv->SetPixel(pRect->right-sx + x, pRect->bottom-sy + y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->left+sx - x, pRect->bottom-sy + y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->right-sx + x, pRect->top+sy - y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->left+sx - x, pRect->top+sy - y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->right-sx + y, pRect->bottom-sy + x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->left+sx - y, pRect->bottom-sy + x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->right-sx + y, pRect->top+sy - x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->SetPixel(pRect->left+sx - y, pRect->top+sy - x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  while (x < y) {
    if (d < 0)
      d += x * 2 + 3;
    else {
      d += x * 2 - y * 2 + 5;
      y--;
    }
    x++;

    pDC->m_GfxDrv->Line(pRect->left+sx - x, pRect->top+sy - y, pRect->right-sx + x, pRect->top+sy - y, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->Line(pRect->left+sx - x, pRect->bottom-sy + y, pRect->right-sx + x, pRect->bottom-sy + y, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->Line(pRect->left+sx - y, pRect->bottom-sy + x, pRect->right-sx + y, pRect->bottom-sy + x, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->Line(pRect->left+sx - y, pRect->bottom-sy + x -1, pRect->right-sx + y, pRect->bottom-sy + x -1, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->Line(pRect->left+sx - y, pRect->top+sy - x, pRect->right-sx + y, pRect->top+sy - x, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);


    pDC->m_GfxDrv->SetPixel(pRect->right-sx + x, pRect->bottom-sy + y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->left+sx - x, pRect->bottom-sy + y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->right-sx + x, pRect->top+sy - y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->left+sx - x, pRect->top+sy - y, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);

    pDC->m_GfxDrv->SetPixel(pRect->right-sx + y, pRect->bottom-sy + x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->left+sx - y, pRect->bottom-sy + x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->right-sx + y, pRect->top+sy - x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    pDC->m_GfxDrv->SetPixel(pRect->left+sx - y, pRect->top+sy - x, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);

  }

  Rc.top = pRect->top + sy;
  Rc.left = pRect->left;
  Rc.right = pRect->right;
  Rc.bottom = pRect->bottom - sy;

  pDC->m_GfxDrv->Rectangle(&Rc, pDC->m_CurrentBrush, pDC->m_CurrentBrush, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);

  pDC->m_GfxDrv->Line(pRect->left, pRect->top+sy, pRect->left, pRect->bottom-sy, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->left+sx, pRect->top, pRect->right-sy, pRect->top, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->right, pRect->top+sy, pRect->right, pRect->bottom-sy, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  pDC->m_GfxDrv->Line(pRect->left+sx, pRect->bottom-1, pRect->right-sy, pRect->bottom-1, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);

}

BX_VOID BxLine(BxDC* pDC, BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2)
{
  BxSetClipRect(&pDC->m_clipRect);
  pDC->m_GfxDrv->Line(x1, y1, x2, y2, pDC->m_CurrentPen, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
}

BX_BOOL BxTextOut(BxDC* pDC, BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr)
{
  BX_INT i;
  BX_INT k,cp,cb;
  BX_INT xp, yp, inx;
  BX_UINT c;
  BX_PBYTE bmp;
  BX_INT xAlign = x, yAlign = y;

  BxSetClipRect(&pDC->m_clipRect);

  if(pDC->m_TextAlign & BX_TA_CENTER)
    xAlign = x - FontStringLength(pStr, pDC->m_CurrentFont)/2;

  if(pDC->m_TextAlign & BX_TA_RIGHT)
    xAlign = x - FontStringLength(pStr, pDC->m_CurrentFont);

  if(pDC->m_TextAlign & BX_TA_BOTTOM)
	  yAlign = y - FontStringHeight(pStr, pDC->m_CurrentFont);

  if(pDC->m_TextAlign & BX_TA_BASELINE)
	  yAlign = y - FontStringHeight(pStr, pDC->m_CurrentFont)/2;

  for(i=0;i<lenStr;i++)
  {
		c = (BX_UINT)((BX_BYTE)pStr[i]);
    bmp = (BX_PBYTE)pDC->m_CurrentFont->cacheBit[c].bitmap;
    
    for(yp=0;yp<pDC->m_CurrentFont->cacheBit[c].rows;yp++) 
    {
      cb = 0;
      for(xp=0;xp<pDC->m_CurrentFont->cacheBit[c].cols;xp++) 
      {
        inx=(yp*pDC->m_CurrentFont->cacheBit[c].cols)+xp;
        cp = 0;
        for(k=0;k<8;k++) 
        {
          if(bmp[inx] & masktable[cp & 0x0007])
//            if(PointInRect(&pDC->m_clipRect, xAlign+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), yAlign+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64)))
//              pDC->m_GfxDrv->SetPixel(xAlign+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), yAlign+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64), pDC->m_CurrentTextColor);
            if(BxPointInRect(&pDC->m_clipRect, xAlign+cb+(pDC->m_CurrentFont->metrics[c].bearingX), yAlign+yp-(pDC->m_CurrentFont->metrics[c].bearingY)))
              pDC->m_GfxDrv->SetPixel(xAlign+cb+(pDC->m_CurrentFont->metrics[c].bearingX), yAlign+yp-(pDC->m_CurrentFont->metrics[c].bearingY), pDC->m_CurrentTextColor, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
          cb++;
          cp++;
        }
      }
    }
//    xAlign += (pDC->m_CurrentFont->metrics[c].advance/64);
    xAlign += (pDC->m_CurrentFont->metrics[c].advance);
  }

  return TRUE;
}

BX_COLORREF BxSetTextColor(BxDC* pDC, BX_COLORREF TxtClr)
{
  BX_COLORREF rtn = pDC->m_CurrentTextColor;

  pDC->m_CurrentTextColor = TxtClr;

  return rtn;
}


BX_COLORREF BxSetBkColor(BxDC* pDC, BX_COLORREF BkClr)
{
  BX_COLORREF rtn = pDC->m_CurrentBkColor;

  pDC->m_CurrentBkColor = BkClr;

  return rtn;
}


BX_UINT BxSetTextAlign(BxDC* pDC, BX_UINT Flag)
{
  BX_DWORD oldAlign = pDC->m_TextAlign;

  pDC->m_TextAlign = Flag;

  return oldAlign;
}

BX_UINT BxGetTextAlign(BxDC* pDC)
{
  return pDC->m_TextAlign;
}

BX_COLORREF BxSetPen(BxDC* pDC, BX_COLORREF penClr)
{
  BX_COLORREF Old = pDC->m_CurrentPen;

  pDC->m_CurrentPen = penClr;

  return Old;
}

BX_COLORREF BxSetBrush(BxDC* pDC, BX_COLORREF brClr)
{
  BX_COLORREF Old = pDC->m_CurrentBrush;

  pDC->m_CurrentBrush = brClr;

  return Old;
}

BX_VOID BxSolidRect(BxDC* pDC, BX_RECT * pRect, BX_COLORREF clr)
{
  pDC->m_GfxDrv->Rectangle(pRect, clr, clr, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
}

BxFont* BxGetCurrentFont(BxDC* pDC)
{
  return pDC->m_CurrentFont;
}

BxFont* BxSetFont(BxDC* pDC, BxFont * pFont)
{
  BxFont* rtnFnt = pDC->m_CurrentFont;
  if(pFont==NULL)
    pFont = DefaultFont;

  pDC->m_CurrentFont = pFont;
  return rtnFnt;
}

BX_VOID BxSetClipRegion(BxDC* pDC, BX_RECT * rc)
{
  pDC->m_clipRect.left=rc->left;
  pDC->m_clipRect.top=rc->top;
  pDC->m_clipRect.right=rc->right;
  pDC->m_clipRect.bottom=rc->bottom;
}

BX_INT BxDrawText(BxDC* pDC, BX_PSTRING pString, BX_INT Count, BX_PRECT pRect, BX_UINT Format)
{
  BX_INT x, y;
#ifndef DFBDRV
#ifndef SDLDRV
  BX_INT i;
  BX_INT k,cp,cb;
  BX_INT xp, yp, inx;
  BX_UINT c;
  BX_PBYTE bmp;
  BX_RECT txtRc = {pRect->left,pRect->top,pRect->right,pRect->bottom};
#endif
#endif

  BxSetClipRect(&pDC->m_clipRect);

  x = pRect->left;
//  y = pRect->top + FontStringHeight(pString, pDC->m_CurrentFont)/2;
  y = pRect->top;

  if(Format & DT_VCENTER)
    y = pRect->top + BxRectHeight(pRect)/2 + (FontStringHeight(pString, pDC->m_CurrentFont)/2);
  if(Format & DT_BOTTOM)
    y = pRect->bottom - (FontStringHeight(pString, pDC->m_CurrentFont));
  if(Format & DT_CENTER)
    x = pRect->left + BxRectWidth(pRect)/2 - (FontStringLength(pString, pDC->m_CurrentFont)/2);

  if(Format & DT_RIGHT)
    x = pRect->right - FontStringLength(pString, pDC->m_CurrentFont);

#ifdef DFBDRV
  pDC->m_GfxDrv->TextOut(x, y, pString, Count, pDC->m_CurrentFont, pDC->m_CurrentTextColor, pDC->m_CurrentTextColor,1);
#else
#ifdef SDLDRV
  pDC->m_GfxDrv->TextOut(x, y, pString, Count, pDC->m_CurrentFont, pDC->m_CurrentTextColor, pDC->m_CurrentTextColor, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
#else
  for(i=0;i<Count;i++)
  {
		c = (BX_UINT)((BX_BYTE)pString[i]);
    bmp = (BX_PBYTE)pDC->m_CurrentFont->cacheBit[c].bitmap;
    
    for(yp=0;yp<pDC->m_CurrentFont->cacheBit[c].rows;yp++) 
    {
      cb = 0;
      for(xp=0;xp<pDC->m_CurrentFont->cacheBit[c].cols;xp++) 
      {
        inx=(yp*pDC->m_CurrentFont->cacheBit[c].cols)+xp;
        cp = 0;
        for(k=0;k<8;k++) 
        {
//          if(bmp[inx] & masktable[cp & 0x0007])
          if(bmp[inx] & masktable[cp])
//            if(PointInRect(&txtRc, x+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64)))
//              pDC->m_GfxDrv->SetPixel(x+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64), pDC->m_CurrentTextColor);
            if(PointInRect(&txtRc, x+cb+(pDC->m_CurrentFont->metrics[c].bearingX), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY)))
              pDC->m_GfxDrv->SetPixel(x+cb+(pDC->m_CurrentFont->metrics[c].bearingX), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY), pDC->m_CurrentTextColor);
          cb++;
          cp++;
        }
      }
    }
//    x += (pDC->m_CurrentFont->metrics[c].advance/64);
    x += (pDC->m_CurrentFont->cacheBit[c].width);
  }
#endif
#endif
  return 0;
}

BX_INT BxTextOutXY(BxDC* pDC, BX_INT x, BX_INT y, BX_PSTRING pString, BX_INT Count)
{
  BX_INT i;
  BX_INT k,cp,cb;
  BX_INT xp, yp, inx;
  BX_UINT c;
  BX_PBYTE bmp;

  BxSetClipRect(&pDC->m_clipRect);

  for(i=0;i<Count;i++)
  {
		c = (BX_UINT)((BX_BYTE)pString[i]);
    bmp = (BX_PBYTE)pDC->m_CurrentFont->cacheBit[c].bitmap;
    
    for(yp=0;yp<pDC->m_CurrentFont->cacheBit[c].rows;yp++) 
    {
      cb = 0;
      for(xp=0;xp<pDC->m_CurrentFont->cacheBit[c].cols;xp++) 
      {
        inx=(yp*pDC->m_CurrentFont->cacheBit[c].cols)+xp;
        cp = 0;
        for(k=0;k<8;k++) 
        {
          if(bmp[inx] & masktable[cp & 0x0007])
//            if(PointInRect(&txtRc, x+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64)))
              pDC->m_GfxDrv->SetPixel(x+cb+(pDC->m_CurrentFont->metrics[c].bearingX/64), y+yp-(pDC->m_CurrentFont->metrics[c].bearingY/64), pDC->m_CurrentTextColor, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
          cb++;
          cp++;
        }
      }
    }
    x += (pDC->m_CurrentFont->metrics[c].advance/64);
  }
  return x;
}

static BX_INT GetCharPos(BX_PSTRING pString, BX_CHAR c, BX_INT len)
{
	BX_INT pos=0;
	
	while( *pString == c && *pString != 0 && *pString != '\n' && pos <= len)
	{
		pos++;
		pString++;
	}

	while( *pString != c && *pString != 0  && *pString != '\n' && pos <= len)
	{
		pos++;
		pString++;
	}

	if(*pString==0 || *pString=='\n')
		return --pos;
	return pos;
}

BX_INT BxDrawMultiLineText(BxDC* pDC, BX_PSTRING pString, BX_INT Count, BX_PRECT pRect, BX_UINT Format)
{
	BX_CHAR pStr[255]="";
	BX_CHAR pWord[127]="";
	BX_CHAR pnewStr[255]="";
  BX_INT x, y, sx;
  BX_INT i, j, sh, sl;

  BxSetClipRect(&pDC->m_clipRect);

	sh = FontStringHeight(pString, pDC->m_CurrentFont);

  sx = pRect->left;
  y = pRect->top + sh;

/*
  if(Format & DT_VCENTER)
    y = pRect->top + ((pRect->bottom - pRect->top)/2) + (sh/2);

  if(Format & DT_BOTTOM)
    y = pRect->bottom - (sh/2);
*/
  if(Format & DT_CENTER)
    sx = pRect->left + (BxRectWidth(pRect)/2);

//  if(Format & DT_RIGHT)
//    sx = pRect->left + ((pRect->right - pRect->left)/2) - (FontStringLength(pString, pDC->m_CurrentFont)/2);

	x = sx;

  for(i=0;i<Count;i++)
	{
		switch(pString[i]) {
		case '\n':
			if(Format & DT_CENTER)
 				x -= FontStringLength(pnewStr, pDC->m_CurrentFont)/2;

			BxTextOutXY(pDC, x, y, pnewStr, strlen(pnewStr));
			memset(pnewStr, 0, 255);
			memset(pStr, 0, 255);
			x = sx;
			y += sh*2;
			break;
		default:
			j = GetCharPos(&pString[i], 32, Count-i);

			strncpy(pWord, &pString[i], j+1);
			i += j;
			strcat(pStr, pWord);

			sl = FontStringLength(pStr, pDC->m_CurrentFont);
			if ( BxRectWidth(pRect) <= sl )
			{
				if(Format & DT_CENTER)
 					x -= FontStringLength(pnewStr, pDC->m_CurrentFont)/2;

				BxTextOutXY(pDC, x, y, pnewStr, strlen(pnewStr));
				memset(pnewStr, 0, 255);
				memset(pStr, 0, 255);
				x = sx;
				y += sh*2;
				i -= j+1;
			}
			else
			{
				strcat(pnewStr, pWord);
			}
			memset(pWord, 0, 127);

			break;
		}
	}
	if(Format & DT_CENTER)
  	x -= FontStringLength(pStr, pDC->m_CurrentFont)/2;

	BxTextOutXY(pDC, x, y, pnewStr, strlen(pnewStr));
  return 0;
}

/*
BxBitmap * SetBitmap(BxDC* pDC, BxBitmap * pBitmap)
{
  BxBitmap * rtn = pDC->m_CurrentBitmap;
  
  pDC->m_CurrentBitmap = pBitmap;

  return rtn;
}
*/

BX_BOOL BxDrawIcon(BxDC* pDC, BX_INT x, BX_INT y, BxIcon* pIcon)
{
  if(pIcon)
  {
   BxSetClipRect(&pDC->m_clipRect);
   pDC->m_GfxDrv->PutMaskedBitmap(x, y, pIcon->icoMask->bmWidth, pIcon->icoBits->bmHeight, (BX_BYTE*)pIcon->icoBits->bmBits, (BX_BYTE*)pIcon->icoMask->bmBits, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    return TRUE;
  }
  return FALSE;
}

BX_BOOL BxDrawBitmap(BxDC* pDC, BX_INT x, BX_INT y, BxBitmap* pBmp, BX_INT paintType)
{
  if(pBmp)
  {
    BxSetClipRect(&pDC->m_clipRect);
    pDC->m_GfxDrv->PutBitmap(x, y, pBmp, paintType, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
    return TRUE;
  }
  return FALSE;
}

/*
BX_BOOL BxGetBitmap(BxDC* pDC, BX_INT x, BX_INT y, BxBitmap* pBmp)
{
  if(pBmp)
  {
    pDC->m_GfxDrv->GetBitmap(x, y, pBmp->bmWidth, pBmp->bmHeight, (BX_BYTE*)pBmp->bmBits);
    return TRUE;
  }
  return FALSE;
}
*/

BX_COLORREF BxSetPixel(BxDC* pDC, BX_INT x, BX_INT y, BX_COLORREF color)
{
  BxSetClipRect(&pDC->m_clipRect);
  pDC->m_GfxDrv->SetPixel(pDC->m_clipRect.left+x, pDC->m_clipRect.top+y, color, pDC->m_AlphaOn == TRUE ? pDC->m_AlphaLevel : 255);
  return color;
}

BX_BOOL BxBitBlt( BxDC* pdcDest,  // handle to destination device context 
	BX_INT nXDest,  // x-coordinate of destination rectangles upper-left corner 
	BX_INT nYDest,  // y-coordinate of destination rectangles upper-left corner 
	BX_INT nWidth,  // width of destination rectangle 
	BX_INT nHeight, // height of destination rectangle 
	BxDC*  pdcSrc,  // handle to source device context 
	BX_INT nXSrc,   // x-coordinate of source rectangles upper-left corner 
	BX_INT nYSrc,   // y-coordinate of source rectangles upper-left corner 
	BX_DWORD dwRop  // raster operation code 
)
{
	if( pdcDest == NULL || pdcSrc == NULL )
		return FALSE;

  BxSetClipRect(&pdcDest->m_clipRect);
	

	return FALSE;	
}
 
BX_VOID BxUpdateView(HBOX hBx)
{
  BX_INT i;
  
  if(dirtyAreaTabCount > 0)
  {
    for(i=0;i<dirtyAreaTabCount;i++)
    {
      ((BOXSTRUCT*)hBx)->m_BxDC.m_GfxDrv->CopyArea(&dirtyAreaTab[i]);
    }
    dirtyAreaTabCount = 0;
  }
//  else
//  {
//    ((BOXSTRUCT*)hBx)->m_BxDC.m_GfxDrv->CopyArea(NULL);
//  }
}

BX_BOOL BxSetDirtyArea(BX_RECT *rc)
{
  BX_INT i;

  for(i=0;i<dirtyAreaTabCount;i++)
    if(BxMergeRects(&dirtyAreaTab[i], rc, &dirtyAreaTab[i]))
      return TRUE;

  if(dirtyAreaTabCount + 1 >= MAX_DIRTY_AREA)
    return FALSE;

  BxCopyRect(&dirtyAreaTab[dirtyAreaTabCount++], rc);

  return TRUE;
}
