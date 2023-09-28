#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int qtd_moedas(int m[], int n, int t, int minimo, int i)
{
    int aux1, aux2;

    if (i < n)
    {
        aux1 = qtd_moedas(m, n, t, minimo, i + 1);
        aux2 = qtd_moedas(m, n, t % m[i], minimo + (t / m[i]), i + 1);

        return aux1 < aux2 ? aux1 : aux2;
    }
    else
    {
        if (t > 0)
            return INT_MAX;
        else
            return minimo;
    }
}

int main()
{
    int i, n, t;
    int *m;

    scanf("%d", &t);
    scanf("%d", &n);

    m = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    printf("%d", qtd_moedas(m, n, t, 0, 0));

    return 0;
}