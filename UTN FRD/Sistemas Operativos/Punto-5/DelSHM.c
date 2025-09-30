#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/shm.h>

int main(void){
//Realiza remove de la memoria compartida posix "/mishm" si existe

if(shm_unlink("/mishm")==-1)
	printf("Memoria compartida de semaforos Posix NO Existe\n");
else
	printf("Memoria compartida de semaforos Posix ELIMINADA\n");
	
// Elimino memoria compartida de iteraciones
int shmid = shmget(0xb, 0,0);
if (shmctl(shmid, IPC_RMID,NULL) != -1)
		printf("Memoria de iteraciones eliminada\n");
else 	
		printf("No se pudo eliminar la memoria de iteraciones\n");

exit(0);
}

