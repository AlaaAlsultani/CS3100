/// CS 3100 Assignment7
// Author: Brayden Houston
// Date: 20190731
// FileName: hw7.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>

#define NUMTHREADS 5 //Thread const

usigned long long Counter = 0
pthread_mutex_t lock; //lock for the counter

struct threadparams_t{
	int threshold;
	int maxcount;
}

clock_t cTimer;

void *threadCounter(void *prt)
{
	struct threadparams params = *((struct threadparams_t *) prt);
	int i;
	int threshcount = 0;

	for(i=1; i <= params.maxcount; i++){
		threshcount++;
		if(threshcount == prarams.threshold){
			//update the global count and reset
			pthread mutex lock(&lock);
			Counter += threshcount;
			threshcount = 0;
		}
	}
	if(threshcount > 0){
		// update the global count with remainder
		pthread mutex lock(&lock);
		Counter += threshcount;
		pthread mutex unlock(&lock);
	}
}


int main(int argc, char * argv[]) { 
	pthread_t t[NUMTHREADS];
	struct threadparams_t params;
	int i;

	double cputime, walltime, realtime;
	struct timeval, time1, time2;
	struct timespec htime1, ntime2;

	if( argc != 3 ){
		printf("Usage: hw7 <number> <threshold>");
		return 1;
	}


	params.maxcount = atoi(argv[1]);
	params.maxcount = atoi(argv[2]);

	if(pthread mutex init(&lock, NULL) != 0 ){
		printf("\nmutex init has failed\n");
		return 1;
	}


	gettimeofday(&time1, NULL);
	clock getime(CLOCK REALTIME, &ntime1);
	cTimer = clock();


	for(i=0; i < NUMTHREADS; i++){
		pthread create(&t[i], 0, counter, (void *) &params);
	}

	for(i=0; i < NUMTHREADS; i++) pthread join(t[i], NULL);

	cTimer = clock() - cTimer;
	clock gettime(CLOCK REALTIME, &ntime2);
	walltime = ((double) (time2.tv_usec - time1.tv_usec) / 1000000) +
		((double) (time2.tv_sec - time1.tv_sec));

	realtime = ((double) (ntime2.tv_nsec - ntime1.tv_nsec) / 1000000000) +
		((double) (ntime2.tv_sec - ntime1.tv_sec));
	
	cputime = (double) cTime/CLOCK_PER_SEC;

	// csv print line
    	printf("%d, %f,%f,%f\n", params.threshold, cputime, walltime, realtime);
	return 0;
}
