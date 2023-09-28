#include <stdio.h>
#include <math.h>

int main()
{
	float A, B, X = 0;
	scanf("%f", &A);
	scanf("%f", &B);

	X = ((A * 3.5 + B * 7.5) / (3.5 + 7.5));
	printf("MEDIA = %.5f\n", X);
}
