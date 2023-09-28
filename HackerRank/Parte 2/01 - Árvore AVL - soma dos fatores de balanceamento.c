#include <stdio.h>
#include <stdlib.h>

typedef struct NodeAVL NodeAVL;

struct NodeAVL
{
    int item;
    int fb;
    struct NodeAVL *left; 
    struct NodeAVL *right;
};

NodeAVL* criar_AVL(int item)
{
    NodeAVL * tree = (NodeAVL *) malloc(sizeof(NodeAVL));

    tree->item = item;
        tree->fb = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

static NodeAVL* rotateL(NodeAVL *tree)
{
    NodeAVL *auxA = tree->left, *auxB;

    if (auxA->fb == +1)
	{
        tree->left = auxA->right;
        auxA->right = tree;
        tree->fb = 0;
        tree = auxA;
    }else
	{
        auxB = auxA->right;
        auxA->right = auxB->left;
        auxB->left = auxA;
        tree->left = auxB->right;
        auxB->right = tree;

        if (auxB->fb == +1)
            tree->fb = -1;
        else
            tree->fb = 0;

        if (auxB->fb == -1)
            auxA->fb = +1;
        else
            auxA->fb = 0;

        tree = auxB;
    }
    
    return tree;
}


static NodeAVL* rotateR(NodeAVL *tree)
{
    NodeAVL *auxA = tree->right, *auxB;

    if (auxA->fb == -1)
	{
        tree->right = auxA->left;
        auxA->left = tree;
        tree->fb = 0;
        tree = auxA;
    }else
	{
        auxB = auxA->left;
        auxA->left = auxB->right;
        auxB->right = auxA;
        tree->right = auxB->left;
        auxB->left = tree;

        if (auxB->fb == -1)
            tree->fb = +1;
        else
            tree->fb = 0;

        if (auxB-> fb == +1)
            auxA->fb = -1;
        else
            auxA->fb = 0;

        tree = auxB;
    }
    
    return tree;
}

NodeAVL *inserirAVL(NodeAVL *tree, int value, int *grown)
{

    if (tree == NULL)
    {
        tree = criar_AVL(value);

        *grown = 1;
    }
    else if (value < tree->item)
    {
        tree->left = inserirAVL(tree->left, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case -1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = +1;
                break;
            case +1:
                tree = rotateL(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }
    else if (value > tree->item)
    {
        tree->right = inserirAVL(tree->right, value, grown);

        if (*grown)
        {
            switch (tree->fb)
            {
            case +1:
                tree->fb = 0;
                *grown = 0;
                break;
            case 0:
                tree->fb = -1;
                break;
            case -1:
                tree = rotateR(tree);
                tree->fb = 0;
                *grown = 0;
            }
        }
    }

    return tree;    
}

int altura(NodeAVL* tree)
{
    int l, r;
    
    if (tree == NULL)
        return -1;
    else{
        l = altura(tree->left);
        r = altura(tree->right);
        
        return ((l > r) ? l : r) + 1;
    }
}

int soma_fator_bal(NodeAVL *tree)
{
	if(tree == NULL)
		return 0;
	else
		return tree->fb + soma_fator_bal(tree->right) + soma_fator_bal(tree->left);
}

int main()
{
    int n, i, item,x,g=0;
    NodeAVL *raiz = NULL;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        raiz = inserirAVL(raiz, item, &g);
    }
    x = soma_fator_bal(raiz);
    printf("%d",x);
}
