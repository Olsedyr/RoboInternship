
#ifndef __ppweed_h
#define __ppweed_h

void weedPP(PPSTRUCT *pp);
void weedMOVE_LIST(MOVE_LIST *ml);
void weedMOVEDEC(MOVEDEC *m);
void weedFRAME(FRAME *fr);
void weedVIA(VIAP *v);
void weedSTARTMACRO(STARTMACRO *s);
void weedENDMACRO(ENDMACRO *e);
void weedOPT_WITH(OPT_WITH *o);
void weedPARAMLIST(PARAMLIST *pl);
void weedPARAM(PARAM *p);
void weedSIXNUMS(SIXNUMS* f);

#endif /* ppweed_h */
