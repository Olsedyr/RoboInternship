
%option noyywrap
/*
%option case-insensitive
*/

%{
  #include <string.h>
  #include "stmparser.tab.h"
  extern int line;
  int stmval;
  char *stmtext;
  int comments=0;
%}

%x COMMENT
%x COMMENTSEMI
%x QUOTE

delim			[ \t]
ws			{delim}+
letter			[a-zA-Z]
ext_letter		[_]
digit			[0-9]
id			{letter}({letter}|{ext_letter}|{digit})*
iddio			{letter}({letter}|{ws}|{ext_letter}|{digit}|"+"|"-")*
int			{digit}+

    

%%
"/*" {comments++;BEGIN(COMMENT);}
<COMMENT>"/*" {comments++;}
<COMMENT>"*/" {comments--; if (comments==0) BEGIN(INITIAL);}
<COMMENT>[\n] {line++;}
<COMMENT>.    {}

"*/" {printf("No comments to end here! line %i \n",line);}

";" {BEGIN(COMMENTSEMI);}
<COMMENTSEMI>[\n] {line++; BEGIN(INITIAL);}
<COMMENTSEMI>. {}

"\"" {BEGIN(QUOTE);}
<QUOTE>"\"" {BEGIN(INITIAL);}
<QUOTE>[\n]    {printf("Unrecongnised string at line %i\n",line);}
<QUOTE>{iddio} {stmlval.stringconst=(char*)malloc(strlen(stmtext)+1);
			      sprintf(stmlval.stringconst,"%s",stmtext); return(ID);}
<QUOTE>. {printf("Unrecongnised string at line %i\n",line);}

[\n]                       {line++;}
{ws}		           {/* no action */}
AND     	           {return(AND);}
"*"		           {return(TIMES);}
"/"		           {return(DIV);}

OR                         {return(OR);}
"+"		           {return(PLUS);}
"-"		           {return(MINUS);}

"!"                        {return(NOT);}

"!="           	           {return(NOT_EQUAL);}
"=="        	           {return(EQUAL);}
">="	      	           {return(LARGER_THAN_EQUAL);}
"<="		           {return(SMALLER_THAN_EQUAL);}
"<"		           {return(SMALLER_THAN);}
">"		           {return(LARGER_THAN);}

"("                        {return(LEFT_PAR);}
")"                        {return(RIGHT_PAR);}
"="                        {return(ASSIGNMENT);}
"++"                       {return(PLUSPLUS);}
"+="                       {return(PLUSASSIGN);}
"-="                       {return(MINUSASSIGN);}
":"                        {return(COLON);}
STATEMACHINEVERSION        {return(VERSION);}
Name                       {return(NAME);}
Delaystop                  {return(DELAYSTOP);}
Input                      {return(INPUT);}
Output                     {return(OUTPUT);}
Filter                     {return(FILTER);}
Link                       {return(LINK);}
Value                      {return(VALUE);}
Time                       {return(TIMEVAL);}
State                      {return(STATE);}
Simulate                   {return(SIMULATE);}
From                       {return(FROM);}

END                        {return(END);} 

PRINT                      {return(PRINT);}
TEST                       {return(TEST);}
ENDTEST                    {return(ENDTEST);}
ELSETEST                   {return(ELSETEST);}
ELSE                       {return(ELSE);}

SETSTATE                   {return(SETSTATE);}
SET                        {return(SET);}
TIMEOUT                    {return(TIMEOUT);}

{id}       	           {stmlval.stringconst=(char*)malloc(strlen(stmtext)+1);
			      sprintf(stmlval.stringconst,"%s",stmtext); return(ID);}



{int}                      {stmlval.num=atoi(stmtext);return(NUM);}

.		           {printf("Unrecongnised string at line %i\n",line);}

%%
/*
commatal                {digit}+"."{digit}+
{commatal}                 {stmlval.floatie=atof(stmtext);return(FLOAT);}
int main(void) {
  yylex();
  return 0;
}
*/



