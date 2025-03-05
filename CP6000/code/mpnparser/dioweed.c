#include "cmd.h"
#include "diotree.h"
#include "dioweed.h"

int dioerr = 0;
int nummodtot = 0;

void weedDIO(DIO *d) 
{
  int numM;
  dioerr=0;
  nummodtot=0;
  numM=weedNUMMOD(d->val.dio.nummod);
  if(d->val.dio.numV!=DIOVERSION) 
  {
    printf("Warning! Wrong dioversion. Syntax must abide to version %i\n",DIOVERSION);
  }
  if (d->val.dio.modlist->kind == modlistK)
  {
    weedMODLIST(d->val.dio.modlist);
  }
  if (nummodtot > numM) 
  {
    printf("Warning: NumOfModules-value (%i) differs from the actual number of modules (%i)\n",numM,nummodtot);
  }
  else if (nummodtot < numM) {
    printf("NumOfModules-value (%i) is greater than the actual number of modules (%i)\n",numM,nummodtot);
    dioerr++;
  }
  if (dioerr) 
  {
    printf("quitting!\n");
    exit(0);
  }
}

int weedNUMMOD(NUMMODST *nm)
{
  return nm->numM;
}

void weedMODLIST(MODLIST *ml)
{
  if (ml->val.modlistM.modlist->kind == modlistK)
  {
    weedMODLIST(ml->val.modlistM.modlist);
  }
  weedMODULE(ml->val.modlistM.module);
}

void weedMODULE(MODULE *m)
{
  int maxcon=0;
  char *typeid=m->val.moduleM.typeid;
  if (m->val.moduleM.connectlist->kind == connectlistK)
  {
    maxcon = weedCONNECTLIST(m->val.moduleM.connectlist);
  }
  if (!strcmp(typeid,"STB3600DDO"))
  {
    if (maxcon>6) 
    {
      if (maxcon==100) maxcon=0;
      printf("Unknown connector (Connect%i) in module %s\n",maxcon,m->val.moduleM.nameid);
      dioerr++;
    } 
  }
  else if (!strcmp(typeid,"EPI2145"))
  {
    if (maxcon>8) 
    {
      if (maxcon==100) maxcon=0;
      printf("Unknown connector (Connect%i) in module %s\n",maxcon,m->val.moduleM.nameid);
      dioerr++;
    } 
  }
  else if (!strcmp(typeid,"STB3610DDI"))
  {
    if (maxcon>6) 
    {
      if (maxcon==100) maxcon=0;
      printf("Unknown connector (Connect%i) in module %s\n",maxcon,m->val.moduleM.nameid);
      dioerr++;
    } 
  }
  else
  {
    printf("Unknown module type (%s) in module %s\n",typeid,m->val.moduleM.nameid);
    dioerr++;
  }
  nummodtot++;
}

int weedCONNECTLIST(CONNECTLIST *connectlist)
{
  int maxcon = 0;
  int tempcon = 0;
  if (connectlist->val.connectorL.connectlist->kind == connectlistK) {
    tempcon = weedCONNECTLIST(connectlist->val.connectorL.connectlist);
    if (tempcon == 0) tempcon=100;
    if (tempcon > maxcon) maxcon = tempcon;
  }
  tempcon = weedCONNECTOR(connectlist->val.connectorL.connector);
  if (tempcon > maxcon) maxcon = tempcon;
  return maxcon;
}

int weedCONNECTOR(CONNECTOR *connector)
{
  weedOPT_FLIP(connector->val.connectorC.opt_flip);
  return connector->val.connectorC.num;
}

void weedOPT_FLIP(OPT_FLIP *opt_flip) 
{
}
