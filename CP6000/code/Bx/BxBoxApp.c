#include <stdio.h>
#include <stdlib.h>

#ifdef LINUX
#include <sys/io.h>
#include <asm/segment.h>
#include <asm/system.h>
#include <semaphore.h>
#endif

#include "BxTypes.h"
#include "Bx.h"
#include "BxEvent.h"

#ifdef SDLDRV
#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"

SDL_cond *bx_cond;
SDL_mutex *bx_mutex;
#else
#ifdef LINUX
#include "pthread.h"

pthread_cond_t bx_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t bx_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif
#endif


BX_VOID BxWaitEvent(BX_VOID)
{
//  sem_wait((sem_t*)&bx_sem);
#ifdef SDLDRV
  SDL_mutexP(bx_mutex);
  SDL_CondWait(bx_cond, bx_mutex);
  SDL_mutexV(bx_mutex);
#else
#ifdef LINUX
	pthread_mutex_lock(&bx_mutex);
  pthread_cond_wait(&bx_cond, &bx_mutex);
	pthread_mutex_unlock(&bx_mutex);
#endif
#endif
}

BX_VOID BxSetEvent(BX_VOID)
{
#ifdef SDLDRV
  SDL_CondSignal(bx_cond);
#else
#ifdef LINUX
	pthread_cond_signal(&bx_cond);
#endif
#endif
}

BX_VOID DlgAppInit(BX_VOID)
{
#ifdef SDLDRV
  bx_cond = SDL_CreateCond();
  bx_mutex = SDL_CreateMutex();
#else
#ifdef LINUX
	pthread_cond_init(&bx_cond, NULL);
	pthread_mutex_init(&bx_mutex, NULL);
#endif
#endif
}
