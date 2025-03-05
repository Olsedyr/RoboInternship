#ifndef BX
#define BX

#include "BxGlue.h" // system afhængig

#define LOGOUTLEVEL         0
#define BROWSERLEVEL        1
#define OPERATORLEVEL       2
#define SERVICELEVEL        3
#define MANAGERLEVEL        4
#define PROGRAMMERLEVEL     5
#define MAXLEVEL            6

#define MAXLANGUAGE 5

#ifdef CreateFont
#undef CreateFont
#endif

#ifdef SendMessage
#undef SendMessage
#endif

#include "BxTypes.h"
//#include "BxFile.h"
#include "font.h"
#include "BxVKeys.h"
//#include "BxPoint.h"
//#include "BxString.h"
#include "BxFont.h"
#include "BxGdi.h"
#include "BxDrivers.h"
#include "BxDC.h"
#include "BxUser.h"

//extern BxFont* DefaultButtonFont;
BxFont* DefaultSmallFont;
extern BX_INT BX_LANGUAGE;

///////////////////////////////////////////////////////////////////
// Box return values

#define BX_STATUS_OK                  0
#define BX_DRIVER_STARTUP_FAILED      1
#define BX_DRIVER_LIST_FAILED         2
#define BX_ERR_INVALID_ADDRESS        3
#define BX_ERR_RESOURCEMAN			      4

#define GB_BOXNEXT 0
#define GB_BOXPREV 1

//#include "BxBoxApp.h"
//#include "BxGfxDrv.h"
#include "BxBitmap.h"
#include "BxIcon.h"
#include "BxBox.h"
//#include "BxLabel.h"
//#include "BxButton.h"
//#include "BxEdit.h"
//#include "BxCheckBox.h"
//#include "BxOKBox.h"
//#include "BxRadio.h"

//#include "BxDialog.h"
#define MSGBOX_ID   0x9999
//#include "BxMsgBox.h"
//#include "BxWizardDlg.h"
#include "BxPBar.h"
#include "BxScrollBar.h"
#include "BxList.h"
#include "BxLayout.h"
#include "BxFileDialog.h"
#include "BxMenu.h"
#include "BxValue.h"
#include "BxResource.h"
#include "BxTranslator.h"

///////////////////////////////////////////////////////////////////
// BoxSystem API



extern BX_BOOL BxUpdateFlag;
extern BX_VOID BxUpdate(BX_VOID);
extern BX_VOID BxWaitEvent(BX_VOID);
extern BX_VOID BxSetEvent(BX_VOID);
extern BX_VOID DlgAppInit(BX_VOID);
//BX_INT BxMessageBox(BxBox* pBx, BX_PSTRING pMessage, BX_PSTRING pCaption, BX_UINT Style);
HBOX BxSetActiveDlgBox(HBOX hBx);
HBOX BxGetActiveDlgBox(void);
HBOX SetActiveBox(HBOX hBx, BX_BOOL clicked);
BX_LRESULT BxInitSystem(BX_VOID);
BX_LRESULT BxCloseSystem(BX_VOID);

#define BxDisableInt() 0
#define BxEnableInt(flags) 0


BX_BOOL BxRegistrateBox(BxBox* pBox);
BX_BOOL BxUnRegistrateBox(BxBox* pBox);

//BX_BOOL BxFindBox(BxBox* pBox);
PBOXSTRUCT BxGetNextBox(PBOXSTRUCT pBox, BX_UINT Flag);
//BxBox* BxGetChild(BxBox* pBox, BxBox* pChild, BX_UINT Type);
HBOX BxFindDirtyChild(HBOX pBox);
BX_BOOL BxGetCheck(HBOX hBx);
BX_VOID BxSetCheck(HBOX hBx, BX_BOOL check);

BX_VOID ShowDialogBox(HBOX hBox);
BX_VOID HideDialogBox(HBOX hBox);
HBOX BxGetDlgItem(HBOX hBx, BX_INT Id);
PINSTANCE GetAppInstance(HBOX hBx);
BX_INT DoModal(HBOX hBx);
BX_INT BxMsgBox( HBOX hBox, BX_PSTRING lpText, BX_PSTRING lpCaption, BX_UINT uType , BX_PSTRING OkStr, BX_PSTRING CancelStr);

// Til indtastning af heltal og float
BX_INT VirtNumKeyBox( HBOX hBox);
BX_VOID BxVirtNumBox_SetFloatValue(BX_DOUBLE val);
BX_DOUBLE BxVirtNumBox_GetFloatValue(BX_VOID);
BX_VOID BxVirtNumBox_SetFloatLimits(BX_DOUBLE min, BX_DOUBLE max);
BX_VOID BxVirtNumBox_SetValue(BX_S64 val);
BX_S64 BxVirtNumBox_GetValue(BX_VOID);
BX_VOID BxVirtNumBox_SetLimits(BX_S64 min, BX_S64 max);

// Til indtastning af strenge
BX_VOID BxVirtualKeyboard_LoginMode(BX_VOID);
BX_INT BxVirtualKeyboard( HBOX hBox, BX_PSTRING initStr, BX_INT len);
BX_PSTRING BxVirtualKeyboard_GetString(BX_VOID);

BX_VOID BxSleep(BX_DWORD ms);
//BxBox* BxGetChildFromID(BxBox* pBox, BX_INT ID);

//BxBitmap* BxLoadBitmap(BX_UINT ID);
//BxIcon* BxLoadIcon(BX_UINT ID);
//BX_WORD ProcessUsages();
//extern "C" BX_VOID ReportBxFatalError(BX_INT (*handleReport)());

#endif // BX
