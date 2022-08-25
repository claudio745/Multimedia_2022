#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct nodo
{
	int dato;
	struct nodo* sgt;
	struct nodo* ant;
}nodo;

nodo* primero = NULL;
nodo* ultimo= NULL;
int lista=0;

void insertarnodo();
void mostrarlista();
void buscarnodo();
void eliminarnodo();
void ingresarincio();
void ordenadoascendente();
void ordenadodescendente();
void nodoordenado();

int main()
{
	int opcion;
	do
	{
		
	
		printf("Bienvenido, por favor seleccione una de las siguientes opciones:\n\n");
		printf("1. Ingresar nodo al principio.\n");
		printf("2. Ingresar nodo al final.\n");
		printf("3. Mostrar lista\n");
		printf("4. Buscar nodo.\n");
		printf("5 Eliminar nodo.\n");
		printf("6. Ordenar ascendente.\n");
		printf("7. Ordenar descendente.\n");
		printf("8. Ingresar nodo ordenado.\n");
		printf("9. Salir\n");
		printf("su opcion:\t");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
					ingresarincio();
			break;
			case 2:
					insertarnodo();
			break;
			case 3:
					mostrarlista();
			break;
			case 4:
					buscarnodo();
			break;
			case 5:
					eliminarnodo();
			break;
			case 6:
					ordenadoascendente();
			break;
			case 7:
					ordenadodescendente();
			break;
			case 8:
					nodoordenado();
			break;
			case 9:
				break;
			default:
					system("cls");
					printf("Ingrese una opcion valida.\n");
					system("pause");
					system("cls");
			break;
		}
	}while(opcion != 9);
	
	return 0;
}

void insertarnodo()
{
	system("cls");
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("ingrese dato nuevo:\t");
	scanf("%d", &nuevo->dato);
	if(primero==NULL)
	{
		primero = nuevo;
		primero->sgt= NULL;
		ultimo = nuevo;
		lista++;
	}else{
		ultimo->sgt = nuevo;
		nuevo->sgt = NULL;
		nuevo->ant = ultimo;
		ultimo = nuevo;
		lista++;
	}
	printf("su nodo se ha ingresado de manera correcta\n");
	system("pause");
	system("cls");
}

void mostrarlista()
{
	system("cls");
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL)
	{
		while(actual != NULL)
		{
			printf("\n %d", actual->dato);
			actual = actual->sgt;
			
		}
		printf("\n");
	}else{
		printf("\nsu lista se encuentra vacia, ingrese datos para poder desplegar su lista\n");
		
	}
	system("pause");
	system("cls");
}

void buscarnodo()
{
	system("cls");
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodobuscado=0,encontrado= 0;
	printf("\nIngrese el dato del nodo a buscar:\t");
	scanf("%d", &nodobuscado);
	if(primero != NULL)
	{
		while(actual != NULL && encontrado != 1) 
		{
			if(actual->dato == nodobuscado)
			{
				printf(" El nodo con el dato (%d) ha sido encontrado\n", nodobuscado);
				encontrado = 1;
			}
			
			actual = actual->sgt;
		}
		if(encontrado == 0)
		{
			printf("El nodo no ha sido encontrado\n");
		}
	}else{
		printf("su lista se encuentra vacia, ingrese datos para poder desplegar su lista\n");	
	}
	system("pause");
	system("cls");
}

void eliminarnodo()
{
	system("cls");
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* ant = (nodo*) malloc(sizeof(nodo));
	ant = NULL;
	int nodobuscado = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a buscar para eliminar:\t");
	scanf("%d", &nodobuscado);
	if(primero != NULL)
	{
		while(actual != NULL && encontrado != 1) 
		{
			if(actual->dato == nodobuscado)
			{
				if(actual == primero)
				{
					primero = primero->sgt;
				}else if(actual == ultimo){
					ant->sgt = NULL;
					ultimo = ant;
				}else{
					ant->sgt = actual->sgt;
				}
				printf("Nodo eliminado con exito.\n");
				encontrado = 1;
			}
			ant = actual;
			actual = actual->sgt;
		}
		if(encontrado == 0)
		{
			printf("El nodo no ha sido encontrado\n");
		}else{
			free(ant);
			lista--;
		}
	}else{
		printf("su lista se encuentra vacia, ingrese datos para poder desplegar su lista\n");	
	}
	system("pause");
	system("cls");
	
}

void ingresarincio()
{
	system("cls");
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("Ingrese nuevo dato para el inicio:\t");
	scanf("%d", &nuevo->dato);
	if(primero==NULL)
	{
		primero= nuevo;
		primero->sgt = NULL;
		ultimo = nuevo;
	}else{
		primero->ant= nuevo;
		nuevo->sgt = primero;
		primero = nuevo;
	}
	printf("Ingresado de manera correcta.\n");
	lista++;
	system("pause");
	system("cls");
}

void ordenadoascendente()
{
	system("cls");
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	nodo* posterior = (nodo*) malloc(sizeof(nodo));

	if(primero == NULL)
	{
		printf("Su lista esta vacia, inserte datos.\n");
	}else{
		
		if(primero->sgt == NULL)
		{
			printf("Solo exsite un elemento en su lista.\n");
		}else{
			int cambio = 0;
			do
			{
				anterior = primero;
				posterior = primero->sgt;
			 	cambio = 0;
				do
				{
					if(anterior->dato > posterior->dato)
					{
						int aux;
						aux = anterior->dato;
						anterior->dato = posterior->dato;
						posterior->dato =aux;
						cambio++;
					}
					posterior = posterior->sgt;
					anterior = anterior->sgt;
				}while(anterior->sgt != NULL);
			}while(cambio != 0);
			printf("Su lista se ha ordenado de manera satisfactoria.\n");
		}	
	}
	system("pause");
	system("cls");	
}

void ordenadodescendente()
{
	system("cls");
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	nodo* posterior = (nodo*) malloc(sizeof(nodo));

	if(primero == NULL)
	{
		printf("Su lista esta vacia, inserte datos.\n");
	}else{
		
		if(primero->sgt == NULL)
		{
			printf("Solo exsite un elemento en su lista.\n");
		}else{
			int cambio = 0;
			do
			{
				anterior = primero;
				posterior = primero->sgt;
			 	cambio = 0;
				do
				{
					if(anterior->dato < posterior->dato)
					{
						int aux;
						aux = anterior->dato;
						anterior->dato = posterior->dato;
						posterior->dato =aux;
						cambio++;
					}
					posterior = posterior->sgt;
					anterior = anterior->sgt;
				}while(anterior->sgt != NULL);
			}while(cambio != 0);
			printf("Su lista se ha ordenado de manera satisfactoria.\n");
		}	
	}	
	system("pause");
	system("cls");
}

void nodoordenado()
{
	system("cls");
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	nodo* posterior = (nodo*) malloc(sizeof(nodo));
	
	if(primero == NULL)
	{
		insertarnodo();
	}else if(primero->sgt == NULL){
		printf("Solo exsite un elemento en su lista.\n");
	}else{
		anterior = primero;
		posterior = primero->sgt;
		printf("El largo de su lista es de:%d\n", lista);
		int opcion;
		printf("Ingrese en que posicion desea agregar el nuevo nodo:\t");	
		do
		{
			scanf("%d", &opcion);
			if(opcion > lista || opcion < 0)
			{
				printf("Ingrese un valor dentro del largo de la lista:\n");
			}
		}while(opcion > lista || opcion < 0);
		
		int i;
		for(i=1; i<opcion;i++)
		{
			posterior = posterior->sgt;
			anterior = anterior->sgt;
		}	
		printf("Ingrese el valor:\t");
		scanf("%d", &nuevo->dato);
		if(posterior == NULL)
		{
			nuevo->ant = anterior;
			nuevo->sgt = NULL;
			anterior->sgt= nuevo;
		}else{
			nuevo->ant = anterior;
			nuevo->sgt = posterior;
			anterior->sgt = nuevo;
			posterior->ant= nuevo;
		}
		printf("Su nodo se ha ingresado\n");
		lista++;
		system("pause");
		system("cls");			
	}

}
