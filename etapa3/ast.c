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

	switch(node->type){
	
		case AST_DECLIST: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_DEC: astPrint(node->son[0],level);
			break;		
		case AST_OP_PLUS: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "+", node->son[1]->symbol->text);
			break;
		case AST_OP_MINUS: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "-", node->son[1]->symbol->text);
			break;
		case AST_OP_MULT: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "*", node->son[1]->symbol->text);
			break;
		case AST_OP_DIV: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "/", node->son[1]->symbol->text);
			break;
		case AST_OP_LE: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "<=", node->son[1]->symbol->text);
			break;
		case AST_OP_GE: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, ">=", node->son[1]->symbol->text);
			break;
		case AST_OP_EQ: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "=", node->son[1]->symbol->text);
			break;
		case AST_OP_NE: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "!=", node->son[1]->symbol->text);
			break;
		case AST_OP_NEG: fprintf(stderr, "%s%s", "!", node->son[0]->symbol->text);
			break;
		case AST_OP_AND: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "AND", node->son[1]->symbol->text);
			break;
		case AST_OP_OR: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "OR", node->son[1]->symbol->text);
			break;
		case AST_OP_L: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, "<", node->son[1]->symbol->text);
			break;
		case AST_OP_G: fprintf(stderr, "%s %s %s", node->son[0]->symbol->text, ">", node->son[1]->symbol->text);
			break;
		case AST_DECVAR: astPrint(node->son[0],level); fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr,"= "); astPrint(node->son[1],level); fprintf(stderr,";\n");
			break;
		case AST_DECVEC_A: astPrint(node->son[0],level); fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr,"[ "); astPrint(node->son[1],level); fprintf(stderr,"] "); fprintf(stderr,": ");astPrint(node->son[2],level);fprintf(stderr,";\n");
			break;
		case AST_DECVEC_B: astPrint(node->son[0],level); fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr,"[ "); astPrint(node->son[1],level); fprintf(stderr,"] ");fprintf(stderr,";\n");
			break;
		case AST_DECPOINT: astPrint(node->son[0],level); fprintf(stderr,"#"); fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr,"= "); astPrint(node->son[1],level); fprintf(stderr,";\n");
			break;
		case AST_DECFUNC: astPrint(node->son[0],level); fprintf(stderr,"%s ", node->symbol->text); fprintf(stderr,"( "); astPrint(node->son[1],level); fprintf(stderr,") "); astPrint(node->son[2],level);
			break;
		case AST_DECV_A: fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[0],level); 
		case AST_DECV_B: fprintf(stderr,"' ' "); astPrint(node->son[0],level); 
			break;
		case AST_KW_INT: fprintf(stderr, "int ");
			break;
		case AST_KW_FLOAT: fprintf(stderr, "float ");
			break;
		case AST_KW_CHAR: fprintf(stderr, "char ");
			break;
		case AST_EMPTY: fprintf(stderr, " ");
			break;
		case AST_SYMBOL_A: fprintf(stderr,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_B: fprintf(stderr,"%s ", node->symbol->text); fprintf(stderr,"[ "); astPrint(node->son[0],level);fprintf(stderr,"] ");
			break;
		case AST_SYMBOL_C: fprintf(stderr,"#");fprintf(stderr,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_D: fprintf(stderr,"&");fprintf(stderr,"%s ", node->symbol->text);
 fprintf(stderr,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_LIT: fprintf(stderr,"%s ", node->symbol->text);
			break;
		case AST_BODY: fprintf(stderr, "{\n"); astPrint(node->son[0],level); fprintf(stderr, "}\n");
			break;
		case AST_PARAMLIST_A: astPrint(node->son[0],level); fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[1],level);
			break;
		case AST_PARAMLIST_B: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_PARAMLIST_C: fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_PARAM_A: fprintf(stderr, ", "); astPrint(node->son[0],level); fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[1],level);
			break;
		case AST_PARAM_B: fprintf(stderr, ", "); astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_PARAM_C: fprintf(stderr, ", "); fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_CMD: astPrint(node->son[0],level);
			break;
		case AST_LISTCMD_A: astPrint(node->son[0],level); fprintf(stderr, ";\n");astPrint(node->son[1],level);
			break;
		case AST_LISTCMD_B: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_LISTCMD_C: astPrint(node->son[0],level);
			break;
		case AST_ATTRIB_A: fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr, "= "); astPrint(node->son[0],level);
			break;
		case AST_ATTRIB_B: fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr, "[ ");fprintf(stderr, "] ");astPrint(node->son[0],level);fprintf(stderr, "= "); astPrint(node->son[1],level);
			break;
		case AST_IF: fprintf(stderr, "IF ("); astPrint(node->son[0],level); fprintf(stderr, ") "); fprintf(stderr, "THEN "); astPrint(node->son[1],level);
			break;
		case AST_IFELSE: fprintf(stderr, "IF ("); astPrint(node->son[0],level); fprintf(stderr, ") "); fprintf(stderr, "THEN "); astPrint(node->son[1],level); fprintf(stderr, "ELSE "); astPrint(node->son[2],level);
			break;
		case AST_WHILE: fprintf(stderr, "WHILE ("); astPrint(node->son[0],level); fprintf(stderr, ") "); astPrint(node->son[1],level);
			break;
		case AST_FOR: fprintf(stderr, "FOR ("); fprintf(stderr,"%s ",node->symbol->text); fprintf(stderr, "= ");astPrint(node->son[0],level); fprintf(stderr, "TO ");astPrint(node->son[1],level);fprintf(stderr, ") "); astPrint(node->son[2],level);
			break;
		case AST_INOUT: fprintf(stderr, "PRINT "); astPrint(node->son[0],level);
			break;
		case AST_READ: fprintf(stderr, "READ "); fprintf(stderr,"%s ",node->symbol->text);
			break;
		case AST_RETURN: fprintf(stderr, "RETURN "); astPrint(node->son[0],level);
			break;
		case AST_PRINT_A: fprintf(stderr,"%s ",node->symbol->text);
			break;
		case AST_PRINT_B: fprintf(stderr,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_PRINT_C: fprintf(stderr,"%s ",node->symbol->text);fprintf(stderr, "' ' ");astPrint(node->son[0],level);
			break;
		case AST_PRINT_D: astPrint(node->son[0],level);
			break;
		case AST_PRINT_E: astPrint(node->son[0],level);astPrint(node->son[1],level);
			break;
		case AST_PRINT_F: astPrint(node->son[0],level); fprintf(stderr, "' ' "); astPrint(node->son[0],level);
			break;
		case AST_VEC_SIZE: fprintf(stderr, "%s ",node->symbol->text);
			break;

		case AST_FUNCCALL: fprintf(stderr, "%s ",node->symbol->text); fprintf(stderr, "( "); astPrint(node->son[0],level);fprintf(stderr," )");
			break;
		case AST_EXP: fprintf(stderr, "AST_EXP,\n");
			break;


		default: fprintf(stderr, "UNKNOWN,\n");

	}

	//for(int i = 0; i < MAX_SONS; i++)
	//	astPrint(node->son[i], level+1);


}
