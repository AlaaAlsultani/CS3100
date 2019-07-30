/// CS 3100 Assignment6
// Author: Brayden Houston
// Date: 20190729
// FileName: hw6.c

/*
 * This is a sample program, showing how to read the file.  
 */
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define MAXTHREADS 100


void *threadPrintName(void *arg)
{
    printf("\nMy name is Brayden\n");
}

void *threadFib(void *prt){
	int i = *((int *) prt );

	int fib(int n){
		if(n==0){
			return 0;
		}
		else if(n==1){
			return 1;
		}
		else{
			return (fib(n-1) + fib(n-2));
		}
	}

	if( i < 0 ){
		printf("\nError: Fibonacci is not defined for negitives.\n");
	}
	else{
		printf("\nFibonacci Number %d is: %d", i, fib(i));
	}
}


int getSelection(){
	int select = 0;
	
	printf("\n1) Print out my name\n2) Find the i-th Fibonacci number\n3) Exit");
	printf("\nEnter selection: ");
   	scanf("%d", &select);
	return select;
}

int main(int argc, char * argv[]) { 
	int select;
	int i;
	pthread_t thread[MAXTHREADS];
	pthread_t *t = thread;

	printf("Welcome!\n");
	while ( ( select = getSelection() ) != 3 ){
		
		switch(select){
			case 1:
        			pthread_create(t, NULL, threadPrintName, &select);
				t++;
				break;
			case 2:
				printf("\nPlease enter i for the Fibonacci series: ");
				scanf("%d", &i);
        			pthread_create(t, NULL, threadFib, &i);
				t++;
				break;
		}
	}
    	printf("\nGoodbye\n");
	return 0;
}
