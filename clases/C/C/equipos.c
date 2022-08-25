#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void qs(int salario[], int limite_izq, int limite_der)
{
	int izq,der,temporal,pivote;
	izq=limite_izq;
	der=limite_der;
	pivote=salario[(izq+der)/2];
	
	do{
		while(salario[izq]<pivote && izq<limite_der)izq++;
		while(pivote<salario[der] && der> limite_izq)der--;
		if(izq<=der)
		{
			temporal = salario[izq];
			salario[izq]=salario[der];
			salario[der]=temporal;
			izq++;
			der--;
		}
	}while(izq<=der);
	if(limite_izq<der) 
	{
		qs(salario, limite_izq,der);
	}
	if(limite_der > izq)
	{
		qs(salario,izq,limite_der);
	}
}
void quicksort(int salario[], int n)
{
	qs(salario,0,n-1);
}
struct empleado
{
	char nombre[30];
	char sexo[12];
	float salario; 
};
 
int main()
{
	struct empleado emp[100];
	int e,nemp,pmay,pmen,i,j;
	float mayor=0.0, menor=9999.0;
	int opcion;
	do
	{
		printf("1. Ingresar empleados y ver el menor y mayor sueldo.\n");
		printf("2. Ver todos los trabajadores.\n");
		printf("3. Ver lista ordenada.");
		printf("4. Salir.\n");
		printf("Opcion a elegir:\t");
		scanf("%d", &opcion);
	
		switch (opcion)
		{
			case 1:	printf("lntroduzca el numero de empleados: ");
					scanf("%d",&nemp);
					for(e=0;e<nemp;e++)
					{
						printf("\n");
						printf("Nombre[%d]: ",e+1);
						fflush(stdin);
						scanf("%[^\n]s",emp[e].nombre);
						fflush(stdin);
						printf("Sexo[%d]: ",e+1);
						scanf("%s",emp[e].sexo);
						fflush(stdin);
						printf("Salario[%d]: ",e+1);
						scanf("%f",&emp[e].salario);
						fflush(stdin);
						if(emp[e].salario>mayor)
						{
							mayor=emp[e].salario;
							pmay=e;
						}
						if(emp[e].salario<menor)
						{
							menor=emp[e].salario;
							pmen=e;
						}
					}
					system("cls");
					printf("\n\n%s es el trabajador con MAYOR salario\n", emp[pmay].nombre);
					printf("%s es el trabajador con MENOR salario\n",emp[pmen].nombre);
					
					
			break;
			case 2:	system("cls");
					printf("Los empleados son:\n");
					for(i=0;i<nemp;i++)
					{
						
						printf("%s\n", emp[i]);
					}
			break;
			case 3:	quicksort(emp, nemp);
					for(j=0;j<nemp;j++)
					{
						printf("%d", emp[j]);
					}
					if(j<nemp-1)
					{
						printf(",");
					}
			break;
			case 4:
			break;
			default: printf("Opcion no valida, intente de nuevo.");
		}
	}while(opcion != 4);
	return 0;
}
		
	
