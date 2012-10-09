OBJS = ~/SecondAssignment/test/test.o
CC = gcc
CFLAGS = -O3 -wall -c ${DEBUG}
LFLAGS = -wall ${DEBUG}
DEBUG = -g
PROFILR = -pg

.PHONY: test test.o run

test: test.o
	$(CC) $(PROFILR) $(LFLAGS) ~/SecondAssignment/test/test.o -o ~/SecondAssignment/test/test

test.o: test.c 	
	$(CC) -o ~/SecondAssignment/test/test.o $(PROFILR) $(CFLAGS) ~/SecondAssignment/test/test.c

run: 
	~/SecondAssignment/test/./test
	
clean:
	rm -rf *.o *~ *.out *.dat test
	@echo "all cleaned up!"