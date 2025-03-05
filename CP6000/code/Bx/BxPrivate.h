#include "Bx.h"
#include "BxBoxSx.h"
#include "BxSysBoxList.h"

extern HBOX  BXFOCUSBOX;
extern HBOX  BXACTIVEBOX;
extern HBOX  BXACTIVEDLGBOX;



#define BXC_CAPTIONHEIGHT   20

BX_VOID ShowCursor(BX_BOOL bShow);

BxGfxDrv* BxGetGfxDriver();
extern BxFont* DefaultFont;
extern BxFont* DefaultSmallFont;
extern BxFont* DefaultButtonFont;
extern BX_INT BX_DEFSTRLEN;

extern void BxUpdateOn(void);
extern void BxUpdateOff(void);

BX_BOOL IsEndDialog(HBOX hBox);
BX_VOID RequestRectPaint(HBOX hBx, BX_PRECT pRc);

BX_LRESULT DefPushButtonProc( HBOX hBox, BX_UINT uMsg,
                                 BX_WPARAM wParam, BX_LPARAM lParam );
BX_LRESULT DefEditProc( HBOX hBox, BX_UINT uMsg,
                                 BX_WPARAM wParam, BX_LPARAM lParam );
BX_LRESULT DefStaticProc( HBOX hBox, BX_UINT uMsg,
                                 BX_WPARAM wParam, BX_LPARAM lParam );
BX_VOID BxUpdateView(HBOX hBx);

BX_RECT BxSetClipRect(BX_RECT *clip);
