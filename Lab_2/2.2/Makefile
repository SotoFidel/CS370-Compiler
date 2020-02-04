#
#
#		Makefile for Lab 2.2
#		Fidel Soto
#		February 3, 2020
#
#

#Produces the final output for the lab.
#Dependency: lab2_2, which produces lab2docalc.o
all:		lab2_2

#compiles y.tab.c and produces lab2docalc.o object file. 
#Dependencies: y.tab, lex.yy.c
lab2_2:		y.tab  lex.yy.c
		gcc y.tab.c -o lab2docalc

#Lexes lab2docalc.l and produces a c file ( lex.yy.c file).#Dependency: existence of lab2docalc.l 
lex.yy.c: 	lab2docalc.l
		lex lab2docalc.l

#Makes the y.tab.c c and y.tab.h header files. 
#Dependency: the existence of lab2docalc.y
y.tab:		lab2docalc.y
		yacc -d lab2docalc.y
