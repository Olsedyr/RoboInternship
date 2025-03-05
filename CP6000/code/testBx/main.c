#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Bx.h"

#include "SDL\SDL.h"
#include "SDL\SDL_thread.h"

#include "formStdRun.h"

extern int sdlevent_task(void *t);
static int quit=0;

static unsigned long bx_update_freq = 100;

int one_second_interval(void * argument )
{
  for(;;)
  {
    SDL_Delay(bx_update_freq);
    BxUpdate();
    BxSetEvent();
  }
}


/***************************************************************************
 *
 *  Box task
 *
 ***************************************************************************/

int boxMain(void *t)
{
  INSTANCESTRUCT inst = {&formStdRun[0], FALSE, 0,};
//  INSTANCESTRUCT hsinst = {&formTomatoInBox[0], FALSE, 0,};
  HBOX hBox;

//  BxInitSystem();

  BxSetUserLevel(BROWSERLEVEL);

  hBox = BxCreateDialog(&inst, &formStdRun[0], formStdRunProc);

  DoModal(hBox);

  BxCloseSystem();
  quit=1;
  return 0;
}

int main(int argc, char *argv[])
{
  SDL_Event event;
  SDL_Thread *boxthread;
  SDL_Thread *onesecthread;
//  SDL_Thread *eventfunc;
  int status;
  float swf = 800.0/800.0;
  float shf = 600.0/600.0;
  
  BxInitSystem();
//  eventfunc = SDL_CreateThread(sdlevent_task, NULL);
  onesecthread = SDL_CreateThread(one_second_interval, NULL);
  boxthread = SDL_CreateThread(boxMain, NULL);

  /* main event loop */
  while(!quit)
  {
	SDL_WaitEvent(&event);

    switch(event.type)
      {
        case SDL_MOUSEBUTTONDOWN:
          BxInsertMouseEvent(1, (int)((float)event.button.x/swf), (int)((float)event.button.y/shf));
          BxSetEvent();
		break;
        case SDL_MOUSEMOTION:
          if(event.motion.state & SDL_BUTTON(1))   
          {
            BxInsertMouseEvent(2, (int)((float)event.motion.x/swf), (int)((float)event.motion.y/shf));
            BxSetEvent();
          }
		break;
        case SDL_MOUSEBUTTONUP:
          BxInsertMouseEvent(4, (int)((float)event.button.x/swf), (int)((float)event.button.y/shf));
          BxSetEvent();
		break;

        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							BxInsertKeyboardEvent(1, 27);
							BxSetEvent();
						break;
						case SDLK_UP:
							BxInsertKeyboardEvent(1, 147);
							BxSetEvent();
						break;
						case SDLK_DOWN:
							BxInsertKeyboardEvent(1, 141);
							BxSetEvent();
						break;
						case SDLK_LEFT:
							BxInsertKeyboardEvent(1, 143);
							BxSetEvent();
						break;
						case SDLK_RIGHT:
							BxInsertKeyboardEvent(1, 145);
							BxSetEvent();
						break;
						case SDLK_RETURN:
							BxInsertKeyboardEvent(1, 13);
							BxSetEvent();
						break;

						default:
						break;
					}
				break;
        case SDL_KEYUP:
				break;
        default:
        break;
     }
    }
  SDL_WaitThread(boxthread, &status);
//  SDL_KillThread(eventfunc);     
  
  return 0;
}
