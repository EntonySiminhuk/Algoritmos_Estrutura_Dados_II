#include <stdio.h>
#include <math.h>
int main()
{
    int N, a, b, c, d, e, f, g;
    scanf("%d", &N);
    printf("%d\n", N);
    a = (N / 100);
    N = N - (a * 100);
    printf("%d nota(s) de R$ 100,00\n", a);

    b = (N / 50);
    N = N - (b * 50);
    printf("%d nota(s) de R$ 50,00\n", b);

    c = (N / 20);
    N = N - (c * 20);
    printf("%d nota(s) de R$ 20,00\n", c);

    d = (N / 10);
    N = N - (d * 10);
    printf("%d nota(s) de R$ 10,00\n", d);

    e = (N / 5);
    N = N - (e * 5);
    printf("%d nota(s) de R$ 5,00\n", e);

    f = (N / 2);
    N = N - (f * 2);
    printf("%d nota(s) de R$ 2,00\n", f);

    g = (N / 1);
    N = N - (g * 1);
    printf("%d nota(s) de R$ 1,00\n", g);
}