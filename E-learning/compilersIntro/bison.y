%{
    
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int line = 1; 
    int errorFlag = 0;  

    int corr_word = 0;  
    int inv_word = 0;   
    int corr_command = 0;   
    int inv_command = 0;    
    int parenExist = 0; 

    extern char *yytext;
    #define YYSTYPE char *  
        
%}

%token  CHARACTER NUMBER COMMENT OP_EQUAL OP_PLUS OP_MINUS OP_MULT OP_DIVIDE UNKNOWN


%start program

%%

    program 
    :   program COMMENT { $$ = "COMMENT"; corr_word++;
            printf ("\n\n Line %d: ### 2 LETTER",line); }

    |   program CHARACTER NUMBER { $$ = "CHARACTER NUMBER"; corr_word++;
            printf ("\n\n Line %d: ### 2 CHARACTER NUMBER",line); }
    |;
        
%%


int yyerror(void)   {}

extern FILE *yyin;

int main(int argc,char **argv)
{
	int i;
	if(argc == 2)
		yyin=fopen(argv[1],"r");
	else
		yyin=stdin;

	int parse = yyparse();

	if (errorFlag == 0 && parse == 0){
		printf("\nINPUT FILE: PARSING SUCCEEDED.\n");
        printf("\nCORRECT WORDS:%d\n",corr_word);
    }
	else
		printf("\nINPUT FILE: PARSING FAILED.\n");

	return 0;
}