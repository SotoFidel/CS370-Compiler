%{
    #include "y.tab.h"
    #include <stdio.h>
    int lineCount = 1;
    int myDebug = 1;
%}

%%
int                     { return(INT); }
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
                          fprintf(stderr, "Constant found with value %d\n", yylval.typeInt);
                          return (NUM); 
                        }
[+\-=%*/\[\]\(\),;]     { return (*yytext);  }
[ \t]                   {}
\n                      { lineCount++; }
%%

int yywrap()
{
	fprintf(stderr, "Done\n");
}
