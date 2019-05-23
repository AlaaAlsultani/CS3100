// CS 3100 Assignment2
// Author: Brayden Houston
// Date: 20190522
// FileName: test.c 

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){

	int fd;
	printf(1, "My name is Brayden!\n");

	// Create file tom.txt
	fd = open ("tim.txt", O_CREATE | O_RDWR );
	// Write 1234 to file
	write(fd, "1 2 3 4\n", 9);
	close(fd);
	exit();
}

