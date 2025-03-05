#if !defined(BXSYSBOXLIST_H)
#define BXSYSBOXLIST_H

typedef struct LISTELEMENT {
  BX_PVOID pElement;
  struct LISTELEMENT * next, * prev;
} LISTELEMENT, *PLISTELEMENT;

typedef struct BxSysBoxList
{
  BX_WORD m_length;
  BX_INT m_cPosition;
  PLISTELEMENT m_current;
  PLISTELEMENT m_first;
  PLISTELEMENT m_last;
} BxSysBoxList;

BX_VOID AddTail(BxSysBoxList* lst, BX_PVOID element);
BX_PVOID GetHead(BxSysBoxList* lst);
BX_PVOID GetNext(BxSysBoxList* lst);
BX_VOID RemoveAll(BxSysBoxList* lst);
BX_PVOID GetTail(BxSysBoxList* lst);
BX_PVOID GetPrev(BxSysBoxList* lst);
BX_PVOID Head(BxSysBoxList* lst);
BX_PVOID Tail(BxSysBoxList* lst);
BX_PVOID Current(BxSysBoxList* lst);
BX_BOOL Remove(BxSysBoxList* lst, BX_PVOID pElement);
BX_INT CurrentPosition(BxSysBoxList* lst);
BX_BOOL SetCurrentPosition(BxSysBoxList* lst, BX_INT cPos);
BX_WORD GetLength(BxSysBoxList* lst);

#endif //BXSYSBOXLIST_H










