Compiler: lex.l syntax.y
	flex lex.l
	bison -d syntax.y
	gcc -o izlez syntax.tab.c main.c Fun.c hash.c -lfl -ly -w
clean:
	rm -f izlez *.yy.c *.tab.h *.tab.c
