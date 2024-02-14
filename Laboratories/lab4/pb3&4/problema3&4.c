/*
3. Sa se scrie o func¸tie care determina adancimea maxima a unui arbore binar. 
4. Sa se scrie o functie care determina diametrul unui arbore binar
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTree
{
    int id;
    int depth;
    struct BinaryTree* left;
    struct BinaryTree* right;
}NodeT;

NodeT* createBinaryTree(FILE* pf)
{
    int key; 
    fscanf(pf, "%d", &key);
    if (0 == key)
    {
        return NULL;
    }

    NodeT* root = (NodeT*)malloc(sizeof(NodeT));

    if (NULL == root)
    {
        printf("Eroare!");
        return;
    }

    root->id = key;
    root->depth= 0;
    root->left = createBinaryTree(pf);
    root->right = createBinaryTree(pf);

    return root;
}

void PreOrder(NodeT* root)
{
    if (NULL != root)
    {
        printf("%d ", root->id);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int k;
int Depth(NodeT* root, int* MaxDepth, int* AlmostMaxDepth)
{
    if (NULL != root)
    {
        if (root->left != NULL)
        {
            root->left->depth = 1 + root->depth;
        }

        if (root->right != NULL)
        {
            root->right->depth = 1 + root->depth;
        }

        Depth(root->left, MaxDepth, AlmostMaxDepth);  
        Depth(root->right, MaxDepth, AlmostMaxDepth);
        
        if (NULL == root->left && NULL == root->right)
        {
            if (root->depth >= *MaxDepth)
            {
                *AlmostMaxDepth = *MaxDepth;
                *MaxDepth = root->depth;
            }
            else
            {
                if (root->depth > *AlmostMaxDepth)
                {
                    *AlmostMaxDepth = root->depth;
                }
            }
        }
    }
}

int main()
{
    FILE* pf = fopen("file.txt", "r");
    if (NULL == pf)
    {
        printf("eroare");
        exit(1);
    }

    NodeT* root = createBinaryTree(pf);
    PreOrder(root);
    printf("\n");
    int max1 = 0 , max2 = 0;
    Depth(root,&max1,&max2);
    printf("Adancimea maxima = %d\n", max1, max2);

    // diametrul unui arbore este egal cu A( = cea mai mare adancime) + B( = urmatoarea cea mai mare adancime, mai mica decat A)
    printf("Diametrul arborelui este = %d\n", max1 + max2);
}