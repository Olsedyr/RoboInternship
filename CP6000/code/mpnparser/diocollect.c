#include <string.h>
#include "diotree.h"
#include "symbol.h"
#include "diocollect.h"

extern DioTable* theDioTable;
DioTable* theModuleTable;
char *currentModuleName;
int currentModule=0;
int currentType=-1;
int currentKind=-1;

void collectDIO(DIO *d)
{
  theModuleTable = initDioTable();
  currentModuleName=NULL;
  currentModule=0;
  currentType=-1;
  currentKind=-1;
  collectNUMMOD(d->val.dio.nummod);
  if (d->val.dio.modlist->kind == modlistK)
  {
    collectMODLIST(d->val.dio.modlist);
  }
  killDioTable(theModuleTable);
}

void collectNUMMOD(NUMMODST *nm)
{
  theDioTable->numOfModules = nm->numM;
}

void collectMODLIST(MODLIST *ml)
{
  if (ml->val.modlistM.modlist->kind == modlistK)
  {
    collectMODLIST(ml->val.modlistM.modlist);
  }
  collectMODULE(ml->val.modlistM.module);
}

void collectMODULE(MODULE *m)
{
  currentModuleName = m->val.moduleM.nameid;
  DIOSYM *SB=NULL;
  /* Be sure there are no duplicate modulenames: */
  SB = putDioSym(theModuleTable, 0, currentModuleName, NULL, 0, NULL, 0, 0, 0);
  if (SB == NULL) {
    printf("quitting.\n");
    exit(0);
  }
  char *typeid=m->val.moduleM.typeid;
  if (!strcmp(typeid,"STB3600DDO")) 
  {
    currentKind = DIOOUTK;
    currentType = STBDDO3600;
  }
  else if (!strcmp(typeid,"EPI2145"))
  {
    currentKind = DIOOUTK;
    currentType = STBEPI2145;
  }
  else if (!strcmp(typeid,"STB3610DDI")) 
  {
    currentKind = DIOINK;
    currentType = STBDDI3610;
  }
    
  if (m->val.moduleM.connectlist->kind == connectlistK)
  {
    collectCONNECTLIST(m->val.moduleM.connectlist);
  }
  currentModule++;
}

void collectCONNECTLIST(CONNECTLIST *connectlist)
{
  if (connectlist->val.connectorL.connectlist->kind == connectlistK) {
    collectCONNECTLIST(connectlist->val.connectorL.connectlist);
  }
  collectCONNECTOR(connectlist->val.connectorL.connector);
}

void collectCONNECTOR(CONNECTOR *connector)
{
  int f;
  DIOSYM *SB=NULL;
  if (connector->kind==connectorK) {
    f = collectOPT_FLIP(connector->val.connectorC.opt_flip);
    SB = putDioSym(theDioTable, currentKind, connector->val.connectorC.id, connector->val.connectorC.comment, currentType, currentModuleName, currentModule, connector->val.connectorC.num,f);
    if (SB == NULL) {
      printf("quitting.\n");
      exit(0);
    }
  }
}

int collectOPT_FLIP(OPT_FLIP *opt_flip)
{
  if (opt_flip->kind==opt_flipK) return 1;
  return 0;
}
