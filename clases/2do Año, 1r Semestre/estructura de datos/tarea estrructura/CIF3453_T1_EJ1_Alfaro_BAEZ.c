#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "spanish");
	int filas;
	int columnas;
	
	printf("A continuacion se le pedira ingresar datos, estos datos deben ser mayores o iguales a 3 y menores o iguales a 10.\n");
	
	do
	{
		printf("Ingrese numero de filas:\t");
		scanf("%d", &filas);
		if(filas >= 3 && filas <= 10)
		{
			printf("Dato ingresado con exito.\n");
		}
		else{
			printf("Fila debe ser mayor o igual a 3 y menor o igual a 10, intente de nuevo.\n");
		}	
	}while(filas < 3 || filas > 10);
	
	do
	{
		printf("Ingrese numero de columnas:\t");
		scanf("%d", &columnas);
		if(columnas >= 3 && columnas <= 10)
		{
			printf("Dato ingresado con exito.\n");
		}
		else{
			printf("Dato erroneo, intente nuevamente.\n");
		}
	}while(columnas < 3 || columnas > 10);
		
	int matriz[filas][columnas];	
	
	int fil;
	int col;
	
	for (fil = 0; fil < filas; fil++)
	{
		for (col = 0; col < columnas; col++)
		{
			do
			{
				printf("Ingrese el valor en la posicion %d, %d:", fil, col);
				scanf("%d", &matriz[fil][col]);
				if(matriz[fil][col] < 0)
				{
					printf("Su valor es negativo, ingrese uno positivo para continuar.\n");
				}	
			}while(matriz[fil][col] < 0);
		}
	}
	
	for (fil = 0; fil < filas; fil++)
	{
		for (col = 0; col < columnas; col++)
		{
			printf("%d \t", matriz[fil][col]);
		}
		printf("\n");
	}
	
	int cont = 0;
	int i;
	int j;
	
	for (fil = 1; fil < filas; fil++)
	{
		for (col = 1; col < columnas; col++)
		{
			if(matriz[fil][col] < matriz[fil+1][col+1] && matriz[fil][col] < matriz[fil+1][col] && matriz[fil][col] < matriz[fil+1][col-1] && matriz[fil][col] < matriz[fil][col-1] && matriz[fil][col] < matriz[fil-1][col-1] && matriz[fil][col] < matriz[fil-1][col] && matriz[fil][col] < matriz[fil-1][col+1] && matriz[fil][col] < matriz[fil][col+1])
			{
				printf("hay un valle en la fila %d columna %d:  \n", fil, col);
				cont++;
				for(i = fil-1; i < fil +2; i++)
				{
					for(j = col-1; j < col + 2; j++)
					{
						printf("%d\t", matriz[i][j] );
					}
					printf("\n");
				}
			}
		}
	}
	
	if(cont == 0)
	{
		printf("No existe valle.");
	}
}


