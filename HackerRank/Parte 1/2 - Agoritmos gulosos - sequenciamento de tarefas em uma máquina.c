//finalizado
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Tarefas Tarefas;

struct Tarefas
{
    int id;
    int e;
    int d;
};

void sequencia(Tarefas *maquina, int tamanho)
{

    int i, j, soma = 0;
    Tarefas aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if ((maquina[j].d - maquina[j].e) < (maquina[j + 1].d - maquina[j + 1].e))
            {

                aux = maquina[j];
                maquina[j] = maquina[j + 1];
                maquina[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", maquina[i].id);
        soma = soma + (maquina[i].d - maquina[i].e);
    }

    if (soma > 0)
    {
        printf("\n0");
    }
    else
    {
        printf("\n%d", (-1) * soma);
    }
}

int main(void)
{
    int i, tamanho;

    scanf("%d", &tamanho);

    Tarefas maquina[tamanho];

    for (i = 0; i < tamanho; i++)
    {
        maquina[i].id = i;

        scanf("%d %d", &maquina[i].e, &maquina[i].d);
    }

    sequencia(maquina, tamanho);
}