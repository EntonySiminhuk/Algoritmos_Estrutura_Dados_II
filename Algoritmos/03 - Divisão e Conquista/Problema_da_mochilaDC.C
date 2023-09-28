#include <stdio.h>

int mochila_dq(int c[], int p[], int *b, int ini, int fim)
{
    int meio;
    if (fim == ini)
    {
        if ((*b - p[ini] >= 0))
        {
            *b -= p[ini];
            return c[ini];
        }
        else
            return 0;
    }
    else
    {
        meio = (ini + fim) / 2;
        return mochila_dq(c, p, b, ini, meio) +
               mochila_dq(c, p, b, meio + 1, fim);
    }
}

int mochila(int c[], int p[], int n, int b)
{
    int aux = b;
    return mochila_dq(c, p, n, &aux, 0, n - 1);
}

int main()
{
}