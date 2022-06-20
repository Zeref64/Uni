all:
	clear
	bison -d bison.y --verbose
	flex flex.l
	gcc bison.tab.c lex.yy.c -o executable
	./executable inputtest.txt
clean:
	rm bison.tab.c bison.tab.h lex.yy.c executable
