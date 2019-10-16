# Proyecto1Compi

Pasos para compilar el proyecto  

1. bison -d proyecto1Parser.y  
2. flex proyecto1Scanner.l  
3. gcc lex.yy.c proyecto1Parser.tab.c -lfl  
