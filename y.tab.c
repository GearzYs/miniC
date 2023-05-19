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
#line 10 "miniC.y"
typedef union YYSTYPE{
	int val;
	char* id;
	noeud *noeud;
	liste_noeud *liste_noeud;
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
    0,   23,   23,   19,   19,   14,   24,   24,   15,   15,
   13,   13,   16,   16,   21,   21,   21,   18,   20,   20,
    8,    8,    8,    8,    8,    8,    7,    7,    7,    5,
    5,    5,    5,    5,    6,    6,    6,   11,    9,   10,
   17,   17,   12,   12,   12,   12,   12,   12,   22,   22,
   22,    4,    4,    4,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    2,    2,    2,    2,    2,
    2,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    2,    1,    3,    3,    1,    1,    4,
    6,    7,    1,    1,    3,    1,    0,    2,    2,    0,
    1,    1,    1,    2,    1,    1,    9,    5,    2,    5,
    7,    5,    4,    3,    2,    2,    3,    3,    4,    5,
    1,    4,    3,    3,    2,    1,    1,    4,    3,    1,
    0,    4,    3,    3,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   13,   14,    0,    5,    2,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    6,    0,
    0,    0,    0,   16,    0,    0,    9,    0,    0,   18,
    0,    0,   10,    0,   15,    3,   11,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   39,   22,   23,   21,   19,   25,   26,    0,    0,
   29,    0,    0,    0,    0,   35,    0,    0,   46,   36,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,
    0,   56,   57,   58,   59,   60,   61,   62,   63,   37,
    0,   34,    0,    0,    0,    0,    0,    0,    0,   64,
   65,    0,    0,   66,   67,   68,   69,   70,   71,    0,
    0,    0,    0,    0,    0,   43,   44,   33,    0,   42,
    0,   54,   28,   53,    0,    0,    0,    0,   40,   48,
   32,   52,    0,    0,    0,   31,    0,   27,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  292,  315,  257,  258,  290,  305,  306,  308,  311,  308,
  283,  307,  316,  305,  308,  283,   40,   91,   59,   44,
  283,   40,  258,  310,  313,  284,  283,  307,  313,  283,
   44,   41,   93,   41,  310,  123,  301,   59,  315,  308,
  312,  256,  279,  280,  281,  283,  285,  286,  287,  288,
  289,  125,  297,  298,  299,  300,  301,  302,  303,  309,
   10,   40,   40,   40,   40,   59,  260,  283,  284,   59,
   40,  304,  309,   58,  284,   40,   59,   91,   61,  282,
   40,  296,  304,  283,  303,  296,  304,  314,  304,   40,
  304,  259,  260,  261,  262,  263,  264,  265,  266,   59,
  295,  300,   58,  304,  304,  304,   40,  296,  304,  267,
  268,   41,  293,  269,  270,  271,  272,  273,  274,  294,
   59,   41,   44,   41,  314,   41,  304,  300,   41,   93,
  296,   41,  300,  296,  304,  296,  300,  304,   59,   41,
  300,   41,   59,  276,  303,  300,   41,  300,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
  113,  120,  101,   82,   53,   54,   55,   56,   57,   58,
   59,   83,    6,    7,   12,    8,   73,   24,    9,   41,
   25,   88,    2,   13,
};
static const YYINT yysindex[] = {                         0,
    0, -241,    0,    0, -213,    0,    0, -269, -241, -265,
  -13,  -50,  -21,    0, -249,    6, -206, -221,    0, -218,
  -13, -206, -208,    0,   13,  -16,    0,  -50,   32,    0,
 -206,  -44,    0,   22,    0,    0,    0,    0, -213, -218,
 -103,   75,   47,   54,   66,   84,   85,  -40,   49, -159,
  105,    0,    0,    0,    0,    0,    0,    0,   87,  -36,
    0,  -37, -136,  -37,  -35,    0,  -35,  108,    0,    0,
  -35,  -47,   58,   78,   92,  -35,    0,  -35,  -35,  111,
  -37,   25, -143,    0,   93,   27, -161,   48, -129,  -35,
   42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -35,    0,   78,   50,  -91, -161,  -37,   29,    7,    0,
    0,   78,  -37,    0,    0,    0,    0,    0,    0,  -35,
  -37,   78,  -35,   95,   52,    0,    0,    0,   78,    0,
   31,    0,    0,    0, -161,  -58, -121, -161,    0,    0,
    0,    0, -136,   78,  115,    0,   78,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  157,    0,
  -29,  -20,    0,    0,    0,    0,   70,    0,    0,    0,
    0,   70,    0,    0,    0,    0,    0,   -8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -92,    0,
    0,    0,    0,    0,    0,  -24,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   97,    0,    0,  -33,    0,    0,
    0,    0,   -9,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   98,    0,   15,   97,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   23,    0,   67,   99,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  -60,    0,    0,    0,  -32,  126,    0,
  -57,  303,  150,    0,  140,    4,  -34,  130,    0,    0,
  141,   72,  129,    0,
};
#define YYTABLESIZE 426
static const YYINT yytable[] = {                         71,
  143,  130,   81,   86,   71,   85,   60,   41,   10,   38,
   41,  100,   15,   11,    9,    3,    4,   16,   70,   36,
  108,   52,   20,    8,   79,   41,   17,   38,   60,    9,
   20,   47,   20,   21,   47,    7,   41,   19,    8,   60,
   18,  102,   40,    3,    4,   22,  131,  126,    5,   47,
    7,   23,  134,   32,   78,   45,   31,   41,   45,   41,
  136,    9,   26,   55,   27,  112,   41,  122,   60,  132,
  128,  142,   34,   45,   30,   31,   33,   60,   36,  133,
   38,   55,  126,   47,   61,  145,   62,   60,  124,  137,
  129,  123,  140,   63,   60,  123,  141,   92,   93,   94,
   95,   96,   97,   98,   99,   64,   74,   45,   60,   60,
   17,  146,   60,   17,  148,   92,   93,   94,   95,   96,
   97,   98,   99,   65,   75,  114,  115,  116,  117,  118,
  119,   94,   95,   96,   97,   98,   99,   51,   50,   49,
   51,   50,   49,   66,   76,   77,   84,   90,   78,  103,
  107,  121,   42,  139,  144,  147,    1,   37,   14,   28,
   35,  125,   29,   20,   39,    0,    0,   92,   93,   94,
   95,   96,   97,   98,   99,   43,   44,   45,    0,   46,
    0,   47,   48,   49,   50,   51,   20,   20,   20,   30,
   20,   30,   20,   20,   20,   20,   20,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,    0,  110,  111,
    0,   92,   93,   94,   95,   96,   97,   98,   99,   67,
    0,    0,   67,    0,   67,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,    0,   68,   69,   80,   68,   69,   68,   69,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   92,   93,   94,   95,   96,
   97,   98,   99,   45,   45,  114,  115,  116,  117,  118,
  119,   45,   45,   45,   45,   45,   45,   45,   45,   55,
   55,  110,  111,  110,  111,  110,  111,  110,  111,    0,
   92,   93,   94,   95,   96,   97,   98,   99,   92,   93,
   94,   95,   96,   97,   98,   99,    0,    0,    0,    0,
    0,    0,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,   30,   30,    0,   30,
   72,   30,   30,   30,   30,   30,   43,   44,   45,    0,
   46,    0,   47,   48,   49,   50,   51,   87,    0,   89,
    0,    0,    0,   91,    0,    0,    0,    0,  104,    0,
  105,  106,    0,  109,    0,    0,    0,    0,    0,    0,
    0,    0,   87,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  127,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  135,    0,    0,  138,
};
static const YYINT yycheck[] = {                         40,
   59,   93,   40,   64,   40,   63,   41,   41,    5,   41,
   44,   59,    9,  283,   44,  257,  258,  283,   59,  123,
   81,  125,   44,   44,   61,   59,   40,   59,   63,   59,
  123,   41,  125,  283,   44,   44,   61,   59,   59,   74,
   91,   74,   39,  257,  258,   40,  107,   41,  290,   59,
   59,  258,  113,   41,   91,   41,   44,   91,   44,   93,
  121,   91,  284,   41,  283,   41,   91,   41,  103,   41,
  103,   41,   41,   59,  283,   44,   93,  112,  123,  112,
   59,   59,   41,   93,   10,  143,   40,  122,   41,  122,
   41,   44,   41,   40,  129,   44,  129,  259,  260,  261,
  262,  263,  264,  265,  266,   40,   58,   93,  143,  144,
   41,  144,  147,   44,  147,  259,  260,  261,  262,  263,
  264,  265,  266,   40,  284,  269,  270,  271,  272,  273,
  274,  261,  262,  263,  264,  265,  266,   41,   41,   41,
   44,   44,   44,   59,   40,   59,  283,   40,   91,   58,
   40,   59,  256,   59,  276,   41,    0,   32,    9,   20,
   31,   90,   22,  256,   36,   -1,   -1,  259,  260,  261,
  262,  263,  264,  265,  266,  279,  280,  281,   -1,  283,
   -1,  285,  286,  287,  288,  289,  279,  280,  281,  123,
  283,  125,  285,  286,  287,  288,  289,   -1,   -1,   -1,
  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
   -1,  259,  260,  261,  262,  263,  264,  265,  266,  260,
   -1,   -1,  260,   -1,  260,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   -1,  283,  284,  282,  283,  284,  283,  284,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  259,  260,  261,  262,  263,
  264,  265,  266,  259,  260,  269,  270,  271,  272,  273,
  274,  267,  268,  269,  270,  271,  272,  273,  274,  267,
  268,  267,  268,  267,  268,  267,  268,  267,  268,   -1,
  259,  260,  261,  262,  263,  264,  265,  266,  259,  260,
  261,  262,  263,  264,  265,  266,   -1,   -1,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  279,  280,  281,   -1,  283,
   48,  285,  286,  287,  288,  289,  279,  280,  281,   -1,
  283,   -1,  285,  286,  287,  288,  289,   65,   -1,   67,
   -1,   -1,   -1,   71,   -1,   -1,   -1,   -1,   76,   -1,
   78,   79,   -1,   81,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   90,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  101,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  120,   -1,   -1,  123,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,
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
"instruction","bloc","appel","affectation","expression","fonction",
"declaration","declarateur","type","variable","parm","liste_fonctions",
"liste_instructions","liste_parms","liste_expressions","liste_declarations",
"liste_declarateurs","illegal-symbol",
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
"fonction : type IDENTIFICATEUR '(' liste_parms ')' bloc",
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
#line 252 "miniC.y"
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
	while(yyparse());
}
#line 622 "y.tab.c"

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
#line 39 "miniC.y"
	{yyval.noeud= creerNoeud("PROGRAMME");
											noeud* declaration = creerNoeud("BLOC");
											declaration->tableSymbole->fonction->declaration = yystack.l_mark[-1].liste_noeud;
											printf("nb noeud : %d\n",yystack.l_mark[-1].liste_noeud->nb_noeud);
											declaration=addAllChild(declaration,yystack.l_mark[-1].liste_noeud);
											noeud* fonction = creerNoeud("FONCTIONS");
											fonction=addAllChild(fonction,yystack.l_mark[0].liste_noeud);
											yyval.noeud=appendChild2(yyval.noeud,declaration,fonction);
											verifierDeclarations(yyval.noeud);
											generateDotFile(yystack.l_mark[0].liste_noeud);}
#line 1304 "y.tab.c"
break;
case 2:
#line 51 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}
#line 1309 "y.tab.c"
break;
case 3:
#line 52 "miniC.y"
	{yyval.liste_noeud=NULL;}
#line 1314 "y.tab.c"
break;
case 4:
#line 55 "miniC.y"
	{yyval.liste_noeud = addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}
#line 1319 "y.tab.c"
break;
case 5:
#line 56 "miniC.y"
	{yyval.liste_noeud= creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1324 "y.tab.c"
break;
case 6:
#line 59 "miniC.y"
	{if(strcmp(yystack.l_mark[-2].noeud->val,"int")==0){
										yyval.noeud = creerNoeud("DECLARATION");
										yyval.noeud = addAllChild(yyval.noeud,yystack.l_mark[-1].liste_noeud);
									} else{
										yyerror("Error : Declaration of a non-handled type.");
									}}
#line 1334 "y.tab.c"
break;
case 7:
#line 67 "miniC.y"
	{yyval.liste_noeud= addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1339 "y.tab.c"
break;
case 8:
#line 68 "miniC.y"
	{yyval.liste_noeud = creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1344 "y.tab.c"
break;
case 9:
#line 71 "miniC.y"
	{yyval.noeud = newVariable(yystack.l_mark[0].id,yylineno);}
#line 1349 "y.tab.c"
break;
case 10:
#line 72 "miniC.y"
	{yyval.noeud=appendChild1(yystack.l_mark[-3].noeud,creerNoeud(yystack.l_mark[-1].id));}
#line 1354 "y.tab.c"
break;
case 11:
#line 75 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"%s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = FONCTION;
																								if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0){
																									yyval.noeud=newFunction(yyval.noeud,yystack.l_mark[-4].id,yystack.l_mark[-5].noeud,yystack.l_mark[-2].liste_noeud,yylineno);
																								}
																								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);
																								}
#line 1367 "y.tab.c"
break;
case 12:
#line 84 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"EXTERN %s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = FONCTION;
																								if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0) {
																									/*$$=newFunction($$,$3,$2,$5);*/
																									for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
																										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
																									}
																								}}
#line 1381 "y.tab.c"
break;
case 13:
#line 96 "miniC.y"
	{yyval.noeud = creerNoeud("void");}
#line 1386 "y.tab.c"
break;
case 14:
#line 97 "miniC.y"
	{yyval.noeud = creerNoeud("int");}
#line 1391 "y.tab.c"
break;
case 15:
#line 101 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1396 "y.tab.c"
break;
case 16:
#line 102 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1401 "y.tab.c"
break;
case 17:
#line 103 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1408 "y.tab.c"
break;
case 18:
#line 109 "miniC.y"
	{yyval.noeud = creerNoeud("INT");
							yyval.noeud = appendChild1(yyval.noeud,creerNoeud(yystack.l_mark[0].id));}
#line 1414 "y.tab.c"
break;
case 19:
#line 114 "miniC.y"
	{if (yystack.l_mark[0].noeud!=NULL) {yyval.liste_noeud=addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}}
#line 1419 "y.tab.c"
break;
case 20:
#line 115 "miniC.y"
	{yyval.liste_noeud=NULL;}
#line 1424 "y.tab.c"
break;
case 21:
#line 118 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1429 "y.tab.c"
break;
case 22:
#line 119 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1434 "y.tab.c"
break;
case 23:
#line 120 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1439 "y.tab.c"
break;
case 24:
#line 121 "miniC.y"
	{yyval.noeud=yystack.l_mark[-1].noeud;}
#line 1444 "y.tab.c"
break;
case 25:
#line 122 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1449 "y.tab.c"
break;
case 26:
#line 123 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1454 "y.tab.c"
break;
case 27:
#line 126 "miniC.y"
	{yyval.noeud= creerNoeud("FOR");
																			yyval.noeud = appendChild4(yyval.noeud,yystack.l_mark[-6].noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1460 "y.tab.c"
break;
case 28:
#line 128 "miniC.y"
	{yyval.noeud= creerNoeud("WHILE");
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1466 "y.tab.c"
break;
case 29:
#line 130 "miniC.y"
	{yyerror("reenter last");
                        yyerrok; }
#line 1472 "y.tab.c"
break;
case 30:
#line 134 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
													yyval.noeud->type = IF;
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1479 "y.tab.c"
break;
case 31:
#line 137 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
															yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1485 "y.tab.c"
break;
case 32:
#line 139 "miniC.y"
	{yyval.noeud= creerNoeud("SWITCH");
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1491 "y.tab.c"
break;
case 33:
#line 141 "miniC.y"
	{yyval.noeud= creerNoeud("CASE");
										noeud* constante = creerNoeud(yystack.l_mark[-2].id);
										yyval.noeud = appendChild2(yyval.noeud,constante,yystack.l_mark[0].noeud);}
#line 1498 "y.tab.c"
break;
case 34:
#line 144 "miniC.y"
	{yyval.noeud= creerNoeud("default");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1504 "y.tab.c"
break;
case 35:
#line 148 "miniC.y"
	{yyval.noeud= creerNoeud("BREAK"); 
					yyval.noeud->type = BREAK;}
#line 1510 "y.tab.c"
break;
case 36:
#line 150 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
					yyval.noeud->type = RETURN;}
#line 1516 "y.tab.c"
break;
case 37:
#line 152 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
							yyval.noeud->type = RETURN;
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1523 "y.tab.c"
break;
case 38:
#line 157 "miniC.y"
	{yyval.noeud = creerNoeud(":=");
									yystack.l_mark[0].noeud->type = ARGUMENT;
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1530 "y.tab.c"
break;
case 39:
#line 162 "miniC.y"
	{yyval.noeud= creerNoeud("BLOC");
														yyval.noeud->tableSymbole->fonction->declaration=yystack.l_mark[-2].liste_noeud;
														if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															if (yystack.l_mark[-1].liste_noeud->liste_noeud[i]!=NULL){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
														}
														}
														}
}
#line 1544 "y.tab.c"
break;
case 40:
#line 174 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-4].id);
														yyval.noeud->type = APPELFONCTION;
														if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
															if (yystack.l_mark[-2].liste_noeud->liste_noeud[i]!=NULL){
															yystack.l_mark[-2].liste_noeud->liste_noeud[i]->type = ARGUMENT;
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
															}
														}
													}}
#line 1558 "y.tab.c"
break;
case 41:
#line 186 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id);}
#line 1563 "y.tab.c"
break;
case 42:
#line 187 "miniC.y"
	{yyval.noeud = creerNoeud("TAB");
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-3].noeud,yystack.l_mark[-1].noeud);}
#line 1569 "y.tab.c"
break;
case 43:
#line 191 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1574 "y.tab.c"
break;
case 44:
#line 192 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-1].id);
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1580 "y.tab.c"
break;
case 45:
#line 194 "miniC.y"
	{yyval.noeud = creerNoeud("-");
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1586 "y.tab.c"
break;
case 46:
#line 196 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[0].id);}
#line 1591 "y.tab.c"
break;
case 47:
#line 197 "miniC.y"
	{yyval.noeud = yystack.l_mark[0].noeud;}
#line 1596 "y.tab.c"
break;
case 48:
#line 198 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[-3].id);
													yyval.noeud->type = APPELFONCTION;
													if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
														}
													}}
#line 1607 "y.tab.c"
break;
case 49:
#line 208 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1612 "y.tab.c"
break;
case 50:
#line 209 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1617 "y.tab.c"
break;
case 51:
#line 210 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1624 "y.tab.c"
break;
case 52:
#line 216 "miniC.y"
	{yyval.noeud = creerNoeud("NOT");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1630 "y.tab.c"
break;
case 53:
#line 218 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1638 "y.tab.c"
break;
case 54:
#line 222 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1643 "y.tab.c"
break;
case 55:
#line 223 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1651 "y.tab.c"
break;
case 56:
#line 229 "miniC.y"
	{yyval.id = "+"; }
#line 1656 "y.tab.c"
break;
case 57:
#line 230 "miniC.y"
	{yyval.id = "-"; }
#line 1661 "y.tab.c"
break;
case 58:
#line 231 "miniC.y"
	{yyval.id = "*"; }
#line 1666 "y.tab.c"
break;
case 59:
#line 232 "miniC.y"
	{yyval.id = "/"; }
#line 1671 "y.tab.c"
break;
case 60:
#line 233 "miniC.y"
	{yyval.id = "<<"; }
#line 1676 "y.tab.c"
break;
case 61:
#line 234 "miniC.y"
	{yyval.id = ">>"; }
#line 1681 "y.tab.c"
break;
case 62:
#line 235 "miniC.y"
	{yyval.id = "&="; }
#line 1686 "y.tab.c"
break;
case 63:
#line 236 "miniC.y"
	{yyval.id = "|="; }
#line 1691 "y.tab.c"
break;
case 64:
#line 239 "miniC.y"
	{yyval.id = "&&"; }
#line 1696 "y.tab.c"
break;
case 65:
#line 240 "miniC.y"
	{yyval.id = "||"; }
#line 1701 "y.tab.c"
break;
case 66:
#line 243 "miniC.y"
	{yyval.id = "<"; }
#line 1706 "y.tab.c"
break;
case 67:
#line 244 "miniC.y"
	{yyval.id = ">"; }
#line 1711 "y.tab.c"
break;
case 68:
#line 245 "miniC.y"
	{yyval.id = ">="; }
#line 1716 "y.tab.c"
break;
case 69:
#line 246 "miniC.y"
	{yyval.id = "<="; }
#line 1721 "y.tab.c"
break;
case 70:
#line 247 "miniC.y"
	{yyval.id = "=="; }
#line 1726 "y.tab.c"
break;
case 71:
#line 248 "miniC.y"
	{yyval.id = "!="; }
#line 1731 "y.tab.c"
break;
#line 1733 "y.tab.c"
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
