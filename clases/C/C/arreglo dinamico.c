#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int *a;
	a = (int *) calloc(5, sizeof(int));
	a[0] = 6;
	a[1]= -512;
	a[2] = 1000;
	a[3] = 500;
	a[4] = 890;
	for (i = 0; i<5; i++)
	{
		printf("%d\n", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}
