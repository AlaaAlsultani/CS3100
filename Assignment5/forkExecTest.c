#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	char *argvector[4];
	char arg1Temp[20];
	int id;

	if(argc < 2){
		printf(1, "Usage: forkExecTest num of forks\n");
		exit();
	}

	argvector[0] = "child";
	strcpy(arg1Temp, argv[1]);
	argvector[1] = arg1Temp;
	argvector[3] = (char*) 0;

	for(int i = 0; i < 2; i++){
		if( i == 0 ){
			argvector[2] = "lowPriority";
		}
		else{
			argvector[2] = "highPriority";
		}
		id = fork();

		if( id == 0 ){
			exec("child", argvector);
		}
	}

	for(int i=0; i < 2; i++){
		wait();
	}

	exit();
}
