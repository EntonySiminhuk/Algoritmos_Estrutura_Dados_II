#include <stdio.h>

int main()
{
	int x, ano = 0, mes = 0, dia = 0;

	scanf("%d", &x);

	while (x > 0)
	{
		if (x > 364)
		{
			(x = x - 365);
			ano++;
		}
		if (x > 29)
		{
			x = x - 30;
			mes++;
		}
		if (x > 0)
		{
			x = x - 1;
			dia++;
		}
	}
	printf("%d ano(s)\n", ano);
	printf("%d mes(es)\n", mes);
	printf("%d dia(s)\n", dia);
}