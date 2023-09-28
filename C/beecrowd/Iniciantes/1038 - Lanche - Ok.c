#include <stdio.h>

int main()
{
	int V, Q;
	float VTOT;

	scanf("%d", &V);
	scanf("%d", &Q);

	VTOT = V * Q;
	if (V == 1)
	{
		VTOT = Q * 4.00;
		printf("Total: R$ %0.2lf\n", VTOT);
	}
	else if (V == 2)
	{
		VTOT = Q * 4.50;
		printf("Total: R$ %0.2lf\n", VTOT);
	}
	else if (V == 3)
	{
		VTOT = Q * 5.00;
		printf("Total: R$ %0.2lf\n", VTOT);
	}
	else if (V == 4)
	{
		VTOT = Q * 2.00;
		printf("Total: R$ %0.2lf\n", VTOT);
	}
	else if (V == 5)
	{
		VTOT = Q * 1.50;
		printf("Total: R$ %0.2lf\n", VTOT);
	}
	return 0;
}