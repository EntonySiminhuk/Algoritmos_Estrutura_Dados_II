#include <stdio.h>
#include <stdlib.h>

long fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

long fib2(int n)
{
    int i, atual = 1;
    int p = 0; // penúltimo
    int u = 1; // último
    if (n <= 0) return 0;
    for (i = 2; i <= n; i++)
    {
        atual = p + u;
        p = u;
        u = atual;
    }
    return atual;
}

int main()
{

    return 0;
}