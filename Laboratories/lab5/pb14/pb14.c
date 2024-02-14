#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* parinte;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->left = node->right = node->parinte = NULL;
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

void init_parinte(NodeT* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            root->left->parinte = root;
        }
        if (root->right != NULL)
        {
            root->right->parinte = root;
        }
        init_parinte(root->left);
        init_parinte(root->right);
    }
}

NodeT* cauta_noduri(NodeT* root, int key)
{
    while (root != NULL)
    {
        if (root->key == key)
        {
            return root;
        }
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
    }
    return root;
}

typedef struct rezultat
{
    int a, b;
}rez;

rez cauta_pereche(NodeT* root, int x)
{
    rez r = { 0,0 };
    if (root != NULL)
    {
        int find = x - root->key;

        // caz 1. urmatorul numar cautat este mai mic decat nodul curent
            // deci in cautam in subarborele stang determinat de nodul curent
        NodeT* node = cauta_noduri(root->left, find);
        if (node != NULL)
        {
            r.a = root->key;
            r.b = node->key;
            printf("%d+%d=%d\n", root->key, node->key, x);
            return r;
        }
        else
        {
            // caz2. urmatorul nr cautat e mai mare decat nodul curent 
            // deci acesta fie se afla in "susul" nodului curent , fie in subarborele drept al acestuia

            if (root->parinte != NULL && find >= root->parinte->key)
            {
                // aici poate aparea problema de a lua de 2 ori aceeasi valoare!

                node = cauta_noduri(root->parinte, find);
                if (node != NULL && node->key == root->key)
                {
                    node = NULL;
                }
            }
            if (node == NULL && root->right != NULL && find >= root->right->key)
            {

                node = cauta_noduri(root->right, find);
            }

            if (node != NULL)
            {
                r.a = root->key;
                r.b = node->key;
                printf("%d+%d=%d\n", root->key, node->key, x);
                return r;
            }
        }
        if (r.a == 0 && r.b == 0)
        {
            r = cauta_pereche(root->left, x);
            r = cauta_pereche(root->right, x);
        }
        
    }
     return r;
}

int main()
{

    NodeT* root = NULL;
    root = insert_ABC(root, 7);
    insert_ABC(root, 5);
    insert_ABC(root, 2);
    insert_ABC(root, 12);
    insert_ABC(root, 10);
    insert_ABC(root, 1);
    insert_ABC(root, 4);
    insert_ABC(root, 15);
    insert_ABC(root, 16);
    insert_ABC(root, 6);
    int x = 3;
    int* vect = (int*)malloc(sizeof(int) * 10);

    init_parinte(root);

    rez rezultat = cauta_pereche(root, x);
    printf("%d %d", rezultat.a, rezultat.b);
}