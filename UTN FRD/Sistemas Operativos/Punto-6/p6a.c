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
	
	int contador = 0;
	
	int ite = shmget(0xb, 0 ,0);
	int *dirite = (int *) shmat(ite,0,0);
	printf("Iteraciones en A: %d\n", *dirite);
	
	int semid = semget(0xa, 0, 0);
	
	while(contador < *dirite *2) 
	{
		P(semid,0); //SemA
		printf("A\n");
		contador++;
		sleep(1);
		V(semid, 3); //SemX
	}
	
	exit(0);
}


