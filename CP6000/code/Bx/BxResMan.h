// BxResMan.h: interface for BxResMan.
//
//////////////////////////////////////////////////////////////////////

#if !defined(BXRESMAN_H)
#define BXRESMAN_H

#include "BxResource.h"

#define RESMAN_OK										0
#define RESMAN_ERROR_NULL_PTR				1
#define RESMAN_ERROR_ID_EXISTS			2
#define RESMAN_ERROR_OPENFILE				3
#define RESMAN_ERROR_WRITEFILE			4
#define RESMAN_ERROR_READFILE				5
#define RESMAN_ERROR_CREATEBITMAP		6

BX_BOOL AddResource(BX_UINT type, BX_UINT id, BX_PVOID data);
BX_BOOL AddResourceElm(BxResElement * elm);
BX_BOOL RemoveResource(BX_UINT type, BX_UINT id);
BX_VOID RemoveAll();
BX_INT SaveResource(BX_PSTRING filename);
BX_INT LoadResource(BX_PSTRING filename);

#endif // !defined(BXRESMAN_H)
