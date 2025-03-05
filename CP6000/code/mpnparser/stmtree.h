
#ifndef __stmtree_h
#define __stmtree_h

#define NEW(type) (type*)malloc(sizeof(type))


/*

  int num;
  char *stringconst;
  struct STM *statemachine_type;
  struct NAME *name_type;
  struct VERSION *version_type;
  struct OPT_FILTER *opt_filter_type;
  struct OPT_SIM *opt_sim__type;
  struct OPT_FROM *opt_from__type;
  struct EXP *expression_type;
  struct TERM *term_type;
  struct STATE_LIST *state_list_type;
  struct STATE *state_type;
  struct HEAD *head_type;
  struct TAIL *tail_type;
  struct DECL_LIST *decl_list_type;
  struct DECLARATION *dec_type;
  struct STATEMENT_LIST *statement_list_type;
  struct STATEMENT *statement_type;
  struct OPT_TIMERSTATE *opt_timerstate_type;
  struct OPT_ET_LIST *opt_et_list_type;
  struct OPT_ELSE *opt_else_type;
  struct OPT_ELSETEST *opt_elsetest_type;

*/

typedef struct STATEMACHINE {
  int lineno;
  union {
    struct {struct VERSST *version; struct NAMEST *name; struct DECL_LIST *decl_list; struct STATE_LIST *state_list;} stm;    
  } val; 
} STATEMACHINE;


typedef struct VERSST {
  int lineno;
  union {
    int numV;
  } val; 
} VERSST;

typedef struct NAMEST {
  int lineno;
  union {
    char *id;
  } val; 
} NAMEST;

typedef struct DECL_LIST {
  int lineno;
  enum {decl_listK,emptydlK} kind;
  union {
    struct {struct DECL_LIST *decl_list; struct DECLARATION *declaration;} decl_listD; 
  } val;
} DECL_LIST;

typedef struct DECLARATION {
  int lineno;
  enum {inputK,outputK,linkK,timeK,valueK,delaystopK} kind;
  union {
    struct {char *id1; char *id2; struct OPT_FILTER *opt_filter; struct OPT_SIM *opt_sim;} inputD;
    struct {char *id1; char *id2;} outputD;
    struct {char *id;} linkD;
    struct {char *id; struct EXP *exp;} timeD;
    struct {char *id; struct EXP *exp; struct OPT_FROM *opt_from;} valueD;
    struct {struct EXP *exp;} delaystopD;
  } val;
} DECLARATION;

typedef struct OPT_FILTER {
  int lineno;
  enum {filterK,emptyfilterK} kind;
  union {
    struct {struct EXP *ontime; struct EXP *offtime;} filterF;    
  } val; 
} OPT_FILTER;

typedef struct OPT_SIM {
  int lineno;
  enum {simK,emptysimK} kind;
} OPT_SIM;

typedef struct OPT_FROM {
  int lineno;
  enum {fromK,emptyfromK} kind;
  union {
    char *id;    
  } val; 
} OPT_FROM;

typedef struct STATE_LIST {
  int lineno;
  enum {state_listK,emptystate_listK} kind;
  union {
    struct {struct STATE_LIST *state_list; struct STATEST *state;} state_listS;
  } val;
} STATE_LIST;

typedef struct STATEST {
  int lineno;
  union {
    struct {struct HEAD *head; struct STATEMENT_LIST *statement_list;} stateS;
  } val;
} STATEST;

typedef struct HEAD {
  int lineno;
  char *id;
} HEAD;

typedef struct STATEMENT_LIST {
  int lineno;
  enum {slK,emptyslK} kind;
  union {
    struct {struct STATEMENT_LIST *statement_list; struct STATEMENT *statement;} statement_listS;
  } val;
} STATEMENT_LIST;

typedef struct STATEMENT {
  int lineno;
  enum {printK,setK,assignmentK,plusassignK,minusassignK,plusplusK,testK,setstateK,timeoutK} kind;
  union {
    struct {struct EXP *exp;} printS;
    struct {char* id; struct EXP *exp;} setS;
    struct {char* id; struct EXP *exp;} assignmentS;
    struct {char* id; struct EXP *exp;} plusassignS;
    struct {char* id; struct EXP *exp;} minusassignS;
    struct {char* id;} plusplusS;
    struct {struct EXP *exp; struct STATEMENT_LIST *statement_list; struct OPT_ET_LIST *opt_et_list; struct OPT_ELSE *opt_else;} testS;
    struct {char* id;} setstateS;
    struct {char* idtime; char* id_gotostate; struct OPT_TIMERSTATE *opt_timerstate;} timeoutS; 
  } val;
} STATEMENT;

typedef struct OPT_TIMERSTATE {
  int lineno;
  enum {otsK,emptyotsK} kind;
  union {
    char *id;    
  } val; 
} OPT_TIMERSTATE;

typedef struct OPT_ET_LIST {
  int lineno;
  enum {oelK,emptyoelK} kind;
  union {
    struct {struct OPT_ET_LIST *opt_et_list; struct OPT_ELSETEST *opt_elsetest;} oelO;    
  } val; 
} OPT_ET_LIST;

typedef struct OPT_ELSETEST {
  int lineno;
  union {
    struct {struct EXP *exp; struct STATEMENT_LIST *statement_list;} elsetestO;    
  } val; 
} OPT_ELSETEST;

typedef struct OPT_ELSE {
  int lineno;
  enum {elseK,emptyOEK} kind;
  union {
    struct {struct STATEMENT_LIST *statement_list;} statementlO;    
  } val; 
} OPT_ELSE;

typedef struct EXP {
  int lineno;
  enum {termK,orK,andK,plusK,minusK\
	,timesK,divK,equalK,not_equalK,larger_thanK\
	,larger_than_equalK,smaller_thanK,smaller_than_equalK} kind;
  union {
    struct {struct TERM *term;} termE;
    struct {struct EXP *left; struct EXP *right;} orE;
    struct {struct EXP *left; struct EXP *right;} andE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} equalE;
    struct {struct EXP *left; struct EXP *right;} not_equalE;
    struct {struct EXP *left; struct EXP *right;} larger_thanE;
    struct {struct EXP *left; struct EXP *right;} larger_than_equalE;
    struct {struct EXP *left; struct EXP *right;} smaller_thanE;
    struct {struct EXP *left; struct EXP *right;} smaller_than_equalE;
  } val;
} EXP;

typedef struct TERM {
  int lineno;
  enum {notK,numK,idK,parK} kind;
  union {   
    int numT;
    //    float floatT;
    char *id;
    struct {struct TERM *term;} notT;
    struct {struct EXP *exp;} parT;
  } val;
} TERM;

typedef struct TY {
  enum {tyINPUTK,tyOUTPUTK,tyTIMEK,tySTMK,tySTATEK,tyVALUEK,tyINTK} type;
  char *id;
} TY;

STATEMACHINE *makeSTATEMACHINE(VERSST *v, NAMEST *n, DECL_LIST *dl,STATE_LIST *stl);

VERSST *makeVERSION(int num);

NAMEST *makeNAME(char *nameid);

DECL_LIST *makeDECL_LISTempty();

DECL_LIST *makeDECL_LIST(DECL_LIST *del,DECLARATION *d);

DECLARATION *makeDECLARATIONinput(char *inputid, char *dioid, OPT_FILTER *opt_filter, OPT_SIM *opt_sim);

DECLARATION *makeDECLARATIONoutput(char *outputid,char *dioid);

DECLARATION *makeDECLARATIONlink(char *id);

DECLARATION *makeDECLARATIONtime(char *id, EXP *exp);

DECLARATION *makeDECLARATIONvalue(char *id, EXP *exp);

DECLARATION *makeDECLARATIONvaluefrom(char *id, OPT_FROM *opt_from);

DECLARATION *makeDECLARATIONdelaystop(EXP *exp);

OPT_FILTER *makeFILTER(EXP *onexp, EXP *offexp);

OPT_FILTER *makeFILTERempty();

OPT_SIM *makeSIM();

OPT_SIM *makeSIMempty();

OPT_FROM *makeFROM(char *id);

OPT_FROM *makeFROMempty();

STATE_LIST *makeSTATE_LIST(STATE_LIST *stlist,STATEST *st);

STATE_LIST *makeSTATE_LISTempty();

STATEST *makeSTATE(HEAD *h,STATEMENT_LIST *stlist);

HEAD *makeHEAD(char *id);

STATEMENT_LIST *makeSTATEMENT_LIST(STATEMENT_LIST *sl, STATEMENT *statement);

STATEMENT_LIST *makeSTATEMENT_LISTempty();

STATEMENT *makeSTATEMENTprint(EXP *exp);

STATEMENT *makeSTATEMENTset(char *id, EXP *exp);

STATEMENT *makeSTATEMENTtest(EXP *exp, STATEMENT_LIST *sl, OPT_ET_LIST *opt_et_list, OPT_ELSE *opt_else);

STATEMENT *makeSTATEMENTassignment(char *id, EXP *exp);

STATEMENT *makeSTATEMENTplusassign(char *id, EXP *exp);

STATEMENT *makeSTATEMENTminusassign(char *id, EXP *exp);

STATEMENT *makeSTATEMENTplusplus(char *id);

STATEMENT *makeSTATEMENTsetstate(char *id);

STATEMENT *makeSTATEMENTtimeout(char *timeid, char *tostateid, OPT_TIMERSTATE *opt_timerstate);

OPT_TIMERSTATE *makeOPT_TIMERSTATE(char *id);

OPT_TIMERSTATE *makeOPT_TIMERSTATEempty();

OPT_ET_LIST *makeOPT_ET_LIST(OPT_ET_LIST *opt_et_list, OPT_ELSETEST *opt_elsetest);

OPT_ET_LIST *makeOPT_ET_LISTempty();

OPT_ELSETEST *makeOPT_ELSETEST(EXP *exp, STATEMENT_LIST *sl);

OPT_ELSE *makeOPT_ELSE(STATEMENT_LIST *sl);

OPT_ELSE *makeOPT_ELSEempty();

TERM *makeTERMid(char *id);

TERM *makeTERMnum(int num);

//TERM *makeTERMfloat(float f);

TERM *makeTERMnot(TERM *term);

TERM *makeTERMpar(EXP *exp);

EXP *makeEXPterm(TERM *term);

EXP *makeEXPor(EXP *left, EXP *right);

EXP *makeEXPand(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPequal(EXP *left, EXP *right);

EXP *makeEXPnot_equal(EXP *left, EXP *right);

EXP *makeEXPlarger_than(EXP *left, EXP *right);

EXP *makeEXPlarger_than_equal(EXP *left, EXP *right);

EXP *makeEXPsmaller_than(EXP *left, EXP *right);

EXP *makeEXPsmaller_than_equal(EXP *left, EXP *right);

#endif
