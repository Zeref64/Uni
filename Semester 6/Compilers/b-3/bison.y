%{
    
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int line = 1;  //Μετρητής Αριθμού Γραμμών
    int errorFlag = 0;  //Flag για Error στο parsing
    int testFlag = 0;   //Flag εντοπισμού κανόνα test μέσα σε κανόνα deffacts
                        //Όταν ενεργοποιείται, αν υπάρχει test σε κανόνα deffacts,
                        //τότε το πρόγραμμα κάνει exit με Error και κατάλληλο μήνυμα
    int corr_word = 0;  //Μετρητής σωστών λέξεων
    int inv_word = 0;   //Μετρητής λάθος λέξεων (TOKEN_ERROR)
    int corr_command = 0;   //Μετρητής σωστών εντολών
    int inv_command = 0;    //Μετρητής λάθος λέξεων
    int parenExist = 0; //Flag ελέγχου διπλής αριστερής παρένθεσης
    extern char *yytext;    
    #define YYSTYPE char *  
        
%}

%token PAREN_L PAREN_R ARROW TOKEN_ERROR

INTCONST FLOAT_POINT 

DEF_FACT  DEF_RULE TEST BIND READ_TEXT PRINT_TEXT NAME 

VARIABLE STRING

OP_EQUAL OP_PLUS OP_MINUS OP_MULT OP_DIVIDE


%start program

%%

    program 
        :   program PAREN_L define{
            //Σύνταξη DEFFACTS
            if (!strcmp($3,"DEF_FACT")){
                printf("\n\n Line %d: ### FACT DEFINITION COMPOSITION",line);
                corr_command++;
            }
            //Σύνταξη DEFRULE    
            else if (!strcmp($3,"DEF_RULE")){
                printf("\n\n Line %d: ### RULE DEFINITION COMPOSITION",line);
                corr_command++;
            }
            //Σύνταξη TEST
            else if (!strcmp($3,"TEST")){
                printf("\n\n Line %d: ### NUMBER TEST FUNCTION",line);
                corr_command++;
            }
            //Σύνταξη BIND
            else if (!strcmp($3,"BIND")){
                printf("\n\n Line %d: ### INTEGER ASSIGNMENT",line);
                corr_command++;
            }
	}

	|   program PAREN_L fact PAREN_R {
        //Σύνταξη ενός γεγονότος 
		printf ("\n\n Line %d: ### FACT DECLARATION",line); 
		corr_command++; }
	
	|   program prepare_calc {
        //Σύνταξη αριθμητικής πράξης
		printf ("\n\n Line %d: ### NUMERIC OPERATION",line);
		corr_command++; }

	|   program PAREN_L OP_EQUAL compare PAREN_R {
        //Σύγκριση Αριθμών
        printf ("\n\n Line %d: ###NUMBER COMPARISON ",line);
        corr_command++;}
	|   program TOKEN_ERROR {}
	|   ;
       
    define 
        :   DEF_RULE statement PRINT_TEXT print PAREN_R PAREN_R{
            $$ = "DEF_RULE";
            testFlag=0; //Μετά την ολοκλήρωση της DEF_RULE, το testFlag ξαναμηδενίζεται
            parenExist=0;   //Μετά την ολοκλήρωση της DEF_RULE, το parenExist flag ξαναμηδενίζεται
            }
        |   DEF_FACT statement PAREN_R { 
		    $$ = "DEF_FACT";

		    parenExist = 0; //Μετά την ολοκλήρωση της DEF_RULE, το parenExist flag ξαναμηδενίζεται

            //Αν εσφαλμένα έχουμε συντάξει κανόνα test μέσα σε DEFFACTS, το πρόγραμμα απορρίπτει την είσοδο και τερματίζει
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
	|   text {
        //Ο χρήστης νομίζει πως μετά την printout, αυτά προς εκτύπωση δε χρειάζεται να είναι σε παρενθέσεις
		printf("\n\tWARNING! Data to be printed must be encased in parenthesis.\n");
		inv_command++;
		yyerrok;} 

    text 
        :   STRING
        |   VARIABLE
        |   text text

    statement
        :   NAME statement
        |   PAREN_L fact PAREN_R {
		printf("\n \t### FACT COMPOSITION");
		
        //Αν γνωρίζει το κώδικα από πίσω και προσπαθεί να προσπεράσει τον κανόνα της statement: ...test...
        //τότε το πρόγραμμα απορρίπτει την είσοδο και τερματίζει
		if(parenExist){
			printf("\nDouble Parenthesis Detected. Please follow UNI-Clips proper syntax.\n");
			printf("\nINPUT FILE: PARSING FAILED.\n");
	                exit(0);}
		}

        |   PAREN_L test PAREN_R ARROW PAREN_L{
        //Ο χρήστης βάζει διπλή Test στην defrule, ενώ επιτρέπεται ακριβώς και μόνο μία
        //Ο έλεγχος γίνεται στη δεύτερη εμφάνιση test κανόνα
		if(testFlag){
		  printf("\nDuplicate TEST-> statement not allowed.\n");
                  printf("\nINPUT FILE: PARSING FAILED.\n");
		  exit(0);
		 }
         //Ενεργοποίηση του testFlag μετά από την πρώτη εμφάνιση κανόνα test
		testFlag=1;
		
        //Αν γνωρίζει το κώδικα από πίσω και προσπαθεί να προσπεράσει τον κανόνα της statement: ...test...
        //τότε το πρόγραμμα απορρίπτει την είσοδο και τερματίζει
		if(parenExist){ 
                printf("\nDouble Parenthesis Detected. Please follow UNI-Clips proper syntax.\n"); 
                printf("\nINPUT FILE: PARSING FAILED.\n");
                exit(0);}

        //Ενεργοποίηση του parenExist flag μετά τον πρώτο test κανόνα
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
            {//Σύνταξη test
            }
    
    compare
        :   argument prepare_calc {
////Όλα τα πιθανά ζεύγη συγκρίσεων
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
	|   ;

    argument 
        :   VARIABLE    { $$ = "VARIABLE"; }
        |   INTCONST    { $$ = "INTCONST"; }
	|   ;
    
    prepare_calc
        :   PAREN_L operator calc calc PAREN_R {
	    if(!strcmp($2,"OP_PLUS"))
		printf("\n \t### ADDITION OPERATION");

	    else if(!strcmp($2,"OP_MINUS"))
		printf("\n \t### SUBTRACTION OPERATION");

	    else if(!strcmp($2,"OP_MULT"))
		printf("\n \t### MULTIPLICATION OPERATION");

	    else
		printf("\n \t### DIVISION OPERATION");}
	|   PAREN_L operator calc operator calc PAREN_R {
            if(!strcmp($2,"OP_PLUS"))
                printf("\n \t### ADDITION OPERATION");
            else if(!strcmp($2,"OP_MINUS"))
                printf("\n \t### SUBTRACTION OPERATION");
            else if(!strcmp($2,"OP_MULT"))
                printf("\n \t### MULTIPLICATION OPERATION");
            else
                printf("\n \t### DIVISION OPERATION");
            //Ο χρήστης καταλάθος πάτησε space ανάμεσα στο πρόσημο και τον αριθμό
            printf ("\n\tWARNING! Only one operation can be done.\n\tDid you mean to input a signed number?\n");
	    inv_command++;
	    yyerrok;}
	|   PAREN_L calc operator calc PAREN_R {
        //Ο χρήστης προσπάθησε να συντάξει πράξη με in-order σειρά
        printf ("\n\tWARNING! Operations must be stated in pre-order.\n\tEx. + 1 2 3 4\n");
		inv_command++;
		yyerrok;}

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
	|   BIND VARIABLE PAREN_L NAME PAREN_R {
        //Ο χρήστης έκανε ορθογραφικό λάθος στη λέξη "read". Ή έβαλε εντελώς λάθος λέξη
		printf("\n\tWARNING!\n\tDid you mean \"(bind <var> (read))\" ?\n");
		inv_command++;
		yyerrok;}

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
		printf("\nINPUT FILE: PARSING SUCCEEDED.\n");
        
		printf("\nΣΩΣΤΕΣ ΛΕΞΕΙΣ:%d\n",corr_word);

	    printf("\nΣΩΣΤΕΣ ΕΚΦΡΑΣΕΙΣ:%d\n",corr_command);
       
		printf("\nΛΑΘΟΣ ΛΕΞΕΙΣ:%d\n",inv_word); //TOKEN_ERRORs

		printf("\nΛΑΘΟΣ ΕΚΦΡΑΣΕΙΣ:%d\n",inv_command); //Μετρητής Warning
    }
	else
		printf("\nINPUT FILE: PARSING FAILED.\n");

	return 0;
}
