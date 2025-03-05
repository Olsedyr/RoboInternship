#ifndef __symbol_h
#define __symbol_h

#define HashSize 241

#define NEW(type) (type*)malloc(sizeof(type))

#define STBDDI3610      1
#define STBDDO3600      2
#define STBEPI2145      3

typedef struct SYMBOL {
  enum {INPUTK,OUTPUTK,TIMEK,STMK,STATEK,VALUEK,INTK} kind;
  char *name;
  struct SYMBOL *next;
} SYMBOL;

typedef struct SymbolTable {
  char *name;
  struct SymbolTable *next;
  SYMBOL *table[HashSize];
} SymbolTable;

typedef struct StmTable {
  SymbolTable *table[HashSize];
} StmTable;

typedef struct DIOSYM {
  enum {DIOINK,DIOOUTK} kind;
  char *name;
  char *comment;
  int moduleType; //STBDDI3610,STBDDO3600,STBEPI2145
  char *moduleName;
  int moduleNum;  //smaller than numOfModules
  int connectNum;
  int flip;
  struct DIOSYM *next;
} DIOSYM;

typedef struct DioTable {
  DIOSYM *table[HashSize];
  int numOfModules;
} DioTable;

int Hash(char *str);

StmTable *initStmTable();

SymbolTable *addSymbolTable(StmTable *t, char *name);

SymbolTable *getSymbolTable(StmTable *t, char *name);

void dumpStmTable(StmTable *t);



SymbolTable *initSymbolTable();

SYMBOL *putSymbol(SymbolTable *t, char *name, int kind);

SYMBOL *getSymbol(SymbolTable *t, char *name);

void dumpSymbolTable(SymbolTable *t);


DioTable *initDioTable();

DIOSYM *putDioSym(DioTable *t, int kind, char *name, char *comment, int moduleType, char *moduleName, int moduleNum, int connectNum, int flip);

DIOSYM *getDioSym(DioTable *t, char *name);

void dumpDioTable(DioTable *t);

void killDioTable(DioTable *t);

#endif /* __symbol_h */









