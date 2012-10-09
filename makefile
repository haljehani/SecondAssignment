OBJS = ../SecondAssignment/obj/SecondProject.o
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
	$(CC) $(PROFILR) $(LFLAGS) ../SecondAssignment/obj/SecondProject.o -o ../SecondAssignment/etc/SecondProject
      
SecondProject.o: ../SecondAssignment/src/SecondProject.c 	
	$(CC) -o ../SecondAssignment/obj/SecondProject.o $(PROFILR) $(CFLAGS) ../SecondAssignment/src/SecondProject.c

run: 
	../SecondAssignment/obj/./SecondProject ${ROW1} ${COL1} ${ROW2} ${COL2}

profile:
	$(CC) $(PROFILR) $(LFLAGS) ../SecondAssignment/obj/SecondProject.o -o ../SecondAssignment/etc/SecondProject; $(CC) -o ../SecondAssignment/obj/SecondProject.o $(PROFILR) $(CFLAGS) ../SecondAssignment/src/SecondProject.c; ../SecondAssignment/obj/./SecondProject ${ROW1} ${COL1} ${ROW2} ${COL2}; gprof ../SecondAssignment/etc/ > SecondProject.dat

clean:
	rm -rf ./obj/*.o *~ *.out *.dat ./etc/SecondProject*
	@echo "all cleaned up!"