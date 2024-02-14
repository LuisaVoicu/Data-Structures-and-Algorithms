#define _CRT_SECURE_NO_WARNINGS_
#include <stdlib.h>
#include <stdio.h>
#define ABS(x) (((x)<0)? -(x):(x))

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

//////////////////////////////////////////////////////////////////////////////////////


int get_heights(NodeT* root)
{
    if (root == NULL)
    {
        return -1;
    }

    int HL = get_heights(root->left);
    int HR = get_heights(root->right);

    if (HL > HR)
    {
        root->height = 1 + HL;
        return 1 + HL;
    }
    else
    {
        root->height = 1 + HR;
        return 1 + HR;
    }
}

int is_AVL(NodeT* root)
{
    int res;
    if (root == NULL)
    {
        return 1;
    }

    res = is_AVL(root->left);
    res = is_AVL(root->right);
    // verificam daca modulul diferentei dintre inaltimile subarborilor este cel mult 1 ( daca da atunci e AVL)
    int HL = -1;
    int HR = -1;
    if (root->right != NULL)
    {
        HR = root->right->height;
    }
    if (root->left != NULL)
    {
        HL = root->left->height;
    }

    int abs = ABS(HR - HL); // sau (HR + 1) - (HL + 1)
  printf("%d %d \n", root->id, abs);
    if (abs > 1)
    {
        return 0;
    }



    return res;
}

int main()
{
    NodeT* root = NULL;
    root = insert_ABC(root, 7);
    insert_ABC(root, 5);
    insert_ABC(root, 2);
    insert_ABC(root, 12);
    insert_ABC(root, 10);
    insert_ABC(root, 6);
    insert_ABC(root, 3);
    insert_ABC(root, 4);
    insert_ABC(root, 15);
    insert_ABC(root, 16);
    insert_ABC(root, 1);
    insert_ABC(root, 9);
    insert_ABC(root, 8);
    printf("arborele are elementele:\n");
    get_heights(root);
    preorder(root);
    printf("\n");

    int k = is_AVL(root);
    if (k == 0)
    {
        printf("\nArborele NU este AVL!\n");
    }
    else
    {
        printf("\nArborele este AVL!\n");
    }


    /// cazul in care nu e AVL

    insert_ABC(root, 9);
    insert_ABC(root, 8);

    printf("arborele are elementele:\n");
    get_heights(root);
    preorder(root);
    printf("\n");

    k = is_AVL(root);
    if (k == 0)
    {
        printf("\nArborele NU este AVL!\n");
    }
    else
    {
        printf("\nArborele este AVL!\n");
    }
}
