all: build

build: parser lexer
	clang -Wall -o one ast.c print.c\
						   lex.yy.c parser.tab.c\
						   -lfl -lstdc++

lexer: lexer.l
	flex lexer.l

parser: parser.y
	bison -d parser.y

clean:
	rm lex.yy.c parser.tab.c parser.tab.h one
