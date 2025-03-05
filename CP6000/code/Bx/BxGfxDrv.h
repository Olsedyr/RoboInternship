#ifndef BXGFXDRV
#define BXGFXDRV

typedef struct BxGfxDrvStruct
{
  BX_INT (*Init)(BX_VOID);
  BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask, BX_BYTE alpha);
  BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_PBITMAP pBmp, BX_INT PaintType, BX_BYTE alpha);
  BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color, BX_BYTE alpha);
  BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr, BX_BYTE alpha);
  BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush, BX_BYTE alpha);
  BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush, BX_BYTE alpha);
  BX_VOID (*Line)(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen, BX_BYTE alpha);
  BX_COLORREF (*Circle)(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha);
  BX_COLORREF (*FillCircle)(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha);
  BX_VOID (*CopyArea)(BX_RECT *rc);
} BxGfxDrv;

extern BxGfxDrv* sysGfxDrv;

typedef struct BxGfxDrvInfoStruct
{
  int Width;
  int Height;
  int BytesPrPixel;
  int ByteWidth;
  unsigned char *framebuffer;
} BxGfxDrvInfo;

#endif //BXGFXDRV
