mfcalc.exe:	mfcalc.tab.c
	gcc -o $@ $^ -lm
mfcalc.tab.c:	mfcalc.y
	bison $^

clean:	
	rm -rf *.tab.c *.o mfcalc.exe
