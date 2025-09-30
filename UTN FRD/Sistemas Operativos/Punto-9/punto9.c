/*realizar un programa que recibe por linea de comandos un comando a ejecutar y sus argumentos
en base a esto crea un hijo, el padre lee la salida del comando*/
//crear un pipe y hacer la función dup()



//el STDOUT_FILENO se utiliza para redirigir el comando al extremo del pipe
// la función dup me permite que cualquier cosa que escriba el hijo se podrá duplicar en el pipe y como uso la función STDOUT FILENO lo escribo en el extremo

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	
		int pipe1[2];  //pipe lector [0] , escritor [1]
		pid_t pid;
		int buffer[256];
		int N;
		
		
		
		//crear pipe
		
		if(pipe(pipe1)!=-1){
			
			printf("pipe creado con exito\n");
			
			} else {
				
			printf("error en la creación del pipe\n");
			return 1;
		}
		
		
		//creo al proceso hijo
		
		pid = fork();
		
		
		
		if (pid == 0) {		//estoy en el hijo
			
			
			execvp(argv[1], &argv[1]);		  // el argv sirve para ejecutar el argumento del comando y formar un array con el comando y el argumento que es lo q ejecuta el execvp
			close(pipe1[0]);  				 //cierro la lectura ya que el proceso hijo escribirá
			dup2(pipe1[1],STDOUT_FILENO);   //redirigir la salida al pipe que se mostrará en la terminal
			}
			
			else {	//estoy en el padre
				
				close(pipe1[1]); //el padre será lector
			
				while(N = read(pipe1[0], buffer, sizeof(buffer)) > 0 ){    //read(  nombre pipe, donde lo guarda, tamaño de lo que se lee)
																		   // el padre leerá el extremo del pipe y eso lo guarda en buffer
					printf("Salida: %s", buffer);
				
				//se podría agregar un caracter nulo al final del buffer para indicar un fin de cadena, funciona de la misma manera
				
				}
				
				wait(NULL);   //espero al hijo
				
			} 
			
			
			close(pipe1[1]);
			close(pipe1[0]);
			
			printf("Fin\n");
			
			return 0;
	}