#include "Bx.h"
#include "BxLayout.h"

BX_VOID BxCreateLayout( BX_LAYOUTSTRUCT * pBxLout, HBOX hBox, BX_INT cols, BX_INT rows, BX_INT cmargin, BX_INT rmargin )
{
  BOXSTRUCT *pBx = (BOXSTRUCT *)hBox;

  if ( pBxLout == NULL )
    return;

  if ( hBox == NULL )
    return;

  if ( cols <= 0 )
    return;

  if ( rows <= 0 )
    return;

  pBxLout->CWidth = (BX_FLOAT)BxRectWidth(&pBx->rc)/(BX_FLOAT)cols;
  pBxLout->RHeight = (BX_FLOAT)BxRectHeight(&pBx->rc)/(BX_FLOAT)rows;

  pBxLout->hBx = hBox;
  pBxLout->Cols = cols;
  pBxLout->Rows = rows;
  pBxLout->CMargin = cmargin;
  if(pBxLout->CMargin <= 0)
    pBxLout->CMargin = 1;
  pBxLout->RMargin = rmargin;
  if(pBxLout->RMargin <= 0)
    pBxLout->RMargin = 1;
}

BX_VOID BxAssignBoxToLayout( HBOX hBox, BX_LAYOUTSTRUCT * pBxLout, 
                            BX_INT fromCol, BX_INT fromRow, 
                            BX_INT toCol, BX_INT toRow)
{
  BOXSTRUCT *pBx = (BOXSTRUCT *)hBox;
  BOXSTRUCT *ppBx;

  if ( pBx == NULL )
    return;

  if ( pBxLout == NULL )
    return;

  if ( pBxLout->hBx == NULL )
    return;

  ppBx = (BOXSTRUCT *)pBxLout->hBx;

  if ( toCol <= fromCol ) // single cell
    toCol = fromCol + 1;

  if ( toRow <= fromRow ) // single cell
    toRow = fromRow + 1;

  pBx->rc.left    = (BX_INT)(ppBx->rc.left + (pBxLout->CWidth * (BX_FLOAT)fromCol)) + pBxLout->CMargin;
  pBx->rc.top     = (BX_INT)(ppBx->rc.top + (pBxLout->RHeight * (BX_FLOAT)fromRow)) + pBxLout->RMargin;
  pBx->rc.right   = (BX_INT)(ppBx->rc.left + (pBxLout->CWidth * (BX_FLOAT)toCol)) - pBxLout->CMargin;
  pBx->rc.bottom  = (BX_INT)(ppBx->rc.top + (pBxLout->RHeight * (BX_FLOAT)toRow)) - pBxLout->RMargin;
}
