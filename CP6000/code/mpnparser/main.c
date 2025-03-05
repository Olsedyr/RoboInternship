#include <stdio.h>
#include "cmd.h"
#include "symbol.h"
#include "stmtree.h"
#include "stmweed.h"
#include "stmcollectsymbols.h"
#include "diotree.h"
#include "dioweed.h"
#include "diocollect.h"
#include "pptree.h"

STATEMACHINE* theStatemachine;
DIO* theDio;
PPSTRUCT *thePP;
StmTable *theStmTable;
DioTable *theDioTable;

int main(int argc,char *argv[]){
  FILE *filearray[MAXSTATEMACHINES];
  char *fnarray[MAXSTATEMACHINES];
  STATEMACHINE *stmarray[MAXSTATEMACHINES];
  extern FILE *dioin;
  extern FILE *stmin;
  extern FILE *ppin;
  char diofn[50];
  char ppfn[50];
  int i=0;
  int j;
  /*******************/
  LoadRSSystemData(&rs_param);
  tmpnSetDatabase(rs_systempath);
  LoadCalibrationParam(&rs_param);
  printf("item[0] %s\n",tworkcell->items.item[0].name);
  /*******************/
  strncpy(diofn,"307.io",50);
  dioin = fopen(diofn, "r" );
  if (dioin!=NULL) {
    printf("Parsing dio-file: %s ...\n",diofn);
    dioparse();
    fclose(dioin);
    printf("Stage 1 done: dio-file succesfully parsed!\n");
    weedDIO(theDio);
    printf("Stage 2 done: dio-file succesfully weeded!\n");
    theDioTable = initDioTable(); 
    collectDIO(theDio);
    printf("Stage 3 done: dio-file succesfully collected!\n");
    dumpDioTable(theDioTable);
  }
  else {
    printf("Couldn't find dio-file: %s\n",diofn);
  }
  /*******************/
  strncpy(ppfn,"307.ppscript",50);
  ppin = fopen(ppfn, "r" );
  if (ppin!=NULL) {
    printf("Parsing pp-file: %s ...\n",ppfn);
    ppparse();
    fclose(ppin);
    printf("Stage 1 done: pp-file succesfully parsed!\n");
    weedPP(thePP);
    printf("Stage 2 done: pp-file succesfully weeded!\n");
    collectPP(thePP);
    printf("Stage 3 done: pp-file succesfully collected!\n");
  }
  else {
    printf("Couldn't find pp-file: %s\n",ppfn);
  }
  /*******************/
  while (1) 
  {
    ++argv; --argc;  // skip over program name 
    if ( argc > 0 ) 
    {
      filearray[i] = fopen( argv[0], "r" );
      fnarray[i] = (char*)malloc(strlen(argv[0])+1);
      strcpy(fnarray[i],argv[0]);
      i++;
      printf("Reading file %i: %s\n",i,argv[0]);
    }
    else break;
  }
  theStmTable = initStmTable(); 
  for (j=0;j<i;j++) {
    if (filearray[j]!=NULL) {
      stmin = filearray[j];
      printf("Parsing statemachine-program: %s ...\n",fnarray[j]);
      stmparse();
      printf("Stage 1 done: Statemachine program succesfully parsed!\n");
      StmWeedSTATEMACHINE(theStatemachine);
      printf("Stage 2 done: Statemachine program succesfully weeded!\n");
      StmCollectSTATEMACHINE(theStatemachine);
      printf("Stage 3 done: Statemachine program succesfully collected!\n");
      stmarray[j]=theStatemachine;
    }
    else 
    {
      printf("Couldn't find file: %s\n",fnarray[j]);
      exit(0);
    } 
  }
  for (j=0;j<i;j++) {
    if (filearray[j]!=NULL) {
      printf("Typechecking statemachine-program: %s ...\n",fnarray[j]);
      theStatemachine = stmarray[j];
      StmTypecheckSTATEMACHINE(theStatemachine);
      printf("Stage 4 done: Statemachine program succesfully typechecked!\n");
      dumpStmTable(theStmTable);
      dumpSymbolTable(getSymbolTable(theStmTable, "Plads5"));
      //StmPrettyPrinter(theStatemachine);
      fclose(filearray[j]);
      free(fnarray[j]);
    }
  }
  return 0;
}
