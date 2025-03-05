#include "Bx.h"
#include "BxEvent.h"
#ifdef SDLDRV
#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"
SDL_mutex *bxevent_mutex;
#else
#ifdef LINUX
#include "pthread.h"
pthread_mutex_t bxevent_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif
#endif
extern void fbcon_bell(void);

extern xVkeys xVkeysTab[];

//static int OLD_LBUTTON = BM_LBUTTONUP;

BX_VOID BxConvertKBDEventToVKeys(BX_PMSG pMsg, BX_EVENTSTRUCT* e);

BX_EVENTSTRUCT bx_SystemEventQueue[BX_MAX_EVENTS];

BX_INT volatile AKTEVENTNUM=-1;

BX_VOID InitEventHandler(BX_VOID)
{
  BX_INT i;
#ifdef SDLDRV
  bxevent_mutex=SDL_CreateMutex();  
	SDL_mutexP(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_init(&bxevent_mutex, NULL);
	pthread_mutex_lock(&bxevent_mutex);
#endif
#endif
  for(i=0;i<BX_MAX_EVENTS;i++)
    bx_SystemEventQueue[i].type = BX_NOEVENT;

	AKTEVENTNUM=-1;
#ifdef SDLDRV
	SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
}

/***********************************************************
** This is the callback function for the MOUSE driver
**
** BX_BOOL BxInsertMouseEvent(BX_WORD type, BX_WORD state, BX_WORD xpos, BX_WORD ypos) 
**
**
** return : TRUE if OK or FALSE if bx_SystemEventQueue is full
**
** state :  bit			Description
**			     0			pressed
**			     1   		released
**			     2			pressed and moved
**			     3 - 15		reserved
**
** xpos : 			Horizontal position
** ypos					Vertical position
**
************************************************************/

BX_BOOL BxInsertMouseEvent(BX_WORD state, BX_WORD xpos, BX_WORD ypos) 
{
#ifdef SDLDRV
	SDL_mutexP(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_lock(&bxevent_mutex);
#endif
#endif
  if(AKTEVENTNUM+1 >= BX_MAX_EVENTS)
  {
#ifdef SDLDRV
		SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
		pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
		//			MoveCursor(xpos, ypos);
		//    Beep(25,1000);
    return FALSE;
  }
	
	bx_SystemEventQueue[AKTEVENTNUM+1].type = BX_MOUSE_EVENT;
	
	bx_SystemEventQueue[AKTEVENTNUM+1].ms_event.state = state;
	bx_SystemEventQueue[AKTEVENTNUM+1].ms_event.xpos = xpos;
	bx_SystemEventQueue[AKTEVENTNUM+1].ms_event.ypos = ypos;
	
  AKTEVENTNUM++;
#ifdef SDLDRV
	SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
  return TRUE;
}    

/***********************************************************
** This is the callback function for the Keyboard driver
**
** BX_BOOL BxInsertKeyboardEvent(BX_WORD scan_code) 
**
**
** return : TRUE if OK or FALSE if bx_SystemEventQueue is full
**
**
************************************************************/

BX_BOOL BxInsertKeyboardEvent(BX_WORD state, BX_WORD scan_code) 
{
#ifdef SDLDRV
	SDL_mutexP(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_lock(&bxevent_mutex);
#endif
#endif
  if(AKTEVENTNUM+1 >= BX_MAX_EVENTS)
  {
#ifdef SDLDRV
		SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
		pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
//    Beep(25,1000);
    return FALSE;
  }
	
	bx_SystemEventQueue[AKTEVENTNUM+1].type = BX_KBD_EVENT;
	bx_SystemEventQueue[AKTEVENTNUM+1].kbd_event.state = state;
	bx_SystemEventQueue[AKTEVENTNUM+1].kbd_event.scan_code = scan_code;
	
  AKTEVENTNUM++;
#ifdef SDLDRV
		SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
		pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
  return TRUE;
}    

/***********************************************************
** This is the callback function for the Keyboard driver
**
** BX_BOOL BxInsertSystemEvent(BX_WORD scan_code) 
**
**
** return : TRUE if OK or FALSE if bx_SystemEventQueue is full
**
**
************************************************************/
/*
BX_BOOL BxInsertSystemEvent(BX_WORD state, BX_WORD scan_code) 
{
  if(AKTEVENTNUM+1 >= BX_MAX_EVENTS)
  {
//    Beep(25,1000);
    return FALSE;
  }
	
	bx_SystemEventQueue[AKTEVENTNUM+1].type = BX_KBD_EVENT;
	bx_SystemEventQueue[AKTEVENTNUM+1].kbd_event.state = state;
	bx_SystemEventQueue[AKTEVENTNUM+1].kbd_event.scan_code = scan_code;
	
  AKTEVENTNUM++;
  return TRUE;
}    
*/

BX_BOOL BxGetSystemEvent(BX_EVENTSTRUCT *e)
{
	//BX_UINT flags;
	BX_INT i;
#ifdef SDLDRV
	SDL_mutexP(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_lock(&bxevent_mutex);
#endif
#endif
  if(AKTEVENTNUM < 0)
  {
#ifdef SDLDRV
		SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
		pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
    return FALSE;
  }
	
  switch(bx_SystemEventQueue[0].type) {
  case BX_MOUSE_EVENT:
		e->type = bx_SystemEventQueue[0].type;
		e->ms_event.state = bx_SystemEventQueue[0].ms_event.state;
		e->ms_event.xpos = bx_SystemEventQueue[0].ms_event.xpos;
		e->ms_event.ypos = bx_SystemEventQueue[0].ms_event.ypos;
		break;
  case BX_KBD_EVENT:
		e->type = bx_SystemEventQueue[0].type;
		e->kbd_event.state = bx_SystemEventQueue[0].kbd_event.state;
		e->kbd_event.scan_code = bx_SystemEventQueue[0].kbd_event.scan_code;
		break;
  }
	
	//flags = BxDisableInt();

  for(i=0;i<AKTEVENTNUM;i++)
  {
    bx_SystemEventQueue[i].type = bx_SystemEventQueue[i+1].type;
		switch(bx_SystemEventQueue[i+1].type) {
		case BX_MOUSE_EVENT :
			bx_SystemEventQueue[i].ms_event.state = bx_SystemEventQueue[i+1].ms_event.state;
			bx_SystemEventQueue[i].ms_event.xpos = bx_SystemEventQueue[i+1].ms_event.xpos;
			bx_SystemEventQueue[i].ms_event.ypos = bx_SystemEventQueue[i+1].ms_event.ypos;
			break;
		case BX_KBD_EVENT :
		  bx_SystemEventQueue[i].kbd_event.scan_code = bx_SystemEventQueue[i+1].kbd_event.scan_code;
		  bx_SystemEventQueue[i].kbd_event.state = bx_SystemEventQueue[i+1].kbd_event.state;
			break;
		}
  }
  AKTEVENTNUM--;
#ifdef SDLDRV
	SDL_mutexV(bxevent_mutex);
#else
#ifdef LINUX
	pthread_mutex_unlock(&bxevent_mutex);
#endif
#endif
	//flags = BxEnableInt(flags);
  return TRUE;
}


BX_VOID BxConvertEventToMessage(BX_PMSG pMsg, BX_EVENTSTRUCT* e)
{
  switch(e->type) {
		case BX_MOUSE_EVENT:
			pMsg->wParam = 0;
			pMsg->lParam = BX_MAKELPARAM(e->ms_event.xpos, e->ms_event.ypos) ;
			pMsg->pt.x = e->ms_event.xpos;
			pMsg->pt.y = e->ms_event.ypos;
//			pMsg->time = (BX_DWORD)time(NULL);
			
			if(e->ms_event.state & 1) // Left button down
  			pMsg->message = BM_LBUTTONDOWN;
			if(e->ms_event.state & 2) // Left button down & move
				pMsg->message = BM_MOUSEMOVE;
			if(e->ms_event.state & 4) // Left button up
      {
        pMsg->message = BM_LBUTTONUP;
        fbcon_bell();
      }
			break;
		case BX_KBD_EVENT:
      BxConvertKBDEventToVKeys(pMsg, e);
      break;
	}
}


BX_VOID BxConvertKBDEventToVKeys(BX_PMSG pMsg, BX_EVENTSTRUCT* e)
{
  if(e->kbd_event.state & 1)
    pMsg->message = BM_KEYDOWN;
  else
    pMsg->message = BM_KEYUP;
  switch(e->kbd_event.scan_code) {
  case 9:
    pMsg->wParam = VK_TAB;
    break;
  case 13:
    pMsg->wParam = VK_RETURN;
    break;
  case 27:
    pMsg->wParam = VK_ESCAPE;
    break;
  case 43:
    pMsg->wParam = VK_ADD;
    break;
  case 45:
    pMsg->wParam = VK_SUBTRACT;
    break;
  case 147:
    pMsg->wParam = VK_UP;
    break;
  case 141:
    pMsg->wParam = VK_DOWN;
    break;
  case 71:
    pMsg->wParam = VK_HOME;
    break;
  case 79:
    pMsg->wParam = VK_END;
    break;
  case 73:
    pMsg->wParam = VK_PGUP;
    break;
  case 81:
    pMsg->wParam = VK_PGDN;
    break;
  case 145:
    pMsg->wParam = VK_RIGHT;
    break;
  case 143:
    pMsg->wParam = VK_LEFT;
    break;
  default:
    pMsg->wParam = xVkeysTab[e->kbd_event.scan_code].vkey;
//    printf("\n%d ", e->kbd_event.scan_code);
    break;
  }
}
