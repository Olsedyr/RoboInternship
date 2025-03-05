#include <stdio.h>
#include "symbol.h"


int Hash(char *str) {
  int result = 0;
  while(*str != '\0')
    result = (result << 1) + *str++;
  return abs(result % HashSize);
} 

/*************************/

StmTable *initStmTable() 
{
  StmTable *ST;
  int i = 0;
  ST = NEW(StmTable);
  if(ST == NULL) {
    printf("\n%s","Out of space!!!");
    return NULL;
  }
  for(i = 0; i < HashSize; ++i) {
    ST->table[i]=NULL;
  }
  return ST;
}

SymbolTable *addSymbolTable(StmTable *t, char *name)
{
  SymbolTable *ST, *ST2, *newST;
  int hashValue;
  hashValue = Hash(name);
  ST = t -> table[hashValue];
  if(ST != NULL) {
    ST2 = ST;
    while(ST2 -> next != NULL && (0 != strcmp(ST2 -> name, name)))
      ST2 = ST2 -> next;
    if( strcmp(ST2 -> name, name)==0 ) {
      printf("Duplicate Statemachine Names: %s",name);
      return NULL;
    }
  }
  newST = initSymbolTable();
  if(newST == NULL) {
    printf("%s\n", "Out of space!!!");
    return NULL;
  }
  else {
    newST -> name = name;
    newST -> next = ST;
    t -> table[hashValue] = newST;
    return newST;
  }
}

SymbolTable *getSymbolTable(StmTable *t, char *name)
{
  SymbolTable *ST;
  int hashValue;
  hashValue = Hash(name);
  ST = t -> table[hashValue];
  if(ST != NULL) {
    while(ST -> next != NULL && (0 != strcmp(ST -> name, name)))
      ST = ST -> next;
    if( strcmp(ST -> name, name)== 0 )
      return ST;
  } 
  return NULL;
}

void dumpStmTable(StmTable *t)
{
  SymbolTable *ST;
  int i;
  for(i = 0; i < HashSize; ++i) {
    if(t -> table[i] != NULL) {
      ST = t -> table[i];
      do {
	printf(" (%i: %s) \n",i,ST->name);
	ST = ST -> next;
      }
      while(ST != NULL);
    }
  }
}

/*************************/

SymbolTable *initSymbolTable() 
{
  SymbolTable *ST;
  int i = 0;
  ST = NEW(SymbolTable);
  if(ST == NULL) {
    printf("\n%s","Out of space!!!");
    return NULL;
  }
  for(i = 0; i < HashSize; ++i) {
    ST->table[i]=NULL;
  }
  return ST;
} 
  
SYMBOL *putSymbol(SymbolTable *t, char *name, int kind) {
  SYMBOL *SB, *SB2, *newSB;
  int hashValue;
  hashValue = Hash(name);
  SB = t -> table[hashValue];
  if(SB != NULL) {
    SB2 = SB;
    while(SB2 -> next != NULL && (0 != strcmp(SB2 -> name, name)))
      SB2 = SB2 -> next;
    if(!strcmp(SB2 -> name, name)) {
      printf("Duplicate symbol: %s\n",name);
      return NULL;
    }
  }
  newSB = NEW(SYMBOL);
  if(newSB == NULL) {
    printf("%s\n", "Out of space!!!");
    return NULL;
  }
  else {
    newSB -> name = name;
    newSB -> kind = kind;
    newSB -> next = SB;
    t -> table[hashValue] = newSB;
    return newSB;
  }
}


SYMBOL *getSymbol(SymbolTable *t, char *name) {
  SYMBOL *SB;
  int hashValue;
  hashValue = Hash(name);
  SB = t -> table[hashValue];
  if(SB != NULL) {
    while(SB->next != NULL && (0 != strcmp(SB->name, name)))
      SB = SB->next;
    if(strcmp(SB->name, name)==0)
      return SB;
  } 
  return NULL;
} 

void dumpSymbolTable(SymbolTable *t) {
  SYMBOL *SB;
  int i; 
  printf("***Dumping SymbolTable for Statemachine: %s : ***\n",t->name);
  do {
    for(i = 0; i < HashSize; ++i) {
      if(t -> table[i] != NULL) {
	SB = t -> table[i];
	do {
	  printf("(%s , %s , %i)\n",SB -> name,PrintType(SB -> kind),i);
	  SB = SB -> next;
	}
	while(SB != NULL);
      }
    }
    t = t -> next;
  }
  while(t != NULL);
  printf("***********************************\n");
} 

/**********************************/

DioTable *initDioTable() 
{
  DioTable *DT;
  int i = 0;
  DT = NEW(DioTable);
  if(DT == NULL) {
    printf("\n%s","Out of space!!!");
    return NULL;
  }
  DT->numOfModules = 0;
  for(i = 0; i < HashSize; ++i) {
    DT->table[i]=NULL;
  }
  return DT;
} 

DIOSYM *putDioSym( DioTable *t, int kind, char *name, char *comment, int moduleType, char *moduleName, int moduleNum, int connectNum, int flip) {
  DIOSYM *SB, *SB2, *newSB;
  int hashValue;
  hashValue = Hash(name);
  SB = t -> table[hashValue];
  if(SB != NULL) {
    SB2 = SB;
    while(SB2 -> next != NULL && (0 != strcmp(SB2 -> name, name)))
      SB2 = SB2 -> next;
    if(!strcmp(SB2 -> name, name)) {
      printf("Duplicate symbol: %s\n",name);
      return NULL;
    }
  }
  newSB = NEW(DIOSYM);
  if(newSB == NULL) {
    printf("%s\n", "Out of space!!!");
    return NULL;
  }
  else {
    newSB->name = name;
    newSB->kind = kind;
    newSB->comment = comment;
    newSB->moduleType = moduleType;
    newSB->moduleName = moduleName;
    newSB->moduleNum = moduleNum;
    newSB->connectNum = connectNum;
    newSB->flip = flip;
    newSB->next = SB;
    t -> table[hashValue] = newSB;
    return newSB;
  }
}


DIOSYM *getDioSym(DioTable *t, char *name) {
  DIOSYM *SB;
  int hashValue, notFound = 1;
  hashValue = Hash(name);
  SB = t->table[hashValue];
  if(SB != NULL) {
    while(SB->next != NULL && (0 != strcmp(SB->name, name)))
      SB = SB->next;
    if(strcmp(SB->name, name)==0)
      return SB;
  } 
  return NULL;
} 

void dumpDioTable(DioTable *t) {
  DIOSYM *SB;
  int i; 
  printf("***Dumping DioTable : %i modules ***\n",t->numOfModules);
  for(i = 0; i < HashSize; ++i) {
    if(t -> table[i] != NULL) 
    {
      SB = t -> table[i];
      do {
	if (SB->kind==DIOINK)
	{
	  printf("(name: %s , kind: %s , comment: %s, modtype: %i, modname: %s, modnum: %i, connum: %i, flip: %i, %i)\n",SB->name,"DIOINK",SB->comment,SB->moduleType,SB->moduleName,SB->moduleNum,SB->connectNum,SB->flip,i);
	}
	else if (SB->kind==DIOOUTK)
	{
	  printf("(name: %s , kind: %s , comment: %s, modtype: %i, modname: %s, modnum: %i, connum: %i, flip: %i,%i)\n",SB->name,"DIOOUTK",SB->comment,SB->moduleType,SB->moduleName,SB->moduleNum,SB->connectNum,SB->flip,i);
	}
	SB = SB -> next;
      }
      while(SB != NULL);
    }
  }
  printf("***********************************\n");
} 

void killDioTable(DioTable *t) {
 DIOSYM *SB;
 DIOSYM *SB2;
 int i; 
 for(i=0;i<HashSize;++i) {
   SB = t -> table[i];
   while (SB != NULL)
   {
     //printf("kill: %i %s\n",i,SB->name);
     SB2=SB->next;
     free(SB);
     SB=SB2;
   }
 }
 free(t);
}
