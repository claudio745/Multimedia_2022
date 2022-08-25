//Nombre integrante 1: Claudio Alfaro 
//Nombre intgerante 2: Dylan Baez

#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct Afp
{
	short int codigo;	//Por ejemplo: 1003
	char nombre[15];	//Por ejemplo: AFP Cuprum
}Afp;

typedef struct Cotizante
{ 
	int rut;			//Sin dígito verificador
	short int codigo;	//Código de la AFP a la que pertenece el cotizante
	char tipo[2];		//Tipo de cotizante: D (Dependiente), I (Independiente)
	int fondo;			//Ahorro total del cotizante en la AFP
	char genero[2];		//Género del cotizante: F (Femenino), N (Masculino)
	int retiro[3];		//Monto en pesos de cada retiro de 10% que haya efectuado el cotizante
}Cotizante;

void main()
{
	setlocale(LC_ALL, "spanish");
	Afp afp[7];
	Cotizante cotiz[5];
	
	//1. Inicializa las variables afp y cotiz. 
	//   La primera con 4 AFPs (Buscar en Superintendencia de Pensiones)
	//	 La segunda con 5 cotizantes (usar datos variados)
	
	strcpy(afp[0].nombre, "capital");
	strcpy(afp[1].nombre, "cuprum");
	strcpy(afp[2].nombre, "provida");
	strcpy(afp[3].nombre, "modelo");

	afp[0].codigo = 1033;
	afp[1].codigo = 1003;
	afp[2].codigo = 1008;
	afp[3].codigo = 1034;
	
	cotiz[0].rut = 209558122;
	cotiz[0].codigo = 1034;
	strcpy(cotiz[0].genero, "N");
	strcpy(cotiz[0].tipo, "I");
	cotiz[0].retiro[0] = 4300000;
	cotiz[0].retiro[1] = 4300000;
	cotiz[0].retiro[2] = 4300000;
	cotiz[0].fondo = 50000000;
	
	cotiz[1].rut = 19020090;
	cotiz[1].codigo = 1033;
	strcpy(cotiz[1].genero, "F");
	strcpy(cotiz[1].tipo, "I");
	cotiz[1].retiro[0] = 400000;
	cotiz[1].retiro[1] = 390000;
	cotiz[1].retiro[2] = 380000;
	cotiz[1].fondo = 40000000;
	
	cotiz[2].rut = 20203076;
	cotiz[2].codigo = 1033;
	strcpy(cotiz[2].genero, "F");
	strcpy(cotiz[2].tipo, "I");
	cotiz[2].retiro[0] = 4000000;
	cotiz[2].retiro[1] = 3600000;
	cotiz[2].retiro[2] = 3200000;
	cotiz[2].fondo = 40000000;
	
	cotiz[3].rut = 13020081;
	cotiz[3].codigo = 1003;
	strcpy(cotiz[3].genero, "F");
	strcpy(cotiz[3].tipo, "D");
	cotiz[3].retiro[0] = 430000;
	cotiz[3].retiro[1] = 0;
	cotiz[3].retiro[2] = 0;
	cotiz[3].fondo = 100000000;
	
	cotiz[4].rut = 20360471;
	cotiz[4].codigo = 1034;
	strcpy(cotiz[4].genero, "N");
	strcpy(cotiz[4].tipo, "D");
	cotiz[4].retiro[0] = 100000;
	cotiz[4].retiro[1] = 0;
	cotiz[4].retiro[2] = 0;
	cotiz[4].fondo = 100000;

	//2. Mostrar, por cada cotizante su rut, género, fondo y total retirado.

	printf("%s\n", afp[0].nombre);
	printf("%s\n", afp[1].nombre);
	printf("%s\n", afp[2].nombre);
	printf("%s\n", afp[3].nombre);
	
	printf("\n");
	
	int x;
	
	for (x=0; x<5; x++)
	{
		printf("Rut:\t %i \n", cotiz[x].rut);
		printf("Codigo afp:\t %i \n", cotiz[x].codigo);
		printf("Genero:\t%s\n", cotiz[x].genero);
		printf("Tipo:\t%s\n", cotiz[x].tipo);
		printf("Retiro 1:\t%i\n", cotiz[x].retiro[0]);
		printf("Retiro 2:\t%i\n", cotiz[x].retiro[1]);
		printf("Retiro 3:\t%i\n", cotiz[x].retiro[2]);
		printf("Fondo:\t%i\n\n", cotiz[x].fondo);
	}
	
	//3. Para una AFP indicada por el usuario, mostrar por cada uno de sus cotizantes: 
	//   rut, tipo y cantidad de retiros
	//   Validar lo que corresponda
	
	int codigoafp;
	int i;
	int j;
	char nomafp[10];
	
	printf("Ingrese el nombre de su afp:\t");
	gets(nomafp);
	
	short int contador = 0;
	for(i=0; i < 7; i++)
	{
		char cadena1[20];
		char cadena2[20];
		
		strcpy(cadena1, afp[i].nombre);
		strcpy(cadena2, nomafp);
		if(strcmp (strupr(cadena1), strupr(cadena2)) == 0)
		{
			contador++;
			for(j = 0; j < 5; j++)
			{
				if(afp[i].codigo == cotiz[j].codigo)
				{
					printf("cotizante %d:\n", j);
					printf("%i Rut:\n", cotiz[j].rut);
					printf("%s Genero:\n", cotiz[j].genero);
					printf("%s Tipo:\n", cotiz[j].tipo);
					printf("%i\n\n", cotiz[j].retiro);		
				}
			}
		}	
	}	
	
	if(contador == 0){
			printf("Afp no encontrada\n");
		}
	
	//4. Para un cotizante indicado por el usuario, permitir efectuar un retiro del 10%, si corresponde.
	//   Tener presente que puede haber cotizantes que aún no hayan cursado los retiros anteriores.
	//   Analizar detenidamente la situación.
	//   Validar lo que corresponda
	
	int rutbus;
	int posicion;
	int consulta;
	
	printf("Ingrese el rut del cotizante buscado:\t");
	scanf("%i", &rutbus);
	
	for(i=0; i < 5; i++)
	{
		if (cotiz[i].rut == rutbus)
		{
			contador = 0;
			for(j = 0; j < 3; j++)
			{
				if(cotiz[i].retiro[j] > 0)
				{
					contador++;
					
				}
				else{
					posicion = j;
				}	
			}
			if( contador == 3)
			{
				printf("Usted no puede realizar más retiros.");
			}
			else{
				printf("¿Desea solicitar un retiro?, presione 1 para si, 0 para no \t");
				do
				{
					scanf("%i", &consulta);
					if(consulta != 1 || consulta != 0)
					{
						printf("Intente nuevamente.\n");
						printf("¿Desea solicitar un retiro?, presione 1 para si, 0 para no\t \n");	
					}
				}while(consulta != 1 && consulta != 0);
				
				if(consulta == 1)
				{
					int monto;
					monto = cotiz[i].fondo * 0.1;
					
					cotiz[i].fondo = cotiz[i].fondo - monto;
					
					
					cotiz[i].retiro[posicion] = monto; 
					printf("Solicitud realizada con exito.");
				}	
			}
		}		
	}
}
