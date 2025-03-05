#ifndef __stmcollectsymbols_h
#define __stmcollectsymbols_h

void StmCollectSTATEMACHINE(STATEMACHINE *s);
void StmCollectVERSION(VERSST *v);
void StmCollectNAME(NAMEST *n);
void StmCollectDECL_LIST(DECL_LIST *d);
void StmCollectDECLARATION(DECLARATION *d);
void StmCollectSTATE_LIST(STATE_LIST *s);
void StmCollectSTATE(STATEST *s);
void StmCollectHEAD(HEAD *h);

#endif /* __stmcollectsymbols_h  */
