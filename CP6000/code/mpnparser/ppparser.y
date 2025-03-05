%{

#include <stdio.h>
#include "pptree.h"

  int ppline=1;
  extern char *pptext;
  extern char *ppval;
  extern PPSTRUCT* thePP;
  void pperror() {
    printf("syntax error before %s at line %i\n",pptext,ppline);
    exit(0);
  }  
 
%}


%union { 
  struct PPSTRUCT *ppstruct_type;
  struct MOVE_LIST *move_list_type;
  struct MOVEDEC *movedec_type;
  struct FRAME *frame_type;
  struct VIAP *via_type;
  struct STARTMACRO *startmacro_type;
  struct ENDMACRO *endmacro_type;
  struct OPT_WITH *opt_with_type;
  struct PARAMLIST *paramlist_type;
  struct PARAM *param_type;
  struct SIXNUMS *sixnums_type;
  float real_type;
  int num;
  char *stringconst;
  float floating;
}

%token FLOAT NUM ID COMMA RIGHT_PAR LEFT_PAR SAMPLERATE MAXACC MAXVEL POSITIONHINT CUBICBLEND QUINTICBLEND DEFAULTS SPIRAL DOWNLINE UPLINE WITH MACRO VEL POS VIA TO FROM WCP IDX MOVE LAYERS TYPE ITEMSPRLAYER VERSION

/*
%expect 1
%pure_parser
*/

%token <num> NUM
%token <stringconst> ID
%token <floating> FLOAT

%type <ppstruct_type> ppstruct1 ppstruct
%type <move_list_type> move_list
%type <movedec_type> movedec
%type <frame_type> frame
%type <via_type> via
%type <startmacro_type> startmacro
%type <endmacro_type> endmacro
%type <opt_with_type> opt_with
%type <paramlist_type> paramlist
%type <param_type> param
%type <sixnums_type> sixnums
%type <real_type> real


%start ppstruct1 

%%
ppstruct1         : ppstruct {thePP=$1;}
                        ;

ppstruct          : VERSION NUM ID TYPE NUM ITEMSPRLAYER NUM LAYERS NUM move_list {$$=makePP($2,$3,$5,$7,$9,$10);}
                        ;

move_list	  : move_list movedec {$$=makeMOVE_LIST($1,$2);}
                        | {$$=makeMOVE_LISTempty();}
                        ;
		
movedec       : MOVE ID IDX NUM COMMA NUM FROM frame startmacro via TO frame endmacro via opt_with {$$=makeMOVEDEC($2,$4,$6,$8,$9,$10,$12,$13,$14,$15);}
			;

frame             : ID {$$=makeFRAME($1);}
                        | ID LEFT_PAR WCP sixnums RIGHT_PAR{$$=makeFRAMErel($1,$4);}
                        ;

via               : VIA POS LEFT_PAR sixnums RIGHT_PAR VEL LEFT_PAR sixnums RIGHT_PAR {$$=makeVIA($4,$8);}
                        | {$$=makeVIAempty();}
                        ;

startmacro        : MACRO LEFT_PAR UPLINE COMMA real COMMA real RIGHT_PAR {$$=makeSTARTMACROupline($5,$7);}
                        | {$$=makeSTARTMACROempty();}
                        ;

endmacro          : MACRO LEFT_PAR DOWNLINE COMMA real COMMA real RIGHT_PAR {$$=makeENDMACROdownline($5,$7);}
                        | MACRO LEFT_PAR SPIRAL COMMA real COMMA real COMMA real COMMA real COMMA real COMMA real RIGHT_PAR {$$=makeENDMACROspiral($5,$7,$9,$11,$13,$5);}
                        | {$$=makeENDMACROempty();}
                        ;

opt_with          : WITH paramlist {$$=makeOPT_WITHparamlist($2);}
                        | WITH DEFAULTS {$$=makeOPT_WITHdefaults();}
                        | {$$=makeOPT_WITHdefaults();}
                        ; 

paramlist         : paramlist param {$$=makePARAMLISTparamlist($1,$2);}
                        | param {$$=makePARAMLISTparam($1);}
                        ; 

param             : QUINTICBLEND {$$=makePARAMquintic();}
                        | CUBICBLEND {$$=makePARAMcubic();}
                        | POSITIONHINT LEFT_PAR real RIGHT_PAR {$$=makePARAMpositionhint($3);}
                        | MAXVEL LEFT_PAR sixnums RIGHT_PAR {$$=makePARAMmaxvel($3);}
                        | MAXACC LEFT_PAR sixnums RIGHT_PAR {$$=makePARAMmaxacc($3);}
                        | SAMPLERATE LEFT_PAR real RIGHT_PAR {$$=makePARAMsamplerate($3);}
                        ; 

sixnums         : real COMMA real COMMA real COMMA real COMMA real COMMA real {$$=makeSIXNUMS($1,$3,$5,$7,$9,$11);}
                        ;

real              : NUM {$$=makeREALnum($1);}
                        |  FLOAT {$$=makeREALfloating($1);}
                        ;
%%
