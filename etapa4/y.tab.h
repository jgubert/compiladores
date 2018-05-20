#define KW_CHAR 257
#define KW_INT 258
#define KW_FLOAT 259
#define KW_IF 260
#define KW_THEN 261
#define KW_ELSE 262
#define KW_WHILE 263
#define KW_FOR 264
#define KW_TO 265
#define KW_READ 266
#define KW_RETURN 267
#define KW_PRINT 268
#define OPERATOR_PLUS 269
#define OPERATOR_MINUS 270
#define OPERATOR_MULT 271
#define OPERATOR_DIV 272
#define OPERATOR_LE 273
#define OPERATOR_GE 274
#define OPERATOR_EQ 275
#define OPERATOR_NE 276
#define OPERATOR_AND 277
#define OPERATOR_OR 278
#define OPERATOR_L 279
#define OPERATOR_G 280
#define OPERATOR_NEG 281
#define TK_IDENTIFIER 282
#define LIT_INTEGER 283
#define LIT_REAL 284
#define LIT_CHAR 285
#define LIT_STRING 286
#define TOKEN_ERROR 287
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	HASH *symbol;
	AST *ast;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
