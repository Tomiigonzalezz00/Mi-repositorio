#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/shm.h>

//Estructura que se alamcenara en una memoria compartida

struct semaforos
{
	sem_t Sa; //Semaforo POSIX sin nombre a
	sem_t Sb; //Semaforo POSIX sin nombre b
	sem_t Sc; //Semaforo POSIX sin nombre c
	sem_t Sx; //Semaforo POSIX sin nombre x
};



int main(void){
	
int c; // Contador ciclo while
//Cantidad de iteraciones almacenada en la shared memory
int shmIDCont = shmget(0xb,0,0);
int * dirCont = (int *) shmat(shmIDCont, 0, 0);
printf("Iteraciones = %d\n", *dirCont);	

//Apertura de la memoria compartida
int fd = shm_open("/mishm",O_RDWR,S_IRUSR|S_IWUSR);
if(fd == -1){printf("ERROR shm_open\n"); exit(-1) ; }
printf("Proceso a shm_open fd= %d\n",fd);

//Mapea la memoria compartida posix dentro del espacio de direcciones del proceso pa
struct semaforos * shm = mmap(NULL,sizeof(struct semaforos),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
if(shm==MAP_FAILED) {printf("ERROR mmap\n"); exit(-1) ;}

//Sincronizacion
while(c < *dirCont){
	sem_wait(&shm->Sa);
	printf("A\n");
	sleep(1);
	sem_post(&shm->Sb);
	
	sem_wait(&shm->Sx);
	printf("A\n");
	sleep(1);
	sem_post(&shm->Sc);
	c++;
	
}

exit(0);
}
