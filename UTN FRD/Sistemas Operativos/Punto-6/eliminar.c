#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/sem.h> 
#include <sys/types.h>

int main(){

	int shmid = shmget(0xb, 0,0);
	char *dirid = (char *) shmat(shmid,0,0);


	int memauxi;
	
	
	// elimino memoria compartida
	memauxi = shmctl(shmid, IPC_RMID,NULL);
	if (memauxi != -1)
		printf("Memoria eliminada\n");
	else 	
		printf("No se pudo eliminar la memoria\n");
	
	//elimino semaforos
	
	int semid = semget(0xa, 0, 0);
	
	int semauxi;
	
	semauxi = semctl(semid, 0, IPC_RMID);
	
	if (semauxi != -1)
		printf("Semaforos eliminados\n");
	else 
		printf("No se pudieron eliminar los semaforos\n");
	
	exit(0);
}
