#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

#define LONGITUD 80
struct cuenta 
{
	char correo[LONGITUD +1];
	char clave[LONGITUD +1];
	char nombre[LONGITUD +1];
	char usuario[LONGITUD +1];
	char clave2[LONGITUD +1];
	char apellido[LONGITUD +1];
};

int main()
{
	int opcion;
	
	struct cuenta e1;
	do
	{
		printf("Bienvenido/a\n");
		printf("1. Ingresar correo.\n");
		printf("2. Ingresar usuario.\n");
		printf("3. Ingresar tu nombre.\n");
		printf("4. Ingrese su contrasena.\n");
		printf("5. Ver todos tus datos.\n");
		printf("6. Salir\n");	
		printf("Ingrese su opcion:\t");
		scanf("%d", &opcion);
		system("cls");
		
		
		switch (opcion)
		{
			case 1:	printf("Ingrese su correo electronico:\t");
					fflush(stdin);
					scanf("%[^\n]s", &e1.correo);
			break;
			case 2:	printf("Ingrese su nombre de usuario:\t");
					fflush(stdin);
					scanf("%[^\n]s", &e1.usuario);
			break;
			case 3:	printf("Ingrese su nombre:\t");
					fflush(stdin);
					scanf("%[^\n]s", &e1.nombre);
			break;
			case 4:	printf("Ingrese su contrasena:\t");
					fflush(stdin);
					scanf("%[^\n]s", &e1.clave);
			break;
			case 5:	printf("Para ver sus datos ingrese su contrasena:\t");
					fflush(stdin);
					scanf("%[^\n]s", e1.clave2);
					if (strcmp(e1.clave, e1.clave2)==0)
					{
						printf("sus datos son:\n");
						printf("1. Usuario:\t %s\n", e1.usuario);
						printf("2. Nombre:\t %s\n", e1.nombre);
						printf("3. Correo:\t %s\n", e1.correo);
					}
					else{
						printf("Su clave es incorrecta.");
					}
			break;
			case 6:
			break;
			default:printf("La opcion ingresada es incorrecta.\n");	
		}	
	}while (opcion != 6);
	return 0;
}
