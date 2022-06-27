%option noyywrap
%x error

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bison.tab.h"

extern int flag;
extern int line; 
extern int corr_word;
extern int inv_word;


void formatPrint(char *s);

%}

CHARACTER   ([a-z]|[A-Z])+
NUMBER		[0-9]+		
COMMENT		;.*
OP_EQUAL	(=)
OP_PLUS		(\+)
OP_MINUS	(\-)
OP_MULT		(\*)
OP_DIVIDE	(\/)

%%

{CHARACTER}	{ formatPrint("CHARACTER"); return CHARACTER; }
{NUMBER}	{ formatPrint("NUMBER"); return NUMBER; }	
{COMMENT}	{ formatPrint("COMMENT"); }
{OP_EQUAL}	{ formatPrint("EQUAL"); corr_word++; return OP_EQUAL;}
{OP_PLUS}	{ formatPrint("OP_PLUS"); corr_word++; return OP_PLUS;}
{OP_MINUS}	{ formatPrint("OP_MINUS"); corr_word++; return OP_MINUS;}
{OP_MULT}	{ formatPrint("OP_MULT"); corr_word++; return OP_MULT;}
{OP_DIVIDE}	{ formatPrint("OP_DIVIDE"); corr_word++; return OP_DIVIDE;}

.		{ errorPrn (" UNKNOWN"); BEGIN(error);  inv_word++; return UNKNOWN;}

<error>[ \t]+	{BEGIN(0);}
<error>.	{inv_word++;}
<error>\n	{BEGIN(0); line++; printf("\n");}

\n		{ line++; printf("\n"); } 


%%

void formatPrint(char *s)
{
	printf("\n\t%s >> %s ", s, yytext);
	return;
}

void errorPrn (const char *msg)
{
	fprintf(yyout,"\n\tERROR line %d at lexeme \'%s\': %s\n",line,yytext,msg);
}