#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Sele_atividade(int id[], int inicio[], int fim[], int n)
{
	int i, j, ig, igaux, selecionado = 0;

	if (n == 0)
		return 0;
	int fims = fim[0];

	// pegando a atividade que termina primeiro
	for (i = 0; i < n; i++)
	{
		if (fim[i] < fims)
		{
			fims = fim[i];
			ig = i;
		}
	}

	int cont;
	printf("Aulas alocadas: %d ", id[ig]);
	selecionado++;
	// pegando as atividade que terminam primeiro pós a primeira
	for (i = 0; i < n; i++)
	{
		igaux = ig;
		if (inicio[i] > fim[igaux])
		{
			fims = fim[i];
			for (j = 0; j < n; j++)
			{
				if ((inicio[j] > fim[igaux]) && (fim[j] <= fims))
				{
					fims = fim[j];
					ig = j;
					i = 0;
				}
			}
			cont++;
			printf("%d ", id[ig]);
			selecionado++;
		}
		if (cont == 10)
			break;
		;
	}
	printf(" \n ");
	return selecionado;
}

int main()
{
	int i, n;

	scanf("%d", &n);

	int id[n], v_ini[n], v_fim[n];

	for (i = 0; i < n; i++)
		scanf("%d %d %d", &id[i], &v_ini[i], &v_fim[i]);

	Sele_atividade(id, v_ini, v_fim, n);
}