#include<stdio.h>

void copiandoarrays(int a[], int b[], int tamanio);
void copiararrays2(int f[], int g[], int tamanio2);
int main()
{
	int i, j, aux;
	int arraypares[4] = {10, 2, 4, 6};
	int arrayimpares[4] = {9, 5, 1, 3};
	int arraydos[4];
	int arraytres[4];
	copiandoarrays(arraypares, arraydos, 4);
	copiandoarrays2(arrayimpares, arraytres, 4);
	
	return 0;
}


void copiandoarrays(int a[], int b[], int tamanio)
{
	int x, z;
	for(x = 0;x<tamanio; x++)
	{
		b[x] = a[x];
	}
	for(z=0; z<tamanio; z++)
	{	
		printf("\n%i", b[z]);
	}
}
void copiandoarrays2(int f[], int g[], int tamanio2)
{
	int h,k;
	for(h = 0;h<tamanio2; h++)
	{
		g[h] = f[h];
	}
	for(k=0; k<tamanio2; k++)
	{	
		printf("\n%i", g[k]);
	}
}

