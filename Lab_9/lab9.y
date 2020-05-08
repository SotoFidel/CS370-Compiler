%{

    /* LAB 7: C-ALGOL YACC ROUTINE*/
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

        
        Date: April 13, 2020
        ADDED SEMANTIC ACTION FOR SYMBOL TABLE
            *Added a global variable called 'level' that denotes the current level that a variable is in.
             The level increments at the beginning of a function or a compound statement, and then decrements
             once we exit.
            *Added action that will insert a new variable into the symbol table IF the variable doesn't exist,
             thereby preventing duplicate functions and variabled, and assigns that symbol to the variable's 
             'symbol' symbol table pointer.
            *Added exitence and type checking to make sure that when a variable is used, that it has been
             declared before, and to make sure that a variable's type is being used correctly. Also added 
             checking to make sure that whether a variable is being used correctly in terms of it being a
             function, scalar, or array.
            *Added a variable called 'typeOfData' that will assign a type to variables once they're declared.
            *Added a variabled called 'maxOffset' that will help determine the max offset that a function
             will need at the very least.
        
        Date: May 6, 2020
        Added more functionality to the main() function so that it requires a -o flag followed by a file name, with an optional
        -d flag for debugging to call ASTprint() and Display() if it is activated
    */

    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "symtable.h"
    #include "ast.h"
    #include "emit.h"
   
    
    extern int lineCount;
    int mydebug = 0;
    int offset = 0;
    int maxOffset = 0;
    int globalOffset = 0;
    int level = 0;
    int maxOffset;
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
%token < typeString > ID STRING

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
                                                            p->symbol->Type = $1;
                                                            p = p->s1;
                                                        }
                                                    }
            ;

     
varList            :    ID      {
                                    /*
                                        Declare just a variable
                                    */

                                    /*
                                        Check if the variable has already been declared.
                                        If it has already been declared, throw an error. 
                                        Otherwise, insert the symbol.
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else 
                                    {
                                        /*
                                            IsAFunc Definitions: 
                                            0 - Scalar
                                            1 - Function 
                                            2 - Array
                                            TODO: Modify the inserts
                                        */
                                        $$ = ASTCreateNode(varDeclaration);
                                        $$->name = $1;
                                        $$->size = 1;  
                                        
                                        /*
                                            IsAFunc Definitions: 
                                            0 - Scalar
                                            1 - Function 
                                            2 - Array
                                            TODO: Modify the inserts
                                        */                  
                                        $$->symbol = Insert($1, -1, 0, level, 1, offset, NULL); 
                                        offset = offset + 1;
                                    }
                                    
                                }
            |   ID '[' NUM ']'  {
                                    /*
                                        Declare an array
                                    */

                                    /*
                                        Check if the variable has already been declared.
                                        If it has already been declared, throw an error. 
                                        Otherwise, insert the symbol.
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else
                                    {
                                        
                                        $$ = ASTCreateNode(varDeclaration);
                                        $$->name = $1;
                                        $$->size = $3;
                                        
                                        /*
                                            IsAFunc Definitions: 
                                            0 - Scalar
                                            1 - Function 
                                            2 - Array
                                            TODO: Modify the inserts
                                        */          
                                        $$->symbol = Insert($1, -1, 2, level, $3, offset, NULL);
                                       
                                        offset = offset + $3;
                                    }
                                    

                                }
            |   ID ',' varList  {
                                    /*
                                        Declare a comma separated list of
                                        variables (of the same type
                                        of course)
                                    */

                                    /*
                                        Check if the variable has already been declared.
                                        If it has already been declared, throw an error. 
                                        Otherwise, insert the symbol.
                                    */
                                    if (Search($1, level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                    }
                                    else 
                                    {
                                        /*
                                            IsAFunc Definitions: 
                                            0 - Scalar
                                            1 - Function 
                                            2 - Array
                                            TODO: Modify the inserts
                                        */       
                                        $$ = ASTCreateNode(varDeclaration);
                                        $$->name = $1;
                                        $$->size = 1;
                                        $$-> s1 = $3;    
                                        $$->symbol = Insert($1, -1, 0, level, 1, offset, NULL); 
                                        offset = offset + 1;
                                       
                                    }
                                    

                                }
            |   ID '[' NUM ']' ',' varList  {
                                                /*
                                                    Declare a comma separated list of
                                                    variables (of the same type
                                                    of course)
                                                */

                                                /*
                                                    Check if the variable has already been declared.
                                                    If it has already been declared, throw an error. 
                                                    Otherwise, insert the symbol.
                                                 */
                                                if (Search($1, level, 0) != NULL)
                                                {
                                                    yyerror("Duplicate Variable");
                                                    yyerror($1);
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    /*
                                                        IsAFunc Definitions: 
                                                        0 - Scalar
                                                        1 - Function 
                                                        2 - Array
                                                        TODO: Modify the inserts
                                                    */        
                                                    $$ = ASTCreateNode(varDeclaration);
                                                    $$->name = $1;
                                                    $$->size = $3;
                                                    $$-> s1 = $6;   
                                                    $$->symbol = Insert($1, -1, 2, level, $3, offset, NULL);
                                                    offset = offset + $3;
                                                   
                                                }
                                                

                                            }
            ;
            
typeSpecifier      :   INT  {
                                /*
                                    Set the type of data to int
                                */
                                $$ = intType;
                            }
            |   VOID        {
                                /*
                                    Set the type of data to void
                                */
                                $$ = voidType;
                            }
            |   BOOL        {
                                /*
                                    Set the type of data to int
                                */
                                $$ = boolType;
                            }
            ;
            
funDeclaration     :   typeSpecifier ID '(' {
                                                /*
                                                    Make sure that the function hasn't
                                                    been declared before. If it has,
                                                    throw an error. Otherwise, insert
                                                    the symbol
                                                */
                                                if (Search($2, level, 0) != NULL)
                                                {
                                                    yyerror("Function has already been declared");
                                                    yyerror($2);
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    /*
                                                        IsAFunc Definitions: 
                                                        0 - Scalar
                                                        1 - Function 
                                                        2 - Array
                                                        TODO: Modify the inserts
                                                    */                                                             
                                                    Insert($2, $1, 1, level, 0, 0, NULL);
                                                }
                                                globalOffset = offset;
                                                offset = 2;
                                                maxOffset = offset;
                                            } params ')' {
                                                            /*
                                                                Search will indefinitely work here,
                                                                since the name was inserted already.
                                                                Set fparms to the list of parameters
                                                            */
                                                            Search($2, level, 0)->fparms = $5;
                                                         } compoundStatement    {
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
                                                                                    $$->s2 = $8;
                                                                                    $$->symbol = Search($2, 0, 0);

                                                                                    offset = globalOffset;

                                                                                    /*
                                                                                        THIS is when the size of the function
                                                                                        will be set.
                                                                                    */
                                                                                    Search($2, 0, 0)->mysize = maxOffset;
                                                                                    $$->size = maxOffset;
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

                                                        /*
                                                            Check if there isn't a duplicate in the 
                                                            parameter list. If there is, throw an 
                                                            error. Otherwise insert the symbol
                                                        */
                                                        /*
                                                            IsAFunc Definitions: 
                                                            0 - Scalar
                                                            1 - Function 
                                                            2 - Array
                                                            TODO: Modify the inserts
                                                        */         
                                                        if (Search($2, level + 1, 0) != NULL)
                                                        {
                                                            yyerror("Duplicate Variable");
                                                            yyerror($2);
                                                            exit(1);
                                                        }
                                                        else
                                                        {
                                                            $$ = ASTCreateNode(param);
                                                            $$->dataType = $1;
                                                            $$->name = $2;
                                                            $$->size = -1;
                                                            $$->semanticType = $1;
                                                            $$->symbol = Insert($2, $1, 2, level + 1, 1, offset, NULL);
                                                            offset = offset + 1;
                                                        }
                                                       
                                                    }
            |   typeSpecifier ID    {
                                        /*
                                            Regular parameter
                                        */
                                        
                                        /*
                                            Check if there isn't a duplicate in the 
                                            parameter list. If there is, throw an 
                                            error. Otherwise insert the symbol
                                        */
                                        if (Search($2, level + 1, 0) != NULL)
                                        {
                                            yyerror("Duplicate Variable");
                                            yyerror($2);
                                            exit(1);
                                        }
                                        else 
                                        {
                                            $$ = ASTCreateNode(param);
                                            $$->dataType = $1;
                                            $$->name = $2;
                                            $$->size = 0;
                                            $$->semanticType = $1;
                                            $$->symbol = Insert($2, $1, 0, level + 1, 1, offset, NULL);
                                            offset = offset + 1;
                                        }
                                        
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
                                                                        /*
                                                                            When we enter the compoundstatement, 
                                                                            we increment the level, and when we 
                                                                            exit the level, we decrement the level.
                                                                        */
                                                                        $$ = ASTCreateNode(body);
                                                                        $$->s1 = $3;
                                                                        $$->s2 = $4;
                                                                        if (offset > maxOffset) maxOffset = offset;
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
            
expressionStatement :   expression ';'  { 
                                            $$ = ASTCreateNode(exprStmt);
                                            $$->s1 = $1;
                                         }
            |   ';' { $$ = ASTCreateNode(exprStmt);
                                            $$->s1 = NULL;
                    }
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
                                                            if ($1->semanticType != $3->semanticType)
                                                            {
                                                                yyerror("Type mismatch on assignment");
                                                                exit(1);
                                                            }
                                                            $$ = ASTCreateNode(assignment);
                                                            
                                                            $$->name=CreateTemp();
                                                            $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                                            offset++;

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
            |   WRITE STRING ';'                {
                                                    $$ = ASTCreateNode(myWrite);
                                                    $$->name = $2;
                                                    $$->label = genlabel();
                                                }
            ;
            
expression          :   simpleExpression    { $$ = $1; }
            ;

/*
    IsAFunc Definitions: 
    0 - Scalar
    1 - Function 
    2 - Array
    TODO: Modify the inserts
*/           
var                 :   ID '[' expression ']'   {
                                                    /*
                                                        Array reference
                                                    */
                                                    /*
                                                        Make sure that the variable exists, and that 
                                                        it is being used in the correct context. If either of 
                                                        these conditions are not met, then we throw an error.
                                                    */
                                                    struct SymbTab *s;
                                                    s = Search($1, level, 1);
                                                    if (s == NULL) 
                                                    {
                                                        yyerror("Variable has not been declared");
                                                        exit(1);
                                                    }
                                                    if (s->IsAFunc != 2)
                                                    {
                                                        yyerror("This reference needs to be an array");
                                                        exit(1);
                                                    }
                                                    $$ = ASTCreateNode(variable);
                                                    $$->name = $1;
                                                    $$->s1 = $3;
                                                    $$->symbol = s;
                                                    $$->semanticType = s->Type;
                                                }
            |   ID  {
                        /*
                            Variable reference
                        */
                        /*
                            Make sure that the variable exists, and that 
                            it is being used in the correct context. If either of 
                            these conditions are not met, then we throw an error.
                        */
                        struct SymbTab *s;
                        s = Search($1, level, 1);
                        if (s == NULL) 
                        {
                            yyerror("Variable has not been declared");
                            exit(1);
                        }
                        if (s->IsAFunc != 0)
                        {
                            yyerror("This reference needs to be a scalar");
                            exit(1);
                        }
                        $$ = ASTCreateNode(variable);
                        $$->name = $1;
                        $$->s1 = NULL;
                        $$->symbol = s;
                        $$->semanticType = s->Type;
                    }
            ;
            
simpleExpression    :   additiveExpression  { $$ = $1; }
            |   simpleExpression relop additiveExpression   {
                                                                /*
                                                                    Compare simpleExpression (LHS) to the
                                                                    additiveExpression (RHS)
                                                                */
                                                                if ($1->semanticType != $3->semanticType)
                                                                {
                                                                    yyerror("Type mismatch");
                                                                    exit(1);
                                                                }
                                                                $$ = ASTCreateNode(expression);
                                                                $$->name=CreateTemp();
                                                                $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                                                offset++;
                                                                $$->s1 = $1;
                                                                $$->operator = $2;
                                                                $$->s2 = $3;
                                                                $$->semanticType = $1->semanticType;
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
                                                if ($1->semanticType != $3->semanticType)
                                                {
                                                    yyerror("Type mismatch");
                                                    exit(1);
                                                }
                                                $$ = ASTCreateNode(expression);
                                                $$->name=CreateTemp();
                                                $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                                offset++;
                                                $$->s1 = $1;
                                                $$->operator = $2;
                                                $$->s2 = $3;
                                                $$->semanticType = $1->semanticType;
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
                                        if ($1->semanticType != $3->semanticType)
                                        {
                                            yyerror("Type mismatch");
                                            exit(1);
                                        }
                                        $$ = ASTCreateNode(expression);
                                        $$->name=CreateTemp();
                                        $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                        offset++;
                                        $$->s1 = $1;
                                        $$->operator = $2;
                                        $$->s2 = $3;
                                        $$->semanticType = $1->semanticType;
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
                        $$->semanticType = intType;
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
                            $$->semanticType = boolType;
                        }
            |   FALSE   {
                            /*
                                This will be a number, and its value will be 0
                            */
                            $$ = ASTCreateNode(myNum);
                            $$->size = 0;
                            $$->semanticType = boolType;
                        }
            |   NOT factor  {
                                /*
                                    Just for this, we need to make it
                                    an expression rather than an enum because
                                    of the 'NOT' operator.
                                */
                                if ($2->semanticType != boolType)
                                {
                                    yyerror("the 'not' operator needs a BOOLEAN on right hand side");
                                    exit(1);
                                }
                                $$ = ASTCreateNode(expression);
                                $$->name=CreateTemp();
                                $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                offset++;
                                $$->operator = myNot;
                                $$->s1 = $2;
                                $$->semanticType = $2->semanticType;
                            }
            ;
            
call            :   ID '(' args ')' {
                                        /*
                                            Function call with arguments
                                        */
                                        struct SymbTab *s;
                                        s = Search($1, level, 1);
                                        if (s == NULL) 
                                        {
                                            yyerror("function has not been declared");
                                            exit(1);
                                        }
                                        if (s->IsAFunc != 1)
                                        {
                                            yyerror("This reference needs to be a function call");
                                            exit(1);
                                        }
                                        /*
                                            Check the formal parameters versus the actual parameters.
                                        */
                                        if (checkFormalsAndParms(s->fparms, $3) != 1)
                                        {
                                            yyerror("Function actual and formal parameters mismatch");
                                            exit(1);
                                        }
                                        $$ = ASTCreateNode(myCall);
                                        $$->name = $1;
                                        $$->s1 = $3;
                                        $$->symbol = s;
                                        $$->semanticType = s->Type;
                                    }
            ;
            
args            :   /* Empty */ { $$ = NULL; }
            |   argsList    { $$ = $1; }
            ;
            
argsList        :   expression { 
                                    $$ = ASTCreateNode(argslist);
                                    $$->name=CreateTemp();
                                    $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                    offset++;
                                    $$->s1 = $1;
                                    $$->semanticType = $1->semanticType;
                                    $$->next = NULL; 
                               }
            |   expression ',' argsList {
                                            /*
                                                List of arguments, connected using
                                                the 'next' pointer
                                            */
                                            $$ = ASTCreateNode(argslist);
                                            $$->name=CreateTemp();
                                            $$->symbol=Insert($$->name,intType,0,level,1,offset, NULL);
                                            offset++;
                                            $$->semanticType = $1->semanticType;
                                            $$->next = $3;
                                            $$->s1 = $1;
                                        }
            ;

%%

/*
    PRECONDITION: Require a -o flag with a file name, with an optional debug -d flag.
    POSTCONDITION: Will Parse the input, print out the symbol table and tree structure if -d flag is added,
    and will emit code to the specified file name

    argc - Argument Count
    argv - Argument char* vector
*/
int main(int argc, char*argv[])  
{
    int i = 1;
    char s[100];
    FILE *fp; // file pointer
    int foundIt = 0;
    while ( i < argc)
    {
        // Check if our arguments contain -d
        if (strcmp(argv[i],"-d") == 0)
        {
            printf("Debugging mode activated. Symbol table and AST will be printed\n");
            mydebug = 1;
            i++;
        }
        else if (strcmp(argv[i], "-o") == 0)
        {// we assume that i+1 is the file that we want to open (sans the extension)
            if ( argc > i + 1) foundIt = 1;
            sprintf(s, "%s.asm",argv[i+1]);
            i+=2;
        }
        else 
        {
            i++;
        }

        // Check for -o with a file name. this MUST be passed as an argument 

    }

    /*
        We want to open a file descriptor and use that variable
        to write to the file
    */
    if (foundIt == 0){
        printf("You must provide a -o with an argument\n");
        exit(1);
    }
    fp = fopen(s,"w");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n",s);
        exit(1);
    }

    yyparse();
    
    // Print out the table and tree if -d is added.
    if (mydebug){
        printf("\n\nLAST DISPLAY\n");
        Display();
        printf("\n\n");
        ASTprint(GlobalPointer, 0);
    }
    
    // Define the data segment
    fprintf(fp, "# Globals\n");
    fprintf(fp, ".data\n\n");

    // Print out strings with corresponding labels
    emitStrings(fp, GlobalPointer);

    // NewLine string definition
    fprintf(fp,"_NL:\t .asciiz\t\"\\n\"\n");
    fprintf(fp,"\n.align 2\n\n");

    // Emit global variables
    emitGlobals(fp, GlobalPointer);

    // Print out the text segment, and define main as the main function
    fprintf(fp, "\n.text\n\n");
    fprintf(fp, ".globl main");

    // Print out mips code to the file
    emitAST(GlobalPointer, fp);
    
}
