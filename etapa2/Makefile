#João Pedro Gubert de Souza
#Samuel Rudnicki

#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: y.tab.c lex.yy.c
	cc -o etapa2 lex.yy.c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y
	
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c y.tab.h y.output etapa2
