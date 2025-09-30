//Implementación de procesos emparentados pipes. Padre A , Hijo B, Padre A, Hijo C. La ejecución se detiene luego de N iteraciones
//El HijoB e HijoC son hermanos
// resolver con sincronización
//SECCIÓN CRÍTICA EN PIPES = MULTIPLES PROCESOS INTENTAN LEER O ESCRIBIR EN EL MISMO PIPE


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>		
#include <sys/shm.h>
#include <sys/sem.h>
#include <wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>



//creo sección crítica
  void seccionCritica(char id){
	  printf("Accedio [%c] a la sección critica\n", id);    	// mediante el Char = A,B,C determino quien estuvo en la seccion critica
	  }
	  
	  
int main(int argc, char*argv[]){
	  
	  pid_t pidB, pidC;
	  int i;
	  int Numero = atoi(argv[1]);
	
	//(creo semáforos)
	sem_t * Sa;
	sem_t * Sb;
	sem_t * Sx;
	sem_t * Sc;
	
	sem_unlink("/Sa");
	sem_unlink("/Sb");
	sem_unlink("/Sx");
	sem_unlink("/Sc"); 
	
	Sa = sem_open("/Sa", O_CREAT | O_EXCL, 0644, 1);   //semáforo flag permiso inicialización
	Sb = sem_open("/Sb", O_CREAT | O_EXCL, 0644, 0);
	Sx = sem_open("/Sx", O_CREAT | O_EXCL, 0644, 0);
	Sc = sem_open("/Sc", O_CREAT | O_EXCL, 0644, 0);
	
		
	  if(pidC = fork()) { //creo hijoC
			//contemplo error
			if(pidC == -1){
				printf("Error hijoC\n");
				return 1;
				}
			  
		if(pidB = fork()){  //creo hijoB
				//contemplo error
				if(pidB == -1){
					printf("Error hijoB\n");
					return 1;
				  }
			  
			  
				// estoy en el padre
			
				for(i=0; i < Numero; i++){  
				//printf("Soy el Padre y mi pid es %d\n", getpid());
				sem_wait(Sa);
				seccionCritica('A');
				sem_post(Sb);
				sem_wait(Sx);
				seccionCritica('A');
				sem_post(Sc);
				
				
		  
		  } 
	  
	   } else { //estoy en hijoB
				
				for(i = 0; i < Numero; i++){
					//printf("Soy hijoB y mi pid es %d\n", getpid());
				
					//printf("HijoB en la sección crítica\n");
					sem_wait(Sb);
					seccionCritica('B');
					sem_post(Sx);
					
					}
					
				exit(0);
			  }
			  
	 } else { //estoy en el hijoC
		 
			for(i=0; i < Numero; i++){
				//printf("Soy hijoC y mi pid es %d\n", getpid());
			
				//printf("HijoC en la sección crítica\n");
				sem_wait(Sc);
				seccionCritica('C');
				sem_post(Sa);
				
				}
				
			exit(0);
		 } 
		 
	while(wait(NULL)!=-1); //espera por los hijos
	      
	 printf("fin\n");
	 return 0;
}
