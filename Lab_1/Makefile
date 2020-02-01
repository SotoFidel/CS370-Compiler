#
#
#	Makefile for Lab1
#	Fidel Soto
#	January 24, 2020
#
#

#Produces the final output. Dependent on lab1
all:	lab1

#Compiles lex.yy.c and produces the lab1 object file. Dependent on lex.yy.c
lab1:	lex.yy.c
	gcc -o lab1 lex.yy.c

#Lexes wordlengthlab1.l and produces the lexed c file (lex.yy.c). Dependent on wordlengthlab1.l
lex.yy.c:	wordlengthlab1.l
	lex wordlengthlab1.l
