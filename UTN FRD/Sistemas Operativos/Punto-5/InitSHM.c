#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
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
//Apertura de la memoria compartida
int fd = shm_open("/mishm",O_RDWR,S_IRUSR|S_IWUSR);
if(fd == -1){printf("ERROR shm_open\n");exit(-1) ;} 

//Mapea la memoria compartida posix dentro del espacio de direcciones del proceso pa
struct semaforos *shm = mmap(NULL,sizeof(struct semaforos),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
if(shm==MAP_FAILED) {printf("ERROR mmap\n"); exit(-1) ;}

//Inicializacion de los semafotos posix sin nombre
if(sem_init(&shm->Sa, 1,1) == -1){printf("ERROR sem_init Sa\n"); exit(-1) ;}
if(sem_init(&shm->Sb, 1,0) == -1){printf("ERROR sem_init Sb\n"); exit(-1) ;}
if(sem_init(&shm->Sc, 1,0) == -1){printf("ERROR sem_init Sc\n"); exit(-1) ;}
if(sem_init(&shm->Sx, 1,0) == -1){printf("ERROR sem_init Sx\n"); exit(-1) ;}

printf("Semaforos posix sin nombre inicializados\n");

//Mostramos la cantidad de iteraciones
int ite = shmget(0xb, 0,0);
int *dirite = (int *) shmat(ite, 0,0);
printf("Se repetira el ciclo %d veces\n", *dirite);

exit(0);

}
