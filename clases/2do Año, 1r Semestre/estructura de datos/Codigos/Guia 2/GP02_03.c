#include <stdio.h>
#include <math.h>

typedef struct Fraccion
{
	short int entero;
	int       numerador;
	int       denominador;
}Fraccion;


void main()
{
	Fraccion frac1;
	Fraccion frac2;
	Fraccion frac11;
	Fraccion frac22;
	int num;
	int den;
	int entero;
	
	
	printf("Ingreso de la primera fraccion. Si no es mixta ingrese 0 para la parte entera");
	printf("\nIngrese la parte entera de la fraccion: ");
	scanf("%i",&frac1.entero);

	do
	{
		printf("Ingrese el numerador de la fraccion: ");
		scanf("%i",&frac1.numerador);
	}while(frac1.denominador == 0);
	
	do
	{
		printf("Ingrese el denominador de la fraccion: ");
		scanf("%i",&frac1.denominador);
	}while(frac1.denominador <= 0);
	
	
	printf("\nIngreso de la segunda fraccion. Si no es mixta ingrese 0 para la parte entera");
	printf("\nIngrese la parte entera de la fraccion: ");
	scanf("%i",&frac2.entero);

	do
	{
		printf("Ingrese el numerador de la fraccion: ");
		scanf("%i",&frac2.numerador);
	}while(frac2.denominador == 0);
	
	do
	{
		printf("Ingrese el denominador de la fraccion: ");
		scanf("%i",&frac2.denominador);
	}while(frac2.denominador <= 0);
	
	
	if(frac1.entero > 0)
		frac11.numerador=frac1.entero*frac1.denominador + frac1.numerador;
	else
		frac11.numerador=frac1.numerador;
		
	frac11.denominador=frac1.denominador;
	
	if(frac2.entero > 0)
		frac22.numerador=frac2.entero*frac2.denominador + frac2.numerador;
	else
		frac22.numerador=frac2.numerador;
		
	frac22.denominador=frac2.denominador;
		
	
	//Suma de fracciones
	den=frac11.denominador * frac22.denominador;
	num=frac11.numerador * frac22.denominador + frac11.denominador * frac22.numerador;
	
	if(abs(num) < den)	
		printf("\nLa suma de las fracciones es: %i/%i",num,den);	
	else
	{
		entero=num/den;
		if(num%den == 0)	
			printf("\nLa suma de las fracciones es: %i",entero);
		else
		{
			num=abs(num%den);
			printf("\nLa suma de las fracciones es: %i %i/%i",entero,num,den);
		}
	}

	//Resta de fracciones
	den=frac11.denominador * frac22.denominador;
	num=frac11.numerador * frac22.denominador - frac11.denominador * frac22.numerador;
	
	if(abs(num) < den)		
		printf("\nLa resta de las fracciones es: %i/%i",num,den);	
	else
	{
		entero=num/den;
		if(num%den == 0)	
			printf("\nLa resta de las fracciones es: %i",entero);
		else
		{
			num=abs(num%den);
			printf("\nLa resta de las fracciones es: %i %i/%i",entero,num,den);
		}
	}
		
	//Multiplicación de fracciones
	num=frac11.numerador * frac22.numerador;
	den=frac11.denominador * frac22.denominador;
	
	if(abs(num) < den)		
		printf("\nLa multiplicación de las fracciones es: %i/%i",num,den);	
	else
	{
		entero=num/den;
		if(num%den == 0)	
			printf("\nLa multiplicación de las fracciones es: %i",entero);
		else
		{
			num=abs(num%den);
			printf("\nLa multiplicación de las fracciones es: %i %i/%i",entero,num,den);
		}
	}	
	
	//División de fracciones
	num=frac11.numerador * frac22.denominador;
	den=frac11.denominador * frac22.numerador;
	
	if(abs(num) < den)		
		printf("\nLa division de las fracciones es: %i/%i",num,den);	
	else
	{
		entero=num/den;
		if(num%den == 0)	
			printf("\nLa division de las fracciones es: %i",entero);
		else
		{
			num=abs(num%den);
			printf("\nLa division de las fracciones es: %i %i/%i",entero,num,den);
		}
	}	
}
