#include <stdio.h>

int main()
{
	int h = 0, m = 0, s = 0, x;

	scanf("%d", &x);
	h = (x / 3600);
	m = (x - (3600 * h)) / 60;
	s = (x - (3600 * h) - (m * 60));

	printf("%d:%d:%d\n", h, m, s);
}