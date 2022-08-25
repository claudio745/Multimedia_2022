typedef struct Carrera
{
	char 	  nombre[50];
	short int duracion;		//duración en semestres
	int		  arancel;
	short int codigo;
	short int agnoCreacion;
	short int acreditacion; //Si está o no acreditada
}Carrera;


typedef struct Hora
{
	short int hh;
	short int mm;
}Hora;


typedef struct Fraccion
{
	short int entero;
	int       numerador;
	int       denominador;
}Fraccion;

void main()
{
}
