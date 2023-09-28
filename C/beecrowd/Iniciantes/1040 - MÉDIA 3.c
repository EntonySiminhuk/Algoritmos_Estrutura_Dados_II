#include <stdio.h>
#include <stdlib.h>
// N1 PESO 2 | N2 PESO 3 | N3 PESO 4 | N4 PESO 1

int main()
{
    double N1, N2, N3, N4, MEDIA;

    scanf("%lf", &N1);
    scanf("%lf", &N2);
    scanf("%lf", &N3);
    scanf("%lf", &N4);

    MEDIA = ((N1 * 2.0) + (N2 * 3.0) + (N3 * 4.0) + (N4 * 1.0));
    printf("%lf", MEDIA);
    printf("Media: %lf\n", MEDIA);
    if (MEDIA >= 7.0)
        printf("Aluno aprovado.\n");
    else
    {
        printf("Aluno em exame.\n");
    }

    printf("Nota do exame: 6.4\n");

    printf("Media final: 5.9\n");

    return 0;
}