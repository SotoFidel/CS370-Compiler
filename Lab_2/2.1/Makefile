#
#
#	Makefile for Lab 2.1
#	Fidel Soto
#	February 3, 2020
#
#

#Final output. This is dependent on creating lab2remove object file.
all:		lab2remove

#Compile lex.yy.c and produces lab2remove.o (object file).
#Dependent on lex.yy.c
lab2remove:	lex.yy.c
		gcc -o lab2remove lex.yy.c

#lexes lab2remove.l and produces a c file (lex.yy.c).
#Dependent on the existence of lab2remove.l
lex.yy.c:	lab2remove.l
		lex lab2remove.l
