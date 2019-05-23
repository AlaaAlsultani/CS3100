#include "stack.h"
#include <stdio.h>

int main(void){
	stackT *A, *B, *C; // stacks to be used in this test program
	bool b; // boolean variable declared from enumerated type in stack.h
    char arr1[] = {'R','A','C','E','C','A','R'};  // an array of values used later
    int i; // a loop control variable used to place the array values into a stack
	
    printf("Welcome to CS 3100!\n");
    printf("Creating a new stack.\n");
    A = NewStack();
    printf("Pushing 'M' onto the stack.\n");
    Push(A,'M');
    printf("Pushing 'O' onto the stack.\n");
    Push(A,'O');
    printf("Pushing 'P' onto the stack.\n");
    Push(A,'P');
    printf("Popping, the result should be a 'P': %c\n", Pop(A));
    printf("Popping, the result should be a 'O': %c\n", Pop(A));
    printf("Popping, the result should be a 'M': %c\n", Pop(A));
    printf("Popping from an empty stack.   The result should be an empty space");
	printf("and I should have just gotten an error: %c\n", Pop(A));

    printf("Checking to see if the stack is empty now.\n");
    b = IsEmpty(A);
    if (b == true){
        printf("The stack is empty. Now I am going to call FreeStack on it.\n");
    }
    else{
        printf("Oh, dear. We have a problem. The stack should be empty now. ");
		printf("I wonder, can I call FreeStack on it anyway?\n");
    }
    FreeStack(A);


    printf("\nCreating another stack.\n");
    B = NewStack();
    
    b = IsEmpty(B);
    if (b == true){
        printf("(PASS) The new stack is empty. That is good.\n");
    }
    else{
        printf("(FAIL) The new stack is not empty. That is not good.\n");
    }

    printf("Filling the new stack up with information.\n");
    for(i = 0; i < 7; i++){
        Push(B,arr1[i]);
    }
    b = IsEmpty(B);
    if (b == true){
        printf("(FAIL) The stack is empty. That is not good.\n");
    }
    else{
        printf("(PASS) The stack is not empty. That is good.\n");
    }

    printf("Can we free a non-empty stack? Let's try. We should get an error.\n");
    FreeStack(B);

    printf("\nHopefully that caused a problem. Let's empty the stack then try to free it.\n");
    EmptyStack(B);
    printf("What happens when we Pop from an empty stack? We should get an error:\n");
    valueT temp = Pop(B);
    FreeStack(B);

    printf("\nCreating a third stack.\n");
    C = NewStack();

    char arr2[] = {'G','o','o','d'};
    printf("Filling the third stack up with information.\n");
    for(i = 0; i < 4; i++){
        Push(C,arr2[i]);
    }
    printf("Now let's empty it and print out the result: (It should be \"dooG\"):");
    for(i = 0; i < 4; i++){
        valueT val = Pop(C);
        printf("%c",val);
    }
    printf("\nNow, let's free the stack and be finished.\n");
    FreeStack(C);
}
