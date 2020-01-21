Filename = limbaj

all:
	yacc -d --verbose yacc.y
	lex lex.l
	gcc lex.yy.c y.tab.c `pkg-config --cflags --libs glib-2.0` -lfl -g -o test 
