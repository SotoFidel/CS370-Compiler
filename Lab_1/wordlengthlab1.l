     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
        
        Modified by: Fidel Soto
        Date: January 24, 2020
        Changes:
                *Added a variable (numCounter) to count the number of Numbers for a given input.
                *Added a lex directive that will increment numCounter if a number ( defined by the regex [0-9]+ ) is detected.
                *Added a print statement to the yywrap() function that will tell the usert how many numbers there are in the input
   */
	int lgths[100];
	int numCounter = 0;
%%
[a-zA-Z]+	lgths[yyleng]++;
[0-9]+      { numCounter++; }
.	|
\n	;
%%
int yywrap()
{
	int i;
	printf("Length  No. words\n");
	
	//Print the number of words of length i
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	
	//Print the number of numbers
	printf("\nThere are %d numbers\n\n in this input", numCounter);
	return(1);
}

int main()
{
 yylex();

}
