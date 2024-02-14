#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) ((A) > (B) ? (A):(B))
typedef struct node
{
    int key;
    int height;
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


void  height_avl(NodeT* root, int* isAVL)
{
    if (root != NULL)
    {
        height_avl(root->left,isAVL);
        height_avl(root->right,isAVL);
        int hl = -1;
        int hr = -1;
        if (root->left != NULL)
        {
            hl = root->left->height;
        }
        if (root->right != NULL)
        {
            hr = root->right->height;
        }
        root->height = 1 + MAX(hl, hr);
        
        int balance = hl - hr;
        if (balance > 1 || balance < -1)
        {
            if (*isAVL == 1)
            {
                printf("Arborele nu este AVL! Dezechilibrul apare la nodul %d !\n", root->key);
            }
            *isAVL = 0;
        }

    }

}

int height(NodeT* root)
{
    if (root != NULL)
    {
        return MAX(height(root->left), height(root->right)) + 1;
    }
    return -1;
}

void set_heights(NodeT* root)
{
    if (root != NULL)
    {
        set_heights(root->right);
        set_heights(root->left);
    }
}

void isAVL(NodeT* root, int* r)
{
    if (root != NULL)
    {
        isAVL(root->left,r);
        isAVL(root->right,r);
        int hl = height(root->left);
        int hr = height(root->right);
        int balance = hl - hr;
        if (balance > 1 || balance < -1)
        {
            if (*r == 1)
            {
                printf("Arborele nu este AVL! Dezechilibrul apare pentru nodul %d !\n", root->key);
            }
            *r = 0;
        }
    }
}
void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%d %d\n", root->key, root->height);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    NodeT* abc = NULL;
    abc = insert_ABC(abc, 4);
    insert_ABC(abc, 2);
    insert_ABC(abc, 3);
    insert_ABC(abc, 8);
    insert_ABC(abc, 9);
    insert_ABC(abc, 0);
    //insert_ABC(abc, 10);
    
    
    /*
    // MET 1. se calculeaza inaltimea si verifica daca arborele este AVL simultan!
          // complexitate O(n)
    int k = 1;
    height_avl(abc, &k);
    if (k == 1)
    {
        printf("Arborele este AVL !\n");
    }

    printf("\nInaltimea elementelor din arbore este:\n");
    preorder(abc);
    */

    // MET2. se calculeaza inaltimea si se verifica daca arborele este AVL separat
       // complexitate : 
    int avlTree = 1;
    isAVL(abc, &avlTree);
    if (avlTree == 1)
    {
        printf("Arborele este AVL!\n");
    }

}