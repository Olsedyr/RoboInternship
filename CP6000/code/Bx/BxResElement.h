// BxResElement.h: interface for BxResElement
//
//////////////////////////////////////////////////////////////////////

#if !defined(BXRESELEMENT_H)
#define BXRESELEMENT_H

#include "BxBitmap.h"
#include "BxIcon.h"

/*
typedef struct STRING_TABLE_ITEM_STRUCT
{
	BX_UINT ID;
	BX_UINT Length;
	BxString* pStr;
} STRING_TABLE_ITEM_STRUCT;

typedef struct STRING_TABLE_STRUCT
{
	BX_UINT Length;
	STRING_TABLE_ITEM_STRUCT *strItemTab;
} STRING_TABLE_STRUCT;
*/
typedef struct RESELEMENT
{
	BX_UINT resType;
	BX_UINT resID;
	BxBitmap * m_bmp;
	BxIcon * m_ico;
//	STRING_TABLE_STRUCT* m_strTab;
} BX_RESELEMENT, *PBX_RESELEMENT;

typedef BX_RESELEMENT BxResElement;

BX_VOID BxResElementDelete(PBX_RESELEMENT m_relm);
BX_BOOL BxResElementLoad(PBX_RESELEMENT m_relm, FILE *pFile);
BX_BOOL BxResElementSave(PBX_RESELEMENT m_relm, FILE *pFile);

#endif // !defined(BXRESELEMENT_H)
