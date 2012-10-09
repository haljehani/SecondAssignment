/****************************************************
 *        Matrix Multiplication Using Pthread       *
 ****************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
void testCheckDim();
int checkDim(int cA, int rB);

int main()
{	
	testCheckDim();
	return 0;
}

void testCheckDim()
{
	if(checkDim(3,3)!=1)
		printf("not pass when they are equal\n");
	else 
		printf("pass when they are equal\n");
	
	
	
	if(checkDim(3,4)!=0)
		printf("not pass when they are not equal\n");
	else 
		printf("pass when they are not equal\n");
}

int checkDim(int cA, int rB)
{
    if(cA!=rB)
		return 0;
	else 
		return 1;
}
