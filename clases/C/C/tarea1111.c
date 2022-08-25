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
	srand(time(NULL));
	Pedido *recep; //recepción de pedidos
	Pedido *clasif; //no se copian, 
	Pedido *listaP;
    Pedido *listaM;
    Pedido *listaG;
    Pedido *listaE;
    Pedido *listaS;
    Pedido *Nuevo;
    Pedido *mostrar;//mostrar lista
    
	
    
    int op;
    recep = NULL;
    mostrar = NULL;
    //recep = (Pedido*) malloc (sizeof(Pedido));
    //printf("%d, %d, %s", recep, recep->sig, recep->prod);
    do{
    	printf("|-----------------------------------------------------------|\n");
		printf("|  1- Ingresar pedido                                       |\n");
		printf("|  2- clasificar pedido(s)                                  |\n");
		printf("|  3- consultar capacidad actual de una linea (P, M G o E)  |\n");
		printf("|  4- Vaciar una linea (P, M, G o E)                        |\n");
		printf("|  5- consultar cantidad de pedidos en lista de espera      |\n");
		printf("|  6- Salir                                                 |\n");
		printf("|-----------------------------------------------------------|\n");
		printf("Elija una de las siguientes opciones:\t");
    	scanf("%d", &op);
    	switch(op){
    		case 1:
    			//Paso 1 Verificar si existe, si no crear
    			if(recep == NULL)
				{
    				printf("Holaif1\n");
    				recep = (Pedido*) malloc (sizeof(Pedido));
    				recep->sig = NULL;
    				printf("Ingrese el nombre del producto:\n");
    				scanf("%s", &recep->prod);
    				recep->peso = rand() % 100 + 1;
					recep->volumen = rand() % 200 + 1;
					printf("Holaif2\n");
					clasif = recep;
				}
				else{
					printf("Holaelse1\n");
					Nuevo = (Pedido*) malloc (sizeof(Pedido));
					recep->sig = Nuevo;
					Nuevo->sig = NULL;
					printf("Ingrese el nombre del producto:\n");
    				scanf("%s", &Nuevo->prod);
					Nuevo->peso = rand() % 101;
					Nuevo->volumen = rand() % 201;
					printf("Holaelse2\n");
					recep = Nuevo;

				}
    			
    			
    			break;
    		case 2:
    			mostrar = clasif;
    			while(mostrar!=NULL)
				{
    				printf("%s, %d, %d\n", mostrar->prod, mostrar->peso, mostrar->volumen);
    				mostrar = mostrar->sig;
				}
    			break;
    		case 6:
    			printf("Finalizando");
		}
	}while(op!=6);
	
}
