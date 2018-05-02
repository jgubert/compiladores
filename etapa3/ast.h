#ifndef AST_HEADER
#define AST_HEADER

#include "hash.h"

#define MAX_SONS 4

#define AST_SYMBOL_A			1
#define AST_SYMBOL_B			150
#define AST_SYMBOL_C			151
#define AST_SYMBOL_D			152
#define AST_SYMBOL_VEC 			2
#define AST_SYMBOL_LIT 			3

#define AST_OP_PLUS 			4
#define AST_OP_MINUS			5
#define AST_OP_MULT			6
#define AST_OP_DIV			7
#define AST_OP_LE			8
#define AST_OP_GE			9
#define AST_OP_EQ			10
#define AST_OP_NE			11
#define AST_OP_AND			12
#define AST_OP_OR			13
#define AST_OP_L			14
#define AST_OP_G			15
#define AST_OP_NEG			16

#define AST_PROGRAM			17
#define AST_DECLIST			18
#define AST_DECVAR			19
#define AST_DECVEC_A			20
#define AST_DECVEC_B			90
#define AST_DECFUNC			21
#define AST_DECPOINT			22

#define AST_KW_CHAR			23
#define AST_KW_INT			24
#define AST_KW_FLOAT			25

#define AST_PARAMLIST_A			26
#define AST_PARAMLIST_B			85
#define AST_PARAMLIST_C			86
#define AST_PARAM_A			27
#define AST_PARAM_B			83
#define AST_PARAM_C			84
#define AST_CMD				28
#define AST_BODY			29
#define AST_LISTCMD_A			30
#define AST_LISTCMD_B			81
#define AST_LISTCMD_C			82


#define AST_ATTRIB_A			31
#define AST_ATTRIB_B			80
#define AST_IF				32
#define AST_IFELSE			33
#define AST_WHILE			34
#define AST_FOR				35
#define AST_PRINT_A			36
#define AST_PRINT_B			136
#define AST_PRINT_C			137
#define AST_PRINT_D			138
#define AST_PRINT_E			139
#define AST_PRINT_F			140
#define AST_READ			37
#define AST_RETURN			38

#define AST_EMPTY			39

#define AST_DEC				40
#define AST_VEC_SIZE			41
#define AST_INOUT			42	
#define AST_FUNCCALL			43
#define AST_DECV_A			44
#define AST_DECV_B			91
#define AST_EXP				45



typedef struct ast_node{

	int type;
	HASH * symbol;
	struct ast_node *son[MAX_SONS];

} AST;

AST* astCreate(int type, HASH* symbol, AST *son0, AST *son1, AST *son2, AST *son3);
AST *astSearchLeaf(AST *node);
void astPrint(AST *node, int level);


#endif
