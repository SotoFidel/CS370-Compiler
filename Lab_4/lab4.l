%{

/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015

		  Modified by: Fidel Soto
		  January 31 2020
		  Changes:
			  *Added a lex directive for when a parenthesis '(' or ')'
			  are detected. The c code accompanying the directive
			  prints the lex file and outputs  the character to the
			  yacc file. Lines 36-37
			  
          February 21, 2020
          Changes:
              *Added rule for ';'
              *Added rule for int so that it returns INT
              *Modified variable rule so that it can be a longer word
*/


int mydebug=0;
#include "y.tab.h"
%}


%%
int             { return (INT); }
[a-zA-Z][a-zA-Z0-9]*	{if (mydebug) fprintf(stderr,"Variable found: %s \n", yytext); 
                       yylval.typeString = strdup(yytext); return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Number found\n"); 
                       yylval.typeInt = atoi( ( const char * )yytext ); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|;] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
\(|\)		{if (mydebug) fprintf(stderr, "found a parenthesis %c\n", *yytext);
		       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}



