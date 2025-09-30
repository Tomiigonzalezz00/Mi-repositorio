//Implementación del programa Shell, que haga uso de la señal SIGCHLD para verificar 
// la finalización de procesos en background y evite la existencia de zombies.
// si el usuario presiona CTRL + C el programa esperará a que terminen los procesos 
// luego finaliza sin dejar procesos zombies o huérfanos.

// Importante : el programa finaliza cuando se escribe 'exit' luego si presiona CTRL+C el programa esperara por la finalización de los procesos


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

//prototipo función sigchld
void sigchld_handle(int);

//prototipo función sigint
void sigint_handle(int);

int main(void){

	// declaro señal SIGCHLD y le asocio un handle
    signal(SIGCHLD,sigchld_handle);

    pid_t pid; //guarda el valor de los ejecutado en el fork
    char comando [64]; //tomo el valor del comando para hacer el exec
	memset(comando, '\0', 64);  // inicializo el vector [64] en 0 memset(vector, en q valor, posiciones totales).
	int i,aux;
	int tam=0;
	   
   
    while(1)  
    {
		printf("Ingrese un Prompt: ");
		scanf("%s", comando); //para que el usuarios ingrese un comando
		tam = 0;
		
		if(strcmp(comando, "exit") == 0) //strcmp compara dos caracteres, deveuelve 0 cuando son iguales
			exit(0);
		
		for (i=0;comando[i]!=0;i++){
		tam = tam+1;
		aux = comando[i];
		}
		
		
		if(aux == '&'){
			
			comando[tam-1] = 0;
			pid = fork(); //creo un hijo
			 if(pid == 0) //hijo
			 {
				printf("Proceso Creado en Background\n"); 
				execlp(comando,comando,NULL); // ó execlp(comando, comando, NULL) modifico imagén del hijo.
				
				//Si es valido , en esta linea cambia de codigo, sino sigue con la ejecucion de este codigo 
				printf("El Comando Ingresado no es Valido\n"); //en caso de comando invalido
				for (i=0;comando[i]!=0;i++){
					printf("%c",comando[i]);
				}
				
				exit(0); // cuando el hijo termina sale del while	
			 }
			else 
				if (pid > 0)  //padre
				{
					printf("Creación del proceso %d en background\n", pid);
					while(wait(NULL)!= -1);
				}
		}
		
		else{
			pid = fork(); //creo un hijo
			 if(pid == 0)  //hijo
			 {
				execlp(comando,comando,NULL); // ó execlp(comando, comando, NULL) modifico imagén del hijo.
				
				//Si es valido , en esta linea cambia de codigo, sino sigue con la ejecucion de este codigo 
				printf("El Comando Ingresado no es Valido\n"); //en caso de comando invalido
						for (i=0;comando[i]!=0;i++){
							printf("%c",comando[i]);
						}
				exit(0); // cuando el hijo termina sale del while	
			 }
			else 
				if (pid > 0)  //padre
				{
					printf("Creación del proceso %d en foreground\n", pid);
					while(wait(NULL)!= -1);
				}
				
			} 
	 }
}

void sigchld_handle(int sig){ 
     printf("Termino el proceso hijo\n");
}

void sigint_handle(int sig){
	 while(wait(NULL)!= -1); //Para que no se hagan hijos zombies o huerfanos
	 exit(0);
}
