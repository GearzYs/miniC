/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220128

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "miniC.y"
#include <stdio.h> 
#include <stdlib.h>
#include "parsingMini.h"

extern int chars;

void yyerror (char *s);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 11 "miniC.y"
typedef union YYSTYPE{
	int val;
	char* id;
	noeud *noeud;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

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

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define VOID 257
#define INT 258
#define PLUS 259
#define MOINS 260
#define MUL 261
#define DIV 262
#define LSHIFT 263
#define RSHIFT 264
#define BAND 265
#define BOR 266
#define LAND 267
#define LOR 268
#define LT 269
#define GT 270
#define GEQ 271
#define LEQ 272
#define EQ 273
#define NEQ 274
#define THEN 275
#define ELSE 276
#define OP 277
#define REL 278
#define WHILE 279
#define FOR 280
#define IF 281
#define NOT 282
#define IDENTIFICATEUR 283
#define CONSTANTE 284
#define BREAK 285
#define RETURN 286
#define DEFAULT 287
#define CASE 288
#define SWITCH 289
#define EXTERN 290
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   14,   14,   16,   16,   17,   18,   18,   19,   19,
   15,   15,   21,   21,   23,   23,   23,   24,   11,   11,
    8,    8,    8,    8,    8,    8,    7,    7,    7,    5,
    5,    5,    5,    5,    6,    6,    6,   12,    9,   10,
   22,   22,   13,   13,   13,   13,   13,   13,   20,   20,
   20,    4,    4,    4,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    2,    2,    2,    2,    2,
    2,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    2,    1,    3,    3,    1,    1,    4,
    9,    7,    1,    1,    3,    1,    0,    2,    2,    0,
    1,    1,    1,    2,    1,    1,    9,    5,    2,    5,
    7,    5,    4,    3,    2,    2,    3,    3,    4,    5,
    1,    4,    3,    3,    2,    1,    1,    4,    3,    1,
    0,    4,    3,    3,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   13,   14,    0,    5,    0,    2,    0,    0,
    4,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,    0,    0,   16,    9,    0,    0,    0,   18,
    0,    0,   10,    0,   15,    3,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,   11,   22,   23,   21,   19,   25,   26,    0,    0,
   29,    0,    0,    0,    0,   35,    0,    0,   46,   36,
    0,    0,    0,    0,    0,    0,    0,   24,    0,    0,
    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,
    0,    0,   56,   57,   58,   59,   60,   61,   62,   63,
   37,    0,   34,    0,    0,    0,    0,    0,    0,    0,
    0,   64,   65,    0,    0,   66,   67,   68,   69,   70,
   71,    0,    0,    0,    0,    0,    0,   43,   44,   33,
    0,   39,   42,    0,   54,   28,   53,    0,    0,    0,
    0,   40,   48,   32,   52,    0,    0,    0,   31,    0,
   27,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  292,  306,  257,  258,  290,  307,  308,  309,  313,  313,
  307,  313,  283,  310,  311,  283,  283,   40,   59,   44,
   91,   40,  258,  315,  316,  283,  311,  284,  315,  283,
   44,   41,   93,   41,  316,  123,   59,  306,  303,  313,
  256,  279,  280,  281,  283,  285,  286,  287,  288,  289,
  123,  125,  297,  298,  299,  300,  301,  302,  304,  314,
   10,   40,   40,   40,   40,   59,  260,  283,  284,   59,
   40,  305,  314,   58,  284,   40,  306,   59,   91,   61,
  282,   40,  296,  305,  283,  304,  296,  305,  312,  305,
   40,  305,  259,  260,  261,  262,  263,  264,  265,  266,
   59,  295,  300,   58,  305,  303,  305,  305,   40,  296,
  305,  267,  268,   41,  293,  269,  270,  271,  272,  273,
  274,  294,   59,   41,   44,   41,  312,   41,  305,  300,
   41,  125,   93,  296,   41,  300,  296,  305,  296,  300,
  305,   59,   41,  300,   41,   59,  276,  304,  300,   41,
  300,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
  115,  122,  102,   83,   53,   54,   55,   56,   57,   58,
   39,   59,   84,    2,    6,    7,    8,   14,   15,   89,
   40,   73,   24,   25,
};
static const YYINT yysindex[] = {                         0,
    0, -251,    0,    0, -204,    0, -251,    0, -259, -255,
    0, -253,   -4,  -21,  -50,    9,   -4, -211,    0, -228,
 -221, -211, -214,  -27,    0,    0,  -50,  -20,  -26,    0,
 -211,  -44,    0,   37,    0,    0,    0, -204, -103, -228,
   82,   48,   61,   65,   85,   51,  -40,   64, -177,   87,
    0,    0,    0,    0,    0,    0,    0,    0,   69,  -48,
    0,  -37, -154,  -37,  -35,    0,  -35,   90,    0,    0,
  -35,  -47,   40,  119,   76,  -35, -204,    0,  -35,  -35,
   93,  -37,   25,   66,    0,   77,   27, -118,   45,   56,
  -35,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -35,    0,  119,   50,  -92,  -91, -118,  -37,   29,
    7,    0,    0,  119,  -37,    0,    0,    0,    0,    0,
    0,  -35,  -37,  119,  -35,   80,   49,    0,    0,    0,
  119,    0,    0,   31,    0,    0,    0, -118,  -58, -139,
 -118,    0,    0,    0,    0, -154,  119,   97,    0,  119,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  149,    0,    0,    0,
    0,    0,  -15,    0,  -19,    0,    0,   62,    0,    0,
    0,   62,    0,    0,    0,    0,   -7,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,  -45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,    0,    0,  -33,    0,    0,
    0,    0,   -9,    0,    0,    0,   67,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   75,    0,   15,
   70,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -32,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    0,   78,
   79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   17,    0,    0,    0,  -53,    0,    0,
   73,  -59,   33,    6,  144,    0,    0,    0,  132,   63,
   60,  -29,  134,  126,
};
#define YYTABLESIZE 408
static const YYINT yytable[] = {                         71,
  146,  133,   82,   86,   71,    3,    4,   41,   38,   60,
   41,  101,   80,   32,   34,   41,   31,   31,   70,   51,
  103,   52,   20,   13,    8,   41,   38,   16,    9,   17,
   51,   47,  132,   60,   47,   18,    7,   19,    5,    8,
   21,   38,   79,    9,   60,   41,   23,  128,   22,   47,
  130,    7,    3,    4,   26,   45,   77,   41,   45,   41,
  136,    9,   28,   55,   10,  114,   12,  124,   30,  135,
  140,  145,   33,   45,   60,    9,   60,  144,   36,   72,
   87,   55,  128,   47,   60,  126,  148,   62,  125,  143,
  131,   61,  125,  149,   60,   37,  151,   88,  110,   90,
   63,   60,   17,   92,   64,   17,   75,   45,  105,   66,
   51,  107,  108,   51,  111,   50,   60,   60,   50,   49,
   60,   74,   49,   88,   65,  134,   76,   78,   85,   91,
   79,  137,  109,  104,  129,  123,  147,  150,  142,  139,
   93,   94,   95,   96,   97,   98,   99,  100,    1,  106,
   11,   27,   41,  127,  138,   29,   35,  141,    0,    0,
    0,    0,    0,   41,    0,    0,    0,   93,   94,   95,
   96,   97,   98,   99,  100,   42,   43,   44,    0,   45,
    0,   46,   47,   48,   49,   50,   42,   43,   44,   20,
   45,   20,   46,   47,   48,   49,   50,    0,    0,    0,
   30,    0,   30,    0,    0,    0,    0,    0,  112,  113,
    0,   93,   94,   95,   96,   97,   98,   99,  100,   67,
    0,    0,   67,    0,   67,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   51,   68,   69,   81,   68,   69,   68,   69,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   93,   94,   95,   96,   97,
   98,   99,  100,   45,   45,  116,  117,  118,  119,  120,
  121,   45,   45,   45,   45,   45,   45,   45,   45,   55,
   55,  112,  113,  112,  113,  112,  113,  112,  113,    0,
   93,   94,   95,   96,   97,   98,   99,  100,   93,   94,
   95,   96,   97,   98,   99,  100,   95,   96,   97,   98,
   99,  100,   20,    0,   93,   94,   95,   96,   97,   98,
   99,  100,    0,   30,  116,  117,  118,  119,  120,  121,
    0,    0,    0,    0,    0,   20,   20,   20,    0,   20,
    0,   20,   20,   20,   20,   20,   30,   30,   30,    0,
   30,    0,   30,   30,   30,   30,   30,    0,    0,    0,
    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   43,   44,
    0,   45,    0,   46,   47,   48,   49,   50,
};
static const YYINT yycheck[] = {                         40,
   59,   93,   40,   63,   40,  257,  258,   41,   41,   39,
   44,   59,   61,   41,   41,   61,   44,   44,   59,  123,
   74,  125,   44,  283,   44,   59,   59,  283,   44,  283,
  123,   41,  125,   63,   44,   40,   44,   59,  290,   59,
   91,   36,   91,   59,   74,   91,  258,   41,   40,   59,
  104,   59,  257,  258,  283,   41,   51,   91,   44,   93,
  114,    2,  284,   41,    5,   41,    7,   41,  283,   41,
  124,   41,   93,   59,  104,   91,  106,  131,  123,   47,
   64,   59,   41,   93,  114,   41,  146,   40,   44,   41,
   41,   10,   44,  147,  124,   59,  150,   65,   82,   67,
   40,  131,   41,   71,   40,   44,  284,   93,   76,   59,
   41,   79,   80,   44,   82,   41,  146,  147,   44,   41,
  150,   58,   44,   91,   40,  109,   40,   59,  283,   40,
   91,  115,   40,   58,  102,   59,  276,   41,   59,  123,
  259,  260,  261,  262,  263,  264,  265,  266,    0,   77,
    7,   20,  256,   91,  122,   22,   31,  125,   -1,   -1,
   -1,   -1,   -1,  256,   -1,   -1,   -1,  259,  260,  261,
  262,  263,  264,  265,  266,  279,  280,  281,   -1,  283,
   -1,  285,  286,  287,  288,  289,  279,  280,  281,  123,
  283,  125,  285,  286,  287,  288,  289,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,  267,  268,
   -1,  259,  260,  261,  262,  263,  264,  265,  266,  260,
   -1,   -1,  260,   -1,  260,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  123,  283,  284,  282,  283,  284,  283,  284,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  259,  260,  261,  262,  263,
  264,  265,  266,  259,  260,  269,  270,  271,  272,  273,
  274,  267,  268,  269,  270,  271,  272,  273,  274,  267,
  268,  267,  268,  267,  268,  267,  268,  267,  268,   -1,
  259,  260,  261,  262,  263,  264,  265,  266,  259,  260,
  261,  262,  263,  264,  265,  266,  261,  262,  263,  264,
  265,  266,  256,   -1,  259,  260,  261,  262,  263,  264,
  265,  266,   -1,  256,  269,  270,  271,  272,  273,  274,
   -1,   -1,   -1,   -1,   -1,  279,  280,  281,   -1,  283,
   -1,  285,  286,  287,  288,  289,  279,  280,  281,   -1,
  283,   -1,  285,  286,  287,  288,  289,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  279,  280,  281,
   -1,  283,   -1,  285,  286,  287,  288,  289,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 317
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"error","VOID","INT","PLUS","MOINS","MUL","DIV","LSHIFT","RSHIFT","BAND",
"BOR","LAND","LOR","LT","GT","GEQ","LEQ","EQ","NEQ","THEN","ELSE","OP","REL",
"WHILE","FOR","IF","NOT","IDENTIFICATEUR","CONSTANTE","BREAK","RETURN",
"DEFAULT","CASE","SWITCH","EXTERN","$accept","programme","binary_rel",
"binary_comp","binary_op","condition","selection","saut","iteration",
"instruction","bloc","appel","liste_instructions","affectation","expression",
"liste_declarations","fonction","liste_fonctions","declaration",
"liste_declarateurs","declarateur","liste_expressions","type","variable",
"liste_parms","parm","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programme",
"programme : liste_declarations liste_fonctions",
"liste_declarations : liste_declarations declaration",
"liste_declarations :",
"liste_fonctions : liste_fonctions fonction",
"liste_fonctions : fonction",
"declaration : type liste_declarateurs ';'",
"liste_declarateurs : liste_declarateurs ',' declarateur",
"liste_declarateurs : declarateur",
"declarateur : IDENTIFICATEUR",
"declarateur : declarateur '[' CONSTANTE ']'",
"fonction : type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}'",
"fonction : EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'",
"type : VOID",
"type : INT",
"liste_parms : liste_parms ',' parm",
"liste_parms : parm",
"liste_parms :",
"parm : INT IDENTIFICATEUR",
"liste_instructions : liste_instructions instruction",
"liste_instructions :",
"instruction : iteration",
"instruction : selection",
"instruction : saut",
"instruction : affectation ';'",
"instruction : bloc",
"instruction : appel",
"iteration : FOR '(' affectation ';' condition ';' affectation ')' instruction",
"iteration : WHILE '(' condition ')' instruction",
"iteration : error '\\n'",
"selection : IF '(' condition ')' instruction",
"selection : IF '(' condition ')' instruction ELSE instruction",
"selection : SWITCH '(' expression ')' instruction",
"selection : CASE CONSTANTE ':' instruction",
"selection : DEFAULT ':' instruction",
"saut : BREAK ';'",
"saut : RETURN ';'",
"saut : RETURN expression ';'",
"affectation : variable '=' expression",
"bloc : '{' liste_declarations liste_instructions '}'",
"appel : IDENTIFICATEUR '(' liste_expressions ')' ';'",
"variable : IDENTIFICATEUR",
"variable : variable '[' expression ']'",
"expression : '(' expression ')'",
"expression : expression binary_op expression",
"expression : MOINS expression",
"expression : CONSTANTE",
"expression : variable",
"expression : IDENTIFICATEUR '(' liste_expressions ')'",
"liste_expressions : liste_expressions ',' expression",
"liste_expressions : expression",
"liste_expressions :",
"condition : NOT '(' condition ')'",
"condition : condition binary_rel condition",
"condition : '(' condition ')'",
"condition : expression binary_comp expression",
"binary_op : PLUS",
"binary_op : MOINS",
"binary_op : MUL",
"binary_op : DIV",
"binary_op : LSHIFT",
"binary_op : RSHIFT",
"binary_op : BAND",
"binary_op : BOR",
"binary_rel : LAND",
"binary_rel : LOR",
"binary_comp : LT",
"binary_comp : GT",
"binary_comp : GEQ",
"binary_comp : LEQ",
"binary_comp : EQ",
"binary_comp : NEQ",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

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

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 204 "miniC.y"

extern int yylineno;

void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	clearFile();
	startFile();
	while(yyparse());
	endFile();
}
#line 624 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

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

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 38 "miniC.y"
	{afficherArbre(yystack.l_mark[-1].noeud);}
#line 1297 "y.tab.c"
break;
case 2:
#line 41 "miniC.y"
	{yyval.noeud=creerNoeud("LISTE_DECLARATIONS",1);
											yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1303 "y.tab.c"
break;
case 3:
#line 43 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_DECLARATIONS",0);}
#line 1308 "y.tab.c"
break;
case 4:
#line 46 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_FONCTIONS",0);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-1].noeud,yystack.l_mark[0].noeud);}
#line 1314 "y.tab.c"
break;
case 5:
#line 48 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_FONCTIONS",0);
										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1320 "y.tab.c"
break;
case 6:
#line 52 "miniC.y"
	{yyval.noeud= creerNoeud("DECLARATION",1);
										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1326 "y.tab.c"
break;
case 7:
#line 56 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_DECLARATEURS",0);
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1332 "y.tab.c"
break;
case 8:
#line 58 "miniC.y"
	{yyval.noeud = creerNoeud("LISTE_DECLARATEURS",0);
					yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1338 "y.tab.c"
break;
case 9:
#line 62 "miniC.y"
	{ yyval.noeud = creerNoeud(yystack.l_mark[0].id,0);}
#line 1343 "y.tab.c"
break;
case 10:
#line 63 "miniC.y"
	{yyval.noeud= creerNoeud("[]",2);
										noeud* constante = creerNoeud(yystack.l_mark[-1].id,0);
										yyval.noeud = appendChild1(yyval.noeud,constante);}
#line 1350 "y.tab.c"
break;
case 11:
#line 68 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-7].id,3);
																								yyval.noeud->type = FONCTION;
																								yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-8].noeud,yystack.l_mark[-5].noeud,yystack.l_mark[-2].noeud);
																								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1358 "y.tab.c"
break;
case 12:
#line 72 "miniC.y"
	{yyval.noeud= creerNoeud("EXTERN",1);
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-5].noeud);}
#line 1364 "y.tab.c"
break;
case 13:
#line 76 "miniC.y"
	{yyval.noeud = creerNoeud("void",0);}
#line 1369 "y.tab.c"
break;
case 14:
#line 77 "miniC.y"
	{yyval.noeud = creerNoeud("int",0);}
#line 1374 "y.tab.c"
break;
case 15:
#line 81 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_PARMS",2);
								yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1380 "y.tab.c"
break;
case 16:
#line 83 "miniC.y"
	{yyval.noeud= yystack.l_mark[0].noeud;}
#line 1385 "y.tab.c"
break;
case 17:
#line 84 "miniC.y"
	{yyval.noeud= creerNoeud("PARAM VIDE",0);}
#line 1390 "y.tab.c"
break;
case 18:
#line 88 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id,0);}
#line 1395 "y.tab.c"
break;
case 19:
#line 92 "miniC.y"
	{yyval.noeud=yystack.l_mark[-1].noeud;afficherArbre(yystack.l_mark[0].noeud);}
#line 1400 "y.tab.c"
break;
case 20:
#line 93 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_INSTRUCTIONS",0);}
#line 1405 "y.tab.c"
break;
case 21:
#line 96 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1410 "y.tab.c"
break;
case 22:
#line 97 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1415 "y.tab.c"
break;
case 23:
#line 98 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1420 "y.tab.c"
break;
case 24:
#line 99 "miniC.y"
	{yyval.noeud=yystack.l_mark[-1].noeud;}
#line 1425 "y.tab.c"
break;
case 25:
#line 100 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1430 "y.tab.c"
break;
case 26:
#line 101 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1435 "y.tab.c"
break;
case 27:
#line 104 "miniC.y"
	{yyval.noeud= creerNoeud("for",4);
																			yyval.noeud = appendChild4(yyval.noeud,yystack.l_mark[-6].noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1441 "y.tab.c"
break;
case 28:
#line 106 "miniC.y"
	{yyval.noeud= creerNoeud("while",2);
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1447 "y.tab.c"
break;
case 29:
#line 108 "miniC.y"
	{yyerror("reenter last");
                        yyerrok; }
#line 1453 "y.tab.c"
break;
case 30:
#line 112 "miniC.y"
	{yyval.noeud= creerNoeud("if",2);
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1459 "y.tab.c"
break;
case 31:
#line 114 "miniC.y"
	{yyval.noeud= creerNoeud("if",3);
															yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1465 "y.tab.c"
break;
case 32:
#line 116 "miniC.y"
	{yyval.noeud= creerNoeud("switch",2);
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1471 "y.tab.c"
break;
case 33:
#line 118 "miniC.y"
	{yyval.noeud= creerNoeud("case",2);
										noeud* constante = creerNoeud(yystack.l_mark[-2].id,0);
										yyval.noeud = appendChild2(yyval.noeud,constante,yystack.l_mark[0].noeud);}
#line 1478 "y.tab.c"
break;
case 34:
#line 121 "miniC.y"
	{yyval.noeud= creerNoeud("default",1);
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1484 "y.tab.c"
break;
case 35:
#line 125 "miniC.y"
	{yyval.noeud= creerNoeud("break",0); }
#line 1489 "y.tab.c"
break;
case 36:
#line 126 "miniC.y"
	{yyval.noeud= creerNoeud("return",0);}
#line 1494 "y.tab.c"
break;
case 37:
#line 127 "miniC.y"
	{yyval.noeud= creerNoeud("return",1);
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1500 "y.tab.c"
break;
case 38:
#line 131 "miniC.y"
	{yyval.noeud = creerNoeud(":=",2);
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1506 "y.tab.c"
break;
case 39:
#line 135 "miniC.y"
	{yyval.noeud= creerNoeud("BLOC",2);
														yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[-1].noeud);}
#line 1512 "y.tab.c"
break;
case 40:
#line 139 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-4].id,0);
														yyval.noeud->type = APPELFONCTION;}
#line 1518 "y.tab.c"
break;
case 41:
#line 143 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id,0);}
#line 1523 "y.tab.c"
break;
case 42:
#line 144 "miniC.y"
	{yyval.noeud = creerNoeud("[]",2);
									yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1529 "y.tab.c"
break;
case 43:
#line 148 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1534 "y.tab.c"
break;
case 44:
#line 149 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-1].id,2);
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1540 "y.tab.c"
break;
case 45:
#line 151 "miniC.y"
	{yyval.noeud = creerNoeud("MOINS",1);
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1546 "y.tab.c"
break;
case 46:
#line 153 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[0].id,0);}
#line 1551 "y.tab.c"
break;
case 47:
#line 154 "miniC.y"
	{yyval.noeud = yystack.l_mark[0].noeud;}
#line 1556 "y.tab.c"
break;
case 48:
#line 155 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[-3].id,0);
													yyval.noeud->type = APPELFONCTION;
													yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1563 "y.tab.c"
break;
case 49:
#line 161 "miniC.y"
	{yyval.noeud= creerNoeud("LISTE_EXPRESSIONS",0);
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1569 "y.tab.c"
break;
case 50:
#line 163 "miniC.y"
	{yyval.noeud= yystack.l_mark[0].noeud;}
#line 1574 "y.tab.c"
break;
case 51:
#line 164 "miniC.y"
	{yyval.noeud= creerNoeud(" ",0);}
#line 1579 "y.tab.c"
break;
case 52:
#line 168 "miniC.y"
	{yyval.noeud = creerNoeud("NOT",1);
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1585 "y.tab.c"
break;
case 53:
#line 170 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id,2);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1593 "y.tab.c"
break;
case 54:
#line 174 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1598 "y.tab.c"
break;
case 55:
#line 175 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id,2);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1606 "y.tab.c"
break;
case 56:
#line 181 "miniC.y"
	{yyval.id = "+"; }
#line 1611 "y.tab.c"
break;
case 57:
#line 182 "miniC.y"
	{yyval.id = "-"; }
#line 1616 "y.tab.c"
break;
case 58:
#line 183 "miniC.y"
	{yyval.id = "*"; }
#line 1621 "y.tab.c"
break;
case 59:
#line 184 "miniC.y"
	{yyval.id = "/"; }
#line 1626 "y.tab.c"
break;
case 60:
#line 185 "miniC.y"
	{yyval.id = "<<"; }
#line 1631 "y.tab.c"
break;
case 61:
#line 186 "miniC.y"
	{yyval.id = ">>"; }
#line 1636 "y.tab.c"
break;
case 62:
#line 187 "miniC.y"
	{yyval.id = "&="; }
#line 1641 "y.tab.c"
break;
case 63:
#line 188 "miniC.y"
	{yyval.id = "|="; }
#line 1646 "y.tab.c"
break;
case 64:
#line 191 "miniC.y"
	{yyval.id = "&&"; }
#line 1651 "y.tab.c"
break;
case 65:
#line 192 "miniC.y"
	{yyval.id = "||"; }
#line 1656 "y.tab.c"
break;
case 66:
#line 195 "miniC.y"
	{yyval.id = "<"; }
#line 1661 "y.tab.c"
break;
case 67:
#line 196 "miniC.y"
	{yyval.id = ">"; }
#line 1666 "y.tab.c"
break;
case 68:
#line 197 "miniC.y"
	{yyval.id = ">="; }
#line 1671 "y.tab.c"
break;
case 69:
#line 198 "miniC.y"
	{yyval.id = "<="; }
#line 1676 "y.tab.c"
break;
case 70:
#line 199 "miniC.y"
	{yyval.id = "=="; }
#line 1681 "y.tab.c"
break;
case 71:
#line 200 "miniC.y"
	{yyval.id = "!="; }
#line 1686 "y.tab.c"
break;
#line 1688 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
