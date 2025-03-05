// BxBitmap.h: interface for the BxBitmap structure
//
//////////////////////////////////////////////////////////////////////

#if !defined(BXBITMAP_H)
#define BXBITMAP_H

typedef BX_BITMAP BxBitmap;
BX_PBITMAP BxBitmap_Load(FILE * pFile);
BX_BOOL BxBitmap_Save(BX_PBITMAP m_bmp, FILE * pFile);
BX_PBITMAP BxCreateBitmap(BX_INT Width, BX_INT Height, BX_UINT Planes, BX_UINT BitCount, BX_PVOID Bits );
BX_PBITMAP BxCreateCompatibleBitmap(BX_INT Width, BX_INT Height, BX_PVOID Bits );
BX_VOID BxDeleteBitmap(BX_PBITMAP m_bmp);

#endif // BXBITMAP_H
