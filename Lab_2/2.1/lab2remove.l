%{         
            /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
 
         */
        int comment = 0;
        int debug = 1;  /* prints out debug statements if desired */
        int linecount = 1;
%}


%%

"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n", linecount);
	comment = 1;
	}

"*/"	{
            if (!comment) printf(" >>>>>>>> line %d: Unexpexted comment termination <<<<<<<<<<\n", linecount);
            comment = 0;
	}
\n      {linecount++;}
.       ;
%%

int yywrap(void)
{ return 1;
}

int main()
{
  yylex();
  
}

