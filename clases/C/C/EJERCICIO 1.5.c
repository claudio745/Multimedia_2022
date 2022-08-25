#include<stdio.h>
#define LARGO 8000
int main(){
	char cadenita[LARGO + 1];
	char auxiliar;
	int contador1;
	int contador2;
	
	printf("ingrese una cadena corta\n");
	scanf("%[^\n]s", cadenita);
	
	for(contador1=0; cadenita[contador1]; contador1++)
	{
		for(contador2 = 0; cadenita[contador2]; contador2++)
		{
			if(cadenita[contador2] > cadenita[contador1])
			{
				auxiliar = cadenita[contador2];
				cadenita[contador2] = cadenita[contador1];
				cadenita[contador1] = auxiliar;
			}
		}
	}
	printf("El ordenamiento de su palabra es: %s\n", cadenita);
	printf("Gracias por usar nuestro codigo, vuelva pronto.");
	return 0;
}

