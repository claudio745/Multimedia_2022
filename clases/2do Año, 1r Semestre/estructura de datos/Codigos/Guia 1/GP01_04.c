#include <stdio.h>

main()
{
	float m1;	//pendiente de la recta dada
	float b1;
	float y1;
	float x;
	float y;
	float m2;
	float b2;
	
	printf("Recta 1 --> y = mx + b \n");
	
	printf("Ingrese la pendiente m: ");
	scanf("%f",&m1);
	
	printf("Ingrese el valor de b: ");
	scanf("%f",&b1);
	
	printf("Ingrese valor de x para el punto (x,y): ");
	scanf("%f",&x);
	
	printf("Ingrese valor de y para el punto (x,y): ");
	scanf("%f",&y);
	
	m2 = -1/m1;
	b2 = -1*x + y;
	
	printf("La recta perpendicular es: y = %fx - %f",m2,b2);
	
	
	
	
	
}
