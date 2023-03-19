LEX = flex
YACC = yacc
CC = gcc


# Fichiers source
LEX_FILE = ANSI-C.l
YACC_FILE = miniC.y
SRC_FILES = lex.yy.c y.tab.c translateDot.c
NAME = compil
CFLAG = -o
LFLAG = -lfl


# Règles de compilation
all:
	$(YAAC) -d miniC.y 
	$(LEX) ANSI-C.l
	$(CC) $(CFLAG) $(NAME) $(SRC_FILES) $(LFLAG)
	./$(NAME) < Tests/add.c

clean:
	rm $(NAME)
