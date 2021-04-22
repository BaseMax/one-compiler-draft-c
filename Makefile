all: build

build: parser lexer
	gcc -o one ast.c print.c\
						   lex.yy.c parser.tab.c\
						   one.c\
						   -lfl  -lm -g  -w -Wno-psabi
						   #-fsanitize=address

lexer: lexer.l
	flex lexer.l

parser: parser.y
	bison -d parser.y

clean:
	rm lex.yy.c parser.tab.c parser.tab.h one
