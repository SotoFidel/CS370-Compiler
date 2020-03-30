
#
#	Makefile
#	Fidel Soto
#	March 21, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab6)
#

all:
	yacc -d lab6.y
	lex Lab6.l
	gcc lex.yy.c y.tab.c ast.c -o lab6
run: all
	./lab6 < lab6test.al > lab6testoutput.txt
	clear
clean:
	rm y.tab.c y.tab.h lex.yy.c lab6