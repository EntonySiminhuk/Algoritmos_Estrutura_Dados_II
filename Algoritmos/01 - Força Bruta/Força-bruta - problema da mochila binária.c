#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mochila_fb(int p[], int c[], int n, int b, int i, int max)
{
    int c1, c2;
    if (i >= n)
    {
        /*if(b < 0)
            return 0;
        else
            return max; */
        return (b < 0) ? 0 : max; // operador ternario
    }
    else
    {
        c1 = mochila_fb(p, c, n, b, i + 1, max);
        c2 = mochila_fb(p, c, n, b - p[i], i + 1, max + c[i]);

        return (c1 > c2) ? c1 : c2;
    }
}

int main()
{
    int i, b, n;
    int *p, *c; // vetores

    scanf("%d", &b);
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int) * n); // alocação dinamica, ou pode ser int p[n];
    c = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d %d", &p[i], &c[i]);

    printf("%d", mochila_fb(p, c, n, b, 0, 0));

    free(p); // quando não  ser mais usado o ponteiro e sempre bom desalocalo
    free(c); // quando não  ser mais usado o ponteiro e sempre bom desalocalo

    return 0;
}