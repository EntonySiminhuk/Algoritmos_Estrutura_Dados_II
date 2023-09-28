#include <stdio.h>
#include <math.h>

int main()
{
	double R, TOT, pi;
	pi = 3.14159;
	scanf("%lf", &R);
	R = (pow(R, 3));
	TOT = (4 / 3.0 * pi * R);
	printf("VOLUME = %0.3lf\n", TOT);
}