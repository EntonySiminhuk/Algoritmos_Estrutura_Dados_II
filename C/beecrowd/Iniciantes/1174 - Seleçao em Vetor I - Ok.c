#include <stdio.h>
int main()
{
	int i;
	float aux, N[100];
	for (i = 0; i < 100; i++)
	{
		scanf("%f", &N[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (N[i] <= 100)
			printf("A[%d] = %0.1f\n", i, N[i]);
	}
	return 0;
}
