#include <stdio.h>

void main()
{
	//En estos casos, queda determinado el tama�o de los vectores 
	//a partir de los elementos que los definen
	//Sin embargo, en el c�digo, puede llevar a confusi�n al momento de trabajar los l�mites dle vector
	
	//short int u[][]={{6,18,29},{3,-11,13},{15,-5,19}};
	
	//float v[][]={{0.85,6.50,6.95,0.42,3.10},{0.74,7.20,7.15,0.62,2.60},{1.05,6.85,6.75,0.55,2.95}};
	
	//Se sugiere
	
	short int u[3][3]={{6,18,29},{3,-11,13},{15,-5,19}};
	
	float v[3][5]={{0.85,6.50,6.95,0.42,3.10},{0.74,7.20,7.15,0.62,2.60},{1.05,6.85,6.75,0.55,2.95}};
}
