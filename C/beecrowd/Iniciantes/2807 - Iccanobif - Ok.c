#include <stdio.h>

int main()
{
	int x, N[40], cont;
	scanf("%d", &x);
	N[0] = 1;
	N[1] = 1;
	cont = 2;

	while (cont < x)
	{
		N[cont] = N[cont - 1] + N[cont - 2];
		cont++;
	}

	if (x > 1)
	{
		while (cont > 1)
		{
			printf("%d ", N[--cont]);
		}
	}
	printf("%d\n", N[0]);

	return 0;
}
