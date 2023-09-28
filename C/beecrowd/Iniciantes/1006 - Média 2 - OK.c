#include <stdio.h>
#include <math.h>

int main()
{
	float A, B, C, X = 0;
	scanf("%f", &A);
	scanf("%f", &B);
	scanf("%f", &C);

	X = ((A * 2 + B * 3 + C * 5) / (2 + 3 + 5));
	printf("MEDIA = %.1f\n", X);
}
