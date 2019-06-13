// CS 3100 Assignment3
// Author: Brayden Houston
// Date: 20190610
// FileName: fork.c

/*
 * This program creates a child process that it communicates
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    const char * filename;  // name of file to read 
    int forks;
    int cp[4][2];     // integer array for the pipes
    int pid = 0;   // process id of this proccess
    char ch;       // character read from the pipe

if ( argc < 3 ) {  // not enough arguments, need output file name
	printf("Usage: fork <# of forks (1 or 4)> <filename>\n");
        return 1;
}

forks =  strtol(argv[1], NULL, 10); // # of forks to be used
filename = argv[2];  // read the file named on the command line

if( forks != 1 && forks != 4 ){
	printf("Invalid number of forks-must be 1 or 4!");	
	return -1;
}

if( filename == "" ){
	printf("No file provided!");	
	return -1;
}
	
for(int i = 1; i <= forks; i++){ 
    printf("This is before the fork.\n");
    if (pipe(cp[i]) < 0) {
	printf("didn't work, couldn't not establish pipe.\n");
	return -1;
    }

    pid = fork();
    if (pid == 0) {
	printf("this is the child. not the original\n");
	close(1);       //close stdout
	dup2(cp[i][1], 1); //move stdout to pipe of cp[1]
	close(0);       //close stdin
	close(cp[i][0]);   //close pipe in 
	//note: All the arguments in exec have to be strings.
	// with an extra null string to end the args
	execl("hw3", "hw3", filename,(char *) 0);  
    } else {
	close(cp[i][1]); //if you don't close this part of the pipe 
	        // then the while loop (three lines down) will never return
	printf("this is the parent. the 'original.'\n");
	while( read(cp[i][0], &ch, 1) == 1) {
            printf("%c",ch);
    	    //write(1, &ch, 1);
   	    //outcount++;
	}
	printf("all done.\n");
	//execl("printstuff","printstuff", "10",(char *) 0);
    }
}
    printf("This is after the fork.\n");
    return 0;
}
