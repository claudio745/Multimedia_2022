#include<stdio.h>

void main()
{
	float a;
	float b;
	float funcion3;
	
	printf("se implementa la siguiente expresion algebraica: 1 / 1 + (1/ (3a - 2b)\n");
	printf("Ingrese valor para a: ");
	scanf("%f", &a);
	
	printf("Ingrese valor para b:  ");
	scanf("%f", &b);
	
	funcion3 = 1/(1+(1/((3*a) -(2*b))));
	
	printf("El resultado es: %f", funcion3);
	
	
	
	
	
}
