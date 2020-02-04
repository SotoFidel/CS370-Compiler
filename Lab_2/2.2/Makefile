all: lab2_2

lab2_2: y.tab  lex.yy.c
	gcc y.tab.c -o lab2docalc

lex.yy.c: lab2docalc.l
	lex lab2docalc.l

y.tab: lab2docalc.y
	yacc -d lab2docalc.y
