#include <stdio.h>
#include <stdlib.h>

typedef struct nodos
{
	int nodito;
	struct nodo* sgt;
	struct nodo* ant;
	
}tnodo;


typedef tnodo *tpuntero;

void insertarnodo (tpuntero *cabeza, int e);
void imprimirlista (tpuntero cabeza);
void borrarlista (tpuntero *cabeza);
void insertarinicio( tpuntero *cabeza, int case2);
void insertarfinal(tpuntero *cabeza, int a);


void menulista();


int main()
{
	tpuntero cabeza;
	cabeza = NULL;
	int opcion;
	int e;
	int case5;
	int case2;
	int case3;
	do
	{
		printf("Bienvenido, seleccione una opcion.\n");
		printf("1. Ingresar nodos\n");
		printf("2. Ingresar nodo al inicio\n");
		printf("3. Ingresar nodo al final\n");
		printf("4. Ingresar nodo ordenado\n");
		printf("5. Mostrar lista completa\n");
		printf("6. Ordenar lista ascendente\n");
		printf("7. Ordenar lista descendente\n");
		printf("8. Buscar y mostrar nodo\n");
		printf("9. Eliminar nodos\n");
		printf("10. Pasar lista a archivo de texto \n");
		printf("11. leer lista desde un archivo de texto\n");
		printf("12. Salir\n");
		printf("Opcion:\t");
		scanf("%d", &opcion);
	
		switch(opcion)
		{
			case 1:
					system("cls");
					printf("Ingrese valores, si no quiere ingresar ingrese -1:\t");
					scanf("%d", &e);
					while(e!=-1)
					{
						insertarnodo(&cabeza, e);
						printf("Se ha ingresado correctamente.\n");
						printf("Ingrese valores, ingrese -1 para detenerse:\t");
						scanf("%d", &e);
						system("cls");
					}		
			break;
			case 2:	
					system("cls");
					printf("ingrese el valor nuevo para el inicio:\t");
					scanf("%d", &case2);
					insertarinicio(&cabeza, case2);
					printf("\n");
					printf("se ha ingresado de manera correcta.\n");
					system("pause");
					system("cls");
					
					
			break;
			case 3:
				system("cls");
				printf("ingrese un valor final:\t");
				scanf("%d", &case3);
				insertarfinal(&cabeza, case3);
			break;
			case 4:
			break;
			case 5: printf("Sus valores son:");
					do
					{
						imprimirlista (cabeza);
						printf("\n");
						printf("Para dejar de ver la lista ingrese 1\t");
						scanf("%d", &case5);
						
					}while(case5!= 1);
					system("cls");
			break;
			case 6:
			break;
			case 7:
			break;
			case 8:
			break;
			case 9:
			break;
			case 10:
			break;
			case 11:
			break;
			case 12:
			break;
			default:
			break;
		}
	}while(opcion != 12);
		
	return 0;
}



void insertarnodo (tpuntero *cabeza, int e)
{
    tpuntero nuevo; 
    nuevo = malloc(sizeof(tnodo));
    nuevo->nodito = e;
    nuevo->sgt = *cabeza; 
    *cabeza = nuevo; 
}
 
void imprimirlista(tpuntero cabeza)
{
    while(cabeza != NULL)
	{ 
        printf("%4d",cabeza->nodito);
        cabeza = cabeza->sgt;
    }
    
}

void borrarlista(tpuntero *cabeza)
{ 
    tpuntero actual; 
  
    while(*cabeza != NULL)
	{ 
        actual = *cabeza; 
        *cabeza = (*cabeza)->sgt;
        free(actual); 
	}
}

void insertarinicio( tpuntero *cabeza, int case2)
{
	tpuntero nuevo; 
    nuevo = malloc(sizeof(tnodo));
    nuevo->nodito = case2;
    nuevo->sgt = *cabeza; 
    *cabeza = nuevo;
}

void insertarfinal(tpuntero *cabeza, int a)
{
	/*
	void insertarnodo (tpuntero *cabeza, int e)
{
    tpuntero nuevo; 
    nuevo = malloc(sizeof(tnodo));
    nuevo->nodito = e;
    nuevo->sgt = *cabeza; 
    *cabeza = nuevo; 
}
	*/
	
	tpuntero final, actual;
	final = malloc(sizeof(tnodo));
	if(cabeza == NULL)
	{
		final->nodito = a;
		final->sgt = *cabeza;
		*cabeza = final;
	}else{
		final->sgt = *cabeza;
		while(*cabeza != NULL){
			final->sgt = *cabeza;
			cabeza = cabeza->sgt;
		}
		printf("%d", final->sgt);
		/*
		while(cabeza != NULL ) 
		{
			cabeza = *cabeza->sgt;
		}
		final->sgt = *cabeza->sgt;
		*/
	}
}




void menulista()
{
}





