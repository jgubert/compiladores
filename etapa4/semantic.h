#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
void set_declarations(AST *node);
void check_use(AST *node);
void check_op(AST *node);
#endif
