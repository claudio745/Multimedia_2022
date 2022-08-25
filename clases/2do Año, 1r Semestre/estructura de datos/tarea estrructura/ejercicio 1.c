#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "spanish");
	int opcion;
	
	
	do
	{
		printf("Si desea ingresar su polinomio de forma dispersa, ingrese 1, para ingresarlo de forma densa ingrese 2:\t");
		scanf("%d", &opcion);
		
		if(opcion != 1 && opcion != 2)
		{
			printf("Opcion incorrecta, ingrese los datos correspondientes.\n.");
		}	
		if(opcion == 1)
		{
			int tampolinomio1;
			printf("ingrese el tamaño de su polinomio:\t");
			scanf("%i", &tampolinomio1);
			int polinomio1[tampolinomio1];
			int indice1[tampolinomio1];
			int i;
		
			for(i=0; i < tampolinomio1; i++)
			{
				printf("Ingrese el numero en la posicion %d:", i);
				scanf("%i", &polinomio1[i]);
				printf("Ingrese el indice de su dato ingresado:");
				scanf("%i", &indice1[i]);
				printf("\n");
			}
			printf("su número representado de la forma dispersa es:");
			for(i=0; i < tampolinomio1; i++)
			{	
				printf("[%i], ", polinomio1[i]);
			}
		}
		
		
			
		if(opcion == 2)
		{
			int tampolinomio;
	
			printf("ingrese el tamaño de su polinomio:\t");
			scanf("%i", &tampolinomio);
		
			int polinomio[tampolinomio];
			int indice[tampolinomio];
			int i;
		
			for(i=0; i < tampolinomio; i++)
			{
				printf("Ingrese el numero en la posicion %d:", i);
				scanf("%i", &polinomio[i]);
				printf("Ingrese el indice de su dato ingresado:");
				scanf("%i", &indice[i]);
				printf("\n");
			}
			printf("su número representado de la forma densa es:");
			for(i=0; i < tampolinomio; i++)
			{	
				printf("[(%i, %i)], ",indice[i], polinomio[i]);
			}		
		}
	}while(opcion < 0 || opcion > 2);


	
	
}
