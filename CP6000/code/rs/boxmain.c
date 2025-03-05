/***************************************************************************
                          boxmain.c  -  description
                             -------------------
    begin                : Wed Aug 6 2003
    copyright            : (C) 2003 by MPN A/S - Guided by vision(R) Lars M Sandig
    email                : lms@mpn.nu
 ***************************************************************************/
#include <unistd.h>
#include <pthread.h>

#include "Bx.h"
#include "form2pCal.h"
#include "formStartup.h"
#include "formHome.h"
#include "formStdRun.h"
#include "formTomatoInBox.h"
#include "cmd.h"

static unsigned long bx_update_freq = 1000000;

extern int LoadSystemParam(void);
extern BX_VOID BxGfxX11Drv_Shutdown(BX_VOID);
// Send opdate til Bx hver sek.
unsigned long SetUpdateFreq(unsigned long updfq)
{
  unsigned long old = bx_update_freq;

  if(updfq > 1000)
    bx_update_freq = updfq;

  return old;
}

void *one_second_interval(void * argument )
{
  usleep(2000000);
  for(;;)
  {
    usleep(bx_update_freq);

    BxUpdate();
    BxSetEvent();
  }
}


/***************************************************************************
 *
 *  Box task
 *
 ***************************************************************************/

void *boxMain(void *t)
{
  INSTANCESTRUCT inst = {&formStdRun[0], FALSE, 0,};
  INSTANCESTRUCT hsinst = {&formTomatoInBox[0], FALSE, 0,};
  HBOX hBox;

  BxInitSystem();

  BxSetUserLevel(BROWSERLEVEL);

  if(LoadSystemParam()==FALSE)
  {
    hBox = BxCreateDialog(&inst, &form2pCal[0], form2pCalProc);
    DoModal(hBox);
  }

  hBox = BxCreateDialog(&inst, &formStartup[0], formStartupProc);
  if(DoModal(hBox)!=IDOK)
  {
    hBox = BxCreateDialog(&inst, &formHome[0], formHomeProc);
    DoModal(hBox);
  }

  if(rs_param.workcellid==302) 
    hBox = BxCreateDialog(&hsinst, &formTomatoInBox[0], formTomatoInBoxProc);
  else
    hBox = BxCreateDialog(&inst, &formStdRun[0], formStdRunProc);
  DoModal(hBox);
  BxCloseSystem();
  return NULL;
}
