#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define casillas_buffer = N;

typedef struct semaforo
{
	sem_casillas_por_llenar = N;
	sem_casillas_por_consumir = 0;	
}semaforo;


int proxima_casilla_llenar = 0;

int proxima_casilla_consumir =0;

tipo_dato buffer[N];

void productor() {
	while (1) {
    	wait(sem_casillas_por_llenar);
    	wait(sem_binario);
    	buffer[proxima_casilla_llenar] = producir_dato();
    	signal(sem_binario);
    	signal(sem_casillas_por_consumir);
    	proxima_casilla_llenar = (proxima_casilla_llenar +1 ) % N; }
}


void consumidor() {
    
    while (1) {
		wait m_casillas_por_consumir);
    	wait(sem_binario);
    	consumir_dato(buffer[proxima_casilla_consumir]);
    	signal(sem_binario);
    	signal(sem_casillas_por_llenar);
    	proxima_casilla_consumir = (proxima_casilla_consumir +1 ) % N; }
}

