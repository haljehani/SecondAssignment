/****************************************************
 *        Matrix Multiplication Using Pthread       *
 ****************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define TYPE float

void initrandom(void);
void generateMatrix(TYPE **A, int rA, int cA);
void mallocMatrix(TYPE ***A, int rA, int cA);
void prnMatrix(TYPE **A, int rA, int cA);
void Mulitiplication(TYPE **A, TYPE **B, TYPE **C, int rA,int rB, int cB);
TYPE rnd_int(int i);


/**************************************************************************************/

int main(int argc, char * argv[])
{
	struct timeval start;
    struct timeval stop;
    unsigned long elapsed;
	
    int rA, cA, rB, cB;
	int numRow, numCol, j, k, i;
	int threadNum;
	void *status;
	
	TYPE **A, **B, **C;
	
	
	rA=atoi(argv[1]);
	cA=atoi(argv[2]);
	rB=atoi(argv[3]);
	cB=atoi(argv[4]);
	
	//*******************************************
	
    
	if(cA!=rB)
    {
        printf("\n******* Wrong input N*M and M*K *******\n");
        exit(0);
    }
	
	//********************************************
	
    
	
    mallocMatrix(&A, rA, cA);
    mallocMatrix(&B, rB, cB);
    mallocMatrix(&C, rA, cB);
	
	
	initrandom();
	
    
	generateMatrix(A, rA, cA);
    generateMatrix(B, rB, cB);
	
	
	gettimeofday(&start,NULL);
	
	
	Mulitiplication(A, B, C, rA, rB, cB);
	
	gettimeofday(&stop,NULL);
	
	elapsed = 1000000 * (stop.tv_sec - start.tv_sec);
	elapsed += stop.tv_usec - start.tv_usec;
	
	
	printf ("Time: %lu;\t", elapsed);
	
	printf("performance: %lu\n", (unsigned long)((((TYPE)rA)*((TYPE)cA)*((TYPE)cB)*2)/elapsed));
	
	
	prnMatrix(C, rA, cB);
	
	//free(A);
	//free(B);
	//free(C);
	
	return (0);
}
//--------------------------------------------------------------


//--------------------------------------------------------------

void mallocMatrix(TYPE ***A, int rA, int cA)
{
    int z;
    *A= malloc (rA* sizeof(TYPE*));
	for (z=0; z<rA; z++)
        (*A)[z]=(TYPE*)malloc(cA * sizeof(TYPE));
}
//--------------------------------------------------------------


//--------------------------------------------------------------

void initrandom(void)
{
    
    time_t ltime;
	
    
    time(&ltime);
    ltime%=10000;
    srand(ltime);
}
//--------------------------------------------------------------


//--------------------------------------------------------------

void generateMatrix(TYPE **A, int rA, int cA)
{
    int i, j;
    
    for(i=0; i<rA; i++)
        for(j=0;j<cA;j++)
			A[i][j]=rnd_int(100);	
	//A[i][j]=1.5;
}
//--------------------------------------------------------------


//--------------------------------------------------------------

TYPE rnd_int(int i)
{
    TYPE num;
    TYPE denum = RAND_MAX+1.0;
    TYPE res;
	
    num = (TYPE) rand();
    res =(TYPE) i*(num/denum);
    return(res);
}
//--------------------------------------------------------------


//--------------------------------------------------------------

void prnMatrix(TYPE **A, int rA, int cA)
{
    
    int i,j;  
    
    
    for (i=0; i<rA; i++)
    {
        for (j=0; j<cA; j++)
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//--------------------------------------------------------------


//--------------------------------------------------------------
void Mulitiplication(TYPE **A, TYPE ** B, TYPE ** C, int rA, int rB, int cB)
{
    
    int i,j,k;
	TYPE result;
    //result=0.0;
	
	for (i=0; i<rA; i++)
	{
		for (j=0; j<cB; j++)
		{
		    for (k=0; k<rB; k++)
			{
				C[i][j]= C[i][j] + A[i][k]*B[k][i];
			}
		}	
		
	}	
	
}
//--------------------------------------------------------------