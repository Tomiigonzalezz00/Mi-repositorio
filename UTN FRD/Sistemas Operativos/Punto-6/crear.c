#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 
#include <sys/shm.h>

int main(void)
{
	int semid = semget(0xa,4,IPC_CREAT|IPC_EXCL|0600);
	if (errno == EEXIST)
		printf("ya existe un semaforo para esa direccion 0xa \n");
	else 
		printf("Semid = %d\n",semid);
		
	//////////////////	
		
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
