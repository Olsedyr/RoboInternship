#ifndef _BOXSX_
#define _BOXSX_

/****** Message crackers ****************************************************/

#define HANDLE_MSG(hbox, message, fn)    \
    case (message): return HANDLE_##message((hbox), (wParam), (lParam), (fn))

/* BX_VOID Cls_OnQuit(HBOX hbox, BX_INT exitCode) */
#define HANDLE_BM_QUIT(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_INT)(wParam)), 0L)

/* BX_BOOL Cls_OnCreate(HBOX hbox, LPCREATESTRUCT lpCreateStruct) */
#define HANDLE_BM_CREATE(hbox, wParam, lParam, fn) \
    ((fn)((hbox)))

/* BX_VOID Cls_OnShowBox(HBOX hbox, BX_BOOL fShow, BX_UINT status) */
#define HANDLE_BM_SHOWBOX(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_BOOL)(wParam), (BX_UINT)(lParam)), 0L)

/* BX_VOID Cls_OnDestroy(HBOX hbox) */
#define HANDLE_BM_DESTROY(hbox, wParam, lParam, fn) \
    ((fn)(hbox), 0L)

/* BX_VOID Cls_OnEnable(HBOX hbox, BX_BOOL fEnable) */
#define HANDLE_BM_ENABLE(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_BOOL)(wParam)), 0L)

/* BX_VOID Cls_OnSetText(HBOX hbox, BX_PSTRING lpszText) */
#define HANDLE_BM_SETTEXT(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_PSTRING)(lParam)), 0L)

/* INT Cls_OnGetText(HBOX hbox, BX_INT cchTextMax, BX_PSTRING lpszText) */
#define HANDLE_BM_GETTEXT(hbox, wParam, lParam, fn) \
    (BX_LRESULT)(BX_DWORD)(BX_INT)(fn)((hbox), (BX_INT)(wParam), (BX_PSTRING)(lParam))

/* INT Cls_OnGetTextLength(HBOX hbox) */
#define HANDLE_BM_GETTEXTLENGTH(hbox, wParam, lParam, fn) \
    (BX_LRESULT)(BX_DWORD)(BX_INT)(fn)(hbox)

/* BX_VOID Cls_OnClose(HBOX hbox) */
#define HANDLE_BM_CLOSE(hbox, wParam, lParam, fn) \
    ((fn)(hbox), 0L)

/* BX_VOID Cls_OnPaint(HBOX hbox) */
#define HANDLE_BM_PAINT(hbox, wParam, lParam, fn) \
    ((fn)(hbox), 0L)

/* BX_VOID Cls_OnNCPaint(HBOX hbox, HRGN hrgn) */
#define HANDLE_BM_NCPAINT(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (PRGN)(wParam)), 0L)


/* BX_UINT Cls_OnNCHitTest(HBOX hbox, BX_INT x, BX_INT y) */
#define HANDLE_BM_NCHITTEST(hbox, wParam, lParam, fn) \
    (BX_LRESULT)(BX_DWORD)(BX_UINT)(fn)((hbox), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam))

/* BX_VOID Cls_OnActivate(HBOX hbox, BX_UINT state, HBOX hboxActDeact, BX_BOOL fMinimized) */
#define HANDLE_BM_ACTIVATE(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)BX_LOWORD(wParam), (HBOX)(lParam), (BX_BOOL)BX_HIWORD(wParam)), 0L)

/* BX_VOID Cls_OnSetFocus(HBOX hbox, HBOX hboxOldFocus) */
#define HANDLE_BM_SETFOCUS(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (HBOX)(wParam)), 0L)

/* BX_VOID Cls_OnKillFocus(HBOX hbox, HBOX hboxNewFocus) */
#define HANDLE_BM_KILLFOCUS(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (HBOX)(wParam)), 0L)

/* BX_VOID Cls_OnKey(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags) */
#define HANDLE_BM_KEYDOWN(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)(wParam), TRUE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnKey(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags) */
#define HANDLE_BM_KEYUP(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)(wParam), FALSE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat) */
#define HANDLE_BM_CHAR(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_CHAR)(wParam), (BX_INT)(BX_SHORT)BX_LOWORD(lParam)), 0L)

/* BX_VOID Cls_OnDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat) */
#define HANDLE_BM_DEADCHAR(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_CHAR)(wParam), (BX_INT)(BX_SHORT)BX_LOWORD(lParam)), 0L)

/* BX_VOID Cls_OnSysKey(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags) */
#define HANDLE_BM_SYSKEYDOWN(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)(wParam), TRUE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnSysKey(HBOX hbox, BX_UINT vk, BX_BOOL fDown, BX_INT cRepeat, BX_UINT flags) */
#define HANDLE_BM_SYSKEYUP(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)(wParam), FALSE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnSysChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat) */
#define HANDLE_BM_SYSCHAR(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_CHAR)(wParam), (BX_INT)(BX_SHORT)BX_LOWORD(lParam)), 0L)

/* BX_VOID Cls_OnSysDeadChar(HBOX hbox, BX_CHAR ch, BX_INT cRepeat) */
#define HANDLE_BM_SYSDEADCHAR(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_CHAR)(wParam), (BX_INT)(BX_SHORT)BX_LOWORD(lParam)), 0L)

/* BX_VOID Cls_OnMouseMove(HBOX hbox, BX_INT x, BX_INT y) */
#define HANDLE_BM_MOUSEMOVE(hbox, wParam, lParam, fn) \
    ((BX_VOID)(fn)((hbox), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y) */
#define HANDLE_BM_LBUTTONDOWN(hbox, wParam, lParam, fn) \
    ((BX_VOID)(fn)((hbox), FALSE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnLButtonDblClk(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y) */
#define HANDLE_BM_LBUTTONDBLCLK(hbox, wParam, lParam, fn) \
    ((BX_VOID)(fn)((hbox), TRUE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam)))

/* BX_VOID Cls_OnLButtonUp(HBOX hbox, BX_INT x, BX_INT y) */
#define HANDLE_BM_LBUTTONUP(hbox, wParam, lParam, fn) \
    ((BX_VOID)(fn)((hbox), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam)), 0L)

/* BX_VOID Cls_OnNCMouseMove(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest) */
#define HANDLE_BM_NCMOUSEMOVE(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam), (BX_UINT)(wParam)), 0L)

/* BX_VOID Cls_OnNCLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y, BX_UINT codeHitTest) */
#define HANDLE_BM_NCLBUTTONDOWN(hbox, wParam, lParam, fn) \
    ((fn)((hbox), FALSE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam), (BX_UINT)(wParam)), 0L)

/* BX_VOID Cls_OnNCLButtonDown(HBOX hbox, BX_BOOL fDoubleClick, BX_INT x, BX_INT y, BX_UINT codeHitTest) */
#define HANDLE_BM_NCLBUTTONDBLCLK(hbox, wParam, lParam, fn) \
    ((fn)((hbox), TRUE, (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam), (BX_UINT)(wParam)), 0L)

/* BX_VOID Cls_OnNCLButtonUp(HBOX hbox, BX_INT x, BX_INT y, BX_UINT codeHitTest) */
#define HANDLE_BM_NCLBUTTONUP(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam), (BX_UINT)(wParam)), 0L)

/* BX_INT Cls_OnMouseActivate(HBOX hbox, HBOX hboxTopLevel, BX_UINT codeHitTest, BX_UINT msg) */
#define HANDLE_BM_MOUSEACTIVATE(hbox, wParam, lParam, fn) \
    (BX_LRESULT)(BX_DWORD)(BX_INT)(fn)((hbox), (HBOX)(wParam), (BX_UINT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam))

/* BX_VOID Cls_OnCut(HBOX hbox) */
#define HANDLE_BM_CUT(hbox, wParam, lParam, fn) \
    ((fn)(hbox), 0L)

/* BX_VOID Cls_OnClear(HBOX hbox) */
#define HANDLE_BM_CLEAR(hbox, wParam, lParam, fn) \
    ((fn)(hbox), 0L)

/* BX_BOOL Cls_OnSetCursor(HBOX hbox, HBOX hboxCursor, BX_UINT codeHitTest, BX_UINT msg) */
#define HANDLE_BM_SETCURSOR(hbox, wParam, lParam, fn) \
    (BX_LRESULT)(BX_DWORD)(BX_BOOL)(fn)((hbox), (HBOX)(wParam), (BX_UINT)BX_LOWORD(lParam), (BX_UINT)BX_HIWORD(lParam))

/* BX_VOID Cls_OnSysCommand(HBOX hbox, BX_UINT cmd, BX_INT x, BX_INT y) */
#define HANDLE_BM_SYSCOMMAND(hbox, wParam, lParam, fn) \
    ((fn)((hbox), (BX_UINT)(wParam), (BX_INT)(BX_SHORT)BX_LOWORD(lParam), (BX_INT)(BX_SHORT)BX_HIWORD(lParam)), 0L)

/****** Static control message APIs ******************************************/

#define Static_Enable(hboxCtl, fEnable)         EnableBox((hboxCtl), (fEnable))

#define Static_GetText(hboxCtl, lpch, cchMax)   GetBoxText((hboxCtl), (lpch), (cchMax))
#define Static_GetTextLength(hboxCtl)           GetBoxTextLength(hboxCtl)
#define Static_SetText(hboxCtl, lpsz)           SetBoxText((hboxCtl), (lpsz))

#define Static_SetIcon(hboxCtl, hIcon)          ((PBX_ICON)(BX_LRESULT)(BX_DWORD)BxSendMessage((hboxCtl), BSTM_SETICON, (BX_WPARAM)(PBX_ICON)(hIcon), 0L))
#define Static_GetIcon(hboxCtl, hIcon)          ((PBX_ICON)(BX_LRESULT)(BX_DWORD)BxSendMessage((hboxCtl), BSTM_GETICON, 0L, 0L))

/****** Button control message APIs ******************************************/

#define Button_Enable(hboxCtl, fEnable)         EnableBox((hboxCtl), (fEnable))

#define Button_GetText(hboxCtl, lpch, cchMax)   GetBoxText((hboxCtl), (lpch), (cchMax))
#define Button_GetTextLength(hboxCtl)           GetBoxTextLength(hboxCtl)
#define Button_SetText(hboxCtl, lpsz)           SetBoxText((hboxCtl), (lpsz))

#define Button_GetCheck(hboxCtl)            ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BBM_GETCHECK, 0L, 0L))
#define Button_SetCheck(hboxCtl, check)     ((BX_VOID)BxSendMessage((hboxCtl), BBM_SETCHECK, (BX_WPARAM)(BX_INT)(check), 0L))

#define Button_GetState(hboxCtl)            ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BBM_GETSTATE, 0L, 0L))
#define Button_SetState(hboxCtl, state)     ((BX_UINT)(BX_DWORD)BxSendMessage((hboxCtl), BBM_SETSTATE, (BX_WPARAM)(BX_INT)(state), 0L))

#define Button_SetStyle(hboxCtl, style, fRedraw) ((BX_VOID)BxSendMessage((hboxCtl), BBM_SETSTYLE, (BX_WPARAM)BX_LOWORD(style), MAKELPARAM(((fRedraw) ? TRUE : FALSE), 0)))

/****** Edit control message APIs ********************************************/

#define Edit_Enable(hboxCtl, fEnable)           EnableBox((hboxCtl), (fEnable))

#define Edit_GetText(hboxCtl, lpch, cchMax)     GetBoxText((hboxCtl), (lpch), (cchMax))
#define Edit_GetTextLength(hboxCtl)             GetBoxTextLength(hboxCtl)
#define Edit_SetText(hboxCtl, lpsz)             SetBoxText((hboxCtl), (lpsz))

#define Edit_LimitText(hboxCtl, cchMax)         ((BX_VOID)BxSendMessage((hboxCtl), BEM_LIMITTEXT, (BX_WPARAM)(cchMax), 0L))

#define Edit_GetLineCount(hboxCtl)              ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_GETLINECOUNT, 0L, 0L))
#define Edit_GetLine(hboxCtl, line, lpch, cchMax) ((*((BX_INT *)(lpch)) = (cchMax)), ((BX_INT)(BX_DWORD)SendMessage((hboxCtl), BEM_GETLINE, (BX_WPARAM)(BX_INT)(line), (BX_LPARAM)(BX_PSTRING)(lpch))))

#define Edit_GetRect(hboxCtl, lprc)             ((BX_VOID)BxSendMessage((hboxCtl), BEM_GETRECT, 0L, (BX_LPARAM)(RECT *)(lprc)))
#define Edit_SetRect(hboxCtl, lprc)             ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETRECT, 0L, (BX_LPARAM)(const RECT *)(lprc)))
#define Edit_SetRectNoPaint(hboxCtl, lprc)      ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETRECTNP, 0L, (BX_LPARAM)(const RECT *)(lprc)))

#define Edit_GetSel(hboxCtl)                    ((BX_DWORD)BxSendMessage((hboxCtl), BEM_GETSEL, 0L, 0L))
#define Edit_SetSel(hboxCtl, ichStart, ichEnd)  ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETSEL, (ichStart), (ichEnd)))
#define Edit_ReplaceSel(hboxCtl, lpszReplace)   ((BX_VOID)BxSendMessage((hboxCtl), BEM_REPLACESEL, 0L, (BX_LPARAM)(BX_PSTRING)(lpszReplace)))

#define Edit_GetModify(hboxCtl)                 ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_GETMODIFY, 0L, 0L))
#define Edit_SetModify(hboxCtl, fModified)      ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETMODIFY, (BX_WPARAM)(BX_UINT)(fModified), 0L))

#define Edit_ScrollCaret(hboxCtl)               ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_SCROLLCARET, 0, 0L))

#define Edit_LineFromChar(hboxCtl, ich)         ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_LINEFROMCHAR, (BX_WPARAM)(BX_INT)(ich), 0L))
#define Edit_LineIndex(hboxCtl, line)           ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_LINEINDEX, (BX_WPARAM)(BX_INT)(line), 0L))
#define Edit_LineLength(hboxCtl, line)          ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_LINELENGTH, (BX_WPARAM)(BX_INT)(line), 0L))

#define Edit_Scroll(hboxCtl, dv, dh)            ((BX_VOID)BxSendMessage((hboxCtl), BEM_LINESCROLL, (BX_WPARAM)(dh), (BX_LPARAM)(dv)))

#define Edit_CanUndo(hboxCtl)                   ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_CANUNDO, 0L, 0L))
#define Edit_Undo(hboxCtl)                      ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_UNDO, 0L, 0L))
#define Edit_EmptyUndoBuffer(hboxCtl)           ((BX_VOID)BxSendMessage((hboxCtl), BEM_EMPTYUNDOBUFFER, 0L, 0L))

#define Edit_SetPasswordChar(hboxCtl, ch)       ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETPASSWORDCHAR, (BX_WPARAM)(BX_UINT)(ch), 0L))

#define Edit_SetTabStops(hboxCtl, cTabs, lpTabs) ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETTABSTOPS, (BX_WPARAM)(BX_INT)(cTabs), (BX_LPARAM)(const BX_INT *)(lpTabs)))

#define Edit_FmtLines(hboxCtl, fAddEOL)         ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_FMTLINES, (BX_WPARAM)(BX_BOOL)(fAddEOL), 0L))

#define Edit_GetHandle(hboxCtl)                 ((HLOCAL)(BX_UINT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_GETHANDLE, 0L, 0L))
#define Edit_SetHandle(hboxCtl, h)              ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETHANDLE, (BX_WPARAM)(BX_UINT)(HLOCAL)(h), 0L))

#define Edit_GetFirstVisibleLine(hboxCtl)       ((BX_INT)(BX_DWORD)BxSendMessage((hboxCtl), BEM_GETFIRSTVISIBLELINE, 0L, 0L))

#define Edit_SetReadOnly(hboxCtl, fReadOnly)    ((BX_BOOL)(BX_DWORD)BxSendMessage((hboxCtl), BEM_SETREADONLY, (BX_WPARAM)(BX_BOOL)(fReadOnly), 0L))

#define Edit_GetPasswordChar(hboxCtl)           ((BX_CHAR)(BX_DWORD)BxSendMessage((hboxCtl), BEM_GETPASSWORDCHAR, 0L, 0L))

#define Edit_SetWordBreakProc(hboxCtl, lpfnWordBreak) ((BX_VOID)BxSendMessage((hboxCtl), BEM_SETWORDBREAKPROC, 0L, (BX_LPARAM)(EDITWORDBREAKPROC)(lpfnWordBreak)))
#define Edit_GetWordBreakProc(hboxCtl)          ((EDITWORDBREAKPROC)BxSendMessage((hboxCtl), BEM_GETWORDBREAKPROC, 0L, 0L))


#endif //_BOXSX_
