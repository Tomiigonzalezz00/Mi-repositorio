#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 

int main (void)
{
		int semid = semget(0xa, 0,0);
		if (semid != -1)
			{
				printf("semA = %d\n", semctl(semid,0,GETVAL));
				printf("semB = %d\n", semctl(semid,1,GETVAL));
				printf("semc = %d\n", semctl(semid,2,GETVAL));
				printf("semx = %d\n", semctl(semid,3,GETVAL));
			}
		else 
			printf("Error semget\n");
		exit(0);
}
