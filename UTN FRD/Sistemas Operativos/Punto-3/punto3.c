/*
Implementación de una sincronización de los hilos A, B y C de forma tal, que la secuencia de ejecución y acceso a su sección crítica sea la siguiente: ABAC... detener el proceso luego de N iteraciones completas (el número N se ingresa por línea de comandos). Resolver la sincronización con variables Mutex (librería pthread). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <string.h>
#include <pthread.h>

//Prototipo de las funciones hilos
void fHiloA(void *);
void fHiloB(void *);
void fHiloC(void *);

//Declaro los mutex de cada hilo y los inicializamos. Se declara de manera global porque cada hilo debe conocer el estado de los otros
pthread_mutex_t mA1 = PTHREAD_MUTEX_INITIALIZER; //candado mA1 abierto.
pthread_mutex_t mB = PTHREAD_MUTEX_INITIALIZER; //candado mB abierto.
pthread_mutex_t mA2 = PTHREAD_MUTEX_INITIALIZER; //candado mA2 abierto. Hay que crear dos candados de A ya que acontinuación de él hay dos valores distintos. Hacemos uno para cada caso.
pthread_mutex_t mC = PTHREAD_MUTEX_INITIALIZER; //candado mC abierto.
//Si el valor de un candado es 1 significa que está abierto y el hilo continua con su ejecución. Si el valor del candado es 0, significa que el candado está cerrado y el hilo tendrá bloqueada su ejecución.

int main(int argc, char * argv[]) {
    int n = atoi(argv[1]);
    //Declaro las variables de tipo hilo
    pthread_t hiloA, hiloB, hiloC;
    int i;

    //Bloqueo los candados mA2, mB y mC para que solo se inicialice el hilo A y lo esperen a él
    pthread_mutex_lock(&mB);
    pthread_mutex_lock(&mC);
    pthread_mutex_lock(&mA2);

    for(i = 0; i < n; i++) {
        //Prototipo para crear los hilos
        pthread_create(&hiloA, NULL, (void *)fHiloA, NULL);
        pthread_create(&hiloB, NULL, (void *)fHiloB, NULL);
        pthread_create(&hiloC, NULL, (void *)fHiloC, NULL);

        //Prototipo para esperar hilos
        pthread_join(hiloA, NULL);
        pthread_join(hiloB, NULL);
        pthread_join(hiloC, NULL);
    }

    printf("\n");

    return 0;
}

void fHiloA(void *p) {
    pthread_mutex_lock(&mA1);
        printf("A");
    pthread_mutex_unlock(&mB);
    pthread_mutex_lock(&mA2);
        printf("A");
    pthread_mutex_unlock(&mC);
}

void fHiloB(void *p) {
    pthread_mutex_lock(&mB);
        printf("B");
    pthread_mutex_unlock(&mA2);
}

void fHiloC(void *p) {
    pthread_mutex_lock(&mC);
        printf("C");
    pthread_mutex_unlock(&mA1);
}
