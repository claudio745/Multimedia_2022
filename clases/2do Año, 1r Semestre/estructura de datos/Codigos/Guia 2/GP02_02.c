#include <stdio.h>

typedef struct Hora
{
	short int hh;
	short int mm;
}Hora;

void main()
{
	Hora hhmm;
	short int horas;
	short int minutos;
	
	do
	{
		printf("Ingrese la parte correspondiente a la hora (hh:mm): ");
		scanf("%i",&hhmm.hh);
	}while(hhmm.hh < 0 || hhmm.hh > 23);
	
	do
	{
		printf("Ingrese la parte correspondiente a los minutos (hh:mm): ");
		scanf("%i",&hhmm.mm);
	}while(hhmm.mm < 0 || hhmm.hh > 59);
	
	if(hhmm.mm == 59)
	{
		minutos=0;
				
		if(hhmm.hh == 23)		
			horas=0;
		else
			horas=hhmm.hh+1;
	}
	else
	{
		horas=hhmm.hh;
		minutos=hhmm.mm+1;
	}
		
	if(horas < 10 && minutos >= 10)
		printf("La hora %i:%i incrementada en 1 minuto es: 0%i:%i",hhmm.hh,hhmm.mm,horas,minutos);
	if(horas >= 10 && minutos < 10)
		printf("La hora %i:%i incrementada en 1 minuto es: %i:0%i",hhmm.hh,hhmm.mm,horas,minutos);	
	if(horas < 10 && minutos < 10)
		printf("La hora %i:%i incrementada en 1 minuto es: 0%i:0%i",hhmm.hh,hhmm.mm,horas,minutos);
	if(horas >= 10 && minutos >= 10)
		printf("La hora %i:%i incrementada en 1 minuto es: %i:%i",hhmm.hh,hhmm.mm,horas,minutos);
}
