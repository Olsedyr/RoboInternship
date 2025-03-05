
#ifndef __dioweed_h
#define __dioweed_h

void weedDIO(DIO *d);
int weedNUMMOD(NUMMODST *nm);
void weedMODLIST(MODLIST *ml);
void weedMODULE(MODULE *m);
int weedCONNECTLIST(CONNECTLIST *connectlist);
int weedCONNECTOR(CONNECTOR *connector);
void weedOPT_FLIP(OPT_FLIP *opt_flip);

#endif /* dioweed_h */
