#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    double key;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create_node(double key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* abc, double key)
{
    if (abc == NULL)
    {
        abc = create_node(key);
        return abc;
    }
    else
    {
        if (key < abc->key)
            abc->left = insert_ABC(abc->left, key);
        else
            abc->right = insert_ABC(abc->right, key);

        return abc;
    }
}

void Preorder(NodeT* abc)
{

    if (NULL != abc)
    {
        printf("%g ", abc->key);
        Preorder(abc->left);
        Preorder(abc->right);
    }
}

void Inorder(NodeT* abc)
{

    if (NULL != abc)
    {
        Inorder(abc->left);
        printf("%g ", abc->key);
        Inorder(abc->right);
    }
}

int main()
{
    FILE* pf = fopen("fisier.txt", "r");
    if (pf == NULL)
    {
        printf("fisierul nu se poate deschide!\n");
        exit(1);
    }

    int n;
    fscanf(pf, "%d\n", &n);
    NodeT* root = NULL;
    NodeT* intreg = NULL;
    NodeT* zecimal = NULL;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        double x;
        int nri;
        double nrz;
        fscanf(pf, "%lf", &x);
        nri = (int)x;
        nrz = x - nri;
        printf("%g %d %g \n", x, nri, nrz);
        if (i == 0)
        {
            root = insert_ABC(root, x);
            intreg = insert_ABC(intreg, nri);
            zecimal = insert_ABC(zecimal, nrz);
        }
        else
        {
            insert_ABC(root, x);
            insert_ABC(intreg, nri);
            insert_ABC(zecimal, nrz);
        }
    }

    printf("arborele format din numerele citite este:\n\n");
    Inorder(root);
    printf("\n\narborele format din partea intreaga a numerelor citite este:\n\n");
    Inorder(intreg);
    printf("\n\narborele format din partea zecimala a numerelor citite este:\n");
    Inorder(zecimal);
    printf("\n");

}