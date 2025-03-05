// BxResource.c: implementation of BxResource.
//
//////////////////////////////////////////////////////////////////////

#include "Bx.h"
#include "BxResource.h"

#define PICTURE       0x01
#define ICON          0x02

typedef struct BX_RESOURCE_ELEMENT_HEADER {
  BX_CHAR   id[255];
  BX_INT    type;
  BX_INT    size;
} BX_RESOURCE_ELEMENT_HEADER;

BxResElement * pCurrent;
BxSysBoxList systemResourceList = {0, 0, NULL, NULL, NULL}, * pElement = &systemResourceList;

BX_BOOL FindElement(BX_UINT resType, BX_UINT ResID);

BxBitmap *LoadResBitmap(FILE *fp, BX_UINT ResourceID)
{
  BxBitmap *pBmp = NULL;
  BX_RESOURCE_ELEMENT_HEADER rhd;
  
  if(fp!=NULL)
  {
    fread(&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER), 1, fp);
        
    while(feof(fp)==0)
    {
      if(rhd.type == PICTURE && atoi(rhd.id) == ResourceID)
      {
        pBmp = BxBitmap_Load(fp);
#ifdef SDLDRV
       pBmp = BxConvertBitmap(pBmp);
#endif //SDLDRV
        return pBmp;
      }
      else
      {
        fseek(fp, rhd.size, SEEK_CUR);
        fread(&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER), 1, fp);
      }
    }
  }  
  else
    printf("LoadResBitmap FAILED\n");
  return pBmp;
}

BxIcon *LoadResIcon(FILE *fp, BX_UINT ResourceID)
{
  BxIcon *pIco = NULL;
  BX_RESOURCE_ELEMENT_HEADER rhd;

  if(fp!=NULL)
  {
    fread(&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER), 1, fp);
    while(!feof(fp))
    {
      if(rhd.type == ICON && atoi(rhd.id) == ResourceID)
      {
        pIco = BxIcon_Load(fp);
        return pIco;
      }
      else
      {
        fseek(fp, rhd.size, SEEK_CUR);
        fread(&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER), 1, fp);
      }
    }
  }
  else
    fprintf(stderr, "LoadResIcon FAILED\n");
  return pIco;
}

BxBitmap* BxResourceLoadBxBitmap(BX_UINT ResourceID, BX_PSTRING res)
{
  BxBitmap* pBmp;
  FILE *fp;
  
  if(!FindElement(BX_RESTYPE_BITMAP, ResourceID))
  {
    // seek in user resource file: eg. res.bxr
    if((fp = fopen(res, "r")) == NULL)
      return NULL;
    if((pBmp = LoadResBitmap(fp, ResourceID))==NULL)
    {
      fclose(fp);
      return NULL;
    }
    fclose(fp);
  }
  else
    pBmp = pCurrent->m_bmp;

  return pBmp;
}

BxIcon* BxResourceLoadBxIcon(BX_UINT ResourceID, BX_PSTRING res)
{
  BxIcon* pIco;
  FILE *fp;
//  if(!FindElement(BX_RESTYPE_ICON, ResourceID))
  {
    // seek in user resource file: res.bxr
    if((fp = fopen(res, "r")) == NULL)
     return NULL;
    if((pIco = LoadResIcon(fp, ResourceID))==NULL)
    {
      fclose(fp);
      return NULL;
    }
    fclose(fp);
  }
//  else
//    pIco = pCurrent->m_ico;

  return pIco;
}

BxIcon* BxSystemResourceLoadBxIcon(BX_UINT ResourceID)
{
  BxIcon* pIco;

  if(!FindElement(BX_RESTYPE_ICON, ResourceID))
  {
    return NULL;
  }
  else
    pIco = pCurrent->m_ico;

  return pIco;
}

BxBitmap* BxSystemResourceLoadBxBitmap(BX_UINT ResourceID)
{
  BxBitmap* pBmp;

  if(!FindElement(BX_RESTYPE_BITMAP, ResourceID))
  {
    return NULL;
  }
  else
    pBmp = pCurrent->m_bmp;

  return pBmp;
}

BX_BOOL FindElement(BX_UINT resType, BX_UINT resID)
{
  BxResElement *pRes = (BxResElement*)GetHead(pElement);

  while(pRes!=NULL)
  {
    if(pRes->resType==resType && pRes->resID==resID)
    {
      pCurrent = pRes;
      return TRUE;
    }
    pRes = (BxResElement*)GetNext(pElement);
  }
  return FALSE;
}

BX_UINT BxResourceGetFirst(BX_UINT resType)
{
  BxResElement *pRes = (BxResElement*)GetHead(pElement);

  if(pRes==NULL)
    return 0;

  if(resType==BX_RESTYPE_ALL)
    pCurrent = (BxResElement*)GetHead(pElement);
  else
  {
    while(pRes!=NULL)
    {
      if(pRes->resType==resType)
      {
        pCurrent = pRes;
        return pCurrent->resType;
      }
      pRes = (BxResElement*)GetNext(pElement);
    }
  }
  return pCurrent->resType;
}

BX_UINT BxResourceGetNext(BX_UINT resType)
{
  BxResElement *pRes = pCurrent;

  if(resType==BX_RESTYPE_ALL)
    pCurrent = (BxResElement*)GetNext(pElement);
  else
  {
    while(pRes!=NULL)
    {
      if(pRes->resType==resType)
      {
        pCurrent = pRes;
        return pCurrent->resType;
      }
      pRes = (BxResElement*)GetNext(pElement);
    }
  }
  if(pCurrent==NULL)
    return 0;
  return pCurrent->resType;
}

BxBitmap* BxResourceLoadCurrentBitmap(BX_VOID)
{
  BxBitmap* pBmp;

  pBmp = pCurrent->m_bmp;

  return pBmp;
}

BxIcon* BxResourceLoadCurrentIcon(BX_VOID)
{
  return pCurrent->m_ico;
}

BX_UINT BxResourceCurrentID()
{
  return pCurrent->resID;
}

BX_UINT BxResourceGetCount(BX_VOID)
{
  return GetLength(pElement);
}
