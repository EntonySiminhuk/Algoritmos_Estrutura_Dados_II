#include <stdio.h>
#include <math.h>
int main()
{
	double N;
	int a,b,c,d,e,f,m1,m2,m3,m4,m5,m6;
	scanf("%lf",&N);

    printf("NOTAS:\n");	
	a = ( N / 100);
    N = N - (a *100);
    printf("%d nota(s) de R$ 100.00\n",a);
    	
	b = (N / 50);
    N = N - (b *50);
    printf("%d nota(s) de R$ 50.00\n",b);

    c = ( N / 20);
    N = N - (c *20);
    printf("%d nota(s) de R$ 20.00\n",c);

    d = ( N / 10.);
    N = N - (d *10);
    printf("%d nota(s) de R$ 10.00\n",d);

    e = ( N / 5);
    N = N - (e *5);
    printf("%d nota(s) de R$ 5.00\n",e);
   
    f = ( N / 2);
    N = N - (f *2);
   printf("%d nota(s) de R$ 2.00\n",f);

    printf("MOEDAS:\n");
    m1 = ( N / 1 );
    N = N - (m1 *1);
    printf("%d moeda(s) de R$ 1.00\n",m1);
    
    m2 = ( N / 0.50 );
    N = N - (m2 *0.50);
    printf("%d moeda(s) de R$ 0.50\n",m2);

    m3 = ( N / 0.25 );
    m3 = N - (m3 *0.25);
    printf("%d moeda(s) de R$ 0.25\n",m3);

    m4 = ( N / 0.10 );
    N = N - (m4 *0.10);
    printf("%d moeda(s) de R$ 0.10\n",m4);

    m5 = ( N / 0.05 );
    N = N - (m5 *0.05);
    printf("%d moeda(s) de R$ 0.05\n",m5);

    m6 = ( N / 0.01 );
    N = N - (m6 *0.01);
	printf("%d moeda(s) de R$ 0.01\n",m6);
    
    return 0;
    }
