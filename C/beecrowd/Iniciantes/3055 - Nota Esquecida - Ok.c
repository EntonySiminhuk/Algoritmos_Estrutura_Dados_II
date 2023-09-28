#include <stdio.h>

int main()
{
	int A, M, AUX, B;

	scanf("%d", &A);
	scanf("%d", &M);

	AUX = A - M;
	B = A + M;
	B = B - AUX;
	B = B - A;
	printf("%d\n", B);
	return 0;
}
