//João Pedro Gubert de Souza
//Samuel Rudnicki

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int getLineNumber();
extern int isRunning();
extern FILE * yyin;
extern int yylex();
//extern int initMe();


int main(int argc, char ** argv){

  int tok;

  if(argc < 2){
    fprintf(stderr, "Please, call: etapa1 file_name.\n");
    exit(1);
  }

  if((yyin = fopen(argv[1],"r")) == 0){
    fprintf(stderr, "Cannot open file %s.\n", argv[1]);
    exit(2);
  }

  //hashInit();
  initMe();

  while(isRunning()){
    tok = yylex();

    if(!isRunning())
      break;

    switch(tok){
      case KW_CHAR: printf("line %d: Achei um CHAR!\n", getLineNumber());
        break;
      case KW_INT: printf("line %d: Achei um INTEIRO!\n", getLineNumber());
        break;
      case KW_FLOAT: printf("line %d: Achei um FLOAT!\n", getLineNumber());
        break;
      case KW_IF: printf("line %d: Achei um IF!\n", getLineNumber());
        break;
      case KW_THEN: printf("line %d: Achei um THEN!\n", getLineNumber());
        break;
      case KW_ELSE: printf("line %d: Achei um ELSE!\n", getLineNumber());
        break;
      case KW_WHILE: printf("line %d: Achei um WHILE!\n", getLineNumber());
        break;
      case KW_FOR: printf("line %d: Achei um FOR!\n", getLineNumber());
        break;
      case KW_READ: printf("line %d: Achei um SCANF!\n", getLineNumber());
        break;
      case KW_RETURN: printf("line %d: Achei um RETURN!\n", getLineNumber());
        break;
      case KW_PRINT: printf("line %d: Achei um PRINTF!\n", getLineNumber());
        break;

      case OPERATOR_LE: printf("line %d: Achei um Operador <= !\n", getLineNumber());
        break;
      case OPERATOR_GE: printf("line %d: Achei um Operador >= !\n", getLineNumber());
        break;
      case OPERATOR_EQ: printf("line %d: Achei um Operador == !\n", getLineNumber());
        break;
      case OPERATOR_NE: printf("line %d: Achei um Operador != !\n", getLineNumber());
        break;
      case OPERATOR_AND: printf("line %d: Achei um Operador && !\n", getLineNumber());
        break;
      case OPERATOR_OR: printf("line %d: Achei um Operador || !\n", getLineNumber());
        break;

      case TK_IDENTIFIER: printf("line %d: Achei um IDENTIFICADOR!\n", getLineNumber());
        break;
      case LIT_INTEGER: printf("line %d: Achei um LITERAL INT!\n", getLineNumber());
        break;
      case LIT_REAL: printf("line %d: Achei um LITERAL REAL!\n", getLineNumber());
        break;
      case LIT_CHAR: printf("line %d: Achei um LITERAL CHAR!\n", getLineNumber());
        break;
      case LIT_STRING: printf("line %d: Achei um LITERAL STRING!\n", getLineNumber());
        break;

      case TOKEN_ERROR: printf("line %d: TOKEN ERROR!\n", getLineNumber());

      default: printf("line %d: symbol: %c\n", getLineNumber(), tok);
    }
  }

  hashPrint();

  exit(0);
}
