#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int key;
    struct node* left;
    struct node* right;
}NodeT;


NodeT* create_from_file(FILE* pf)
{
    int x;
    fscanf(pf, "%d", &x);
    if (x != 0)
    {
        NodeT* root = (NodeT*)malloc(sizeof(NodeT));
        if (root == NULL)
        {
            printf("Eroare!!!\n");
            return;
        }

        root->key = x;
        root->left = root->right = NULL;
        root->left = create_from_file(pf);
        root->right = create_from_file(pf);
        return root;
    }
    else
    {
        return NULL;
    }
}

void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{

    FILE* pf = fopen("fisier.txt", "r");
    if (pf == NULL)
    {
        printf("eroare");
        exit(12345);
    }


    NodeT* root = NULL;
    root = create_from_file(pf);

    preorder(root);
}