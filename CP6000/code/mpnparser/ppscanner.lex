
%option noyywrap
/*
%option case-insensitive
*/

%{
  #include <string.h>
  #include "ppparser.tab.h"
  extern int ppline;
  int ppval;
  char *pptext;
%}

%x COMMENTSEMI

delim			[ \t]
ws			{delim}+
letter			[a-zA-Z\303\206\230\205\246\270\245]
ext_letter		[_]
digit			[0-9]
minus                   [-]
id			({letter}|{ext_letter}|{digit})*{letter}({letter}|{ext_letter}|{digit})*
int			{minus}?{digit}+
float                   {minus}?{digit}+"."{digit}*   

%%

";" {BEGIN(COMMENTSEMI);}
<COMMENTSEMI>[\n] {ppline++; BEGIN(INITIAL);}
<COMMENTSEMI>. {}

[\n]                       {ppline++;}
{ws}		           {/* no action */}

PPSCRIPTVERSION            {return(VERSION);}
"itemsPrLayer="            {return(ITEMSPRLAYER);}
"type="                    {return(TYPE);}
"layers="                  {return(LAYERS);}
move                       {return(MOVE);}
"idx="                     {return(IDX);}
"wcp="                     {return(WCP);}
from                       {return(FROM);}
to                         {return(TO);}
via                        {return(VIA);}
pos                        {return(POS);}
vel                        {return(VEL);}
macro                      {return(MACRO);}
with                       {return(WITH);}
upline                     {return(UPLINE);}
downline                   {return(DOWNLINE);}
spiral                     {return(SPIRAL);}
defaults                   {return(DEFAULTS);}
quinticblend               {return(QUINTICBLEND);}
cubicblend                 {return(CUBICBLEND);}
positionhint               {return(POSITIONHINT);}
maxvel                     {return(MAXVEL);}
maxacc                     {return(MAXACC);}
samplerate                 {return(SAMPLERATE);}

"("                        {return(LEFT_PAR);}
")"                        {return(RIGHT_PAR);}

","                        {return(COMMA);}

{id}       	           {pplval.stringconst=(char*)malloc(strlen(pptext)+1);
			      sprintf(pplval.stringconst,"%s",pptext); return(ID);}

{int}                      {pplval.num = atoi(pptext); return(NUM);}

{float}                    {pplval.floating = atof(pptext); return(FLOAT);}

.		           {printf("Unrecongnised string at line %i\n",ppline);}

%%

/*
int main(void) {
  pplex();
  int ppline=1;
  return 0;
  }*/




