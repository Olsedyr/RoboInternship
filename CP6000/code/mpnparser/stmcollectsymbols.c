#include <string.h>
#include "symbol.h"
#include "stmtree.h"
#include "stmcollectsymbols.h"

extern StmTable* theStmTable;
extern DioTable* theDioTable;

SymbolTable* currentSymbolTable;

void StmCollectSTATEMACHINE(STATEMACHINE *s)
{
  currentSymbolTable = NULL;
  StmCollectVERSION(s->val.stm.version);
  StmCollectNAME(s->val.stm.name);
  StmCollectDECL_LIST(s->val.stm.decl_list);
  StmCollectSTATE_LIST(s->val.stm.state_list);
}

void StmCollectVERSION(VERSST *v)
{
}

void StmCollectNAME(NAMEST *n)
{
  currentSymbolTable = addSymbolTable(theStmTable, n->val.id);
  if (currentSymbolTable==NULL) {
    printf("quitting.\n");
    exit(0);
  }
}

void StmCollectDECL_LIST(DECL_LIST *d)
{
  switch(d->kind) {
  case decl_listK:
    StmCollectDECL_LIST(d->val.decl_listD.decl_list);
    StmCollectDECLARATION(d->val.decl_listD.declaration);
    break;
  case emptydlK:
    break;
  } 
}

void  StmCollectDECLARATION(DECLARATION *d)
{
  SYMBOL* SB;
  DIOSYM* DS;
  switch(d->kind) {
  case inputK: 
    SB = putSymbol(currentSymbolTable, d->val.inputD.id1, INPUTK);
    if (SB==NULL) {
      printf("quitting.\n");
      exit(0);
    }
    DS = getDioSym(theDioTable, d->val.inputD.id2);
    if ((DS==NULL)||(DS->kind != DIOINK)) {
      printf("Input identifier \"%s\" not found in dio-file.\n",d->val.inputD.id2);
      printf("quitting.\n");
      exit(0);
    }
    break;
  case outputK:
    SB = putSymbol(currentSymbolTable, d->val.outputD.id1, OUTPUTK);
    if (SB==NULL) 
    {
      printf("quitting.\n");
      exit(0);
    }
    DS = getDioSym(theDioTable, d->val.outputD.id2);
    if ((DS==NULL)||(DS->kind != DIOOUTK)) 
    {
      printf("Output identifier \"%s\" not found in dio-file.\n",d->val.outputD.id2);
      printf("quitting.\n");
      exit(0);
    }
    break;
  case linkK:
    SB = putSymbol(currentSymbolTable, d->val.linkD.id, STMK);
    if (SB==NULL) {
      printf("quitting.\n");
      exit(0);
    }
    //under typecheck: getSymbolTable(theStmTable, d->val.linkD.id) og getSYMBOL: tjek STMK; 
    break;
  case timeK:
    SB = putSymbol(currentSymbolTable, d->val.timeD.id, TIMEK);
    if (SB==NULL) {
      printf("quitting.\n");
      exit(0);
    }
    break;
  case valueK:
    SB = putSymbol(currentSymbolTable, d->val.valueD.id, VALUEK);
    if (SB==NULL) {
      printf("quitting.\n");
      exit(0);
    }
  }
}

void StmCollectSTATE_LIST(STATE_LIST *s)
{
  switch (s->kind) {
  case state_listK:
    StmCollectSTATE_LIST(s->val.state_listS.state_list);
    StmCollectSTATE(s->val.state_listS.state);
    break;
  case emptystate_listK:
    break;
  }
}

void StmCollectSTATE(STATEST *s)
{
  StmCollectHEAD(s->val.stateS.head);
}

void StmCollectHEAD(HEAD *h)
{
  SYMBOL* SB;
  SB = putSymbol(currentSymbolTable, h->id, STATEK);
  if (SB==NULL) {
    printf("quitting.\n");
    exit(0);
  }
}

