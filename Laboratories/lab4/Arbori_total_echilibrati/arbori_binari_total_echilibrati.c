#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Tree_type
{
    int id;
    struct Tree_type* left;
    struct Tree_type* right;
}NodeT;

NodeT* CreateBalancedBinTree(int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    int sizeL = size / 2;
    int sizeR = size - sizeL - 1;

    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    
    scanf("%d", &(node->id));
    printf(" a fost introds elementul %d\n", node->id);
    node->left = CreateBalancedBinTree(sizeL);
    node->right = CreateBalancedBinTree(sizeR);

    return node;
}

void preord(NodeT* tree)
{
    if (NULL != tree)
    {
        printf("%d ", tree->id);
   
    preord(tree->left);
    preord(tree->right); 
    }
}
int main()
{
    NodeT* root = NULL;
    int nrelem = 7;
    root = CreateBalancedBinTree(nrelem);
    printf("\n");
    preord(root);
}