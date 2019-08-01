#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	int count=0;
	char pri[20];
	int i;
	int mypri;

	if(argc < 3){
		printf(1, "Usage: child <num to count to> <priority>");
		exit();
	}

	mypri = atoi(argv[2]);
	setPriority(mypri);
	count  = (atoi(argv[1]));
	strcpy(pri, argv[2]);

	for(i=1; i<= count; i++){
		printf(1, "priority: %d : %d\n", mypri, i);
	}
	exit();
}
