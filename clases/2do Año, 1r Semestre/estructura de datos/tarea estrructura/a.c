#include <stdio.h>
#define N 3
void main()
{
	int m[N][N] = {{0,0,0}, {1,1,1}, {2,2,2}};
	int x;
	int y;
	
	for(x=1; x < N; x++)
	{
		for(y=0; y < N; y++)
		{
			m[x][y] = m[x][y] + m[x-1][y];
		}
	}
	printf("%i, %i, %i", m[0][0], m[1][1], m[2][2]);
	
}
