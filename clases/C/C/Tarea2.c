#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



typedef struct Pedido
{
	int cod;
	char prod[40];
	float peso;
	float volumen;
	char clasificacion;
	struct Pedido* sig;
	
	
}Pedido;
	
	
void main()
{
	
	Pedido *recep;
	Pedido *clasif;
	Pedido *listaP;
	Pedido *listaM;
	Pedido *listaG;
	Pedido *listaE;
	Pedido *listaS;
	int contador = 100;	
	srand(time(NULL));
	Pedido *head;
	Pedido *aux;
	Pedido *nodosig;	
	int opcion;
	recep=(Pedido*)malloc(sizeof(Pedido));
	clasif=(Pedido*)malloc(sizeof(Pedido));
	listaP=(Pedido*)malloc(sizeof(Pedido));
	listaM=(Pedido*)malloc(sizeof(Pedido));
	listaG=(Pedido*)malloc(sizeof(Pedido));
	listaE=(Pedido*)malloc(sizeof(Pedido));
	listaS=(Pedido*)malloc(sizeof(Pedido));
	int nuevo;
	
	printf("|-----------------------------------------------------------|\n");
	printf("|  1- Ingresar pedido                                       |\n");
	printf("|  2- clasificar pedido(s)                                  |\n");
	printf("|  3- consultar capacidad actual de una linea (P, M G o E)  |\n");
	printf("|  4- Vaciar una linea (P, M, G o E)                        |\n");
	printf("|  5- consultar cantidad de pedidos en lista de espera      |\n");
	printf("|  6- Salir                                                 |\n");
	printf("|-----------------------------------------------------------|\n");
	printf("Elija una de las siguientes opciones:\t");
	scanf("%d", &opcion);
		
	do
	{
		switch(opcion)
		{
			
			case 1:
				aux=(Pedido*)malloc(sizeof(Pedido));
				printf("Ingrese el nombre del producto:\n");
				scanf("%s", &aux->prod);
				aux->peso = rand() % 101;
				aux->volumen = rand() % 201;
				aux->cod = contador;
				contador+1;
				printf("%s\n", aux->prod);
				printf("%.2f\n", aux->peso);
				printf("%.2f\n", aux->volumen);
				printf("%i", aux->cod);
				printf("Hola");
				if(recep == NULL)
				{
					printf("hola");
					recep = aux;
					recep->sig = NULL;
				}else{
					aux = recep;
					while(aux->sig =! NULL)
					{
						aux = aux->sig;
					}
					
				}
				printf("hola");

				
				break;
			case 2:
				break;
			default:
				break;	
		}
	}while(opcion == 6);
	

}

