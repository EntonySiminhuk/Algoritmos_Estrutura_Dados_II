#include <stdio.h>
#include <math.h>

int main()
{
	char N[50];
	double A, C, X = 0;
	scanf("%s", N);
	scanf("%lf", &A);
	scanf("%lf", &C);
	X = (A + C * 0.15);
	printf("TOTAL = R$ %.2f", X);
}