%{

    /* LAB 6: C-ALGOL YACC ROUTINE*/
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
            *Tokens will be brought in from the lex routine, with some of them 
                (namely 'NUM' and 'ID') having  a type coming from a %union{}

        
        
        Date: March 20, 2020
        ADDED AST ACTION:
            *Implemented syntax directed semantic action that will generate an abstract syntax tree from
                the input.
            *Introduced the AST node, DATATYPE enum, and OPERATOR enum to the union.
            *Made some terminals and nonterminals to be of type node, and others
                to be an element of either the DATATYPE or OPERATOR enums.
            *NO PRODUCTION RULES WERE CHANGED. ONLY ACTION WAS ADDED.
    */

    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "ast.h"
    #include "symtable.h"
    
    extern int lineCount;
    int offset = 0;
    int maxOffset = 0;
    int globalOffset = 0;
    int level = 0;
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
%type <node> expressionStatement returnStatement assignmentStatement selectionStatement iterationStatement

%type < type > typeSpecifier

%type < opType > addop multop relop
%%

program            :   declarationList  { GlobalPointer = $1; }
            ;
            
declarationList    :  declaration   { $$ = $1; }
            |   declaration declarationList     {
                                                    /*
                                                        Connect declarations
                                                        using the next pointer
                                                    */
                                                    $1 -> next = $2;
                                                    $$ = $1;
                                                }
            ;
            
declaration        :   varDeclaration   { $$ = $1; }
            |   funDeclaration  { $$ = $1; }
            ;
            
varDeclaration     :   typeSpecifier varList ';'    { 
                                                        $$ = $2;

                                                        /*
                                                        Make a node, set it equal to
                                                        our current pointer reference
                                                        ($$), and set the datatypes 
                                                        of each of the declared variables
                                                        in the list to be of the typeSpecifier.
                                                        */
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
                                    /*
                                        Declare just a variable
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else 
                                    {
                                        Insert($1, -1, 0, level, 1, offset, NULL); //TODO: Change that -1 to the type of the variable.
                                        Display();
                                        offset = offset + 1;
                                    }
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = 1;
                                }
            |   ID '[' NUM ']'  {
                                    /*
                                        Declare an array
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else
                                    {
                                        Insert($1, -1, 0, level, $3, offset, NULL);
                                        Display();
                                        offset = offset + $3;
                                    }
                                    
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = $3;
                                }
            |   ID ',' varList  {
                                    /*
                                        Declare a comma separated list of
                                        variables (of the same type
                                        of course)
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else 
                                    {
                                        Insert($1, -1, 0, level, 1, offset, NULL); //TODO: Change that -1 to the type of the variable.
                                        offset = offset + 1;
                                    }
                                    
                                    $$ = ASTCreateNode(varDeclaration);
                                    $$->name = $1;
                                    $$->size = 1;
                                    $$-> s1 = $3;
                                }
            |   ID '[' NUM ']' ',' varList  {
                                                /*
                                                    Declare a comma separated list of
                                                    variables (of the same type
                                                    of course)
                                                */
                                                if (Search($1, level, 0) != NULL)
                                                {
                                                    yyerror("Duplicate Variable");
                                                    yyerror($1);
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    Insert($1, -1, 0, level, $3, offset, NULL);
                                                    offset = offset + $3;
                                                }
                                                
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
            
funDeclaration     :   typeSpecifier ID '(' {globalOffset = offset; offset = 0;} params ')' compoundStatement    {
                                                                                /*
                                                                                    Declare a function with a 
                                                                                    return type. If there
                                                                                    are no parameters
                                                                                    in the function, then 
                                                                                    there should at
                                                                                    least be a 'void' in there
                                                                                */
                                                                                $$ = ASTCreateNode(funDeclaration);
                                                                                $$->name = $2;
                                                                                $$->dataType = $1;
                                                                                $$->s1 = $5;
                                                                                $$->s2 = $7;

                                                                                offset = globalOffset;
                                                                            }
            ;
            
params             :   VOID { $$ = NULL; }
            |   paramsList  { $$ = $1; }
            ;
            
paramsList         : param  { $$ = $1; }
            |   param ',' paramsList    {
                                            /*
                                                Each parameter must have its own type
                                                specifier, and it can be just one parameter
                                                or a comma separated list of parameters, again,
                                                each with its own type specifier. Connected by 
                                                the 'next' pointer
                                            */
                                            $$->next = $3;
                                            $$ = $1;
                                        }
            ;
            
param              :    typeSpecifier ID '[' ']'    {
                                                        /*
                                                            Array parameter
                                                        */
                                                        
                                                        $$ = ASTCreateNode(param);
                                                        $$->dataType = $1;
                                                        $$->name = $2;
                                                        $$->size = -1;
                                                    }
            |   typeSpecifier ID    {
                                        /*
                                            Regular parameter
                                        */
                                        if (Search($2, level + 1, 0) != NULL)
                                        {
                                            yyerror("Duplicate Variable");
                                            yyerror($2);
                                            exit(1);
                                        }
                                        else 
                                        {
                                            Insert($2, $1, 0, level + 1, 1, offset, NULL);
                                            offset = offset + 1;
                                        }
                                        $$ = ASTCreateNode(param);
                                        $$->dataType = $1;
                                        $$->name = $2;
                                        $$->size = 0;
                                    }
            ;
            
compoundStatement  :    MYBEGIN { level++; } localDeclarations statementList END {
                                                                        /*
                                                                            Usually follows a function
                                                                            declaration, selection statement,
                                                                            or iteration statement. In any scope,
                                                                            make sure that the variable
                                                                            declarations are put before anything
                                                                            else, or else get a syntax error.
                                                                        */
                                                                        $$ = ASTCreateNode(body);
                                                                        $$->s1 = $3;
                                                                        $$->s2 = $4;
                                                                        offset -= Delete(level);
                                                                        level--;
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
                                            /*
                                                Without this check, we get a sef fault
                                                because we could just have no statement, 
                                                but a statement list followed afterwards.
                                            */
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
            |   selectionStatement { $$ = $1; }
            |   iterationStatement { $$ = $1; }
            |   assignmentStatement { $$ = $1; }
            |   returnStatement { $$ = $1; }
            |   readStatement { $$ = $1; }
            |   writeStatment { $$ = $1; }
            ;
            
expressionStatement :   expression ';'  { $$ = $1; }
            |   ';' { $$ = NULL; }
            ;
            
selectionStatement  :   IF expression THEN statement    {
                                                            /*
                                                                For selection statement, we need to make
                                                                a separate node whose s1 pointer
                                                                will be the positive statement, and
                                                                s2 will be null.
                                                            */
                                                            $$ = ASTCreateNode(selection);
                                                            $$->s1 = $2;
                                                            $$->s2 = ASTCreateNode(selectionBody);
                                                            $$->s2->s1 = $4;
                                                        }
            |   IF expression THEN statement ELSE statement {
                                                                /*
                                                                    For selection statement, we need to make
                                                                    a separate node whose s1 pointer
                                                                    will be the positive statement, and
                                                                    s2 will be the negative statement
                                                                */
                                                                $$ = ASTCreateNode(selection);
                                                                $$->s1 = $2;
                                                                $$->s2 = ASTCreateNode(selectionBody);
                                                                $$->s2->s1 = $4;
                                                                $$->s2->s2 = $6;
                                                            }
            ;
            
iterationStatement  :   WHILE expression DO statement   {
                                                            /*
                                                                Unlike the selection statement,
                                                                it is ok to just make the 
                                                                iteration statement s1 and s2 connect,
                                                                where s1 is the condition and s2 is
                                                                the body.
                                                            */
                                                            $$ = ASTCreateNode(iteration);
                                                            $$->s1 = $2;
                                                            $$->s2 = $4;
                                                        }
            ;
            
assignmentStatement :   var '=' simpleExpression ';'    {
                                                            /*
                                                                We need to make a new node type
                                                                for assignment since '=' is not
                                                                defined in the relop terminal.
                                                            */
                                                            $$ = ASTCreateNode(assignment);
                                                            $$->s1 = $1;
                                                            $$->operator = equals;
                                                            $$->s2 = $3;
                                                        }
            ;
            
returnStatement     : MYRETURN expression ';'   {
                                                    $$ = ASTCreateNode(myReturn);
                                                    $$->s1 = $2;
                                                }
            |   MYRETURN ';'    {
                                    $$ = ASTCreateNode(myReturn);
                                }
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
                                                    /*
                                                        Array reference
                                                    */
                                                    $$ = ASTCreateNode(variable);
                                                    $$->name = $1;
                                                    $$->s1 = $3;
                                                }
            |   ID  {
                        /*
                            Variable reference
                        */
                        $$ = ASTCreateNode(variable);
                        $$->name = $1;
                        $$->s1 = NULL;
                    }
            ;
            
simpleExpression    :   additiveExpression  { $$ = $1; }
            |   simpleExpression relop additiveExpression   {
                                                                /*
                                                                    Compare simpleExpression (LHS) to the
                                                                    additiveExpression (RHS)
                                                                */
                                                                $$ = ASTCreateNode(expression);
                                                                $$->s1 = $1;
                                                                $$->operator = $2;
                                                                $$->s2 = $3;
                                                            }
            ;
            
relop               :   LE  { $$ = le; }
            |   LT  { $$ = lt; }
            |   GT  { $$ = gt; }
            |   GE  { $$ = ge; }
            |   EQ  { $$ = eq; }
            |   NE  { $$ = ne; }
            ;
            
            
additiveExpression  :   term    { $$ = $1; }
            |  additiveExpression addop term { 
                                                /*
                                                    LHS = s1
                                                    operator is addop
                                                    RHS = s2
                                                */
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
                                        /*
                                            LHS = term
                                            operator = multop (can be '*'' '/' ' 'AND' or 'OR')
                                            RHS = the factor
                                        */
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
                            /*
                                This will be a number, and its value will be 
                                1
                            */
                            $$ = ASTCreateNode(myNum);
                            $$->size = 1;
                        }
            |   FALSE   {
                            /*
                                This will be a number, and its value will be 0
                            */
                            $$ = ASTCreateNode(myNum);
                            $$->size = 0;
                        }
            |   NOT factor  {
                                /*
                                    Just for this, we need to make it
                                    an expression rather than an enum because
                                    of the 'NOT' operator.
                                */
                                $$ = ASTCreateNode(expression);
                                $$->operator = myNot;
                                $$->s1 = $2;
                            }
            ;
            
call            :   ID '(' args ')' {
                                        /*
                                            Function call with arguments
                                        */
                                        $$ = ASTCreateNode(myCall);
                                        $$->name = $1;
                                        $$->s1 = $3;
                                    }
            ;
            
args            :   /* Empty */ { $$ = NULL; }
            |   argsList    { $$ = $1; }
            ;
            
argsList        :   expression { 
                                    $$ = ASTCreateNode(argslist);
                                    $$->s1 = $1;
                                    $$->next = NULL; 
                               }
            |   expression ',' argsList {
                                            /*
                                                List of arguments, connected using
                                                the 'next' pointer
                                            */
                                            $$ = ASTCreateNode(argslist);
                                            $$->next = $3;
                                            $$->s1 = $1;
                                        }
            ;

%%

int main() 
{
    yyparse();
    // ASTprint(GlobalPointer, 0);
    // Print Out
}
