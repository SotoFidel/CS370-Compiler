
#
#	Makefile
#	Fidel Soto
#	February 29, 2020
#	Compiles the C, Lex, and Yacc files into one executiable (lab4)
#

all:
	yacc -d lab4.y
	lex lab4.l
	gcc lex.yy.c y.tab.c symtable.c -o lab4
