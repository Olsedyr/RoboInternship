#ifndef __stmtypecheck_h
#define __stmtypecheck_h

void StmTypecheckSTATEMACHINE(STATEMACHINE *s);
void StmTypecheckVERSION(VERSST *v);
void StmTypecheckNAME(NAMEST *n);
void StmTypecheckDECL_LIST(DECL_LIST *d);
void StmTypecheckDECLARATION(DECLARATION *d);
void StmTypecheckOPT_FILTER(OPT_FILTER *o);
//void StmTypecheckOPT_SIM(OPT_SIM *o);
//void StmTypecheckOPT_FROM(OPT_FROM *o);
void StmTypecheckSTATE_LIST(STATE_LIST *s);
void StmTypecheckSTATE(STATEST *s);
void StmTypecheckHEAD(HEAD *h);
void StmTypecheckSTATEMENT_LIST(STATEMENT_LIST *sl);
void StmTypecheckSTATEMENT(STATEMENT *s);
void StmTypecheckOPT_TIMERSTATE(OPT_TIMERSTATE *o);
void StmTypecheckOPT_ET_LIST(OPT_ET_LIST *o);
void StmTypecheckOPT_ELSETEST(OPT_ELSETEST *o);
void StmTypecheckOPT_ELSE(OPT_ELSE *o);
TY *StmTypecheckTERM(TERM *t);
TY *StmTypecheckEXP(EXP *e);

#endif /* __stmtypecheck_h  */
