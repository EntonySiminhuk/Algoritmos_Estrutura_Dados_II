#include <stdio.h>

int main()
{
	int h, k;
	double tot;

	scanf("%d", &h);
	scanf("%d", &k);
	tot = (k / 12.0) * h;
	printf("%0.3lf\n", tot);
	return 0;
}