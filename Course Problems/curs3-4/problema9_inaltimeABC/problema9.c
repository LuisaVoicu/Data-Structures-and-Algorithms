#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ABC
{
    int id;
    int height;
    struct ABC* left;
    struct ABC* right;
}NodeT;

//// functii auxiliare pt verificarea programului

NodeT* create_nodeT(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->id = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* root, int key)
{

    if (root == NULL)
    {
        root = create_nodeT(key);
    }
    else
    {
        if (key > root->id)
        {
            root->right = insert_ABC(root->right, key);
        }
        else if (key < root->id)
        {
            root->left = insert_ABC(root->left, key);
        }

    }
    return root;
}

void preorder(NodeT* root)
{
    if (NULL != root)
    {
        printf("%d ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}

int ABC_MAXheight(NodeT* root)
{
    // algoritmul calculeaza cea mai mare inaltime din arbore
    // in acelasi timp memoreaza inaltimea fiecarui nod
    if (root == NULL)
    {
        return -1;
    }
    int Hleft = ABC_MAXheight(root->left);
    int Hright = ABC_MAXheight(root->right);
    if (Hleft > Hright)
    {
        root->height = 1 + Hleft;
        return 1 + Hleft;
    }
    else
    {
        root->height = 1 + Hright;
        return 1 + Hright;
    }
}
void print_node_height(NodeT* root)
{
    if (root != NULL)
    {
        printf("h(%d) = %d\n", root->id, root->height);
        print_node_height(root->left);
        print_node_height(root->right);
    }
}


int main()
{

    NodeT* root = NULL;
    root = insert_ABC(root, 7);
    insert_ABC(root, 1);
    insert_ABC(root, 2);
    insert_ABC(root, 0);
    insert_ABC(root, 9);
    insert_ABC(root, 12);
    insert_ABC(root, 4);
    insert_ABC(root, 5);
    insert_ABC(root, 14);
    insert_ABC(root, 3);
    printf("arborele are elementele:\n");
    preorder(root);
    printf("\n");
    int HMax = ABC_MAXheight(root);
    printf("\ninaltimea maxima este: %d\n", HMax);
    printf("\ninaltimea fiecarui nod este:\n");
    print_node_height(root);
}
