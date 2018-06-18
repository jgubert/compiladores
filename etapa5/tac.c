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
TAC *tacJoin(TAC *l1, TAC *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	TAC *t = l2;

	while(t->prev) {
		t = t->prev;
	}

	t->prev = l1;
	l1->next = l2;
	return l2;
}

void tacPrintBack(TAC *tac)
{
	if (!tac) return;
	tacPrintBack(tac->prev);
	tacPrintSingle(tac);

}
TAC *tacReverse(TAC *last)
{
	TAC *tac = 0;
	for (tac=last; tac->prev;tac=tac->prev)
		tac->prev->next = tac;
	return tac;
}
TAC *codeGenerator(AST *node)
{
 	if(!node) return 0;
	int i;
	TAC *result =0;
	TAC *code[MAX_SONS];
	
	
	for (i=0;i<MAX_SONS; i++)
		code[i]= codeGenerator(node->son[i]);

	switch(node->type)
		{
			case AST_SYMBOL_A || AST_SYMBOL_B || AST_SYMBOL_C || AST_SYMBOL_D: result =tacCreate(TAC_SYMBOL, node->symbol,0,0);
			break;
			case AST_SYMBOL_A || AST_SYMBOL_B || AST_SYMBOL_C || AST_SYMBOL_D: result =tacCreate(TAC_SYMBOL, node->symbol,0,0);
			case AST_OP_PLUS || AST_OP_MINUS || AST_OP_MULT || AST_OP_DIV || AST_OP_LE || AST_OP_GE || AST_OP_EQ || AST_OP_NE || AST_OP_NEG || AST_OP_AND || AST_OP_OR || AST_OP_L || AST_OP_G: result=tacJoin(code[0], tacJoin(code[0], tacCreate(TAC_ADD, makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0)));
			break;
			case
			//ADICAO DE OPERADORES
		}
		
	return result;
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
/*void tacPrintForward(TAC *tac)
{
	TAC *newtac = tacCreate(TAC_ADD,makeTemp(),code0?code0->res:0,code1?code1->res:0);
	return tacJoin(code0,tacJoin(code1,newtac));
}*/
TAC* makeOps(int type, TAC* op1, TAC* op2) {
	TAC* codeList;
	codeList = tacCreate(type, makeTemp(), op1? op1->res : 0, op2? op2->res : 0);
	codeList = tacJoin(op2, codeList);
	codeList = tacJoin(op1, codeList);
	return codeList;
}
void tacPrintSingle(TAC *tac)
{
	if (!tac) return;
	if (tac->type == TAC_SYMBOL) return;
	fprintf(stderr,"TAC(");
	switch (tac->type)
	{
		case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
		case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
		case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
		default: fprintf(stderr,"%d\n" ,tac->type); break;
	}
	if (tac->res) fprintf(stderr,",%s",tac->res->text);
	else fprintf(stderr,",0");
	if (tac->op1) fprintf(stderr,",%s",tac->op1->text);
	else fprintf(stderr,",0");
	if (tac->op2) fprintf(stderr,",%s",tac->op2->text);
	else fprintf(stderr,",0");
}
