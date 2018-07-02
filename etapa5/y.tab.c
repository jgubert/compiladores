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
#include "semantic.h"
#include "tac.h"


int yylex();
void yyerror(char* erro);
void stringError(void);
#line 19 "parser.y"
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
#line 49 "y.tab.c"

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
   19,   19,   19,   19,   19,   19,   19,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    1,    5,    8,    6,
    6,    6,    2,    2,    2,    2,    0,    1,    1,    1,
    1,    1,    1,    3,    2,    2,    0,    4,    3,    3,
    0,    1,    1,    1,    1,    0,    3,    3,    2,    1,
    3,    6,    6,    8,    5,    9,    2,    2,    2,    1,
    2,    3,    1,    2,    3,    1,    4,    2,    2,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    2,    3,
    3,    3,    3,    3,    3,    3,    4,
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
   62,   61,    0,    0,    0,    0,    0,   47,    0,    0,
    0,   39,    0,   37,    0,    0,    0,   69,    0,    0,
    0,   58,   59,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,   54,    0,
    0,   38,    0,    0,    0,    0,    0,   70,    0,    0,
   65,   66,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   55,    0,    0,   45,    0,   57,   77,    0,    0,
    0,    0,    0,    0,   44,    0,   46,
};
static const YYINT yydgoto[] = {                          4,
    5,   61,    7,    8,    9,   10,   50,   11,   26,   27,
   32,   62,   63,   64,   65,   66,   67,   88,   89,
};
static const YYINT yysindex[] = {                      -216,
    0,    0,    0,    0,    0, -216,    0,    0,    0,    0,
  -18,    0,  -22, -270, -154, -235, -125,  -12,    0,    0,
    0,   -5,  -36,   11, -218,   11,   31, -154,    0,  -13,
  225,    0,   11,    0,  -41,   32,    0,  -24,   11, -192,
   11,    0, -112,    0,    0,  -24,  -24,  -24,  -24,   36,
    0,   11,    0,   61,   67,   70, -166,  104,   54,  -29,
 -112,   58,    0,   -6,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  104,  104, -161,    0,  104,  -17,    0,
    0,    0,  104, -160, -158,  302,   28,    0,   88,  104,
  104,    0, -112,    0,  224,  290,   64,    0,  104, -125,
  314,    0,    0,  104,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,  104,   54,    0,   54,    0,  302,
  -92,    0, -126,  382,  104,  263,   96,    0, -242, -242,
    0,    0,  302,  302,  302,  302, -157, -157, -173, -173,
    0,    0,   77,  382,    0,  506,    0,    0,  104, -122,
  104,  302,  382,  341,    0,  382,    0,
};
static const YYINT yyrindex[] = {                       141,
    0,    0,    0,    0,    0,  141,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  108,    0,    0,    0,
    0,    0,    0,  109,    0,  109,    0,    0,    0,    0,
    0,    0,  109,    0,    0,    0,    0,   94,  109,    0,
  109,    0,  -38,    0,    0,   94,   94,   94,   94,    0,
    0,  109,    0,    0,    0,    0,    0,    0,    0,    0,
  -38,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -32,    0,
    0,    0,    0,    0,    0,  -55,  -54,    0,  -52,    0,
    0,    0,  -38,    0,    0,    0,    0,    0,    0,  108,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -49,
    0,    0,    0,  -46,    0,    0,    0,    0,   -7,   18,
    0,    0,  343,  392,  420,  431,   43,   68,  131,  164,
    0,    0,    0,  -46,    0,    0,    0,    0,    0,  -37,
    0,  -45,  -46,    0,    0,  -46,    0,
};
static const YYINT yygindex[] = {                         0,
  158,   20,    0,    0,    0,    0,  127,  -15,    9,   65,
  614, -109,  132,  -42,    0,    0,    0,  -51,  649,
};
#define YYTABLESIZE 800
static const YYINT yytable[] = {                         56,
  143,   25,   56,   49,   50,   56,   53,   49,   56,   41,
   43,   18,   36,   42,  145,   40,   14,   17,   92,    6,
   36,   43,  100,   22,   63,    6,   56,   63,  106,  107,
   63,   90,   63,   63,  150,  117,   36,  119,   15,   41,
    1,    2,    3,  155,   38,   37,  157,   23,   28,   64,
  122,   63,   64,   29,   31,   64,   30,   64,   64,  116,
   56,   91,   84,   33,  141,   85,  142,   83,   16,   49,
   50,   35,   53,   99,   75,   41,   64,   75,   36,   42,
   75,   43,   75,   75,   25,   63,   36,   43,   84,   52,
   45,   85,   56,   83,   72,  104,  105,  106,  107,   76,
   74,   75,   76,  112,  113,   76,   75,   76,   76,   76,
   64,  104,  105,  106,  107,   77,   93,   63,   94,  118,
   97,  102,   84,  103,  125,   85,   76,   83,   19,   20,
   21,    1,    2,    3,  144,   75,  148,  149,   84,  153,
    3,   85,   64,   83,    1,    2,    3,   54,   27,   31,
   55,   56,   17,   57,   58,   59,   24,   19,   20,   21,
   76,   40,   67,   12,  127,   67,   44,   75,   67,   60,
   67,   67,   68,   69,   70,   71,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,  115,    0,   67,
    0,    0,   76,    0,    0,   68,    0,    0,   68,    0,
    0,   68,    0,   68,   68,    0,   49,   50,    0,   53,
    0,    0,   41,    0,    0,   36,   42,    0,    0,    0,
    0,    0,   68,   67,    0,    0,    0,    0,    0,   56,
    0,    0,   56,    0,    0,    0,   56,   56,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
   56,   56,   56,   56,   63,   67,   68,   63,   46,   47,
   48,   63,   63,   13,  123,   63,   63,   63,   63,   63,
   63,   63,   63,   63,   63,   63,   63,   63,   63,   64,
    0,    0,   64,    0,    0,    0,   64,   64,   68,    0,
   64,   64,   64,   64,   64,   64,   64,   64,   64,   64,
   64,   64,   64,   64,   75,    0,    0,   75,   78,   79,
   80,   81,   82,   87,    0,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,   75,   76,
  124,    0,   76,    0,   78,   79,   80,   81,   82,   87,
   76,   76,   76,   76,   76,   76,   76,   76,   76,   76,
   76,   76,   76,   76,  128,  147,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,  115,   78,   79,
   80,   81,   82,   87,   71,    0,    0,   71,    0,    0,
   71,  156,   71,   71,   78,   79,   80,   81,   82,    0,
    0,    0,   67,    0,    0,   67,    0,    0,    0,    0,
    0,   71,    0,   67,   67,   67,   67,    0,    0,   67,
   67,   67,   67,   67,   67,   67,   67,    0,    0,    0,
    0,    0,    0,   72,    0,   68,   72,    0,   68,   72,
    0,   72,   72,    0,    0,   71,   68,   68,   68,   68,
    0,    0,   68,   68,   68,   68,   68,   68,   68,   68,
   72,   73,    0,    0,   73,    0,    0,   73,    0,   73,
   73,    0,   74,    0,    0,   74,    0,   71,   74,    0,
   74,   74,    0,    0,    0,    0,    0,    0,   73,    0,
    0,    1,    2,    3,   72,    0,    0,    0,    0,   74,
    0,    0,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,   43,    0,   39,   19,   20,   21,
    0,    0,   73,    0,    0,    0,   72,    0,    0,    0,
    0,    0,    0,   74,    0,    0,    0,    0,    0,    0,
    0,  104,  105,  106,  107,  108,  109,  110,  111,  112,
  113,  114,  115,    0,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   74,    0,    0,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,
  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,
  114,  115,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   71,    0,    0,   71,    0,  104,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,    0,    0,   71,   71,   71,   71,   71,   71,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
    0,   54,    0,    0,   55,   56,   42,   57,   58,   59,
    0,    0,   51,   72,   53,    0,   72,    0,    0,    0,
    0,    0,    0,   60,    0,   73,    0,    0,    0,    0,
    0,    0,   72,   72,   72,   72,   72,   72,    0,    0,
    0,   73,    0,    0,   73,    0,    0,    0,    0,    0,
    0,    0,   74,    0,    0,   74,    0,    0,    0,    0,
   73,   73,   73,   73,   73,   73,   86,    0,    0,    0,
    0,   74,   74,   74,   74,   74,   74,    0,    0,    0,
    0,    0,   95,   96,    0,    0,   98,    0,    0,    0,
    0,  101,    0,    0,    0,    0,    0,    0,  120,  121,
    0,    0,    0,    0,    0,    0,    0,  126,    0,    0,
    0,    0,  129,  130,  131,  132,  133,  134,  135,  136,
  137,  138,  139,  140,    0,    0,    0,    0,    0,    0,
  151,    0,    0,  146,  104,  105,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  152,    0,  154,
};
static const YYINT yycheck[] = {                         32,
   93,   17,   35,   59,   59,   38,   59,   32,   41,   59,
  123,  282,   59,   59,  124,   31,   35,   40,   61,    0,
   59,   59,   40,   15,   32,    6,   59,   35,  271,  272,
   38,   61,   40,   41,  144,   87,   28,   89,   61,   31,
  257,  258,  259,  153,   58,   59,  156,  283,   61,   32,
   93,   59,   35,   59,   44,   38,   93,   40,   41,   32,
   93,   91,   35,  282,  116,   38,  118,   40,   91,  125,
  125,   41,  125,   91,   32,  125,   59,   35,  125,  125,
   38,  123,   40,   41,  100,   93,  125,  125,   35,  282,
   59,   38,  125,   40,   59,  269,  270,  271,  272,   32,
   40,   59,   35,  277,  278,   38,   40,   40,   41,   40,
   93,  269,  270,  271,  272,  282,   59,  125,  125,   32,
  282,  282,   35,  282,   61,   38,   59,   40,  283,  284,
  285,  257,  258,  259,  261,   93,   41,   61,   35,  262,
    0,   38,  125,   40,  257,  258,  259,  260,   41,   41,
  263,  264,   59,  266,  267,  268,  282,  283,  284,  285,
   93,  125,   32,    6,  100,   35,   35,  125,   38,  282,
   40,   41,   46,   47,   48,   49,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,   59,
   -1,   -1,  125,   -1,   -1,   32,   -1,   -1,   35,   -1,
   -1,   38,   -1,   40,   41,   -1,  262,  262,   -1,  262,
   -1,   -1,  262,   -1,   -1,  262,  262,   -1,   -1,   -1,
   -1,   -1,   59,   93,   -1,   -1,   -1,   -1,   -1,  262,
   -1,   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  262,  125,   93,  265,  283,  284,
  285,  269,  270,  282,   41,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  262,
   -1,   -1,  265,   -1,   -1,   -1,  269,  270,  125,   -1,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  262,   -1,   -1,  265,  281,  282,
  283,  284,  285,  286,   -1,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  262,
   41,   -1,  265,   -1,  281,  282,  283,  284,  285,  286,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,   41,   93,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,   32,   -1,   -1,   35,   -1,   -1,
   38,   41,   40,   41,  281,  282,  283,  284,  285,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,
   -1,   59,   -1,  273,  274,  275,  276,   -1,   -1,  279,
  280,  281,  282,  283,  284,  285,  286,   -1,   -1,   -1,
   -1,   -1,   -1,   32,   -1,  262,   35,   -1,  265,   38,
   -1,   40,   41,   -1,   -1,   93,  273,  274,  275,  276,
   -1,   -1,  279,  280,  281,  282,  283,  284,  285,  286,
   59,   32,   -1,   -1,   35,   -1,   -1,   38,   -1,   40,
   41,   -1,   32,   -1,   -1,   35,   -1,  125,   38,   -1,
   40,   41,   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,  257,  258,  259,   93,   -1,   -1,   -1,   -1,   59,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  123,   -1,  282,  283,  284,  285,
   -1,   -1,   93,   -1,   -1,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,   -1,   -1,  265,   -1,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,   -1,  281,  282,  283,  284,  285,  286,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   26,
   -1,  260,   -1,   -1,  263,  264,   33,  266,  267,  268,
   -1,   -1,   39,  262,   41,   -1,  265,   -1,   -1,   -1,
   -1,   -1,   -1,  282,   -1,   52,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  285,  286,   -1,   -1,
   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  285,  286,   58,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  285,  286,   -1,   -1,   -1,
   -1,   -1,   74,   75,   -1,   -1,   78,   -1,   -1,   -1,
   -1,   83,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   99,   -1,   -1,
   -1,   -1,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,   -1,   -1,   -1,   -1,   -1,   -1,
  265,   -1,   -1,  125,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  149,   -1,  151,
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
"exp : LIT_REAL",
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
#line 194 "parser.y"

//#include "main.c"

int getLineNumber();

void yyerror(char *erro){
	fprintf(stderr, "line: %d - Syntax error!\n", getLineNumber());
	stringError();
	exit(3);
}
#line 514 "y.tab.c"

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
#line 70 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;
astPrint(yyval.ast,0);
if (set_declarations(yyval.ast) || check_use(yyval.ast) || check_op(yyval.ast))
	exit(4);
TAC* root = codeGenerator(yyval.ast);
tacPrintBack(root);
}
break;
case 2:
#line 79 "parser.y"
	{yyval.ast = astCreate(AST_DECLIST,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 3:
#line 80 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 4:
#line 83 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 5:
#line 84 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 6:
#line 85 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 7:
#line 86 "parser.y"
	{yyval.ast = astCreate(AST_DEC,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 8:
#line 89 "parser.y"
	{yyval.ast = astCreate(AST_DECVAR,yystack.l_mark[-3].symbol,yystack.l_mark[-4].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 9:
#line 92 "parser.y"
	{yyval.ast = astCreate(AST_DECVEC_A,yystack.l_mark[-6].symbol,yystack.l_mark[-7].ast,astCreate(AST_VEC_SIZE, yystack.l_mark[-4].symbol, 0, 0, 0, 0),yystack.l_mark[-1].ast,0);}
break;
case 10:
#line 93 "parser.y"
	{yyval.ast = astCreate(AST_DECVEC_B,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,astCreate(AST_VEC_SIZE,yystack.l_mark[-2].symbol,0,0,0,0),0,0);}
break;
case 11:
#line 96 "parser.y"
	{yyval.ast = astCreate(AST_DECFUNC,yystack.l_mark[-4].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 12:
#line 98 "parser.y"
	{yyval.ast = astCreate(AST_DECPOINT,yystack.l_mark[-3].symbol,yystack.l_mark[-5].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 13:
#line 100 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 14:
#line 101 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 15:
#line 102 "parser.y"
	{yyval.ast = astCreate(AST_DECV_A,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 16:
#line 103 "parser.y"
	{yyval.ast = astCreate(AST_DECV_B,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 17:
#line 104 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 18:
#line 107 "parser.y"
	{yyval.ast = astCreate(AST_KW_CHAR,0,0,0,0,0);}
break;
case 19:
#line 108 "parser.y"
	{yyval.ast = astCreate(AST_KW_INT,0,0,0,0,0);}
break;
case 20:
#line 109 "parser.y"
	{yyval.ast = astCreate(AST_KW_FLOAT,0,0,0,0,0);}
break;
case 21:
#line 112 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 22:
#line 113 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 23:
#line 114 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 24:
#line 117 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_A,yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 25:
#line 118 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 26:
#line 119 "parser.y"
	{yyval.ast = astCreate(AST_PARAMLIST_C,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 27:
#line 120 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 28:
#line 123 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_A,yystack.l_mark[-1].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 29:
#line 124 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 30:
#line 125 "parser.y"
	{yyval.ast = astCreate(AST_PARAM_C,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 31:
#line 126 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 32:
#line 130 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 33:
#line 131 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 34:
#line 132 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 35:
#line 133 "parser.y"
	{yyval.ast = astCreate(AST_CMD,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 36:
#line 134 "parser.y"
	{yyval.ast = astCreate(AST_EMPTY,0,0,0,0,0);}
break;
case 37:
#line 137 "parser.y"
	{yyval.ast = astCreate(AST_BODY,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 38:
#line 140 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_A,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 39:
#line 141 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_B,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 40:
#line 142 "parser.y"
	{yyval.ast = astCreate(AST_LISTCMD_C,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 41:
#line 145 "parser.y"
	{yyval.ast = astCreate(AST_ATTRIB_A,yystack.l_mark[-2].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 42:
#line 146 "parser.y"
	{yyval.ast = astCreate(AST_ATTRIB_B,yystack.l_mark[-5].symbol,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 43:
#line 149 "parser.y"
	{yyval.ast = astCreate(AST_IF,0,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0,0);}
break;
case 44:
#line 150 "parser.y"
	{yyval.ast = astCreate(AST_IFELSE,0,yystack.l_mark[-5].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 45:
#line 151 "parser.y"
	{yyval.ast = astCreate(AST_WHILE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 46:
#line 152 "parser.y"
	{yyval.ast = astCreate(AST_FOR,yystack.l_mark[-6].symbol,yystack.l_mark[-4].ast,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0);}
break;
case 47:
#line 155 "parser.y"
	{yyval.ast = astCreate(AST_INOUT,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 48:
#line 156 "parser.y"
	{yyval.ast = astCreate(AST_READ,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 49:
#line 157 "parser.y"
	{yyval.ast = astCreate(AST_RETURN,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 50:
#line 160 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_A,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 51:
#line 161 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_B,yystack.l_mark[-1].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 52:
#line 162 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_C,yystack.l_mark[-2].symbol,yystack.l_mark[0].ast,0,0,0);}
break;
case 53:
#line 163 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_D,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 54:
#line 164 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_E,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0);}
break;
case 55:
#line 165 "parser.y"
	{yyval.ast = astCreate(AST_PRINT_F,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 56:
#line 168 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_A,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 57:
#line 169 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_B,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0);}
break;
case 58:
#line 170 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_C,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 59:
#line 171 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_D,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 60:
#line 172 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 61:
#line 173 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 62:
#line 174 "parser.y"
	{yyval.ast = astCreate(AST_SYMBOL_LIT,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 63:
#line 175 "parser.y"
	{yyval.ast = astCreate(AST_OP_PLUS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 64:
#line 176 "parser.y"
	{yyval.ast = astCreate(AST_OP_MINUS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 65:
#line 177 "parser.y"
	{yyval.ast = astCreate(AST_OP_MULT,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 66:
#line 178 "parser.y"
	{yyval.ast = astCreate(AST_OP_DIV,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 67:
#line 179 "parser.y"
	{yyval.ast = astCreate(AST_OP_L,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 68:
#line 180 "parser.y"
	{yyval.ast = astCreate(AST_OP_G,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 69:
#line 181 "parser.y"
	{yyval.ast = astCreate(AST_OP_NEG,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 70:
#line 182 "parser.y"
	{yyval.ast = astCreate(AST_EXP,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 71:
#line 183 "parser.y"
	{yyval.ast = astCreate(AST_OP_LE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 72:
#line 184 "parser.y"
	{yyval.ast = astCreate(AST_OP_GE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 73:
#line 185 "parser.y"
	{yyval.ast = astCreate(AST_OP_EQ,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 74:
#line 186 "parser.y"
	{yyval.ast = astCreate(AST_OP_NE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 75:
#line 187 "parser.y"
	{yyval.ast = astCreate(AST_OP_AND,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 76:
#line 188 "parser.y"
	{yyval.ast = astCreate(AST_OP_OR,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 77:
#line 189 "parser.y"
	{yyval.ast = astCreate(AST_FUNCCALL,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0);}
break;
#line 1030 "y.tab.c"
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
