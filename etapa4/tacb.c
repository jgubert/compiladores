//Bruno Nunes e Paulo Silvestrin

#include "tac.h"
#include <stdlib.h>
#include <stdio.h>



//adiciona l2 depois do l1

void tacPrintOne(TAC *tac) {
	if(!tac) return;
	printf("TAC(");

	switch(tac->type) {
		case TAC_SYMBOL: printf("TAC_SYMBOL");
			break;
		case TAC_SYMBOL_VEC: printf("TAC_SYMBOL_VEC");
			break;
		case TAC_SYMBOL_LIT: printf("TAC_SYMBOL_LIT");
			break;
		case TAC_OP_SUM: printf("TAC_OP_SUM");
			break;
		case TAC_OP_SUB: printf("TAC_OP_SUB");
			break;
		case TAC_OP_MUL: printf("TAC_OP_MUL");
			break;
		case TAC_OP_DIV: printf("TAC_OP_DIV");
			break;
		case TAC_OP_LES: printf("TAC_OP_LES");
			break;
		case TAC_OP_GRE: printf("TAC_OP_GRE");
			break;
		case TAC_OP_LE: printf("TAC_OP_LE");
			break;
		case TAC_OP_GE: printf("TAC_OP_GE");
			break;
		case TAC_OP_EQ: printf("TAC_OP_EQ");
			break;
		case TAC_OP_NE: printf("TAC_OP_NE");
			break;
		case TAC_OP_AND: printf("TAC_OP_AND");
			break;
		case TAC_OP_OR: printf("TAC_OP_OR");
			break;

		case TAC_CALL: printf("TAC_CALL");
			break;

		case TAC_RET: printf("TAC_RET");
			break;
		case TAC_INP: printf("TAC_INP");
			break;
		case TAC_OUT: printf("TAC_OUT");
			break;

		case TAC_MOVE: printf("TAC_MOVE");
			break;
		case TAC_MOVE_IND: printf("TAC_MOVE_IND");
			break;

		case TAC_PARAM: printf("TAC_PARAM");
			break;

		case TAC_T_INT: printf("TAC_T_INT");
			break;
		case TAC_T_FLO: printf("TAC_T_FLO");
			break;
		case TAC_T_BOO: printf("TAC_T_BOO");
			break;
		case TAC_T_CHA: printf("TAC_T_CHA");
			break;

		case TAC_DECL_VEC: printf("TAC_DECL_VEC");
			break;
		case TAC_DECL_VAR: printf("TAC_DECL_VAR");
			break;

		case TAC_JFALSE: printf("TAC_JFALSE");
			break;
		case TAC_JTRUE: printf("TAC_JTRUE");
			break;
		case TAC_JUMP: printf("TAC_JUMP");
			break;
		case TAC_JUMPIND: printf("TAC_JUMPIND");
			break;
		case TAC_LABEL: printf("TAC_LABEL");
			break;

		case TAC_BEGINF: printf("TAC_BEGINF");
			break;
		case TAC_ENDF: printf("TAC_ENDF");
			break;

		case TAC_ARG: printf("TAC_ARG");
			break;
		default : printf("UNKNOWN");
	}

	if (tac->res) printf(", %s", tac->res->text); else printf(", ");
	if (tac->op1) printf(", %s", tac->op1->text); else printf(", ");
	if (tac->op2) printf(", %s", tac->op2->text); else printf(", ");
	
	printf(")\n");
}

TAC *codeGenerate(ASTREE *root) {
	// search tree bottom-up
	if(root == 0) return NULL;

	int i;
	TAC *result[MAX_CHILDREN];

	for(i = 0; i < MAX_CHILDREN; i++)
		result[i] = 0;

	TAC *codeList = NULL;

	for(i = 0; i < MAX_CHILDREN; i++)
		result[i] = codeGenerate(root->children[i]);

	// process this node

	switch(root->type) {
		case AST_SYMBOL: codeList = tacCreate(TAC_SYMBOL, root->symbol, 0, 0);
			break;
		case AST_SYMBOL_VEC: codeList = tacCreate(TAC_SYMBOL_VEC, makeTemp(), root->symbol, result[0]? result[0]->res : 0);
			codeList = tacJoin(result[0], codeList);
			break;
		case AST_SYMBOL_LIT: codeList = tacCreate(TAC_SYMBOL_LIT, root->symbol, 0, 0);
			break;
		case AST_OP_SUM: codeList = makeOps(TAC_OP_SUM, result[0], result[1]);
			break;
		case AST_OP_SUB: codeList = makeOps(TAC_OP_SUB, result[0], result[1]);
			break;
		case AST_OP_MUL: codeList = makeOps(TAC_OP_MUL, result[0], result[1]);
			break;
		case AST_OP_DIV: codeList = makeOps(TAC_OP_DIV, result[0], result[1]);
			break;
		case AST_OP_LES: codeList = makeOps(TAC_OP_LES, result[0], result[1]);
			break;
		case AST_OP_GRE: codeList = makeOps(TAC_OP_GRE, result[0], result[1]);
			break;
		case AST_OP_LE: codeList = makeOps(TAC_OP_LE, result[0], result[1]);
			break;
		case AST_OP_GE: codeList = makeOps(TAC_OP_GE, result[0], result[1]);
			break;
		case AST_OP_EQ: codeList = makeOps(TAC_OP_EQ, result[0], result[1]);
			break;
		case AST_OP_NE: codeList = makeOps(TAC_OP_NE, result[0], result[1]);
			break;
		case AST_OP_AND: codeList = makeOps(TAC_OP_AND, result[0], result[1]);
			break;
		case AST_OP_OR: codeList = makeOps(TAC_OP_OR, result[0], result[1]);
			break;
		case AST_LIST_E: codeList = tacJoin(tacJoin(result[0], tacCreate(TAC_ARG, result[0]? result[0]->res : 0, 0, 0)), result[1]);
			break;
		case AST_CHAM_F: codeList = tacJoin(result[0], tacCreate(TAC_CALL, makeTemp(), root->symbol, 0));
			break;
		case AST_IF: codeList = makeIf(result[0], result[1], result[2]);
			break;
		case AST_WHILE: codeList = makeWhile(result[0], result[1]);
			break;
		case AST_DO_WHILE: codeList = makeDoWhile(result[0], result[1]);
			break;
		case AST_RET: codeList = tacJoin(result[0], tacCreate(TAC_RET, result[0]? result[0]->res : 0, 0, 0));
			break;
		case AST_INP: codeList = tacCreate(TAC_INP, root->symbol, 0, 0);
			break;
		case AST_OUT: codeList = tacJoin(result[0], tacCreate(TAC_OUT, result[0]? result[0]->res : 0, 0, 0));
			break;
		case AST_ATR_VAR: codeList = tacJoin(result[0], tacCreate(TAC_MOVE, root->symbol, result[0]? result[0]->res : 0, 0));
			break;
		case AST_ATR_VEC: codeList = makeAtrVec(root->symbol, result[0], result[1]);
			break;
		case AST_SEQ: codeList = tacJoin(result[0], result[1]);
			break;
		case AST_PARAM: codeList = tacJoin(result[0], tacCreate(TAC_PARAM, root->symbol, result[0]? result[0]->res : 0, 0)); 
			break;
		case AST_T_INT: codeList = tacCreate(TAC_T_INT, 0, 0, 0);
			break;
		case AST_T_FLO: codeList = tacCreate(TAC_T_FLO, 0, 0, 0);
			break;
		case AST_T_BOO: codeList = tacCreate(TAC_T_BOO, 0, 0, 0);
			break;
		case AST_T_CHA: codeList = tacCreate(TAC_T_CHA, 0, 0, 0);
			break;
		case AST_LIST_P: codeList = tacJoin(result[0], result[1]);
			break;
		case AST_DEF_F: codeList = funcDecl(root->symbol, result[0], result[1], result[2]);
			break;
		case AST_DECL_VEC: codeList = tacCreate(TAC_DECL_VEC, root->symbol, result[1]? result[1]->res : 0, 0);
			break;
		case AST_VEC_SIZE: codeList = tacCreate(TAC_T_INT, root->symbol, 0, 0);
			break;
		case AST_DECL_VAR: codeList = tacCreate(TAC_DECL_VAR, root->symbol, 0, 0);
			break;
		case AST_DECL_GL: codeList = result[0];
			break;
		case AST_PROG: codeList = tacJoin(result[0], result[1]);
			break;
		case AST_COM: codeList = result[0];
			break;
		case AST_BLO_COM: codeList = result[0];
			break;
		case AST_EMPTY: 
			break;
		default: break;
	}

	return codeList;
}

TAC* makeAtrVec(HASH_ELEMENT* symbol, TAC* exprIndex, TAC* cmd){
	TAC *codeList = 0;

	TAC *moveInd = tacCreate(TAC_MOVE_IND, symbol, exprIndex ? exprIndex->res : 0, cmd ? cmd->res : 0);
	codeList = tacJoin(tacJoin(exprIndex, cmd), moveInd);

	return codeList;
}

TAC* makeOps(int type, TAC* op1, TAC* op2) {
	TAC* codeList;
	codeList = tacCreate(type, makeTemp(), op1? op1->res : 0, op2? op2->res : 0);
	codeList = tacJoin(op2, codeList);
	codeList = tacJoin(op1, codeList);
	return codeList;
}

/*
*			expr
*			jmpFalse	else
*			then
*			jmp 		end
*	else:	els
*	end:	...			*/
TAC* makeIf(TAC* expr, TAC* then, TAC* els) {
	HASH_ELEMENT* targetElse = makeLabel();
	HASH_ELEMENT* targetEnd = makeLabel();

	TAC* jumpElse = tacCreate(TAC_JFALSE, targetElse, expr->res, 0);
	TAC* jumpEnd = tacCreate(TAC_JUMP, targetEnd, 0, 0);

	TAC* labelElse = tacCreate(TAC_LABEL, targetElse, 0, 0);
	TAC* labelEnd = tacCreate(TAC_LABEL, targetEnd, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(expr ,jumpElse), then), jumpEnd), labelElse), els), labelEnd);
}

/*
*	begin:	expr
*			jmpFalse	end
*			cmd
*			jmp			begin
*	end:	...			*/
TAC* makeWhile(TAC* expr, TAC* cmd) {
	HASH_ELEMENT* targetBegin = makeLabel();
	HASH_ELEMENT* targetEnd = makeLabel();

	TAC* jumpBegin = tacCreate(TAC_JUMP, targetBegin, 0, 0);
	TAC* jumpEnd = tacCreate(TAC_JFALSE, targetEnd, expr->res, 0);

	TAC* labelBegin = tacCreate(TAC_LABEL, targetBegin, 0, 0);
	TAC* labelEnd = tacCreate(TAC_LABEL, targetEnd, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(labelBegin, expr), jumpEnd), cmd), jumpBegin), labelEnd);
}

/*
*	begin:	cmd
*			expr
*			jmpTrue		begin
*			...			*/
TAC* makeDoWhile(TAC* cmd, TAC* expr) {
	HASH_ELEMENT* targetBegin = makeLabel();

	TAC* jumpBegin = tacCreate(TAC_JTRUE, targetBegin, 0, 0);

	TAC* labelBegin = tacCreate(TAC_LABEL, targetBegin, 0, 0);

	return tacJoin(tacJoin(tacJoin(labelBegin, cmd), expr), jumpBegin);
}

TAC* funcDecl(HASH_ELEMENT* symbol, TAC* type, TAC* params, TAC* cmds) {
	TAC* beginf = tacCreate(TAC_BEGINF, symbol, 0, 0);
	TAC* endf = tacCreate(TAC_ENDF, symbol, 0, 0);

	return tacJoin(tacJoin(tacJoin(params, beginf), cmds), endf);

	/*HASH_ELEMENT* targetReturn = makeLabel();

	TAC* jumpIndReturn = tacCreate(TAC_JUMPIND, targetReturn, 0, 0);

	TAC* labelReturn = tacCreate(TAC_LABEL, targetReturn, 0, 0);
	TAC* labelBegin = tacCreate(TAC_LABEL, symbol, 0, 0);

	return tacJoin(tacJoin(tacJoin(labelReturn, labelBegin), cmds), jumpIndReturn);*/
}
void tacPrintList(TAC *tac) {	//backwards
	if(tac){
		tacPrintList(tac->prev);
		tacPrintOne(tac);
	}
}
