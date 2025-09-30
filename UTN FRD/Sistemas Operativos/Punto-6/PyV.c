#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 

void P(int semid, int sem) // id del conjunto de semaforos, numero de semaforo
{ 
	struct sembuf buf;
	buf.sem_num = sem; //numero de semaforo
	buf.sem_op = -1; //operacion
	buf.sem_flg = 0;
	semop(semid, &buf, 1); //
}

void V(int semid, int sem)
{
	struct sembuf buf;
	buf.sem_num = sem;
	buf.sem_op = 1;
	buf.sem_flg = 0;
	semop(semid, &buf, 1);
}

//llamada al sistema semop, en P evalua el semaforo y le resta 1 si tiene un valor mayor a cero
//semop en V suma 1 al semaforo. Esta llamada al sistema ejecuta el semaforo

