#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	//declare vars
	int count = 0;
	char pri[20];

	//check number of args
	if(argc < 3){
		printf(1, "Usage: child <num to count to> <priority>");
		exit();
	}

	//count to int value of count
	count = (atoi(argv[1]));
	// copy priority to array
	strcpy(pri, argv[2]);
	
	for(int i = 1; i<= count; i++){
		printf(1, "%s : %d\n", pri, i);
		sleep(60);
	}
	exit();
}
