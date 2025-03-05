#include <string.h>
#include "stmtree.h"
#include "symbol.h"
#include "stmtypecheck.h"

extern StmTable* theStmTable;
SymbolTable* currentSymbolTable;
int typecheckerr=0;

void StmTypecheckSTATEMACHINE(STATEMACHINE *s)
{
  typecheckerr=0;
  //StmTypecheckVERSION(s->val.stm.version);
  StmTypecheckNAME(s->val.stm.name);
  StmTypecheckDECL_LIST(s->val.stm.decl_list);
  StmTypecheckSTATE_LIST(s->val.stm.state_list);
  if (typecheckerr)
  {
    printf("Found %i errors during typecheck. Quitting.\n",typecheckerr);
    exit(0);
  }
}

void StmTypecheckVERSION(VERSST *v)
{
}

void StmTypecheckNAME(NAMEST *n)
{
  currentSymbolTable = getSymbolTable(theStmTable, n->val.id);
  if (currentSymbolTable==NULL) {
    typecheckerr++;
  }
}

void StmTypecheckDECL_LIST(DECL_LIST *d)
{
  if (d->kind == decl_listK) {
    StmTypecheckDECL_LIST(d->val.decl_listD.decl_list);
    StmTypecheckDECLARATION(d->val.decl_listD.declaration);
  }
}

void StmTypecheckDECLARATION(DECLARATION *d)
{
  int tyKind;
  SYMBOL *SB;
  SymbolTable *ST;
  switch(d->kind) {
  case inputK:
    StmTypecheckOPT_FILTER(d->val.inputD.opt_filter);
    //StmTypecheckOPT_SIM(d->val.inputD.opt_sim);
    break;
  case outputK:
    break;
  case linkK:
    ST = getSymbolTable(theStmTable, d->val.linkD.id);
    if ((ST==NULL)||(ST==currentSymbolTable)) 
    {
      printf("Link %s not found among the other statemachines. At line %i\n",d->val.linkD.id,d->lineno);
      typecheckerr++;
      printf("quitting.\n");
      exit(0);
    }
    break;
  case timeK:
    tyKind = StmTypecheckEXP(d->val.timeD.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)) 
    {
      printf("Non-integer initialization for time-value at line %i\n",d->val.timeD.exp->lineno);
      typecheckerr++;
    }
    break;
  case valueK:
    if (d->val.valueD.opt_from != NULL) 
    {
      SB = getSymbol(currentSymbolTable, d->val.valueD.opt_from->val.id);
      if ((SB==NULL)||(SB->kind!=STMK)) 
      {
	printf("Link %s unknown in from-declaration at line %i\n",d->val.valueD.opt_from->val.id,d->val.valueD.opt_from->lineno);
	typecheckerr++;
	break;
      }
      ST = getSymbolTable(theStmTable, d->val.valueD.opt_from->val.id);
      if (ST==NULL) break;
      SB = getSymbol(ST, d->val.valueD.id);
      if ((SB==NULL)||(SB->kind!=VALUEK)) 
      {
	printf("Value %s not found in statemachine %s. Before line %i\n",d->val.valueD.id,d->val.valueD.opt_from->val.id,d->lineno);
	typecheckerr++;
      }
    }
    else if (d->val.valueD.exp != NULL)
    {
      tyKind = StmTypecheckEXP(d->val.valueD.exp)->type;
      if (tyKind!=tyINTK) 
      {
	printf("Non-integer initialization for Value at line %i\n",d->val.valueD.exp->lineno);
	typecheckerr++;
      }
    }
    break;
  case delaystopK:
    tyKind = StmTypecheckEXP(d->val.delaystopD.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)) 
    {
      printf("Non-integer initialization for Delaystop at line %i\n",d->val.delaystopD.exp->lineno);
      typecheckerr++;
    }
  }
}

void StmTypecheckOPT_FILTER(OPT_FILTER *o)
{
 int tyKind1;
 int tyKind2;
  if (o->kind == filterK) {
    tyKind1 = StmTypecheckEXP(o->val.filterF.ontime)->type;
    tyKind2 = StmTypecheckEXP(o->val.filterF.offtime)->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)) {
      printf("Non-integer initialization for filter onvalue at line %i\n",o->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)) {
      printf("Non-integer initialization for filter offvalue at line %i\n",o->lineno);
      typecheckerr++;
    }
  }
}

void StmTypecheckSTATE_LIST(STATE_LIST *s)
{
  if (s->kind == state_listK) 
  {
    StmTypecheckSTATE_LIST(s->val.state_listS.state_list);
    StmTypecheckSTATE(s->val.state_listS.state);
  }
}

void StmTypecheckSTATE(STATEST *s)
{
  //StmTypecheckHEAD(s->val.stateS.head);
  StmTypecheckSTATEMENT_LIST(s->val.stateS.statement_list);
}

void StmTypecheckHEAD(HEAD *h)
{
  //printf("(State %s)\n",h->id);
}

void StmTypecheckSTATEMENT_LIST(STATEMENT_LIST *sl)
{
  if (sl->kind == slK) {
    StmTypecheckSTATEMENT_LIST(sl->val.statement_listS.statement_list);
    StmTypecheckSTATEMENT(sl->val.statement_listS.statement);
  }
}

void StmTypecheckSTATEMENT(STATEMENT *s)
{
  SYMBOL *SB;
  int tyKind;
  switch (s->kind) {
  case printK:
    StmTypecheckEXP(s->val.printS.exp);
    break;
  case setK:
    SB = getSymbol(currentSymbolTable, s->val.setS.id);
    if ((SB==NULL)||(SB->kind!=OUTPUTK)) {
      printf("The output-identifier %s in SET-statement not found. Before line %i\n", s->val.setS.id, s->lineno);
      typecheckerr++;
    }
    tyKind = StmTypecheckEXP(s->val.setS.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)) {
      printf("Wrong type expression (non-integer) in SET-statement. Before line %i\n", s->lineno);
      typecheckerr++;
    }
    break;
  case testK:
    tyKind = StmTypecheckEXP(s->val.testS.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)&&(tyKind!=tyINPUTK)&&(tyKind!=tyTIMEK)) {
      printf("Wrong type expression (not value/integer/input or timevalue) in TEST-statement. At line %i\n", s->val.testS.exp->lineno);
      typecheckerr++;
    }
    StmTypecheckSTATEMENT_LIST(s->val.testS.statement_list);
    StmTypecheckOPT_ET_LIST(s->val.testS.opt_et_list);
    StmTypecheckOPT_ELSE(s->val.testS.opt_else);
    break;
  case setstateK:
    SB = getSymbol(currentSymbolTable, s->val.setstateS.id);
    if ((SB==NULL)||(SB->kind!=STATEK)) {
      printf("The State-identifier %s in SETSTATE-statement not found. At line %i\n", s->val.setstateS.id, s->lineno);
      typecheckerr++;
    }
    break;
  case timeoutK:
    SB = getSymbol(currentSymbolTable, s->val.timeoutS.idtime);
    if ((SB==NULL)||(SB->kind!=TIMEK)) {
      printf("The Time-identifier %s in TIMEOUT-statement not found. Before line %i\n", s->val.timeoutS.idtime, s->lineno);
      typecheckerr++;
    }
    SB = getSymbol(currentSymbolTable, s->val.timeoutS.id_gotostate);
    if ((SB==NULL)||(SB->kind!=STATEK)) {
      printf("The State-identifier %s in TIMEOUT-statement not found. Before line %i\n", s->val.timeoutS.id_gotostate, s->lineno);
      typecheckerr++;
    }
    StmTypecheckOPT_TIMERSTATE(s->val.timeoutS.opt_timerstate);
    break;
  case assignmentK:
    SB = getSymbol(currentSymbolTable, s->val.assignmentS.id);
    if ((SB==NULL)||(SB->kind!=VALUEK)) {
      printf("The Value-identifier %s in assignment-statement not found. Before line %i\n",s->val.assignmentS.id, s->lineno);
      typecheckerr++;
    }
    tyKind = StmTypecheckEXP(s->val.assignmentS.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)&&(tyKind!=tyINPUTK)) {
      printf("Wrong type expression (non-integer) in assignment-statement. At line %i\n", s->val.assignmentS.exp->lineno);
      typecheckerr++;
    }
    break;
  case plusassignK:
    SB = getSymbol(currentSymbolTable, s->val.plusassignS.id);
    if ((SB==NULL)||(SB->kind!=VALUEK)) {
      printf("The Value-identifier %s in plusassign-statement not found. Before line %i\n",s->val.plusassignS.id, s->lineno);
      typecheckerr++;
    }
    tyKind = StmTypecheckEXP(s->val.plusassignS.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)&&(tyKind!=tyINPUTK)) {
      printf("Wrong type expression (non-integer) in plusassign-statement. At line %i\n", s->val.plusassignS.exp->lineno);
      typecheckerr++;
    }
    break;
  case minusassignK:
    SB = getSymbol(currentSymbolTable, s->val.minusassignS.id);
    if ((SB==NULL)||(SB->kind!=VALUEK)) {
      printf("The Value-identifier %s in minusassign-statement not found. Before line %i\n",s->val.minusassignS.id, s->lineno);
      typecheckerr++;
    }
    tyKind = StmTypecheckEXP(s->val.minusassignS.exp)->type;
    if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)&&(tyKind!=tyINPUTK)) {
      printf("Wrong type expression (non-integer) in minusassign-statement. At line %i\n", s->val.minusassignS.exp->lineno);
      typecheckerr++;
    }
    break;
  case plusplusK:
    SB = getSymbol(currentSymbolTable, s->val.plusplusS.id);
    if ((SB==NULL)||(SB->kind!=VALUEK)) {
      printf("The Value-identifier %s in increment-statement not found. Before line %i\n",s->val.plusplusS.id, s->lineno);
      typecheckerr++;
    }
  }
}

void StmTypecheckOPT_TIMERSTATE(OPT_TIMERSTATE *o)
{
  SYMBOL *SB;
  if (o->kind == otsK)
  { 
    SB = getSymbol(currentSymbolTable, o->val.id);
    if ((SB==NULL)||(SB->kind!=STATEK)) {
      printf("The State-identifier %s in TIMEOUT-statement (optional timerstate) not found. Before line %i\n", o->val.id, o->lineno);
      typecheckerr++;
    }
  }
}

void StmTypecheckOPT_ET_LIST(OPT_ET_LIST *o)
{
  if (o->kind == oelK) {
    StmTypecheckOPT_ET_LIST(o->val.oelO.opt_et_list);
    StmTypecheckOPT_ELSETEST(o->val.oelO.opt_elsetest);
  }
}

void StmTypecheckOPT_ELSETEST(OPT_ELSETEST *o)
{
  int tyKind;
  tyKind = StmTypecheckEXP(o->val.elsetestO.exp)->type;
  if ((tyKind!=tyINTK)&&(tyKind!=tyVALUEK)&&(tyKind!=tyINPUTK)&&(tyKind!=tyTIMEK)) {
    printf("Wrong type expression (not value/integer/input or timevalue) in ELSETEST-statement. At line %i\n", o->val.elsetestO.exp->lineno);
    typecheckerr++;
  }
  StmTypecheckSTATEMENT_LIST(o->val.elsetestO.statement_list);
}

void StmTypecheckOPT_ELSE(OPT_ELSE *o)
{
  if (o->kind == elseK) {
    StmTypecheckSTATEMENT_LIST(o->val.statementlO.statement_list);
  }
}

TY *StmTypecheckTERM(TERM *t) {
  TY *curtype=NULL;
  TY *rettype;
  SYMBOL *SB;
  rettype = NEW(TY);
  rettype->id=NULL;
  switch(t->kind) {
  case parK:
    curtype = StmTypecheckEXP(t->val.parT.exp);
    if (curtype->id!=NULL) rettype->id = curtype->id;
    rettype->type=curtype->type;
    break;
  case notK:
    curtype = StmTypecheckTERM(t->val.notT.term);
    if ((curtype->type!=tyINTK)&&(curtype->type!=tyVALUEK)&&(curtype->type!=tyINPUTK))
    {
      printf("Not-expression on wrong-type (non-integer) before line %i\n",t->lineno);
      typecheckerr++;
    }
    rettype->type=tyINTK;
    break;
  case numK:
    rettype->type=tyINTK;
    break;
  case idK:
    SB = getSymbol(currentSymbolTable, t->val.id);
    rettype->id = t->val.id;
    if (SB==NULL) 
    {
      printf("Symbol %s not found. At line %i\n",t->val.id,t->lineno);
      typecheckerr++;
      break;
    }
    switch (SB->kind) {
    case INPUTK:
      rettype->type = tyINPUTK;
      break;
    case OUTPUTK:
      rettype->type = tyOUTPUTK;
      break;
    case TIMEK:
      rettype->type = tyTIMEK;
      break;    
    case STMK:
      rettype->type = tySTMK;
      break;    
    case STATEK:
      rettype->type = tySTATEK;
      break;  
    case VALUEK:
      rettype->type = tyVALUEK;
      break;  
    case INTK:
      rettype->type = tyINTK;
    }
  }
  if (curtype!=NULL) free(curtype);
  return rettype;
}

TY *StmTypecheckEXP(EXP* e) { 
  int tyKind1;
  int tyKind2;
  SymbolTable *tempST;
  SYMBOL *tempSB;
  TY *curtype1=NULL;
  TY *curtype2=NULL;
  TY *rettype;
  rettype = NEW(TY);
  rettype->id=NULL;
  switch(e->kind) {
  case termK:
    curtype1 = StmTypecheckTERM(e->val.termE.term);
    rettype->type = curtype1->type;
    if (curtype1->id!=NULL) rettype->id = curtype1->id;
    break;
  case orK:
    curtype1 = StmTypecheckEXP(e->val.orE.left);
    curtype2 = StmTypecheckEXP(e->val.orE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of OR-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    else if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of OR-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case andK:
    curtype1 = StmTypecheckEXP(e->val.andE.left);
    curtype2 = StmTypecheckEXP(e->val.andE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of AND-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of AND-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case plusK:
    curtype1 = StmTypecheckEXP(e->val.plusE.left);
    curtype2 = StmTypecheckEXP(e->val.plusE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of PLUS-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of PLUS-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case minusK:
    curtype1 = StmTypecheckEXP(e->val.minusE.left);
    curtype2 = StmTypecheckEXP(e->val.minusE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of MINUS-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of MINUS-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case timesK:
    curtype1 =StmTypecheckEXP(e->val.timesE.left);
    curtype2 =StmTypecheckEXP(e->val.timesE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of TIMES-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of TIMES-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case divK:
    curtype1 = StmTypecheckEXP(e->val.divE.left);
    curtype2 = StmTypecheckEXP(e->val.divE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of DIV-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of DIV-expression before line %i\n",e->lineno);
      typecheckerr++;
    }
    rettype->type = tyINTK;
    break;
  case equalK:
    curtype1 = StmTypecheckEXP(e->val.equalE.left);
    curtype2 = StmTypecheckEXP(e->val.equalE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if (tyKind1==tySTMK) {
      if (curtype1->id!=NULL)
      {
	if (curtype2->id!=NULL)	
	{
	  tempST = getSymbolTable(theStmTable, curtype1->id);
	  if (tempST==NULL) 
	  {
	    printf("Statemachine %s not found. Equal-comparison before line %i\n",curtype1->id,e->lineno);
	    typecheckerr++;
	  }
	  else
	  {
	    tempSB = getSymbol(tempST,curtype2->id);
	    if (tempSB==NULL) 
	    {
	      printf("State %s in statemachine %s not found. Equal-comparion before line %i\n",curtype2->id,curtype1->id,e->lineno);
	      typecheckerr++;
	    }
	  }
	}
	else
	{
	  printf("Wrong type in equal-comparison at line %i\n",e->lineno);
	  typecheckerr++;
	}
      }
      else
      {
	printf("Wrong type in equal-comparison at line %i\n",e->lineno);
	typecheckerr++;
      }
    }
    else {
      if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
      {
	printf("Wrong type (non-integer) in leftside of equal-comparison before line %i\n",e->lineno);
	typecheckerr++;
      }
      if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
      {
	printf("Wrong type (non-integer) in rightside of equal-comparison before line %i\n",e->lineno);
	typecheckerr++; 
      }
    }
    rettype->type = tyINTK;
    break;
  case not_equalK:
    curtype1 = StmTypecheckEXP(e->val.not_equalE.left);
    curtype2 = StmTypecheckEXP(e->val.not_equalE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if (tyKind1==tySTMK) {
      if (curtype1->id!=NULL)
      {
	if (curtype2->id!=NULL)	
	{
	  tempST = getSymbolTable(theStmTable, curtype1->id);
	  if (tempST==NULL) 
	  {
	    printf("Statemachine %s not found. Notequal-comparison before line %i\n",curtype1->id,e->lineno);
	    typecheckerr++;
	  }
	  else
	  {
	    tempSB = getSymbol(tempST,curtype2->id);
	    if (tempSB==NULL) 
	    {
	      printf("State %s in statemachine %s not found. Notequal-comparion at line %i\n",curtype2->id,curtype1->id,e->lineno);
	      typecheckerr++;
	    }
	  }
	}
	else
	{
	  printf("Wrong type in notequal-comparison at line %i\n",e->lineno);
	  typecheckerr++;
	}
      }
      else
      {
	printf("Wrong type in notequal-comparison at line %i\n",e->lineno);
	typecheckerr++;
      }
    }
    else {
      if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
      {
	printf("Wrong type (non-integer) in leftside of notequal-comparison before line %i\n",e->lineno);
	typecheckerr++;   
      }
      if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
      {
	printf("Wrong type (non-integer) in rightside of notequal-comparison before line %i\n",e->lineno);
	typecheckerr++;    
      }
    }
    rettype->type = tyINTK;
    break;
  case larger_thanK:
    curtype1 = StmTypecheckEXP(e->val.larger_thanE.left);
    curtype2 = StmTypecheckEXP(e->val.larger_thanE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of largerthan-comparison before line %i\n",e->lineno);
      typecheckerr++;    
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of largerthan-comparison before line %i\n",e->lineno);
      typecheckerr++;       
    }
    rettype->type = tyINTK;
    break;
  case larger_than_equalK:
    curtype1 = StmTypecheckEXP(e->val.larger_than_equalE.left);
    curtype2 = StmTypecheckEXP(e->val.larger_than_equalE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of largerthan-equal-comparison before line %i\n",e->lineno);
      typecheckerr++;        
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of largerthan-equal-comparison before line %i\n",e->lineno);
      typecheckerr++;        
    }
    rettype->type = tyINTK;
    break;
  case smaller_thanK:
    curtype1 = StmTypecheckEXP(e->val.smaller_thanE.left);
    curtype2 = StmTypecheckEXP(e->val.smaller_thanE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of smallerthan-comparison before line %i\n",e->lineno);
      typecheckerr++;  
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of smallerthan-comparison before line %i\n",e->lineno);
      typecheckerr++;  
    }
    rettype->type = tyINTK;
    break;
  case smaller_than_equalK:
    curtype1 = StmTypecheckEXP(e->val.smaller_than_equalE.left);
    curtype2 = StmTypecheckEXP(e->val.smaller_than_equalE.right);
    tyKind1 = curtype1->type;
    tyKind2 = curtype2->type;
    if ((tyKind1!=tyINTK)&&(tyKind1!=tyVALUEK)&&(tyKind1!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in leftside of smallerthan-equal-comparison before line %i\n",e->lineno);
      typecheckerr++;  
    }
    if ((tyKind2!=tyINTK)&&(tyKind2!=tyVALUEK)&&(tyKind2!=tyINPUTK))
    {
      printf("Wrong type (non-integer) in rightside of smallerthan-equal-comparison before line %i\n",e->lineno);
      typecheckerr++;  
    }
    rettype->type = tyINTK;
  }
  if (curtype1!=NULL) free(curtype1);
  if (curtype2!=NULL) free(curtype2);
  return rettype;
}

