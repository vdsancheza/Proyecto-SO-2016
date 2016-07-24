#ifndef SERVICIO_TECNICO_H
#define SERVICIO_TECNICO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* 
	Modulo hecho por:
	Mura Javier		21.456.202
	Labbe Andres		22.728.231
	Capriles Oswaldo	26.026.458
	Victor Tortolero	24.569.609
*/

pthread_t TI;
void * servicioTecnico(void *data); 
int nosVolvimosLocos();


void init_TI()
{
	srand(time(NULL));
	pthread_create(&TI,NULL,servicioTecnico,NULL);
}

void * servicioTecnico(void *data)
{
	while(1)
	{
		if(nosVolvimosLocos())
		{
        		printf("Hubo un fallo de energia!\n");
		}
	}
}

int nosVolvimosLocos()
{
	int luz = 0;
	if(rand() < RAND_MAX * 0.1)
	{
		luz = 1;
	}
	return luz;
}
	

#endif
