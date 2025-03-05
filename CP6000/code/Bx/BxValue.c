/***************************************************************************
                          BxValue.c  -  description
                             -------------------
    begin                : Wed Sep 17 2003
    copyright            : (C) 2003 by lms
    email                : lms@mpn.nu
 ***************************************************************************/
#include "Bx.h"
 
BX_BOOL BxAssignIntValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXINTVALUESTRUCT *iv;
  
  if(hBox==NULL)
    return FALSE;

  if(b->m_userData != NULL) // already allocated
    return TRUE;
    
  iv = (BXINTVALUESTRUCT*)BxMemAlloc(sizeof(BXINTVALUESTRUCT));
  if(iv==NULL)
    return FALSE;

  iv->type = BX_INT_VALUE;
  iv->value = 0;
  sprintf(iv->vstr,"%d", iv->value);
  b->lpBoxStr = iv->vstr;
  b->m_userData = iv;
  
  return TRUE;
}

BX_BOOL BxDeleteValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXINTVALUESTRUCT *iv;

  if(hBox==NULL)
    return FALSE;

  if(iv->type==BX_STRING_VALUE)
    BxMemFree(((BXSTRINGVALUESTRUCT*)b->m_userData)->vstr);

  BxMemFree((BXINTVALUESTRUCT*)b->m_userData);
  b->m_userData = NULL;
  
  return TRUE;
}

BX_BOOL BxSetIntValue(HBOX hBox, BX_INT val)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXINTVALUESTRUCT *iv = (BXINTVALUESTRUCT*)b->m_userData;

  iv->value = val;
  sprintf(iv->vstr,"%d", iv->value);
  BxRequestPaint(hBox);
  
  return TRUE;
}

BX_INT BxGetIntValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXINTVALUESTRUCT *iv = (BXINTVALUESTRUCT*)b->m_userData;

  return iv->value;
}

BX_BOOL BxAssignStringValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXSTRINGVALUESTRUCT *fv;

  if(hBox==NULL)
    return FALSE;

  if(b->m_userData != NULL) // already allocated
    return TRUE;

  fv = (BXSTRINGVALUESTRUCT*)BxMemAlloc(sizeof(BXSTRINGVALUESTRUCT));
  if(fv==NULL)
    return FALSE;

  fv->type = BX_STRING_VALUE;
  fv->length = 0;
  fv->vstr = NULL;
  fv->vstr = (BX_PSTRING)BxMemAlloc(sizeof(BX_CHAR)*256); // default string size
  sprintf(fv->vstr,"%s","");
  b->lpBoxStr = fv->vstr;
  b->m_userData = fv;

  return TRUE;
}

BX_BOOL BxSetStringValue(HBOX hBox, BX_PSTRING val)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXSTRINGVALUESTRUCT *fv = (BXSTRINGVALUESTRUCT*)b->m_userData;

  fv->length = strlen(val);
	if (fv->vstr==NULL)
	{
		fv->vstr = (BX_PSTRING)BxMemAlloc(sizeof(BX_CHAR)*(fv->length+1));
	}
  else if(fv->length > 255 && fv->length > strlen(fv->vstr))
  {
    BxMemFree(fv->vstr);
    fv->vstr = (BX_PSTRING)BxMemAlloc(sizeof(BX_CHAR)*(fv->length+1));
  }
	
  sprintf(fv->vstr,"%s", val);
  b->lpBoxStr = fv->vstr;

  BxRequestPaint(hBox);

  return TRUE;
}

BX_PSTRING BxGetStringValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXSTRINGVALUESTRUCT *fv = (BXSTRINGVALUESTRUCT*)b->m_userData;

  return fv->vstr;
}

BX_BOOL BxAssignFloatValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXFLOATVALUESTRUCT *fv;

  if(hBox==NULL)
    return FALSE;

  if(b->m_userData != NULL) // already allocated
    return TRUE;

  fv = (BXFLOATVALUESTRUCT*)BxMemAlloc(sizeof(BXFLOATVALUESTRUCT));
  if(fv==NULL)
    return FALSE;

  fv->type = BX_FLOAT_VALUE;
  fv->value = 0.0;
  sprintf(fv->vstr,"%.4f", fv->value);
  b->lpBoxStr = fv->vstr;
  b->m_userData = fv;

  return TRUE;
}

BX_BOOL BxSetFloatValue(HBOX hBox, BX_FLOAT val)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXFLOATVALUESTRUCT *fv = (BXFLOATVALUESTRUCT*)b->m_userData;

  fv->value = val;
  sprintf(fv->vstr,"%.4f", fv->value);
  BxRequestPaint(hBox);

  return TRUE;
}

BX_FLOAT BxGetFloatValue(HBOX hBox)
{
  PBOXSTRUCT b = (PBOXSTRUCT)hBox;
  BXFLOATVALUESTRUCT *fv = (BXFLOATVALUESTRUCT*)b->m_userData;

  return fv->value;
}

