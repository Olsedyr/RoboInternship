// BxResource.h: interface for BxResource
//
//////////////////////////////////////////////////////////////////////

#if !defined(BXRESOURCE_H)
#define BXRESOURCE_H

#include "BxSysBoxList.h"
#include "BxResElement.h"

#define BX_RESTYPE_ALL					0x0
#define BX_RESTYPE_BITMAP				0x1
#define BX_RESTYPE_ICON					0x2
#define BX_RESTYPE_STRINGTABLE	0x3

BX_UINT GetCount(void);
BX_UINT CurrentID(void);
BxBitmap* LoadCurrentBitmap(void);
BxIcon* LoadCurrentIcon(void);
//BX_UINT GetFirst(BX_UINT resType = BX_RESTYPE_ALL);
//BX_UINT GetNext(BX_UINT resType = BX_RESTYPE_ALL);
BxBitmap* BxResourceLoadBxBitmap(BX_UINT ResourceID, BX_PSTRING res);
BxIcon* BxSystemResourceLoadBxIcon(BX_UINT ResourceID);
BxBitmap* BxSystemResourceLoadBxBitmap(BX_UINT ResourceID);
BxIcon* BxResourceLoadBxIcon(BX_UINT ResourceID, BX_PSTRING res);

extern BxResElement * pCurrent;
extern BxSysBoxList * pElement;
extern BX_BOOL FindElement(BX_UINT resType, BX_UINT ResID);

#endif // !defined(BXRESOURCE_H)
