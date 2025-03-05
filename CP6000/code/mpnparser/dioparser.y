%{

#include <stdio.h>
#include "diotree.h"

  int dioline=1;
  extern char *diotext;
  extern char *dioval;
  extern DIO* theDio;
  void dioerror() {
    printf("syntax error before %s at line %i\n",diotext,dioline);
    exit(0);
  }  
 
%}

%union { 
  struct DIO *dio_type;
  struct NUMMODST *nummod_type;
  struct MODLIST *modlist_type;
  struct MODULE *module_type;
  struct CONNECTLIST *connectlist_type;
  struct CONNECTOR *connector_type;
  struct OPT_FLIP *opt_flip_type;
  int num;
  char *stringconst;
}

%token NUM ID QID EID VERSION NUMMOD TYPE NAME CONNECT ASSIGNMENT FLIP

/*
%expect 1
%pure_parser
*/

%token <num> NUM CONNECT
%token <stringconst> ID QID

%type <dio_type> dio1 dio
%type <nummod_type> nummod
%type <modlist_type> modlist 
%type <module_type> module
%type <connectlist_type> connectlist
%type <connector_type> connector
%type <opt_flip_type> opt_flip

%start dio1 

%%
dio1              : dio {theDio=$1;}
                        ;

dio               : VERSION NUM nummod modlist {$$=makeDIO($2,$3,$4);}
                        ;

nummod            : NUMMOD ASSIGNMENT NUM {$$=makeNUMMOD($3);}
                        ;

modlist	          : modlist module {$$=makeMODLIST($1,$2);}
                        |{$$=makeMODLISTempty();}
                        ;
		
module            : TYPE ASSIGNMENT ID NAME ASSIGNMENT ID connectlist {$$=makeMODULE($3,$6,$7);}
			;

connectlist       : connectlist connector {$$=makeCONNECTLIST($1,$2);}
                        | {$$=makeCONNECTLISTempty();}
                        ;

connector         : CONNECT ASSIGNMENT QID QID opt_flip {$$=makeCONNECTOR($1,$3,$4,$5);}
                        | CONNECT ASSIGNMENT EID EID opt_flip {$$=makeCONNECTORempty($1);}
                        ;

opt_flip          : FLIP {$$=makeOPT_FLIP();}
                        | {$$=makeOPT_FLIPempty();}
%%
