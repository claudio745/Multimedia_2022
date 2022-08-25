#include<stdio.h>
#include<math.h>

void main()
{
	double a;
	double b;
	double x;
	double funcion1;
	float funcion2;
	float funcion3;
	double elevado = ((x+1) / (x-1));
	double elevado1;


	printf("se implementa la siguiente expresion algebraica: a + b ^(x+1)/(x-1)\n");
	
	printf("Ingrese un valor para a: ");
	scanf("%lf", &a);
	printf("ingrese valor para b: ");
	scanf("%lf", &b);
	printf("ingrese valor para x: ");
	scanf("%lf", &x);
	
	elevado1 = pow(b,elevado);
	elevado1 = b;
	
	funcion1 = a + elevado1;
	
	printf("el resultado es: %0.3lf", funcion1);	
	
	

	
	
	
}
