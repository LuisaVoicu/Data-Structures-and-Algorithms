/*
2. Sa se scrie un program care sa interschimbe subarborele drept cu cel stâng pentru un nod dat
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeType
{
    int id;
    struct TreeType* left;
    struct TreeType* right;
}NodeT;

NodeT* Create_BinTree(FILE* pf)
{   int id;

    fscanf(pf, "%d", &id);

    if (0 == id)
    {
        return NULL;
    }

    NodeT* root = (NodeT*)malloc(sizeof(NodeT));

    if (NULL == root)
    {
        printf("Eroare! Nu se poate aloca memorie!\n");
        return;
    }
    root->id = id;
    root->left = Create_BinTree(pf);
    root->right = Create_BinTree(pf);

    return root;
}

void PreOrder(NodeT* tree)
{
    if (NULL != tree)
    {
        printf("%d ", tree->id);
        PreOrder(tree->left);
        PreOrder(tree->right);
    }
}

void Swap_Subtree(NodeT* node)
{
    if (NULL != node)
    {
        
        NodeT* aux = node->left;
        node->left = node->right;
        node->right = aux;
    }
    return node;
}
int main()
{
    FILE* pf = fopen("file.txt", "r");
    if (NULL == pf)
    {
        printf("eroare!nu se poate deschide fisierul!");
        exit(1);
    }

    NodeT* root = Create_BinTree(pf);
    printf("arborele inainte de interschimbare: ");
    PreOrder(root);
    printf("\n");
    
    Swap_Subtree(root);
    printf("arborele dupa interschimbare: ");
    PreOrder(root);
    printf("\n");
}