
#ifndef __diocollect_h
#define __diocollect_h

void collectDIO();
void collectNUMMOD(NUMMODST *nm);
void collectMODLIST(MODLIST *ml);
void collectMODULE(MODULE *m);
void collectCONNECTLIST(CONNECTLIST *connectlist);
void collectCONNECTOR(CONNECTOR *connector);
int collectOPT_FLIP(OPT_FLIP *opt_flip);

#endif /* diocollect_h */
