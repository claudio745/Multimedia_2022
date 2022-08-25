#include <stdio.h>
#include <math.h>

void main()
{
	short int x;
	float fx;
	
	printf("Ingrese el valor de x (0 <= x < 20): ");
	scanf("%i",&x);
	
	if(x < 0 || x >= 20)
		printf("El valor de x es incorrecto");
	else
	{
		if(x >= 0 && x < 5)	fx=3*pow(x,2) - 4*x;
		if(x >= 5 && x < 10) fx=8*x - x/5 + 15;
		if(x >= 10 && x < 20) fx=pow(x,2) - 17;	
		
		printf("f(%i)= %f",x,fx);
	}
}

