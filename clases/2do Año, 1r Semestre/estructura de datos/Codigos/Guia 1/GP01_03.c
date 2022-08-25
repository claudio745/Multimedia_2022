#include <stdio.h>
#include <math.h>

#define k 8.99E9	//Definición de la constante

main()
{
	float q1;
	float q2;
	float x1;
	float y1;
	float x2;
	float y2;
	double fuerza;
	
	do
	{
		printf("Ingrese valor de la carga q1: ");
		scanf("%e",&q1);
	}while(q1 == 0);
	
	printf("Ingrese coordenada x de la carga q1: ");
	scanf("%f",&x1);
	
	printf("Ingrese coordenada y de la carga q1: ");
	scanf("%f",&y1);
	
	do
	{
		printf("Ingrese valor de la carga q2: ");
		scanf("%e",&q2);
	}while(q2 == 0);
	
	printf("Ingrese coordenada x de la carga q2: ");
	scanf("%f",&x2);
	
	printf("Ingrese coordenada y de la carga q2: ");
	scanf("%f",&y2);
	
	fuerza = k * q1*q2 /(pow(x2-x1,2)+pow(y2-y1,2));
	
	if(fuerza < 0) fuerza= -1 * fuerza;
	
	printf("La magnitud de a fuerza entre las cargas q1 y q2 es: %e N",fuerza);
}
