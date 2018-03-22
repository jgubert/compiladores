
%{
	//João Pedro Gubert de Souza
	//Samuel Rudnicki

	#include "y.tab.h"
	#include "hash.c"

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
int					{printf("KW INTEIRO\n");return KW_INT;}
float					{return KW_FLOAT;}
if      				{return KW_IF;}
then					{return KW_THEN;}
else					{return KW_ELSE;}
while					{return KW_WHILE;}
for					{return KW_FOR;}
read					{return KW_READ;}
return					{return KW_RETURN;}
print					{return KW_PRINT;}

"<="					{return OPERATOR_LE;}
">="					{return OPERATOR_GE;}
"=="					{return OPERATOR_EQ;}
"!="					{return OPERATOR_NE;}
"&&"					{return OPERATOR_AND;}
"||"					{return OPERATOR_OR;}

[0-9]+					{hashInsert(SYMBOL_LIT_INTEGER,yytext); return LIT_INTEGER;}
[a-zA-Z_][a-zA-Z_0-9]*			{printf("IDENTIFICADOR\n"); hashInsert(SYMBOL_IDENTIFIER,yytext); return TK_IDENTIFIER;}
[0-9]+"."[0-9]+				{hashInsert(SYMBOL_LIT_REAL,yytext); return LIT_REAL;}
'.'					{hashInsert(SYMBOL_LIT_CHAR,yytext); return LIT_CHAR;}
["]([^"]|\\.)*["]			{hashInsert(SYMBOL_LIT_STRING,yytext); return LIT_STRING;}
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

void initMe(void){
	hashInit();
}


int isRunning(void){
	return running;
}

int getLineNumber(void){
	return lineNumber;
}

int yywrap(void){
	running = 0;
	return 1;
}
