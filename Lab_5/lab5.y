%{
    // #include <stdio.h>
    // #include <ctype.h>
    // #include "lex.yy.c"
    
    void yyerror (s)  /* Called by yyparse on error */
     char *s;
    {
        printf ("%s\n", s);
    }
    
    int lineCount;

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
declarationList    :   /* Empty*/
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
paramsList         : /* Empty */
            |   param ',' paramsList
            |   param
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
            |   statement
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
assignmentStatement :   var '=' expression ';'
            ;
returnStatement     : MYRETURN expression ';'
            |   MYRETURN ';'
            ;
readStatement       :   READ ID ';' /*CHANGE*/
            ;
writeStatment       :   WRITE expression ';'
            ;
expression          :   simpleExpression
            ;
var                 :   ID '[' expression ']'
            |   ID '['']'
            ;
simpleExpression    :   additiveExpression relop additiveExpression
            |   additiveExpression
            ;
relop               :   LE
            |   LT
            |   GT
            |   GE
            |   EQ
            |   NE
            ;
additiveExpression  :   term zomAOT
            ;
zomAOT              :   /* Empty */
            |   addop term zomAOT
            ;
addop               :   '+'
            |   '-'
            ;
term            :   factor zomMF
            ;
zomMF           :   /* Empty */
            |   multop factor zomMF
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
argsList        :   expression ',' expression
            |   expression
            ;


%%

int main() 
{
    yyparse();
}
