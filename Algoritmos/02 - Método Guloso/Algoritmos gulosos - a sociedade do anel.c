#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int somalabirinto(int l, int c, int **matriz)
{
    int i, j, soma;

    i = 0;
    j = 0;
    soma = 0;

    int cima, baixo, esquerda, direita;

    while (i != l - 1 || j != c - 1)
    {

        cima = INT_MAX;
        baixo = INT_MAX;
        direita = INT_MAX;
        esquerda = INT_MAX;

        if (i > 0)
        {
            cima = matriz[i - 1][j];
        }
        if (i < l - 1)
        {
            baixo = matriz[i + 1][j];
        }
        if (j > 0)
        {
            esquerda = matriz[i][j - 1];
        }
        if (j < c - 1)
        {
            direita = matriz[i][j + 1];
        }

        if (esquerda == INT_MAX && direita == INT_MAX && cima == INT_MAX && baixo == INT_MAX)
        {
            return -1;
        }

        if (cima <= baixo && cima <= direita && cima <= esquerda) // pra cima
        {
            matriz[i][j] = INT_MAX;
            i--;
            soma = matriz[i][j] + soma;
        }
        else if (direita <= baixo && direita <= cima && direita <= esquerda) // pra direita
        {
            matriz[i][j] = INT_MAX;
            j++;
            soma = matriz[i][j] + soma;
        }
        else if (baixo <= cima && baixo <= direita && baixo <= esquerda) // pra baixo
        {
            matriz[i][j] = INT_MAX;
            i++;
            soma = matriz[i][j] + soma;
        }
        else if (esquerda <= baixo && esquerda <= cima && esquerda <= direita) // pra esquerda
        {
            matriz[i][j] = INT_MAX;
            j--;
            soma = matriz[i][j] + soma;
        }
    }

    return soma;
}

int main()
{
    int l, c, soma;

    scanf("%d %d", &l, &c);

    int i, j, n;

    int **matriz = (int **)malloc(l * sizeof(int *));

    for (i = 0; i < l; i++)
    {
        matriz[i] = (int *)malloc(c * sizeof(int));
    }

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &n);
            matriz[i][j] = n;
        }
    }

    soma = somalabirinto(l, c, matriz);

    if (soma == -1)
    {
        printf("sem solucao");
    }
    else
    {
        printf("%d", soma);
    }

    for (i = 0; i < l; i++)
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}