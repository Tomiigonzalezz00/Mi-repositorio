#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <string.h>  
#include <sys/shm.h>
#include <sys/ipc.h> 

int main(void)
{
	//semaforos
	sem_t * semA;
	sem_t * semB;
	sem_t * semC;
	sem_t * semX;

	int valsemA;
	int valsemB;
	int valsemC;
	int valsemX;
	
	sem_unlink("/semA");
	sem_unlink("/semB");
	sem_unlink("/semC");
	sem_unlink("/semX");
	
	semA = sem_open("/semA", O_CREAT|O_EXCL,0644,1); //nombre semaforo, flags, permisos, inicializacion
	semB = sem_open("/semB", O_CREAT|O_EXCL,0644,1);
	semC = sem_open("/semC", O_CREAT|O_EXCL,0644,0);
	semX = sem_open("/semX", O_CREAT|O_EXCL,0644,0);
	
	sem_getvalue(semA, &valsemA);
	sem_getvalue(semB, &valsemB);
	sem_getvalue(semC, &valsemC);
	sem_getvalue(semX, &valsemX);
	
	printf("/semA = %d \n", valsemA);
	printf("/semB = %d \n", valsemB);
	printf("/semC = %d \n", valsemC);
	printf("/semX = %d \n", valsemX);
	
	//memoria compartida
	
	int iteraciones;
	
	printf("Cantidad de iteraciones: ");
	scanf("%d", &iteraciones);
	
	int shmid = shmget(0xb, sizeof(int), IPC_CREAT|IPC_EXCL|0600);
		
	int ite = shmget(0xb, 0,0);
	
	
	int *dirite = (int *) shmat(ite, 0,0);
	
	*dirite = iteraciones;
	
	printf("Se repetira el ciclo %d veces\n", *dirite);
	
	exit(0);
}

