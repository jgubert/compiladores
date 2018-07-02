//Bruno Nunes e Paulo Silvestrin
#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include <stdio.h>


#define TAC_SYMBOL		1
#define TAC_SYMBOL_VEC	2
#define TAC_SYMBOL_LIT	3

#define TAC_OP_SUM		4
#define TAC_OP_SUB		5
#define TAC_OP_MUL		6
#define TAC_OP_DIV		7
#define TAC_OP_LES		8
#define TAC_OP_GRE		9
#define TAC_OP_LE		10
#define TAC_OP_GE		11
#define TAC_OP_EQ		12
#define TAC_OP_NE		13
#define TAC_OP_AND		14
#define TAC_OP_OR		15

#define TAC_CALL		17

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

#define TAC_LABEL		46

#define TAC_BEGINF		47
#define TAC_ENDF		48

#define TAC_ARG			49

typedef struct tac_structure {
	int type;
	HASH_ELEMENT *res;
	HASH_ELEMENT *op1;
	HASH_ELEMENT *op2;
	struct tac_structure *prev;
	struct tac_structure *next;
} TAC;


TAC * tacCreate(int type, HASH_ELEMENT *res, HASH_ELEMENT *op1, HASH_ELEMENT *op2);
TAC * tacJoin(TAC *l1, TAC *l2);
void tacPrintOne(TAC *tac);
void tacPrintList(TAC *tac);

TAC *codeGenerate(ASTREE *root);
TAC* makeOps(int type, TAC* op1, TAC* op2);
TAC* makeIf(TAC* cond, TAC* then, TAC* els);
TAC* makeWhile(TAC* expr, TAC* cmd);
TAC* makeDoWhile(TAC* expr, TAC* cmd);
TAC* funcDecl(HASH_ELEMENT* symbol, TAC* type, TAC* params, TAC* cmds);
TAC* makeAtrVec(HASH_ELEMENT* symbol, TAC* exprIndex, TAC* cmd);


#endif
