#ifndef BXLAYOUT
#define BXLAYOUT

typedef struct BX_LAYOUTSTRUCT
{
	HBOX hBx;
	BX_INT Cols;
	BX_INT Rows;
	BX_INT CMargin;
	BX_INT RMargin;
	BX_FLOAT CWidth;
	BX_FLOAT RHeight;
} BX_LAYOUTSTRUCT;

extern BX_VOID BxCreateLayout( BX_LAYOUTSTRUCT * pBxLout, HBOX hBox, BX_INT cols, BX_INT rows, BX_INT cmargin, BX_INT rmargin );
extern BX_VOID BxAssignBoxToLayout( HBOX hBox, BX_LAYOUTSTRUCT * pBxLout, 
                            BX_INT fromCol, BX_INT fromRow, 
                            BX_INT toCol, BX_INT toRow);


#endif // BXLAYOUT
