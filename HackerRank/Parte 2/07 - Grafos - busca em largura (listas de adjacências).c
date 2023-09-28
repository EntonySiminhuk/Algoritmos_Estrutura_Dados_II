#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/***************************************************************/
typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct FilaE FilaE;

struct Cell
{
    int key;
    struct Cell *next;
};

struct Lista
{
    Cell *head;
};

struct GrafoLA
{
    int V;
    int A;
    int *cor;
    int *pai;
    int *d;
    Lista **adj;
};
/***************************************************************/
// Lista encadeada

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}

Cell *criar_celula(int key)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->key = key;
    c->next = NULL;

    return c;
}

int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, Lista *l)
{
    Cell *aux;

    if (l != NULL)
    {
        aux = l->head;

        while ((aux != NULL) && (key < aux->key))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->key))
        return 1;
    else
        return 0;
}

void inserir_na_lista(int key, Lista *l)
{
    Cell *auxA, *auxP;
    Cell *c;

    if (lista_vazia(l))
    {
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key);
    }
    else
    {
        c = criar_celula(key);

        if (l->head->key >= key)
        {
            c->next = l->head;

            l->head = c;
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key))
            {
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}

int remover_na_lista(int key, Lista *l)
{
    Cell *auxA, *auxP;

    if (!lista_vazia(l))
    {
        auxA = l->head;

        if (auxA->key == key)
            l->head = l->head->next;
        else
        {
            auxP = auxA;

            while ((auxA != NULL) && (key < auxA->key))
            {
                auxP = auxA;
                auxA = auxA->next;
            }

            if (auxA->key == key)
                auxP->next = auxA->next;
            else
                auxA = NULL;
        }

        if (auxA != NULL)
            free(auxA);

        return 1;
    }

    return 0;
}

void imprimir(Lista *l)
{
    Cell *aux;

    if (!lista_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%d\n", aux->key);

            aux = aux->next;
        }
    }
}

int liberar_lista(Lista *l)
{
    Cell *aux;

    if ((l != NULL) && !lista_vazia(l))
    {

        while (l->head != NULL)
        {
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

struct FilaE
{
    Cell *inicio;
    Cell *fim;
};

FilaE *criar_filaE()
{
    FilaE *f = (FilaE *)malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int filaE_vazia(FilaE *f)
{
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int key, FilaE *f)
{
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else
    {
        f->fim->next = aux;
        f->fim = f->fim->next;
    }
}

int desenfileirar(FilaE *f)
{
    Cell *aux;
    int item = INT_MAX;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;

        f->inicio = aux->next;

        item = aux->key;

        free(aux);
    }

    return item;
}

void imprimir_fila(FilaE *f)
{
    Cell *aux;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->key);
            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_filaE(FilaE *f)
{
    if (!filaE_vazia(f))
    {
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

/***************************************************************/
// Grafo

static Lista **iniciar_LA(int n)
{
    int i;
    Lista **adj = (Lista **)malloc(n * sizeof(Lista *));

    for (i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}

GrafoLA *iniciar_grafoLA(int v)
{
    GrafoLA *G = (GrafoLA *)malloc(sizeof(GrafoLA));
    G->pai = (int *)malloc(sizeof(int) * v);
    G->cor = (int *)malloc(sizeof(int) * v);
    G->d = (int *)malloc(sizeof(int) * v);
    G->V = v;
    G->A = 0;
    G->adj = iniciar_LA(G->V);

    return G;
}

int aresta_existeLA(GrafoLA *G, int v1, int v2)
{
    if ((G != NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}

void inserir_arestaLA(GrafoLA *G, int v1, int v2)
{
    if (!aresta_existeLA(G, v1, v2))
    {
        inserir_na_lista(v2, G->adj[v1]);
        inserir_na_lista(v1, G->adj[v2]);
        G->A++;
    }
}

void remover_arestaLA(GrafoLA *G, int v1, int v2)
{
    if (aresta_existeLA(G, v1, v2))
    {
        remover_na_lista(v2, G->adj[v1]);
        remover_na_lista(v1, G->adj[v2]);
        G->A--;
    }
}

void imprimir_arestasLA(GrafoLA *G)
{
    int i;
    Cell *aux;

    if (G != NULL)
        for (i = 0; i < G->V; i++)
        {
            aux = G->adj[i]->head;

            while (aux != NULL)
            {
                printf("(%d, %d)\n", i, aux->key);

                aux = aux->next;
            }
        }
}

void liberarGLA(GrafoLA *G)
{
    int i;

    if (G != NULL)
    {
        for (i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);

        free(G);
    }
}
static int valida_vertice(GrafoLA *G, int ver)
{
    return (ver >= 0) && (ver < G->V);
}

void busca_largura(GrafoLA *G, int s)
{
    int u, v;
    FilaE *f;
    if (valida_vertice(G, s))
    {
        for (v = 0; v < G->V; v++)
        {
            G->cor[v] = 0;
            G->pai[v] = -1;
            G->d[v] = INT_MAX;
        }
        G->cor[s] = 1;
        G->d[s] = 0;
        f = criar_filaE();
        enfileirar(s, f);
        while (!filaE_vazia(f))
        {
            u = desenfileirar(f);
            for (v = 0; v < G->V; v++)
            {
                if ((aresta_existeLA(G, v, u)) && (G->cor[v] == 0))
                {
                    G->cor[v] = 1;
                    G->pai[v] = u;
                    G->d[v] = G->d[u] + 1;
                    enfileirar(v, f);
                }
            }
            G->cor[u] = 2;
        }
        printf("v d p\n");
        for (v = 0; v < G->V; v++)
        {
            printf("%d ", v);
            if (G->d[v] < INT_MAX)
                printf("%d ", G->d[v]);
            else
                printf("- ");
            if (G->pai[v] >= 0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");
        }
        liberar_filaE(f);
    }
}

int main()
{
    int i, V, ver, aux;
    GrafoLA *G;

    scanf("%d", &V);
    G = iniciar_grafoLA(V);
    for (i = 0; i < V; i++)
    {
        do
        {
            scanf("%d", &ver);
            if (ver >= 0)
                inserir_arestaLA(G, i, ver);

        } while (ver >= 0);
    }
    scanf("%d", &aux);
    busca_largura(G, aux);
}