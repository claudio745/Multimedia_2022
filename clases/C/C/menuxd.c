#include<stdio.h>

int main (){
	
	int opcion;
	float agregar, retirar, saldo = 1000;
	
	printf("\tBienvenido a su cajero virtual");
	printf("\n1. Ingreso de dinero a su cuenta.");
	printf("\n2. Retiro de dinero.");
	printf("\n3. Salir");
	printf("\nOpcion: ");
	scanf("%i", &opcion);
	
	switch(opcion){
		case 1: printf("\n Cuanto dinero desea ingresar a su cuenta?\n");
				scanf("%f", &agregar);
				saldo += agregar;
				printf("El saldo total es de: %.2f", saldo);
		break;
		case 2: printf("Cuanto dinero desea retirar?.\n");
				scanf("%f", &retirar);
				if(retirar > saldo){
					printf("la cantidad que desea retirar excede su saldo actual\n");
				}
				else{
					saldo -= retirar;
					printf("El saldo disponible es de: %f\n", saldo);
				}
		break;
		case 3: break;
		default: printf("la opcion que usted ingreso es invalida.");		
	}
	
	
	
	return 0;
}
	
