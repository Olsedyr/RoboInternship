#include <stdlib.h>
#include "stmtree.h"

extern int line;

STATEMACHINE *makeSTATEMACHINE(VERSST *v, NAMEST *n, DECL_LIST *dl,STATE_LIST *stl)
{
  STATEMACHINE *s;
  s = NEW(STATEMACHINE);
  s->lineno = line;
  s->val.stm.version = v;
  s->val.stm.name = n;
  s->val.stm.decl_list = dl;
  s->val.stm.state_list = stl;
  return s;
}

VERSST *makeVERSION(int num)
{
  VERSST *v;
  v = NEW(VERSST);
  v->lineno = line;
  v->val.numV = num;
  return v;
}

NAMEST *makeNAME(char *nameid)
{
  NAMEST* n;
  n = NEW(NAMEST);
  n->lineno = line;
  n->val.id = nameid;
  return n;
}

DECL_LIST *makeDECL_LIST(DECL_LIST *del,DECLARATION *d)
{
  DECL_LIST *dl;
  dl = NEW(DECL_LIST);
  dl->lineno = line;
  dl->kind = decl_listK;
  dl->val.decl_listD.decl_list = del;
  dl->val.decl_listD.declaration = d;
  return dl;
}

DECL_LIST *makeDECL_LISTempty()
{
  DECL_LIST *d;
  d = NEW(DECL_LIST);
  d->lineno = line;
  d->kind = emptydlK;
  return d;
}

DECLARATION *makeDECLARATIONinput(char *inputid, char *dioid, OPT_FILTER *opt_filter, OPT_SIM *opt_sim)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = inputK;
  d->val.inputD.id1 = inputid;
  d->val.inputD.id2 = dioid;
  d->val.inputD.opt_filter = opt_filter;
  d->val.inputD.opt_sim = opt_sim;
  return d;
}

DECLARATION *makeDECLARATIONoutput(char *outputid,char *dioid)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = outputK;
  d->val.outputD.id1 = outputid;
  d->val.outputD.id2 = dioid;
  return d;
}

DECLARATION *makeDECLARATIONlink(char *id)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = linkK;
  d->val.linkD.id = id;
  return d;
}

DECLARATION *makeDECLARATIONtime(char *id, EXP *exp)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = timeK;
  d->val.timeD.id = id;
  d->val.timeD.exp = exp;
  return d;
}

DECLARATION *makeDECLARATIONvalue(char *id, EXP *exp)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = valueK;
  d->val.valueD.id = id;
  d->val.valueD.exp = exp;
  d->val.valueD.opt_from = NULL;
  return d;
}

DECLARATION *makeDECLARATIONvaluefrom(char *id, OPT_FROM *opt_from)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = valueK;
  d->val.valueD.id = id;
  d->val.valueD.exp = NULL;
  d->val.valueD.opt_from = opt_from;
  return d;
}

DECLARATION *makeDECLARATIONdelaystop(EXP *exp)
{
  DECLARATION *d;
  d = NEW(DECLARATION);
  d->lineno = line;
  d->kind = delaystopK;
  d->val.delaystopD.exp = exp;
  return d;
}

OPT_FILTER *makeFILTER(EXP *onexp, EXP *offexp)
{
  OPT_FILTER *f;
  f = NEW(OPT_FILTER);
  f->lineno = line;
  f->kind = filterK;
  f->val.filterF.ontime = onexp;
  f->val.filterF.offtime = offexp;
  return f;
}

OPT_FILTER *makeFILTERempty()
{
  OPT_FILTER *f;
  f = NEW(OPT_FILTER);
  f->lineno = line;
  f->kind = emptyfilterK;
  return f;
}

OPT_SIM *makeSIM()
{
  OPT_SIM *o;
  o = NEW(OPT_SIM);
  o->lineno = line;
  o->kind = simK;
  return o;
}

OPT_SIM *makeSIMempty()
{
  OPT_SIM *o;
  o = NEW(OPT_SIM);
  o->lineno = line;
  o->kind = emptysimK;
  return o;
}

OPT_FROM *makeFROM(char *id)
{
  OPT_FROM *f;
  f = NEW(OPT_FROM);
  f->lineno = line;
  f->kind = fromK;
  f->val.id = id;
  return f;
}

OPT_FROM *makeFROMempty()
{
  OPT_FROM *f;
  f = NEW(OPT_FROM);
  f->lineno = line;
  f->kind = emptyfromK;
  return f;
}

STATE_LIST *makeSTATE_LIST(STATE_LIST *stlist,STATEST *st)
{
  STATE_LIST *s;
  s = NEW(STATE_LIST);
  s->lineno = line;
  s->kind = state_listK;
  s->val.state_listS.state_list = stlist;
  s->val.state_listS.state = st;
  return s;
}

STATE_LIST *makeSTATE_LISTempty()
{
  STATE_LIST *s;
  s = NEW(STATE_LIST);
  s->lineno = line;
  s->kind = emptystate_listK;
  return s;
}

STATEST *makeSTATE(HEAD *h,STATEMENT_LIST *stlist)
{
  STATEST *s;
  s = NEW(STATEST);
  s->lineno = line;
  s->val.stateS.head = h;
  s->val.stateS.statement_list = stlist;
  return s;
}

HEAD *makeHEAD(char *id)
{
  HEAD *h;
  h = NEW(HEAD);
  h->lineno = line;
  h->id = id;
  return h;
}

STATEMENT_LIST *makeSTATEMENT_LIST(STATEMENT_LIST *sl, STATEMENT *statement)
{
  STATEMENT_LIST *s;
  s = NEW(STATEMENT_LIST);
  s->lineno = line;
  s->kind = slK;
  s->val.statement_listS.statement_list = sl;
  s->val.statement_listS.statement = statement;
  return s;
}

STATEMENT_LIST *makeSTATEMENT_LISTempty()
{
  STATEMENT_LIST *s;
  s = NEW(STATEMENT_LIST);
  s->lineno = line;
  s->kind = emptyslK;
  return s;
}

STATEMENT *makeSTATEMENTprint(EXP *exp)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = printK;
  s->val.printS.exp = exp;
  return s;
}

STATEMENT *makeSTATEMENTset(char *id, EXP *exp)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = setK;
  s->val.setS.id = id;
  s->val.setS.exp = exp;
  return s;
}

STATEMENT *makeSTATEMENTtest(EXP *exp, STATEMENT_LIST *sl, OPT_ET_LIST *opt_et_list, OPT_ELSE *opt_else)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = testK;
  s->val.testS.exp = exp;
  s->val.testS.statement_list = sl;
  s->val.testS.opt_et_list = opt_et_list;
  s->val.testS.opt_else = opt_else;
  return s;
}

STATEMENT *makeSTATEMENTassignment(char *id, EXP *exp)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = assignmentK;
  s->val.assignmentS.id = id;
  s->val.assignmentS.exp = exp;
  return s;
}

STATEMENT *makeSTATEMENTplusassign(char *id, EXP *exp)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = plusassignK;
  s->val.plusassignS.id = id;
  s->val.plusassignS.exp = exp;
  return s;
}

STATEMENT *makeSTATEMENTminusassign(char *id, EXP *exp)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = minusassignK;
  s->val.minusassignS.id = id;
  s->val.minusassignS.exp = exp;
  return s;
}

STATEMENT *makeSTATEMENTplusplus(char *id)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = plusplusK;
  s->val.plusplusS.id = id;
  return s;
}

STATEMENT *makeSTATEMENTsetstate(char *id)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = setstateK;
  s->val.setstateS.id = id;
  return s;
}

STATEMENT *makeSTATEMENTtimeout(char *timeid, char *tostateid, OPT_TIMERSTATE *opt_timerstate)
{
  STATEMENT *s;
  s = NEW(STATEMENT);
  s->lineno = line;
  s->kind = timeoutK;
  s->val.timeoutS.idtime = timeid;
  s->val.timeoutS.id_gotostate = tostateid;
  s->val.timeoutS.opt_timerstate = opt_timerstate;
  return s;
}

OPT_TIMERSTATE *makeOPT_TIMERSTATE(char *id)
{
  OPT_TIMERSTATE *o;
  o = NEW(OPT_TIMERSTATE);
  o->lineno = line;
  o->kind = otsK;
  o->val.id = id;
  return o;
}

OPT_TIMERSTATE *makeOPT_TIMERSTATEempty()
{
  OPT_TIMERSTATE *o;
  o = NEW(OPT_TIMERSTATE);
  o->lineno = line;
  o->kind = emptyotsK;
  return o;
}

OPT_ET_LIST *makeOPT_ET_LIST(OPT_ET_LIST *opt_et_list, OPT_ELSETEST *opt_elsetest)
{
  OPT_ET_LIST *o;
  o = NEW(OPT_ET_LIST);
  o->lineno = line;
  o->kind = oelK;
  o->val.oelO.opt_et_list = opt_et_list;
  o->val.oelO.opt_elsetest = opt_elsetest;
  return o;
}

OPT_ET_LIST *makeOPT_ET_LISTempty()
{
  OPT_ET_LIST *o;
  o = NEW(OPT_ET_LIST);
  o->lineno = line;
  o->kind = emptyoelK;
  return o;
}

OPT_ELSETEST *makeOPT_ELSETEST(EXP *exp, STATEMENT_LIST *sl)
{
  OPT_ELSETEST *o;
  o = NEW(OPT_ELSETEST);
  o->lineno = line;
  o->val.elsetestO.exp = exp;
  o->val.elsetestO.statement_list = sl;
  return o;
}

OPT_ELSE *makeOPT_ELSEempty() {
  OPT_ELSE *o;
  o = NEW(OPT_ELSE);
  o->lineno = line;
  o->kind = emptyOEK;
  return o;
}

OPT_ELSE *makeOPT_ELSE(STATEMENT_LIST *sl) {
  OPT_ELSE *o;
  o = NEW(OPT_ELSE);
  o->lineno = line;
  o->kind = elseK;
  o->val.statementlO.statement_list = sl;
  return o;
}

TERM *makeTERMid(char *id) {
  TERM *t;
  t = NEW(TERM);
  t->lineno = line;
  t->kind = idK;
  t->val.id = id;
  return t;
}

/*TERM *makeTERMfloat(float f)
{
  TERM *t;
  t = NEW(TERM);
  t->lineno = line;
  t->kind = floatK;
  t->val.floatT = f;
  return t;
}*/

TERM *makeTERMnum(int num){ 
  TERM *t;
  t = NEW(TERM);
  t->lineno = line;
  t->kind = numK;
  t->val.numT = num;
  return t;
}

TERM *makeTERMnot(TERM *term) {
  TERM *t;
  t = NEW(TERM);
  t->lineno = line;
  t->kind = notK;
  t->val.notT.term = term;
  return t;  
}

TERM *makeTERMpar(EXP *exp)
{
  TERM *t;
  t = NEW(TERM);
  t->lineno = line;
  t->kind = parK;
  t->val.parT.exp = exp;
  return t;
}

EXP *makeEXPterm(TERM *term) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = termK;
  e->val.termE.term=term;
  return e;
}

EXP *makeEXPor(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = orK;
  e->val.orE.left = left;
  e->val.orE.right = right;
  return e;
}

EXP *makeEXPand(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = andK;
  e->val.andE.left = left;
  e->val.andE.right = right;
  return e;
}


EXP *makeEXPtimes(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = timesK;
  e->val.timesE.left = left;
  e->val.timesE.right = right;
  return e;
}

EXP *makeEXPdiv(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = divK;
  e->val.divE.left = left;
  e->val.divE.right = right;
  return e;
}

EXP *makeEXPplus(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = plusK;
  e->val.plusE.left = left;
  e->val.plusE.right = right;
  return e;
}

EXP *makeEXPminus(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = minusK;
  e->val.minusE.left = left;
  e->val.minusE.right = right;
  return e;
}

EXP *makeEXPequal(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = equalK;
  e->val.equalE.left = left;
  e->val.equalE.right = right;
  return e;
}

EXP *makeEXPnot_equal(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = not_equalK;
  e->val.not_equalE.left = left;
  e->val.not_equalE.right = right;
  return e;
}

EXP *makeEXPlarger_than(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = larger_thanK;
  e->val.larger_thanE.left = left;
  e->val.larger_thanE.right = right;
  return e;
}

EXP *makeEXPlarger_than_equal(EXP *left, EXP *right){
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = larger_than_equalK;
  e->val.larger_than_equalE.left = left;
  e->val.larger_than_equalE.right = right;
  return e;
}

EXP *makeEXPsmaller_than(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = smaller_thanK;
  e->val.smaller_thanE.left = left;
  e->val.smaller_thanE.right = right;
  return e;
}

EXP *makeEXPsmaller_than_equal(EXP *left, EXP *right) {
  EXP *e;
  e = NEW(EXP);
  e->lineno = line;
  e->kind = smaller_than_equalK;
  e->val.smaller_than_equalE.left = left;
  e->val.smaller_than_equalE.right = right;
  return e;
}
