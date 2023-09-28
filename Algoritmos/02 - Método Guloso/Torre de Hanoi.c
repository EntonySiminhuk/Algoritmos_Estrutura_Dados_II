#include <stdio.h>
#include <stdlib.h>

void hanoi(char de, char para, char meio, int n)
{
    if (n <= 1)
        printf("Disco %d:  %c => %c\n", n, de, para);
    else
    {
        hanoi(de, meio, para, n - 1);
        printf("Disco %d:  %c => %c\n", n, de, para);
        hanoi(meio, para, de, n - 1);
    }
}

int main()
{

    return 0;
}