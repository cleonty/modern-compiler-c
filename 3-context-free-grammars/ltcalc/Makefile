ltcalc.exe:	ltcalc.tab.c
	gcc -o $@ $^ -lm
ltcalc.tab.c:	ltcalc.y
	bison $^

clean:	
	rm -rf *.tab.c *.o ltcalc.exe
