#include <stdio.h>
#include <math.h>
int main()
{
    double A, B, C, TOT1 = 0, TOT2 = 0, TOT3 = 0, TOT4 = 0, TOT5 = 0, PI;
    PI = 3.14159;
    scanf("%lf %lf %lf", &A, &B, &C);
    // c) a �rea do trap�zio que tem A e B por bases e C por altura.
    TOT3 = C * (A + B) / 2;
    // a) a �rea do tri�ngulo ret�ngulo que tem A por base e C por altura.
    TOT1 = (A * C) / 2;
    // b) a �rea do c�rculo de raio C. (pi = 3.14159)
    C = (pow(C, 2));
    TOT2 = (PI * C);
    // d) a �rea do quadrado que tem lado B.
    TOT4 = B * B;
    // e) a �rea do ret�ngulo que tem lados A e B.
    TOT5 = A * B;

    printf("TRIANGULO: %0.3lf\n", TOT1);
    printf("CIRCULO: %0.3lf\n", TOT2);
    printf("TRAPEZIO: %0.3lf\n", TOT3);
    printf("QUADRADO: %0.3lf\n", TOT4);
    printf("RETANGULO: %0.3lf\n", TOT5);
}