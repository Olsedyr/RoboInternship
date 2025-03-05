// BxIcon.h: interface for BxIcon
//
//////////////////////////////////////////////////////////////////////

#if !defined(BXICON_H)
#define BXICON_H

typedef BX_ICON BxIcon;
BX_PICON BxIcon_Load(FILE * pFile);
BX_BOOL BxIcon_Save(BX_PICON m_ico, FILE * pFile);
BX_VOID BxDeleteIcon(BX_PICON m_ico);
BX_PICON BxCreateIcon(BX_PBITMAP pMsk, BX_PBITMAP pBits);

#endif // !defined(BXICON_H)
