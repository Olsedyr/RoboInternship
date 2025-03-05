// BxBitmap.c: implementation of BxBitmap 
//
//////////////////////////////////////////////////////////////////////

#include "Bx.h"
#include "BxBitmap.h"

#ifdef SDLDRV
#include "SDL/SDL.h"
#endif

extern BxGfxDrvInfo FBInfo;

BX_PBITMAP BxCreateBitmap(BX_INT Width, BX_INT Height, BX_UINT Planes, BX_UINT BitCount, BX_PVOID Bits)
{
  BX_UCHAR * pSrc, * pDst;
  BX_PBITMAP m_bmp;
  BX_INT i, j;

  m_bmp = (BX_PBITMAP)BxMemAlloc(sizeof(BX_BITMAP));
  if(m_bmp==NULL)
    return NULL;

  m_bmp->bmType = 0;
  m_bmp->bmWidth = Width;
  m_bmp->bmHeight = Height;
  m_bmp->bmPlanes = Planes;
  m_bmp->bmBitsPixel = BitCount;
  m_bmp->bmWidthBytes = Width * (BitCount/8);
#ifdef SDLDRV
  m_bmp->img = NULL;
#endif

  m_bmp->bmBits = BxMemAlloc(sizeof(BX_UCHAR)*m_bmp->bmHeight*m_bmp->bmWidthBytes);
  if(m_bmp->bmBits==NULL)
  {
    BxMemFree( m_bmp );
    return NULL;
  }

  if(Bits)
  {
  	m_bmp->bmBits = BxMemAlloc(sizeof(BX_UCHAR)*m_bmp->bmHeight*m_bmp->bmWidthBytes);
  	if(m_bmp->bmBits==NULL)
  	{
      BxMemFree( m_bmp );
      return NULL;
  	}

    pSrc = (BX_UCHAR*)Bits;
    pDst = (BX_UCHAR*)m_bmp->bmBits;

    for(i=0; i<m_bmp->bmHeight; i++)
    {
      for(j=0; j<m_bmp->bmWidthBytes; j++)
      {
        *pDst = *pSrc;
        pDst++;
        pSrc++;
      }
    }
  }
  return m_bmp;
}

BX_PBITMAP BxCreateCompatibleBitmap(BX_INT Width, BX_INT Height, BX_PVOID Bits)
{
  BX_PBITMAP m_bmp;

  m_bmp = (BX_PBITMAP)BxMemAlloc(sizeof(BX_BITMAP));
  if(m_bmp==NULL)
    return NULL;

  m_bmp->bmType = 0;
  m_bmp->bmWidth = Width;
  m_bmp->bmHeight = Height;
  m_bmp->bmPlanes = FBInfo.BytesPrPixel;
  m_bmp->bmBitsPixel = FBInfo.BytesPrPixel;
  m_bmp->bmWidthBytes = FBInfo.ByteWidth;
#ifdef SDLDRV
  m_bmp->img = NULL;
#endif

  m_bmp->bmBits = BxMemAlloc(sizeof(BX_UCHAR)*m_bmp->bmHeight*m_bmp->bmWidthBytes);
  if(m_bmp->bmBits==NULL)
  {
    BxMemFree( m_bmp );
    return NULL;
  }

  return m_bmp;
}

BX_PBITMAP BxBitmap_Load(FILE * pFile)
{
  BX_BITMAP tmp;
  BX_PBITMAP m_bmp;
  BX_UCHAR * pSrc;
  BX_INT i, j;

  if(!pFile)
    return NULL;

  fread(&tmp.bmType, sizeof(tmp.bmType), 1, pFile);
  fread(&tmp.bmWidth, sizeof(tmp.bmWidth), 1, pFile);
  fread(&tmp.bmHeight, sizeof(tmp.bmHeight), 1, pFile);
  fread(&tmp.bmWidthBytes, sizeof(tmp.bmWidthBytes), 1, pFile);
  fread(&tmp.bmPlanes, sizeof(tmp.bmPlanes), 1, pFile);
  fread(&tmp.bmBitsPixel, sizeof(tmp.bmBitsPixel), 1, pFile);

  if((m_bmp = BxCreateBitmap(tmp.bmWidth, tmp.bmHeight, tmp.bmPlanes, tmp.bmBitsPixel, NULL))==NULL) return NULL;

  pSrc = (BX_UCHAR*)m_bmp->bmBits;

  for(i=0; i<m_bmp->bmHeight; i++)
  {
    for(j=0; j<m_bmp->bmWidthBytes; j++)
    {
      fread(&pSrc[0], 1, 1, pFile);
      pSrc++;
    }
  }
  return m_bmp;
}

BX_PBITMAP BxBitmap_Load32(FILE * pFile)
{
  BX_BITMAP tmp;
  BX_PBITMAP m_bmp;
  BX_UCHAR * pSrc, dummy;
  BX_INT i, j;

  if(!pFile)
    return NULL;

  fread(&tmp.bmType, sizeof(tmp.bmType), 1, pFile);
  fread(&tmp.bmWidth, sizeof(tmp.bmWidth), 1, pFile);
  fread(&tmp.bmHeight, sizeof(tmp.bmHeight), 1, pFile);
  fread(&tmp.bmWidthBytes, sizeof(tmp.bmWidthBytes), 1, pFile);
  fread(&tmp.bmPlanes, sizeof(tmp.bmPlanes), 1, pFile);
  fread(&tmp.bmBitsPixel, sizeof(tmp.bmBitsPixel), 1, pFile);

  tmp.bmWidthBytes = tmp.bmWidth*3;
  tmp.bmBitsPixel = 24;
  
  if((m_bmp = BxCreateBitmap(tmp.bmWidth, tmp.bmHeight, tmp.bmPlanes, tmp.bmBitsPixel, NULL))==NULL) return NULL;

  pSrc = (BX_UCHAR*)m_bmp->bmBits;

  for(i=0; i<m_bmp->bmHeight; i++)
  {
    for(j=0; j<m_bmp->bmWidth; j++)
    {
      fread(&pSrc[2], 1, 1, pFile);
      fread(&pSrc[1], 1, 1, pFile);
      fread(&pSrc[0], 1, 1, pFile);
      pSrc++;
      pSrc++;
      pSrc++;
      fread(&dummy, 1, 1, pFile);
    }
  }
  return m_bmp;
}

BX_BOOL BxBitmap_Save(BX_PBITMAP m_bmp, FILE * pFile)
{
  BX_UCHAR * pSrc;
  BX_INT i, j;

  if(!pFile)
    return FALSE;

  fwrite(&m_bmp->bmType, sizeof(m_bmp->bmType), 1, pFile);
  fwrite(&m_bmp->bmWidth, sizeof(m_bmp->bmWidth), 1, pFile);
  fwrite(&m_bmp->bmHeight, sizeof(m_bmp->bmHeight), 1, pFile);
  fwrite(&m_bmp->bmWidthBytes, sizeof(m_bmp->bmWidthBytes), 1, pFile);
  fwrite(&m_bmp->bmPlanes, sizeof(m_bmp->bmPlanes), 1, pFile);
  fwrite(&m_bmp->bmBitsPixel, sizeof(m_bmp->bmBitsPixel), 1, pFile);

  pSrc = (BX_UCHAR*)m_bmp->bmBits;

  for(i=0; i<m_bmp->bmHeight; i++)
  {
    for(j=0; j<m_bmp->bmWidthBytes; j++)
    {
      fwrite(&pSrc[0], 1, 1, pFile);
      pSrc++;
    }
  }

  return TRUE;
}

BX_VOID BxDeleteBitmap(BX_PBITMAP m_bmp)
{
  if(m_bmp)
  {
    if(m_bmp->bmBits) BxMemFree( m_bmp->bmBits );
#ifdef SDLDRV
    if(m_bmp->img) SDL_FreeSurface(m_bmp->img);
#endif
    BxMemFree( m_bmp );
  }
}
