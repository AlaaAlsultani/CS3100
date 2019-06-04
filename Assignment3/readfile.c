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
