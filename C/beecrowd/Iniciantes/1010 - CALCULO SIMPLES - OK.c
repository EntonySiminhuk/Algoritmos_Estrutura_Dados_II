#include <stdio.h>

int main()
{
	int P1, C1, P2, C2;
	float V1, V2, TOT1, TOT2;

	scanf("%d %d %f", &C1, &P1, &V1);
	scanf("%d %d %f", &C2, &P2, &V2);
	TOT1 = (V1 * P1);
	TOT2 = (V2 * P2);
	printf("VALOR A PAGAR: R$ %.2f", (TOT1 + TOT2));
}