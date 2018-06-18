#ifndef TAC_HEADER
#define TAC_HEADER

#include "ast.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>


#define TAC_SYMBOL		1
#define TAC_SYMBOL_VEC	2
#define TAC_SYMBOL_LIT	3

#define TAC_ADD		4
#define TAC_SUB		5
#define TAC_MUL		6
#define TAC_DIV		7
#define TAC_OP_LES		8
#define TAC_OP_GRE		9
#define TAC_OP_LE		10
#define TAC_OP_GE		11
#define TAC_OP_EQ		12
#define TAC_OP_NE		13
#define TAC_OP_AND		14
#define TAC_OP_OR		15

#define TAC_LABEL		16


typedef struct tac {
	int type;
	HASH *res;
	HASH *op1;
	HASH *op2;
	struct tac *prev;
	struct tac *next;
} TAC;


TAC *tacCreate(int type, HASH *res, HASH *op1, HASH *op2);
TAC *tacJoin(TAC *l1, TAC *l2);
void tacPrintSingle(TAC *tac);
void tacPrintBack(TAC *tac);


TAC *codeGenerator(AST *root);
TAC *makeOps(int type, TAC* op1, TAC* op2);
TAC *makeIf(TAC* cond, TAC* then, TAC* els);
TAC *makeWhile(TAC* expr, TAC* cmd);
TAC *makeDoWhile(TAC* expr, TAC* cmd);
TAC *funcDecl(HASH* symbol, TAC* type, TAC* params, TAC* cmds);
TAC *makeAtrVec(HASH* symbol, TAC* exprIndex, TAC* cmd);


#endif
