#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//função criada pelo professor
#define max(a,b) a > b ? a : b

int maior_preco(int preco[], int tam_h)
{
    int i, j, q;
    int r[tam_h + 1];
    
    r[0] = 0;
    
    for(i = 1; i <= tam_h; i++)
    {
        q = INT_MIN;
        
        
        for(j = 0; j < i; j++)
            q = max(q,preco[j] + r[i - j - 1]);
        
        r[i] = q;
    }
    
    return r[tam_h];
}


// minha função
int cortar(int t, int n, int preco[])
{
    int auxs, auxt, s, i;

    s = 0;

    for (i = 0; i < n; i++)
    {
        auxt = t - (i + 1);
        auxs = 0;

        if (auxt < 0)
        {
            break;
        }
        else
        {
            auxs = preco[i] + cortar(auxt, n, preco);
        }
        if (auxs > s)
        {
            s = auxs;
        }
    }
    return s;
}

int main(void)
{
    int i, t, n;

    scanf("%d", &t);
    scanf("%d", &n);

    int preco[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &preco[i]);
    }
    printf("%d", cortar(t, n, preco));

    return 0;
}
