#include "diotree.h"

extern int dioline;


DIO *makeDIO(int numV, NUMMODST *n, MODLIST *ml)
{
  DIO *d;
  d = NEW(DIO);
  d->lineno = dioline; 
  d->val.dio.numV = numV;
  d->val.dio.nummod = n;
  d->val.dio.modlist = ml;
  return d;
}

NUMMODST *makeNUMMOD(int num)
{
  NUMMODST *n;
  n = NEW(NUMMODST);
  n->lineno = dioline;
  n->numM=num;
  return n;
}

MODLIST *makeMODLIST(MODLIST *modlist,MODULE *module)
{
  MODLIST *m;
  m = NEW(MODLIST);
  m->lineno = dioline; 
  m->kind = modlistK;
  m->val.modlistM.modlist=modlist;
  m->val.modlistM.module=module;
  return m;
}

MODLIST *makeMODLISTempty()
{
  MODLIST *m;
  m = NEW(MODLIST);
  m->lineno = dioline; 
  m->kind = emptymlK;
  return m;
}

MODULE *makeMODULE(char *typeid,char *nameid,CONNECTLIST *connectlist)
{
  MODULE *m;
  m = NEW(MODULE);
  m->lineno = dioline;
  m->val.moduleM.typeid=typeid;
  m->val.moduleM.nameid=nameid;
  m->val.moduleM.connectlist=connectlist;
  return m;
}

CONNECTLIST *makeCONNECTLIST(CONNECTLIST *connectlist,CONNECTOR *connector)
{
  CONNECTLIST *c;
  c = NEW(CONNECTLIST);
  c->lineno = dioline;
  c->kind = connectlistK;
  c->val.connectorL.connectlist = connectlist;
  c->val.connectorL.connector = connector;
  return c;
}

CONNECTLIST *makeCONNECTLISTempty()
{
  CONNECTLIST *c;
  c = NEW(CONNECTLIST);
  c->lineno = dioline;
  c->kind = emptyclK;
  return c;
}

CONNECTOR *makeCONNECTOR(int num, char *id, char *comment,OPT_FLIP *opt_flip)
{
  CONNECTOR *c;
  c = NEW(CONNECTOR);
  c->lineno = dioline;
  c->kind = connectorK;
  c->val.connectorC.num = num;
  c->val.connectorC.id = id;
  c->val.connectorC.comment = comment;
  c->val.connectorC.opt_flip = opt_flip;
  return c;
}

CONNECTOR *makeCONNECTORempty(int num)
{
  CONNECTOR *c;
  c = NEW(CONNECTOR);
  c->lineno = dioline;
  c->kind = emptyconnectorK;
  c->val.connectorC.num = num;
  return c;
}

OPT_FLIP *makeOPT_FLIP()
{
  OPT_FLIP *o;
  o = NEW(OPT_FLIP);
  o->lineno = dioline;
  o->kind = opt_flipK;
  return o;
}

OPT_FLIP *makeOPT_FLIPempty()
{
  OPT_FLIP *o;
  o = NEW(OPT_FLIP);
  o->lineno = dioline;
  o->kind = emptyopt_flipK;
  return o;
}
