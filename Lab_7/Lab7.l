%{
    /* LAB 6: C-ALGOL LEX ROUTINE*/
    /*
        Written by: Fidel Soto
    */
    /*
        Date: March 1, 2020
        INITIAL IMPLEMENTATION:
            *Implemented lex rules that adhere to the C-Algol specification.
                For now, the lex routine returns tokens and will print out
                constants that it comes accross.
        

        Date: March 20, 2020
        NO CHANGES TO THIS FILE
    */
    #include "ast.h"
    #include "y.tab.h"
    #include <stdio.h>
    int lineCount = 1;
%}

%%
int                     { return (INT); }
and                     { return (AND); }
or                      { return (OR); }
void                    { return (VOID); }
boolean                 { return (BOOL); }
true                    { return (TRUE); }
false                   { return (FALSE); }
not                     { return (NOT); }
if                      { return (IF); }
then                    { return (THEN); }
else                    { return (ELSE); }
read                    { return (READ); }
write                   { return (WRITE); }
return                  { return (MYRETURN); }
while                   { return (WHILE); }
do                      { return (DO); }
"<"                     { return (LT); }
">"                     { return (GT); }
"<="                    { return (LE); }
">="                    { return (GE); }
"=="                    { return (EQ); }
"!="                    { return (NE); }
"begin"                 { return (MYBEGIN); }
"end"                   { return (END); }
[a-zA-Z][a-zA-Z0-9]*    { yylval.typeString = strdup(yytext);
                          return (ID); 
                        }
[0-9][0-9]*             { yylval.typeInt = atoi( (const char *)yytext);
                          return (NUM); 
                        }
[+\-=%*/\[\]\(\),;]     { return (*yytext);  }
[ \t]                   {}
\n                      { lineCount++; }
%%

int yywrap()
{
}
