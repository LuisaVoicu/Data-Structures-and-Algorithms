/*
5. Sa se scrie un program care transforma un arbore binar într-o lista dublu înlan¸tuita
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
    struct BinaryTree* parent;
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
    root->depth = 0;
    root->left = createBinaryTree(pf);
    root->right = createBinaryTree(pf);
    return root;
}

void SetParent(NodeT* root)
{
    if (NULL != root)
    {

        if (root->left != NULL)
        {
            root->left->parent = root;
        }
        if (root->right != NULL)
        {
            root->right->parent = root;
        }

        SetParent(root->left);
        SetParent(root->right);
    }
}

NodeT* SearchKey(NodeT* tree, int key)
{
    NodeT* node = NULL;

    if (NULL != tree)
    {
        if (tree->id == key)
        {
            return tree;
        }

        if (node == NULL)
        {
            node = SearchKey(tree->left, key);
        }
        if (node == NULL)
        {
            node = SearchKey(tree->right, key);
        }
    }
    return node;

}

void TraversalRoot(NodeT* node, NodeT* root)
{
    if (node != root)
    {
        printf("%d ", node->id);
        TraversalRoot(node->parent, root);
    }
    else
    {
        printf("%d ", root->id);
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
    SetParent(root);
    NodeT* node = SearchKey(root, 6);
    if (node != NULL)
    {
        printf("%d\n", node->id);
        TraversalRoot(node, root);
    }
   
}