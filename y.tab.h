#ifndef _yy_defines_h_
#define _yy_defines_h_

#define IDENTIFICATEUR 257
#define CONSTANTE 258
#define VOID 259
#define INT 260
#define FOR 261
#define WHILE 262
#define IF 263
#define ELSE 264
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define BREAK 268
#define RETURN 269
#define PLUS 270
#define MOINS 271
#define MUL 272
#define DIV 273
#define LSHIFT 274
#define RSHIFT 275
#define BAND 276
#define BOR 277
#define LAND 278
#define LOR 279
#define LT 280
#define GT 281
#define GEQ 282
#define LEQ 283
#define EQ 284
#define NEQ 285
#define NOT 286
#define EXTERN 287
#define THEN 288
#define OP 289
#define REL 290
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	char* val;
	char *string;
	int integer;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
