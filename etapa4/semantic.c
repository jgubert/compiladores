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
			fprintf(stderr,"Semantic error: Variable %s already declared.\n",node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_VAR;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_CHAR;

		}
	}
	if(node->type == AST_PARAMLIST_A || node->type == AST_PARAM_A)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Variable %s already declared.\n",node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_PARAM;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_CHAR;

		}
	}
	if (node->type == AST_DECFUNC)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Function %s already declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_FUNC;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_CHAR;
		}
	}
		if (node->type == AST_DECVEC_A || node->type == AST_DECVEC_B)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Vector %s already declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_VECTOR;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_CHAR;
		}
	}
		if (node->type == AST_DECPOINT)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Semantic error: Pointer %salready declared.\n", node->symbol->text);
			exit(4);
		}
		else
		{
			node->symbol->type = SYMBOL_POINT;
			if(node->son[0]->type == AST_KW_INT)
				node->symbol->datatype = DATATYPE_INT;
			if(node->son[0]->type == AST_KW_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KW_CHAR)
				node->symbol->datatype = DATATYPE_CHAR;
		}
	}
	for (int i=0;i<MAX_SONS; ++i)
		set_declarations(node->son[i]);
}


void check_use(AST *node){
	if(!node) return;
	
  //variaveis
	if(node->type == AST_SYMBOL_A || node->type == AST_ATTRIB_A){
		if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Vector %s being used as scalar type.\n", node->symbol->text);
						exit(4);
		} else if(node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Function %s being used as scalar type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_PARAM && node->symbol->type != SYMBOL_POINT){
			fprintf(stderr,"Variable %s not declared.%d\n", node->symbol->text,node->symbol->type);
						exit(4);
		}
	}

	// Verifica utilizacao vetores
	else if(node->type == AST_SYMBOL_B || node->type == AST_ATTRIB_B){
		if (node->symbol->type == SYMBOL_IDENTIFIER || node->symbol->type == SYMBOL_PARAM || node->symbol->type == SYMBOL_VAR) {
			fprintf(stderr,"Scalar %s being used as vector type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Function %s being used as vector type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type == SYMBOL_POINT) {
			fprintf(stderr,"Pointer %s being used as vector type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type != SYMBOL_VECTOR){
			fprintf(stderr,"Vector %s not declared.\n", node->symbol->text);
						exit(4);
		}
	}

	// funcoes
	else if(node->type == AST_FUNCCALL){
		if (node->symbol->type == SYMBOL_IDENTIFIER || node->symbol->type == SYMBOL_PARAM) {
			fprintf(stderr,"Scalar %s being used as function type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type == SYMBOL_VAR) {
			fprintf(stderr,"Scalar %s being used as function type.\n", node->symbol->text);
						exit(4);					
		} else if (node->symbol->type == SYMBOL_POINT) {
			fprintf(stderr,"Pointer %s being used as function type.\n", node->symbol->text);
						exit(4);	
		} else if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Vector %s being used as function type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type != SYMBOL_FUNC){
			fprintf(stderr,"Function %s not declared.\n", node->symbol->text);
						exit(4);
		}
	}//ponteiros
		else if(node->type == AST_SYMBOL_C){
		  if (node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Function %s being used as pointer type.\n", node->symbol->text);
						exit(4);					
		} else if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Vector %s being used as pointer type.\n", node->symbol->text);
						exit(4);
		} else if (node->symbol->type != SYMBOL_POINT){
			fprintf(stderr,"Pointer %s not declared.\n", node->symbol->text);
						exit(4);
		}
	}

	for (int i = 0; i < MAX_SONS; ++i) {
		check_use(node->son[i]);
	}
}
void check_op(AST *node) {
	if(node == 0) return;
	
	int i;


	// Verifica compatibilidade com operandos
	if(node->type == AST_OP_PLUS || node->type == AST_OP_MINUS || node->type == AST_OP_MULT || node->type == AST_OP_DIV) {
		if(node->son[0]->type != AST_OP_PLUS &&
			node->son[0]->type != AST_OP_MINUS &&
			node->son[0]->type != AST_OP_MULT &&
			node->son[0]->type != AST_OP_DIV) {
			if(node->son[0]->type == AST_SYMBOL_A ||
				node->son[0]->type == AST_SYMBOL_B ||
				node->son[0]->type == AST_SYMBOL_LIT) {
				if(node->son[0]->symbol->datatype != DATATYPE_INT &&
					node->son[0]->symbol->datatype != DATATYPE_FLOAT &&
					node->son[0]->symbol->datatype != DATATYPE_CHAR) {
					fprintf(stderr,"Operator %s is of an invalid type for arithmetic expression.\n", node->son[0]->symbol->text);
					exit(4);
				}
			}
			else {fprintf(stderr,"Arithmetic expression contains an invalid operator type.\n");
			exit(4);}
		}

		if(node->son[1]->type != AST_OP_PLUS &&
			node->son[1]->type != AST_OP_MINUS &&
			node->son[1]->type != AST_OP_MULT &&
			node->son[1]->type != AST_OP_DIV) {
			if(node->son[1]->type == AST_SYMBOL_A ||
				node->son[1]->type == AST_SYMBOL_B ||
				node->son[1]->type == AST_SYMBOL_LIT) {
				if(node->son[1]->symbol->datatype != DATATYPE_INT &&
					node->son[1]->symbol->datatype != DATATYPE_FLOAT &&
					node->son[1]->symbol->datatype != DATATYPE_CHAR) {
					fprintf(stderr,"Operator %s is of an invalid type for arithmetic expression.\n", node->son[1]->symbol->text);
					exit(4);
				}
			}
			else{ fprintf(stderr,"Arithmetic expression contains an invalid operator type.\n");
			exit(4);}
		}
	}

	// relacionais
	else if(node->type == AST_OP_L || node->type == AST_OP_G || node->type == AST_OP_LE || node->type == AST_OP_GE || node->type == AST_OP_EQ || node->type == AST_OP_NE || node->type == AST_OP_GE) {
		if(node->son[0]->type != AST_OP_PLUS &&
			node->son[0]->type != AST_OP_MINUS &&
			node->son[0]->type != AST_OP_MULT &&
			node->son[0]->type != AST_OP_DIV) {
			if(node->son[0]->type == AST_SYMBOL_A ||
				node->son[0]->type == AST_SYMBOL_B ||
				node->son[0]->type == AST_SYMBOL_LIT) {
				if(node->son[0]->symbol->datatype != DATATYPE_INT &&
					node->son[0]->symbol->datatype != DATATYPE_FLOAT &&
					node->son[0]->symbol->datatype != DATATYPE_CHAR) {
					fprintf(stderr,"Operator %s is of an invalid type for relational expression.\n",node->son[0]->symbol->text);
					exit(4);
				}
			}
			else {fprintf(stderr,"Relational expression contains an invalid operator type.\n");
			exit(4);}
		}

		if(node->son[1]->type != AST_OP_PLUS &&
			node->son[1]->type != AST_OP_MINUS &&
			node->son[1]->type != AST_OP_MULT &&
			node->son[1]->type != AST_OP_DIV) {
			if(node->son[1]->type == AST_SYMBOL_A ||
				node->son[1]->type == AST_SYMBOL_B ||
				node->son[1]->type == AST_SYMBOL_LIT) {
				if(node->son[1]->symbol->datatype != DATATYPE_INT &&
					node->son[1]->symbol->datatype != DATATYPE_FLOAT &&
					node->son[1]->symbol->datatype != DATATYPE_CHAR) {
					fprintf(stderr,"Operator %s is of an invalid type for relational expression.\n", node->son[1]->symbol->text);
					exit(4);
				}
			}
			else {fprintf(stderr,"Relational expression contains an invalid operator type.\n");
			exit(4);}
		}
	}


	// logicas
	else if(node->type == AST_OP_AND || node->type == AST_OP_OR) {
		if(node->son[0]->type != AST_OP_L &&
			node->son[0]->type != AST_OP_G &&
			node->son[0]->type != AST_OP_LE &&
			node->son[0]->type != AST_OP_GE &&
			node->son[0]->type != AST_OP_EQ &&
			node->son[0]->type != AST_OP_NE &&
			node->son[0]->type != AST_OP_AND &&
			node->son[0]->type != AST_OP_OR) {
			if(node->son[0]->type == AST_SYMBOL_A ||
				node->son[0]->type == AST_SYMBOL_B ||
				node->son[0]->type == AST_SYMBOL_LIT) {
				if(node->son[0]->symbol->datatype != DATATYPE_INT) {
					fprintf(stderr,"Operator %s is of an invalid type for logical expression.\n", node->son[0]->symbol->text);
				}
			}
			else fprintf(stderr,"Logical expression contains an invalid operator type.\n");
		}

		if(node->son[1]->type != AST_OP_L &&
			node->son[1]->type != AST_OP_G &&
			node->son[1]->type != AST_OP_LE &&
			node->son[1]->type != AST_OP_GE &&
			node->son[1]->type != AST_OP_EQ &&
			node->son[1]->type != AST_OP_NE &&
			node->son[1]->type != AST_OP_AND &&
			node->son[1]->type != AST_OP_OR) {
			if(node->son[1]->type == AST_SYMBOL_A ||
				node->son[1]->type == AST_SYMBOL_B ||
				node->son[1]->type == AST_SYMBOL_LIT) {
				if(node->son[1]->symbol->datatype != DATATYPE_INT) {
					fprintf(stderr,"Operator %s is of an invalid type for logical expression.\n", node->son[1]->symbol->text);
				}
			}
			else fprintf(stderr,"Logical expression contains an invalid operator type.\n");
		}
	}



	// vetor
	else if(node->type == AST_SYMBOL_B ||
		node->type == AST_ATTRIB_B) {
		if(node->son[0]->type != AST_OP_PLUS &&
			node->son[0]->type != AST_OP_MINUS &&
			node->son[0]->type != AST_OP_MULT &&
			node->son[0]->type != AST_OP_DIV) {
			if(node->son[0]->type == AST_SYMBOL_A ||
				node->son[0]->type == AST_SYMBOL_B ||
				node->son[0]->type == AST_SYMBOL_LIT) {
				if(node->son[0]->symbol->datatype != DATATYPE_INT &&
					node->son[0]->symbol->datatype != DATATYPE_CHAR) {
					fprintf(stderr,"Vector index %s is of an invalid type.\n", node->son[0]->symbol->text);
				}
			}
			else fprintf(stderr,"Vector index is of an invalid type.\n");
		}
	}

	for (i = 0; i < MAX_SONS; ++i) {
		check_use(node->son[i]);
	}
}



