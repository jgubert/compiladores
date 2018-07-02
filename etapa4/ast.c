#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST* astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3){
	extern int getLineNumber();
	AST *newnode;
	newnode = (AST*) calloc(1, sizeof(AST));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
  newnode->lineNumber = getLineNumber();
	return newnode;

}
FILE *out;
void astPrint(AST *node, int level){

	if(!node) return;

	switch(node->type){
	
		case AST_DECLIST: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_DEC: astPrint(node->son[0],level);
			break;		
		case AST_OP_PLUS: astPrint(node->son[0],level);fprintf(out,"+ "); astPrint(node->son[1],level);
			break;
		case AST_OP_MINUS: astPrint(node->son[0],level);fprintf(out,"- "); astPrint(node->son[1],level);
			break;
		case AST_OP_MULT: astPrint(node->son[0],level);fprintf(out,"* "); astPrint(node->son[1],level);
			break;
		case AST_OP_DIV: astPrint(node->son[0],level);fprintf(out,"/ "); astPrint(node->son[1],level);
			break;
		case AST_OP_LE: astPrint(node->son[0],level);fprintf(out,"<= "); astPrint(node->son[1],level);
			break;
		case AST_OP_GE: astPrint(node->son[0],level);fprintf(out,">= "); astPrint(node->son[1],level);
			break;
		case AST_OP_EQ: astPrint(node->son[0],level);fprintf(out,"== "); astPrint(node->son[1],level);
			break;
		case AST_OP_NE: astPrint(node->son[0],level);fprintf(out,"!= "); astPrint(node->son[1],level);
			break;
		case AST_OP_NEG: fprintf(out,"!"); astPrint(node->son[0],level);
			break;
		case AST_OP_AND: astPrint(node->son[0],level);fprintf(out,"AND "); astPrint(node->son[1],level);
			break;
		case AST_OP_OR: astPrint(node->son[0],level);fprintf(out,"OR "); astPrint(node->son[1],level);
			break;
		case AST_OP_L: astPrint(node->son[0],level);fprintf(out,"< "); astPrint(node->son[1],level);
			break;
		case AST_OP_G: astPrint(node->son[0],level);fprintf(out,"> "); astPrint(node->son[1],level);
			break;
		case AST_DECVAR: astPrint(node->son[0],level); fprintf(out,"%s ",node->symbol->text); fprintf(out,"= "); astPrint(node->son[1],level); fprintf(out,";\n");
			break;
		case AST_DECVEC_A: astPrint(node->son[0],level); fprintf(out,"%s ",node->symbol->text); fprintf(out,"[ "); astPrint(node->son[1],level); fprintf(out,"] "); fprintf(out,": ");astPrint(node->son[2],level);fprintf(out,";\n");
			break;
		case AST_DECVEC_B: astPrint(node->son[0],level); fprintf(out,"%s ",node->symbol->text); fprintf(out,"[ "); astPrint(node->son[1],level); fprintf(out,"] ");fprintf(out,";\n");
			break;
		case AST_DECPOINT: astPrint(node->son[0],level); fprintf(out,"#"); fprintf(out,"%s ",node->symbol->text); fprintf(out,"= "); astPrint(node->son[1],level); fprintf(out,";\n");
			break;
		case AST_DECFUNC: astPrint(node->son[0],level); fprintf(out,"%s ", node->symbol->text); fprintf(out,"( "); astPrint(node->son[1],level); fprintf(out,") "); astPrint(node->son[2],level);
			break;
		case AST_DECV_A: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level); 
			break;
		case AST_DECV_B: fprintf(out,"' ' "); astPrint(node->son[0],level); 
			break;
		case AST_KW_INT: fprintf(out, "int ");
			break;
		case AST_KW_FLOAT: fprintf(out, "float ");
			break;
		case AST_KW_CHAR: fprintf(out, "char ");
			break;
		case AST_EMPTY: fprintf(out, " ");
			break;
		case AST_SYMBOL_A: fprintf(out,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_B: fprintf(out,"%s ", node->symbol->text); fprintf(out,"[ "); astPrint(node->son[0],level);fprintf(out,"] ");
			break;
		case AST_SYMBOL_C: fprintf(out,"#");fprintf(out,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_D: fprintf(out,"&");fprintf(out,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_LIT: fprintf(out,"%s ", node->symbol->text);
			break;
		case AST_SYMBOL_LIT_R: fprintf(out,"%s ", node->symbol->text);
			break;
		case AST_BODY: fprintf(out, "{\n"); astPrint(node->son[0],level); fprintf(out, "}\n");
			break;
		case AST_PARAMLIST_A: astPrint(node->son[0],level); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[1],level);
			break;
		case AST_PARAMLIST_B: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_PARAMLIST_C: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_PARAM_A: fprintf(out, ", "); astPrint(node->son[0],level); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[1],level);
			break;
		case AST_PARAM_B: fprintf(out, ", "); astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_PARAM_C: fprintf(out, ", "); fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_CMD: astPrint(node->son[0],level);
			break;
		case AST_LISTCMD_A: astPrint(node->son[0],level); fprintf(out, ";\n");astPrint(node->son[1],level);
			break;
		case AST_LISTCMD_B: astPrint(node->son[0],level); astPrint(node->son[1],level);
			break;
		case AST_LISTCMD_C: astPrint(node->son[0],level);
			break;
		case AST_ATTRIB_A: fprintf(out,"%s ",node->symbol->text); fprintf(out, "= "); astPrint(node->son[0],level);
			break;
		case AST_ATTRIB_B: fprintf(out,"%s ",node->symbol->text); fprintf(out, "[ ");astPrint(node->son[0],level);fprintf(out, "] ");fprintf(out, "= "); astPrint(node->son[1],level);
			break;
		case AST_IF: fprintf(out, "if ("); astPrint(node->son[0],level); fprintf(out, ") "); fprintf(out, "then "); astPrint(node->son[1],level);
			break;
		case AST_IFELSE: fprintf(out, "if ("); astPrint(node->son[0],level); fprintf(out, ") "); fprintf(out, "then "); astPrint(node->son[1],level); fprintf(out, "else "); astPrint(node->son[2],level);
			break;
		case AST_WHILE: fprintf(out, "while ("); astPrint(node->son[0],level); fprintf(out, ") "); astPrint(node->son[1],level);
			break;
		case AST_FOR: fprintf(out, "for ("); fprintf(out,"%s ",node->symbol->text); fprintf(out, "= ");astPrint(node->son[0],level); fprintf(out, "to ");astPrint(node->son[1],level);fprintf(out, ") "); astPrint(node->son[2],level);
			break;
		case AST_INOUT: fprintf(out, "print "); astPrint(node->son[0],level);
			break;
		case AST_READ: fprintf(out, "read "); fprintf(out,"%s ",node->symbol->text);
			break;
		case AST_RETURN: fprintf(out, "return "); astPrint(node->son[0],level);
			break;
		case AST_PRINT_A: fprintf(out,"%s ",node->symbol->text);
			break;
		case AST_PRINT_B: fprintf(out,"%s ",node->symbol->text); astPrint(node->son[0],level);
			break;
		case AST_PRINT_C: fprintf(out,"%s ",node->symbol->text);fprintf(out, "' ' ");astPrint(node->son[0],level);
			break;
		case AST_PRINT_D: astPrint(node->son[0],level);
			break;
		case AST_PRINT_E: astPrint(node->son[0],level);astPrint(node->son[1],level);
			break;
		case AST_PRINT_F: astPrint(node->son[0],level); fprintf(out, "' ' "); astPrint(node->son[0],level);
			break;
		case AST_VEC_SIZE: fprintf(out, "%s ",node->symbol->text);
			break;

		case AST_FUNCCALL: fprintf(out, "%s ",node->symbol->text); fprintf(out, "( "); astPrint(node->son[0],level);fprintf(out," )");
			break;
		case AST_EXP: fprintf(out,"( ");astPrint(node->son[0],level); fprintf(out,") ");
			break;


		default: fprintf(out, "UNKNOWN,\n");

	}


}
