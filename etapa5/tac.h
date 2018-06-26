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
#define TAC_CALL		17
#define TAC_FOR     18
#define TAC_RET			21
#define TAC_INP			22
#define TAC_OUT			23

#define TAC_MOVE		24
#define TAC_MOVE_IND	25

#define TAC_PARAM		27

#define TAC_T_INT		28
#define TAC_T_FLO		29
#define TAC_T_BOO		30
#define TAC_T_CHA		31

#define TAC_DECL_VEC	34
#define TAC_VEC_SIZE	35
#define TAC_DECL_VAR	36
#define TAC_DECL_GL		37

#define TAC_EMPTY		41

#define TAC_JFALSE		42
#define TAC_JTRUE		43
#define TAC_JUMP		44
#define TAC_JUMPIND		45

#define TAC_BEGINF		47
#define TAC_ENDF		48

#define TAC_ARG			49

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

 TAC *makeFor(HASH *symbol,TAC* exp1, TAC* exp2, TAC *cmd);
TAC *codeGenerator(AST *root);
TAC *makeOps(int type, TAC* op1, TAC* op2);
TAC *makeIf(TAC* cond, TAC* then, TAC* els);
TAC *makeWhile(TAC* expr, TAC* cmd);
TAC *makeDoWhile(TAC* expr, TAC* cmd);
TAC *funcDecl(HASH* symbol, TAC* type, TAC* params, TAC* cmds);
TAC *makeAtrVec(HASH* symbol, TAC* exprIndex, TAC* cmd);


#endif
