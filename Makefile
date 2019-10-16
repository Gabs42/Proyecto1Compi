all: calc

proyecto1Parser.tab.c proyecto1Parser.tab.h:	proyecto1Parser.y
	bison -d proyecto1Parser.y

lex.yy.c: proyecto1Scanner.l
	flex proyecto1Scanner.l

calc: lex.yy.c proyecto1Parser.tab.c 
	gcc -o a.out  lex.yy.c proyecto1Parser.tab.c -lfl
