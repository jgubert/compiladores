#ifndef AST_HEADER
#define AST_HEADER

#include "hash.h"

#define MAX_SONS 4

#define AST_SYMBOL			1
#define AST_SYMBOL_VEC 	2
#define AST_SYMBOL_LIT 	3

#define AST_OP_PLUS 		4
#define AST_OP_MINUS		5
#define AST_OP_MULT			6
#define AST_OP_DIV			7
#define AST_OP_LE				8
#define AST_OP_GE				9
#define AST_OP_EQ				10
#define AST_OP_NE				11
#define AST_OP_AND			12
#define AST_OP_OR				13
#define AST_OP_L				14
#define AST_OP_G				15
#define AST_OP_NEG			16

#define AST_PROGRAM			17
#define AST_DECLIST			18
#define AST_DECVAR			19
#define AST_DECVEC			20
#define AST_DECFUNC			21
#define AST_DECPOINT		22

#define AST_KW_CHAR			23
#define AST_KW_INT			24
#define AST_KW_FLOAT		25

#define AST_PARAMLIST		26
#define AST_PARAM				27
#define AST_CMD					28
#define AST_BODY				29
#define AST_LISTCMD			30

#define AST_ATTRIB			31
#define AST_IF					32
#define AST_IFELSE			33
#define AST_WHILE				34
#define AST_FOR					35
#define AST_PRINT				36
#define AST_READ				37
#define AST_RETURN			38

#define AST_EMPTY				39



typedef struct ast_node{

	int type;
	HASH * symbol;
	struct ast_node *son[MAX_SONS];

} AST;

AST* astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3);

void astPrint(AST *node, int level);


#endif
