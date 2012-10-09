OBJS = ~/SecondAssignment/obj/SecondProject.o
CC = gcc
CFLAGS = -O3 -wall -c ${DEBUG}
LFLAGS = -wall ${DEBUG}
DEBUG = -g
PROFILR = -pg
ROW1 = 
COL1 = 
ROW2 = 
COL2 =

.PHONY: SecondProject SecondProject.o run profile clean

SecondProject: SecondProject.o
	$(CC) $(PROFILR) $(LFLAGS) ~/SecondAssignment/obj/SecondProject.o -o ~/SecondAssignment/etc/SecondProject
      
SecondProject.o: ~/SecondAssignment/src/SecondProject.c 	
	$(CC) -o ~/SecondAssignment/obj/SecondProject.o $(PROFILR) $(CFLAGS) ~/SecondAssignment/src/SecondProject.c

run: 
	~/SecondAssignment/etc/./SecondProject ${ROW1} ${COL1} ${ROW2} ${COL2}

profile:
	$(CC) $(PROFILR) -o ~/SecondAssignment/etc/profileInfo ~/SecondAssignment/obj/SecondProject.o ; ~/SecondAssignment/etc/./profileInfo ; gprof ~/SecondAssignment/etc/profileInfo > ~/SecondAssignment/etc/profileInfo.dat ; cd ~/SecondAssignment/etc ; gedit profileInfo.dat

clean:
	rm -rf ./obj/*.o *~ *.out ./etc/*.dat ./etc/SecondProject* ./etc/profileInfo*
	@echo "all cleaned up!"
	
test: ~/SecondAssignment/test/test.o
	cd ~/SecondAssignment/test ; make ; make run