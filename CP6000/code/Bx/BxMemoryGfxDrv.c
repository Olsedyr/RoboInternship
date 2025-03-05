#include "Bx.h"
#include "BxDrivers.h"
#include "font.h"

#ifdef MEMDRV
BxGfxDrvInfo FBInfo;

BX_VOID BxSleep(BX_DWORD ms)
{
//	sleepTask(CURRENTTASK, MS_TO_TICKS(ms));
}

void fbcon_bell(void)
{
}

BX_BOOL GreyFramebuffer(BX_VOID)
{
  return TRUE;
}

void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);
#endif //MEMDRV

/* static BX_WORD ConvertColor(BX_COLORREF clr) */
/* { */
/* 	BX_WORD c=0; */

/* 	c = (BxGetRValue(clr)>>3)<<11 | (BxGetGValue(clr)>>2)<<5 | BxGetBValue(clr)>>3; */

/* 	return c; */
/* } */

static BX_INT BxGfxMEMDrv_Init(BX_VOID)
{
	return BX_STATUS_OK;
}


static BX_VOID BxGfxMEMDrv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush, BX_BYTE alpha)
{
}


static BX_VOID BxGfxMEMDrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen, BX_BYTE alpha)
{
}


static BX_VOID BxGfxMEMDrv_FillRect(BX_RECT * pRect, BX_COLORREF brush, BX_BYTE alpha)
{
//  gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
}


static BX_BOOL BxGfxMEMDrv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr, BX_BYTE alpha)
{
  //DrawFontString(pStr, pFont, x, y, ConvertColor(FntClr), 0);

	return TRUE;
}



static BX_COLORREF BxGfxMEMDrv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color, BX_BYTE alpha)
{
//  gl_setpixel(x, y, ConvertColor(color));

	return color;
}

static BX_BOOL BxGfxMEMDrv_PutBitmap(BX_INT x, BX_INT y, BX_PBITMAP pBmp, BX_INT paintType, BX_BYTE alpha)
{
	return TRUE;
}

static BX_BOOL BxGfxMEMDrv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask, BX_BYTE alpha)
{
	return TRUE;
}

BX_VOID BxGfxMEMDrv_MMap(BX_PVOID data, BX_DWORD size)
{

}

static BX_COLORREF BxGfxMEMDrv_Circle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha)
{
  return color;
}

static BX_COLORREF BxGfxMEMDrv_FillCircle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha)
{
  return color;
}

static BX_VOID BxGfxMEMDrv_CopyVirtualToPhysicArea(BX_RECT *rc)
{
}


BxGfxDrv BxGfxMEMDrv = 
{
	BxGfxMEMDrv_Init, //BX_INT (*Init)(BX_VOID);
	BxGfxMEMDrv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
	BxGfxMEMDrv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
	BxGfxMEMDrv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
	BxGfxMEMDrv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
	BxGfxMEMDrv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
	BxGfxMEMDrv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
	BxGfxMEMDrv_Line,  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
  BxGfxMEMDrv_Circle,
  BxGfxMEMDrv_FillCircle,
  BxGfxMEMDrv_CopyVirtualToPhysicArea
};
