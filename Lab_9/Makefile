
#
#	Makefile
#	Fidel Soto
#	May 6, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab9)
#

all:
	yacc -d lab9.y
	lex lab9.l
	gcc lex.yy.c y.tab.c ast.c symtable.c emit.c -o lab9
clean:
	rm y.tab.c y.tab.h lex.yy.c lab9