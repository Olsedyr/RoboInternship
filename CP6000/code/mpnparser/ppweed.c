#include "cmd.h"
#include "pptree.h"
#include "ppweed.h"

int ppweederr = 0;

void weedPP(PPSTRUCT *pp)
{
  int i;
  if(pp->numV!=PPSCRIPTVERSION) 
  {
    printf("Warning! Wrong ppscriptversion. Syntax must abide to version %i\n",PPSCRIPTVERSION);
  }
  weedMOVE_LIST(pp->move_list);
  if (ppweederr) {
    printf("quitting!\n");
    exit(0);
  }
}

void weedMOVE_LIST(MOVE_LIST *ml)
{
  if (ml->kind!=emptymove_listK)
  {
    weedMOVE_LIST(ml->move_list);
    weedMOVEDEC(ml->movedec);
  }
}

void weedMOVEDEC(MOVEDEC *m)
{
  int i;
  int itemok=0;
  //tjek at m->item findes i tworkcell;
  for (i=0;i<MAXITEMS;i++)
  {
    if(!strcmp((char*)tworkcell->items.item[i].name,m->item))
    {    
      itemok++;
      break;
    }
  }
  if (!itemok) 
  {
    printf("Item %s not found in workcell! Before line %i\n",m->item,m->lineno);
    ppweederr++;
  }
  if ((m->startmacro->kind!=emptystartmacroK)&&(m->startvia->kind==emptyviaK))
  {
    printf("It is necessary to have a startvia when having a startmacro! Before line %i\n",m->startvia->lineno);
    ppweederr++;
  }
  if ((m->endmacro->kind!=emptyendmacroK)&&(m->endvia->kind==emptyviaK))
  {
    printf("It is necessary to have an endvia when having an endmacro! Before line %i\n",m->endvia->lineno);
    ppweederr++;
  }
  weedFRAME(m->fromframe);
  weedSTARTMACRO(m->startmacro);
  weedVIA(m->startvia);
  weedFRAME(m->toframe);
  weedENDMACRO(m->endmacro);
  weedVIA(m->endvia);
  weedOPT_WITH(m->opt_with);
}

void weedFRAME(FRAME *fr)
{
  int i;
  int frameok=0;
  if (fr->kind==frameK)
  {
    //tjek at frame ID findes
    for (i=0;i<MAXFRAMENAMES;i++) {
      if (!strcmp((char*)trobot->m_frames.frame[i].name,fr->val.frameF.id))
      {
	frameok++;
	break;
      }
    }
    if (!frameok)
    {
      printf("Frame %s not found in workcell! Before line %i\n",fr->val.frameF.id,fr->lineno);
      ppweederr++;
    }
  }
  else if (fr->kind==framerelK)
  {
    //tjek at frame ID findes
    for (i=0;i<MAXFRAMENAMES;i++) {
      if (!strcmp((char*)trobot->m_frames.frame[i].name,fr->val.framerelF.id))
      {
	frameok++;
	break;
      }
    }
    if (!frameok)
    {
      printf("Frame %s not found in workcell! Before line %i\n",fr->val.framerelF.id,fr->lineno);
      ppweederr++;
    }
    weedSIXNUMS(fr->val.framerelF.sixnums);
  }
}

void weedVIA(VIAP *v)
{
  if (v->kind!=emptyviaK)
  {
    weedSIXNUMS(v->posnums);
    weedSIXNUMS(v->velnums);
  }
}

void weedSTARTMACRO(STARTMACRO *s)
{
  if (s->kind==uplinestartmacroK)
  {
    //TODO: tjek indenfor grænser;
  }
}

void weedENDMACRO(ENDMACRO *e)
{
  if (e->kind==downlineendmacroK)
  {
    //TODO: tjek indenfor grænser;
  }
  else if (e->kind==spiralendmacroK)
  {
    //TODO: tjek indenfor grænser;
  }
}

void weedOPT_WITH(OPT_WITH *o)
{
  if (o->kind==paramopt_withK)
  {
    weedPARAMLIST(o->paramlist);
  }
}

void weedPARAMLIST(PARAMLIST *pl)
{
  if (pl->kind==paramlist_paramlistK)
  {
    weedPARAMLIST(pl->paramlist);
    weedPARAM(pl->param);
  }
  else weedPARAM(pl->param);
}

void weedPARAM(PARAM *p)
{
  if (p->kind==maxvelparamK) 
  {
  weedSIXNUMS(p->val.maxvel);
  }
  else if (p->kind==maxaccparamK)
  { 
  weedSIXNUMS(p->val.maxacc);
  }
}

void weedSIXNUMS(SIXNUMS* f)
{
}

