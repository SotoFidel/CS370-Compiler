all:
	yacc -d lab4.y
	lex lab4.l
	gcc lex.yy.c y.tab.c symtable.c -o lab4
