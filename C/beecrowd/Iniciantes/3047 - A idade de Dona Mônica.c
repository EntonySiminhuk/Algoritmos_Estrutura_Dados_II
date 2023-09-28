#include <stdio.h>

int main()
{
	int M, A, B, X;

	scanf("%d", &M);
	scanf("%d", &A);
	scanf("%d", &B);
	if ((M <= 110) || (M >= 1) || (A >= 1) || (A < M) || (B >= 1) || (B < M) || (A != B))
	{
		X = (M - A) - B;
	}
	if ((X > A) && (X > B))
		printf("%d\n", X);
	else if ((X < A) && (A > B))
		printf("%d\n", A);
	else if ((X < B) && (A < B))
		printf("%d\n", B);
	return 0;
}
