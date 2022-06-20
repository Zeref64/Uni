%option noyywrap

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token.h"

int line = 1;

/* to \s den to vriskei opote evala \t */
%}

VARIABLE       \?([a-z]|[A-Z]|[0-9])+
DELIMITER      [ ]+|\([^()]*\) 
STRING         "hello"
COMMENT         ;.*                 

%%

{VARIABLE}     { return VARIABLE; }
{COMMENT}      { ; }
{DELIMITER}    { ; }
{STRING}       { return STRING }
\n             { line++; printf("\n"); }             
<<EOF>>        { printf("<< END-OF-FILE >>\n"); exit(0); }

%%

char *tname[4] = {"", "", "", "VARIABLE" };     /*Me skopo na trexei to variable me timh 4 sto define
                                                thelei to 4o stoixeio na einai variable opote ta alla 3 kena*/

int main(int argc, char **argv){

   int token;

   if(argc == 3)
   {
      if(!(yyin = fopen(argv[1], "r")))
      {
         fprintf(stderr, "Cannot read file: %s\n", argv[1]);
         return 1;
      }
      if(!(yyout = fopen(argv[2], "w")))
      {
         fprintf(stderr, "Cannot create file: %s\n", argv[2]);
         return 1;
      }
   }
   else if(argc == 2)
   {
      if(!(yyin = fopen(argv[1], "r")))
      {
         fprintf(stderr, "Cannot read file: %s\n", argv[1]);
         return 1;
      }
   }
   while( (token=yylex()) >= 0)
   {
      fprintf(yyout, "\tLine=%d, token=%s, value=\"%s\"\n", line, tname[token-1], yytext);
   }
   return 0;
}
