#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

//Estructura que se alamcenara en una memoria compartida

struct semaforos
{
	sem_t Sa; //Semaforo POSIX sin nombre a
	sem_t Sb; //Semaforo POSIX sin nombre b
	sem_t Sc; //Semaforo POSIX sin nombre c
	sem_t Sx; //Semaforo POSIX sin nombre x
};



int main(void){

//Crea la memoria compartida para almacenar la estructura de semaforos
int fd = shm_open("/mishm", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
if(fd == -1){printf("ERROR shm_open\n"); exit(-1); }

//Ajusta el tamaño de la memoria compartida al tamaño de la estructura de los semaforos

if(ftruncate(fd, sizeof(struct semaforos))==-1) {printf("ERROR ftruncate\n"); exit(-1) ;}

printf("Memoria compartida posix creada\n");

// Guardamos la cantidad de iteraciones en memoria compartida

int iteraciones;
	
printf("Cantidad de iteraciones: ");
scanf("%d", &iteraciones);
	 
int ite = shmget(0xb, sizeof(int), IPC_CREAT|IPC_EXCL|0600);
int *dirite = (int *) shmat(ite, 0,0);

*dirite = iteraciones;

exit(0);

}
