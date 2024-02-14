#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int key;
    struct Node* left, * right;
} NodeT;

void preorder(NodeT* root)
{
    // TODO
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NodeT* root)
{
    // TODO
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(NodeT* root)
{
    // TODO
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

NodeT* createNode(int key, NodeT* left, NodeT* right)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->key = key;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// modifica arborele astfel incat fiecare nod sa fie suma copiilor sai
int leafSum(NodeT* root)
{
    // TODO
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // daca e frunza returnam valoarea ei
            return root->key;
        }
        // altfel 
        root->key = leafSum(root->left) + leafSum(root->right);
        return root->key;
    }
    else
    {
        return 0;
    }
}

int main()
{
    NodeT* root = createNode(1, createNode(7, createNode(2, createNode(3, NULL, NULL), createNode(5, NULL, NULL)), NULL),
        createNode(11, createNode(3, NULL, NULL), createNode(4, createNode(8, NULL, NULL), createNode(6, NULL, NULL))));

    printf("\nParcurgere in preordine\n");
    preorder(root); // 1 7 2 3 5 11 3 4 8 6

    printf("\nParcurgere in inordine\n");
    inorder(root); // 3 2 5 7 1 3 11 8 4 6

    printf("\nParcurgere in postordine\n");
    postorder(root); // 3 5 2 7 3 8 6 4 11 1

    printf("\nParcurgere in preordine dupa leafSum:\n");
    leafSum(root);
    preorder(root); // 25 8 8 3 5 17 3 14 8 6

    printf("\n");

    return 0;
}
