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
FILE *out;
void astPrint(AST *node, int level){

	if(!node) return;
	for (int i=0; i<level; i++)
		fprintf(stderr, "  ");
	
	switch(node->type){
	
		case AST_DECLIST: astPrint(node->son[0],level+1); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_DECLIST,\n");
			break;
		case AST_DEC: astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_DEC,\n");
			break;		
		case AST_OP_PLUS: astPrint(node->son[0],level+1);fprintf(out,"+ "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_PLUS,\n");
			break;
		case AST_OP_MINUS: astPrint(node->son[0],level+1);fprintf(out,"- "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_MINUS,\n");
			break;
		case AST_OP_MULT: astPrint(node->son[0],level+1);fprintf(out,"* "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_MULT,\n");
			break;
		case AST_OP_DIV: astPrint(node->son[0],level+1);fprintf(out,"/ "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_DIV,\n");
			break;
		case AST_OP_LE: astPrint(node->son[0],level+1);fprintf(out,"<= "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_LE,\n");
			break;
		case AST_OP_GE: astPrint(node->son[0],level+1);fprintf(out,">= "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_GE,\n");
			break;
		case AST_OP_EQ: astPrint(node->son[0],level+1);fprintf(out,"== "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_EQ,\n");
			break;
		case AST_OP_NE: astPrint(node->son[0],level+1);fprintf(out,"!= "); astPrint(node->son[1],level+1);
			break;
			fprintf(stderr,"AST_OP_NE,\n");
		case AST_OP_NEG: fprintf(out,"!"); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_OP_NEG,\n");
			break;
		case AST_OP_AND: astPrint(node->son[0],level+1);fprintf(out,"AND "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_AND,\n");
			break;
		case AST_OP_OR: astPrint(node->son[0],level+1);fprintf(out,"OR "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_OR,\n");
			break;
		case AST_OP_L: astPrint(node->son[0],level+1);fprintf(out,"< "); astPrint(node->son[1],level+1);
			break;
			fprintf(stderr,"AST_OP_L,\n");
		case AST_OP_G: astPrint(node->son[0],level+1);fprintf(out,"> "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_OP_G,\n");
			break;
		case AST_DECVAR: astPrint(node->son[0],level+1); fprintf(out,"%s ",node->symbol->text); fprintf(out,"= "); astPrint(node->son[1],level+1); fprintf(out,";\n");
			fprintf(stderr,"AST_DECVAR: %s,\n",node->symbol->text);
			break;
		case AST_DECVEC_A: astPrint(node->son[0],level+1); fprintf(out,"%s ",node->symbol->text); fprintf(out,"[ "); astPrint(node->son[1],level+1); fprintf(out,"] "); fprintf(out,": ");astPrint(node->son[2],level+1);fprintf(out,";\n");
			fprintf(stderr,"AST_DECVEC_A: %s,\n",node->symbol->text);
			break;
		case AST_DECVEC_B: astPrint(node->son[0],level+1); fprintf(out,"%s ",node->symbol->text); fprintf(out,"[ "); astPrint(node->son[1],level+1); fprintf(out,"] ");fprintf(out,";\n");
			fprintf(stderr,"AST_DECVEC_B: %s,\n",node->symbol->text);			
			break;
		case AST_DECPOINT: astPrint(node->son[0],level+1); fprintf(out,"#"); fprintf(out,"%s ",node->symbol->text); fprintf(out,"= "); astPrint(node->son[1],level+1); fprintf(out,";\n");
			fprintf(stderr,"AST_DECPOINT: %s,\n",node->symbol->text);
			break;
		case AST_DECFUNC: astPrint(node->son[0],level+1); fprintf(out,"%s ", node->symbol->text); fprintf(out,"( "); astPrint(node->son[1],level+1); fprintf(out,") "); astPrint(node->son[2],level+1);
			fprintf(stderr,"AST_DECFUNC: %s,\n",node->symbol->text);
			break;
		case AST_DECV_A: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level+1); 
			fprintf(stderr,"AST_DECV_A: %s,\n",node->symbol->text);
			break;
		case AST_DECV_B: fprintf(out,"' ' "); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_DECV_B,\n");
			break;
		case AST_KW_INT: fprintf(out, "int");
				fprintf(stderr, "int\n");
			break;
		case AST_KW_FLOAT: fprintf(out, "float\n");
				fprintf(stderr, "float\n");
			break;
		case AST_KW_CHAR: fprintf(out, "char\n");
				fprintf(stderr, "char\n");
			break;
		case AST_EMPTY: fprintf(out, " ");
				fprintf(stderr, "\n");
			break;
		case AST_SYMBOL_A: fprintf(out,"%s ", node->symbol->text);
			fprintf(stderr,"AST_SYMBOL_A: %s,\n",node->symbol->text);
			break;
		case AST_SYMBOL_B: fprintf(out,"%s ", node->symbol->text); fprintf(out,"[ "); astPrint(node->son[0],level+1);fprintf(out,"] ");
			fprintf(stderr,"AST_SYMBOL_B: %s,\n",node->symbol->text);
			break;
		case AST_SYMBOL_C: fprintf(out,"#");fprintf(out,"%s ", node->symbol->text);
			fprintf(stderr,"AST_SYMBOL_C: %s,\n",node->symbol->text);
			break;
		case AST_SYMBOL_D: fprintf(out,"&");fprintf(out,"%s ", node->symbol->text);
			fprintf(stderr,"AST_SYMBOL_D: %s,\n",node->symbol->text);
			break;
		case AST_SYMBOL_LIT: fprintf(out,"%s ", node->symbol->text);
			fprintf(stderr,"AST_SYMBOL_LIT: %s,\n",node->symbol->text);
			break;
		case AST_BODY: fprintf(out, "{\n"); astPrint(node->son[0],level+1); fprintf(out, "}\n");
			break;
				fprintf(stderr,"AST_BODY,\n");
		case AST_PARAMLIST_A: astPrint(node->son[0],level+1); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[1],level+1);
			break;
			fprintf(stderr,"AST_PARAMLIST_A: %s,\n",node->symbol->text);
		case AST_PARAMLIST_B: astPrint(node->son[0],level+1); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_PARAMLIST_B,\n");
			break;
		case AST_PARAMLIST_C: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PARAMLIST_C: %s,\n",node->symbol->text);
			break;
		case AST_PARAM_A: fprintf(out, ", "); astPrint(node->son[0],level+1); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_PARAM_A: %s,\n",node->symbol->text);
			break;
		case AST_PARAM_B: fprintf(out, ", "); astPrint(node->son[0],level+1); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_PARAM_B,\n");
			break;
		case AST_PARAM_C: fprintf(out, ", "); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PARAM_C: %s,\n",node->symbol->text);
			break;
		case AST_CMD: astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_CMD,\n");
			break;
		case AST_LISTCMD_A: astPrint(node->son[0],level+1); fprintf(out, ";\n");astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_LISTCMD_A,\n");
			break;
		case AST_LISTCMD_B: astPrint(node->son[0],level+1); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_LISTCMD_B,\n");
			break;
		case AST_LISTCMD_C: astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_LISTCMD_C,\n");
			break;
		case AST_ATTRIB_A: fprintf(out,"%s ",node->symbol->text); fprintf(out, "= "); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_ATTRIB_A: %s\n",node->symbol->text);
			break;
		case AST_ATTRIB_B: fprintf(out,"%s ",node->symbol->text); fprintf(out, "[ ");astPrint(node->son[0],level+1);fprintf(out, "] ");fprintf(out, "= "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_ATTRIB_B: %s\n",node->symbol->text);
			break;
		case AST_IF: fprintf(out, "if ("); astPrint(node->son[0],level+1); fprintf(out, ") "); fprintf(out, "then "); astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_IF,\n");
			break;
		case AST_IFELSE: fprintf(out, "if ("); astPrint(node->son[0],level+1); fprintf(out, ") "); fprintf(out, "then "); astPrint(node->son[1],level+1); fprintf(out, "else "); astPrint(node->son[2],level+1);
		fprintf(stderr,"AST_IFELSE,\n");
			break;
		case AST_WHILE: fprintf(out, "while ("); astPrint(node->son[0],level+1); fprintf(out, ") "); astPrint(node->son[1],level+1);
		fprintf(stderr,"AST_WHILE,\n");
			break;
		case AST_FOR: fprintf(out, "for ("); fprintf(out,"%s ",node->symbol->text); fprintf(out, "= ");astPrint(node->son[0],level+1); fprintf(out, "to ");astPrint(node->son[1],level+1);fprintf(out, ") "); astPrint(node->son[2],level+1);
		fprintf(stderr,"AST_FOR: %s,\n",node->symbol->text);
			break;
		case AST_INOUT: fprintf(out, "print "); astPrint(node->son[0],level+1);
		fprintf(stderr,"AST_INTOUT,\n");
			break;
		case AST_READ: fprintf(out, "read "); fprintf(out,"%s ",node->symbol->text);
			fprintf(stderr,"AST_READ: %s\n", node->symbol->text);
			break;
		case AST_RETURN: fprintf(out, "return "); astPrint(node->son[0],level+1);
		fprintf(stderr,"AST_RETURN,\n");
			break;
		case AST_PRINT_A: fprintf(out,"%s ",node->symbol->text);
			fprintf(stderr,"AST_PRINT_A: %s\n", node->symbol->text);
			break;
		case AST_PRINT_B: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PRINT_B: %s\n", node->symbol->text);
			break;
		case AST_PRINT_C: fprintf(out,"%s ",node->symbol->text);fprintf(out, "' ' ");astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PRINT_C: %s\n", node->symbol->text);
			break;
		case AST_PRINT_D: astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PRINT_D,\n");
			break;
		case AST_PRINT_E: astPrint(node->son[0],level+1);astPrint(node->son[1],level+1);
			fprintf(stderr,"AST_PRINT_E,\n");
			break;
		case AST_PRINT_F: astPrint(node->son[0],level+1); fprintf(out, "' ' "); astPrint(node->son[0],level+1);
			fprintf(stderr,"AST_PRINT_F,\n");
			break;
		case AST_VEC_SIZE: fprintf(out, "%s ",node->symbol->text);
			fprintf(stderr,"AST_VEC_SIZE: %s\n",node->symbol->text);
			break;
		case AST_FUNCCALL: fprintf(out, "%s ",node->symbol->text); fprintf(out, "( "); astPrint(node->son[0],level+1);fprintf(out," )");
			fprintf(stderr,"AST_FUNCCALL: %s\n", node->symbol->text);
			break;
		case AST_EXP: fprintf(out,"( ");astPrint(node->son[0],level+1); fprintf(out,") ");
			fprintf(stderr,"AST_EXP,\n");
			break;


		default: fprintf(out, "UNKNOWN,\n");

	}

}
