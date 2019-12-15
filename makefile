Filename = limbaj

all:
	yacc -d iac.y
	lex lex.l
	gcc lex.yy.c y.tab.c -lfl -o test

