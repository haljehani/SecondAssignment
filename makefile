OBJS = ~/SecondAssignment/obj/SecondProject.o
CC = gcc
CFLAGS = -O3 -wall -c $(OBJS)
LFLAGS = -wall $(OBJS)
DEBUG = -g
PROFILR = -pg
ROW1 = 
COL1 = 
ROW2 = 
COL2 =

SecondProject: ${OBJS}
	${CC} ${DEBUG} ${PROFILR} -o SecondProject ${CFLAGS} ${OBJS}
      
SecondProject.o: ~/SecondAssignment/src/SecondProject.c 	
	$(CC) ${DEBUG} ${PROFILR} -o SecondProject ${CFLAGS}; ~/SecondAssignment/./SecondProject ${ROW1} ${COL1} ${ROW2} ${COL2}

profile:
	

clean:
      rm -f SecondProject ${OBJS}
      @echo "all cleaned up!"