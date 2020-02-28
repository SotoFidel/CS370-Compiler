%{
    #include <stdio.h>
    #include <ctype.h>
    #include "lex.yy.c"
    
    void yyerror (s)  /* Called by yyparse on error */
     char *s;
    {
        printf ("%s\n", s);
    }
    
    extern int lineCount;

%}

%start program

%token INT AND OR VOID BOOL TRUE FALSE NOT IF THEN ELSE READ WRITE MYRETURN WHILE DO LT
%token GT LE GE EQ NE MYBEGIN END NUM ID
%%

program            :   declarationList
            ;
declarationList    :   /*Empty*/
            |   declaration
            |   declaration declarationList
            ;
declaration        :   varDeclaration
            |   funDeclaration
            ;
varDeclaration     :   typeSpecifier varList
            ;
varList            :    ID
            |   ID '[' NUM ']'
            |   ID',' varList
            |   ID '[' NUM ']' ',' varList
            ;
typeSpecifier       :   INT
            |   VOID
            |   BOOL
            ;
funDeclaration      :   typeSpecifier ID '(' params ')' compuntStatement
            ;
%%

int main() 
{
    yyparse();
}
