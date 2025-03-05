#ifndef BXEVENT
#define BXEVENT

extern BX_BYTE NET_EVENT;

typedef struct tagMOUSEEVENT
{
  BX_WORD 				state;
  BX_WORD				xpos;
  BX_WORD				ypos;

} BX_MOUSEEVENTSTRUCT;

typedef struct tagKEYBOARDEVENT
{
  BX_WORD 			state;
  BX_WORD 			scan_code;

} BX_KEYBOARDEVENTSTRUCT;

#define				BX_NOEVENT 	    0
#define				BX_MOUSE_EVENT 	1
#define				BX_KBD_EVENT		2
#define				BX_SYS_EVENT		3

typedef struct tagEVENT 
{
  BX_UINT     		        type;
  BX_MOUSEEVENTSTRUCT		  ms_event;
  BX_KEYBOARDEVENTSTRUCT  kbd_event;

} BX_EVENTSTRUCT;

#define				BX_MAX_EVENTS 120

BX_VOID BxWaitEvent(BX_VOID);
BX_VOID BxSetEvent(BX_VOID);
BX_VOID BxInitEventHandler(BX_VOID);
BX_BOOL BxInsertMouseEvent(BX_WORD state, BX_WORD xpos, BX_WORD ypos); 
BX_BOOL BxInsertKeyboardEvent(BX_WORD state, BX_WORD scan_code); 
BX_BOOL BxGetSystemEvent(BX_EVENTSTRUCT *e);
BX_VOID BxConvertEventToMessage(BX_PMSG pMsg, BX_EVENTSTRUCT* e);

#endif //BXEVENT
