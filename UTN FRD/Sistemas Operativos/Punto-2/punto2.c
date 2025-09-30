/*Implementar un proceso al cual se le indique por línea de comando la cantidad de procesos a crear, todos los procesos a crear 
 * serán hermanos; cada uno de ellos retornará un valor entero distinto al proceso padre. Los procesos hijos quedan en un loop eterno, 
 * en una espera no activa, cuando recibe la señal SIGUSR1 o SIGINT el proceso hijo termina retornando un valor entero distinto al de sus 
 * hermanos. El proceso padre reportará por pantalla la sumatoria de los retornos de los procesos hijos creados. No se permitirá que existan 
 * procesos huérfanos o zombies.*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void handler(int);
void handlerpadre(int);

pid_t pid;	
int sum = 0;
int retorno = 1;
int status =0;
	

int main(int argc, char *argv[])
{
	int cant_procesos = atoi(argv[1]); //Convierto a tipo Integer el valor pasado por linea de comando

	signal(SIGUSR1, handlerpadre);
	signal(SIGINT, handlerpadre);
	
	for (int i = 0; i < cant_procesos; i++) 
	{
		pid = fork();		
		if (pid == 0) //hijo
			{
				signal(SIGUSR1, handler);
				signal(SIGINT, handler);
				
				printf("Hijo pausado. Mi pid es %d, mi padre es %d. Retorno %d\n", getpid(), getppid(), retorno);
				
				pause(); //para el ciclo sin espera activa
			}
					
		retorno++;
	}
	
	
	while (wait(&status) != -1) {
		//printf("wexit %d\n", (status/256));
		sum += status/256;	
		}
	
	printf("------------------------------------------------------------\n");	
	printf("SUMATORIA: %d\n", sum);	
	

}

void handler(int s)
{
	printf("\nMe mataron, mi pid es %d\n", getpid());
	exit(retorno);
}

void handlerpadre(int s)
{
	printf("\nSoy el padre, mi pid es %d, recibi la senial\n", getpid());
}



