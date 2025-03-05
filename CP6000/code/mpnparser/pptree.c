#include "pptree.h"

extern int ppline;


PPSTRUCT *makePP(int numV,char *name,int type,int itemsprlayer,int layers,MOVE_LIST *move_list)
{
  PPSTRUCT *p;
  p = NEW(PPSTRUCT);
  p->lineno = ppline; 
  p->numV = numV;
  p->name = name;
  p->type = type;
  p->itprlay = itemsprlayer;
  p->layers = layers;
  p->move_list = move_list;
  return p;
}

MOVE_LIST *makeMOVE_LIST(MOVE_LIST *move_list,MOVEDEC *movedec)
{
  MOVE_LIST *dl;
  dl = NEW(MOVE_LIST);
  dl->lineno=ppline;
  dl->kind=move_listK;
  dl->move_list=move_list;
  dl->movedec=movedec;
  return dl;
}

MOVE_LIST *makeMOVE_LISTempty()
{
  MOVE_LIST *dl;
  dl = NEW(MOVE_LIST);
  dl->lineno=ppline;
  dl->kind=emptymove_listK;
  return dl;
}

MOVEDEC *makeMOVEDEC(char *id,int idxlayer,int idxnum,FRAME *fromframe,STARTMACRO *startmacro,VIAP *startvia,FRAME *toframe,ENDMACRO *endmacro,VIAP *endvia,OPT_WITH *opt_with)
{
  MOVEDEC *d;
  d = NEW(MOVEDEC);
  d->lineno=ppline;
  d->item=id;
  d->idxlayer=idxlayer;
  d->idxnum=idxnum;
  d->fromframe=fromframe;
  d->startmacro=startmacro;
  d->startvia=startvia;
  d->toframe=toframe;
  d->endmacro=endmacro;
  d->endvia=endvia;
  d->opt_with=opt_with;
  return d;
}

FRAME *makeFRAME(char *id)
{
  FRAME *f;
  f = NEW(FRAME);
  f->lineno=ppline;
  f->kind=frameK;
  f->val.frameF.id=id;
  return f;
}

FRAME *makeFRAMErel(char *id,SIXNUMS *f)
{
  FRAME *fr;
  fr = NEW(FRAME);
  fr->lineno=ppline;
  fr->kind=framerelK;
  fr->val.framerelF.id=id;
  fr->val.framerelF.sixnums=f;
  return fr;
}

VIAP *makeVIA(SIXNUMS *pos,SIXNUMS *vel)
{
  VIAP *v;
  v = NEW(VIAP);
  v->lineno=ppline;
  v->kind=viaK;
  v->posnums=pos;
  v->velnums=vel;
  return v;
}

VIAP *makeVIAempty()
{
  VIAP *v;
  v = NEW(VIAP);
  v->lineno=ppline;
  v->kind=emptyviaK;
  return v;
}

STARTMACRO *makeSTARTMACROupline(REAL length,REAL time)
{
  STARTMACRO *s;
  s = NEW(STARTMACRO);
  s->lineno = ppline;
  s->kind = uplinestartmacroK;
  s->val.uplineM.length=length;
  s->val.uplineM.time=time;
  return s;
}

STARTMACRO *makeSTARTMACROempty()
{
  STARTMACRO *s;
  s = NEW(STARTMACRO);
  s->lineno = ppline;
  s->kind = emptystartmacroK;
  return s;
}

ENDMACRO *makeENDMACROdownline(REAL length,REAL time)
{
  ENDMACRO *e;
  e = NEW(ENDMACRO);
  e->lineno = ppline;
  e->kind = downlineendmacroK;
  e->val.downlineM.length=length;
  e->val.downlineM.time=time;
  return e;
}

ENDMACRO *makeENDMACROspiral(REAL amplitude, REAL offsx, REAL offsz, REAL length, REAL freq, REAL time)
{
  ENDMACRO *e;
  e = NEW(ENDMACRO);
  e->lineno = ppline;
  e->kind = spiralendmacroK;
  e->val.spiralM.amplitude=amplitude;
  e->val.spiralM.offsx=offsx;
  e->val.spiralM.offsz=offsz;
  e->val.spiralM.length=length;
  e->val.spiralM.freq=freq;
  e->val.spiralM.time=time;
  return e;
}

ENDMACRO *makeENDMACROempty()
{
  ENDMACRO *e;
  e = NEW(ENDMACRO);
  e->lineno = ppline;
  e->kind = emptyendmacroK;
  return e;
}

OPT_WITH *makeOPT_WITHparamlist(PARAMLIST *pl)
{
  OPT_WITH *o;
  o = NEW(OPT_WITH);
  o->lineno=ppline;
  o->kind=paramopt_withK;
  o->paramlist=pl;
  return o;
}

OPT_WITH *makeOPT_WITHdefaults()
{
  OPT_WITH *o;
  o = NEW(OPT_WITH);
  o->lineno=ppline;
  o->kind=defaultsopt_withK;
  return o;
}

PARAMLIST *makePARAMLISTparamlist(PARAMLIST *pl,PARAM *p)
{
  PARAMLIST *parl;
  parl = NEW(PARAMLIST);
  parl->lineno=ppline;
  parl->kind=paramlist_paramlistK;
  parl->paramlist=pl;
  parl->param=p;
  return parl;
}

PARAMLIST *makePARAMLISTparam(PARAM *p)
{
  PARAMLIST *parl;
  parl = NEW(PARAMLIST);
  parl->lineno=ppline;
  parl->kind=param_paramlistK;
  parl->param=p;
  return parl;
}

PARAM *makePARAMquintic()
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=quinticparamK;
  return p;
}

PARAM *makePARAMcubic()
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=cubicparamK;
  return p;
}

PARAM *makePARAMpositionhint(REAL poshinttime)
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=positionhintparamK;
  p->val.positionhinttime=poshinttime;
  return p;
}

PARAM *makePARAMmaxvel(SIXNUMS *maxvel)
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=maxvelparamK;
  p->val.maxvel=maxvel;
  return p;
}

PARAM *makePARAMmaxacc(SIXNUMS *maxacc)
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=maxaccparamK;
  p->val.maxacc=maxacc;
  return p;
}

PARAM *makePARAMsamplerate(REAL samplerate)
{
  PARAM *p;
  p = NEW(PARAM);
  p->lineno=ppline;
  p->kind=samplerateparamK;
  p->val.samplerate=samplerate;
  return p;
}

SIXNUMS *makeSIXNUMS(REAL a, REAL b,REAL c, REAL d, REAL e, REAL f)
{
  SIXNUMS *fn;
  fn = NEW(SIXNUMS);
  fn->lineno=ppline;
  fn->nums[0]=a;
  fn->nums[1]=b;
  fn->nums[2]=c;
  fn->nums[3]=d;
  fn->nums[4]=e;
  fn->nums[5]=f;
}

REAL makeREALnum(int i)
{
  return (float)i;
}

REAL makeREALfloating(float f)
{
  return f;
}
