/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*João Pedro Gubert de Souza*/
/*Samuel Rudnicki*/

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "hash.h"


int yylex();
void yyerror(char* erro);
void stringError(void);
#line 17 "parser.y"
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
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    3,    4,    4,
    5,    6,    7,    7,    7,    7,    7,    8,    8,    8,
    9,    9,    9,   10,   10,   10,   10,   11,   11,   11,
   11,   12,   12,   12,   12,   12,   13,   14,   14,   14,
   15,   15,   16,   16,   16,   16,   17,   17,   17,   18,
   18,   18,   18,   18,   18,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    1,    5,    8,    6,
    6,    6,    2,    2,    2,    2,    0,    1,    1,    1,
    1,    1,    1,    3,    2,    2,    0,    4,    3,    3,
    0,    1,    1,    1,    1,    0,    3,    3,    2,    1,
    3,    6,    6,    8,    5,    9,    2,    2,    2,    1,
    2,    3,    1,    2,    3,    1,    4,    2,    2,    1,
    1,    3,    3,    3,    3,    3,    3,    2,    3,    3,
    3,    3,    3,    3,    3,    4,
};
static const YYINT yydefred[] = {                         0,
   18,   19,   20,    0,    1,    0,    4,    5,    6,    7,
    0,    2,    0,    0,    0,    0,    0,    0,   21,   23,
   22,    0,    0,    0,    0,    0,    0,    0,    8,    0,
    0,   26,    0,   25,    0,    0,   10,    0,    0,    0,
    0,   24,    0,   11,   12,    0,    0,    0,    0,    0,
   30,    0,   29,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   35,    0,   32,   33,   34,   13,   15,   14,
   16,    9,   28,    0,    0,    0,   48,    0,    0,   60,
   61,    0,    0,    0,    0,    0,   47,    0,    0,    0,
   39,    0,   37,    0,    0,    0,   68,    0,    0,    0,
   58,   59,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   51,    0,   54,    0,    0,
   38,    0,    0,    0,    0,    0,   69,    0,    0,   64,
   65,    0,    0,    0,    0,    0,    0,    0,    0,   52,
   55,    0,    0,   45,    0,   57,   76,    0,    0,    0,
    0,    0,    0,   44,    0,   46,
};
static const YYINT yydgoto[] = {                          4,
    5,   61,    7,    8,    9,   10,   50,   11,   26,   27,
   32,   62,   63,   64,   65,   66,   67,   87,   88,
};
static const YYINT yysindex[] = {                      -169,
    0,    0,    0,    0,    0, -169,    0,    0,    0,    0,
  -25,    0,  -28, -265, -177, -260,  192,  -23,    0,    0,
    0,  -30,  -42,   -8, -242,   -8,    2, -177,    0,  -38,
  224,    0,   -8,    0,  -67,    6,    0,   42,   -8, -223,
   -8,    0,  -81,    0,    0,   42,   42,   42,   42,   25,
    0,   -8,    0,   36,   46,   52, -187,  162,   86,  -50,
  -81,   39,    0,   -9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  162,  162, -162,    0,  162,   -6,    0,
    0,  162, -160, -155,  339,   22,    0,   79,  162,  162,
    0,  -81,    0,  193,  259,   62,    0,  162,  192,  287,
    0,    0,  162,  162,  162,  162,  162,  162,  162,  162,
  162,  162,  162,  162,   86,    0,   86,    0,  339,  315,
    0, -133,  286,  162,  327,   88,    0, -159, -159,    0,
    0,  339,  339,  339,  339, -126, -126, -168, -168,    0,
    0,   70,  286,    0,  357,    0,    0,  162, -128,  162,
  339,  286,  302,    0,  286,    0,
};
static const YYINT yyrindex[] = {                       135,
    0,    0,    0,    0,    0,  135,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  106,    0,    0,    0,
    0,    0,    0,  108,    0,  108,    0,    0,    0,    0,
    0,    0,  108,    0,    0,    0,    0,   89,  108,    0,
  108,    0,  -44,    0,    0,   89,   89,   89,   89,    0,
    0,  108,    0,    0,    0,    0,    0,    0,    0,    0,
  -44,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -32,    0,
    0,    0,    0,    0,  -58,  -57,    0,  -55,    0,    0,
    0,  -44,    0,    0,    0,    0,    0,    0,  106,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -52,    0,
    0,    0,  -46,    0,    0,    0,    0,  -10,   12,    0,
    0,  359,  387,  394,  401,   37,   59,  101,  131,    0,
    0,    0,  -46,    0,    0,    0,    0,    0,  -43,    0,
  -45,  -46,    0,    0,  -46,    0,
};
static const YYINT yygindex[] = {                         0,
  144,   18,    0,    0,    0,    0,  107,  -12,   17,   60,
   99,  -97,  123,  -53,    0,    0,    0,  -51,  616,
};
#define YYTABLESIZE 766
static const YYINT yytable[] = {                         56,
   49,   50,   56,   53,   25,   56,   41,   91,   56,   14,
   89,   17,   36,   42,   36,   43,   18,    6,   40,   38,
   37,   62,   23,    6,   62,  144,   56,   62,   29,   62,
   62,   22,   15,   99,  116,   31,  118,   28,  121,   33,
   90,   43,   35,   63,   36,  149,   63,   41,   62,   63,
   30,   63,   63,  115,  154,   43,   83,  156,   52,   84,
   56,   82,   16,  140,   45,  141,   49,   50,   74,   53,
   63,   74,   41,   49,   74,   74,   74,   74,   36,   42,
   36,   43,   62,   72,   98,   75,   25,    1,    2,    3,
   75,   76,   56,   75,   77,   74,   75,   92,   75,   75,
  103,  104,  105,  106,   63,   19,   20,   21,  111,  112,
  117,  105,  106,   83,   62,   93,   84,   75,   82,   96,
   83,  101,  124,   84,   34,   82,  102,  143,  147,   74,
  148,   42,   66,  152,    3,   66,   63,   51,   66,   53,
   66,   66,  103,  104,  105,  106,   27,   17,   31,   12,
   73,   75,   68,   69,   70,   71,   40,   44,  126,   66,
    0,   74,   67,    0,    0,   67,    0,    0,   67,    0,
   67,   67,    0,    0,    0,    1,    2,    3,   54,    0,
    0,   55,   56,   75,   57,   58,   59,    0,    0,   67,
    0,    0,    0,   66,    0,    0,   83,    0,    0,   84,
   60,   82,    0,   49,   50,    0,   53,    0,    0,   41,
    0,    0,    0,    0,    0,   36,   42,    0,    0,    0,
    0,    0,    0,   67,    0,   66,    0,    0,    0,   56,
    0,    0,   56,  122,    0,    0,   56,   56,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
   56,   62,   56,   56,   62,   67,   13,    0,   62,   62,
    0,    0,   62,   62,   62,   62,   62,   62,   62,   62,
   62,   62,   62,   63,   62,   62,   63,    0,    0,    0,
   63,   63,    0,    0,   63,   63,   63,   63,   63,   63,
   63,   63,   63,   63,   63,    0,   63,   63,   74,  123,
    0,   74,   78,   79,   80,    0,   81,   86,    0,   74,
   74,   74,   74,   74,   74,   74,   74,   74,   74,   74,
   75,   74,   74,   75,   46,   47,   48,  127,    0,    0,
    0,   75,   75,   75,   75,   75,   75,   75,   75,   75,
   75,   75,  155,   75,   75,    0,    0,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,   78,
   79,   80,   66,   81,   86,   66,   78,   79,   80,    0,
   81,   86,    0,   66,   66,   66,   66,    0,    0,   66,
   66,   66,   66,   66,    0,   66,   66,    0,    0,    0,
   70,    0,   67,   70,    0,   67,   70,    0,   70,   70,
    0,    0,    0,   67,   67,   67,   67,  142,   43,   67,
   67,   67,   67,   67,    0,   67,   67,   70,   71,  146,
    0,   71,    0,    0,   71,   72,   71,   71,   72,    0,
    0,   72,   73,   72,   72,   73,    0,    0,   73,    0,
   73,   73,   78,   79,   80,   71,   81,    0,    1,    2,
    3,   70,   72,    0,    0,    0,    0,    0,    0,   73,
    0,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,   24,   19,   20,   21,    0,    0,   71,
    1,    2,    3,   70,    0,    0,   72,    0,    0,    0,
    0,    0,    0,   73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   39,   19,   20,   21,    0,
    0,   71,    0,    0,    0,    0,    0,    0,   72,    0,
    0,    0,    0,    0,    0,   73,    0,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,    0,
    0,    0,    0,    0,    0,   54,    0,    0,   55,   56,
    0,   57,   58,   59,    0,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,   60,    0,    0,
  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,
  113,  114,    0,  103,  104,  105,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,    0,
   70,  150,    0,   70,    0,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,    0,    0,   70,
   70,   70,    0,   70,   70,    0,    0,    0,   71,    0,
    0,   71,    0,    0,    0,   72,    0,    0,   72,    0,
    0,    0,   73,    0,    0,   73,    0,   71,   71,   71,
    0,   71,   71,   85,   72,   72,   72,    0,   72,   72,
    0,   73,   73,   73,    0,   73,   73,    0,    0,   94,
   95,    0,    0,   97,    0,    0,    0,  100,    0,    0,
    0,    0,    0,    0,  119,  120,    0,    0,    0,    0,
    0,    0,    0,  125,    0,    0,    0,    0,  128,  129,
  130,  131,  132,  133,  134,  135,  136,  137,  138,  139,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  145,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  151,    0,  153,
};
static const YYINT yycheck[] = {                         32,
   59,   59,   35,   59,   17,   38,   59,   61,   41,   35,
   61,   40,   59,   59,   59,   59,  282,    0,   31,   58,
   59,   32,  283,    6,   35,  123,   59,   38,   59,   40,
   41,   15,   61,   40,   86,   44,   88,   61,   92,  282,
   91,  123,   41,   32,   28,  143,   35,   31,   59,   38,
   93,   40,   41,   32,  152,  123,   35,  155,  282,   38,
   93,   40,   91,  115,   59,  117,  125,  125,   32,  125,
   59,   35,  125,   32,   38,   40,   40,   41,  125,  125,
  125,  125,   93,   59,   91,   40,   99,  257,  258,  259,
   32,   40,  125,   35,  282,   59,   38,   59,   40,   41,
  269,  270,  271,  272,   93,  283,  284,  285,  277,  278,
   32,  271,  272,   35,  125,  125,   38,   59,   40,  282,
   35,  282,   61,   38,   26,   40,  282,  261,   41,   93,
   61,   33,   32,  262,    0,   35,  125,   39,   38,   41,
   40,   41,  269,  270,  271,  272,   41,   59,   41,    6,
   52,   93,   46,   47,   48,   49,  125,   35,   99,   59,
   -1,  125,   32,   -1,   -1,   35,   -1,   -1,   38,   -1,
   40,   41,   -1,   -1,   -1,  257,  258,  259,  260,   -1,
   -1,  263,  264,  125,  266,  267,  268,   -1,   -1,   59,
   -1,   -1,   -1,   93,   -1,   -1,   35,   -1,   -1,   38,
  282,   40,   -1,  262,  262,   -1,  262,   -1,   -1,  262,
   -1,   -1,   -1,   -1,   -1,  262,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  125,   -1,   -1,   -1,  262,
   -1,   -1,  265,   41,   -1,   -1,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  262,  285,  286,  265,  125,  282,   -1,  269,  270,
   -1,   -1,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  262,  285,  286,  265,   -1,   -1,   -1,
  269,  270,   -1,   -1,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,   -1,  285,  286,  262,   41,
   -1,  265,  281,  282,  283,   -1,  285,  286,   -1,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  262,  285,  286,  265,  283,  284,  285,   41,   -1,   -1,
   -1,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,   41,  285,  286,   -1,   -1,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  262,  285,  286,  265,  281,  282,  283,   -1,
  285,  286,   -1,  273,  274,  275,  276,   -1,   -1,  279,
  280,  281,  282,  283,   -1,  285,  286,   -1,   -1,   -1,
   32,   -1,  262,   35,   -1,  265,   38,   -1,   40,   41,
   -1,   -1,   -1,  273,  274,  275,  276,   93,  123,  279,
  280,  281,  282,  283,   -1,  285,  286,   59,   32,   93,
   -1,   35,   -1,   -1,   38,   32,   40,   41,   35,   -1,
   -1,   38,   32,   40,   41,   35,   -1,   -1,   38,   -1,
   40,   41,  281,  282,  283,   59,  285,   -1,  257,  258,
  259,   93,   59,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  282,  283,  284,  285,   -1,   -1,   93,
  257,  258,  259,  125,   -1,   -1,   93,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  282,  283,  284,  285,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
   -1,   -1,   -1,   -1,   -1,  260,   -1,   -1,  263,  264,
   -1,  266,  267,  268,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  282,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  269,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
  262,  265,   -1,  265,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,  281,
  282,  283,   -1,  285,  286,   -1,   -1,   -1,  262,   -1,
   -1,  265,   -1,   -1,   -1,  262,   -1,   -1,  265,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,  281,  282,  283,
   -1,  285,  286,   58,  281,  282,  283,   -1,  285,  286,
   -1,  281,  282,  283,   -1,  285,  286,   -1,   -1,   74,
   75,   -1,   -1,   78,   -1,   -1,   -1,   82,   -1,   -1,
   -1,   -1,   -1,   -1,   89,   90,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   98,   -1,   -1,   -1,   -1,  103,  104,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  148,   -1,  150,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#define YYUNDFTOKEN 309
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"' '",0,0,"'#'",0,0,"'&'",0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_FLOAT","KW_IF","KW_THEN",
"KW_ELSE","KW_WHILE","KW_FOR","KW_TO","KW_READ","KW_RETURN","KW_PRINT",
"OPERATOR_PLUS","OPERATOR_MINUS","OPERATOR_MULT","OPERATOR_DIV","OPERATOR_LE",
"OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR",
"OPERATOR_L","OPERATOR_G","OPERATOR_NEG","TK_IDENTIFIER","LIT_INTEGER",
"LIT_REAL","LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : decl",
"decl : dec decl",
"decl :",
"dec : decvar",
"dec : decvetor",
"dec : decfunction",
"dec : decpointer",
"decvar : typevar TK_IDENTIFIER '=' literal ';'",
"decvetor : typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ':' decv ';'",
"decvetor : typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"decfunction : typevar TK_IDENTIFIER '(' paramlist ')' body",
"decpointer : typevar '#' TK_IDENTIFIER '=' literal ';'",
"decv : LIT_INTEGER decv",
"decv : LIT_CHAR decv",
"decv : LIT_REAL decv",
"decv : ' ' decv",
"decv :",
"typevar : KW_CHAR",
"typevar : KW_INT",
"typevar : KW_FLOAT",
"literal : LIT_INTEGER",
"literal : LIT_CHAR",
"literal : LIT_REAL",
"paramlist : typevar TK_IDENTIFIER rest",
"paramlist : literal rest",
"paramlist : TK_IDENTIFIER rest",
"paramlist :",
"rest : ',' typevar TK_IDENTIFIER rest",
"rest : ',' literal rest",
"rest : ',' TK_IDENTIFIER rest",
"rest :",
"cmd : attribution",
"cmd : flux_control",
"cmd : inout",
"cmd : body",
"cmd :",
"body : '{' lcmd '}'",
"lcmd : cmd ';' lcmd",
"lcmd : dec lcmd",
"lcmd : cmd",
"attribution : TK_IDENTIFIER '=' exp",
"attribution : TK_IDENTIFIER '[' exp ']' '=' exp",
"flux_control : KW_IF '(' exp ')' KW_THEN cmd",
"flux_control : KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd",
"flux_control : KW_WHILE '(' exp ')' cmd",
"flux_control : KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp ')' cmd",
"inout : KW_PRINT print_elem",
"inout : KW_READ TK_IDENTIFIER",
"inout : KW_RETURN exp",
"print_elem : LIT_STRING",
"print_elem : LIT_STRING print_elem",
"print_elem : LIT_STRING ' ' print_elem",
"print_elem : exp",
"print_elem : exp print_elem",
"print_elem : exp ' ' print_elem",
"exp : TK_IDENTIFIER",
"exp : TK_IDENTIFIER '[' exp ']'",
"exp : '#' TK_IDENTIFIER",
"exp : '&' TK_IDENTIFIER",
"exp : LIT_INTEGER",
"exp : LIT_CHAR",
"exp : exp OPERATOR_PLUS exp",
"exp : exp OPERATOR_MINUS exp",
"exp : exp OPERATOR_MULT exp",
"exp : exp OPERATOR_DIV exp",
"exp : exp OPERATOR_L exp",
"exp : exp OPERATOR_G exp",
"exp : OPERATOR_NEG exp",
"exp : '(' exp ')'",
"exp : exp OPERATOR_LE exp",
"exp : exp OPERATOR_GE exp",
"exp : exp OPERATOR_EQ exp",
"exp : exp OPERATOR_NE exp",
"exp : exp OPERATOR_AND exp",
"exp : exp OPERATOR_OR exp",
"exp : TK_IDENTIFIER '(' paramlist ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 185 "parser.y"



int getLineNumber();
void initMe();

//#include "main.c"

void yyerror(char *erro){
	fprintf(stderr, "line: %d - Syntax error!\n", getLineNumber());
	stringError();
	exit(3);
}
#line 508 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 68 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;}
break;
case 2:
#line 71 "parser.y"
	{yyval.ast = astCreate(AST_DECLIST,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 3:
#line 72 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 4:
#line 75 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 5:
#line 76 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 6:
#line 77 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 7:
#line 78 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 8:
#line 81 "parser.y"
	{yyval.ast = astCreate(AST_DECVAR,yystack.l_mark[-3].symbol,yystack.l_mark[-4].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 9:
#line 84 "parser.y"
	{yyval.ast = astCreate(AST_DECVEC_A,yystack.l_mark[-6].symbol,yystack.l_mark[-7].ast,astCreate(AST_VEC_SIZE, yystack.l_mark[-4].symbol, 0, 0, 0, 0),yystack.l_mark[-1].ast,0);}
break;
case 10:
#line 85 "parser.y"
	{yyval.ast = astCreate(AST_DECVEC_B,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,astCreate(AST_VEC_SIZE,yystack.l_mark[-2].symbol,0,0,0,0),0,0);}
break;
case 11:
#line 88 "parser.y"
	{yyval.ast = astCreate(AST_DECFUNC,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 12:
#line 90 "parser.y"
	{yyval.ast = astCreate(AST_DECPOINT,yystack.l_mark[-3].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 13:
#line 92 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 14:
#line 93 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 15:
#line 94 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 16:
#line 95 "parser.y"
	{yyval.ast = astCreate(AST_DECV_B,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 17:
#line 96 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 18:
#line 99 "parser.y"
	{yyval.ast = astCreate(AST_KW_CHAR,0,0,0,0,0);}
break;
case 19:
#line 100 "parser.y"
	{yyval.ast = astCreate(AST_KW_INT,0,0,0,0,0);}
break;
case 20:
#line 101 "parser.y"
	{yyval.ast = astCreate(AST_KW_FLOAT,0,0,0,0,0);}
break;
case 21:
#line 104 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 22:
#line 105 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 23:
#line 106 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 24:
#line 109 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_A,yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 25:
#line 110 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 26:
#line 111 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_C,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 27:
#line 112 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 28:
#line 115 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_A,yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 29:
#line 116 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 30:
#line 117 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_C,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 31:
#line 118 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 32:
#line 122 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 33:
#line 123 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 34:
#line 124 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 35:
#line 125 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 36:
#line 126 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 37:
#line 129 "parser.y"
	{yyval.ast = astCreate(AST_BODY,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 38:
#line 132 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_A,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 39:
#line 133 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 40:
#line 134 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_C,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 41:
#line 137 "parser.y"
	{yyval.ast = astCreate(AST_ATTRIB_A,yystack.l_mark[-2].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 42:
#line 138 "parser.y"
	{yyval.ast = astCreate(AST_ATTRIB_B,yystack.l_mark[-5].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 43:
#line 141 "parser.y"
	{yyval.ast = astCreate(AST_IF,0,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 44:
#line 142 "parser.y"
	{yyval.ast = astCreate(AST_IFELSE,0,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 45:
#line 143 "parser.y"
	{yyval.ast = astCreate(AST_WHILE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 46:
#line 144 "parser.y"
	{yyval.ast = astCreate(AST_FOR,yystack.l_mark[-6].symbol,yystack.l_mark[-4].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 47:
#line 147 "parser.y"
	{yyval.ast = astCreate(AST_INOUT,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 48:
#line 148 "parser.y"
	{yyval.ast = astCreate(AST_READ,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 49:
#line 149 "parser.y"
	{yyval.ast = astCreate(AST_RETURN,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 50:
#line 152 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_A,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 51:
#line 153 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_B,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 52:
#line 154 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_C,yystack.l_mark[-2].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 53:
#line 155 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_D,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 54:
#line 156 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_E,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 55:
#line 157 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_F,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 56:
#line 160 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_A,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 57:
#line 161 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_B,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0);}
break;
case 58:
#line 162 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_C,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 59:
#line 163 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_D,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 60:
#line 164 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 61:
#line 165 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 62:
#line 166 "parser.y"
	{yyval.ast = astCreate(AST_OP_PLUS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 63:
#line 167 "parser.y"
	{yyval.ast = astCreate(AST_OP_MINUS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 64:
#line 168 "parser.y"
	{yyval.ast = astCreate(AST_OP_MULT,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 65:
#line 169 "parser.y"
	{yyval.ast = astCreate(AST_OP_DIV,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 66:
#line 170 "parser.y"
	{yyval.ast = astCreate(AST_OP_L,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 67:
#line 171 "parser.y"
	{yyval.ast = astCreate(AST_OP_G,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 68:
#line 172 "parser.y"
	{yyval.ast = astCreate(AST_OP_NEG,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 69:
#line 173 "parser.y"
	{yyval.ast = astCreate(AST_EXP,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 70:
#line 174 "parser.y"
	{yyval.ast = astCreate(AST_OP_LE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 71:
#line 175 "parser.y"
	{yyval.ast = astCreate(AST_OP_GE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 72:
#line 176 "parser.y"
	{yyval.ast = astCreate(AST_OP_EQ,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 73:
#line 177 "parser.y"
	{yyval.ast = astCreate(AST_OP_NE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 74:
#line 178 "parser.y"
	{yyval.ast = astCreate(AST_OP_AND,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 75:
#line 179 "parser.y"
	{yyval.ast = astCreate(AST_OP_OR,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 76:
#line 180 "parser.y"
	{yyval.ast = astCreate(AST_FUNCCALL,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0);}
break;
#line 1014 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
