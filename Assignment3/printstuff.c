/*
* This program prints all the natural numbers less than the 
* number passed as a parameter
*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i; // used as a for-loop control variable 
    int max; // the integer value of the first parameter

    printf("Number of command line arguments, argc = %d\n",argc);
    printf("The zeroeth argument, the program name, argv[0] = %s\n",argv[0]); 
    if (argc != 2) {
        printf("Incorrect number of arguments, you must pass in a number.\n");
        return -1;
    } else {
        printf("The first argument, a string value: %s\n",argv[1]);
    }
    max = atoi(argv[1]); // convert the string to an integer
    for(i = 0; i < max; i++) {
        printf("%5i\t",i);
        if((i+1)%10 == 0)
            printf("\n");
    }
    printf("\n");
    return 5;
}
