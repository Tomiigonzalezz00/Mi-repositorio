#include <pthread.h>
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t m1, m2,m3,m4 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
pthread_t hiloQueLlenaMatriz, hiloQueSumaColumna1, hiloQueSumaColumna2,hiloQueSumaColumna3,hiloQueSumaElTotalGeneral;

int matriz[4][3];
int T[3] = {-1,-1,-1};
int i,sumatoria,fil,col;


void llenarMatriz(void);
void sumarTotal(void);
void sumarC1(void);
void sumarC2(void);
void sumarC3(void);

int main(void){
	
	pthread_mutex_lock(&m2);
    pthread_mutex_lock(&m3);
    pthread_mutex_lock(&m4);
	
	pthread_create(&hiloQueLlenaMatriz, NULL, (void *)llenarMatriz, NULL);
	pthread_join(hiloQueLlenaMatriz, NULL);
	
	pthread_create(&hiloQueSumaColumna1, NULL, (void *)sumarC1, NULL);
	pthread_create(&hiloQueSumaColumna2, NULL, (void *)sumarC2, NULL);
	pthread_create(&hiloQueSumaColumna3, NULL, (void *)sumarC3, NULL);
	pthread_create(&hiloQueSumaElTotalGeneral, NULL, (void *)sumarTotal, NULL);
	
	pthread_join(hiloQueSumaColumna1, NULL);
	pthread_join(hiloQueSumaColumna2, NULL);
	pthread_join(hiloQueSumaColumna3, NULL);
	
	pthread_join(hiloQueSumaElTotalGeneral, NULL);
	
	 return 0;
	
}


void llenarMatriz(void){
	pthread_mutex_lock(&m1);
	printf("Matriz  cargada\n");
		for(fil = 0; fil <4;fil++){
				for(col=0; col <3; col ++){
						matriz[fil][col] = random() % 100;
					}
		}
	printf("La matriz cargada es: \n");
		for(fil = 0; fil <4;fil++){			
				for(col=0; col <3; col ++){
						printf("%d|",matriz[fil][col]);
					}
			printf("\n");
		}	
	pthread_mutex_unlock(&m1);
	pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m3);
    pthread_mutex_unlock(&m4);
	pthread_exit(NULL);
	
}

void sumarC1(void){
	pthread_mutex_lock(&m2);
	fil=4;
	sumatoria = 0;
	while(fil){
		fil--;
		 sumatoria = sumatoria+matriz[fil][0];
	}
		T[0] = sumatoria;

	   if (T[0] != -1 && T[1] != -1 && T[2] != -1) {
        pthread_cond_signal(&cv);
    }

	pthread_mutex_unlock(&m2);
    
	pthread_exit(NULL);
}

void sumarC2(void){
	pthread_mutex_lock(&m3);
	fil=4;
	sumatoria = 0;
	while(fil){
		fil--;
		sumatoria = sumatoria+matriz[fil][1];
	}
	T[1]=sumatoria;
	
	if (T[0] != -1 && T[1] != -1 && T[2] != -1) {
        pthread_cond_signal(&cv);
    }
	pthread_mutex_unlock(&m3);
	
	pthread_exit(NULL);
}

void sumarC3(void){
	pthread_mutex_lock(&m4);
	fil=4;
	sumatoria = 0;
	while(fil){
		fil--;
		sumatoria=sumatoria+matriz[fil][2];
	}
	T[2]=sumatoria;
	
	if (T[0] != -1 && T[1] != -1 && T[2] != -1) {
        pthread_cond_signal(&cv);
    }
	pthread_mutex_unlock(&m4);

	pthread_exit(NULL);
}

void sumarTotal(void){
	pthread_mutex_lock(&m1);
	while(T[0] ==-1 || T[1] == -1 || T[2] == -1 ){
	pthread_cond_wait(&cv,&m1);
	}
	pthread_mutex_unlock(&m1);
	
	sumatoria = 0;
	for(i=0;i<3;i++){
		sumatoria=sumatoria + T[i];
		}
	printf("El vector Cargado con la sumatoria de las columnas es: \n");
	for(i=0;i<3;i++){
		printf("%d|",T[i]);
	}
	printf("\n");
	printf("La sumatoria total es: %d \n", sumatoria);
	
	pthread_exit(NULL);
}

