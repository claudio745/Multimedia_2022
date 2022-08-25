#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertar();
void buscar();
void modificarNodo();
void eliminar();
void MostrarLista();

int main(){
	int opcion = 0;
	do{

		printf("\n| 1. Insertar      | 4.Mostrar Lista"); 
		printf("\n| 2. Buscar        | 5. Salir");
		printf("\n| 3. Eliminar");
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
				MostrarLista();
				break;
			case 5:
				printf("\n\n Programa finalizado");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcion != 5);
	return 0;
}


void insertar(){
	system("cls");
	nodo* nuevonodo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el nuevo dato: ");
	scanf("%d", &nuevonodo->dato);
	if(primero==NULL){
		primero = nuevonodo;
		primero->siguiente = NULL;
		ultimo = nuevonodo;
	}else{
		ultimo->siguiente = nuevonodo;
		nuevonodo->siguiente = NULL;
		ultimo = nuevonodo;
	}
	printf("\n Nodo ingresado con satisfaccion\n\n");
	system("pause");
	system("cls");
}

void buscar(){
	system("cls");
	nodo* pivote1 = (nodo*) malloc(sizeof(nodo));
	pivote1 = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(pivote1 != NULL && encontrado != 1){
			
			if(pivote1->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
				
			pivote1 = pivote1->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}
	}else{
		printf("\n La lista esta vacia\n\n");
	}
	system("pause");
	system("cls");
}

void eliminar(){
	system("cls");
	nodo* pivote2 = (nodo*) malloc(sizeof(nodo));
	pivote2 = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(pivote2 != NULL && encontrado != 1){
			
			if(pivote2->dato == nodoBuscado){
	
				if(pivote2 == primero){
					primero = primero->siguiente;
				}else if(pivote2 == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = pivote2->siguiente;
				}
				
				printf("\n Nodo eliminado con satisfaccion");
				encontrado = 1;
			}
			anterior = pivote2;
			pivote2 = pivote2->siguiente;
		}
		if(encontrado == 0){
			printf("\n El nodo no fue encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista esta vacia\n\n");
	}
	system("pause");
	system("cls");
}

void MostrarLista(){
	system("cls");
	nodo* pivote = (nodo*) malloc(sizeof(nodo));
	pivote = primero;
	if(primero!=NULL){
		while(pivote != NULL){
			printf("\n %d\n", pivote->dato);
			pivote = pivote->siguiente;
		}
	}else{
		printf("\n La lista esta vacia\n\n");
	}
	system("pause");
	system("cls");
}
