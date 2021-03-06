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
%token <symbol>KW_CHAR
%token <symbol>KW_INT
%token <symbol>KW_FLOAT
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

%type<ast> program decl dec decvar decvetor decfunction decpointer decv typevar literal paramlist rest cmd body lcmd attribution flux_control inout print_elem exp


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
	|		{$$ = astCreate(AST_EMPTY,0,0,0,0,0);}
	;

dec: decvar			{$$ = astCreate(AST_DEC,0,$1,0,0,0);}
	| decvetor		{$$ = astCreate(AST_DEC,0,$1,0,0,0);}
	| decfunction		{$$ = astCreate(AST_DEC,0,$1,0,0,0);}
	| decpointer		{$$ = astCreate(AST_DEC,0,$1,0,0,0);}
	;

decvar: typevar TK_IDENTIFIER '=' literal ';'		{$$ = astCreate(AST_DECVAR,$2,$1,$4,0,0);}
	;

decvetor: typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ':' decv ';'	{$$ = astCreate(AST_DECVEC_A,$2,$1,astCreate(AST_VEC_SIZE, $4, 0, 0, 0, 0),$7,0);}
	|typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ';'			{$$ = astCreate(AST_DECVEC_B,$2,$1,astCreate(AST_VEC_SIZE,$4,0,0,0,0),0,0);}
	;

decfunction: typevar TK_IDENTIFIER '(' paramlist ')' body		{$$ = astCreate(AST_DECFUNC,$2,$1,$4,$6,0);}

decpointer: typevar '#' TK_IDENTIFIER '=' literal ';'		{$$ = astCreate(AST_DECPOINT,$3,$1,$5,0,0);}

decv:	LIT_INTEGER decv				{$$ = astCreate(AST_DECV_A,$1,$2,0,0,0);}
	| LIT_CHAR decv					{$$ = astCreate(AST_DECV_A,$1,$2,0,0,0);}
	| LIT_REAL decv					{$$ = astCreate(AST_DECV_A,$1,$2,0,0,0);}
	| ' ' decv					{$$ = astCreate(AST_DECV_B,0,$2,0,0,0);}
	|						{$$ = astCreate(AST_EMPTY,0,0,0,0,0);}
	;

typevar: KW_CHAR					{$$ = astCreate(AST_KW_CHAR,0,0,0,0,0);}
	| KW_INT					{$$ = astCreate(AST_KW_INT,0,0,0,0,0);}
	| KW_FLOAT					{$$ = astCreate(AST_KW_FLOAT,0,0,0,0,0);}
	;

literal: LIT_INTEGER					{$$ = astCreate(AST_SYMBOL_LIT,$1,0,0,0,0);}
	| LIT_CHAR					{$$ = astCreate(AST_SYMBOL_LIT,$1,0,0,0,0);}
	| LIT_REAL					{$$ = astCreate(AST_SYMBOL_LIT,$1,0,0,0,0);}
	;

paramlist: typevar TK_IDENTIFIER rest			{$$ = astCreate(AST_PARAMLIST_A,$2,$1,$3,0,0);}
	| literal rest					{$$ = astCreate(AST_PARAMLIST_B,0,$1,$2,0,0);}
	| TK_IDENTIFIER rest				{$$ = astCreate(AST_PARAMLIST_C,$1,$2,0,0,0);}
	|						{$$ = astCreate(AST_EMPTY,0,0,0,0,0);}
	;

rest: ',' typevar TK_IDENTIFIER rest			{$$ = astCreate(AST_PARAM_A,$3,$2,$4,0,0);}
	| ',' literal rest				{$$ = astCreate(AST_PARAM_B,0,$2,$3,0,0);}
	| ',' TK_IDENTIFIER rest			{$$ = astCreate(AST_PARAM_C,$2,$3,0,0,0);}
	|						{$$ = astCreate(AST_EMPTY,0,0,0,0,0);}
	;


cmd: attribution				{$$ = astCreate(AST_CMD,0,$1,0,0,0);}
	| flux_control				{$$ = astCreate(AST_CMD,0,$1,0,0,0);}
	| inout					{$$ = astCreate(AST_CMD,0,$1,0,0,0);}
	| body					{$$ = astCreate(AST_CMD,0,$1,0,0,0);}
	|					{$$ = astCreate(AST_EMPTY,0,0,0,0,0);}
	;

body: '{' lcmd '}'				{$$ = astCreate(AST_BODY,0,$2,0,0,0);}
	;

lcmd: cmd ';' lcmd				{$$ = astCreate(AST_LISTCMD_A,0,$1,$3,0,0);}
	| dec lcmd				{$$ = astCreate(AST_LISTCMD_B,0,$1,$2,0,0);}
	| cmd					{$$ = astCreate(AST_LISTCMD_C,0,$1,0,0,0);}
	;

attribution: TK_IDENTIFIER '=' exp				{$$ = astCreate(AST_ATTRIB_A,$1,$3,0,0,0);}
	| TK_IDENTIFIER '[' exp ']' '=' exp			{$$ = astCreate(AST_ATTRIB_B,$1,$3,$6,0,0);}
	;

flux_control: KW_IF '(' exp ')' KW_THEN cmd					{$$ = astCreate(AST_IF,0,$3,$6,0,0);}
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd				{$$ = astCreate(AST_IFELSE,0,$3,$6,$8,0);}
	| KW_WHILE '(' exp ')' cmd						{$$ = astCreate(AST_WHILE,0,$3,$5,0,0);}
	| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp')' cmd			{$$ = astCreate(AST_FOR,$3,$5,$7,$9,0);}
	;

inout: KW_PRINT print_elem			{$$ = astCreate(AST_INOUT,0,$2,0,0,0);}
	| KW_READ TK_IDENTIFIER			{$$ = astCreate(AST_READ,$2,0,0,0,0);}
	| KW_RETURN exp				{$$ = astCreate(AST_RETURN,0,$2,0,0,0);}
	;

print_elem: LIT_STRING					{$$ = astCreate(AST_PRINT_A,$1,0,0,0,0);}
	| LIT_STRING print_elem				{$$ = astCreate(AST_PRINT_B,$1,$2,0,0,0);}
	| LIT_STRING ' ' print_elem			{$$ = astCreate(AST_PRINT_C,$1,$3,0,0,0);}
	| exp						{$$ = astCreate(AST_PRINT_D,0,$1,0,0,0);}
	| exp print_elem				{$$ = astCreate(AST_PRINT_E,0,$1,$2,0,0);}
	| exp ' ' print_elem				{$$ = astCreate(AST_PRINT_F,0,$1,$3,0,0);}
	;

exp: TK_IDENTIFIER					{$$ = astCreate(AST_SYMBOL_A,$1,0,0,0,0);} //erros estao no exp
	| TK_IDENTIFIER '[' exp ']'			{$$ = astCreate(AST_SYMBOL_B,$1,$3,0,0,0);}
	| '#'TK_IDENTIFIER				{$$ = astCreate(AST_SYMBOL_C,$2,0,0,0,0);}
	| '&'TK_IDENTIFIER				{$$ = astCreate(AST_SYMBOL_D,$2,0,0,0,0);}
	| LIT_INTEGER 					{$$ = astCreate(AST_SYMBOL_LIT,$1,0,0,0,0);}
	| LIT_CHAR					{$$ = astCreate(AST_SYMBOL_LIT,$1,0,0,0,0);}
	| exp OPERATOR_PLUS exp				{$$ = astCreate(AST_OP_PLUS,0,$1,$3,0,0);}
	| exp OPERATOR_MINUS exp			{$$ = astCreate(AST_OP_MINUS,0,$1,$3,0,0);}
	| exp OPERATOR_MULT exp				{$$ = astCreate(AST_OP_MULT,0,$1,$3,0,0);}
	| exp OPERATOR_DIV exp				{$$ = astCreate(AST_OP_DIV,0,$1,$3,0,0);}
	| exp OPERATOR_L exp				{$$ = astCreate(AST_OP_L,0,$1,$3,0,0);}
	| exp OPERATOR_G exp				{$$ = astCreate(AST_OP_G,0,$1,$3,0,0);}
	| OPERATOR_NEG exp				{$$ = astCreate(AST_OP_NEG,0,$2,0,0,0);}
	| '(' exp ')'					{$$ = astCreate(AST_EXP,0,$2,0,0,0);}
	| exp OPERATOR_LE exp				{$$ = astCreate(AST_OP_LE,0,$1,$3,0,0);}
	| exp OPERATOR_GE exp				{$$ = astCreate(AST_OP_GE,0,$1,$3,0,0);}
	| exp OPERATOR_EQ exp				{$$ = astCreate(AST_OP_EQ,0,$1,$3,0,0);}
	| exp OPERATOR_NE exp				{$$ = astCreate(AST_OP_NE,0,$1,$3,0,0);}
	| exp OPERATOR_AND exp				{$$ = astCreate(AST_OP_AND,0,$1,$3,0,0);}
	| exp OPERATOR_OR exp				{$$ = astCreate(AST_OP_OR,0,$1,$3,0,0);}
	| TK_IDENTIFIER '(' paramlist ')'		{$$ = astCreate(AST_FUNCCALL,$1,$3,0,0,0);}
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
