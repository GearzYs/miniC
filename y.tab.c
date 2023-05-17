/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

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
#include <string.h>
#include <stdbool.h>

extern int chars;

void yyerror (char *s);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "miniC.y"
typedef union YYSTYPE{
	int val;
	char* id;
	noeud *noeud;
	liste_chaine_noeud* liste;
	NoeudType* typeu;
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
    0,   21,   21,   20,   20,   23,   19,   19,   24,   24,
   18,   18,   22,   22,   17,   17,   17,    8,   16,   16,
   14,   14,   14,   14,   14,   14,   13,   13,   13,   12,
   12,   12,   12,   12,   11,   11,   11,    6,   10,    9,
    5,    5,    4,    4,    4,    4,    4,    4,   15,   15,
   15,    7,    7,    7,    7,    3,    3,    3,    3,    3,
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
    0,    0,   13,   14,    0,    5,    0,    0,    2,    0,
    4,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,    0,   16,    0,    9,    0,    0,    0,   18,
    0,    0,   10,    0,   15,    3,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,   11,    0,    0,   26,   25,   23,   22,   21,   19,
   29,    0,    0,    0,    0,   35,    0,    0,   46,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,
    0,    0,   56,   57,   58,   59,   60,   61,   62,   63,
   37,    0,   34,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   67,   68,   69,   70,   71,    0,   64,   65,
    0,    0,    0,    0,    0,    0,    0,   43,   44,   33,
    0,   39,   42,    0,   54,    0,   28,   53,    0,    0,
    0,   40,   48,   32,   52,    0,    0,    0,   31,    0,
   27,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  292,  313,  257,  258,  290,  310,  312,  314,  315,  314,
  310,  314,  283,  311,  316,  283,  283,   40,   59,   44,
   91,   40,  258,  300,  309,  283,  316,  284,  309,  283,
   44,   41,   93,   41,  300,  123,   59,  313,  308,  314,
  256,  279,  280,  281,  283,  285,  286,  287,  288,  289,
  123,  125,  297,  298,  301,  302,  303,  304,  305,  306,
   10,   40,   40,   40,   40,   59,  260,  283,  284,   59,
   40,  296,  297,   58,  284,   40,  313,   91,   61,   59,
  282,   40,  296,  299,  283,  298,  299,  296,  307,  296,
   40,  296,  259,  260,  261,  262,  263,  264,  265,  266,
   59,  295,  306,   58,  296,  308,  296,  296,   40,  296,
  299,  269,  270,  271,  272,  273,  274,  294,  267,  268,
   41,  293,   59,   41,   44,   41,  307,   41,  296,  306,
   41,  125,   93,  299,   41,  296,  306,  299,  299,  306,
  296,   59,   41,  306,   41,   59,  276,  298,  306,   41,
  306,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
  122,  118,  102,   83,   73,   54,   84,   24,   55,   56,
   57,   58,   59,   60,   89,   39,   25,    6,   14,    7,
    2,   40,    9,   15,
};
static const YYINT yysindex[] = {                         0,
    0, -243,    0,    0, -241,    0, -243, -253,    0, -242,
    0, -240,    2,  -31,  -36,   11,    2, -201,    0, -222,
 -221, -201, -216,    0,  -17,    0,  -36,  -24,   21,    0,
 -201,  -50,    0,   12,    0,    0,    0, -241, -103, -222,
   68,   39,   61,   65,   74,   48,  -40,   32, -178,   76,
    0,    0,  -54,   77,    0,    0,    0,    0,    0,    0,
    0,  -37, -158,  -37,  -35,    0,  -35,   97,    0,    0,
  -35,  -47,   57,  119,   80,  -35, -241,  -35,  -35,    0,
  109,  -37,   66,   25,    0,   93,   27, -132,   44, -120,
  -35,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -35,    0,  119,   50,  -92,  -91, -132,  -37,    7,
   29,    0,    0,    0,    0,    0,    0,  -35,    0,    0,
  119,  -37,  -37,  119,  -35,   95,   45,    0,    0,    0,
  119,    0,    0,   31,    0, -132,    0,    0,  -58, -121,
 -132,    0,    0,    0,    0, -158,  119,  115,    0,  119,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  157,    0,    0,    0,
    0,    0,  -38,    0,  -21,    0,    0,   53,    0,    0,
    0,   53,    0,    0,    0,    0,  -19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   67,    0,    0,
    0,    0,    0,    0,  -52,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   69,    0,    0,  -33,    0,    0,
    0,    0,   -9,    0,    0,    0,   67,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,    0,   15,
   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,    0,    0,   78,
  106,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,   33,  -29,  -59,   17,  128,    0,    0,
    0,    0,    0,  -28,   70,   83,  140,  156,    0,    0,
   -7,   47,    0,  145,
};
#define YYTABLESIZE 408
static const YYINT yytable[] = {                         71,
  146,  133,   82,   86,   71,    9,   79,   41,   41,   53,
   41,  101,   20,    3,    4,    3,    4,   38,   70,   51,
    9,   52,    8,   32,    7,   41,   31,   19,   38,   13,
   51,   47,  132,   53,   47,   38,   78,    8,   41,    7,
   16,   18,   17,   77,   53,  103,    5,  128,    8,   47,
   22,   10,    9,   12,   21,   45,   23,   41,   45,   41,
   26,   34,   28,   55,   31,  121,   30,  124,   33,  135,
   37,  145,   36,   45,   53,  130,   53,   61,   62,   72,
   87,   55,  128,   47,  126,  143,  148,  125,  125,   74,
  131,   53,  137,   17,   53,  140,   17,   88,  111,   90,
   63,   53,  144,   92,   64,   75,   66,   45,  105,   51,
  107,  108,   51,   65,  110,   76,   53,   53,  149,   50,
   53,  151,   50,   88,   85,  134,   93,   94,   95,   96,
   97,   98,   99,  100,  129,   80,   91,  104,  138,  139,
   95,   96,   97,   98,   99,  100,   49,   78,  109,   49,
  136,  123,   41,  142,  147,  150,    1,  141,   35,  106,
  127,   29,   11,   41,   27,    0,    0,   93,   94,   95,
   96,   97,   98,   99,  100,   42,   43,   44,    0,   45,
    0,   46,   47,   48,   49,   50,   42,   43,   44,   20,
   45,   20,   46,   47,   48,   49,   50,    0,    0,    0,
   30,    0,   30,    0,    0,    0,    0,    0,  119,  120,
    0,   93,   94,   95,   96,   97,   98,   99,  100,   67,
    0,    0,   67,    0,   67,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   51,   68,   69,   81,   68,   69,   68,   69,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   93,   94,   95,   96,   97,
   98,   99,  100,   45,   45,  112,  113,  114,  115,  116,
  117,   45,   45,   45,   45,   45,   45,   45,   45,   55,
   55,  119,  120,  119,  120,  119,  120,  119,  120,    0,
   93,   94,   95,   96,   97,   98,   99,  100,   93,   94,
   95,   96,   97,   98,   99,  100,    0,    0,    0,    0,
    0,    0,   20,    0,   93,   94,   95,   96,   97,   98,
   99,  100,    0,   30,  112,  113,  114,  115,  116,  117,
    0,    0,    0,    0,    0,   20,   20,   20,    0,   20,
    0,   20,   20,   20,   20,   20,   30,   30,   30,    0,
   30,    0,   30,   30,   30,   30,   30,    0,    0,    0,
    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   43,   44,
    0,   45,    0,   46,   47,   48,   49,   50,
};
static const YYINT yycheck[] = {                         40,
   59,   93,   40,   63,   40,   44,   61,   41,   61,   39,
   44,   59,   44,  257,  258,  257,  258,   41,   59,  123,
   59,  125,   44,   41,   44,   59,   44,   59,   36,  283,
  123,   41,  125,   63,   44,   59,   91,   59,   91,   59,
  283,   40,  283,   51,   74,   74,  290,   41,    2,   59,
   40,    5,   91,    7,   91,   41,  258,   91,   44,   93,
  283,   41,  284,   41,   44,   41,  283,   41,   93,   41,
   59,   41,  123,   59,  104,  104,  106,   10,   40,   47,
   64,   59,   41,   93,   41,   41,  146,   44,   44,   58,
   41,  121,  121,   41,  124,  124,   44,   65,   82,   67,
   40,  131,  131,   71,   40,  284,   59,   93,   76,   41,
   78,   79,   44,   40,   82,   40,  146,  147,  147,   41,
  150,  150,   44,   91,  283,  109,  259,  260,  261,  262,
  263,  264,  265,  266,  102,   59,   40,   58,  122,  123,
  261,  262,  263,  264,  265,  266,   41,   91,   40,   44,
  118,   59,  256,   59,  276,   41,    0,  125,   31,   77,
   91,   22,    7,  256,   20,   -1,   -1,  259,  260,  261,
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
  261,  262,  263,  264,  265,  266,   -1,   -1,   -1,   -1,
   -1,   -1,  256,   -1,  259,  260,  261,  262,  263,  264,
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
"binary_comp","binary_op","expression","variable","affectation","condition",
"parm","appel","bloc","saut","selection","iteration","instruction",
"liste_expressions","liste_instructions","liste_parms","fonction",
"liste_declarateurs","liste_fonctions","liste_declarations","type",
"declaration","declarateur","illegal-symbol",
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
#line 175 "miniC.y"

extern int yylineno;

int test() {
    // Création de l'AST
    noeud* root = creerNoeud("Root");
    printf("type root : %d\n", root->typeu); // 0 -> NULLTYPE
    // Ajout de nœuds enfants
    noeud* child1 = creerNoeud("Child1");
    noeud* child2 = creerNoeud("Child2");
    printf("Nombre d'enfants de root : %d\n", root->nb_fils);

	// Création de la liste chaînée de nœuds
	liste_chaine_noeud* liste = creerListeChaineNoeud(child1);
    liste = addListeChaineNoeud(liste, child2);
    
    // Ajout de tous les nœuds de la liste à un nœud parent
    root = addAllChild(root, liste);
	printf("Nombre d'enfants de root : %d\n", root->nb_fils);

    // Affichage de l'AST
    printf("Affichage de l'AST :\n");
    afficherNoeud(root);
    printf("\n");
    
    // Recherche d'un nœud
    char* valeurRecherchee = "Child3";
    noeud* resultatRecherche = rechercherNoeud(root, valeurRecherchee);
	printf("res : %s\n", resultatRecherche);
    if (resultatRecherche != NULL) {
        printf("Noeud avec la valeur \"%s\" trouvé.\n", valeurRecherchee);
    } else {
        printf("Noeud avec la valeur \"%s\" non trouvé.\n", valeurRecherchee);
    }
    
    // Libération de l'AST
    libererNoeud(root);
    
    return 0;
}


void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	//while (yyparse);
	test();
}





/*
c ma save de teste touche pas 
void test() {
    SymbolStack stack;
    initStack(&stack);
    int a = 5;
    int b[] = {1, 2, 3};
    int c[] = {4, 5, 6};
    int size_b = sizeof(b)/sizeof(b[0]);
	int size_c = sizeof(c)/sizeof(c[0]);

	// Ajout de symboles à la pile
	push(&stack, "x", a, NULL, 0, NULL, INTEGER);
	push(&stack, "y", 0, b, size_b, NULL, INTARRAY);
	push(&stack, "z", 0, c, size_c, NULL, INTARRAY);
	// on va teste de faire un changement de valeur de t 
	push(&stack, "t", 2, NULL, 0, NULL, INTEGER);
    // Affichage de la pile pour déboguer
    printf("Pile de symboles :\n");
    printStack(&stack);
    
    // Recherche de symboles dans la pile
	printf("Taille de b : %d\n", size_b);

    printf("x = %d\n", *lookup(&stack, "x"));
    printf("y[0] = %d\n", lookup(&stack, "y")[0]);
	// Modification de la valeur de y[1] à 10
    int* ptr_y1 = assign_array(&stack, "y", 1, 10);
    if (ptr_y1 != NULL) {
        printf("Nouvelle valeur de y[1] : %d\n", *ptr_y1);
    }
    printf("init z[0] = %d\n", lookup(&stack, "z")[0]);
	//on regarde la valeur de t
	printf("valeur initial de t = %d\n", *lookup(&stack, "t"));
	int new_t = 10;
	// avant de donner la nouvelle valeur de t on doit liberer l'ancienne valeur
	// on doit verif si le param est bien une vrai var int car meme si 
	// on met une char quand on appelle la fonction/
	// le code va convertir la valeur de la var char en int
	// a voir comment faire 
	//on change la valeur de t
	int* t = assign(&stack, "t", new_t);
	printf("new valeur de t = %d\n", *t);

    // Dépilement des symboles de la pile
    Symbol symbol1 = pop(&stack);
    printf("Symbole depile : %s\n", symbol1.name);
    Symbol symbol2 = pop(&stack);
    printf("Symbole depile : %s\n", symbol2.name);
    Symbol symbol3 = pop(&stack);
    printf("Symbole depile : %s\n", symbol3.name);
	Symbol symbol4 = pop(&stack);
	printf("Symbole depile : %s\n", symbol4.name);
    
    // Destruction de la pile
    freeStack(&stack);
}


 deux stack , une poour declarations et une pour utilisation 
 si on ajoute une decla, on ajoute dans la stack decla et utilisation je mets une case vide
 si on ajoute une utilisation, on ajoute dans la stack utilisation et dans la stack decla je mets une case vide
 changer structure genre faire 2 pile différentes 
*/
#line 734 "y.tab.c"

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
#line 47 "miniC.y"
	{yyval.id= creerNoeud("coucou");addAllChild(yyval.id,yystack.l_mark[-1].liste);}
#line 1407 "y.tab.c"
break;
case 2:
#line 50 "miniC.y"
	{yyval.liste= addListeChaineNoeud(yystack.l_mark[-1].liste,yystack.l_mark[0].noeud);}
#line 1412 "y.tab.c"
break;
case 3:
#line 51 "miniC.y"
	{yyval.liste= creerListeChaineNoeud(creerNoeud("coucou"));}
#line 1417 "y.tab.c"
break;
case 4:
#line 54 "miniC.y"
	{yyval.liste=yystack.l_mark[-1].liste;}
#line 1422 "y.tab.c"
break;
case 5:
#line 55 "miniC.y"
	{yyval.liste=yystack.l_mark[0].id;}
#line 1427 "y.tab.c"
break;
case 6:
#line 58 "miniC.y"
	{yyval.noeud = creerNoeud("coucou"); yyval.noeud=addAllChild(yyval.noeud,yystack.l_mark[-1].liste); yyval.noeud=addTypeNoeud(yyval.noeud,yystack.l_mark[-2].typeu);}
#line 1432 "y.tab.c"
break;
case 7:
#line 61 "miniC.y"
	{yyval.liste= addListeChaineNoeud(yystack.l_mark[-2].liste,yystack.l_mark[0].noeud);}
#line 1437 "y.tab.c"
break;
case 8:
#line 62 "miniC.y"
	{yyval.liste = creerListeChaineNoeud(yystack.l_mark[0].noeud); }
#line 1442 "y.tab.c"
break;
case 9:
#line 65 "miniC.y"
	{ yyval.noeud = creerNoeud(yystack.l_mark[0].id);}
#line 1447 "y.tab.c"
break;
case 10:
#line 66 "miniC.y"
	{yyval.noeud= addSize(yystack.l_mark[-3].noeud,yystack.l_mark[-1].id);}
#line 1452 "y.tab.c"
break;
case 11:
#line 69 "miniC.y"
	{yyval.id=yystack.l_mark[-8].typeu;}
#line 1457 "y.tab.c"
break;
case 12:
#line 70 "miniC.y"
	{yyval.id=EXTERN;}
#line 1462 "y.tab.c"
break;
case 13:
#line 73 "miniC.y"
	{yyval.typeu = "void";}
#line 1467 "y.tab.c"
break;
case 14:
#line 74 "miniC.y"
	{yyval.typeu = "int";}
#line 1472 "y.tab.c"
break;
case 15:
#line 78 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1477 "y.tab.c"
break;
case 16:
#line 79 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1482 "y.tab.c"
break;
case 17:
#line 80 "miniC.y"
	{yyval.id=" ";}
#line 1487 "y.tab.c"
break;
case 18:
#line 84 "miniC.y"
	{yyval.id = yystack.l_mark[0].id;}
#line 1492 "y.tab.c"
break;
case 19:
#line 88 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1497 "y.tab.c"
break;
case 20:
#line 89 "miniC.y"
	{yyval.id=" ";}
#line 1502 "y.tab.c"
break;
case 21:
#line 92 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1507 "y.tab.c"
break;
case 22:
#line 93 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1512 "y.tab.c"
break;
case 23:
#line 94 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1517 "y.tab.c"
break;
case 24:
#line 95 "miniC.y"
	{yyval.id=yystack.l_mark[-1].id;}
#line 1522 "y.tab.c"
break;
case 25:
#line 96 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1527 "y.tab.c"
break;
case 26:
#line 97 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1532 "y.tab.c"
break;
case 27:
#line 100 "miniC.y"
	{yyval.id=FOR;}
#line 1537 "y.tab.c"
break;
case 28:
#line 101 "miniC.y"
	{yyval.id= WHILE;}
#line 1542 "y.tab.c"
break;
case 29:
#line 102 "miniC.y"
	{yyerror("reenter last");
                        yyerrok; }
#line 1548 "y.tab.c"
break;
case 30:
#line 106 "miniC.y"
	{yyval.id=IF;}
#line 1553 "y.tab.c"
break;
case 31:
#line 107 "miniC.y"
	{yyval.id=ELSE;}
#line 1558 "y.tab.c"
break;
case 32:
#line 108 "miniC.y"
	{yyval.id=SWITCH;}
#line 1563 "y.tab.c"
break;
case 33:
#line 109 "miniC.y"
	{yyval.id=CASE;}
#line 1568 "y.tab.c"
break;
case 34:
#line 110 "miniC.y"
	{yyval.id=DEFAULT;}
#line 1573 "y.tab.c"
break;
case 35:
#line 113 "miniC.y"
	{yyval.id=BREAK;}
#line 1578 "y.tab.c"
break;
case 36:
#line 114 "miniC.y"
	{yyval.id=RETURN;}
#line 1583 "y.tab.c"
break;
case 37:
#line 115 "miniC.y"
	{yyval.id=RETURN;}
#line 1588 "y.tab.c"
break;
case 38:
#line 118 "miniC.y"
	{yyval.id = yystack.l_mark[0].id;}
#line 1593 "y.tab.c"
break;
case 39:
#line 121 "miniC.y"
	{yyval.id="0";}
#line 1598 "y.tab.c"
break;
case 40:
#line 124 "miniC.y"
	{yyval.id=yystack.l_mark[-4].id;}
#line 1603 "y.tab.c"
break;
case 41:
#line 127 "miniC.y"
	{yyval.id = yystack.l_mark[0].id;}
#line 1608 "y.tab.c"
break;
case 42:
#line 128 "miniC.y"
	{yyval.id ="0";/* $$ = $1[$3] ;*/}
#line 1613 "y.tab.c"
break;
case 43:
#line 131 "miniC.y"
	{yyval.id = yystack.l_mark[-1].id;}
#line 1618 "y.tab.c"
break;
case 44:
#line 132 "miniC.y"
	{yyval.id="0";}
#line 1623 "y.tab.c"
break;
case 45:
#line 133 "miniC.y"
	{yyval.id = yystack.l_mark[0].id;}
#line 1628 "y.tab.c"
break;
case 46:
#line 134 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1633 "y.tab.c"
break;
case 47:
#line 135 "miniC.y"
	{yyval.id = yystack.l_mark[0].id;}
#line 1638 "y.tab.c"
break;
case 48:
#line 136 "miniC.y"
	{yyval.id = yystack.l_mark[-3].id;}
#line 1643 "y.tab.c"
break;
case 49:
#line 140 "miniC.y"
	{yyval.id=yystack.l_mark[-2].id;}
#line 1648 "y.tab.c"
break;
case 50:
#line 141 "miniC.y"
	{yyval.id=yystack.l_mark[0].id;}
#line 1653 "y.tab.c"
break;
case 51:
#line 142 "miniC.y"
	{yyval.id=" ";}
#line 1658 "y.tab.c"
break;
case 52:
#line 146 "miniC.y"
	{yyval.id = yystack.l_mark[-1].id;}
#line 1663 "y.tab.c"
break;
case 53:
#line 147 "miniC.y"
	{yyval.id="0";}
#line 1668 "y.tab.c"
break;
case 54:
#line 148 "miniC.y"
	{yyval.id = yystack.l_mark[-1].id;}
#line 1673 "y.tab.c"
break;
case 55:
#line 149 "miniC.y"
	{yyval.id="0";}
#line 1678 "y.tab.c"
break;
case 56:
#line 152 "miniC.y"
	{yyval.id = "+"; }
#line 1683 "y.tab.c"
break;
case 57:
#line 153 "miniC.y"
	{yyval.id = "-"; }
#line 1688 "y.tab.c"
break;
case 58:
#line 154 "miniC.y"
	{yyval.id = "*"; }
#line 1693 "y.tab.c"
break;
case 59:
#line 155 "miniC.y"
	{yyval.id = "/"; }
#line 1698 "y.tab.c"
break;
case 60:
#line 156 "miniC.y"
	{yyval.id = "<<"; }
#line 1703 "y.tab.c"
break;
case 61:
#line 157 "miniC.y"
	{yyval.id = ">>"; }
#line 1708 "y.tab.c"
break;
case 62:
#line 158 "miniC.y"
	{yyval.id = "&="; }
#line 1713 "y.tab.c"
break;
case 63:
#line 159 "miniC.y"
	{yyval.id = "|="; }
#line 1718 "y.tab.c"
break;
case 64:
#line 162 "miniC.y"
	{yyval.id = "&&"; }
#line 1723 "y.tab.c"
break;
case 65:
#line 163 "miniC.y"
	{yyval.id = "||"; }
#line 1728 "y.tab.c"
break;
case 66:
#line 166 "miniC.y"
	{printf("marg" );yyval.id = "<"; }
#line 1733 "y.tab.c"
break;
case 67:
#line 167 "miniC.y"
	{yyval.id = ">"; }
#line 1738 "y.tab.c"
break;
case 68:
#line 168 "miniC.y"
	{yyval.id = ">="; }
#line 1743 "y.tab.c"
break;
case 69:
#line 169 "miniC.y"
	{yyval.id = "<="; }
#line 1748 "y.tab.c"
break;
case 70:
#line 170 "miniC.y"
	{yyval.id = "=="; }
#line 1753 "y.tab.c"
break;
case 71:
#line 171 "miniC.y"
	{yyval.id = "!="; }
#line 1758 "y.tab.c"
break;
#line 1760 "y.tab.c"
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
