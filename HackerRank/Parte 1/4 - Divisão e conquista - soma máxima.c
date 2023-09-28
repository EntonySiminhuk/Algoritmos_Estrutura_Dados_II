// finalizado
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

int soma_max(int vetor[], int n, int i, int soma_m)
{
    int aux;

    if (i >= n)
        return soma_m;
    else if (vetor[i] >= 0)
    {
        aux = soma_max(vetor, n, i + 1, soma_m + vetor[i]);
    }
    else
        aux = soma_max(vetor, n, i + 1, soma_m);

    return aux;
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    int vetor[n];

    for (i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    printf("%d", soma_max(vetor, n, 0, 0));

    return 0;
}