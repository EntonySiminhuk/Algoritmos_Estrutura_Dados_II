#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/***************************************************************/
typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;

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

void inserir_na_lista(int key, Lista *l)
{
    Cell *auxA, *auxP, *c;

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

/***************************************************************/
// GrafoLA

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
        G->A++;
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
static int valida_vertice(GrafoLA* G, int v)
{
    return (v >= 0) && (v < G->V);
}

void busca_largura(GrafoLA *G, int s)
{
    int u, v;
    Lista *l;
    if(valida_vertice(G, s))
    {
        for(v=0; v<G->V; v++)
        {
            G->cor[v]=0;
            G->pai[v]=-1;
            G->d[v]=INT_MAX;
        }
        G->cor[s]=1;
        G->d[s]=0;
        l = criar_lista();
        inserir_na_lista(s, l);
        while(!lista_vazia(l))
        {
            u = liberar_lista(l);
            for(v=0; v<G->V; v++)
            {
                if((aresta_existeLA(G, v, u)) && (G->cor[v]==0))
                {
                    G->cor[v]=1;
                    G->pai[v]=u;
                    G->d[v]=G->d[u]+1;
                    inserir_na_lista(v, l);
                }
            }
            G->cor[u]=2;   
        }
        printf("v d p\n");
        for(v=0; v<G->V; v++)
        {
            printf("%d ", v);
            if(G->d[v]<INT_MAX)
                 printf("%d ", G->d[v]);
            else
                printf("- ");
            if(G->pai[v]>=0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");      
        }
        liberar_lista(l);
    }
}

int main()
{
    int v, ver,i;
    scanf("%d", &v);
    GrafoLA *G = iniciar_grafoLA(v);

    for ( i = 0; i < v; i++)
    {
        do
        {
            scanf("%d", &ver);
            if (ver >= 0)
                inserir_arestaLA(G, i, ver);

        } while (ver >= 0);
    }
    scanf("%d", &ver);
    busca_largura(G,ver);

    return 0;
}