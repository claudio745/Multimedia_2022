#include <stdio.h>

void main()
{
	short int u[3][3]={{6,18,29},{3,-11,13},{15,-5,19}};	
	float v[3][5]={{0.85,6.50,6.95,0.42,3.10},{0.74,7.20,7.15,0.62,2.60},{1.05,6.85,6.75,0.55,2.95}};
	short int i;
	short int j;
	short int menorPosit;
	short int menorNeg;
	float promFil[3];
	float promCol[3];
	float suma;
	
	//1. Menor valor de los valores positivos de U
	
	//Bloque para encontrar el PRIMER elemento positivo
	//para ser utilizado como referencia inicial en el proceso de búsqueda
	
	menorPosit=-1; //Valor comodín para forzar el ingreso al ciclo
	i=0;
	while(menorPosit < 0 && i < 3)
	{
		j=0;
		while(j < 3 && menorPosit < 0)	//Mientras no cambie el valor comodín no ha encontrado un valor positivo
		{
			if(u[i][j] > menorPosit)
				menorPosit=u[i][j];
			j++;
		}
		i++;
	}
	//printf("Primer valor positivo de referencia: %i",menorPosit);
	
	//Busqueda del menor valor positivo
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if((u[i][j] > 0) && (u[i][j] < menorPosit))
				menorPosit=u[i][j];
			
	printf("\nMenor valor positivo de U: %i",menorPosit);		
			
	//2. Menor valor de los valores negativos de U
	
	//Bloque para encontrar el PRIMER elemento negativo
	//para ser utilizado como referencia inicial en el proceso de búsqueda
	
	menorNeg=0; 	//Valor comodín para ingresar al ciclo
	i=0;
	while(menorNeg >= 0 && i < 3)
	{
		j=0;
		while(j < 3 && menorNeg >= 0)
		{
			if(u[i][j] < menorNeg)
				menorNeg=u[i][j];
			j++;
		}
		i++;
	}
	//printf("\nPrimer valor negativo de referencia: %i",menorNeg);
	
	//Busqueda del menor valor negativo
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(u[i][j] < 0 && u[i][j] < menorNeg)
				menorNeg=u[i][j];
			
	printf("\nMenor valor negativo de U: %i",menorNeg);	
	
	
	//Promedios por fila de V
	
	printf("\n\nPromedio por fila del vector V");
	for(i=0; i<3; i++)
	{
		suma=0.0;
		for(j=0; j<5; j++)
			suma=suma+v[i][j];
		
		promFil[i]=suma/5;
		
		printf("\nPromedio fila %i: %f",i,promFil[i]);
	}
	
	printf("\n\nPromedio por columna del vector V");
	for(j=0; j<5; j++)
	{
		suma=0.0;
		for(i=0; i<3; i++)
			suma=suma+v[i][j];
		
		promCol[j]=suma/3;
		
		printf("\nPromedio columna %i: %f",j,promCol[j]);
	}		
}
