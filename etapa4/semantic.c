#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"

int set_declarations(AST *node)
{ 
	int error=0;
	if(!node) return 0;

	if(node->type == AST_DECVAR)
	{
		if(node->symbol->type != SYMBOL_IDENTIFIER)
		{
			fprintf(stderr,"Line: %d - Semantic error: Variable %s already declared.\n",node->lineNumber, node->symbol->text);
			error=1;
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
			fprintf(stderr,"Line: %d - Semantic error: Variable %s already declared.\n",node->lineNumber, node->symbol->text);
			error=1;
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
			fprintf(stderr,"Line: %d - Semantic error: Function %s already declared.\n",node->lineNumber, node->symbol->text);
			error=1;
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
			fprintf(stderr,"Line: %d - Semantic error: Vector %s already declared.\n",node->lineNumber, node->symbol->text);
			error=1;
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
			fprintf(stderr,"Line: %d - Semantic error: Pointer %salready declared.\n",node->lineNumber, node->symbol->text);
			error=1;
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
	return error;
}


int check_use(AST *node){
	int error=0;
	if(!node) return 0;
	
  //variaveis
	if(node->type == AST_SYMBOL_A || node->type == AST_ATTRIB_A){
		if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Line: %d - Vector %s being used as scalar type.\n", node->lineNumber, node->symbol->text);
						error=1;
		} else if(node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Line: %d - Function %s being used as scalar type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_PARAM && node->symbol->type != SYMBOL_POINT){
			fprintf(stderr,"Line: %d - Variable %s not declared.\n",node->lineNumber, node->symbol->text);
						error=1;
		}
	}

	// Verifica utilizacao vetores
	else if(node->type == AST_SYMBOL_B || node->type == AST_ATTRIB_B){
		if (node->symbol->type == SYMBOL_IDENTIFIER || node->symbol->type == SYMBOL_PARAM || node->symbol->type == SYMBOL_VAR) {
			fprintf(stderr,"Line %d - Scalar %s being used as vector type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Line %d - Function %s being used as vector type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type == SYMBOL_POINT) {
			fprintf(stderr,"Line %d - Pointer %s being used as vector type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type != SYMBOL_VECTOR){
			fprintf(stderr,"Line %d - Vector %s not declared.\n",node->lineNumber, node->symbol->text);
						error=1;
		}
	}

	// funcoes
	else if(node->type == AST_FUNCCALL){
		if (node->symbol->type == SYMBOL_IDENTIFIER || node->symbol->type == SYMBOL_PARAM) {
			fprintf(stderr,"Line %d - Scalar %s being used as function type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type == SYMBOL_VAR) {
			fprintf(stderr,"Line %d - Scalar %s being used as function type.\n",node->lineNumber, node->symbol->text);
						error=1;					
		} else if (node->symbol->type == SYMBOL_POINT) {
			fprintf(stderr,"Line %d - Pointer %s being used as function type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Line %d - Vector %s being used as function type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type != SYMBOL_FUNC){
			fprintf(stderr,"Line %d - Function %s not declared.\n",node->lineNumber, node->symbol->text);
						error=1;
		}
	}//ponteiros
		else if(node->type == AST_SYMBOL_C){
		  if (node->symbol->type == SYMBOL_FUNC) {
			fprintf(stderr,"Line: %d - Function %s being used as pointer type.\n",node->lineNumber, node->symbol->text);
						error=1;					
		} else if (node->symbol->type == SYMBOL_VECTOR) {
			fprintf(stderr,"Line: %d - Vector %s being used as pointer type.\n",node->lineNumber, node->symbol->text);
						error=1;
		} else if (node->symbol->type != SYMBOL_POINT){
			fprintf(stderr,"Line: %d - Pointer %s not declared.\n",node->lineNumber, node->symbol->text);
						error=1;
		}
	}

	for (int i = 0; i < MAX_SONS; ++i) {
		check_use(node->son[i]);
	}
	return error;
}
int check_op(AST *node) {
	int error =0;
	if(node == 0) return 0;
	
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
					fprintf(stderr,"Line: %d - Operator %s is of an invalid type for arithmetic expression.\n",node->lineNumber, node->son[0]->symbol->text);
					error=1;
				}
			}
			else {fprintf(stderr,"Line %d - Arithmetic expression contains an invalid operator type.\n",node->lineNumber);
			error=1;}
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
					fprintf(stderr,"Line %d - Operator %s is of an invalid type for arithmetic expression.\n",node->lineNumber, node->son[1]->symbol->text);
					error=1;
				}
			}
			else{ fprintf(stderr,"Arithmetic expression contains an invalid operator type.\n");
			error=1;}
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
					fprintf(stderr,"Line %d - Operator %s is of an invalid type for relational expression.\n",node->lineNumber,node->son[0]->symbol->text);
					error=1;;
				}
			}
			else {fprintf(stderr,"Line %d - Relational expression contains an invalid operator type.\n",node->lineNumber);
			error=1;}
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
					fprintf(stderr,"Line %d - Operator %s is of an invalid type for relational expression.\n",node->lineNumber, node->son[1]->symbol->text);
					error=1;;
				}
			}
			else {fprintf(stderr,"Line %d - Relational expression contains an invalid operator type.\n",node->lineNumber);
			error=1;;}
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
					fprintf(stderr,"Line %d - Operator %s is of an invalid type for logical expression.\n",node->lineNumber, node->son[0]->symbol->text);
					error=1;
				}
			}
			else{ fprintf(stderr,"Line %d - Logical expression contains an invalid operator type.\n",node->lineNumber);
			error=1;
			}
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
					fprintf(stderr,"Line %d - Operator %s is of an invalid type for logical expression.\n",node->lineNumber, node->son[1]->symbol->text);
					error=1;
				}
			}
			else{ fprintf(stderr,"Line %d - Logical expression contains an invalid operator type.\n",node->lineNumber);
		error=1;}
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
					fprintf(stderr,"Line %d - Vector index %s is of an invalid type.\n",node->lineNumber, node->son[0]->symbol->text);
					error=1;
				}
			}
			else{
			error=1; fprintf(stderr,"Line %d - Vector index is of an invalid type.\n",node->lineNumber);}
		}
	}

	for (i = 0; i < MAX_SONS; ++i) {
		check_use(node->son[i]);
	}
	return error;
}



