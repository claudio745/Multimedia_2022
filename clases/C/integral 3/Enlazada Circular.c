#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* sgt;
} nodo;


nodo* prim = NULL;
nodo* ult = NULL;

void insertar();
void buscar();
void eliminar();
void mostrarlista();
void ascendente();


int main(){
	int opcion = 0;
	do{
		printf("\n 1. Insertar      | 4. Desplegar   ");
		printf("\n 2. Buscar        | 5. Salir     ");
		printf("\n 3. Eliminar ");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				insertar();
				break;
			case 2:
				buscar();
				break;	
			case 3:
				eliminar();
				break;
			case 4:
				mostrarlista();
				ascendente();
				mostrarlista();
				break;
			case 5:
				printf("\n\n Programa finalizado...");
				break;	
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcion != 5);
	return 0;
}           


void insertar(){
	system("cls");
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d",&nuevo->dato);
	
	if(prim==NULL){
		prim = nuevo;
		prim->sgt = prim;
		ult = prim;
	}else{
		ult->sgt = nuevo;
		nuevo->sgt = prim;
		ult = nuevo;
	}
	printf("\n Nodo ingresado con exito\n\n");
	system("pause");
	system("cls");
	
}

void buscar(){
	nodo* pivote = (nodo*)malloc(sizeof(nodo));
	pivote = prim;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a Buscar: ");
	scanf("%d",&nodoBuscado);
	if(prim!=NULL){
		do{
			if(pivote->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			pivote = pivote->sgt;
		}while(pivote!=prim && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n Su lista se encuentra vacia, ingrese datos por favor\n\n");
	}	
}

void eliminar(){
	nodo* pivote = (nodo*)malloc(sizeof(nodo));
	pivote = prim;
	nodo* ant = (nodo*)malloc(sizeof(nodo));
	ant = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a Buscar para Eliminar: ");
	scanf("%d",&nodoBuscado);
	if(prim!=NULL){
		do{
			if(pivote->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				if(pivote==prim){
					prim = prim->sgt;
					ult->sgt = prim;
				}else if(pivote==ult){
					ant->sgt  = prim;
					ult = ant;
				}else{
					ant->sgt = pivote->sgt;
				}
				printf("\n Nodo Eliminado\n\n");		
				encontrado = 1;
			}
			ant = pivote;
			pivote = pivote->sgt;
		}while(pivote!=prim && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(ant);
		}
	}else{
		printf("\n Su lista se encuentra vacia, ingrese datos por favor\n\n");
	}
}

void mostrarlista(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo = prim;
	if(prim!=NULL){
		do{
			printf("\n %d", nuevo->dato);
			nuevo = nuevo->sgt;
		}while(nuevo!=prim);
	}else{
		printf("\n Su lista se encuentra vacia, ingrese datos por favor\n\n");
	}
}

void ascendente()
{
	system("cls");
	nodo* pivoteant = (nodo*) malloc(sizeof(nodo));
	nodo* pivotepost = (nodo*) malloc(sizeof(nodo));

	if(prim == NULL)
	{
		printf("Su lista esta vacia, inserte datos.\n");
	}else{
		
		if(prim->sgt == NULL)
		{
			printf("Solo exsite un elemento en su lista.\n");
		}else{
			int hola = 0;
			do
			{
				pivoteant = prim;
				pivotepost = prim->sgt;
			 	hola = 0;
				do
				{
					if(pivoteant->dato > pivotepost->dato)
					{
						int aux;
						aux = pivoteant->dato;
						pivoteant->dato = pivotepost->dato;
						pivotepost->dato =aux;
						hola++;
					}
					pivotepost = pivotepost->sgt;
					pivoteant = pivoteant->sgt;
				}while(pivoteant->sgt != NULL);
			}while(hola != 0);
			printf("Su lista fue ordenada.\n");
		}	
	}
	system("pause");
	system("cls");	
}

