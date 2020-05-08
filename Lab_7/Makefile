
#
#	Makefile
#	Fidel Soto
#	April 13, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab7)
#

all:
	yacc -d lab7.y
	lex lab7.l
	gcc lex.yy.c y.tab.c ast.c symtable.c -o lab7
run: all
	clear
	./lab7 < lab7test.al > lab7output.txt
clean:
	rm y.tab.c y.tab.h lex.yy.c lab7