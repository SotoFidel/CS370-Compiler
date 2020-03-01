
#
#	Makefile
#	Fidel Soto
#	March 1, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab5)
#

all:
	yacc -d lab5.y
	lex Lab5.l
	gcc lex.yy.c y.tab.c -o lab5
