#ifndef BXDC
#define BXDC

typedef struct BxDC
{
//	BxBitmap * m_CurrentBitmap;
	BX_RECT m_clipRect;
	BX_UINT m_TextAlign;
	FONT* m_CurrentFont;
	BX_COLORREF m_CurrentBrush;
	BX_COLORREF m_CurrentPen;
	BX_COLORREF m_CurrentTextColor;
	BX_COLORREF m_CurrentBkColor;
	BX_BOOL m_AlphaOn;
    BX_BYTE m_AlphaLevel;
	BxGfxDrv* m_GfxDrv;

} BxDC;

extern BxDC* BxGetDC( HBOX hBox );
extern BX_VOID BxUpdateView(HBOX hBx);
extern BX_BOOL BxSetAlpha( BxDC* pDC, BX_BOOL mode );
extern BX_BOOL BxIsAlphaOn( BxDC *pDC );
extern BX_BYTE BxSetAlphaLevel( BxDC* pDC, BX_BYTE level );
extern BX_BYTE BxGetAlphaLevel( BxDC* pDC );

BX_BOOL BxCreateDC(BxDC* dc);
BxDC* BxGetBoxDC(HBOX hBx);
BX_VOID BxRectangle(BxDC* pDC, BX_RECT * pRect);
BX_VOID BxLine(BxDC* pDC, BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2);
BX_VOID BxFrame(BxDC* pDC, BX_RECT * pRect, BX_COLORREF color1, BX_COLORREF color2);
BX_VOID BxRoundRect(BxDC* pDC, BX_RECT * pRect, BX_INT r);
BX_BOOL BxTextOut(BxDC* pDC, BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr);
BX_COLORREF BxSetTextColor(BxDC* pDC, BX_COLORREF TxtClr);
BX_COLORREF BxSetBkColor(BxDC* pDC, BX_COLORREF BkClr);
BX_UINT BxSetTextAlign(BxDC* pDC, BX_UINT Flag);
BX_UINT BxGetTextAlign(BxDC* pDC);
BX_COLORREF BxSetPen(BxDC* pDC, BX_COLORREF penClr);
BX_COLORREF BxSetBrush(BxDC* pDC, BX_COLORREF brClr);
BX_VOID BxSolidRect(BxDC* pDC, BX_RECT * pRect, BX_COLORREF clr);
BxFont* BxGetCurrentFont(BxDC* pDC);
BxFont* BxSetFont(BxDC* pDC, BxFont * pFont);
BX_VOID BxSetClipRegion(BxDC* pDC, BX_RECT * rc);
BX_INT BxDrawText(BxDC* pDC, BX_PSTRING pString, BX_INT Count, BX_PRECT pRect, BX_UINT Format);
BX_INT BxDrawMultiLineText(BxDC* pDC, BX_PSTRING pString, BX_INT Count, BX_PRECT pRect, BX_UINT Format);
/*
BxBitmap * SetBitmap(BxDC* pDC, BxBitmap * pBitmap);
*/

BX_BOOL BxDrawIcon(BxDC* pDC, BX_INT x, BX_INT y, BX_PICON pIcon);
BX_BOOL BxDrawBitmap(BxDC* pDC, BX_INT x, BX_INT y, BX_PBITMAP pBmp, BX_INT paintType);
BX_BOOL BxGetBitmap(BxDC* pDC, BX_INT x, BX_INT y, BX_PBITMAP pBmp);

BX_COLORREF BxSetPixel(BxDC* pDC, BX_INT x, BX_INT y, BX_COLORREF color);



#endif // BXDC
