CC=gcc
YC=yacc
FL=flex

TARGET=compil

all: compile run

compile:
	$(YC) -d miniC.y 
	$(FL) ANSI-C.l
	$(CC) -o $(TARGET) lex.yy.c y.tab.c parsingMini.c -lfl 

run:
	./$(TARGET) < Tests/$(FILE).c
	dot -Tpdf ./arbre.dot -o ./PdfFiles/$(FILE).pdf
	mv arbre.dot ./DotFiles/$(FILE).dot

clean:
	rm $(TARGET)
	rm DOT.dot