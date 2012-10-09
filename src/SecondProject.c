/****************************************************
 *        Matrix Multiplication Using Pthread       *
 ****************************************************/ 

#include "SecondProject.h"


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
	
	// Take the Argument from the Terminal
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
	
    
	// Call Function to Allocate Memory
    mallocMatrix(&A, rA, cA);
    mallocMatrix(&B, rB, cB);
    mallocMatrix(&C, rA, cB);
	
	// Call Function to Initialize random generator
	initrandom();
	
    // Call Function to Generate matrices
	generateMatrix(A, rA, cA);
    generateMatrix(B, rB, cB);
	
	
	gettimeofday(&start,NULL);
	// For loop for rows start from 0 until rA
	
	Mulitiplication(A, B, C, rA, rB, cB);
	
	gettimeofday(&stop,NULL);
	
	elapsed = 1000000 * (stop.tv_sec - start.tv_sec);
	elapsed += stop.tv_usec - start.tv_usec;
	
	// time in usecs
	printf ("Time: %lu;\t", elapsed);
	// performance in MFLOPS
	printf("performance: %lu\n", (unsigned long)((((TYPE)rA)*((TYPE)cA)*((TYPE)cB)*2)/elapsed));
	
	// Call Function to Print matrice C
	prnMatrix(C, rA, cB);
	
	//free(A);
	//free(B);
	//free(C);
	
	return (0);
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Function to Allocate Memory
void mallocMatrix(TYPE ***A, int rA, int cA)
{
    int z;
    *A= malloc (rA* sizeof(TYPE*));
	for (z=0; z<rA; z++)
        (*A)[z]=(TYPE*)malloc(cA * sizeof(TYPE));
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Function to Initialize random generator
void initrandom(void)
{
    //Variables
    time_t ltime;
	
    //Code of the Function
    time(&ltime);
    ltime%=10000;
    srand(ltime);
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Function Generation of matrices
void generateMatrix(TYPE **A, int rA, int cA)
{
    int i, j;
    
    for(i=0; i<rA; i++)
        for(j=0;j<cA;j++)
			A[i][j]=rnd_int(100);	// Random number from 0 to 100
	//A[i][j]=1.5;
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Function Generate random numbers
TYPE rnd_int(int i)
{
	//Variables
    TYPE num;
    TYPE denum = RAND_MAX+1.0;
    TYPE res;
	
	//Code of the Function
    num = (TYPE) rand();
    res =(TYPE) i*(num/denum);
    return(res);
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Function to Print matrices
void prnMatrix(TYPE **A, int rA, int cA)
{
    //Variables
    int i,j;  // counters
    
    //Code of the Function
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
    //Variables
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