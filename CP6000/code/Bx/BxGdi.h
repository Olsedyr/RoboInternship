#ifndef BXGDI
#define BXGDI
#ifdef SDLDRV
#include "SDL/SDL.h"
#endif
/* Text Alignment Options */
//#define TA_NOUPDATECP                0
//#define TA_UPDATECP                  1

extern BX_COLORREF BXSYSTEM_PALETTE[];

#define BX_TA_LEFT                      0x00000001
#define BX_TA_RIGHT                     0x00000002
#define BX_TA_CENTER                    0x00000004

#define BX_TA_TOP                       0x00000100
#define BX_TA_BOTTOM                    0x00000200
#define BX_TA_BASELINE                  0x00000400

#define BX_RGB(r,g,b) ((BX_BYTE)b<<16 | \
                    (BX_BYTE)g << 8 |\
                    (BX_BYTE)r << 0)

#define BxGetRValue(rgb)      ((BX_BYTE)(rgb))
#define BxGetGValue(rgb)      ((BX_BYTE)(((BX_WORD)(rgb)) >> 8))
#define BxGetBValue(rgb)      ((BX_BYTE)((rgb)>>16))

#define BITMAPTYPE_SOLID        0
#define BITMAPTYPE_TRANSPARENT  1

/* Bitmap Header Definition */
typedef struct BX_BITMAP
  {
    BX_LONG        bmType;
    BX_LONG        bmWidth;
    BX_LONG        bmHeight;
    BX_LONG        bmWidthBytes;
    BX_WORD        bmPlanes;
    BX_WORD        bmBitsPixel;
    BX_PVOID      bmBits;
#ifdef SDLDRV
	SDL_Surface *img;
#endif	
  } BX_BITMAP, *BX_PBITMAP;

/* Icon Header Definition */
typedef struct BX_ICON
  {
    BX_PBITMAP       icoMask;
    BX_PBITMAP       icoBits;
  } BX_ICON, *BX_PICON;

typedef struct BX_RGBTRIPLE {
        BX_BYTE    rgbtBlue;
        BX_BYTE    rgbtGreen;
        BX_BYTE    rgbtRed;
} BX_RGBTRIPLE;

typedef struct BX_RGBQUAD {
        BX_BYTE    rgbBlue;
        BX_BYTE    rgbGreen;
        BX_BYTE    rgbRed;
        BX_BYTE    rgbReserved;
} BX_RGBQUAD;
typedef BX_RGBQUAD * LPBX_RGBQUAD;

typedef struct BX_BITMAPINFOHEADER{
        BX_DWORD      biSize;
        BX_LONG       biWidth;
        BX_LONG       biHeight;
        BX_WORD       biPlanes;
        BX_WORD       biBitCount;
        BX_DWORD      biCompression;
        BX_DWORD      biSizeImage;
        BX_LONG       biXPelsPerMeter;
        BX_LONG       biYPelsPerMeter;
        BX_DWORD      biClrUsed;
        BX_DWORD      biClrImportant;
} BX_BITMAPINFOHEADER, *PBX_BITMAPINFOHEADER;

/* constants for the biCompression field */
#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L

typedef struct BX_BITMAPINFO {
    BX_BITMAPINFOHEADER    bmiHeader;
    BX_RGBQUAD             bmiColors[1];
} BX_BITMAPINFO, *PBX_BITMAPINFO;

/* Logical Font */
#define LF_FACESIZE         32

typedef struct BX_LOGFONTA
{
    BX_LONG      lfHeight;
    BX_LONG      lfWidth;
    BX_LONG      lfEscapement;
    BX_LONG      lfOrientation;
    BX_LONG      lfWeight;
    BX_BYTE      lfItalic;
    BX_BYTE      lfUnderline;
    BX_BYTE      lfStrikeOut;
    BX_BYTE      lfCharSet;
    BX_BYTE      lfOutPrecision;
    BX_BYTE      lfClipPrecision;
    BX_BYTE      lfQuality;
    BX_BYTE      lfPitchAndFamily;
    BX_CHAR      lfFaceName[LF_FACESIZE];
} BX_LOGFONTA, *PBX_LOGFONTA;

typedef BX_LOGFONTA BX_FONT;
typedef PBX_LOGFONTA PBX_FONT;

BX_VOID BxCopyRect(BX_PRECT pRc1, BX_PRECT pRc2);
BX_BOOL BxSetRect( BX_PRECT lprc, BX_INT xLeft, BX_INT yTop, BX_INT xRight, BX_INT yBottom );
BX_INT BxRectWidth( BX_PRECT prc ) ;
BX_INT BxRectHeight( BX_PRECT prc ) ;
BX_VOID BxRectCenter( BX_PRECT prc, BX_PPOINT pp );
BX_INT BxRectCenterX( BX_PRECT prc );
BX_INT BxRectCenterY( BX_PRECT prc );
BX_BOOL BxPointInRect(BX_RECT* m_rc, BX_INT x, BX_INT y);
BX_BOOL BxRectInRect(BX_PRECT pRc, BX_PRECT pClRc);
BX_BOOL BxMergeRects(BX_PRECT pRc1, BX_PRECT pRc2, BX_PRECT pdstRc);

BX_BOOL BxSetDirtyArea(BX_RECT *rc);

BX_PBITMAP BxLoadImage(BX_PSTRING filename);
BX_PBITMAP BxLoadXPMImage(BX_CHAR **array);
BX_PBITMAP BxConvertBitmap(BX_PBITMAP pBmp);


#endif //BXGDI
