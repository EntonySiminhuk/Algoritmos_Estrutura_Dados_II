#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

Node *criar(int item);

Node *pesquisar(int item, Node *tree);

int min(Node *tree);

int max(Node *tree);

Node *inserir(int item, Node *tree);

int remover(int item, Node *tree);

void imprimirInfix(Node *tree);

void imprimirPrefix(Node *tree);

void imprimirPosfix(Node *tree);

void liberar_arvore(Node *tree);

struct Node
{
    int item;           
    struct Node *left;  
    struct Node *right; 
};


Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *pesquisar(int item, Node *tree)
{
    if (tree != NULL)
        {
            if (item == tree->item)
                return tree;                         
            else if (item < tree->item)              
                return pesquisar(item, tree->left); 
            else                                     
                return pesquisar(item, tree->right); 
        }
    else
        return NULL;
}

int min(Node *tree)
{
    Node *aux = tree;

    if (aux != NULL)
        {
            while (aux->left != NULL)
                aux = aux->left;

            return aux->item;
        }

    return INT_MIN;
}

int max(Node *tree)
{
    Node *aux = tree;

    if (aux != NULL)
        {
            while (aux->right != NULL)
                aux = aux->right;

            return aux->item;
        }

    return INT_MAX;
}

Node *inserir(int item, Node *tree)
{
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);

    return tree;
}

int remover(int item, Node *tree)
{
    Node *aux, *auxP, *auxF;

    if (tree != NULL)
        {
            if (item < tree->item)
                remover(item, tree->left);
            else if (item > tree->item)
                remover(item, tree->right);
            else
                {
                    aux = tree;
                    if (aux->left == NULL)
                        tree = tree->right;
                    else if (aux->right == NULL)
                        tree = tree->left;
                    else
                        {
                            auxP = aux->right;
                            auxF = auxP;

                            while (auxF->left != NULL)
                                {
                                    auxP = auxF;
                                    auxF = auxF->left;
                                }

                            if (auxP != auxF)
                                {
                                    auxP->left = auxF->right;
                                    auxF->left = aux->left;
                                }

                            auxF->right = aux->right;

                            tree = auxF;
                        }

                    free(aux);

                    return 1;
                }
        }

    return 0;
}

void imprimirInfix(Node *tree)
{
    if (tree != NULL)
        {
            imprimirInfix(tree->left);
            printf("\n%i", tree->item);
            imprimirInfix(tree->right);
        }
}


void imprimirPrefix(Node *tree)
{
    if (tree != NULL)
        {
            printf("\n%i", tree->item);
            imprimirPrefix(tree->left);
            imprimirPrefix(tree->right);
        }
}


void imprimirPosfix(Node *tree)
{
    if (tree != NULL)
        {
            imprimirPosfix(tree->left);
            imprimirPosfix(tree->right);
            printf("\n%i", tree->item);
        }
}

void liberar_arvore(Node *tree)
{
    if (tree != NULL)
        {
            liberar_arvore(tree->left);
            liberar_arvore(tree->right);
            free(tree);
        }
}

int altura(Node *tree)
{
    int direita = 0, esquerda = 0;
    if (tree == NULL)
        return 0;
    else
        {
            esquerda = altura(tree->left) + 1;
            direita = altura(tree->right) + 1;
        }
    if (esquerda > direita)
        {
            return esquerda;
        }
    else
        {
            return direita;
        }
}

int altura2(Node *tree)
{
    if (tree == NULL)
        return -1;
    else
        {
            int esq = altura2(tree->left);
            int dir = altura2(tree->right);
            if (esq > dir)
                return esq + 1;
            else
                return dir + 1;
        }
}

void Nos_folhas(Node *tree)
{
    int esq = 0, dir = 0;
    if( tree == NULL)
        printf("%i ", tree->item);
    else
        {
            if(tree->left == NULL)
                esq = 0;
            else if (tree->left != NULL)
            {
                esq = 1;
                Nos_folhas(tree->left);
                
            }
            if(tree->right == NULL)
                dir = 0;
            else if(tree->right != NULL)
            {
                dir = 1;
                Nos_folhas(tree->right);
                
            }
                
                
        }
        if(esq == 0 )
        {
            if(dir == 0)
                printf(" %i", tree->item);
        }
            
}



int main()
{
    int n, i, item;
    Node *raiz;

    scanf("%d", &n);
    scanf("%d", &item);
    raiz = criar(item);
    for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &item);
            inserir(item, raiz);
        }
    Nos_folhas(raiz);
    return 0;
}
