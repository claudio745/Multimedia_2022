#include<stdio.h>

int main(){
	char cad[10];
	char aux;
	int i;
	int j;
	short int repetidor;
	
	do 
	{
		printf("ingrese una cadena corta\n");
		scanf("%[^\n]s", cad);
	
		for(i=0; cad[i]; i++)
		{
			for(j = 0; cad[j]; j++)
			{
				if(cad[j] > cad[i])
				{
					aux = cad[j];
					cad[j] = cad[i];
					cad[i] = aux;
				}
			}
		}
		printf("Su palabra ordenada es: %s\n", cad);	
		printf("Para repetir con otra palabra ingrese cualquier numero, para salir ingrese 1. \n");
		scanf("%d", &repetidor);
		printf("");
	}while (repetidor == 1);

	
	return 0;
}

