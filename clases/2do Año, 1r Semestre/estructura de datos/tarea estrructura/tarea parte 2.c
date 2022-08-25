#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct Componente
{
    int codigo;
    char nombre[25];
}Componente;

typedef struct Residuo
{
    int codigo;
    float pesoHumedo;
    float pesoSeco;
}Residuo;


void main()
{
    setlocale(LC_ALL, "spanish");
    int i;
    int j = 0;
    int humsec;
    Componente comp[6];
    Residuo res[6][7];
    int opcion;
    int seleccion;
    strcpy(comp[0].nombre, "Madera");
    strcpy(comp[1].nombre, "Metales");
    strcpy(comp[2].nombre, "Papel y Carton");
    strcpy(comp[3].nombre, "Plasticos");
    strcpy(comp[4].nombre, "Textiles");
    strcpy(comp[5].nombre, "Vidrio");

    comp[0].codigo = 10;
    comp[1].codigo = 20;
    comp[2].codigo = 30;
    comp[3].codigo = 40;
    comp[4].codigo = 50;
    comp[5].codigo = 60;
    
    
    res[0][0].codigo = 10;
    res[1][0].codigo = 20;
    res[2][0].codigo = 30;
    res[3][0].codigo = 40;
    res[4][0].codigo = 50;
    res[5][0].codigo = 60;  
    
    res[0][0].pesoHumedo = 2.55;
    res[0][0].pesoSeco = 1.53;
    res[1][0].pesoHumedo = 2.56;
    res[1][0].pesoSeco = 2.46;
    res[2][0].pesoHumedo = 29.55;
    res[2][0].pesoSeco = 26.60;
    res[3][0].pesoHumedo = 17.29; 
    res[3][0].pesoSeco = 16.60;
    res[4][0].pesoHumedo = 4.67;
    res[4][0].pesoSeco = 3.97;
    res[5][0].pesoHumedo = 15.12;
    res[5][0].pesoSeco =  14.54;
    
    
    do
    {
        do
        {
            printf("Escoja una de las siguientes opciones:\n");
            printf("1-. Madera.\n");
            printf("2-. Metales.\n");
            printf("3-. Papeles y Carton.\n");
            printf("4-. Plasticos.\n");
            printf("5-. Textiles.\n");
            printf("6-. Vidrio.\n");
            printf("Opcion a elegir:\t");
            scanf("%d", &opcion);


        }while(opcion < 0 || opcion > 7);
        do
        {
        	printf("¿Desea ingresar el material en peso humedo o peso seco?, 1 para seco, 2 para humedo.");
        	scanf("%i", &humsec);
		}while(humsec != 1 && humsec != 2);
		if(humsec == 1)
		{
			for(i = 1; i < 7; i++)
            {
                printf("Ingrese valor del peso seco para el dia %d:", i+1);
                scanf("%f", &res[opcion-1][i].pesoSeco);
            }
		}
		if(humsec == 2)
		{
			for(i = 1; i < 7; i++)
            {
                printf("Ingrese valor del peso humedo para el dia %d:", i+1);
                scanf("%f", &res[opcion-1][i].pesoHumedo);
            }	
		}
		

       
        
        printf("Desea registrar otro material? 1 para si, 2 para no: ");
        scanf("%d", &seleccion);
    }while(seleccion !=2);
    
	
	char material[20];
	char cadena1[20];
	char cadena2[20];
	float suma;
	int k;
	float promedio;

	printf("Ingrese un nombre de residuo para buscar su promedio de peso seco:\t");
	scanf("%s", &material);
	
	for(i = 0; i < 6; i++)
	{
		strcpy(cadena1, comp[i].nombre);
		strcpy(cadena2, material);
		if(strcmp (strupr(cadena1), strupr(cadena2)) == 0)
		{
			for(j = 0; j < 6; j++)
			{
				if(res[j][0].codigo == comp[i].codigo)
				{
					for(k= 0; k < 7; k++)
					{
						suma = res[j][k].pesoSeco + suma;
						promedio = ((float) suma/7);
					}
				}	
			}		
		}	
	}
	printf("su promedio es:");
	printf("%.2f\n", promedio);
	
	float max = 0;
	int pos;
	for(i = 0; i < 6; i++)
	{
		suma = 0;
		for(j = 0; j < 7; j++)
		{
			suma = res[j][k].pesoSeco + suma;
			
		}
		if(max < suma)
		{
			pos = i;
			max = suma;
		}
	}
	printf("El material %s es mayor con una cantidad de: %.2f toneladas.\n", comp[pos].nombre, max);
	
	float total = 0;
	
	for( i = 0; i < 6; i++)
	{
		suma = 0;
		for(j = 0; j < 7; j++)
		{
			suma = res[i][j].pesoHumedo + res[i][j].pesoSeco + suma;
		}
		total = total + suma;
	}
	for( i = 0; i < 6; i++)
	{
		suma = 0;
		for(j = 0; j < 7; j++)
		{
			suma = res[i][j].pesoHumedo + res[i][j].pesoSeco + suma;
			
		}
		printf("Promedio de %s es: %.2f\n", comp[i].nombre, ((suma*100)/total));
	}	
}
