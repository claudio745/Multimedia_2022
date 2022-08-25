#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct datos 
{
	char nombre[40]; 
	char pais[25]; 
}; 
struct atletas 
{ 
	char deporte[30];
	int tiempo;
	struct datos pers; 
}; 
struct atletas ats[3];
 
int main() 
{
	int a,posmay,maynmed=0;
	for(a=0;a<3;a++)
	{
		printf("\n");
		printf("Nombre[%d]: ",a+1);
		scanf("%s",ats[a].pers.nombre);
		printf("Pais[%d]: ",a+1);
		scanf("%s",ats[a].pers.pais);
		printf("Deporte[%d]: ",a+1);
		scanf("%s",ats[a].deporte);
		printf("Tiempo[%d]: ",a+1);
		scanf("%d",&ats[a].tiempo); 
	}
	for(a=1;a<3;a++) 
	{
		if(ats[a].tiempo>maynmed) 
		{
			posmay=a;
			maynmed=ats[a].tiempo;
		}
	} 
	printf(" \n \t****DATOS DEL ATLETA CON MAYOR TIEMPO****\n");
	printf("NOMBRE: %s\n",ats[posmay].pers.nombre);
	printf("PAIS: %s\n",ats[posmay].pers.pais);
	printf("DEPORTE: %s\n",ats[posmay].deporte);
	printf("TIEMPO: %d\n",ats[posmay].tiempo);
	return 0; 
}

