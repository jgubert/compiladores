#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST* astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3){

	AST *newnode;
	newnode = (AST*) calloc(1, sizeof(AST));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;

	return newnode;

}

void astPrint(AST *node, int level){

	if(!node) return;
	for(int i = 0; i < level; i++)
		fprintf(stderr, "  ");

	fprintf(stderr,"AST(");
	switch(node->type){

		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL: %s,\n", node->symbol->text);
			break;
		case AST_SYMBOL_LIT: fprintf(stderr, "AST_SYMBOL_LIT: %s,\n", node->symbol->text);
			break;
		case AST_OP_PLUS: fprintf(stderr, "AST_OP_PLUS,\n");
			break;
		case AST_OP_MINUS: fprintf(stderr, "AST_OP_MINUS,\n");
			break;
		case AST_OP_MULT: fprintf(stderr, "AST_OP_MULT,\n");
			break;
		case AST_OP_DIV: fprintf(stderr, "AST_OP_DIV,\n");
			break;
		case AST_OP_LE: fprintf(stderr, "AST_OP_LE,\n");
			break;
		case AST_OP_GE: fprintf(stderr, "AST_OP_GE,\n");
			break;
		case AST_OP_EQ: fprintf(stderr, "AST_OP_EQ,\n");
			break;
		case AST_OP_NE: fprintf(stderr, "AST_OP_NE,\n");
			break;
		case AST_OP_NEG: fprintf(stderr, "AST_OP_NEG,\n");
			break;
		case AST_OP_AND: fprintf(stderr, "AST_OP_AND,\n");
			break;
		case AST_OP_OR: fprintf(stderr, "AST_OP_OR,\n");
			break;
		case AST_OP_L: fprintf(stderr, "AST_OP_L,\n");
			break;
		case AST_OP_G: fprintf(stderr, "AST_OP_G,\n");
			break;
		case AST_PROGRAM: fprintf(stderr, "AST_PROGRAM,\n");
			break;
		case AST_DECLIST: fprintf(stderr, "AST_DECLIST,\n");
			break;
		case AST_DECVAR: fprintf(stderr, "AST_DECVAR:%s,\n", node->symbol->text);
			break;
		case AST_DECVEC: fprintf(stderr, "AST_DECVEC:%s,\n", node->symbol->text);
			break;
		case AST_DECPOINT: fprintf(stderr, "AST_DECPOINT:%s,\n", node->symbol->text);
			break;
		case AST_DECFUNC: fprintf(stderr, "AST_DECFUNC:%s,\n", node->symbol->text);
			break;
		case AST_PARAMLIST: fprintf(stderr, "AST_PARAMLIST,\n");
			break;
		case AST_BODY: fprintf(stderr, "BODY,\n");
			break;
		case AST_KW_INT: fprintf(stderr, "int\n");
			break;
		case AST_KW_FLOAT: fprintf(stderr, "float\n");
			break;
		case AST_KW_CHAR: fprintf(stderr, "char\n");
			break;
		case AST_PARAM: fprintf(stderr, "AST_PARAM,\n");
			break;
		case AST_CMD: fprintf(stderr, "AST_CMD,\n");
			break;
		case AST_LISTCMD: fprintf(stderr, "AST_LISTCMD,\n");
			break;
		case AST_ATTRIB: fprintf(stderr, "AST_ATTRIB: %s\n", node->symbol->text);
			break;
		case AST_IF: fprintf(stderr, "AST_IF,\n");
			break;
		case AST_IFELSE: fprintf(stderr, "AST_IFELSE,\n");
			break;
		case AST_WHILE: fprintf(stderr, "AST_WHILE,\n");
			break;
		case AST_FOR: fprintf(stderr, "AST_FOR: %s\n", node->symbol->text);
			break;
		case AST_PRINT: fprintf(stderr, "AST_PRINT,\n");
			break;
		case AST_READ: fprintf(stderr, "AST_READ,\n");
			break;
		case AST_RETURN: fprintf(stderr, "AST_RETURN,\n");
			break;
		case AST_DEC: fprintf(stderr, "AST_DEC,\n");
			break;
		case AST_VEC_SIZE: fprintf(stderr, "AST_VEC_SIZE: %s,\n",node->symbol->text);
			break;
		case AST_INOUT: fprintf(stderr, "AST_INOUT,\n");
			break;
		case AST_FUNCCALL: fprintf(stderr, "AST_FUNCCALL,\n");
			break;
		case AST_DECV: fprintf(stderr, "AST_DECV\n");
			break;
		case AST_EXP: fprintf(stderr, "AST_EXP,\n");
			break;
		case AST_EMPTY: fprintf(stderr, "AST_EMPTY,\n");
			break;





		default: fprintf(stderr, "UNKNOWN,\n");


	}

	for(int i = 0; i < MAX_SONS; i++)
		astPrint(node->son[i], level+1);


}
