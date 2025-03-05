// BxResElement.c: implementation of BxResElement.
//
//////////////////////////////////////////////////////////////////////

#include "Bx.h"
#include "BxResource.h"
#include "BxResElement.h"

BX_BOOL BxResElementLoad(PBX_RESELEMENT m_relm, FILE * pFile)
{
//	BX_CHAR *inStr;

	if(!pFile)
		return FALSE;

	fread(&m_relm->resType, sizeof(m_relm->resType), 1, pFile);
	fread(&m_relm->resID, sizeof(m_relm->resID), 1, pFile);
	
	switch(m_relm->resType) {
		case BX_RESTYPE_BITMAP:
			m_relm->m_bmp = BxBitmap_Load(pFile);
			break;
		case BX_RESTYPE_ICON:
			m_relm->m_ico = BxIcon_Load(pFile);
			break;
/*
		case BX_RESTYPE_STRINGTABLE:
			m_strTab = (STRING_TABLE_STRUCT*)BxMemAlloc(sizeof(STRING_TABLE_STRUCT));
			pFile->Read(&m_strTab->Length, sizeof(m_strTab->Length));

			m_strTab->strItemTab = (STRING_TABLE_ITEM_STRUCT*)BxMemAlloc(sizeof(STRING_TABLE_ITEM_STRUCT)*(m_strTab->Length));

			for(BX_UINT i=0; i<m_strTab->Length; i++)
			{
				pFile->Read(&m_strTab->strItemTab[i].ID, sizeof(m_strTab->strItemTab[i].ID));
				pFile->Read(&m_strTab->strItemTab[i].Length, sizeof(m_strTab->strItemTab[i].Length));
				inStr = new BX_CHAR[m_strTab->strItemTab[i].Length];
				m_strTab->strItemTab[i].pStr = (BxString*)BxMemAlloc(sizeof(BxString));
				m_strTab->strItemTab[i].pStr->Constructor(inStr);
				pFile->Read((BX_PSTRING)m_strTab->strItemTab[i].pStr, sizeof(m_strTab->strItemTab[i].Length));
				BxMemFree( inStr );
			}
			break;
*/
	}
	return TRUE;
}

BX_BOOL BxResElementSave(PBX_RESELEMENT m_relm, FILE * pFile)
{
	if(!pFile)
		return FALSE;

	fwrite(&m_relm->resType, sizeof(m_relm->resType), 1, pFile);
	fwrite(&m_relm->resID, sizeof(m_relm->resID), 1, pFile);
	
	switch(m_relm->resType) {
		case BX_RESTYPE_BITMAP:
			return BxBitmap_Save(m_relm->m_bmp, pFile);
			break;
		case BX_RESTYPE_ICON:
			return BxIcon_Save(m_relm->m_ico, pFile);
			break;
/*
		case BX_RESTYPE_STRINGTABLE:
			pFile->Write(&m_strTab->Length, sizeof(m_strTab->Length));
			for(BX_UINT i=0; i<m_strTab->Length; i++)
			{
				pFile->Write(&m_strTab->strItemTab[i].ID, sizeof(m_strTab->strItemTab[i].ID));
				pFile->Write(&m_strTab->strItemTab[i].Length, sizeof(m_strTab->strItemTab[i].Length));
				pFile->Write((BX_PSTRING)m_strTab->strItemTab[i].pStr, sizeof(m_strTab->strItemTab[i].pStr->GetLength()));
			}
			break;
*/
	}
	return TRUE;
}

BX_VOID BxResElementDelete(PBX_RESELEMENT m_relm)
{
	switch(m_relm->resType) {
		case BX_RESTYPE_BITMAP:
				BxDeleteBitmap(m_relm->m_bmp);
			break;
		case BX_RESTYPE_ICON:
			BxDeleteIcon(m_relm->m_ico);
			break;
	}
	BxMemFree( m_relm );
}
