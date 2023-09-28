#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int Sub_Sequencia(int vet[], int n)
{
    int soma_max = INT_MIN;
    int i,j,m;
    for(i = 0; i < n; i++)  
        {
            for(j = i; j< n; j++)
            {
                int s = 0; 
                for(m = i; m < j; m++) 
                {
                    s += vet[m];
                    if(s <= 0)
                        break;
                }
                if(s > soma_max)
                    soma_max = s;
            }
        }
        return soma_max;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int vet[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&vet[i]);
    }
    printf("%d",Sub_Sequencia(vet,n));
    return 0;
}