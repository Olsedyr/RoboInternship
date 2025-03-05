#include "cmd.h"
#include "pptree.h"
#include "ppcollect.h"

int ppcollecterr = 0;

void collectPP(PPSTRUCT *pp)
{
  collectMOVE_LIST(pp->move_list);
  if (ppcollecterr) {
    printf("quitting!\n");
    exit(0);
  }
}

void collectMOVE_LIST(MOVE_LIST *ml)
{
  if (ml->kind!=emptymove_listK)
  {
    collectMOVE_LIST(ml->move_list);
    collectMOVEDEC(ml->movedec);
  }
}

void collectMOVEDEC(MOVEDEC *m)
{
  collectFRAME(m->fromframe);
  collectSTARTMACRO(m->startmacro);
  collectVIA(m->startvia);
  collectFRAME(m->toframe);
  collectENDMACRO(m->endmacro);
  collectVIA(m->endvia);
  collectOPT_WITH(m->opt_with);
}

void collectFRAME(FRAME *fr)
{
  if (fr->kind==frameK)
  {
  }
  else if (fr->kind==framerelK)
  {
    collectSIXNUMS(fr->val.framerelF.sixnums);
  }
}

void collectVIA(VIAP *v)
{
  if (v->kind!=emptyviaK)
  {
    collectSIXNUMS(v->posnums);
    collectSIXNUMS(v->velnums);
  }
}

void collectSTARTMACRO(STARTMACRO *s)
{
  if (s->kind==uplinestartmacroK)
  {
    
  }
}

void collectENDMACRO(ENDMACRO *e)
{
  if (e->kind==downlineendmacroK)
  {
    
  }
  else if (e->kind==spiralendmacroK)
  {
    
  }
}

void collectOPT_WITH(OPT_WITH *o)
{
  if (o->kind==paramopt_withK)
  {
    collectPARAMLIST(o->paramlist);
  }
}

void collectPARAMLIST(PARAMLIST *pl)
{
  if (pl->kind==paramlist_paramlistK)
  {
    collectPARAMLIST(pl->paramlist);
    collectPARAM(pl->param);
  }
  else collectPARAM(pl->param);
}

void collectPARAM(PARAM *p)
{
  if (p->kind==maxvelparamK) 
  {
    collectSIXNUMS(p->val.maxvel);
  }
  else if (p->kind==maxaccparamK)
  { 
    collectSIXNUMS(p->val.maxacc);
  }
}

void collectSIXNUMS(SIXNUMS* f)
{

}

