#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ABS(x) (((x)<0)? -(x):(x))
typedef struct ABC
{
    int id;
    int height;
    struct ABC* left;
    struct ABC* right;
}NodeT;

////////////////////////////////functii auxiliare//////////////////////////////

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


///////////////////////////////////////////////////////////////////////////////////
///////////////// functiile necesare rezolvarii problemei : //////////////////////

NodeT* searchNode(NodeT* root, int key)
{
    // iterativ

    while (root != NULL)
    {
        if (key == root->id)
        {
            return root;
        }
        if (key < root->id)
        {
            root = root->left;
        }
        else if (key > root->id)
        {
            root = root->right;
        }
    }
    
    return NULL;
}

int descendant(NodeT* root, int y)
{
    int found;

    if (root == NULL)
    {
        return 0;
    }
   
   
    if (root->id == y)
    {
        printf("%d ", root->id);
        return 1;
    }

    if (y < root->id)
    {
        found = descendant(root->left, y);
    }
    
    if (y > root->id)
    {
        found = descendant(root->right, y);
    }
    
    if (found == 1)
    {
        printf("%d ", root->id);
    }
 
    return found;
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
    int x = 1;
    NodeT* xNode = searchNode(root, x);
    if (xNode != NULL)
    {
        // se precizeaza in enunt ca x se afla in arbore
        int y = 5;
        printf("\n%d este descendent al lui %d ? rezultat: ", y, x);
        int found = descendant(xNode, y);
        if (found == 0)
        {
            printf("%d nu este descendent al lui %d!\n",y,x);
        }
        printf("\n");

        printf("\n%d este descendent al lui %d ? rezultat: ", y, x);
        y = 12;
        found = descendant(xNode, y);
        if (found == 0)
        {
            printf("%d nu este descendent al lui %d!\n", y, x);
        }

    }
}
