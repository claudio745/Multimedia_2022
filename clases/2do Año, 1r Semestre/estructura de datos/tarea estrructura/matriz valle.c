#include <stdio.h>

#define maxfila  10
#define maxcol  10

void main()
{
	short int filas;
	short int columnas;
	
	printf("A continuacion se le pedira ingresar datos, estos datos deben ser mayores o iguales a 3 y menores o iguales a 10.\n");
	
	do
	{
		printf("Ingrese cuantas filas quiere ingresar:\t");
		fflush(stdin);
		scanf("%d", &filas);
		if (filas >= 3 && filas <= 10)
		{
			printf("Datos ingresados con exito.\n");
		}
		else{
			printf("filas debe ser mayor o igual a 3 y menor o igual a 10\n");
		}
	}while(filas < 3 || filas > 10);
	
	do
	{
		printf("Ingrese cuantas columnas quiere ingresar:\t");
		scanf("%d", &columnas);
		
		if (columnas >= 3 && columnas <= 10)
		{
			printf("Datos ingresados con exito.\n");
		}
		else{
			printf("columnas debe ser mayor o igual a 3 y menor o igual a 10\n");
		}
	}while(columnas < 3 || columnas > 10);
	printf("%d\n", filas);

	
	int matriz[maxfila][maxcol];
	
	printf("%i\n", filas);
	printf("%i", columnas);
	
	int fil;
	int col;
	
	for (fil = 0; fil < filas; fil++)
	{
		for (col = 0; col < columnas; col++)
		{
			printf("Ingrese el valor en la posicion %d, %d:", fil, col);
			scanf("%d", &matriz[fil][col]);
			
		}
	}
	
	
	for (fil = 0; fil < filas; fil++)
	{
		for (col = 0; col < columnas; col++)
		{
			printf("%i", matriz[fil][col]);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}
