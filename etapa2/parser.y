%{
	//João Pedro Gubert de Souza
	//Samuel Rudnicki
	#include <stdio.h>
	#include <stdlib.h>

%}

%token KW_BYTE
%token KW_SHORT
%token KW_LONG
%token KW_DOUBLE

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

dec: decvar
	| decvetor
	| decfunction
	;

decvar: TK_IDENTIFIER ':' typevar '=' literal ';'
	;

decvetor: TK_IDENTIFIER ':' typevar '[' LIT_INTEGER ']' decv ';'
	|	TK_IDENTIFIER ':' typevar '[' LIT_INTEGER ']' ';'
	;

decfunction: '(' typevar ')' TK_IDENTIFIER '(' paramlist ')' cmd

decv:	LIT_INTEGER decv
	| LIT_CHAR ' ' decv
	| LIT_REAL ' ' decv
	|
	;

typevar: KW_BYTE
	| KW_FLOAT
	| KW_SHORT
	| KW_LONG
	| KW_DOUBLE
	;

literal: LIT_INTEGER
	| LIT_CHAR
	| LIT_REAL
	;

paramlist: TK_IDENTIFIER ':' typevar rest
	| literal rest
	| TK_IDENTIFIER rest
	|
	;

rest: ',' TK_IDENTIFIER ':' typevar rest
	| ',' literal rest
	| TK_IDENTIFIER rest
	|
	;


cmd: attribution
	| flux_control
	| inout
	| body
	|
	;

body: '{' lcmd '}'
	;

lcmd: cmd ';' lcmd
	| dec lcmd
	| cmd
	|
	;

attribution: TK_IDENTIFIER '=' exp
	| TK_IDENTIFIER '[' exp ']' '=' exp
	;

flux_control: KW_IF '(' exp ')' KW_THEN cmd
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
	| KW_WHILE '(' exp ')' cmd
	;

inout: KW_PRINT print_elem
	| KW_READ '>' TK_IDENTIFIER
	| KW_RETURN '(' exp ')'
	;

print_elem: LIT_STRING
	| LIT_STRING ',' print_elem
	| exp
	| exp ',' print_elem
	|
	;

exp: TK_IDENTIFIER
	| TK_IDENTIFIER '[' exp ']'
	| LIT_INTEGER
	| LIT_CHAR
	| exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
	| exp '<' exp
	| exp '>' exp
	| '!' exp
	| '(' exp ')'
	| exp OPERATOR_LE exp
	| exp OPERATOR_GE exp
	| exp OPERATOR_EQ exp
	| exp OPERATOR_NE exp
	| exp OPERATOR_AND exp
	| exp OPERATOR_OR exp
	| TK_IDENTIFIER '(' paramlist ')'
	;



%%

int getLineNumber();
void initMe();


#include "main.c"

int yyerror(int code){
	fprintf(stderr, "line: %d - Syntax error!\n", getLineNumber());
	stringError();
	exit(3);
}
