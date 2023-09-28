#include <stdio.h>
#include <math.h>

int main()
{
	int A, B;
	float C, X = 0;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%f", &C);

	X = (B * C);
	printf("NUMBER = %d\n", A);
	printf("SALARY = U$ %.2f\n", X);
}