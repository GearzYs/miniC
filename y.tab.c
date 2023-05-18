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
    0,   13,   13,   21,   21,   15,   16,   16,   17,   17,
   14,   14,   18,   18,   23,   23,   23,   20,   22,   22,
    8,    8,    8,    8,    8,    8,    7,    7,    7,    5,
    5,    5,    5,    5,    6,    6,    6,   11,    9,   10,
   19,   19,   12,   12,   12,   12,   12,   12,   24,   24,
   24,    4,    4,    4,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    2,    2,    2,    2,    2,
    2,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    2,    1,    3,    3,    1,    1,    4,
    6,    7,    1,    1,    3,    1,    0,    2,    2,    1,
    1,    1,    1,    2,    1,    1,    9,    5,    2,    5,
    7,    5,    4,    3,    2,    2,    3,    3,    4,    5,
    1,    4,    3,    3,    2,    1,    1,    4,    3,    1,
    0,    4,    3,    3,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   13,   14,    0,    5,    2,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    6,    0,    0,
    0,    0,    0,   16,    0,    9,    0,    0,    0,   18,
    0,    0,   10,    0,   15,    3,   11,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
   23,   21,   20,   25,   26,    0,    0,    0,    0,   29,
    0,    0,    0,    0,   35,    0,    0,   46,   36,    0,
    0,    0,    0,    0,    0,   24,    0,    0,   39,   19,
    0,    0,    0,    0,   41,    0,    0,    0,    0,    0,
    0,    0,   56,   57,   58,   59,   60,   61,   62,   63,
   37,    0,   34,    0,    0,    0,    0,    0,    0,    0,
   64,   65,    0,    0,   66,   67,   68,   69,   70,   71,
    0,    0,    0,    0,    0,    0,   43,   44,   33,    0,
   42,    0,   54,   28,   53,    0,    0,    0,    0,   40,
   48,   32,   52,    0,    0,    0,   31,    0,   27,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  292,  305,  257,  258,  290,  306,  307,  310,  313,  310,
  283,  308,  309,  306,  310,  283,   40,   59,   44,   91,
  283,   40,  258,  312,  315,  283,  309,  284,  315,  283,
   44,   41,   93,   41,  312,  123,  301,   59,  305,  256,
  279,  280,  281,  283,  285,  286,  287,  288,  289,  297,
  298,  299,  300,  301,  302,  303,  310,  311,  314,   10,
   40,   40,   40,   40,   59,  260,  283,  284,   59,   40,
  304,  311,   58,  284,   40,   59,   91,   61,  125,  300,
  282,   40,  296,  304,  283,  303,  296,  304,  316,  304,
   40,  304,  259,  260,  261,  262,  263,  264,  265,  266,
   59,  295,  300,   58,  304,  304,  304,   40,  296,  304,
  267,  268,   41,  293,  269,  270,  271,  272,  273,  274,
  294,   59,   41,   44,   41,  316,   41,  304,  300,   41,
   93,  296,   41,  300,  296,  304,  296,  300,  304,   59,
   41,  300,   41,   59,  276,  303,  300,   41,  300,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
  114,  121,  102,   83,   50,   51,   52,   53,   54,   55,
   56,   84,    2,    6,    7,   12,   13,    8,   72,   24,
    9,   59,   25,   89,
};
static const YYINT yysindex[] = {                         0,
    0, -241,    0,    0, -212,    0,    0, -256, -241, -247,
   12,  -31,  -44,    0, -230,   39, -191,    0, -203, -213,
   12, -191, -202,    0,  -19,    0,  -44,   -8,   10,    0,
 -191,  -13,    0,   33,    0,    0,    0,    0, -103,   84,
   64,   71,   73,   83,   66,  -40,   70, -160,   91,    0,
    0,    0,    0,    0,    0,   82, -203,  -57,  -92,    0,
  -37, -141,  -37,  -35,    0,  -35,  109,    0,    0,  -35,
  -47,   59,   78,   93,  -35,    0,  -35,  -35,    0,    0,
  112,  -37,   25, -126,    0,   97,   27, -144,   21, -163,
  -35,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -35,    0,   78,   50,  -91, -144,  -37,   29,    7,
    0,    0,   78,  -37,    0,    0,    0,    0,    0,    0,
  -35,  -37,   78,  -35,   98,   32,    0,    0,    0,   78,
    0,   31,    0,    0,    0, -144,  -58, -118, -144,    0,
    0,    0,    0, -141,   78,  118,    0,   78,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  160,    0,
  -30,    0,  -29,    0,    0,    0,   34,    0,    0,    0,
    0,   34,    0,    0,    0,    0,  -21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,    0,    0,  -33,    0,    0,    0,
    0,   -9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,   15,
   46,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,   67,   65,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  -45,    0,    0,    0,  -16,  129,    0,
  -55,  305,  126,  154,    0,    0,  146,    1,  -18,  135,
    0,    0,  145,   88,
};
#define YYTABLESIZE 429
static const YYINT yytable[] = {                         70,
  144,  131,   82,   78,   70,   10,   86,   41,   41,   15,
   41,  101,   19,    9,    8,    3,    4,   87,   69,   36,
   58,   32,    7,   38,   31,   41,   11,   18,    9,    8,
   36,   47,   79,   77,   47,   16,  109,    7,   41,   57,
   58,   38,   80,   58,    3,    4,   20,  127,    5,   47,
   34,   17,   21,   31,   58,   45,  103,   41,   45,   41,
    9,  125,  132,   55,  124,  113,   23,  123,  135,  133,
   28,  143,  141,   45,   17,  124,  137,   17,   22,   26,
   30,   55,  127,   47,   33,   58,   51,  129,  146,   51,
  130,   38,   50,   60,   58,   50,  134,   95,   96,   97,
   98,   99,  100,   61,   58,   49,  138,   45,   49,   36,
   62,   58,   63,  142,   93,   94,   95,   96,   97,   98,
   99,  100,   64,   74,   65,   58,   58,   73,  147,   58,
   75,  149,   93,   94,   95,   96,   97,   98,   99,  100,
   76,   85,  115,  116,  117,  118,  119,  120,   91,   77,
  104,  108,   40,    3,    4,  122,  140,  145,  148,    1,
   37,   39,   14,   40,   27,   35,   29,   93,   94,   95,
   96,   97,   98,   99,  100,   41,   42,   43,  126,   44,
    0,   45,   46,   47,   48,   49,   41,   42,   43,   30,
   44,   30,   45,   46,   47,   48,   49,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,    0,  111,  112,
    0,   93,   94,   95,   96,   97,   98,   99,  100,   66,
    0,    0,   66,    0,   66,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
   41,    0,   67,   68,   81,   67,   68,   67,   68,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   93,   94,   95,   96,   97,
   98,   99,  100,   45,   45,  115,  116,  117,  118,  119,
  120,   45,   45,   45,   45,   45,   45,   45,   45,   55,
   55,  111,  112,  111,  112,  111,  112,  111,  112,    0,
   93,   94,   95,   96,   97,   98,   99,  100,   93,   94,
   95,   96,   97,   98,   99,  100,    0,    0,    0,    0,
    0,    0,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   30,   30,   30,    0,   30,
   71,   30,   30,   30,   30,   30,   41,   42,   43,    0,
   44,    0,   45,   46,   47,   48,   49,    0,   88,    0,
   90,    0,    0,    0,   92,    0,    0,    0,    0,  105,
    0,  106,  107,    0,    0,    0,  110,    0,    0,    0,
    0,    0,    0,    0,    0,   88,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  128,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  136,    0,    0,  139,
};
static const YYINT yycheck[] = {                         40,
   59,   93,   40,   61,   40,    5,   62,   41,   61,    9,
   44,   59,   44,   44,   44,  257,  258,   63,   59,  123,
   39,   41,   44,   41,   44,   59,  283,   59,   59,   59,
  123,   41,  125,   91,   44,  283,   82,   59,   91,   39,
   59,   59,   59,   62,  257,  258,   91,   41,  290,   59,
   41,   40,  283,   44,   73,   41,   73,   91,   44,   93,
   91,   41,  108,   41,   44,   41,  258,   41,  114,   41,
  284,   41,   41,   59,   41,   44,  122,   44,   40,  283,
  283,   59,   41,   93,   93,  104,   41,  104,  144,   44,
   41,   59,   41,   10,  113,   44,  113,  261,  262,  263,
  264,  265,  266,   40,  123,   41,  123,   93,   44,  123,
   40,  130,   40,  130,  259,  260,  261,  262,  263,  264,
  265,  266,   40,  284,   59,  144,  145,   58,  145,  148,
   40,  148,  259,  260,  261,  262,  263,  264,  265,  266,
   59,  283,  269,  270,  271,  272,  273,  274,   40,   91,
   58,   40,  256,  257,  258,   59,   59,  276,   41,    0,
   32,   36,    9,  256,   19,   31,   22,  259,  260,  261,
  262,  263,  264,  265,  266,  279,  280,  281,   91,  283,
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
   46,  285,  286,  287,  288,  289,  279,  280,  281,   -1,
  283,   -1,  285,  286,  287,  288,  289,   -1,   64,   -1,
   66,   -1,   -1,   -1,   70,   -1,   -1,   -1,   -1,   75,
   -1,   77,   78,   -1,   -1,   -1,   82,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  102,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  121,   -1,   -1,  124,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
"instruction","bloc","appel","affectation","expression","liste_declarations",
"fonction","declaration","liste_declarateurs","declarateur","type","variable",
"parm","liste_fonctions","liste_instructions","liste_parms","liste_expressions",
"illegal-symbol",
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
"liste_instructions : instruction",
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
#line 240 "miniC.y"
extern int yylineno;

void testVerifierTypeNoeud() {
    // Création d'un nœud avec le type attendu
    noeud* n = creerNoeud("test");
    bool b = firstLetterIsString(n);
    printf("firstLetterIsString (test) : %s\n", b ? "true" : "false");
	
    // Test avec un nom de fonction commençant par une lettre
    Fonction* fonction1 = malloc(sizeof(Fonction));
    fonction1->nom = "addition";
    fonction1->typeRetour = INTEGER;
    fonction1->parametres = NULL;
    fonction1->nbParametres = 0;
    bool res1 = verifierDeclarationFonction(fonction1);
    printf("verifierDeclarationFonction (addition) : %s\n", res1 ? "true" : "false");
    
    // Test avec un nom de fonction ne commençant pas par une lettre
    Fonction* fonction2 = malloc(sizeof(Fonction));
    fonction2->nom = "_1division";
    fonction2->typeRetour = VOIDE;
    fonction2->parametres = NULL;
    fonction2->nbParametres = 0;
    bool res2 = verifierDeclarationFonction(fonction2);
    printf("verifierDeclarationFonction (1division) : %s\n", res2 ? "true" : "false");

	// Test nombre de paramètres d'une fonction
	Fonction* fonction = malloc(sizeof(Fonction));
	fonction->nom = "maFonction";
	fonction->typeRetour = INTEGER;
	fonction->nbParametres = 2;
	fonction->parametres = malloc(fonction->nbParametres * sizeof(Parametre));

	// Premier paramètre
	fonction->parametres[0].nom = "param1";
	fonction->parametres[0].type = INTEGER;

	// Deuxième paramètre
	fonction->parametres[1].nom = "param2";
	fonction->parametres[1].type = INTARRAY;
	
	// Supposons que nous avons une fonction appelée "maFonction" qui attend 2 paramètres
	printf("\n\n");
	printf("Tester si nombre de param fournis correspond au nombre de param attendus.\n");
	printf("nom fonction tester : %s\n", fonction->nom);
	printf("nombre param attendus : %d\n", fonction->nbParametres);
	printf("param 1 : %s\n", fonction->parametres[0].nom);
	printf("type param 1 : %d\n", fonction->parametres[0].type);
	printf("param 2 : %s\n", fonction->parametres[1].nom);
	printf("type param 2 : %d\n", fonction->parametres[1].type);
	int nombreParametresFournis = 4; // Exemple avec un nombre incorrect de paramètres
	printf("valeur var test pour nb param différents : %d\n", nombreParametresFournis);
	bool estValide = verifierNombreParametres(fonction, nombreParametresFournis);
	if (estValide) {
		printf("Le nombre de paramètres est correct.\n");
	} else {
		printf("Le nombre de paramètres est incorrect.\n");
	}
	
	// Test si un identificateur est un mot clé réservé
	printf("\nTest si un ident porte le nom d'un mot clé ou pas\n");
	char* identificateur = "for";
	bool estMotCle = checkIdentName(identificateur);
	if (!estMotCle) {
		printf("Erreur : l'identificateur '%s' est un mot clé réservé.\n", identificateur);
	} else {
		printf("L'identificateur '%s' n'est pas un mot clé réservé.\n", identificateur);
	}

    // Libération de la mémoire
    libererNoeud(n);
    free(fonction1);
    free(fonction2);
}



void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	testVerifierTypeNoeud();
	/* clearFile();
	while(yyparse()); */
}
#line 698 "y.tab.c"

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
	{yyval.noeud= creerNoeud("PROGRAMME");generateDotFile(yystack.l_mark[0].liste_noeud);}
#line 1371 "y.tab.c"
break;
case 2:
#line 42 "miniC.y"
	{}
#line 1376 "y.tab.c"
break;
case 3:
#line 43 "miniC.y"
	{}
#line 1381 "y.tab.c"
break;
case 4:
#line 46 "miniC.y"
	{yyval.liste_noeud = addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);afficherArbre(yystack.l_mark[0].noeud);}
#line 1386 "y.tab.c"
break;
case 5:
#line 47 "miniC.y"
	{yyval.liste_noeud= creerListeNoeud(yystack.l_mark[0].noeud);afficherArbre(yystack.l_mark[0].noeud);}
#line 1391 "y.tab.c"
break;
case 6:
#line 50 "miniC.y"
	{if(strcmp(yystack.l_mark[-2].noeud->val,"int")==0){
										yyval.noeud = yystack.l_mark[-1].noeud ;
									} else{
										yyerror("Error : Declaration of a non-handled type.");
									}}
#line 1400 "y.tab.c"
break;
case 7:
#line 57 "miniC.y"
	{yyval.noeud= yystack.l_mark[-2].noeud;}
#line 1405 "y.tab.c"
break;
case 8:
#line 58 "miniC.y"
	{yyval.noeud = yystack.l_mark[0].noeud;}
#line 1410 "y.tab.c"
break;
case 9:
#line 61 "miniC.y"
	{}
#line 1415 "y.tab.c"
break;
case 10:
#line 62 "miniC.y"
	{}
#line 1420 "y.tab.c"
break;
case 11:
#line 65 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"%s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = FONCTION;
																								if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0){
																								for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
																										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
																									}
																								}
																								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1434 "y.tab.c"
break;
case 12:
#line 75 "miniC.y"
	{char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"EXTERN %s, %s",yystack.l_mark[-4].id,yystack.l_mark[-5].noeud->val);
																								yyval.noeud= creerNoeud(funcname);
																								yyval.noeud->type = FONCTION;
																								if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0) {
																									for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
																										yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
																									}
																								}}
#line 1447 "y.tab.c"
break;
case 13:
#line 86 "miniC.y"
	{yyval.noeud = creerNoeud("void");}
#line 1452 "y.tab.c"
break;
case 14:
#line 87 "miniC.y"
	{yyval.noeud = creerNoeud("int");}
#line 1457 "y.tab.c"
break;
case 15:
#line 91 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);printf("parms\n");}
#line 1462 "y.tab.c"
break;
case 16:
#line 92 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);printf("liste_parms\n");}
#line 1467 "y.tab.c"
break;
case 17:
#line 93 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1474 "y.tab.c"
break;
case 18:
#line 99 "miniC.y"
	{yyval.noeud = creerNoeud("INT");
							yyval.noeud = appendChild1(yyval.noeud,creerNoeud(yystack.l_mark[0].id));}
#line 1480 "y.tab.c"
break;
case 19:
#line 104 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-1].liste_noeud,yystack.l_mark[0].noeud);}
#line 1485 "y.tab.c"
break;
case 20:
#line 105 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1490 "y.tab.c"
break;
case 21:
#line 108 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1495 "y.tab.c"
break;
case 22:
#line 109 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1500 "y.tab.c"
break;
case 23:
#line 110 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1505 "y.tab.c"
break;
case 24:
#line 111 "miniC.y"
	{yyval.noeud=yystack.l_mark[-1].noeud;}
#line 1510 "y.tab.c"
break;
case 25:
#line 112 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1515 "y.tab.c"
break;
case 26:
#line 113 "miniC.y"
	{yyval.noeud=yystack.l_mark[0].noeud;}
#line 1520 "y.tab.c"
break;
case 27:
#line 116 "miniC.y"
	{yyval.noeud= creerNoeud("FOR");
																			yyval.noeud = appendChild4(yyval.noeud,yystack.l_mark[-6].noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1526 "y.tab.c"
break;
case 28:
#line 118 "miniC.y"
	{yyval.noeud= creerNoeud("WHILE");
											yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1532 "y.tab.c"
break;
case 29:
#line 120 "miniC.y"
	{yyerror("reenter last");
                        yyerrok; }
#line 1538 "y.tab.c"
break;
case 30:
#line 124 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
													yyval.noeud->type = IF;
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1545 "y.tab.c"
break;
case 31:
#line 127 "miniC.y"
	{yyval.noeud= creerNoeud("IF");
															yyval.noeud = appendChild3(yyval.noeud,yystack.l_mark[-4].noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1551 "y.tab.c"
break;
case 32:
#line 129 "miniC.y"
	{yyval.noeud= creerNoeud("SWITCH");
												yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1557 "y.tab.c"
break;
case 33:
#line 131 "miniC.y"
	{yyval.noeud= creerNoeud("CASE");
										noeud* constante = creerNoeud(yystack.l_mark[-2].id);
										yyval.noeud = appendChild2(yyval.noeud,constante,yystack.l_mark[0].noeud);}
#line 1564 "y.tab.c"
break;
case 34:
#line 134 "miniC.y"
	{yyval.noeud= creerNoeud("default");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1570 "y.tab.c"
break;
case 35:
#line 138 "miniC.y"
	{yyval.noeud= creerNoeud("BREAK"); 
					yyval.noeud->type = BREAK;}
#line 1576 "y.tab.c"
break;
case 36:
#line 140 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
					yyval.noeud->type = RETURN;}
#line 1582 "y.tab.c"
break;
case 37:
#line 142 "miniC.y"
	{yyval.noeud= creerNoeud("RETURN");
							yyval.noeud->type = RETURN;
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1589 "y.tab.c"
break;
case 38:
#line 147 "miniC.y"
	{yyval.noeud = creerNoeud(":=");
									yystack.l_mark[0].noeud->type = ARGUMENT;
									yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1596 "y.tab.c"
break;
case 39:
#line 152 "miniC.y"
	{yyval.noeud= creerNoeud("BLOC");
														yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].noeud);
														int lenList = (sizeof(yystack.l_mark[-1].liste_noeud->liste_noeud)/sizeof(yystack.l_mark[-1].liste_noeud->liste_noeud[0]));
														printf("lenList : %d\n",lenList);
														if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
														}
																												printf("TEEEEST\n");
	}}
#line 1610 "y.tab.c"
break;
case 40:
#line 164 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-4].id);
														yyval.noeud->type = APPELFONCTION;
														if (yystack.l_mark[-2].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-2].liste_noeud->nb_noeud; i++){
															yystack.l_mark[-2].liste_noeud->liste_noeud[i]->type = ARGUMENT;
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-2].liste_noeud->liste_noeud[i]);
														}
													}}
#line 1622 "y.tab.c"
break;
case 41:
#line 174 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[0].id);}
#line 1627 "y.tab.c"
break;
case 42:
#line 175 "miniC.y"
	{yyval.noeud = creerNoeud("[]");
									yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1633 "y.tab.c"
break;
case 43:
#line 179 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1638 "y.tab.c"
break;
case 44:
#line 180 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[-1].id);
													yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);}
#line 1644 "y.tab.c"
break;
case 45:
#line 182 "miniC.y"
	{yyval.noeud = creerNoeud("-");
							yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[0].noeud);}
#line 1650 "y.tab.c"
break;
case 46:
#line 184 "miniC.y"
	{yyval.noeud= creerNoeud(yystack.l_mark[0].id);}
#line 1655 "y.tab.c"
break;
case 47:
#line 185 "miniC.y"
	{yyval.noeud = yystack.l_mark[0].noeud;}
#line 1660 "y.tab.c"
break;
case 48:
#line 186 "miniC.y"
	{yyval.noeud = creerNoeud(yystack.l_mark[-3].id);
													yyval.noeud->type = APPELFONCTION;
													if (yystack.l_mark[-1].liste_noeud->nb_noeud > 0){
														for(int i = 0; i < yystack.l_mark[-1].liste_noeud->nb_noeud; i++){
															yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].liste_noeud->liste_noeud[i]);
														}
													}}
#line 1671 "y.tab.c"
break;
case 49:
#line 196 "miniC.y"
	{yyval.liste_noeud=addNoeud(yystack.l_mark[-2].liste_noeud,yystack.l_mark[0].noeud);}
#line 1676 "y.tab.c"
break;
case 50:
#line 197 "miniC.y"
	{yyval.liste_noeud=creerListeNoeud(yystack.l_mark[0].noeud);}
#line 1681 "y.tab.c"
break;
case 51:
#line 198 "miniC.y"
	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		yyval.liste_noeud = f;}
#line 1688 "y.tab.c"
break;
case 52:
#line 204 "miniC.y"
	{yyval.noeud = creerNoeud("NOT");
								yyval.noeud = appendChild1(yyval.noeud,yystack.l_mark[-1].noeud);}
#line 1694 "y.tab.c"
break;
case 53:
#line 206 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1702 "y.tab.c"
break;
case 54:
#line 210 "miniC.y"
	{yyval.noeud = yystack.l_mark[-1].noeud;}
#line 1707 "y.tab.c"
break;
case 55:
#line 211 "miniC.y"
	{
										yyval.noeud = creerNoeud(yystack.l_mark[-1].id);
										yyval.noeud = appendChild2(yyval.noeud,yystack.l_mark[-2].noeud,yystack.l_mark[0].noeud);
	}
#line 1715 "y.tab.c"
break;
case 56:
#line 217 "miniC.y"
	{yyval.id = "+"; }
#line 1720 "y.tab.c"
break;
case 57:
#line 218 "miniC.y"
	{yyval.id = "-"; }
#line 1725 "y.tab.c"
break;
case 58:
#line 219 "miniC.y"
	{yyval.id = "*"; }
#line 1730 "y.tab.c"
break;
case 59:
#line 220 "miniC.y"
	{yyval.id = "/"; }
#line 1735 "y.tab.c"
break;
case 60:
#line 221 "miniC.y"
	{yyval.id = "<<"; }
#line 1740 "y.tab.c"
break;
case 61:
#line 222 "miniC.y"
	{yyval.id = ">>"; }
#line 1745 "y.tab.c"
break;
case 62:
#line 223 "miniC.y"
	{yyval.id = "&="; }
#line 1750 "y.tab.c"
break;
case 63:
#line 224 "miniC.y"
	{yyval.id = "|="; }
#line 1755 "y.tab.c"
break;
case 64:
#line 227 "miniC.y"
	{yyval.id = "&&"; }
#line 1760 "y.tab.c"
break;
case 65:
#line 228 "miniC.y"
	{yyval.id = "||"; }
#line 1765 "y.tab.c"
break;
case 66:
#line 231 "miniC.y"
	{yyval.id = "<"; }
#line 1770 "y.tab.c"
break;
case 67:
#line 232 "miniC.y"
	{yyval.id = ">"; }
#line 1775 "y.tab.c"
break;
case 68:
#line 233 "miniC.y"
	{yyval.id = ">="; }
#line 1780 "y.tab.c"
break;
case 69:
#line 234 "miniC.y"
	{yyval.id = "<="; }
#line 1785 "y.tab.c"
break;
case 70:
#line 235 "miniC.y"
	{yyval.id = "=="; }
#line 1790 "y.tab.c"
break;
case 71:
#line 236 "miniC.y"
	{yyval.id = "!="; }
#line 1795 "y.tab.c"
break;
#line 1797 "y.tab.c"
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
