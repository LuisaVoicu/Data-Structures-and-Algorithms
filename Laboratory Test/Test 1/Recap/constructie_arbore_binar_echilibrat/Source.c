#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* balanced_bin_tree(int nbn)
{
    if (nbn <= 0)
    {
        return NULL;
    }

    int nbl = nbn / 2;
    int nbr = nbn - nbl - 1;
    
    int key;
    scanf("%d", &key);
    NodeT* root = (NodeT*)malloc(sizeof(NodeT));
    root->key = key;
    root->left = balanced_bin_tree(nbl);
    root->right = balanced_bin_tree(nbr);
    return root;
}

void preord(NodeT* tree)
{
    if (NULL != tree)
    {
        printf("%d ", tree->key);

        preord(tree->left);
        preord(tree->right);
    }
}

void inorder(NodeT* tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->key);
        inorder(tree->right);
    }
}
int main()
{
    NodeT* root = NULL;
    int nrelem = 7;
    root = balanced_bin_tree(nrelem);
    printf("\n");
    preord(root);
    printf("\n");
    inorder(root);

}