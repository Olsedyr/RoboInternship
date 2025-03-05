#ifndef __stmweed_h
#define __stmweed_h


void StmWeedSTATEMACHINE(STATEMACHINE *s);
void StmWeedVERSION(VERSST *v);
void StmWeedNAME(NAMEST *n);
void StmWeedDECL_LIST(DECL_LIST *d);
void StmWeedDECLARATION(DECLARATION *d);
void StmWeedOPT_FILTER(OPT_FILTER *o);
void StmWeedOPT_SIM(OPT_SIM *o);
void StmWeedOPT_FROM(OPT_FROM *o);
void StmWeedSTATE_LIST(STATE_LIST *s);
void StmWeedSTATE(STATEST *s);
void StmWeedHEAD(HEAD *h);
void StmWeedSTATEMENT_LIST(STATEMENT_LIST *sl);
void StmWeedSTATEMENT(STATEMENT *s);
void StmWeedOPT_TIMERSTATE(OPT_TIMERSTATE *o);
void StmWeedOPT_ET_LIST(OPT_ET_LIST *o);
void StmWeedOPT_ELSETEST(OPT_ELSETEST *o);
void StmWeedOPT_ELSE(OPT_ELSE *o);
void StmWeedTERM(TERM *t);
void StmWeedEXP(EXP *e);

#endif /* __stmweed_h */
