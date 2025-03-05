
typedef struct BxBoxMetodeStruct {
	BX_LRESULT (*BoxProc)(BX_UINT Msg, BX_WPARAM wParam, BX_LPARAM lParam);
	BX_VOID (*Update)(BX_VOID);
} BxBoxMetodeStruct;

typedef struct BxBoxStruct {
	BX_PCREATESTRUCT m_BxInfo;
//	BxDC* m_BxDC;
	PINSTANCE m_hApp;
	BX_BOOL m_Dirty;
	BX_UINT m_State;
// Metoder
	BxBoxMetodeStruct *m_BxFunc;
} BxBox;

extern BX_VOID Box_OnQuit(HBOX hbox, BX_INT exitCode);
extern BX_BOOL Box_OnCreate(HBOX hbox);
extern BX_BOOL Box_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_INT Status);
extern BX_VOID Box_OnDestroy(HBOX hbox);
extern BX_VOID Box_OnEnable(HBOX hbox, BX_BOOL fEnable);
extern BX_VOID Box_OnSetText(HBOX hbox, BX_PSTRING lpszText);
extern BX_INT  Box_OnGetText(HBOX hbox, BX_INT cchTextMax, BX_PSTRING lpszText);
extern BX_INT  Box_OnGetTextLength(HBOX hbox);
extern BX_VOID Box_OnClose(HBOX hbox);
extern BX_VOID Box_OnPaint(HBOX hbox);
extern BX_VOID Box_OnNCPaint(HBOX hbox, PRGN hrgn);
extern BX_UINT Box_OnNCHitTest(HBOX hbox, BX_INT x, BX_INT y);
extern BX_VOID Box_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized);

extern BX_VOID Box_OnSetFocus(HBOX hbox, HBOX hboxOldFocus);
extern BX_VOID Box_OnKillFocus(HBOX hbox, HBOX hboxNewFocus);
extern BX_VOID Box_OnKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);
extern BX_VOID Box_OnKeyUp(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);
extern BX_VOID Box_OnChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
extern BX_VOID Box_OnDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
extern BX_VOID Box_OnSysKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);
extern BX_VOID Box_OnSysKeyUp(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);
extern BX_VOID Box_OnSysChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
extern BX_VOID Box_OnSysDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat);
extern BX_VOID Box_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y);
extern BX_VOID Box_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
extern BX_VOID Box_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y);

extern BX_VOID Box_OnNCMouseMove(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest);
extern BX_VOID Box_OnNCLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y, BX_UINT codeHitTest);
extern BX_VOID Box_OnNCLButtonUp(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest);
extern BX_INT  Box_OnMouseActivate(HBOX hbox, HBOX hboxTopLevel, BX_UINT codeHitTest, BX_UINT msg);
extern BX_VOID Box_OnCut(HBOX hbox);
extern BX_VOID Box_OnClear(HBOX hbox);

extern BX_BOOL Box_OnSetCursor(HBOX hbox, HBOX hboxCursor, BX_UINT codeHitTest, BX_UINT msg);
extern BX_VOID Box_OnSysCommand(HBOX hbox, BX_UINT cmd, BX_INT x, BX_INT y);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
extern BX_BOOL Button_OnCreate(HBOX hbox);
extern BX_BOOL Button_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_INT Status);
extern BX_VOID Button_OnEnable(HBOX hbox, BX_BOOL fEnable);
extern BX_VOID Button_OnSetText(HBOX hbox, BX_PSTRING lpszText);
extern BX_VOID Button_OnPaint(HBOX hbox);
extern BX_VOID Button_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized);
extern BX_VOID Button_OnKeyDown(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags);

extern BX_VOID Button_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y);
extern BX_VOID Button_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
BX_VOID Static_OnEnable(HBOX hbox, BX_BOOL fEnable);
BX_VOID Static_OnPaint(HBOX hbox);

