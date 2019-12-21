Filename = limbaj

all:
	yacc -d --verbose experiment_hash.y
	lex lex.l
	gcc lex.yy.c y.tab.c `pkg-config --cflags --libs glib-2.0` -lfl -o test