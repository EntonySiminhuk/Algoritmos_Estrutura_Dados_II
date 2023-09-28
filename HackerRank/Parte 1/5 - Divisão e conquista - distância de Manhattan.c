// feito
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}

int dist_tot(int inicio, int t, int vet1[], int vet2[])
{
    int meio = (t + inicio) / 2;

    if (t == inicio)
    {
        return soma(vet1[t], vet2[t]);
    }
    else
    {
        return dist_tot(inicio, meio, vet1, vet2) + dist_tot(meio + 1, t, vet1, vet2);
    }

    return 0;
}

int main(void)
{
    int i, t;

    scanf("%d", &t);

    int vet1[t], vet2[t];

    for (i = 0; i < t; i++)
    {
        scanf("%d", &vet1[i]);
    }

    for (i = 0; i < t; i++)
    {
        scanf("%d", &vet2[i]);
    }

    printf("%d", dist_tot(0, t - 1, vet1, vet2));
}