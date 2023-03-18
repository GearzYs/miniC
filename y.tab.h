#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
	int val;
	char* id;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
