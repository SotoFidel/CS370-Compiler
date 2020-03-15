
#
#	Makefile
#	Fidel Soto
#	March 15, 2020
#	Compiles the C, Lex, and Yacc files into one executable (lab6)
#

all:
	yacc -d lab6.y
	lex Lab6.l
	gcc lex.yy.c y.tab.c ast.c -o lab6
