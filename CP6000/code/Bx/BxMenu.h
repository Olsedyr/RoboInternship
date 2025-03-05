/***************************************************************************
                          BxMenu.h  -  description
                             -------------------
    begin                : Mon Aug 11 2003
    copyright            : (C) 2003 by lms
    email                : lms@localhost.localdomain
 ***************************************************************************/

#define MINMENUWIDTH 149
#define MINMENUHEIGHT 65
#define MENUICONWIDTH 32

#define MENU 0
#define SUB  1
#define SEPARATOR 2

typedef struct BXMENUSTRUCT
{
  HBOX Mnu;        // Menu dialog box
  BX_INT type;
  BX_BOOL(*mnufunc)(HBOX hBox);
} BXMENUSTRUCT;

HBOX BxMenu_Create( HBOX hBox, BXMENUSTRUCT *pBxMenu);
HBOX BxMenu_Add( HBOX hBox, BX_PSTRING pMnuTxt, BX_INT type, BX_BOOL(*connect)(HBOX hBox), BX_BOOL state, BxIcon *pIco);
BX_INT DoMenu(HBOX hBx);
BX_BOOL BxMenu_EndMenu(HBOX hBox, BX_INT nResult);
