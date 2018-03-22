%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_RETURN
%token KW_PRINT

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%%

program: decl
;

decl: dec decl
	|
	;

dec:  KW_INT TK_IDENTIFIER ';'
	| KW_INT TK_IDENTIFIER '(' paramlist ')' body
	;

paramlist: TK_IDENTIFIER rest
	;

rest: ',' TK_IDENTIFIER rest
	|
	;

body: '{' lcmd '}'
;

lcmd: cmd lcmd
	|
	;

cmd: TK_IDENTIFIER '=' exp
	| KW_IF '(' exp ')' cmd cmd
	;

exp: TK_IDENTIFIER
	| LIT_INTEGER
	| exp '+' exp
	| exp '-' exp
	| TK_IDENTIFIER '(' ')'
	;

%%

#include "main.c"

int yyerror(int code){
	fprintf(stderr, "Syntax error!\n");
	exit(3);
}
