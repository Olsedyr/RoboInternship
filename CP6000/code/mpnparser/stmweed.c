#include <stdlib.h>
#include "cmd.h"
#include "stmtree.h"
#include "stmweed.h"

unsigned int sthaltseen=0;
unsigned int stidleseen=0;
unsigned int stresetseen=0;
unsigned int delaystopseen=0;
unsigned int weederr=0;

void StmWeedSTATEMACHINE(STATEMACHINE *s)
{
  sthaltseen=0;
  stidleseen=0;
  stresetseen=0;
  delaystopseen=0;
  weederr=0;
  StmWeedVERSION(s->val.stm.version);
  StmWeedNAME(s->val.stm.name);
  StmWeedDECL_LIST(s->val.stm.decl_list);
  StmWeedSTATE_LIST(s->val.stm.state_list); 
  if (sthaltseen<1) {
    printf("Obligatory state ST_HALT missing!\n");
    weederr++;
  }
  if (stidleseen<1) {
    printf("Obligatory state ST_IDLE missing!\n");
    weederr++;
  }
  if (stresetseen<1) {
    printf("Obligatory state ST_RESET missing!\n");
    weederr++;
  }
  if (weederr) {
    printf("quitting!\n");
    exit(0);
  }
}

void StmWeedVERSION(VERSST *v)
{
  if(v->val.numV!=STATEMACHINEVERSION) 
  {
    printf("Warning! Wrong statemachineversion. Syntax must abide to version %i\n",STATEMACHINEVERSION);
  }
}

void StmWeedNAME(NAMEST *n)
{
}

void StmWeedDECL_LIST(DECL_LIST *d)
{ 
  switch(d->kind) {
  case decl_listK:
    StmWeedDECL_LIST(d->val.decl_listD.decl_list);
    StmWeedDECLARATION(d->val.decl_listD.declaration);
    break;
  case emptydlK:
    break;
  } 
}

void StmWeedDECLARATION(DECLARATION *d)
{
  switch(d->kind) {
  case inputK:    
    StmWeedOPT_FILTER(d->val.inputD.opt_filter);
    StmWeedOPT_SIM(d->val.inputD.opt_sim);
    break;
  case outputK:
    break;
  case linkK:
    break;
  case timeK:
    StmWeedEXP(d->val.timeD.exp);
    break;
  case valueK:
    if (d->val.valueD.exp!=NULL)
      StmWeedEXP(d->val.valueD.exp);
    if (d->val.valueD.opt_from!=NULL)
      StmWeedOPT_FROM(d->val.valueD.opt_from);
    break;
  case delaystopK:
    if (delaystopseen) 
    {
      printf("More than one delaystop declaration (line %i) not allowed.\n",d->lineno);
      weederr++;
    }
    else 
    {
      delaystopseen++;
    }
    StmWeedEXP(d->val.delaystopD.exp);
  }
}

void StmWeedOPT_FILTER(OPT_FILTER *o)
{
  switch (o->kind) {
  case filterK: 
    StmWeedEXP(o->val.filterF.ontime);
    StmWeedEXP(o->val.filterF.offtime);
    break;
  case emptyfilterK:
    break;
  }
}

void StmWeedOPT_SIM(OPT_SIM *o)
{
  switch (o->kind) {
  case simK:
    break;
  case emptysimK:
    break;
  }
}

void StmWeedOPT_FROM(OPT_FROM *o)
{
  switch (o->kind) {
  case fromK:
    break;
  case emptyfromK:
    break;
  }
}

void StmWeedSTATE_LIST(STATE_LIST *s)
{
  
  switch (s->kind) {
  case state_listK:
    StmWeedSTATE_LIST(s->val.state_listS.state_list);
    StmWeedSTATE(s->val.state_listS.state);
    break;
  case emptystate_listK:
    break;
  }
}

void StmWeedSTATE(STATEST *s)
{
  StmWeedHEAD(s->val.stateS.head);
  StmWeedSTATEMENT_LIST(s->val.stateS.statement_list); 
}

void StmWeedHEAD(HEAD *h)
{
  if (!strcmp(h->id,"ST_RESET")) {
    stresetseen++;
  }
  else if (!strcmp(h->id,"ST_IDLE")) {
    stidleseen++;
  }
  else if (!strcmp(h->id,"ST_HALT")) {
    sthaltseen++;
  }
}

void StmWeedSTATEMENT_LIST(STATEMENT_LIST *sl)
{
  switch (sl->kind) {
  case slK:
    StmWeedSTATEMENT_LIST(sl->val.statement_listS.statement_list);
    StmWeedSTATEMENT(sl->val.statement_listS.statement);
    break;
  case emptyslK:
    break;
  } 
}

void StmWeedSTATEMENT(STATEMENT *s)
{
  switch (s->kind) {
  case printK:   
    StmWeedEXP(s->val.printS.exp);
    break;
  case setK:
    StmWeedEXP(s->val.setS.exp);
    break;
  case testK:
    StmWeedEXP(s->val.testS.exp);
    StmWeedSTATEMENT_LIST(s->val.testS.statement_list);
    StmWeedOPT_ET_LIST(s->val.testS.opt_et_list);
    StmWeedOPT_ELSE(s->val.testS.opt_else);
    break;
  case setstateK:
    break;
  case timeoutK:
    StmWeedOPT_TIMERSTATE(s->val.timeoutS.opt_timerstate);
    break;
  case assignmentK:
    StmWeedEXP(s->val.assignmentS.exp);
    break;
  case plusassignK:
    StmWeedEXP(s->val.plusassignS.exp);
    break;
  case minusassignK:
    StmWeedEXP(s->val.minusassignS.exp);
    break;
  case plusplusK:
    break;
  }
}

void StmWeedOPT_TIMERSTATE(OPT_TIMERSTATE *o)
{
  if (o->kind == otsK) {}
}

void StmWeedOPT_ET_LIST(OPT_ET_LIST *o)
{  
  if (o->kind == oelK) {
    StmWeedOPT_ET_LIST(o->val.oelO.opt_et_list);
    StmWeedOPT_ELSETEST(o->val.oelO.opt_elsetest);
  }
}

void StmWeedOPT_ELSETEST(OPT_ELSETEST *o)
{
  StmWeedEXP(o->val.elsetestO.exp);
  StmWeedSTATEMENT_LIST(o->val.elsetestO.statement_list); 
}

void StmWeedOPT_ELSE(OPT_ELSE *o)
{
  if (o->kind == elseK) { 
    StmWeedSTATEMENT_LIST(o->val.statementlO.statement_list);
  } 
}

void StmWeedTERM(TERM *t) {
  switch(t->kind) {
  case parK:
    StmWeedEXP(t->val.parT.exp);
    break;    
  case notK:
    StmWeedTERM(t->val.notT.term);
    break;
  case numK:
    break;
    /*  case floatK:
	break; */
  case idK:
    break;    
  }
}

void StmWeedEXP(EXP* e) { 
 switch(e->kind) {
  case termK:
    StmWeedTERM(e->val.termE.term);
    break;
  case orK:
    StmWeedEXP(e->val.orE.left);
    StmWeedEXP(e->val.orE.right);
    break;
  case andK:
    StmWeedEXP(e->val.andE.left);
    StmWeedEXP(e->val.andE.right);
    break;
  case plusK:
    StmWeedEXP(e->val.plusE.left);
    StmWeedEXP(e->val.plusE.right);
    break;
  case minusK:
    StmWeedEXP(e->val.minusE.left);
    StmWeedEXP(e->val.minusE.right);
    break;
  case timesK:
    StmWeedEXP(e->val.timesE.left);
    StmWeedEXP(e->val.timesE.right);
    break;
  case divK:
    StmWeedEXP(e->val.divE.left);
    StmWeedEXP(e->val.divE.right);
    break;
  case equalK:
    StmWeedEXP(e->val.equalE.left);
    StmWeedEXP(e->val.equalE.right);
    break;
  case not_equalK:
    StmWeedEXP(e->val.not_equalE.left);
    StmWeedEXP(e->val.not_equalE.right);
    break;
  case larger_thanK:
    StmWeedEXP(e->val.larger_thanE.left);    
    StmWeedEXP(e->val.larger_thanE.right);
    break;
  case larger_than_equalK:
    StmWeedEXP(e->val.larger_than_equalE.left);
    StmWeedEXP(e->val.larger_than_equalE.right);
    break;
  case smaller_thanK:
    StmWeedEXP(e->val.smaller_thanE.left);
    StmWeedEXP(e->val.smaller_thanE.right);
    break;
  case smaller_than_equalK:
    StmWeedEXP(e->val.smaller_than_equalE.left);
    StmWeedEXP(e->val.smaller_than_equalE.right);
    break;
  } 
}
