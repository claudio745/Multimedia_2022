#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct cuentacorriente
{
	int rut;
	int guion;
};
int main()
{
	printf("el saldo inicial de todos los clientes sera de 1.000\n");
	int opcion;
	struct	cuentacorriente a1;
	int saldo = 1000;
	int depositar, retirar;
	do
	{
		printf("Bienvenido\n");
		printf("1. Ingresar su rut.\n");
		printf("2. Mostrar su saldo.\n");
		printf("3. Mostrar numero de cuenta.\n");
		printf("4. Retirar dinero\n");
		printf("5. Depositar dinero\n");
		printf("6. Salir \n");
		printf("Opcion a ingresar:\t");
		scanf("%i", &opcion);
		system("cls");
		
		switch(opcion)
		{
			case 1:	printf("Ingrese su rut en este espacio sin puntos ni guion:\t");
					scanf("%d", &a1.rut);
					fflush(stdin);
					printf("Ingrese su digito verificador (solo numero)");
					scanf("&d", &a1.guion);
			break;
			case 2:	printf("Su saldo es de: %d\n", saldo);
			break;
			case 3:	printf("Su numero de cuenta es: %d\n", a1.rut);
			break;
			case 4:	printf("Cuanto dinero desea retirar?");
					scanf("%d", &retirar);
					if (retirar > saldo)
					{
						printf("La cantidad que desea retirar excede su monto.\n");
					}
					else{
						saldo -= retirar;
					}
					system("cls");
			break;
			case 5:	printf("\n Cuanto dinero desea ingresar a su cuenta?\n");
					scanf("%d", &depositar);
					saldo += depositar;
					system("cls");
			break;
			case 6:
			break;
			default: printf("La opcion ingresada es invalida.\n");
		}
	}while(opcion != 6);
	
	
	
	return 0;
}
