// BxResMan.c: implementation of BxResMan.
//
//////////////////////////////////////////////////////////////////////

#include "Bx.h"
#include "BxResMan.h"

BX_VOID ResManRemoveAll();
BX_INT SaveResource(BX_PSTRING filename)
{
	FILE *fp;
	BX_INT i, n;
  BxResElement *pRes = (BxResElement*)GetHead(pElement);

	if(filename==NULL)
		return RESMAN_ERROR_NULL_PTR;

	if((fp = fopen(filename, "wb"))==NULL)
		return RESMAN_ERROR_OPENFILE;

	// Save resource header

	n = GetLength(pElement);
	fwrite(&n, sizeof(BX_WORD), 1, fp);
	
	for(i=0;i<n;i++)
	{
		BxResElementSave(pRes, fp);
		pRes = (BxResElement*)GetNext(pElement);
	}
	fclose(fp);

	return RESMAN_OK;
}


BX_INT LoadResource(BX_PSTRING filename)
{
	FILE *fp;
	BX_INT i;
	BX_WORD num;
	BX_ICON pIco;
	BxResElement * elm;

	if(filename==NULL)
		return RESMAN_ERROR_NULL_PTR;

	if((fp = fopen(filename, "rb"))==NULL)
		return RESMAN_ERROR_OPENFILE;

	ResManRemoveAll();

	// Read resource header

	fread(&num, sizeof(BX_WORD), 1, fp);

	for(i=0;i<num;i++)
	{
		elm = (BxResElement*)BxMemAlloc(sizeof(BxResElement));
		BxResElementLoad(elm, fp);
		switch ( elm->resType ) {
		case BX_RESTYPE_BITMAP:
		  AddResource(elm->resType, elm->resID, (BX_PVOID)elm->m_bmp);
		break;
		case BX_RESTYPE_ICON:
			pIco.icoMask = elm->m_ico->icoMask;
			pIco.icoBits = elm->m_ico->icoBits;
			AddResource(elm->resType, elm->resID, (BX_PVOID)&pIco);
		break;
		}
		BxMemFree( elm );
	}
	fclose(fp);

	return RESMAN_OK;
}


BX_VOID ResManRemoveAll()
{
  BxResElement *pRes = (BxResElement*)GetHead(pElement);

	while(pRes!=NULL)
	{
//		DeleteRes(pRes);
		BxMemFree(pRes);
		pRes = (BxResElement*)GetNext(pElement);
	}
	RemoveAll(pElement);
}

BX_BOOL AddResource(BX_UINT type, BX_UINT id, BX_PVOID data)
{
	BxResElement *nelm;
	BxBitmap* tmp;
	BX_PICON itmp;

	if(!data) return FALSE;

	if(FindElement(type, id))
		return FALSE;
	
	nelm = (BxResElement*)BxMemAlloc(sizeof(BxResElement));

	nelm->resType = type;
	nelm->resID = id;
	switch(type) {
		case BX_RESTYPE_BITMAP:
			nelm->m_bmp = (BxBitmap*)BxMemAlloc(sizeof(BxBitmap));

			tmp = (BxBitmap*)data;
			nelm->m_bmp = BxCreateBitmap(tmp->bmWidth, tmp->bmHeight, tmp->bmPlanes, tmp->bmBitsPixel, tmp->bmBits);
		break;
		case BX_RESTYPE_ICON:
			nelm->m_ico = (BxIcon*)BxMemAlloc(sizeof(BxIcon));
			itmp = (BX_PICON)data;
			nelm->m_ico=BxCreateIcon(itmp->icoMask, itmp->icoBits);
		break;
		default:
			return FALSE;
	}

	AddTail(pElement, (BX_PVOID)nelm);

	return TRUE;
}

BX_BOOL AddResourceElm(BxResElement * elm)
{
	if(!elm) return FALSE;

	if(FindElement(elm->resType, elm->resID))
		return FALSE;
	
	AddTail(pElement, (BX_PVOID)elm);

	return TRUE;
}

BX_BOOL RemoveResource(BX_UINT type, BX_UINT id)
{
	BxResElement * nelm;

	if(!FindElement(type, id))
		return FALSE;
	
	nelm = (BxResElement *)Current(pElement);

	Remove(pElement, (BX_PVOID)nelm);

	return TRUE;
}
