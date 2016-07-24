/* Modulo hecho por:
 * Mura Javier		21.456.202
 * Labbe Andres		22.728.231
 * Capriles Oswaldo	26.026.458
 * Victor Tortolero	24.569.609
 */

#ifndef SERVICIO_TECNICO_H
#define SERVICIO_TECNICO_H

#include "cajeras.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


static int    nosVolvimosLocos();
static void * servicioTecnico(void *);

/* Estas funciones seran usadas para generar reportes!
 * Pasar un struct con los datos necesarios
 */
void reporteDiario(void *);
void reporteSemanal(void *);

pthread_t TI;
static sem_t reporteD, reporteS;
static int luz = 1;


void init_TI()
{
	srand(time(NULL));
	pthread_create(&TI,NULL,servicioTecnico,NULL);
	sem_init(&reporteD, 0, 1);
	sem_init(&reporteS, 0, 1);
}

void close_TI()
{
	pthread_join(TI, null);
}

static void * servicioTecnico(void *data)
{
	int acabaDeIrseLaLuz = 0;
	int acabaDeLlegarLaLuz = 0;

	while(1)
	{
		/* Si no hay luz.. */
		if(!luz)
		{
			acabaDeLlegarLaLuz = llamarACorpoelec();
		}
		else
		{
			acabaDeIrseLaLuz = nosVolvimosLocos();
		}

		if (acabaDeLlegarLaLuz)
		{
			printf("Llego la luz!\n");
			encender_mitad_cajas(); // Esta funcion es del modulo de cajeras
			acabaDeLlegarLaLuz = 0;
		}

		if (acabaDeIrseLaLuz)
		{
			printf("Hubo un fallo de energia! Se prendio la plantas\n");
			apagar_mitad_cajas(); // Esta funcion es del modulo de cajeras
			acabaDeIrseLaLuz = 0;
		}
	}
}

/* Simula si se va la luz */
static int nosVolvimosLocos()
{
	if(rand() < RAND_MAX * 0.1)
	{
		luz = 0;
	}
	return luz;
}

/* Simula que llegue la luz antes de irse */
static int llamarACorpoelec()
{
	if(rand() < RAND_MAX * 0.4)
	{
		luz = 1;
	}
	return luz;
}

void reporteDiario(void *reporte)
{
	// Hacerle casting a reporte e inicializarla
	sem_wait(&reporteD);
		printf("Generando reporte diario");
		// Imprimir data del reporte o guardarla
	sem_post(&reporteD);
}

void reporteSemanal(void *reporte)
{
	// Hacerle casting a reporte e inicializarla
	sem_wait(&reporteS);
		printf("Generando reporte semanal");
		// Imprimir data del reporte o guardarla
	sem_post(&reporteS);
}

#endif
