%{
	//João Pedro Gubert de Souza
	//Samuel Rudnicki

#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "y.tab.h"

int getLineNumber(void);
void initMe(void);
int isRunning(void);

int lineNumber = 1;
int running = 1;

#define SYMBOL_UNDEFINED 0
#define SYMBOL_IDENTIFIER 1
#define SYMBOL_LIT_INTEGER 2
#define SYMBOL_LIT_REAL 3
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5


%}

%x COMMENT

%%

char					{return KW_CHAR;}
int					{return KW_INT;}
float					{return KW_FLOAT;}
if      				{return KW_IF;}
then					{return KW_THEN;}
else					{return KW_ELSE;}
while					{return KW_WHILE;}
for					{return KW_FOR;}
to					{return KW_TO;}
read					{return KW_READ;}
return					{return KW_RETURN;}
print					{return KW_PRINT;}

"+"					{return OPERATOR_PLUS;}//adicao dos operadores +-*/!><
"-"					{return OPERATOR_MINUS;}
"*"					{return OPERATOR_MULT;}
"/"					{return OPERATOR_DIV;}
"<="					{return OPERATOR_LE;}
">="					{return OPERATOR_GE;}
"=="					{return OPERATOR_EQ;}
"!="					{return OPERATOR_NE;}
"&&"					{return OPERATOR_AND;}
"||"					{return OPERATOR_OR;}
"<"					{return OPERATOR_L;}
">"					{return OPERATOR_G;}
"!"					{return OPERATOR_NEG;}


[0-9]+					{yylval.symbol = hashInsert(SYMBOL_LIT_INTEGER,strdup(yytext)); return LIT_INTEGER;}
'.'					{yylval.symbol = hashInsert(SYMBOL_LIT_CHAR,strdup(yytext)); return LIT_CHAR;}
[a-zA-Z_][a-zA-Z_0-9]*			{yylval.symbol = hashInsert(SYMBOL_IDENTIFIER,strdup(yytext)); return TK_IDENTIFIER;}
[0-9]+"."[0-9]+				{yylval.symbol = hashInsert(SYMBOL_LIT_REAL,strdup(yytext)); return LIT_REAL;}

["]([^"]|\\.)*["]			{yylval.symbol = hashInsert(SYMBOL_LIT_STRING,strdup(yytext)); return LIT_STRING;}
[,;:(){}+-]				{return yytext[0];}
[*/<>=!&$#]				{return yytext[0];}
[\[\]]					{return yytext[0];}
\n					{lineNumber++;}
[ \t]
"//".*
.					{return TOKEN_ERROR;}
"/*"					{BEGIN(COMMENT);}

<COMMENT>\n				{lineNumber++;}
<COMMENT>"*/"				{BEGIN(INITIAL);}
<COMMENT>.

%%

int getLineNumber(void){
	return lineNumber;
}

void initMe(void){
	hashInit();
}

int isRunning(void){
	return running;
}



void stringError(void){
	printf("Erro: %s \n", yytext);
}

int yywrap(void){
	running = 0;
	return 1;
}
