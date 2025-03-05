#include "Bx.h"
#ifdef SDLDRV
#include "SDL/SDL_image.h"
#endif

BX_PBITMAP BxCreateDIB( 
		BxDC bxdc,						// handle to device context 
		CONST BX_BITMAPINFO *bxpbmi,	// pointer to structure containing bitmap size, format, and color data 
		BX_UINT bxiUsage,					// color data type indicator: RGB values or palette indices (Only RGB now!!)
		BX_PVOID pbxpvBits			// pointer to variable to receive a pointer to the bitmap’s bit values 
)
{
/*
	BX_PBITMAP pBmp;

	if (bxdc==NULL) return NULL;
	if (bxpbmi==NULL) return NULL;

	pBmp = (BX_PBITMAP)malloc()
*/
	return NULL;
} 

BX_PBITMAP BxLoadImage(BX_PSTRING filename)
{
#ifdef SDLDRV
	BX_PBITMAP pBmp;

	if (filename==NULL) return NULL;

    pBmp = (BX_PBITMAP)BxMemAlloc(sizeof(BX_BITMAP));
    if(pBmp==NULL)
    return NULL;

	pBmp->img = IMG_Load(filename);
	if(!pBmp->img)
	  return NULL;

  	pBmp->bmHeight = pBmp->img->h;
  	pBmp->bmWidth = pBmp->img->w;
    pBmp->bmBitsPixel = pBmp->img->format->BitsPerPixel;
	pBmp->bmWidthBytes = pBmp->img->format->BytesPerPixel*pBmp->bmWidth;
	
    return pBmp;
#endif	
	return NULL;
}

BX_PBITMAP BxConvertBitmap(BX_PBITMAP pBmp)
{
#ifdef SDLDRV
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  unsigned int    rmask = 0xff000000;
  unsigned int    gmask = 0x00ff0000;
  unsigned int    bmask = 0x0000ff00;
  unsigned int    amask = 0x000000ff;
#else

  unsigned int    rmask = 0x000000ff;
  unsigned int    gmask = 0x0000ff00;
  unsigned int    bmask = 0x00ff0000;
  unsigned int    amask = 0xff000000;
#endif

	//  SDL_Surface *dest;

  if (pBmp==NULL) return NULL;

  pBmp->img = SDL_CreateRGBSurfaceFrom(pBmp->bmBits, pBmp->bmWidth, pBmp->bmHeight, pBmp->bmBitsPixel, pBmp->bmWidthBytes, bmask, gmask, rmask, amask);
  if(pBmp->img == NULL) {
      fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
      return NULL;
  }  
  return pBmp;
#endif	
	return NULL;
}

BX_PBITMAP BxLoadXPMImage(BX_CHAR **array)
{
#ifdef SDLDRV
	BX_PBITMAP pBmp;

	if (array==NULL) return NULL;

    pBmp = (BX_PBITMAP)BxMemAlloc(sizeof(BX_BITMAP));
    if(pBmp==NULL)
    return NULL;

	pBmp->img = IMG_ReadXPMFromArray(array);
	if(!pBmp->img)
	  return NULL;

  	pBmp->bmHeight = pBmp->img->h;
  	pBmp->bmWidth = pBmp->img->w;
    pBmp->bmBitsPixel = pBmp->img->format->BitsPerPixel;
	pBmp->bmWidthBytes = pBmp->img->format->BytesPerPixel*pBmp->bmWidth;
	
    return pBmp;
#endif	
	return NULL;
}
