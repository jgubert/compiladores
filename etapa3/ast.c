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
		
		case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL,\n");
		default: fprintf(stderr, "UNKNOWN,\n");


	}
	
	for(int i = 0; i < MAX_SONS; i++)
		astPrint(node->son[i], level+1);


}

