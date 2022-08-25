#include<stdio.h>

void main()
{
	float funcion2;
	float a;
	float b;
	float c;
	float d;
	
	printf("Se implementa la siguiente expresion algebraica: a / b(2c + d)\n");
	
	printf("Ingrese un valor para a: ");
	scanf("%f",&a);
	
	printf("Ingrese valor para b: ");
	scanf("%f",&b);
	
	printf("Ingrese valor para c: ");
	scanf("%f",&c);
	
	printf("Ingrese valor para d: ");
	scanf("%f",&d);
	
	funcion2 = a/(b*(2*c+d));	
	
	printf("El resultado es: %f", funcion2);
}

