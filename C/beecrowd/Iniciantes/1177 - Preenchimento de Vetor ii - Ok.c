#include <stdio.h>
int main()
{
	int i, T, N[1000], X = 0;
	scanf("%d", &T);
	for (i = 0; i < 1000; i++)
	{
		printf("N[%d] = %d\n", i, X);
		X++;
		if (X == T)
			X = 0;
	}
	return 0;
}