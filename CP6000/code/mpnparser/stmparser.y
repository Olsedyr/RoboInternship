%{

#include <stdio.h>
#include "stmtree.h"

  int line=1;
  extern char *stmtext;
  extern char *stmval;
  extern STATEMACHINE* theStatemachine;
  void stmerror() {
    printf("syntax error before %s at line %i\n",stmtext,line);
    exit(0);
  }  
 
%}

%union { 
  struct NAMEST *name_type;
  struct VERSST *version_type;
  struct OPT_FILTER *opt_filter_type;
  struct OPT_SIM *opt_sim_type;
  struct OPT_FROM *opt_from_type;
  struct EXP *expression_type;
  struct TERM *term_type;
  struct STATE_LIST *state_list_type;
  struct STATEST *state_type;
  struct HEAD *head_type;
  struct DECL_LIST *decl_list_type;
  struct DECLARATION *dec_type;
  struct STATEMENT_LIST *statement_list_type;
  struct STATEMENT *statement_type;
  struct OPT_TIMERSTATE *opt_timerstate_type;
  struct OPT_ET_LIST *opt_et_list_type;
  struct OPT_ELSE *opt_else_type;
  struct OPT_ELSETEST *opt_elsetest_type;
  struct STATEMACHINE *statemachine_type;
  int num;
  char *stringconst;
}

%token NUM STATE END ID PRINT TEST ELSETEST ELSE ENDTEST NOT OR AND PLUS MINUS DIV TIMES EQUAL NOT_EQUAL LARGER_THAN SMALLER_THAN LARGER_THAN_EQUAL SMALLER_THAN_EQUAL ASSIGNMENT PLUSASSIGN MINUSASSIGN PLUSPLUS RIGHT_PAR LEFT_PAR NAME SETSTATE INPUT OUTPUT VALUE TIMEOUT FILTER LINK TIMEVAL SET FROM VERSION SIMULATE COLON DELAYSTOP

/*
  float floatie;
FLOAT
%token <floatie> FLOAT
| FLOAT {$$=makeTERMfloat($1);}
			;


%expect 1
%pure_parser
*/

%token <num> NUM
%token <stringconst> ID 

%type <expression_type> expression
%type <term_type> term
%type <statemachine_type> statemachine statemachine1
%type <version_type> version
%type <name_type> name
%type <opt_filter_type> opt_filter
%type <opt_sim_type> opt_sim
%type <opt_from_type> opt_from
%type <state_list_type> state_list
%type <state_type> state
%type <head_type> head
%type <decl_list_type> decl_list
%type <dec_type> declaration
%type <statement_list_type> statement_list
%type <statement_type> statement
%type <opt_timerstate_type> opt_timerstate
%type <opt_else_type> opt_else
%type <opt_et_list_type> opt_et_list
%type <opt_elsetest_type> opt_elsetest


%start statemachine1 
%right ELSE
%right MINUSASSIGN PLUSASSIGN ASSIGNMENT
%left  OR  
%left AND    
%left EQUAL NOT_EQUAL
%left SMALLER_THAN SMALLER_THAN_EQUAL LARGER_THAN LARGER_THAN_EQUAL
%left PLUS MINUS
%left TIMES DIV   
%right PLUSPLUS

%%
statemachine1   : statemachine {theStatemachine=$1;}
                        ;

statemachine    : version name decl_list state_list {$$=makeSTATEMACHINE($1,$2,$3,$4);}
		        ;

version         : VERSION NUM {$$=makeVERSION($2);}
                        ;

name            : NAME ID {$$=makeNAME($2);}
                        ;

decl_list	: decl_list declaration {$$=makeDECL_LIST($1,$2);}
                        |{$$=makeDECL_LISTempty();}
                        ;
		
declaration     : INPUT ID ID opt_filter opt_sim {$$=makeDECLARATIONinput($2,$3,$4,$5);}
			| OUTPUT ID ID {$$=makeDECLARATIONoutput($2,$3);}
			| LINK ID {$$=makeDECLARATIONlink($2);}
			| TIMEVAL ID expression {$$=makeDECLARATIONtime($2,$3);}
			| VALUE ID expression {$$=makeDECLARATIONvalue($2,$3);}
			| VALUE ID opt_from {$$=makeDECLARATIONvaluefrom($2,$3);}
                        | DELAYSTOP expression {$$=makeDECLARATIONdelaystop($2);}
			;

opt_filter      : FILTER expression expression {$$=makeFILTER($2,$3);}
                        | {$$=makeFILTERempty();}
                        ;

opt_sim         : SIMULATE {$$=makeSIM();}
                        | {$$=makeSIMempty();}
                        ;

opt_from        : FROM ID {$$=makeFROM($2);}
                        | {$$=makeFROMempty();}
                        ;

state_list      : state_list state {$$=makeSTATE_LIST($1,$2);}
			| {$$=makeSTATE_LISTempty();}
                        ;

state           : head statement_list END {$$=makeSTATE($1,$2);}
			;

head	        : STATE ID {$$=makeHEAD($2);}
			;

statement_list  : statement_list statement {$$=makeSTATEMENT_LIST($1,$2);}
			| {$$=makeSTATEMENT_LISTempty();}
			;
	
statement	: PRINT expression {$$=makeSTATEMENTprint($2);}
	 		| SET ID expression {$$=makeSTATEMENTset($2,$3);}
			| TEST expression statement_list opt_et_list opt_else ENDTEST {$$=makeSTATEMENTtest($2,$3,$4,$5);}
                        | SETSTATE ID {$$=makeSTATEMENTsetstate($2);}
			| TIMEOUT ID ID opt_timerstate {$$=makeSTATEMENTtimeout($2,$3,$4);}
                        | ID ASSIGNMENT expression {$$=makeSTATEMENTassignment($1,$3);}
                        | ID PLUSASSIGN expression {$$=makeSTATEMENTplusassign($1,$3);}
                        | ID MINUSASSIGN expression {$$=makeSTATEMENTminusassign($1,$3);}
                        | ID PLUSPLUS {$$=makeSTATEMENTplusplus($1);}
			;


opt_timerstate  : COLON ID {$$=makeOPT_TIMERSTATE($2);}
			| {$$=makeOPT_TIMERSTATEempty();}
			;

opt_et_list	: opt_et_list opt_elsetest {$$=makeOPT_ET_LIST($1,$2);}
                        | {$$=makeOPT_ET_LISTempty();}
			;

opt_elsetest	: ELSETEST expression statement_list {$$=makeOPT_ELSETEST($2,$3);}
			;

opt_else	: ELSE statement_list {$$=makeOPT_ELSE($2);}
                        | {$$=makeOPT_ELSEempty();}
			;

expression      : expression EQUAL expression {$$=makeEXPequal($1,$3);}
                        | expression SMALLER_THAN_EQUAL expression {$$=makeEXPsmaller_than_equal($1,$3);}
                        | expression NOT_EQUAL expression {$$=makeEXPnot_equal($1,$3);}
                        | expression LARGER_THAN expression     {$$=makeEXPlarger_than($1,$3);}
                        | expression SMALLER_THAN expression    {$$=makeEXPsmaller_than($1,$3);}
                        | expression LARGER_THAN_EQUAL expression  {$$=makeEXPlarger_than_equal($1,$3);}
                        | expression OR expression        {$$=makeEXPor($1,$3);}
                        | expression PLUS expression  {$$=makeEXPplus($1,$3);}
                        | expression MINUS expression {$$=makeEXPminus($1,$3);}
                        | expression AND expression   {$$=makeEXPand($1,$3);}
                        | expression TIMES expression {$$=makeEXPtimes($1,$3);}
                        | expression DIV expression   {$$=makeEXPdiv($1,$3);}
                        | term {$$=makeEXPterm($1);}
                        ;

term		: ID {$$ = makeTERMid($1);}
                        | LEFT_PAR expression RIGHT_PAR {$$=makeTERMpar($2);}
                        | NOT term {$$=makeTERMnot($2);}
                        | NUM {$$=makeTERMnum($1);}
                        ;

%%
