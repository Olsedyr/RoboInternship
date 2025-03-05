#include <string.h>
#include "symbol.h"
#include "stmtree.h"
#include "stmpretty.h"

void StmPrettyPrinter(STATEMACHINE *s) {
  StmPrettySTATEMACHINE(s);
  printf("\n");
}

void StmPrettySTATEMACHINE(STATEMACHINE *s)
{
  printf("(\n");
  StmPrettyVERSION(s->val.stm.version);
  StmPrettyNAME(s->val.stm.name);
  StmPrettyDECL_LIST(s->val.stm.decl_list);
  StmPrettySTATE_LIST(s->val.stm.state_list);
  printf("\n)");
}

void StmPrettyVERSION(VERSST *v)
{
  printf("(STATEMACHINEVERSION %i)\n",v->val.numV);
}

void StmPrettyNAME(NAMEST *n)
{
 printf("(Name %s)\n",n->val.id);
}

void StmPrettyDECL_LIST(DECL_LIST *d)
{
  printf("(");
  switch(d->kind) {
  case decl_listK:
    StmPrettyDECL_LIST(d->val.decl_listD.decl_list);
    StmPrettyDECLARATION(d->val.decl_listD.declaration);
    break;
  case emptydlK:
    break;
  }
  printf(")\n");
}

void StmPrettyDECLARATION(DECLARATION *d)
{
  printf("{");
  switch(d->kind) {
  case inputK:
    printf("Input %s %s ",d->val.inputD.id1,d->val.inputD.id2); 
    StmPrettyOPT_FILTER(d->val.inputD.opt_filter);
    StmPrettyOPT_SIM(d->val.inputD.opt_sim);
    break;
  case outputK:
    printf("Output %s %s ",d->val.outputD.id1,d->val.outputD.id2); 
    break;
  case linkK:
    printf("Link %s ",d->val.linkD.id); 
    break;
  case timeK:
    printf("Time %s ",d->val.timeD.id);
    StmPrettyEXP(d->val.timeD.exp);
    break;
  case valueK:
    printf("Value %s ",d->val.valueD.id);
    StmPrettyEXP(d->val.valueD.exp);
    StmPrettyOPT_FROM(d->val.valueD.opt_from);
    break;
  case delaystopK:
    printf("Delaystop ");
    StmPrettyEXP(d->val.delaystopD.exp);
  }
  printf("}");
}

void StmPrettyOPT_FILTER(OPT_FILTER *o)
{
  switch (o->kind) {
  case filterK:
    printf("( Filter ");
    StmPrettyEXP(o->val.filterF.ontime);
    StmPrettyEXP(o->val.filterF.offtime);
    break;
  case emptyfilterK:
    printf("(");
  }
  printf(")");
}

void StmPrettyOPT_SIM(OPT_SIM *o)
{
  switch (o->kind) {
  case simK:
    printf("(Simulate");
    break;
  case emptysimK:
    printf("(");
  }
  printf(")");
}

void StmPrettyOPT_FROM(OPT_FROM *o)
{
  switch (o->kind) {
  case fromK:
    printf("(From %s",o->val.id);
    break;
  case emptyfromK:
    printf("(");
  }
  printf(")");
}

void StmPrettySTATE_LIST(STATE_LIST *s)
{
  printf("(");
  switch (s->kind) {
  case state_listK:
    StmPrettySTATE_LIST(s->val.state_listS.state_list);
    StmPrettySTATE(s->val.state_listS.state);
    break;
  case emptystate_listK:
    break;
  }
  printf(")\n");
}

void StmPrettySTATE(STATEST *s)
{
  printf("(\n");
  StmPrettyHEAD(s->val.stateS.head);
  StmPrettySTATEMENT_LIST(s->val.stateS.statement_list);
  printf("\n END )");
}

void StmPrettyHEAD(HEAD *h)
{
  printf("(State %s)\n",h->id);
}

void StmPrettySTATEMENT_LIST(STATEMENT_LIST *sl)
{
  printf("\n(");
  switch (sl->kind) {
  case slK:
    StmPrettySTATEMENT_LIST(sl->val.statement_listS.statement_list);
    StmPrettySTATEMENT(sl->val.statement_listS.statement);
    break;
  case emptyslK:
    break;
  }
  printf(")");
}

void StmPrettySTATEMENT(STATEMENT *s)
{
  printf("\n(");
  switch (s->kind) {
  case printK:
    printf("PRINT ");
    StmPrettyEXP(s->val.printS.exp);
    break;
  case setK:
    printf("SET %s ",s->val.setS.id);
    StmPrettyEXP(s->val.setS.exp);
    break;
  case testK:
    printf("TEST ");
    StmPrettyEXP(s->val.testS.exp);
    StmPrettySTATEMENT_LIST(s->val.testS.statement_list);
    StmPrettyOPT_ET_LIST(s->val.testS.opt_et_list);
    StmPrettyOPT_ELSE(s->val.testS.opt_else);
    printf("ENDTEST");
    break;
  case setstateK:
    printf("SETSTATE %s",s->val.setstateS.id);
    break;
  case timeoutK:
    printf("TIMEOUT %s %s ",s->val.timeoutS.idtime,s->val.timeoutS.id_gotostate);
    StmPrettyOPT_TIMERSTATE(s->val.timeoutS.opt_timerstate);
    break;
  case assignmentK:
    printf("%s = ",s->val.assignmentS.id);
    StmPrettyEXP(s->val.assignmentS.exp);
    break;
  case plusassignK:
    printf("%s += ",s->val.plusassignS.id);
    StmPrettyEXP(s->val.plusassignS.exp);
    break;
  case minusassignK:
    printf("%s -= ",s->val.minusassignS.id);
    StmPrettyEXP(s->val.minusassignS.exp);
    break;
  case plusplusK:
    printf("%s++",s->val.plusplusS.id);
    break;
  }
  printf(")");
}

void StmPrettyOPT_TIMERSTATE(OPT_TIMERSTATE *o)
{
  printf("(");
  if (o->kind == otsK) printf(": %s",o->val.id);
  printf(")");
}

void StmPrettyOPT_ET_LIST(OPT_ET_LIST *o)
{
  printf("(\n");
  if (o->kind == oelK) {
    StmPrettyOPT_ET_LIST(o->val.oelO.opt_et_list);
    StmPrettyOPT_ELSETEST(o->val.oelO.opt_elsetest);
  }
  printf(")");
}

void StmPrettyOPT_ELSETEST(OPT_ELSETEST *o)
{
  printf("( ELSETEST ");
  StmPrettyEXP(o->val.elsetestO.exp);
  StmPrettySTATEMENT_LIST(o->val.elsetestO.statement_list);
  printf(")\n");
}

void StmPrettyOPT_ELSE(OPT_ELSE *o)
{
  printf("(");
  if (o->kind == elseK) {
    printf("ELSE ");
    StmPrettySTATEMENT_LIST(o->val.statementlO.statement_list);
  }
  printf(")\n");
}

void StmPrettyTERM(TERM *t) {
  printf("("); 
  switch(t->kind) {
  case parK:
    StmPrettyEXP(t->val.parT.exp);
    break;    
  case notK:
    printf("! ");  
    StmPrettyTERM(t->val.notT.term);
    break;
  case numK:
    printf("%i",t->val.numT);
    break;
    /*  case floatK:
    printf("%f",t->val.floatT);
    break; */
  case idK:
    printf("%s",t->val.id);
    break;    
  }
  printf(")"); 
}

void StmPrettyEXP(EXP* e) { 
 printf("(");
 switch(e->kind) {
  case termK:
    StmPrettyTERM(e->val.termE.term);
    break;
  case orK:
    StmPrettyEXP(e->val.orE.left);
    printf("OR");
    StmPrettyEXP(e->val.orE.right);
    break;
  case andK:
    StmPrettyEXP(e->val.andE.left);
    printf("AND");
    StmPrettyEXP(e->val.andE.right);
    break;
  case plusK:
    StmPrettyEXP(e->val.plusE.left);
    printf("+");
    StmPrettyEXP(e->val.plusE.right);
    break;
  case minusK:
    StmPrettyEXP(e->val.minusE.left);
    printf("-");
    StmPrettyEXP(e->val.minusE.right);
    break;
  case timesK:
    StmPrettyEXP(e->val.timesE.left);
    printf("*");
    StmPrettyEXP(e->val.timesE.right);
    break;
  case divK:
    StmPrettyEXP(e->val.divE.left);
    printf("/");
    StmPrettyEXP(e->val.divE.right);
    break;
  case equalK:
    StmPrettyEXP(e->val.equalE.left);
    printf("==");
    StmPrettyEXP(e->val.equalE.right);
    break;
  case not_equalK:
    StmPrettyEXP(e->val.not_equalE.left);
    printf("!=");
    StmPrettyEXP(e->val.not_equalE.right);
    break;
  case larger_thanK:
    StmPrettyEXP(e->val.larger_thanE.left);
    printf(">");
    StmPrettyEXP(e->val.larger_thanE.right);
    break;
  case larger_than_equalK:
    StmPrettyEXP(e->val.larger_than_equalE.left);
    printf(">=");
    StmPrettyEXP(e->val.larger_than_equalE.right);
    break;
  case smaller_thanK:
    StmPrettyEXP(e->val.smaller_thanE.left);
    printf("<");
    StmPrettyEXP(e->val.smaller_thanE.right);
    break;
  case smaller_than_equalK:
    StmPrettyEXP(e->val.smaller_than_equalE.left);
    printf("<=");
    StmPrettyEXP(e->val.smaller_than_equalE.right);
    break;
  }
 // printf(" $type:%s$ ",PrintType(e->type));
 printf(")"); 
}

char *PrintType(int kind) {
  char *str;
  str = (char*)malloc(50*sizeof(char));
  if (str==NULL) {
    printf("Out of heap-space in StmPrettyprinter\n");
    exit(0);
  }
  switch (kind) {
  case INPUTK:
    snprintf(str,50," Input");
    break;
  case OUTPUTK:
    snprintf(str,50," Output");
    break;
  case TIMEK:
    snprintf(str,50," Time");
    break;
  case STMK:
    snprintf(str,50," Stm (Link)");
    break;
  case VALUEK:
    snprintf(str,50," Value");
    break;
  case INTK:
    snprintf(str,50," int");
    break;
    /*  case FLOATK:
    snprintf(str,50," float");
    break; */
  case STATEK:
    snprintf(str,50," State");
    break;
  }
  return str;
}
