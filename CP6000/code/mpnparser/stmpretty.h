#ifndef __stmpretty_h
#define __stmpretty_h

void StmPrettyPrinter(STATEMACHINE *s);
void StmPrettySTATEMACHINE(STATEMACHINE *s);
void StmPrettyVERSION(VERSST *v);
void StmPrettyNAME(NAMEST *n);
void StmPrettyDECL_LIST(DECL_LIST *d);
void StmPrettyDECLARATION(DECLARATION *d);
void StmPrettyOPT_FILTER(OPT_FILTER *o);
void StmPrettyOPT_SIM(OPT_SIM *o);
void StmPrettyOPT_FROM(OPT_FROM *o);
void StmPrettySTATE_LIST(STATE_LIST *s);
void StmPrettySTATE(STATEST *s);
void StmPrettyHEAD(HEAD *h);
void StmPrettySTATEMENT_LIST(STATEMENT_LIST *sl);
void StmPrettySTATEMENT(STATEMENT *s);
void StmPrettyOPT_TIMERSTATE(OPT_TIMERSTATE *o);
void StmPrettyOPT_ET_LIST(OPT_ET_LIST *o);
void StmPrettyOPT_ELSETEST(OPT_ELSETEST *o);
void StmPrettyOPT_ELSE(OPT_ELSE *o);
void StmPrettyTERM(TERM *t);
void StmPrettyEXP(EXP *e);
char *PrintType(int kind);

#endif /* __stmpretty_h */
