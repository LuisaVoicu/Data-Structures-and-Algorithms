#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT*));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* abc, int key)
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

NodeT* get_leaf(NodeT* root)
{   
    // functia returneaza cea mai din stanga frunza din arbore;
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root; 
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
    NodeT* tree1 = NULL;
    tree1 = insert_ABC(tree1, 5);
    insert_ABC(tree1, 9);
    insert_ABC(tree1, 4);
    insert_ABC(tree1, 7);
    insert_ABC(tree1, 12);
    insert_ABC(tree1, 6);
    insert_ABC(tree1, 8);
    preorder(tree1);
    printf("\n");


    NodeT* tree2 = NULL;
    tree2 = insert_ABC(tree2, 12);
    insert_ABC(tree2, 15);
    insert_ABC(tree2, 13);
    insert_ABC(tree2, 17);
    insert_ABC(tree2, 8);
    preorder(tree2);
    printf("\n");

    NodeT* leafT1 = get_leaf(tree1);
 

    leafT1->left = tree2;
    
    printf("\n\nArborele rezultat in urma concatenarii este:\n");
    preorder(tree1);
    printf("\n");

}