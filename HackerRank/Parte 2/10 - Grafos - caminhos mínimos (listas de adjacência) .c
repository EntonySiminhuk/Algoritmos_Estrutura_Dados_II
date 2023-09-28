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
    int p;
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
    int *nafila;
    int *pai;
    int *item;
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

Cell *criar_celula(int key, int p)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->key = key;
    c->p = p;
    c->next = NULL;

    return c;
}
Cell *criar_celula_orignal(int key)
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
    Cell *aux = NULL;

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

void inserir_na_lista(int key, Lista *l, int p)
{
    Cell *auxA, *auxP;
    Cell *c;

    if (lista_vazia(l))
    {
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key, p);
    }
    else
    {
        c = criar_celula(key, p);

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

    aux = criar_celula_orignal(key);

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
    G->nafila = (int *)malloc(sizeof(int) * v);
    G->item = (int *)malloc(sizeof(int) * v);
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

void inserir_arestaLA(GrafoLA *G, int v1, int v2, int p)
{
    if (!aresta_existeLA(G, v1, v2))
    {
        inserir_na_lista(v2, G->adj[v1], p);
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
/***************************************************************/

static int extract_min(FilaE *f, GrafoLA *G)
{
    int vM;

    Cell *aux, *auxM;

    auxM = f->inicio;
    aux = auxM->next;

    while (aux != NULL)
    {
        if (G->item[aux->key] < G->item[auxM->key])
            auxM = aux;
        aux = aux->next;
    }

    if (auxM != f->inicio)
    {
        vM = f->inicio->key;
        f->inicio->key = auxM->key;
        auxM->key = vM;
    }

    return desenfileirar(f);
}

void Dijktra(GrafoLA *G)
{
    int u, v;
    FilaE *f = NULL;

    Cell *x;

    f = criar_filaE();
    for (v = 0; v < G->V; v++)
    {
        G->pai[v] = -1;
        G->nafila[v] = 1;
        G->item[v] = INT_MAX;
        enfileirar(v, f);
    }

    G->item[0] = 0;

    while (!filaE_vazia(f))
    {
        u = extract_min(f, G);
        G->nafila[u] = 0;

        x = G->adj[u]->head;
        while (x != NULL)
        {
            if ((x->p < G->item[x->key]) && (G->nafila[x->key]) && (x->p != 0))
            {
                G->item[x->key] = x->p;
                G->pai[x->key] = u;
            }
            x = x->next;
        }
    }

    for (v = 0; v < G->V; v++)
    {
        printf("%d: ", v);

        if (G->pai[v] >= 0)
            printf("%d\n", G->pai[v]);
        else
            printf("-\n");
    }
    liberar_filaE(f);
}

int main()
{
    int i, tamanho, ve1, ve2, n, p;

    scanf("%d", &tamanho);
    GrafoLA *G = iniciar_grafoLA(tamanho);

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ve1);
        scanf("%d", &ve2);
        scanf("%d", &p);

        inserir_arestaLA(G, ve1, ve2, p);
    }

    Dijktra(G);
    return 0;
}
