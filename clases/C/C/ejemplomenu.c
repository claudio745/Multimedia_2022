#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int opcion;
	char temp[10];
	
	do{
		printf("1) opcion 1\n");
		printf("2) opcion 2\n");
		printf("3) opcion 3\n");
		printf("4) salir\n");
		fgets(temp,10,stdin);
		opcion = atoi(temp);	
		switch(opcion){
			case 1:
				printf("usted selecciono %i\n", opcion);
			break;
			case 2:
				printf("usted selecciono %i\n", opcion);
			break;
			case 3:
				printf("usted selecciono %i\n", opcion);
			break;
			case 4:
			break;
			default:
				printf("opcion incorrecta\n");
			break;
		}
		
	}while(opcion != 4);
}
