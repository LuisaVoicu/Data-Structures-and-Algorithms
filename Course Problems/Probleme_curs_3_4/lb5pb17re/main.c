
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int used;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT*));
    node->key = key;
    node->used = 0;
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

void Preorder(NodeT* abc)
{

    if (NULL != abc)
    {
        printf("%d ", abc->key);
        Preorder(abc->left);
        Preorder(abc->right);
    }
}

int sum;

void parcurgere(NodeT* root,int**v,int**el, int k,int i)
{
    if (root != NULL)
    {
        if (i == 0)
        {
            v[i][0] = sum; el[i][0] = 0;
            v[i][1] = sum - root->key; el[i][1] = 1;
        }
        else
        {
            for (int j = 0; j < k / 2; j++)
            {
                v[i][j] = v[i - 1][j];
                el[i][j] = el[i - 1][j];
            }
            for (int j = k / 2; j < k; j++)
            {
                v[i][j] = v[i][j - k / 2] - root->key;
                el[i][j] = el[i][j - k / 2] + 1;
            }
        }
    }
}



int main()
{
    NodeT* root = NULL;
    int* v = (int*)malloc(sizeof(int) * 100);
    int* index = (int*)malloc(sizeof(int) * 100);
    root = insert_ABC(root, 7);
    insert_ABC(root, 5);
    insert_ABC(root, 9);
    insert_ABC(root, 6);
    insert_ABC(root, 8);
    insert_ABC(root, -3);
    insert_ABC(root, 10);
    insert_ABC(root, 12);
    insert_ABC(root, 14);
    printf("Elementele arborelui: ");
    Preorder(root);
    printf("\n");

    int** v = (int**)malloc(sizeof(int*) *10);
        int** el = (int**)malloc(sizeof(int*) * 10);
        // retin in v toate! scaderile posibile
        int t = 1;
        for(int i = 0 ; i < 10; i++)

         {
            t = t * 2;
            v[i] = (int*)malloc(sizeof(int) * t);

            el[i] = (int*)malloc(sizeof(int) * t);

            for (int j = 0; j < t; j++)
            {
                v[i][j] = el[i][j] = 0;
            }
        }
        v[0][0] = sum;


}
