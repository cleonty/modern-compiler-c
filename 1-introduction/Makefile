CC:=gcc

slp.exe: main.o prog1.o slp.o util.o maxargs.o
	$(CC) -g main.o prog1.o slp.o maxargs.o util.o -o $@

main.o: main.c slp.h util.h
	$(CC) -g -c main.c

maxargs.o: maxargs.c slp.h util.h
	$(CC) -g -c maxargs.c

prog1.o: prog1.c slp.h util.h
	$(CC) -g -c prog1.c

slp.o: slp.c slp.h util.h
	$(CC) -g -c slp.c

util.o: util.c util.h
	$(CC) -g -c util.c

clean: 
	rm -f slp.exe util.o prog1.o slp.o main.o maxargs.o
