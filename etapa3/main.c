//João Pedro Gubert de Souza
//Samuel Rudnicki

#include <stdio.h>
#include <stdlib.h>

extern int getLineNumber();
extern int isRunning();
extern FILE * yyin;
extern int yylex();
int yyparse (void);
extern void hashPrint(void);


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

	initMe();

	yyparse();

	hashPrint();

	printf("Compilação Concluida!\n");

	exit(0);
}
