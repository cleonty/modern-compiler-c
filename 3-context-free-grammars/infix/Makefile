infix.exe:	infix.tab.c
	gcc -o $@ $^ -lm
infix.tab.c:	infix.y
	bison $^

clean:	
	rm -rf *.tab.c *.o infix.exe
