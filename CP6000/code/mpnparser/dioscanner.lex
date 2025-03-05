
%option noyywrap
/*
%option case-insensitive
*/

%{
  #include <string.h>
  #include "dioparser.tab.h"
  extern int dioline;
  int dioval;
  char *diotext;
  int diocomments=0;
  int empty=1;
%}

%x COMMENT
%x COMMENTSEMI
%x QUOTE

delim			[ \t]
ws			{delim}+
letter			[a-zA-Z\303\206\230\205\246\270\245]
ext_letter		[_]
digit			[0-9]
id			{letter}({letter}|{ext_letter}|{digit})*
iddio			{letter}({letter}|{ws}|{ext_letter}|{digit}|"+"|"-"|"."|"/")*
diomod                  {digit}{letter}{digit}+
int			{digit}+
    

%%
"/*" {diocomments++;BEGIN(COMMENT);}
<COMMENT>"/*" {diocomments++;}
<COMMENT>"*/" {diocomments--; if (diocomments==0) BEGIN(INITIAL);}
<COMMENT>[\n] {dioline++;}
<COMMENT>.    {}

"*/" {printf("No comments to end here! line %i \n",dioline);}

";" {BEGIN(COMMENTSEMI);}
<COMMENTSEMI>[\n] {dioline++; BEGIN(INITIAL);}
<COMMENTSEMI>. {}

"\"" {BEGIN(QUOTE);}
<QUOTE>"\"" { BEGIN(INITIAL); if (empty) return(EID); else empty=1;}
<QUOTE>[\n]    {printf("dio1: Unrecognised string at line %i\n",dioline);}
<QUOTE>{iddio} {empty=0; diolval.stringconst=(char*)malloc(strlen(diotext)+1);
                              sprintf(diolval.stringconst,"%s",diotext); return(QID);}
<QUOTE>. {empty=0; printf("dio2: Unrecognised string at line %i\n",dioline);}


[\n]                       {dioline++;}
{ws}		           {/* no action */}

IOVERSION                  {return(VERSION);}
NumOfModules               {return(NUMMOD);}
Type                       {return(TYPE);}
Name                       {return(NAME);}
flip                       {return(FLIP);}

Connect{int}               {diolval.num = atoi(diotext+7); return(CONNECT);}

"="                        {return(ASSIGNMENT);}

{id}       	           {diolval.stringconst=(char*)malloc(strlen(diotext)+1);
			      sprintf(diolval.stringconst,"%s",diotext); return(ID);}

{diomod}       	           {diolval.stringconst=(char*)malloc(strlen(diotext)+1);
			      sprintf(diolval.stringconst,"%s",diotext); return(ID);}

{int}                      {diolval.num = atoi(diotext); return(NUM);}

.		           {printf("Unrecongnised string at line %i\n",dioline);}

%%

/*
int main(void) {
  diolex();
  int dioline=1;
  return 0;
  }*/




