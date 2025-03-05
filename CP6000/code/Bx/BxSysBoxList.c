#include "Bx.h"
#include "BxSysBoxList.h"

BX_VOID AddTail(BxSysBoxList* lst, BX_PVOID element)
{
  PLISTELEMENT pLstElm = (PLISTELEMENT)BxMemAlloc(sizeof(LISTELEMENT));

  pLstElm->pElement = element;
  pLstElm->next = NULL;
  pLstElm->prev = NULL;

  if(lst->m_first == NULL)
  {
    lst->m_first = lst->m_last = pLstElm;
  }
  else
  {
    lst->m_last->next = pLstElm;
    pLstElm->prev = lst->m_last;
    lst->m_current = lst->m_last = pLstElm;
  }
  lst->m_length++;
}

BX_PVOID GetHead(BxSysBoxList* lst)
{
  lst->m_current = lst->m_first;
	if(lst->m_current==NULL)
		return NULL;
  return lst->m_current->pElement;
}


BX_PVOID GetNext(BxSysBoxList* lst)
{
  if(lst->m_current->next!=NULL)
  {
    lst->m_current = lst->m_current->next;
    return lst->m_current->pElement;
  }
  return NULL;
}

BX_VOID RemoveAll(BxSysBoxList* lst)
{
  lst->m_current = lst->m_first;
  while(lst->m_current != NULL)
  {
    lst->m_first = lst->m_current;
    lst->m_current = lst->m_current->next;
    BxMemFree( lst->m_first );
    lst->m_length--;
  }
	lst->m_first = lst->m_last = lst->m_current;
}

BX_PVOID GetTail(BxSysBoxList* lst)
{
  lst->m_current = lst->m_last;
  return lst->m_current->pElement;
}

BX_PVOID GetPrev(BxSysBoxList* lst)
{
  if(lst->m_current->prev!=NULL)
  {
    lst->m_current = lst->m_current->prev;
    return lst->m_current->pElement;
  }
  return NULL;
}

BX_PVOID Head(BxSysBoxList* lst)
{
  return lst->m_first->pElement;
}

BX_PVOID Tail(BxSysBoxList* lst)
{
  return lst->m_last->pElement;
}

BX_PVOID Current(BxSysBoxList* lst)
{
  return lst->m_current->pElement;
}

BX_BOOL Remove(BxSysBoxList* lst, BX_PVOID pElement)
{
  PLISTELEMENT tmp = lst->m_first;  

  while(tmp!=NULL)
  {
    if(pElement == tmp->pElement)
    {
      if(tmp == lst->m_first && lst->m_first == lst->m_last)
      {
        lst->m_first = lst->m_last = lst->m_current = NULL;
        BxMemFree( tmp );
        lst->m_length--;
        return TRUE;
      }
      if(tmp == lst->m_first)
      {
        lst->m_first = lst->m_first->next;
        lst->m_first->prev = NULL;
        BxMemFree( tmp );
        lst->m_length--;
        return TRUE;

      }
      if(tmp == lst->m_last)
      {
        lst->m_last = lst->m_last->prev;
        lst->m_last->next = NULL;
        BxMemFree( tmp );
        lst->m_length--;
        return TRUE;
      }
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
        BxMemFree( tmp );
      lst->m_length--;
      return TRUE;
    }
    tmp = tmp->next;
  }

  return FALSE;
}

BX_INT CurrentPosition(BxSysBoxList* lst)
{
  PLISTELEMENT tmp = lst->m_first;  

  return lst->m_current - tmp;
}

BX_BOOL SetCurrentPosition(BxSysBoxList* lst, BX_INT cPos)
{
  PLISTELEMENT tmp = lst->m_first;  

  if(tmp + cPos < lst->m_last)
  {
    lst->m_current = tmp + cPos;
    return TRUE;
  }
  
  return FALSE;
}

BX_WORD GetLength(BxSysBoxList* lst)
{
  return lst->m_length;
}
