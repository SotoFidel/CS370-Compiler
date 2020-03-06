%{

    /* LAB 5: C-ALGOL YACC ROUTINE*/
    /*
        Written by: Fidel Soto
    */
    /*
        Date: March 1, 2020

        INITIAL IMPLEMENTATION:
            *Implemented the rules based on the 'Extended BNF Grammar for C-Algol'
                documentation for our language. In addition to the initial implementation,
                the yacc routine will also throw syntax errors with the corresponding line
                number. The line number variable is declared in Lab5.l.
            *Tokens will be brought in from the lex routine, with some of them (namely 'NUM' and 'ID') having 
             a type coming from a %union{}
    */

    int yylex();
    
    #include "ast.h"
    #include <stdio.h>
    #include <ctype.h>
    
    extern int lineCount;
    ASTNode *GlobalPointer;
    
    void yyerror (s)  /* Called by yyparse on error */
     char *s;
    {
        printf ("%s on line %d\n", s, lineCount);
    }

%}

%start program

%union {
    int typeInt;
    char *typeString;
    struct ASTNodeType * node;
}

%token INT AND OR VOID BOOL TRUE FALSE NOT IF THEN ELSE READ WRITE MYRETURN WHILE DO LT
%token GT LE GE EQ NE MYBEGIN END
%token < typeInt > NUM
%token < typeString > ID

%type <node> varList varDeclaration declaration declarationList

%%

program            :   declarationList  { GlobalPointer = $1; }
            ;
            
declarationList    :  declaration   { $$ = $1; }
            |   declaration declarationList     { 
                                                    $1 -> next = $2;
                                                    $$ = $1;
                                                }
            ;
            
declaration        :   varDeclaration   { $$ = $1; }
            |   funDeclaration  { $$ = NULL; }
            ;
            
varDeclaration     :   typeSpecifier varList ';'    { $$ = $2; }
            ;
            
varList            :    ID      {
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                }
            |   ID '[' NUM ']'  {
                                    fprintf(stderr, "Constant found value %d\n", $3);
                                    $$ = NULL;
                                }
            |   ID ',' varList  {
                                    $$ = NULL;
                                }
            |   ID '[' NUM ']' ',' varList  {
                                                fprintf(stderr, "Constant found value %d\n", $3);
                                                $$ = NULL;
                                            }
            ;
            
typeSpecifier      :   INT
            |   VOID
            |   BOOL
            ;
            
funDeclaration     :   typeSpecifier ID '(' params ')' compoundStatement
            ;
            
params             :   VOID
            |   paramsList
            ;
            
paramsList         : param
            |   param ',' paramsList
            ;
            
param              :    typeSpecifier ID '[' ']'
            |   typeSpecifier ID
            ;
            
compoundStatement  :    MYBEGIN localDeclarations statementList END
            ;
            
localDeclarations  :    /* Empty */
            |   varDeclaration localDeclarations
            ;
            
statementList      :    /* Empty */
            |   statement statementList
            ;
            
statement          :    expressionStatement
            |   compoundStatement
            |   selectionStatement
            |   iterationStatement
            |   assignmentStatement
            |   returnStatement
            |   readStatement
            |   writeStatment
            ;
            
expressionStatement :   expression ';'
            |   ';'
            ;
            
selectionStatement  :   IF expression THEN statement
            |   IF expression THEN statement ELSE statement
            ;
            
iterationStatement  :   WHILE expression DO statement
            ;
            
assignmentStatement :   var '=' simpleExpression ';'
            ;
            
returnStatement     : MYRETURN expression ';'
            |   MYRETURN ';'
            ;
            
readStatement       :   READ var ';'
            ;
            
writeStatment       :   WRITE expression ';'
            ;
            
expression          :   simpleExpression
            ;
            
var                 :   ID '[' expression ']'
            |   ID
            ;
            
simpleExpression    :   additiveExpression
            |   simpleExpression relop additiveExpression
            ;
            
relop               :   LE
            |   LT
            |   GT
            |   GE
            |   EQ
            |   NE
            ;
            
            
additiveExpression  :   term
            |  additiveExpression addop term
            ;
                    
addop               :   '+'
            |   '-'
            ;
            
term                :   factor
            |   term multop factor
            ;

            
multop          :   '*'
            |   '/'
            |   AND
            |   OR
            ;
            
factor          :   '(' expression ')'
            |   NUM {
                        fprintf(stderr, "Constant found value %d\n", $1);
                    }
            |   var
            |   call
            |   TRUE
            |   FALSE
            |   NOT factor
            ;
            
call            :   ID '(' args ')'
            ;
            
args            :   /* Empty */
            |   argsList
            ;
            
argsList        :   expression ',' argsList
            |   expression
            ;

%%

int main() 
{
    yyparse();
    ASTprint(GlobalPointer, 0);
    // Print Out
}
