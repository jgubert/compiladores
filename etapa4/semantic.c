#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"

void set_declarations(AST *node)
{ 
	if(!node) return;

	if(node->type == AST_DECVAR)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Symbol %s already declared.\n",node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_OK;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_FLOAT;	
		}
	}
	if (node->type == AST_DECFUNC)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_OK;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_FLOAT;	
		}
	}
		if (node->type == AST_DECVEC_A || node->type == AST_DECVEC_B)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_OK;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_FLOAT;	
		}
	}
		if (node->type == AST_DECPOINT)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Symbol %salready declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_OK;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_FLOAT;	
		}
	}
	for (int i=0;i<MAX_SONS; ++i)
		set_declarations(node->son[i]);
}
