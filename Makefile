LEX = flex
YACC = yacc
CC = gcc


# Fichiers source
LEX_FILE = ANSI-C.l
YACC_FILE = miniC.y
SRC_FILES = lex.yy.c y.tab.c parsingMini.c
NAME = compil
CFLAG = -o
LFLAG = -lfl


# Règles de compilation
all:
	$(YACC) -d miniC.y 
	$(LEX) ANSI-C.l
	$(CC) $(CFLAG) $(NAME) $(SRC_FILES) $(LFLAG)
	./$(NAME) < Tests/test.c

clean:
	rm $(NAME)
