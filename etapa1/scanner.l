
%{
	//João Pedro Gubert de Souza
	//Samuel Rudnicki

	#include "tokens.h"
	#include "hash.c"

	int lineNumber = 1;
	int running = 1;

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
read					{return KW_READ;}
return					{return KW_RETURN;}
print					{return KW_PRINT;}

"<="					{return OPERATOR_LE;}
">="					{return OPERATOR_GE;}
"=="					{return OPERATOR_EQ;}
"!="					{return OPERATOR_NE;}
"&&"					{return OPERATOR_AND;}
"||"					{return OPERATOR_OR;}

[0-9]+					{hashInsert(1,yytext); return LIT_INTEGER;}
[a-zA-Z_][a-zA-Z_0-9]*			{hashInsert(1,yytext); return TK_IDENTIFIER;}
[0-9]+"."[0-9]+				{hashInsert(1,yytext); return LIT_REAL;}
'.'					{hashInsert(1,yytext); return LIT_CHAR;}
["]([^"]|\\.)*["]			{hashInsert(1,yytext); return LIT_STRING;}
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

void initMe(){
hashInit();
}

#include "main.c"


int isRunning(){
return running;
}

int getLineNumber(){
return lineNumber;
}

int yywrap(){
	running = 0;
	return 1;
}
