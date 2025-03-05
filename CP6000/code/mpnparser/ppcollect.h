
#ifndef __ppcollect_h
#define __ppcollect_h

void collectPP(PPSTRUCT *pp);
void collectMOVE_LIST(MOVE_LIST *ml);
void collectMOVEDEC(MOVEDEC *m);
void collectFRAME(FRAME *fr);
void collectVIA(VIAP *v);
void collectSTARTMACRO(STARTMACRO *s);
void collectENDMACRO(ENDMACRO *e);
void collectOPT_WITH(OPT_WITH *o);
void collectPARAMLIST(PARAMLIST *pl);
void collectPARAM(PARAM *p);
void collectSIXNUMS(SIXNUMS* f);

#endif /* ppcollect_h */
