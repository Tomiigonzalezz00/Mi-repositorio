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
	printf("Iteraciones en B: %d\n", *dirite);

	int semid = semget(0xa, 0, 0);
	int contador =0;
		
	while(contador < *dirite)
	{
		P(semid,1); //SemB
		P(semid, 3); //SemX
		printf("B\n");
		contador++;
		sleep(1);
		V(semid, 0); //SemA
		V(semid, 2); //SemC
	}
	
	exit(0);
}
