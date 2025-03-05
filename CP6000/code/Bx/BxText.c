// Edit CLASS
#include "BxPrivate.h"

//BX_VOID Edit_OnEnable(HBOX hbox, BX_BOOL fEnable) { Static_Enable(hbox, fEnable);}
BX_VOID Edit_OnPaint(HBOX hbox);

CLASSDEF EDIT_CLASS = {
	Box_OnQuit,
	Box_OnCreate,
  Box_OnShowBox,
	Box_OnDestroy,
	Box_OnEnable,
	Box_OnSetText,
	Box_OnGetText,
	Box_OnGetTextLength,
	Box_OnClose,
	Edit_OnPaint,
	Box_OnNCPaint,
	Box_OnNCHitTest,
	Box_OnActivate,
	Box_OnSetFocus,
	Box_OnKillFocus,
	Box_OnKeyDown,
	Box_OnKeyUp,
	Box_OnChar,
	Box_OnDeadChar,
	Box_OnSysKeyDown,
	Box_OnSysKeyUp,
	Box_OnSysChar,
	Box_OnSysDeadChar,
	Box_OnMouseMove,
	Box_OnLButtonDown,
	Box_OnLButtonUp,
	Box_OnNCMouseMove,
	Box_OnNCLButtonDown,
	Box_OnNCLButtonUp,
	Box_OnMouseActivate,
	Box_OnCut,
	Box_OnClear,
	Box_OnSetCursor,
	Box_OnSysCommand,
};

PCLASS hCls_Edit = &EDIT_CLASS;


BX_LRESULT DefEditProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
   switch (uMsg)
   {
		case BEM_GETSEL: break;
		case BEM_SETSEL: break;              
		case BEM_GETRECT: break;              
		case BEM_SETRECT: break;              
		case BEM_SETRECTNP: break;            
		case BEM_SCROLL: break;               
		case BEM_LINESCROLL: break;           
		case BEM_SCROLLCARET: break;          
		case BEM_GETMODIFY: break;            
		case BEM_SETMODIFY: break;            
		case BEM_GETLINECOUNT: break;         
		case BEM_LINEINDEX: break;            
		case BEM_SETHANDLE: break;            
		case BEM_GETHANDLE: break;            
		case BEM_GETTHUMB: break;             
		case BEM_LINELENGTH: break;           
		case BEM_REPLACESEL: break;           
		case BEM_GETLINE: break;              
		case BEM_LIMITTEXT: break;            
		case BEM_CANUNDO: break;              
		case BEM_UNDO: break;                 
		case BEM_FMTLINES: break;             
		case BEM_LINEFROMCHAR: break;         
		case BEM_SETTABSTOPS: break;          
		case BEM_SETPASSWORDCHAR: break;      
		case BEM_EMPTYUNDOBUFFER: break;      
		case BEM_GETFIRSTVISIBLELINE: break;  
		case BEM_SETREADONLY: break;          
		case BEM_SETWORDBREAKPROC: break;     
		case BEM_GETWORDBREAKPROC: break;     
		case BEM_GETPASSWORDCHAR: break;      

		case BEM_SETMARGINS: break;           
		case BEM_GETMARGINS: break;           
		case BEM_GETLIMITTEXT: break;         
		case BEM_POSFROMCHAR: break;          
		case BEM_CHARFROMPOS: break;          
	  default:
         return( DefBoxProc( hBox, uMsg, wParam, lParam ) ) ;
   }
   return 0L ;
}


BX_VOID Edit_OnPaint(HBOX hbox)
{
  BOXSTRUCT *b = hbox;
	BX_RECT m_txtRect;

	b->m_Dirty = FALSE;

  switch(b->style & BES_TYPEMASK) {
	default:
		m_txtRect.left = b->rc.left+2;
		m_txtRect.top = b->rc.top+2;
		m_txtRect.right = b->rc.right-2;
		m_txtRect.bottom = b->rc.bottom-2;
	}

  BxUpdateOff();

  if(b->style & BXS_VISIBLE)
  {
    switch(b->boxState & BBS_STATEMASK) {
    case BA_INACTIVE:
      if((b->style & BES_TYPEMASK) & BES_RIGHT)
			{
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
					BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect,  DT_TOP | DT_RIGHT);
			}
      else if((b->style & BES_TYPEMASK) & BES_CENTER)
      {
				if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
					BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect,  DT_TOP | DT_CENTER);
			}
		  else
			{
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
          BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_TOP | DT_LEFT);
      }
			break;
    case BA_ACTIVE:
      switch(b->style & BES_TYPEMASK) {
      case BES_CENTER:
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
					BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect,  DT_TOP | DT_CENTER);
        break;
      default:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
        BxRectangle(&b->m_BxDC, &b->rc);
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
          BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect, DT_TOP | DT_LEFT);
        break;
      }
      break;
    case BA_CLICKACTIVE:
      switch(b->style & BES_TYPEMASK) {
      case BES_CENTER:
        if(b->style & BXS_BORDER)
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_INACTIVEBORDER]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        else
        {
          BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
          BxRectangle(&b->m_BxDC, &b->rc);
        }
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
					BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &m_txtRect,  DT_TOP | DT_CENTER);
        break;
      default:
        BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXFRAME]);
        BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
        BxRectangle(&b->m_BxDC, &b->rc);
        if(b->style & BXS_DISABLED)
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_GRAYTEXT]);
        else
          BxSetTextColor(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BOXTEXT]);

        if(b->lpBoxStr!=NULL)
          BxDrawMultiLineText(&b->m_BxDC, b->lpBoxStr, strlen(b->lpBoxStr), &b->rc,  DT_TOP | DT_LEFT);
        break;
      }
      break;
    }
  }
  else
  {
    BxSetPen(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxSetBrush(&b->m_BxDC, BXSYSTEM_PALETTE[BXCOLOR_BACKGROUND]);
    BxRectangle(&b->m_BxDC, &b->rc);
  }
  BxUpdateOn();
  BxSetDirtyArea(&b->rc);
}
