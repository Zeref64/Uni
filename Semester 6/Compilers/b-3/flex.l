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
void myerror (const char *msh);

%}

PAREN_L		[\(]
PAREN_R		[\)]
ARROW		->
WHITESPACE	[ |\t|\r|\f]
INTCONST	0+|[+-]?[1-9]+[0-9]*
FLOAT_POINT	(\+|-)?([0-9])+((e(-)?|E(-)?)?[0-9]+|\.([0-9])+(e(-)?[0-9]+|E(-)?[0-9]+)?)
DEF_FACT	deffacts
DEF_RULE	defrule
TEST		test
BIND		bind
READ_TEXT	read
PRINT_TEXT	printout
NAME		([a-z]|[A-Z])+([0-9]|_|-|([a-z]|[A-Z]))*
VARIABLE	\?([a-z]|[A-Z]|[0-9])+
STRING		\"([^\\\n\"]|((\\\\)+)|((\\\")+)|((\\n)+))*\"
COMMENT		;.*
OP_EQUAL	(=)
OP_PLUS		(\+)
OP_MINUS	(\-)
OP_MULT		(\*)
OP_DIVIDE	(\/)

%%

{PAREN_L}	{formatPrint("LEFT_PAREN"); return PAREN_L ;}
{PAREN_R}	{formatPrint("RIGHT_PAREN"); return PAREN_R;}
{ARROW}		{formatPrint("EXECUTE"); corr_word++; return ARROW;}
{WHITESPACE}	{ ; }

{INTCONST}	{ formatPrint("INTCONST"); corr_word++; return INTCONST; }
{FLOAT_POINT}	{ formatPrint("FLOAT_POINT"); corr_word++; return FLOAT_POINT; }

{DEF_FACT}	{ formatPrint("DEF_FACT"); corr_word++; return DEF_FACT; }
{DEF_RULE}	{ formatPrint("DEF_RULE"); corr_word++; return DEF_RULE; }
{TEST}		{ formatPrint("TEST"); corr_word++; return TEST; } 
{BIND}		{ formatPrint("BIND"); corr_word++; return BIND; }
{READ_TEXT}	{ formatPrint("READ_TEXT"); corr_word++; return READ_TEXT; }
{PRINT_TEXT}	{ formatPrint("PRINT_TEXT"); corr_word++; return PRINT_TEXT; }
{NAME}		{ formatPrint("NAME"); corr_word++; return NAME; }

{VARIABLE}	{ formatPrint("VARIABLE"); corr_word++; return VARIABLE; }
{STRING}	{ formatPrint("STRING"); corr_word++; return STRING; }
{COMMENT}	{ ; }
{OP_EQUAL}	{ formatPrint("EQUAL"); corr_word++; return OP_EQUAL;}
{OP_PLUS}	{ formatPrint("OP_PLUS"); corr_word++; return OP_PLUS;}
{OP_MINUS}	{ formatPrint("OP_MINUS"); corr_word++; return OP_MINUS;}
{OP_MULT}	{ formatPrint("OP_MULT"); corr_word++; return OP_MULT;}
{OP_DIVIDE}	{ formatPrint("OP_DIVIDE"); corr_word++; return OP_DIVIDE;}

\n              { line++; printf("\n"); }

.		{ myerror ("-- INVALID TOKEN --"); BEGIN(error);  inv_word++; return TOKEN_ERROR;}

<error>[ \t]+	{BEGIN(0);}
<error>.	{inv_word++;}
<error>\n	{BEGIN(0);line++;printf("\n");}


%%

void formatPrint(char *s)
{
	printf("\n\t%s >> %s ", s, yytext);
	return;
}

void myerror (const char *msg)
{
	fprintf(yyout,"\n\tERROR line %d at lexeme \'%s\':%s\n",line,yytext,msg);
}
