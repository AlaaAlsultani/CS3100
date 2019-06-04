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
