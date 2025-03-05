#ifndef BXSCROLLBAR
#define BXSCROLLBAR

/*
 * ScrollBar styles
 */
#define BSB_VERTICAL            0x0001L
#define BSB_HORIZONTAL          0x0002L
#define BSB_NOCAPTION           0x0004L
#define BPB_TYPEMASK            0xFF00L

typedef struct BXSCROLLBARSTRUCT {
 	BX_INT m_Style;               // Horisontal eller vertical
 	BX_INT m_Pos;                 // Aktuel bar position
	BX_INT m_Step;                // Step størrelse
	BX_INT m_Lower;               // Nedre grænse
	BX_INT m_Upper;               // Øvre grænse
	BX_DOUBLE m_StepSize;       
  BX_RECT 	m_SlideRect;
  BX_RECT 	m_SlideBarRect;
  BX_POINT  m_oldP;
  BOXSTRUCT m_Bar;
  BOXSTRUCT m_Inc;
  BOXSTRUCT m_Dec;
  HBOX  hBx;
} BXSCROLLBARSTRUCT;

extern BX_BOOL BxScrollBar_Create( HBOX hBox, BXSCROLLBARSTRUCT *pBxSBar, BX_DWORD Style);
extern BX_VOID BxScrollBar_SetRange( HBOX hbox, BX_INT Lower, BX_INT Upper);
extern BX_INT BxScrollBar_SetPos( HBOX hbox, BX_INT Pos);
extern BX_INT BxScrollBar_GetPos( HBOX hbox);
extern BX_INT BxScrollBar_GetLower( HBOX hbox);
extern BX_INT BxScrollBar_GetUpper( HBOX hbox);

#endif//BXSCROLLBAR
