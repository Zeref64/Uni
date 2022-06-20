%{
    
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int line = 1;  
    int errorFlag = 0;
    int testFlag = 0;
    int corr_word = 0;
    int inv_word = 0;
    int corr_command = 0;
    int parenExist = 0;
    extern char *yytext;    
    #define YYSTYPE char *  
        
%}

%token PAREN_L PAREN_R ARROW

INTCONST FLOAT_POINT 

DEF_FACT  DEF_RULE TEST BIND READ_TEXT PRINT_TEXT NAME 

VARIABLE STRING

OP_EQUAL OP_PLUS OP_MINUS OP_MULT OP_DIVIDE


%start program

%%

    program 
        :   program PAREN_L define{ 
            if (!strcmp($3,"DEF_FACT")){
                printf("\n\n Line %d: ### FACT DEFINITION COMPOSITION",line);
                corr_command++;
            }
                
            else if (!strcmp($3,"DEF_RULE")){
                printf("\n\n Line %d: ### RULE DEFINITION COMPOSITION",line);
                corr_command++;
            }
                
            else if (!strcmp($3,"TEST")){
                printf("\n\n Line %d: ### NUMBER TEST FUNCTION",line);
                corr_command++;
            }
                
            else if (!strcmp($3,"BIND")){
                printf("\n\n Line %d: ### INTEGER ASSIGNMENT",line);
                corr_command++;
            }
	}

	|   program PAREN_L fact PAREN_R { 
		printf ("\n\n Line %d: ### FACT DECLARATION",line); 
		corr_command++; }
	
	|   program prepare_calc {
		printf ("\n\n Line %d: ### NUMERIC OPERATION",line);
		corr_command++; }

	|   program PAREN_L OP_EQUAL compare PAREN_R { printf ("\n\n Line %d: ###NUMBER COMPARISON ",line); corr_command++;}
	|   
       
    define 
        :   DEF_RULE statement PRINT_TEXT print PAREN_R PAREN_R{ $$ = "DEF_RULE"; testFlag=0; parenExist=0;}
        |   DEF_FACT statement PAREN_R { 
		$$ = "DEF_FACT";

		parenExist = 0;

		if(testFlag){
		  printf("\nTEST statement not allowed in DEFFACTS syntax\n");
		  printf("\nINPUT FILE: PARSING FAILED.\n");
		  exit(0);}
		}
        |   test PAREN_R   { $$ = "TEST"; }
        |   bind PAREN_R   { $$ = "BIND"; }

    print 
        :   PAREN_L text PAREN_R
        |   print print

    text 
        :   STRING
        |   VARIABLE
        |   text text

    statement
        :   NAME statement
        |   PAREN_L fact PAREN_R {
		printf("\n \t### FACT COMPOSITION");
		
		if(parenExist){
			printf("\nDouble Parenthesis Detected. Please follow UNI-Clips proper syntax.\n");
			printf("\nINPUT FILE: PARSING FAILED.\n");
	                exit(0);}
		}

        |   PAREN_L test PAREN_R ARROW PAREN_L{
		if(testFlag){
		  printf("\nDuplicate TEST-> statement not allowed.\n");
                  printf("\nINPUT FILE: PARSING FAILED.\n");
		  exit(0);
		 }
		testFlag=1;
		
		if(parenExist){ 
                printf("\nDouble Parenthesis Detected. Please follow UNI-Clips proper syntax.\n"); 
                printf("\nINPUT FILE: PARSING FAILED.\n");
                exit(0);}

		parenExist=1;
		}
        |   statement statement  

    fact
        :   NAME	{ $$ = $1; } 
        |   VARIABLE    { $$ = $1; }
	|   value	{ $$ = $1; }
	|   fact fact

    value
        :   INTCONST    { $$ = "INTCONST"; }
        |   FLOAT_POINT	{ $$ = "FLOAT_POINT"; }

    test
        :   TEST PAREN_L OP_EQUAL compare PAREN_R
    
    compare
        :   argument prepare_calc {
            if (!strcmp($1, "VARIABLE"))
                printf("\n \t### VARIABLE-OPERATIONAL SEQUENCE COMPARISON");

            else 
                printf("\n \t### INTEGER-OPERATIONAL SEQUENCE COMPARISON");
            }  

        |   prepare_calc argument { 
            if (!strcmp($2, "VARIABLE"))
                printf("\n \t### VARIABLE-OPERATIONAL SEQUENCE COMPARISON");

            else 
                printf("\n \t### INTEGER-OPERATIONAL SEQUENCE COMPARISON");
            } 

        |   VARIABLE INTCONST {printf ("\n \t### VARIABLE-INTEGER COMPARISON");}
        |   INTCONST VARIABLE {printf ("\n \t### INTEGER-VARIABLE COMPARISON");}

    argument 
        :   VARIABLE    { $$ = "VARIABLE"; }
        |   INTCONST    { $$ = "INTCONST"; }        
    
    prepare_calc
        :   PAREN_L operator calc calc PAREN_R {
	    if(!strcmp($2,"OP_PLUS"))
		printf("\n \t### ADDITION OPERATION");

	    else if(!strcmp($2,"OP_MINUS"))
		printf("\n \t### SUBTRACTION OPERATION");

	    else if(!strcmp($2,"OP_MULT"))
		printf("\n \t### MULTIPLICATION OPERATION");

	    else
		printf("\n \t### DIVISION OPERATION"); }  

    operator
        :   OP_PLUS   { $$ = "OP_PLUS"; }
        |   OP_MINUS  { $$ = "OP_MINUS"; }
        |   OP_MULT   { $$ = "OP_MULT"; }
        |   OP_DIVIDE { $$ = "OP_DIVIDE"; }
     
    calc
        :   INTCONST    { $$ = "INTCONST"; }
        |   VARIABLE    { $$ = "VARIABLE"; }
        |   calc calc   

    bind 
        :   BIND VARIABLE content {
            if (!strcmp($3,"READ_TEXT"))
		printf("\n \t### STDIN VAR ASSIGNMENT");
	    else
                printf("\n \t### NUMERIC OPERATION VAR ASSIGNMENT");
            }
        |   BIND VARIABLE INTCONST { printf ("\n \t INT ASSIGNMENT"); }

    content
        :   PAREN_L READ_TEXT PAREN_R { $$ = "READ_TEXT"; }
        |   prepare_calc { $$ = "OPERATIONAL SEQUENCE"; }
        
%%


int yyerror(void)   
{}

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
		printf("\nINPUT FILE: PARSING SUCCEEDED.\n", parse);
        
		printf("\nΣΩΣΤΕΣ ΛΕΞΕΙΣ:%d\n",corr_word);

	        printf("\nΣΩΣΤΕΣ ΕΚΦΡΑΣΕΙΣ:%d\n",corr_command);
       
		 printf("\nΛΑΘΟΣ ΛΕΞΕΙΣ:%d\n",inv_word);
    }
	else
		printf("\nINPUT FILE: PARSING FAILED.\n", parse);

	return 0;
}
