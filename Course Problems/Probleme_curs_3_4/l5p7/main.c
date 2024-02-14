#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int used;
    struct node* left;
    struct node* right;
    struct node* parent;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT*));
    node->key = key;
    node->left = node->right = node->parent = NULL;
    node->used = 0;
    return node;
}

NodeT* insert_ABC(NodeT* abc, int key)
{
    if (abc == NULL)
    {
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
        printf("%d ", abc->key);
        Preorder(abc->left);
        Preorder(abc->right);
    }
}
int main()
{
     NodeT* root = NULL;
    root = insert_ABC(root, -5);
    insert_ABC(root, -9);
    insert_ABC(root, -2);
    insert_ABC(root, -1);
    insert_ABC(root, -3);
    insert_ABC(root, 3);
    insert_ABC(root, 1);
    insert_ABC(root, 4);
    printf("%d\n",root->key);
    return 0;
}
