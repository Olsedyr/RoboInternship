#ifndef BXLIST
#define BXLIST

#define MIN_SCROLLBAR_WIDTH   75
#define MIN_LISTLABEL_HEIGHT  50
#define MAX_LABELS_IN_LIST    15

typedef struct BXLISTUNITSTRUCT {
	struct BXLISTUNITSTRUCT *m_Next;
	struct BXLISTUNITSTRUCT *m_Prev;
	BX_CHAR           m_Str[255];
} BXLISTUNITSTRUCT;

typedef struct BXLISTSTRUCT {
	BX_INT m_Style;               // Horisontal eller vertical
	BX_INT m_Pos;                 // Aktuel bar position
	BX_INT m_ViewPos;             // Første synlige bar position
	BX_INT m_NumView;             // Antal Labels
	BX_INT m_Items;               // Antal enheder i listen
	HBOX  hBx;
	BXSCROLLBARSTRUCT m_ScrollBarStruct;
	BOXSTRUCT m_ScrollBar;
	BXLISTUNITSTRUCT *m_First;
	BXLISTUNITSTRUCT *m_Last;
	BXLISTUNITSTRUCT *m_Ptr;
	BOXSTRUCT m_LabTab[MAX_LABELS_IN_LIST];
} BXLISTSTRUCT;

extern BX_BOOL BxList_Create( HBOX hBox, BXLISTSTRUCT *pBxSBar, BX_DWORD Style);
extern BX_BOOL BxList_AddString( HBOX hBox, BX_PSTRING lpStr);
extern BX_BOOL BxList_InsertString( HBOX hBox, BX_INT index, BX_PSTRING lpStr);
extern BX_BOOL BxList_DeleteString( HBOX hBox, BX_INT index);
extern BX_INT  BxList_GetSelected(HBOX hBox);
extern BX_INT  BxList_GetCount(HBOX hBox);
extern BX_PSTRING  BxList_GetString(HBOX hBox, BX_INT index);
extern BX_INT BxList_SetString(HBOX hBox, BX_INT index, BX_PSTRING pStr);
extern BX_VOID BxList_Update(HBOX hBox);
extern BX_INT  BxList_SetSelected(HBOX hBox, BX_INT index);

#endif//BXLISTBAR
