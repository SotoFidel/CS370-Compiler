%{         
            /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
		
	    Modified by: Fidel Soto
	    Date: January 31, 2020
	    Changes: 
			*Added a variable (linecount) that will count lines
			from the input (comment.tst in this case) whenever
			a newline is detected  and, if there's an error on
			that line, an errror will be printed.
			*set 'debug' to true (1) to see the output of said error messages
			*Got rid of some code that printed every other character, which
			got in the way of the actual error print statements.
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
            if (!comment) printf(" >>>>>>>> line %d: Unexpected comment termination <<<<<<<<<<\n", linecount);
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

