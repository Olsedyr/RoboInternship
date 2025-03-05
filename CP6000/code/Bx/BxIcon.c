// BxIcon.c: implementation of BxIcon
//
//////////////////////////////////////////////////////////////////////

#include "Bx.h"
#include "BxIcon.h"

BX_PBITMAP BxBitmap_Load32(FILE * pFile);

BX_PICON BxCreateIcon(BX_PBITMAP pMsk, BX_PBITMAP pBits)
{
  BX_PICON m_ico;

  m_ico = (BX_PICON)BxMemAlloc(sizeof(BX_ICON));
  if(m_ico==NULL)
    return NULL;

  if((m_ico->icoMask = BxCreateBitmap(pMsk->bmWidth, pMsk->bmHeight, pMsk->bmPlanes, pMsk->bmBitsPixel, pMsk->bmBits))==NULL)
  {
    BxMemFree( m_ico );
    return NULL;
  }

  if((m_ico->icoBits = BxCreateBitmap(pBits->bmWidth, pBits->bmHeight, pBits->bmPlanes, pBits->bmBitsPixel, pBits->bmBits))==NULL)
  {
    BxDeleteBitmap( m_ico->icoMask );
    BxMemFree( m_ico );
    return NULL;
  }
   
  return m_ico;
}

BX_VOID BxDeleteIcon(BX_PICON m_ico)
{
  BxDeleteBitmap( m_ico->icoMask );
  BxDeleteBitmap( m_ico->icoBits );
  BxMemFree( m_ico );
}

BX_PICON BxIcon_Load(FILE * pFile)
{
  BX_PICON m_ico;

  if(!pFile)
    return NULL;

  m_ico = (BX_PICON)BxMemAlloc(sizeof(BX_ICON));

  if((m_ico->icoMask = BxBitmap_Load32(pFile))==NULL)
  {
    BxMemFree(m_ico);
    return NULL;
  }

  if((m_ico->icoBits = BxBitmap_Load32(pFile))==NULL)
  {
    BxDeleteBitmap(m_ico->icoMask);
    BxMemFree(m_ico);
    return NULL;
  }

  return m_ico;
}

BX_BOOL BxIcon_Save(BX_PICON m_ico, FILE * pFile)
{
  if(!pFile)
    return FALSE;

  if(!BxBitmap_Save(m_ico->icoMask, pFile))
    return FALSE;
  if(BxBitmap_Save(m_ico->icoBits, pFile))
    return TRUE;

  return FALSE;
}
