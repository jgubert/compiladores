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

		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL, %s\n", node->symbol->text);
			break;
		case AST_SYMBOL_VEC: fprintf(stderr, "AST_SYMBOL_VEC: %s,\n", node->symbol->text);
			break;
		case AST_SYMBOL_LIT: fprintf(stderr, "AST_SYMBOL_LIT: %s,\n", node->symbol->text);
			break;
		case AST_OP_PLUS: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_OP_MINUS: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_OP_MULT: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_OP_DIV: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_OP_LE: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_OP_GE: fprintf(stderr, "%s", node->symbol->text);
			break;
		case AST_DECLIST: fprintf(stderr, "AST_DECLIST,\n");
			break;
		case AST_DEC: fprintf(stderr, "AST_DEC,\n");
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
		case AST_EMPTY: fprintf(stderr, "AST_EMPTY,\n");
			break;

		default: fprintf(stderr, "UNKNOWN,\n");


	}

	for(int i = 0; i < MAX_SONS; i++)
		astPrint(node->son[i], level+1);


}
