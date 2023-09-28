#include <stdio.h>

int main()
{
	int B, G, X = 0;

	scanf("%d", &B);
	scanf("%d", &G);

	G = G / 2.0;
	X = G - B;

	if (X > 0)
		printf("Faltam %d bolinha(s)\n", X);
	else
		printf("Amelia tem todas bolinhas!");

	return 0;
}