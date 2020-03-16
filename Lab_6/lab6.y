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
    enum DATATYPE type;
    enum OPERATOR opType;
}

%token INT AND OR VOID BOOL TRUE FALSE NOT IF THEN ELSE READ WRITE MYRETURN WHILE DO LT
%token GT LE GE EQ NE MYBEGIN END
%token < typeInt > NUM
%token < typeString > ID

%type <node> varList varDeclaration declaration declarationList funDeclaration params param paramsList
%type <node> compoundStatement statement statementList localDeclarations writeStatment readStatement
%type <node> expression simpleExpression additiveExpression term factor var call args argsList
%type <node> expressionStatement

%type < type > typeSpecifier

%type < opType > addop multop
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
            |   funDeclaration  { $$ = $1; }
            ;
            
varDeclaration     :   typeSpecifier varList ';'    { 
                                                        $$ = $2;
                                                        struct ASTNodeType *p;
                                                        p = $$;
                                                        while (p != NULL) 
                                                        {
                                                            p->dataType = $1;
                                                            p = p->s1;
                                                        }
                                                    }
            ;
            
varList            :    ID      {
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = 1;
                                }
            |   ID '[' NUM ']'  {
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = $3;
                                }
            |   ID ',' varList  {
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = 1;
                                    $$-> s1 = $3;
                                }
            |   ID '[' NUM ']' ',' varList  {
                                                $$ = ASTCreateNode(varDeclaration);
                                                $$->name = $1;
                                                $$->size = $3;
                                                $$-> s1 = $6;
                                            }
            ;
            
typeSpecifier      :   INT  {
                                $$ = intType;
                            }
            |   VOID        {
                                $$ = voidType;
                            }
            |   BOOL        {
                                $$ = boolType;
                            }
            ;
            
funDeclaration     :   typeSpecifier ID '(' params ')' compoundStatement    {
                                                                                $$ = ASTCreateNode(funDeclaration);
                                                                                $$->name = $2;
                                                                                $$->dataType = $1;
                                                                                $$->s1 = $4;
                                                                                $$->s2 = $6;
                                                                            }
            ;
            
params             :   VOID { $$ = NULL; }
            |   paramsList
            ;
            
paramsList         : param  { $$ = $1; }
            |   param ',' paramsList    {
                                            $$->next = $3;
                                            $$ = $1;
                                        }
            ;
            
param              :    typeSpecifier ID '[' ']'    {
                                                        $$ = ASTCreateNode(param);
                                                        $$->dataType = $1;
                                                        $$->name = $2;
                                                        $$->size = -1;
                                                    }
            |   typeSpecifier ID    {
                                        $$ = ASTCreateNode(param);
                                        $$->dataType = $1;
                                        $$->name = $2;
                                        $$->size = 0;
                                    }
            ;
            
compoundStatement  :    MYBEGIN localDeclarations statementList END {
                                                                        $$ = ASTCreateNode(body);
                                                                        $$->s1 = $2;
                                                                        $$->s2 = $3;
                                                                    }
            ;
            
localDeclarations  :    /* Empty */ { $$ = NULL; }
            |   varDeclaration localDeclarations    { 
                                                        $1->next = $2;
                                                        $$ = $1;
                                                    }
            ;
            
statementList      :    /* Empty */ { $$ = NULL; }
            |   statement statementList {
                                            if ($1 ==  NULL)
                                            {
                                                $$ = $2;
                                            }
                                            else 
                                            {
                                                $1->next = $2;
                                                $$ = $1;
                                            }
                                        }
            ;
            
statement          :    expressionStatement { $$ = $1; }
            |   compoundStatement { $$ = $1; }
            |   selectionStatement { $$ = NULL; }
            |   iterationStatement { $$ = NULL; }
            |   assignmentStatement { $$ = NULL; }
            |   returnStatement { $$ = NULL; }
            |   readStatement { $$ = $1; }
            |   writeStatment { $$ = $1; }
            ;
            
expressionStatement :   expression ';'  { $$ = $1; }
            |   ';' { $$ = NULL; }
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
            
readStatement       :   READ var ';'    {
                                            $$ = ASTCreateNode(myRead);
                                            $$->s1 = $2;
                                        }
            ;
            
writeStatment       :   WRITE expression ';'    {
                                                    $$ = ASTCreateNode(myWrite);
                                                    $$->s1 = $2;
                                                }
            ;
            
expression          :   simpleExpression    { $$ = $1; }
            ;
            
var                 :   ID '[' expression ']'   {
                                                    $$ = ASTCreateNode(variable);
                                                    $$->name = $1;
                                                    $$->s1 = $3;
                                                }
            |   ID  {
                        $$ = ASTCreateNode(variable);
                        $$->name = $1;
                        $$->s1 = NULL;
                    }
            ;
            
simpleExpression    :   additiveExpression  { $$ = $1; }
            |   simpleExpression relop additiveExpression   { $$ = NULL; }
            ;
            
relop               :   LE
            |   LT
            |   GT
            |   GE
            |   EQ
            |   NE
            ;
            
            
additiveExpression  :   term    { $$ = $1; }
            |  additiveExpression addop term { 
                                                $$ = ASTCreateNode(expression);
                                                $$->s1 = $1;
                                                $$->operator = $2;
                                                $$->s2 = $3;
                                             }
            ;
                    
addop               :   '+' { $$ = plus; }
            |   '-' { $$ = minus; }
            ;
            
term                :   factor  { $$ = $1; }
            |   term multop factor  { 
                                        $$ = ASTCreateNode(expression);
                                        $$->s1 = $1;
                                        $$->operator = $2;
                                        $$->s2 = $3;
                                    }
            ;

            
multop          :   '*' { $$ = mult; }
            |   '/' { $$ = division; }
            |   AND { $$ = myAnd; }
            |   OR  { $$ = myOr; }
            ;
            
factor          :   '(' expression ')'  { $$ = $2; }
            |   NUM {
                        $$ = ASTCreateNode(myNum);
                        $$->size = $1;
                    }
            |   var { $$ = $1; }
            |   call    { $$ = $1; }
            |   TRUE    {
                            $$ = ASTCreateNode(myNum);
                            $$->size = 1;
                        }
            |   FALSE   {  
                            $$ = ASTCreateNode(myNum);
                            $$->size = 0;
                        }
            |   NOT factor  { 
                                $$ = ASTCreateNode(expression);
                                $$->operator = myNot;
                                $$->s1 = $2;
                            }
            ;
            
call            :   ID '(' args ')' {
                                        $$ = ASTCreateNode(myCall);
                                        $$->name = $1;
                                        $$->s1 = $3;
                                    }
            ;
            
args            :   /* Empty */ { $$ = NULL; }
            |   argsList    { $$ = $1; }
            ;
            
argsList        :   expression { $$ = $1; }
            |   expression ',' argsList { 
                                            $$->next = $3;
                                            $$ = $1;
                                        }
            ;

%%

int main() 
{
    yyparse();
    ASTprint(GlobalPointer, 0);
    // Print Out
}
