#include "tac.h"

TAC *tacCreate(int type, HASH *res, HASH *op1, HASH *op2) {
	TAC *newTac = 0;
	newTac = (TAC*) calloc(1, sizeof(TAC));
	newTac->type = type;
	newTac->res = res;
	newTac->op1 = op1;
	newTac->op2 = op2;
	newTac->prev = 0;
	newTac->next = 0;
	return newTac;
}


void tacPrintBack(TAC *tac)
{
	if (!tac) return;
					tacPrintBack(tac->prev);
		tacPrintSingle(tac);

}
TAC *codeGenerator(AST *node)
{
 	if(!node) return 0;
	int i;
	TAC *result =0;
	TAC *code[MAX_SONS];
	
	
	for (i=0;i<MAX_SONS; i++)
		code[i]= codeGenerator(node->son[i]);
 // fprintf(stderr,"inclui 1");
	switch(node->type)
		{
			case AST_SYMBOL_A: result =tacCreate(TAC_SYMBOL, node->symbol,0,0);
			break;
			case AST_SYMBOL_B: result =tacCreate(TAC_SYMBOL_VEC, node->symbol,0,0);
			break;
			case AST_SYMBOL_LIT: result =tacCreate(TAC_SYMBOL_LIT, node->symbol,0,0);
			break;
			case AST_OP_PLUS: result= makeOps(TAC_OP_PLUS,code[0],code[1]);
			break;
			case AST_OP_MINUS: result=makeOps(TAC_OP_MINUS,code[0],code[1]);
			break;
			case AST_OP_MULT: result=makeOps(TAC_OP_MULT,code[0],code[1]);
			break;
			case AST_OP_DIV: result=makeOps(TAC_OP_DIV,code[0],code[1]);
			break;
			case AST_OP_L: result=makeOps(TAC_OP_LES,code[0],code[1]);
			break;
			case AST_OP_G: result=makeOps(TAC_OP_GRE,code[0],code[1]);
			break;
			case AST_OP_LE: result=makeOps(TAC_OP_LES,code[0],code[1]);
			break;
			case AST_OP_GE: result=makeOps(TAC_OP_GRE,code[0],code[1]);
			break;
			case AST_OP_EQ: result=makeOps(TAC_OP_EQ,code[0],code[1]);
			break;
			case AST_OP_NE: result=makeOps(TAC_OP_NE,code[0],code[1]);
			break;
			case AST_OP_AND: result=makeOps(TAC_OP_AND,code[0],code[1]);
			break;
			case AST_OP_OR: result=makeOps(TAC_OP_OR,code[0],code[1]);
			break;
			case AST_PARAM_A: result = tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, code[0]? code[0]->res : 0, 0, 0)), code[1]);
			break;
			case AST_PARAM_B: result = tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, code[0]? code[0]->res : 0, 0, 0)), code[1]);
			break;
			case AST_PARAM_C: result = tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, code[0]? code[0]->res : 0, 0, 0)), code[1]);
			break;
		case AST_FUNCCALL: result = tacJoin(code[0], tacCreate(TAC_CALL, makeTemp(), node->symbol, 0));
			break;
		case AST_IFELSE: result = makeIf(code[0], code[1], code[2]);
			break;
			case AST_IF: result = makeIf(code[0], code[1], code[2]);
			break;
		case AST_WHILE: result = makeWhile(code[0], code[1]);
			break;
		case AST_FOR: //result = makeFor(node->symbol,code[0], code[1],code[3]);
			break;
		case AST_RETURN: result = tacJoin(code[0], tacCreate(TAC_RET, code[0]? code[0]->res : 0, 0, 0));
			break;
		case AST_READ: result = tacCreate(TAC_INP, node->symbol, 0, 0);
			break;
		case AST_INOUT: result = tacJoin(code[0], tacCreate(TAC_OUT, code[0]? code[0]->res : 0, 0, 0));
			break;
		case AST_ATTRIB_A: result = tacJoin(code[1], tacCreate(TAC_MOVE, node->symbol, code[0]? code[0]->res : 0, 0));
			break;
		case AST_ATTRIB_B: result = makeAtrVec(node->symbol, code[0], code[1]);
			break;
		case AST_LISTCMD_A: result = tacJoin(code[0], code[1]);
			break;
			case AST_LISTCMD_B: result = tacJoin(code[0], code[1]);
			break;
			case AST_LISTCMD_C: result = tacJoin(code[0], code[1]);
			break;
//			case AST_PARAM_A: result = tacJoin(code[0], tacCreate(TAC_PARAM, node->symbol, code[0]? code[0]->res : 0, 0)); 
	//		break;
		//	case AST_PARAM_B: result = tacJoin(code[0], tacCreate(TAC_PARAM, node->symbol, code[0]? code[0]->res : 0, 0)); 
			//break;
			//case AST_PARAM_C: result = tacJoin(code[0], tacCreate(TAC_PARAM, node->symbol, code[0]? code[0]->res : 0, 0)); 
			//break;
		case AST_KW_INT: result = tacCreate(TAC_T_INT, 0, 0, 0);
			break;
		case AST_KW_FLOAT: result = tacCreate(TAC_T_FLO, 0, 0, 0);
			break;
		case AST_KW_CHAR: result = tacCreate(TAC_T_CHA, 0, 0, 0);
			break;
		case AST_PARAMLIST_A: result = tacJoin(code[0], code[1]);
			break;
			case AST_PARAMLIST_B: result = tacJoin(code[0], code[1]);
			break;
			case AST_PARAMLIST_C: result = tacJoin(code[0], code[1]);
			break;
			case AST_DECFUNC: result = funcDecl(node->symbol, code[0], code[1], code[2]);
			break;
			case AST_DECVEC_B: result = tacJoin(code[0],tacCreate(TAC_DECL_VEC, node->symbol, code[0]? code[0]->res:0, 0));
			break;
			case AST_DECVEC_A: result = tacJoin(code[0],tacCreate(TAC_DECL_VEC, node->symbol, code[0]? code[0]->res:0, 0));
			break;
			case AST_VEC_SIZE: result = tacCreate(TAC_VEC_SIZE, node->symbol, 0, 0);
			break;
		case AST_DECVAR: result = tacJoin(code[1],tacCreate(TAC_DECL_VAR, node->symbol, code[1]? code[1]->res:0, 0));
			break;
		case AST_DEC: result = code[0];
			break;
		case AST_DECLIST: result = tacJoin(code[0], code[1]);
			break;
		case AST_CMD: result = code[0];
			break;
		case AST_BODY: result = code[0];
			break;
		case AST_EMPTY: 
			break;
		default: break;
	}
		
	return result;
}

TAC* makeOps(int type, TAC* op1, TAC* op2) {
	TAC* codeList;
	codeList = tacCreate(type, makeTemp(), op1? op1->res : 0, op2? op2->res : 0);
	codeList = tacJoin(op2,codeList);
	codeList = tacJoin(op1,codeList);
	return codeList;
}
void tacPrintSingle(TAC *tac)
{
	if (!tac) return;
	fprintf(stderr,"TAC(");
	switch (tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
				case TAC_SYMBOL_LIT: fprintf(stderr, "TAC_SYMBOL_LIT"); break;
		case TAC_OP_PLUS: fprintf(stderr, "TAC_OP_PLUS"); break;
		case TAC_OP_MINUS: fprintf(stderr, "TAC_OP_MINUS"); break;
		case TAC_OP_MULT: fprintf(stderr, "TAC_OP_MULT"); break;
		case TAC_OP_DIV: fprintf(stderr, "TAC_OP_DIV"); break;
		case TAC_OP_LES: fprintf(stderr, "TAC_OP_LES"); break;
		case TAC_OP_GRE: fprintf(stderr, "TAC_OP_GRE"); break;
		case TAC_OP_LE: fprintf(stderr, "TAC_OP_LE"); break;
		case TAC_OP_GE: fprintf(stderr, "TAC_OP_GE"); break;
		case TAC_OP_NE: fprintf(stderr, "TAC_OP_NE"); break;
		case TAC_OP_AND: fprintf(stderr, "TAC_OP_AND"); break;
		case TAC_OP_EQ: fprintf(stderr, "TAC_OP_EQ"); break;
		case TAC_OP_OR: fprintf(stderr, "TAC_OP_OR"); break;
		case TAC_CALL: fprintf(stderr, "TAC_FUNCALL"); break;
		case TAC_RET: fprintf(stderr,"TAC_RETURN");
			break;
		case TAC_INP: fprintf(stderr,"TAC_READ");
			break;
		case TAC_OUT: fprintf(stderr,"TAC_PRINT");
			break;
		case TAC_MOVE: fprintf(stderr,"TAC_MOVE");
			break;
		case TAC_MOVE_IND: fprintf(stderr,"TAC_MOVE_IND");
			break;
		case TAC_PARAM: fprintf(stderr,"TAC_PARAM");
			break;
		case TAC_FOR: fprintf(stderr,"TAC_FOR");
		break;
		case TAC_T_INT: fprintf(stderr,"TAC_INT");
			break;
		case TAC_T_FLO: fprintf(stderr,"TAC_FLOAT");
			break;
		case TAC_T_CHA: fprintf(stderr,"TAC_CHAR"); break;
		case TAC_DECL_VEC: fprintf(stderr,"TAC_DECL_VEC");break;
		case TAC_DECL_VAR: fprintf(stderr,"TAC_DECL_VAR");break;
		case TAC_JFALSE: fprintf(stderr,"TAC_JFALSE");break;
		case TAC_JTRUE: fprintf(stderr,"TAC_JTRUE");break;
		case TAC_JUMP: fprintf(stderr,"TAC_JUMP");break;
		case TAC_JUMPIND: fprintf(stderr,"TAC_JUMPIND");break;
		case TAC_LABEL: fprintf(stderr,"TAC_LABEL");break;
		case TAC_BEGINF: fprintf(stderr,"TAC_BEGINF");
			break;
		case TAC_ENDF: fprintf(stderr,"TAC_ENDF");
			break;

		case TAC_ARG: fprintf(stderr,"TAC_ARG");
			break;
		default : fprintf(stderr,"%d",tac->type);
	}
	if (tac->res) fprintf(stderr,",%s",tac->res->text);
	else fprintf(stderr,",0");
	if (tac->op1) fprintf(stderr,",%s",tac->op1->text);
	else fprintf(stderr,",0");
	if (tac->op2) fprintf(stderr,",%s",tac->op2->text);
	else fprintf(stderr,",0");
	fprintf(stderr,")\n");
}

TAC* makeAtrVec(HASH* symbol, TAC* exprIndex, TAC* cmd){
	TAC *result = 0;

	TAC *moveInd = tacCreate(TAC_MOVE_IND, symbol, exprIndex ? exprIndex->res : 0, cmd ? cmd->res : 0);
	result = tacJoin(tacJoin(exprIndex, cmd), moveInd);

	return result;
}
TAC* makeWhile(TAC* expr, TAC* cmd) {
	HASH* targetBegin = makeLabel();
	HASH* targetEnd = makeLabel();

	TAC* jumpBegin = tacCreate(TAC_JUMP, targetBegin, 0, 0);
	
	TAC* jumpEnd = tacCreate(TAC_JFALSE, targetEnd, expr? expr->res :0, 0);
	TAC* labelBegin = tacCreate(TAC_LABEL, targetBegin, 0, 0);
	TAC* labelEnd = tacCreate(TAC_LABEL, targetEnd, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(labelBegin, expr), jumpEnd), cmd), jumpBegin), labelEnd);
}
TAC* makeIf(TAC* expr, TAC* then, TAC* els) {
	HASH* targetElse = makeLabel();
	HASH* targetEnd = makeLabel();

	TAC* jumpElse = tacCreate(TAC_JFALSE, targetElse, expr->res, 0);
	TAC* jumpEnd = tacCreate(TAC_JUMP, targetEnd, 0, 0);

	TAC* labelElse = tacCreate(TAC_LABEL, targetElse, 0, 0);
	TAC* labelEnd = tacCreate(TAC_LABEL, targetEnd, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(expr ,jumpElse), then), jumpEnd), labelElse), els), labelEnd);
}

 /*TAC *makeFor(HASH *symbol,TAC *exp1, TAC* exp2, TAC *cmd){
 
 //declaracao inicial
 
 TAC *inicio = tacJoin(exp1,tacCreate(TAC_DECL_VAR, symbol, exp1? exp1->res:0, 0));
 HASH *targetLoop = makeLabel();
 TAC *labelLoop = tacCreate(TAC_LABEL, targetLoop, 0, 0);
 HASH *Um = makeUm();
 TAC *um= tacCreate(TAC_SYMBOL_LIT, Um, 0, 0);
 tacPrintSingle(um);
  tacPrintSingle(exp1);
 TAC *sum = makeOps(TAC_ADD, exp1,um);
   tacPrintSingle(sum);
 TAC *exp = makeOps(TAC_OP_GE,sum,exp2);
   tacPrintSingle(exp);
 HASH * targetEnd = makeLabel();
 TAC *jumpBegin = tacCreate(TAC_JUMP, targetLoop, 0, 0);
 tacPrintSingle(jumpBegin);
 TAC *jumpElse = tacCreate(TAC_JFALSE, targetLoop, exp?exp->res:0,0);
 tacPrintSingle(jumpElse);
 TAC *labelEnd = tacCreate(TAC_LABEL, targetEnd, 0 ,0);
 tacPrintSingle(labelEnd);
 
 TAC *r1 = tacJoin(tacJoin(tacJoin(tacJoin(inicio,labelLoop),exp),cmd),labelEnd);
   fprintf(stderr,"aqui");
 return r1;
 }*/
TAC *tacJoin(TAC *l1, TAC *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	TAC *t = l2;

	while(t->prev && t!=t->prev) {
//		fprintf(stderr,"prev %s",l2->res->text);
		t = t->prev;
	}
	if(t) t->prev = l1;
	l1->next = l2;
	return l2;
}
TAC* funcDecl(HASH* symbol, TAC* type, TAC* params, TAC* cmds) {
	TAC* beginf = tacCreate(TAC_BEGINF, symbol, 0, 0);
	TAC* endf = tacCreate(TAC_ENDF, symbol, 0, 0);

	return tacJoin(tacJoin(tacJoin(params, beginf), cmds), endf);
}

