rpn.exe:	rpn.tab.c
	gcc -o $@ $^ -lm
rpn.tab.c:	rpn.y
	bison $^

clean:	
	rm -rf rpn.tab.c *.o rpn.exe
