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

SecondProject: SecondProject.o
	$(CC) $(PROFILR) $(LFLAGS) ../SecondAssignment/obj/SecondProject.o -o ../SecondAssignment/etc/SecondProject
      
SecondProject.o: ../SecondAssignment/src/SecondProject.c 	
	$(CC) -o ../SecondAssignment/obj/SecondProject.o $(PROFILR) $(CFLAGS) ../SecondAssignment/src/SecondProject.c

run: 
	../SecondAssignment/obj/./SecondProject ${ROW1} ${COL1} ${ROW2} ${COL2}

#profile:
########	

#clean:
       #rm -rf *o *~ *out *dat SecondProject
#      @echo "all cleaned up!"