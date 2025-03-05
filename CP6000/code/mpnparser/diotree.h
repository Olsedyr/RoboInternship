
#ifndef __diotree_h
#define __diotree_h

/*

  struct DIO *dio_type;
  struct MODLIST *modlist_type;
  struct MODULE *module_type;
  struct CONNECTLIST *connectlist_type;
  struct CONNECTOR *connector_type;
  int num;
  char *stringconst;

*/

#define NEW(type) (type*)malloc(sizeof(type))

typedef struct DIO {
  int lineno;
  union {
    struct {int numV; struct NUMMODST *nummod; struct MODLIST *modlist;} dio;    
  } val; 
} DIO;

typedef struct NUMMODST {
  int lineno;
  int numM;
} NUMMODST;

typedef struct MODLIST {
  int lineno;
  enum {modlistK,emptymlK} kind;
  union {
    struct {struct MODLIST *modlist; struct MODULE *module;} modlistM; 
  } val;
} MODLIST;

typedef struct MODULE {
  int lineno;
  union {
    struct {char *typeid; char *nameid; struct CONNECTLIST *connectlist;} moduleM;
  } val;
} MODULE;

typedef struct CONNECTLIST {
  int lineno;
  enum {connectlistK,emptyclK} kind;
  union {
    struct {struct CONNECTLIST *connectlist; struct CONNECTOR *connector;} connectorL;
  } val;
} CONNECTLIST;

typedef struct CONNECTOR {
  int lineno;
  enum {connectorK,emptyconnectorK} kind;
  union {
    struct {int num; char *id; char *comment; struct OPT_FLIP *opt_flip;} connectorC;
  } val;
} CONNECTOR;

typedef struct OPT_FLIP {
  int lineno;
  enum {opt_flipK,emptyopt_flipK} kind;
} OPT_FLIP;

DIO *makeDIO(int numV, NUMMODST *n, MODLIST *ml);
NUMMODST *makeNUMMOD(int num);
MODLIST *makeMODLIST(MODLIST *modlist,MODULE *module);
MODLIST *makeMODLISTempty();
MODULE *makeMODULE(char *typeid,char *nameid,CONNECTLIST *connectlist);
CONNECTLIST *makeCONNECTLIST(CONNECTLIST *connectlist,CONNECTOR *connector);
CONNECTLIST *makeCONNECTLISTempty();
CONNECTOR *makeCONNECTOR(int num, char *id, char *comment,OPT_FLIP *opt_flip);
CONNECTOR *makeCONNECTORempty(int num);
OPT_FLIP *makeOPT_FLIP();
OPT_FLIP *makeOPT_FLIPempty();

#endif /* diotree_h */
