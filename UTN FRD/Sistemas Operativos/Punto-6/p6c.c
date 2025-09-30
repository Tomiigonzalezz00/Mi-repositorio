#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/sem.h> 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void P(int, int);
void V(int, int);

int main(void)
{
	
	int ite = shmget(0xb, 0 ,0);
	int *dirite = (int *) shmat(ite,0,0);
	printf("Iteraciones en C: %d\n", *dirite);
	
	int semid = semget(0xa, 0, 0);
	int contador =0;
	
	while(contador < *dirite)
	{
		P(semid,2); //Semc
		P(semid, 3); //semX
		printf("C\n");
		contador++;
		sleep(1);
		V(semid, 0); //SemB
		V(semid, 1); //semA
	}
	
	exit(0);
}
