#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
int set_declarations(AST *node);
int check_use(AST *node);
int check_op(AST *node);
#endif
