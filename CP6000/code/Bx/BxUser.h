#ifndef BOXUSER
#define BOXUSER

#define DEFBOX 0
#define	DIALOG 1
#define	BUTTON 2
#define EDIT   3
#define STATIC 4
#define LIST   5
#define ANY    9999

/*
 * ShowBox() Commands
 */
#define SB_HIDE             0
#define SB_SHOWNORMAL       1
#define SB_NORMAL           1
#define SB_SHOWMINIMIZED    2
#define SB_SHOWMAXIMIZED    3
#define SB_MAXIMIZE         3
#define SB_SHOWNOACTIVATE   4
#define SB_SHOW             5
#define SB_MINIMIZE         6
#define SB_SHOWMINNOACTIVE  7
#define SB_SHOWNA           8
#define SB_RESTORE          9
#define SB_SHOWDEFAULT      10
#define SB_MAX              10

/*
 * Identifiers for the WM_SHOWBOX message
 */
#define SW_PARENTCLOSING    1
#define SW_OTHERZOOM        2
#define SW_PARENTOPENING    3
#define SW_OTHERUNZOOM      4

/*
 * Message structure
 */
typedef struct BX_MSG {
	HBOX              hbox;
	BX_UINT           message;
	BX_WPARAM         wParam;
	BX_LPARAM         lParam;
	BX_DWORD          time;
	BX_POINT          pt;
} BX_MSG, *BX_PMSG;

/*
#define POINTSTOPOINT(pt, pts)                          \
        { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts);   \
          (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }


#define POINTTOPOINTS(pt)      (MAKELONG((short)((pt).x), (short)((pt).y)))
*/
#define BX_MAKEWPARAM(l, h)      (BX_WPARAM)BX_MAKELONG(l, h)
#define BX_MAKELPARAM(l, h)      (BX_LPARAM)BX_MAKELONG(l, h)
#define BX_MAKELRESULT(l, h)     (BX_LRESULT)BX_MAKELONG(l, h)


/******************************************************************************
**
**  BoxSystem message
**
**********************************************************************************/

#define BM_NULL                         0x0000
#define BM_CREATE                       0x0001
#define BM_DESTROY                      0x0002

#define BM_ACTIVATE                     0x0006
/*
 * BM_ACTIVATE state values
 */
#define     BA_INACTIVE      0x10
#define     BA_ACTIVE        0x20
#define     BA_CLICKACTIVE   0x40



#define     BA_PUSHED				 0x80
#define     BA_RELEASED			0x100

#define BM_SETFOCUS                     0x0007
#define BM_KILLFOCUS                    0x0008
#define BM_ENABLE                       0x000A
#define BM_SETTEXT                      0x000C
#define BM_GETTEXT                      0x000D
#define BM_GETTEXTLENGTH                0x000E
#define BM_PAINT                        0x000F
#define BM_CLOSE                        0x0010

#define BM_QUIT                         0x0012


#define BM_UPDATE						0x0019
#define BM_SHOWBOX						0x0018

#define BM_SETCURSOR                    0x0020

#define BM_NCHITTEST                    0x0084
#define BM_NCPAINT                      0x0085
#define BM_NCACTIVATE                   0x0086

#define BM_KEYFIRST                     0x0100
#define BM_KEYDOWN                      0x0100
#define BM_KEYUP                        0x0101
#define BM_CHAR                         0x0102
#define BM_DEADCHAR                     0x0103
#define BM_SYSKEYDOWN                   0x0104
#define BM_SYSKEYUP                     0x0105
#define BM_SYSCHAR                      0x0106
#define BM_SYSDEADCHAR                  0x0107
#define BM_KEYLAST                      0x0108

#define BM_INITDIALOG                   0x0110
#define BM_COMMAND                      0x0111
#define BM_SYSCOMMAND                   0x0112
#define BM_TIMER                        0x0113
#define BM_HSCROLL                      0x0114
#define BM_VSCROLL                      0x0115
#define BM_INITMENU                     0x0116
#define BM_INITMENUPOPUP                0x0117
#define BM_MENUSELECT                   0x011F
#define BM_MENUCHAR                     0x0120
#define BM_ENTERIDLE                    0x0121

#define BM_CUT                          0x0300
#define BM_CLEAR                        0x0303

#define BM_TSFIRST						0x0400
#define BM_TSMOVE						0x0401
#define BM_TSDOWN						0x0402
#define BM_TSDBLCLK						0x0403
#define BM_TSUP							0x0404



#define BM_NCTSMOVE						0x0405
#define BM_NCTSDOWN						0x0406
#define BM_NCTSDBLCLK					0x0407
#define BM_NCTSUP						0x0408
#define BM_TSACTIVATE					0x0409
#define BM_TSLAST						0x040A

#define BM_MOUSEFIRST						0x0200
#define BM_MOUSEMOVE						0x0201
#define BM_LBUTTONDOWN					0x0202
#define BM_LBUTTONDBLCLK				0x0203
#define BM_LBUTTONUP						0x0204
#define BM_NCMOUSEMOVE					0x0205
#define BM_NCLBUTTONDOWN				0x0206
#define BM_NCLBUTTONDBLCLK			0x0207
#define BM_NCLBUTTONUP					0x0208
#define BM_MOUSEACTIVATE				0x0209
#define BM_MOUSELAST						0x020A


/*
 * Box Styles
 */
#define BXS_OVERLAPPED       0x00000000L
#define BXS_POPUP            0x80000000L
#define BXS_CHILD            0x40000000L
#define BXS_MINIMIZE         0x20000000L
#define BXS_VISIBLE          0x10000000L
#define BXS_DISABLED         0x08000000L
#define BXS_CLIPSIBLINGS     0x04000000L
#define BXS_CLIPCHILDREN     0x02000000L
#define BXS_MAXIMIZE         0x01000000L
#define BXS_CAPTION          0x00C00000L     /* BS_BORDER | BS_DLGFRAME  */
#define BXS_BORDER           0x00800000L
#define BXS_DLGFRAME         0x00400000L
#define BXS_VSCROLL          0x00200000L
#define BXS_HSCROLL          0x00100000L
#define BXS_CENTER           0x00100000L
#define BXS_SYSMENU          0x00080000L
#define BXS_THICKFRAME       0x00040000L
#define BXS_GROUP            0x00020000L
#define BXS_TABSTOP          0x00010000L

#define BXS_MINIMIZEBOX      0x00020000L
#define BXS_MAXIMIZEBOX      0x00010000L




#define BXS_TILED            BS_OVERLAPPED
#define BXS_ICONIC           BS_MINIMIZE
#define BXS_SIZEBOX          BS_THICKFRAME
#define BXS_TILEDWINDOW      BS_OVERLAPPEDWINDOW

/*
 * Common Box Styles
 */

#define BXS_OVERLAPPEDBOX (BXS_OVERLAPPED | BXS_CAPTION | BXS_SYSMENU | BXS_THICKFRAME)

#define BXS_POPUPBOX      (BXS_POPUP | BXS_BORDER | BXS_SYSMENU)

#define BXS_CHILDBOX      (BXS_CHILD)





/*
 * EditBox Control Styles
 */
#define BES_LEFT             0x0000L
#define BES_CENTER           0x0001L
#define BES_RIGHT            0x0002L
#define BES_MULTILINE        0x0004L
#define BES_UPPERCASE        0x0008L
#define BES_LOWERCASE        0x0010L
#define BES_PASSWORD         0x0020L
#define BES_AUTOVSCROLL      0x0040L
#define BES_AUTOHSCROLL      0x0080L
#define BES_NOHIDESEL        0x0100L
#define BES_OEMCONVERT       0x0400L
#define BES_READONLY         0x0800L
#define BES_WANTRETURN       0x1000L
#define BES_NUMBER           0x2000L
#define BES_TYPEMASK         0x3FFFL

/*
 * Edit Control Notification Codes
 */
#define BEN_SETFOCUS         0x0100
#define BEN_KILLFOCUS        0x0200
#define BEN_CHANGE           0x0300
#define BEN_UPDATE           0x0400
#define BEN_ERRSPACE         0x0500
#define BEN_MAXTEXT          0x0501
#define BEN_HSCROLL          0x0601
#define BEN_VSCROLL          0x0602

/* Edit control EM_SETMARGIN parameters */
#define BEC_LEFTMARGIN       0x0001
#define BEC_RIGHTMARGIN      0x0002
#define BEC_USEFONTINFO      0xffff

/*
 * Edit Control Messages
 */
#define BEM_GETSEL               0x00B0
#define BEM_SETSEL               0x00B1
#define BEM_GETRECT              0x00B2
#define BEM_SETRECT              0x00B3
#define BEM_SETRECTNP            0x00B4
#define BEM_SCROLL               0x00B5
#define BEM_LINESCROLL           0x00B6
#define BEM_SCROLLCARET          0x00B7
#define BEM_GETMODIFY            0x00B8
#define BEM_SETMODIFY            0x00B9
#define BEM_GETLINECOUNT         0x00BA
#define BEM_LINEINDEX            0x00BB
#define BEM_SETHANDLE            0x00BC
#define BEM_GETHANDLE            0x00BD
#define BEM_GETTHUMB             0x00BE
#define BEM_LINELENGTH           0x00C1
#define BEM_REPLACESEL           0x00C2
#define BEM_GETLINE              0x00C4
#define BEM_LIMITTEXT            0x00C5
#define BEM_CANUNDO              0x00C6
#define BEM_UNDO                 0x00C7
#define BEM_FMTLINES             0x00C8
#define BEM_LINEFROMCHAR         0x00C9
#define BEM_SETTABSTOPS          0x00CB

#define BEM_SETPASSWORDCHAR      0x00CC
#define BEM_EMPTYUNDOBUFFER      0x00CD
#define BEM_GETFIRSTVISIBLELINE  0x00CE
#define BEM_SETREADONLY          0x00CF
#define BEM_SETWORDBREAKPROC     0x00D0

#define BEM_GETWORDBREAKPROC     0x00D1
#define BEM_GETPASSWORDCHAR      0x00D2

#define BEM_SETMARGINS           0x00D3
#define BEM_GETMARGINS           0x00D4
#define BEM_SETLIMITTEXT         BEM_LIMITTEXT
#define BEM_GETLIMITTEXT         0x00D5
#define BEM_POSFROMCHAR          0x00D6
#define BEM_CHARFROMPOS          0x00D7

/*
 * EDITWORDBREAKPROC code values
 */
#define BWB_LEFT            0
#define BWB_RIGHT           1
#define BWB_ISDELIMITER     2


/*
 * Button Control Styles
 */
#define BBS_PUSHBUTTON       0x00000000L
#define BBS_DEFPUSHBUTTON    0x00000001L
#define BBS_CHECKBOX         0x00000002L
#define BBS_AUTOCHECKBOX     0x00000003L
#define BBS_RADIOBOX         0x00000004L
#define BBS_3STATE           0x00000005L
#define BBS_AUTO3STATE       0x00000006L
#define BBS_GROUPBOX         0x00000007L
#define BBS_USERBUTTON       0x00000008L
#define BBS_AUTORADIOBUTTON  0x00000009L
#define BBS_OWNERDRAW        0x0000000BL
#define BBS_LEFTTEXT         0x00000020L
#define BBS_TYPEMASK         0x0000003FL
#define BBS_STATEMASK        0x0000FFF0L

#define BBS_TEXT             0x00000000L
#define BBS_ICON             0x00000040L
#define BBS_BITMAP           0x00000080L
#define BBS_LEFT             0x00000100L
#define BBS_RIGHT            0x00000200L
#define BBS_CENTER           0x00000300L
#define BBS_TOP              0x00000400L
#define BBS_BOTTOM           0x00000800L
#define BBS_VCENTER          0x00000C00L
#define BBS_PUSHLIKE         0x00001000L
#define BBS_MULTILINE        0x00002000L
#define BBS_NOTIFY           0x00004000L
#define BBS_FLAT             0x00008000L
#define BBS_RIGHTBUTTON      BS_LEFTTEXT

 /*
 * User Button Notification Codes
 */
#define BN_CLICKED          0
#define BN_PAINT            1
#define BN_HILITE           2
#define BN_UNHILITE         3
#define BN_DISABLE          4
#define BN_DOUBLECLICKED    5

#define BN_PUSHED           BN_HILITE
#define BN_UNPUSHED         BN_UNHILITE
#define BN_DBLCLK           BN_DOUBLECLICKED
#define BN_SETFOCUS         6
#define BN_KILLFOCUS        7

/*
 * Button Control Messages
 */
#define BBM_GETCHECK        0x00F0
#define BBM_SETCHECK        0x00F1
#define BBM_GETSTATE        0x00F2
#define BBM_SETSTATE        0x00F3
#define BBM_SETSTYLE        0x00F4

#define BBM_CLICK           0x00F5
#define BBM_GETIMAGE        0x00F6
#define BBM_SETIMAGE        0x00F7
#define BBM_GETBITMAP       0x00F8
#define BBM_SETBITMAP       0x00F9
#define BBM_SETICON         0x00FA

#define BST_UNCHECKED      0x0000
#define BST_CHECKED        0x0001
#define BST_INDETERMINATE  0x0002
#define BST_PUSHED         0x0004
#define BST_FOCUS          0x0008


/*
 * Static Control Constants
 */
#define BSS_LEFT             0x00000000L
#define BSS_CENTER           0x00000001L
#define BSS_RIGHT            0x00000002L

#define BSS_ICON             0x00000003L
#define BSS_BLACKRECT        0x00000004L

#define BSS_GRAYRECT         0x00000005L
#define BSS_WHITERECT        0x00000006L
#define BSS_BLACKFRAME       0x00000007L
#define BSS_GRAYFRAME        0x00000008L
#define BSS_WHITEFRAME       0x00000009L
#define BSS_USERITEM         0x0000000AL
#define BSS_SIMPLE           0x0000000BL
#define BSS_LEFTNOWORDWRAP   0x0000000CL

#define BSS_OWNERDRAW        0x0000000DL
#define BSS_BITMAP           0x0000000EL

#define BSS_PROGRESSBAR      0x0000000FL
#define BSS_ETCHEDHORZ       0x00000010L

#define BSS_ETCHEDVERT       0x00000011L
#define BSS_ETCHEDFRAME      0x00000012L
#define BSS_TYPEMASK         0x0000001FL

#define BSS_NOPREFIX         0x00000080L /* Don't do "&" character translation */

#define BSS_NOTIFY           0x00000100L
#define BSS_CENTERIMAGE      0x00000200L
#define BSS_RIGHTJUST        0x00000400L
#define BSS_REALSIZEIMAGE    0x00000800L
#define BSS_SUNKEN           0x00001000L
#define BSS_ENDELLIPSIS      0x00004000L
#define BSS_PATHELLIPSIS     0x00008000L
#define BSS_WORDELLIPSIS     0x0000C000L
#define BSS_ELLIPSISMASK     0x0000C000L

/*
 * Static Control Mesages
 */
#define BSTM_SETICON         0x0170
#define BSTM_GETICON         0x0171

#define BSTM_SETIMAGE        0x0172
#define BSTM_GETIMAGE        0x0173
#define BSTN_CLICKED         0
#define BSTN_DBLCLK          1
#define BSTN_ENABLE          2
#define BSTN_DISABLE         3

#define BSTM_MSGMAX          0x0174





/*
 * Scroll Bar Constants
 */
#define BSB_HORZ             0
#define BSB_VERT             1
#define BSB_CTL              2
#define BSB_BOTH             3

/*
 * Scroll Bar Commands
 */
#define BSB_LINEUP           0
#define BSB_LINELEFT         0
#define BSB_LINEDOWN         1
#define BSB_LINERIGHT        1
#define BSB_PAGEUP           2
#define BSB_PAGELEFT         2
#define BSB_PAGEDOWN         3
#define BSB_PAGERIGHT        3
#define BSB_THUMBPOSITION    4
#define BSB_THUMBTRACK       5
#define BSB_TOP              6
#define BSB_LEFT             6
#define BSB_BOTTOM           7
#define BSB_RIGHT            7
#define BSB_ENDSCROLL        8


/*
 * Listbox messages
 */
#define BLB_ADDSTRING            0x0180
#define BLB_INSERTSTRING         0x0181

#define BLB_DELETESTRING         0x0182
#define BLB_SELITEMRANGEEX       0x0183
#define BLB_RESETCONTENT         0x0184
#define BLB_SETSEL               0x0185
#define BLB_SETCURSEL            0x0186
#define BLB_GETSEL               0x0187
#define BLB_GETCURSEL            0x0188
#define BLB_GETTEXT              0x0189
#define BLB_GETTEXTLEN           0x018A
#define BLB_GETCOUNT             0x018B
#define BLB_SELECTSTRING         0x018C
#define BLB_DIR                  0x018D
#define BLB_GETTOPINDEX          0x018E
#define BLB_FINDSTRING           0x018F
#define BLB_GETSELCOUNT          0x0190
#define BLB_GETSELITEMS          0x0191
#define BLB_SETTABSTOPS          0x0192
#define BLB_GETHORIZONTALEXTENT  0x0193
#define BLB_SETHORIZONTALEXTENT  0x0194
#define BLB_SETCOLUMNWIDTH       0x0195
#define BLB_ADDFILE              0x0196
#define BLB_SETTOPINDEX          0x0197
#define BLB_GETITEMRECT          0x0198
#define BLB_GETITEMDATA          0x0199
#define BLB_SETITEMDATA          0x019A
#define BLB_SELITEMRANGE         0x019B
#define BLB_SETANCHORINDEX       0x019C
#define BLB_GETANCHORINDEX       0x019D
#define BLB_SETCARETINDEX        0x019E
#define BLB_GETCARETINDEX        0x019F
#define BLB_SETITEMHEIGHT        0x01A0
#define BLB_GETITEMHEIGHT        0x01A1
#define BLB_FINDSTRINGEXACT      0x01A2
#define BLB_SETLOCALE            0x01A5
#define BLB_GETLOCALE            0x01A6
#define BLB_SETCOUNT             0x01A7
#define BLB_INITSTORAGE          0x01A8
#define BLB_ITEMFROMPOINT        0x01A9
#define BLB_MSGMAX               0x01B0

/*
 * Listbox Styles
 */
#define BLBS_NOTIFY              0x0001L
#define BLBS_SORT                0x0002L
#define BLBS_NOREDRAW            0x0004L
#define BLBS_MULTIPLESEL         0x0008L
#define BLBS_OWNERDRAWFIXED      0x0010L
#define BLBS_OWNERDRAWVARIABLE   0x0020L
#define BLBS_HASSTRINGS          0x0040L
#define BLBS_USETABSTOPS         0x0080L
#define BLBS_NOINTEGRALHEIGHT    0x0100L
#define BLBS_MULTICOLUMN         0x0200L
#define BLBS_WANTKEYBOARDINPUT   0x0400L
#define BLBS_EXTENDEDSEL         0x0800L
#define BLBS_DISABLENOSCROLL     0x1000L
#define BLBS_NODATA              0x2000L
#define BLBS_NOSEL               0x4000L
#define BLBS_ICON			     0x8000L


#define BLBS_STANDARD          (BLBS_NOTIFY | BLBS_SORT | BXS_VSCROLL | BXS_BORDER)

/*
 * Listbox Return Values
 */
#define LB_OKAY             0
#define LB_ERR              (-1)
#define LB_ERRSPACE         (-2)

typedef struct BX_CREATESTRUCTA {
//    BX_PVOID      lpCreateParams;
//    HAPP          hApp;
//    HBOX          hboxParent;
//    BX_INT         cy;
//    BX_INT         cx;
//    BX_INT         y;
//    BX_INT         x;
//    BX_LONG        style;
//    BX_PSTRING      lpszName;
//    BX_PSTRING      lpszClass;
//    BX_DWORD       dwExStyle;
	BX_RECT m_Rect;
	BX_PSTRING m_Text;
	BX_LONG m_Style;
	BX_LONG m_Type;
	BX_UINT m_BxID;
	struct BxBoxStruct* m_Parent;
} BX_CREATESTRUCT, *BX_PCREATESTRUCT;

#define DEFAULT_USER_LEVEL      0
#define USER_LEVEL_BROWSER      1
#define USER_LEVEL_OPERATOR     2
#define USER_LEVEL_MANAGER      3
#define USER_LEVEL_SERVICE      4
#define USER_LEVEL_PROGRAMMER   5

#define MIN_USER_LEVEL DEFAULT_USER_LEVEL
#define MAX_USER_LEVEL USER_LEVEL_PROGRAMMER

BX_INT BxSetUserLevel(BX_INT NewUserLevel);
BX_INT BxGetUserLevel(BX_VOID);

typedef struct tagBOX_STRUCT
{
  BX_WORD		ID;
  BX_RECT 		rc;
  BX_WORD		type;
  BX_PSTRING	lpBoxStr;
  BX_DWORD		style;
  struct tagBOX_STRUCT		*bNext;
  struct tagBOX_STRUCT		*bParent;
  BX_INT   userLevel;
  BXPROC		boxProc;
  BXDLGPROC		dlgProc;
  BX_INT		MsgResult;
  PINSTANCE hInstance;
  PCLASS	hCls;
  BX_WORD		boxState;
  BxDC m_BxDC;
  BX_BOOL m_Dirty;
  HBOX m_oldFocus;
  HBOX m_oldActive;
  HBOX m_oldDlg;
  BX_PVOID m_image;
  BX_PVOID m_userData;
	BX_PVOID m_menuData;
} BOXSTRUCT, *PBOXSTRUCT;

BX_LRESULT DefBoxProc(

	HBOX  hBox,	// handle of box
	BX_UINT  uMsg,	// message identifier
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
);


BX_LRESULT DefDlgBoxProc(

	HBOX  hBox,	// handle of box
	BX_UINT  uMsg,	// message identifier
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
);


HBOX 
	BxCreateDialog(
	PINSTANCE hInstance, 
	PBOXSTRUCT b, 
	BXDLGPROC __BoxProc
);


BX_BOOL
  BxGetDlgMessage(

	BX_PMSG  pMsg,	// address of structure with message

	HBOX  hbox,	// handle of box
	BX_UINT  uMsgFilterMin,	// first message
	BX_UINT  uMsgFilterMax 	// last message
);

BX_BOOL 

	BxGetMessage(

		BX_PMSG  lpmsg,	// address of structure with message
	HBOX  hwnd,	// handle of box
	BX_UINT  uMsgFilterMin,	// first message
	BX_UINT  uMsgFilterMax 	// last message
);

BX_BOOL 
	BxTranslateMessage( 
		CONST BX_MSG* lpMsg 
) ;


BX_LONG 
	BxDispatchMessage(

		CONST BX_MSG  *lpmsg 	// address of structure with message
);

BX_BOOL 
	BxPostMessage(


		HBOX  hbox,	// handle of destination box
	BX_UINT  uMsg,	// message to post 
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
);


BX_LRESULT 
	BxSendMessage(

		HBOX  hbox,	// handle of destination box
	BX_UINT  uMsg,	// message to send
	BX_WPARAM  wParam,	// first message parameter
	BX_LPARAM  lParam 	// second message parameter
);

/*
 * PeekMessage() Options
 */
#define PM_NOREMOVE         0x0000
#define PM_REMOVE           0x0001
#define PM_NOYIELD          0x0002

BX_BOOL 
	BxPeekMessage(

		BX_PMSG  lpmsg,	// address of structure with message
	HBOX  hwnd,	// handle of box
	BX_UINT  uMsgFilterMin,	// first message
	BX_UINT  uMsgFilterMax, 	// last message
	BX_UINT bRemoveMsg // Remove message
);



BX_BOOL 
	DestroyBox(

		HBOX  hbox 	// handle of box to destroy  
);

BX_BOOL
  BxShowBox(
    HBOX hBox,
    BX_INT nCmdShow);
    
BX_BOOL 
	CloseBox(

		HBOX  hbox 	// handle of box to minimize
);


BX_INT
  BxGetBoxID(
    HBOX hBox);

BX_BOOL
	BxEnableBox(
		HBOX hBox,
	BX_BOOL bEnable);

BX_BOOL
	IsBoxEnabled(
		HBOX hBox);

BX_BOOL
	BxSetBoxText(
		HBOX hBox,
	BX_PSTRING lpString);

BX_INT
	BxGetBoxText(
		HBOX hBox,
	BX_PSTRING lpString,
	BX_INT nMaxCount);

BX_INT
	BxGetBoxTextLength(
		HBOX hBox);


BX_BOOL DialogProc(

		HBOX  hboxDlg,
	BX_UINT  uMsg,	  
	BX_WPARAM  wParam,
	BX_LPARAM  lParam 
);

BX_INT DialogBox(

		PINSTANCE  hInstance,
	BX_UINT  lpTemplate,
	HBOX  hParent,
	BXDLGPROC  lpDialogFunc
);

BX_BOOL 
	BxEndDialog(
		HBOX hBox, 
	BX_INT nResult
);

#define MB_STANDARDBEEP 1


BX_BOOL
	MessageBeep(
		BX_UINT uType);

BX_INT 
	BoxMessage( 
		HBOX hBox, 
	BX_PSTRING lpText, 
	BX_PSTRING lpCaption, 
	BX_UINT uType
);

BX_BOOL 
	IsChild(
		HBOX hBoxParent, 
	HBOX hBox
);

BX_BOOL 
	IsVisible(
		HBOX pBx
);

BX_BOOL 
	IsDisabled(
		HBOX pBx
);

HBOX 
	BxSetFocus( 
		HBOX hBox
);

HBOX 
	BxGetFocus( 
		BX_VOID
);

BX_VOID 
	BxGetBoxRect(
		HBOX hBx, 
	BX_PRECT pRc
);

HBOX 
	BxGetParent(
		HBOX hBx
);

#define MAX_BOX_MSG  100

BOXSTRUCT *GetBoxStruct(BX_UINT Index);
HBOX 
	BxCreateBox(
		PINSTANCE hInstance, 
	BOXSTRUCT *b,
	BXPROC __BoxProc
);

typedef struct tagINSTANSE
{
	HBOX		mainhBox;
	BX_BOOL	endDialog;
	BX_INT		msgInQueue;
	BX_MSG		InstanceMsg[MAX_BOX_MSG];
	BX_BOOL m_PaintFlag;
} INSTANCESTRUCT, *PINSTANCESTRUCT;


typedef struct tagCLASSDEF 
{															 			/* BM_QUIT */
	BX_VOID (*Cls_OnQuit)(HBOX hbox, BX_INT exitCode);
	BX_BOOL (*Cls_OnCreate)(HBOX hbox);
	BX_BOOL (*Cls_OnShowBox)(HBOX hbox, BX_BOOL fShow, BX_INT status);
	BX_VOID (*Cls_OnDestroy)(HBOX hbox);
	BX_VOID (*Cls_OnEnable)(HBOX hbox, BX_BOOL fEnable);
	BX_VOID (*Cls_OnSetText)(HBOX hbox, BX_PSTRING lpszText);
	BX_INT  (*Cls_OnGetText)(HBOX hbox, BX_INT cchTextMax, BX_PSTRING lpszText);
	BX_INT  (*Cls_OnGetTextLength)(HBOX hbox);
	BX_VOID (*Cls_OnClose)(HBOX hbox);
	BX_VOID (*Cls_OnPaint)(HBOX hbox);
	BX_VOID (*Cls_OnNCPaint)(HBOX hbox, PRGN hrgn);
	BX_UINT (*Cls_OnNCHitTest)(HBOX hbox, BX_INT x, BX_INT y);
	BX_VOID (*Cls_OnActivate)(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized);

	BX_VOID (*Cls_OnSetFocus)(HBOX hbox, HBOX hboxOldFocus); /* BM_SETFOCUS */
	BX_VOID (*Cls_OnKillFocus)(HBOX hbox, HBOX hboxNewFocus); /* BM_KILLFOCUS */
	BX_VOID (*Cls_OnKeyDown)(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags); /*BM_KEYDOWN*/
	BX_VOID (*Cls_OnKeyUp)(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags); /*BM_KEYUP*/
	BX_VOID (*Cls_OnChar)(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
	BX_VOID (*Cls_OnDeadChar)(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);  /* After BM_KEYUP for umlaut ex. */
	BX_VOID (*Cls_OnSysKeyDown)(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags); /* BM_SYSKEYDOWN */
	BX_VOID (*Cls_OnSysKeyUp)(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags); /* BM_SYSKEYUP */
	BX_VOID (*Cls_OnSysChar)(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
	BX_VOID (*Cls_OnSysDeadChar)(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);  /* After BM_SYSKEYUP for umlaut ex. */


	BX_VOID (*Cls_OnMouseMove)(HBOX hbox, BX_INT x, BX_INT y);
	BX_VOID (*Cls_OnLButtonDown)(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
	BX_VOID (*Cls_OnLButtonUp)(HBOX hbox, BX_INT x, BX_INT y);

	BX_VOID (*Cls_OnNCMouseMove)(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest);
	BX_VOID (*Cls_OnNCLButtonDown)(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y, BX_UINT codeHitTest);
	BX_VOID (*Cls_OnNCLButtonUp)(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest);
	BX_INT  (*Cls_OnMouseActivate)(HBOX hbox, HBOX hboxTopLevel, BX_UINT codeHitTest, BX_UINT msg);

	BX_VOID (*Cls_OnCut)(HBOX hbox);
	BX_VOID (*Cls_OnClear)(HBOX hbox);

	BX_BOOL (*Cls_OnSetCursor)(HBOX hbox, HBOX hboxCursor, BX_UINT codeHitTest, BX_UINT msg);

	BX_VOID (*Cls_OnSysCommand)(HBOX hbox, BX_UINT cmd, BX_INT x, BX_INT y);

} CLASSDEF;

extern CLASSDEF BOX_CLASS;
extern PCLASS	hCls_DefBox;
extern PCLASS	hCls_Button;
extern PCLASS	hCls_CheckBox;
extern PCLASS	hCls_Edit;
extern PCLASS	hCls_Static;

/*
 * Dialog Box Command IDs
 */
#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7

/*  System ID */
#define BXID_STATIC         0xffff

#define MB_STANDARDBEEP 1

BX_BOOL	BxMessageBeep(BX_UINT uType);

#define DT_TOP              0x00000000
#define DT_LEFT             0x00000000

#define DT_CENTER           0x00000001
#define DT_RIGHT            0x00000002
#define DT_VCENTER          0x00000004
#define DT_BOTTOM           0x00000008
#define DT_WORDBREAK        0x00000010
#define DT_SINGLELINE       0x00000020
#define DT_EXPANDTABS       0x00000040
#define DT_TABSTOP          0x00000080
#define DT_NOCLIP           0x00000100
#define DT_EXTERNALLEADING  0x00000200
#define DT_CALCRECT         0x00000400
#define DT_NOPREFIX         0x00000800
#define DT_INTERNAL         0x00001000

/*
 * Color Types
 */
#define BXCTLCOLOR_MSGBOX         0
#define BXCTLCOLOR_EDIT           1
#define BXCTLCOLOR_LISTBOX        2

#define BXCTLCOLOR_BTN            3
#define BXCTLCOLOR_DLG            4
#define BXCTLCOLOR_SCROLLBAR      5
#define BXCTLCOLOR_STATIC         6
#define BXCTLCOLOR_MAX            7

#define BXCOLOR_SCROLLBAR         0
#define BXCOLOR_BACKGROUND        1

#define BXCOLOR_ACTIVECAPTION     2
#define BXCOLOR_INACTIVECAPTION   3
#define BXCOLOR_MENU              4
#define BXCOLOR_BOX               5
#define BXCOLOR_BOXFRAME          6
#define BXCOLOR_MENUTEXT          7
#define BXCOLOR_BOXTEXT           8
#define BXCOLOR_CAPTIONTEXT       9
#define BXCOLOR_ACTIVEBORDER      10
#define BXCOLOR_INACTIVEBORDER    11
#define BXCOLOR_APPWORKSPACE      12
#define BXCOLOR_HIGHLIGHT         13

#define BXCOLOR_HIGHLIGHTTEXT     14
#define BXCOLOR_BTNFACE           15
#define BXCOLOR_BTNSHADOW         16
#define BXCOLOR_GRAYTEXT          17
#define BXCOLOR_BTNTEXT           18
#define BXCOLOR_INACTIVECAPTIONTEXT 19
#define BXCOLOR_BTNHIGHLIGHT      20
#define BXCOLOR_POPUPBOX		      21
#define BXCOLOR_MENUBOX		      22


extern BX_VOID BxRequestPaint(	HBOX hBx );

#ifdef DEFREVISION
char idBXUSER_H[]="$Header: /home/cvsroot/sandbox/Bx/BxUser.h,v 1.11 2006/12/19 12:05:56 mil Exp $";
#endif

#endif //BOXUSER
