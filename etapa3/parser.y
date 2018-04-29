%{
//João Pedro Gubert de Souza
//Samuel Rudnicki

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "hash.h"


int yylex();
void yyerror(char* erro);
void stringError(void);
%}

%union {
	HASH *symbol;
	AST *ast;
}

//adicao de tokens dos operadores novos
%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_TO
%token KW_READ
%token KW_RETURN
%token KW_PRINT
%token OPERATOR_PLUS
%token OPERATOR_MINUS
%token OPERATOR_MULT
%token OPERATOR_DIV
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR
%token OPERATOR_L
%token OPERATOR_G
%token OPERATOR_NEG

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER
%token<symbol> LIT_REAL
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING
%token TOKEN_ERROR

%type<ast> program
%type<ast> decl
%type<ast> dec
%type<ast> decvar
%type<ast> decvetor
%type<ast> decfunction
%type<ast> decpointer
%type<ast> typevar
%type<ast> literal
%type<ast> exp
%type<ast> cmd
%type<ast> lcmd

//prioridade de baixo pra cima. Tu sabe se precisa colocar a prioridade de todos os operadores?
%right OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left OPERATOR_L OPERATOR_G
%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_PLUS OPERATOR_MINUS
%left OPERATOR_MULT OPERATOR_DIV
%left OPERATOR_NEG
%%

program: decl			{$$ = $1; astPrint($$,0);}
;

decl: dec decl		{$$ = astCreate(AST_DECLIST,0,$1,$2,0,0);}
	|
	;

dec: decvar				{$$ = astCreate(AST_DECVAR,$1,0,0,0,0);}
	| decvetor
	| decfunction
	| decpointer
	;

decvar: typevar TK_IDENTIFIER '=' literal ';'
	;

decvetor: typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ':' decv ';'
	|typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
	;

decfunction: typevar TK_IDENTIFIER '(' paramlist ')' body

decpointer: typevar '#' TK_IDENTIFIER '=' literal ';'

decv:	LIT_INTEGER decv
	| LIT_CHAR decv
	| LIT_REAL decv
	| ' ' decv
	|
	;

typevar: KW_CHAR
	| KW_INT
	| KW_FLOAT
	;

literal: LIT_INTEGER
	| LIT_CHAR
	| LIT_REAL
	;

paramlist: typevar TK_IDENTIFIER rest
	| literal rest
	| TK_IDENTIFIER rest
	|
	;

rest: ',' typevar TK_IDENTIFIER rest
	| ',' literal rest
	| ',' TK_IDENTIFIER rest
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
	;

attribution: TK_IDENTIFIER '=' exp
	| TK_IDENTIFIER '[' exp ']' '=' exp
	;

flux_control: KW_IF '(' exp ')' KW_THEN cmd
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
	| KW_WHILE '(' exp ')' cmd
	| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp')' cmd
	;

inout: KW_PRINT print_elem
	| KW_READ TK_IDENTIFIER
	| KW_RETURN exp
	;

print_elem: LIT_STRING
	| LIT_STRING print_elem
	| LIT_STRING ' ' print_elem
	| exp
	| exp print_elem
	| exp ' ' print_elem
	;

exp: TK_IDENTIFIER
	| TK_IDENTIFIER '[' exp ']'
	| '#'TK_IDENTIFIER
	| '&'TK_IDENTIFIER
	| LIT_INTEGER 	{$$ = astCreate(AST_SYMBOL, $1,0,0,0,0);}
	| LIT_CHAR
	| exp OPERATOR_PLUS exp
	| exp OPERATOR_MINUS exp
	| exp OPERATOR_MULT exp
	| exp OPERATOR_DIV exp
	| exp OPERATOR_L exp
	| exp OPERATOR_G exp
	| OPERATOR_NEG exp
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

//#include "main.c"

void yyerror(char *erro){
	fprintf(stderr, "line: %d - Syntax error!\n", getLineNumber());
	stringError();
	exit(3);
}
