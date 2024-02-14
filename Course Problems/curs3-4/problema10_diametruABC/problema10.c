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

////////////////// functii auxiliare //////////////////////////
                                                             
NodeT* create_nodeT(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->id = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* root, int key)
{
    NodeT* node = create_nodeT(key);
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
///////////////////////////////////////////////////////////////

int ABC_MAXheight(NodeT* root)
{
    if (root == NULL)
    {
        return -1;
    }
    int Hleft = ABC_MAXheight(root->left);
    int Hright = ABC_MAXheight(root->right);
    if (Hleft > Hright)
    {
        return 1 + Hleft;
    }
    else
    {
        return 1 + Hright;
    }
}

int ABC_diameter(NodeT* root)
{
    if (root == NULL)
    {
        return 0;
    }
    // diametrul unui arbore  = (1+ Hmax subarbore stang) + (1 + Hmax subarbore drept)
    // vom folosi functia de la problema 9
    int HL = ABC_MAXheight(root->left);
    int HR = ABC_MAXheight(root->right);
    return (1 + HL) + (1 + HR);

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

    int diam = ABC_diameter(root);
    printf("\ndiametrul arborelui este: %d\n", diam);


}