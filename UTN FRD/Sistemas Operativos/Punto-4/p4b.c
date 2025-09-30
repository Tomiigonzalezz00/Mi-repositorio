#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>



int main(void)
{
	int ite = shmget(0xb, 0 ,0);
	int *dirite = (int *) shmat(ite,0,0);
	printf("Iteraciones en B: %d\n", *dirite);
	
	sem_t * semA;
	sem_t * semB;
	sem_t * semC;
	sem_t * semX;
	
	semA = sem_open("/semA", 0); //nombre semaforo, 0 no es de inicializacion
	semB = sem_open("/semB", 0);
	semC = sem_open("/semC", 0);
	semX = sem_open("/semX", 0);
	
	int contador =0;
	while(contador < *dirite)
	{
		sem_wait(semB);
		sem_wait(semX);
			printf("procesoB \n");
			contador++;
			sleep(1);
		sem_post(semA);
		sem_post(semC);
		
	}
	
	exit(0);
}
