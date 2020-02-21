%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
   
   Modified by: Fidel Soto
   February 3, 2020
   Changes: 
	    *In the lex file, a parentheses are now returned so now there's no more syntax errors.Now
	     the the YACC file will successfully take the parenthesis input from the LEX file.
	    *The unary minus problem in lines 101-102 was fixed. The first 'expr' in 
	     'expr '-' expr %prec MINUS' was removed. Since the operator is unary,
	     it doesn't make sense that there's a left hand 'expr'
	    *Added a rule for multiplication at lines 91-92  which will multiple the left hand ($1)
	     and right hand ($3) sides.
	     
    
    February 21, 2020
    Changes:
        *Added conditionals in the YACC side to make sure that 
            1) Variables are Declared successfully
            2) Variables aren't declared more than twice
            3) Undeclared Variables Can't be used.
*/


	/* begin specs */
int yylex();

#include <stdio.h>
#include <ctype.h>
#include "symtable.h"

#define REGSMAX 5

int regs[REGSMAX];
int base, debugsw;
int offset = 0;
int errFlag = 0;



void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union {
    int typeInt;
    char *typeString;
}

%token < typeInt > INTEGER
%token INT
%token < typeString > VARIABLE
%type < typeInt > expr

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

program : DECLS list
        ;

DECLS   : DEC DECLS
        | /*Empty*/
        ;

DEC     :   INT VARIABLE ';' '\n'
            { 
				if (Search($2) == 0) {
                    //Variable wasn't declared, so it can be declared.
					if ((offset) == REGSMAX) {
                        //Max Variable number reached
						fprintf(stderr, "Error. Max Variable Limit Reached\n");
					} else {
                        //The variable can be successfully inserted.
						Insert($2, offset++);
					}
				} else {
                    //Variable was already declared, so it can't be declared again.
					fprintf(stderr, "Error. Variable already declared\n");
				}
			}
        ;

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{
                //Added this conditional to make sure that an erronous 
                //answer isn't printed when an Undeclared variable 
                //is used.
				if (errFlag == 1) 
				{
					errFlag = 0;
				}
				else 
				{
					fprintf(stderr,"the anwser is %d\n", $1);
				}
			}
	|	VARIABLE '=' expr ';'
			{ 
				if (Search($1) != 1) {
                    //Variable was not declared. Error.
					fprintf(stderr, "Error. Variable has not been declared.\n");
				} else {
                    //Declared variable's address is set to the 'expr' on the right side.
					regs[fetchAddress($1)] = $3; 
				}
			}
	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '*' expr
			{ $$ = $1 * $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|	'-' expr	%prec UMINUS
			{ $$ = -$2; }
	|	VARIABLE
			{ 
				if (Search($1)!= 1) 
				{
                    //Print error and dont set $$. Instead set errFlag to 1 so that
                    //in 'expr' the return value isn't printed.
					fprintf(stderr, "WARNING: Variable %s  has not been declared.\n", $1);
					errFlag = 1;
				}
				else
				{ 
					$$ = regs[ fetchAddress($1) ];
				}
			}
	|	INTEGER {
                    $$=$1;
		        }
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
