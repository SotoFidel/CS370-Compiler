
#
#	Makefile
#	Fidel Soto
#	March 21, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab6)
#

all:
	yacc -d lab7.y
	lex lab7.l
	gcc lex.yy.c y.tab.c ast.c symtable.c -o lab7
run: all
	./lab7 < lab6test.al > lab6testoutput.txt
	clear
clean:
	rm y.tab.c y.tab.h lex.yy.c lab7