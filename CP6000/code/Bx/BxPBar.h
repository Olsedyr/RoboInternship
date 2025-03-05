#ifndef BXPROGRESSBAR
#define BXPROGRESSBAR

/*
 * ProgressBar styles
 */
#define BPB_VERTICAL            0x0001L
#define BPB_HORIZONTAL          0x0002L
#define BPB_TYPEMASK            0xFF00L

#define BPB_DEFAULT             0x0000L
#define BPB_VOLUME              0x0100L


typedef struct BXPROGRESSBARSTRUCT {
 	BX_INT m_Style;               // Horisontal eller vertical
 	BX_INT m_Pos;                 // Aktuel bar position
	BX_INT m_Step;                // Step størrelse
	BX_INT m_Lower;               // Nedre grænse
	BX_INT m_Upper;               // Øvre grænse
	BX_DOUBLE m_StepSize;       
  BOXSTRUCT m_Bar;
  HBOX  hBx;

} BXPROGRESSBARSTRUCT;

extern BX_INT  BxProgressBar_StepIt( HBOX hbox );
extern BX_INT  BxProgressBar_SetStep( HBOX hbox, BX_INT Step );
extern BX_INT  BxProgressBar_SetPos( HBOX hbox, BX_INT Pos );
extern BX_VOID BxProgressBar_SetRange( HBOX hbox, BX_INT Lower, BX_INT Upper);
extern BX_BOOL BxProgressBar_Create( HBOX hBox, BXPROGRESSBARSTRUCT *pBxBar, BX_DWORD Style);
extern BX_VOID BxProgressBar_Paint( HBOX hbox );
extern BX_INT  BxProgressBar_GetPos( HBOX hbox );

#endif//BXPROGRESSBAR
