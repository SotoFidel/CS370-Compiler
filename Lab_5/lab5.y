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
            *Tokens will be brought in from the lex routine, with some of them having 
             a type (namely 'NUM' and 'ID') coming from a %union{}
    */

    int yylex();
    
    #include <stdio.h>
    #include <ctype.h>
    
    extern int lineCount;
    
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
}

%token INT AND OR VOID BOOL TRUE FALSE NOT IF THEN ELSE READ WRITE MYRETURN WHILE DO LT
%token GT LE GE EQ NE MYBEGIN END
%token < typeInt > NUM
%token < typeString > ID

%%

program            :   declarationList
            ;
            
declarationList    :  declaration
            |   declaration declarationList
            ;
            
declaration        :   varDeclaration
            |   funDeclaration
            ;
            
varDeclaration     :   typeSpecifier varList ';'
            ;
            
varList            :    ID
            |   ID '[' NUM ']'
            |   ID ',' varList
            |   ID '[' NUM ']' ',' varList
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
            
simpleExpression    :   simpleExpression relop additiveExpression
            |   additiveExpression
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
            |   NUM
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
}
