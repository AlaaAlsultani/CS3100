# THIS IS A LINUX ASSIGNMENT  NOT AN Xv6 Assignment.
## Forks

Objective: To understand fork, exec, and pipes.

This document should help you with Making a Makefile.docx

Example program and data:   hw3example.zip  which will only work on Linux. To unzip, type "unzip hw3example.zip"  (NOTE: you only need to include wall or CPU time in your program.)

 

The idea is for you to create a program that reads a binary random access file and finds the min and max. Your program will either use one process or it will use four processes (parallel computing) to achieve the answer. In order for your forked processes to work they must use pipes.

 

Instructions:

- Create at least two c programs to complete the following:
  - From the command prompt the user will run the following: "hw3 numForks fileName"
    - "numForks" can only be "1" or "4" - it indicates the number of processes that will be run.
    - "fileName" is the name of the binary random access file that will be used, generated by a program below.
  - If "1" is entered then the program calls exec on another c program that will return the max and min of the file to the user.
  - if "4" is entered then the program calls fork an appropriate number of times and calls exec on another program the appropriate times and ways and will return the max and min of the file to the user. Your program will need to use pipes to communicate between forked processes.
  - Regardless of "1" or "4" being entered, the program will report how much time it took to process the file.
- When the program runs your name is printed out.
- The first c program will take care of the command line arguments and possibly deal with forking.
- A second c program will actually figure out the min and max from the file.
- A third, fourth, fifth, etc. c programs may be created, but use caution to not confuse yourself.
- Create a Makefile that compiles all of your c programs when the user types 'make' from the command prompt. If your programs do not compile with 'make' then you get zero points.

The grader will create a random access binary file that he will use for grading all assignments. The code that he will use is at the bottom of this page.

### Deliverable:

Zip up all you files, including the Makefile, and submit it to Canvas by the due date.

 Tips:

- Start early.
- Get the write program (see below) working first
- Get the read program (see below) working next.
- Make the minMax program.
- Get the Makefile to work.
- Get exec to work.
- Get fork to work.
- Learn. Live. Love. :)

#### Note 1:

We will be using Linux as the target grading system. However, You may use other environments for development, but they may not work the same as your Linux virtual machine.

#### Note 2:

The input file size is not determined. The grader may have 5 numbers in the file or five trillion.

#### The code used for generating the file:

```c
/*
 * This file generates a binary output file containing integers. It
 * requires the output filename as a parameter and will take an 
 * argument indicating the number of values to generate as input.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BIAS 0 // a bias value added to the numbers to "bias" the file 
               // contents to provide an offset to the min and max

 int main(int argc, char * argv[]) {
    const char * filename;   // name of the output file
    FILE * ft;               // file handle for output file
    int numtogen = 1000000;  // default is to generate 1,000,000 numbers
    int randomnum, i; // variables used in the loop generating numbers
   
    if (argc<2) {  // not enough arguments, need output file name
        printf("Usage: gendata <filename> [number of numbers]\n");
        return 1;
    }
    if (argc == 3)  // optional third argument for number of numbers 
        numtogen = atoi(argv[2]);
   
    filename=argv[1];  // use the filename entered to store numbers
    srand(time(NULL)); // seed the random number generator
    ft= fopen(filename, "wb") ;
    if (ft) {
        for (i = 0; i < numtogen; i++){
            randomnum = rand() % numtogen + BIAS;
            fwrite(&randomnum,sizeof(int),1,ft);
        }
        fclose(ft);
	}
	return 0;
}
```

#### Example code of how to read from the file:
```c
/*
 * This is a sample program, showing how to read the file.  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

 int main(int argc, char * argv[]) {
	const char * filename;  // name of file to read
	FILE * ft;  // file handle for the file
	int pid,    // process id of this process
	    num,    // the number of integer values in the file
	    i,      // loop control variable for reading values
	    temp=0; // used to store each value read from the file
	long size;  // size in bytes of the input file
/*********************************************************************/
   
    if (argc<2) {  // not enough arguments, need output file name
        printf("Usage: readfile <filename>\n");
        return 1;
    }
    filename = argv[1];  // read the file named on the command line
	
	ft= fopen(filename, "rb") ;
	if (ft) {
		pid = getpid();
		fseek (ft,0,SEEK_END); //go to end of file
		size = ftell(ft);      //what byte in file am I at?
		fseek (ft,0,SEEK_SET); //go to beginning of file
		num = (int)size / (int)sizeof(int); // number of integer values
		printf("file size: %li bytes\n", size);
		printf("sizeof(int) = %i bytes\n",(int) sizeof(int));
		printf("how many integers = %i\n\n", num);
		// now read and print out the values
		for(i = 0; i < num; i++){
			fread(&temp,sizeof(int),1,ft);
			printf("%5i: %7i  ",pid,temp);
			if ((i+1)%5 == 0) 
				printf("\n");
		}
		fclose(ft);  // close the file now that we're done
	}
	printf("\n");  // only have a tab on last line so newline
	return 0;
}
```

#### Example of exec and pipe:
Program that will be called using exec named "printstuff":
```c
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
```

Exec example (calls the above program):
```c
/*
 * This program creates a child process that it communicates
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int cp[2];     // integer array for the pipes
    int pid = 0;   // process id of this proccess
    char ch;       // character read from the pipe
	
    printf("This is before the fork.\n");
    if (pipe(cp) < 0) {
	printf("didn't work, couldn't not establish pipe.\n");
	return -1;
    }

    pid = fork();
    if (pid == 0) {
	printf("this is the child. not the original\n");
	close(1);       //close stdout
	dup2(cp[1], 1); //move stdout to pipe of cp[1]
	close(0);       //close stdin
	close(cp[0]);   //close pipe in 
	//note: All the arguments in exec have to be strings.
	// with an extra null string to end the args
	execl("printstuff","printstuff", "5",(char *) 0);  
    } else {
	close(cp[1]); //if you don't close this part of the pipe 
	        // then the while loop (three lines down) will never return
	printf("this is the parent. the 'original.'\n");
	while( read(cp[0], &ch, 1) == 1) {
            printf("%c",ch);
    	    //write(1, &ch, 1);
   	    //outcount++;
	}
	printf("all done.\n");
	//execl("printstuff","printstuff", "10",(char *) 0);
    }
    printf("This is after the fork.\n");
    return 0;
}
```