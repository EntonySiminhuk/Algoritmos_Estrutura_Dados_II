#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void qtd_moedas(int m[], int n, int t)
{
    int i, qtd;

    for (i = 0; (i < n) && (t > 0); i++)
    {
        qtd = t / m[i];
        t = t % m[i];
        t = t % m[i];
        while (qtd > 0)
        {
            printf("%d\n", m[i]);
            qtd--;
        }
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

    qtd_moedas(m, n, t);

    free(m);

    return 0;
}