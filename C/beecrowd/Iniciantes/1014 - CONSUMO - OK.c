#include <stdio.h>

int main()
{
	int x;
	double y, tot;

	scanf("%d", &x);
	scanf("%lf", &y);
	tot = (x / y);
	printf("%0.3lf km/l\n", tot);
}