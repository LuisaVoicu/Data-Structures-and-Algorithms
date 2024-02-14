#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ABS(x) (((x)<0)? -(x):(x))


//// functii auxiliare pt verificarea programului///
/////////////// pentru lista ///////////////////////
typedef struct List
{
    int key;
    struct List* next;
}NodeL;

void insert_lastList(NodeL** head, NodeL** tail, int key)
{
    NodeL* node = (NodeL*)malloc(sizeof(NodeL));
    node->key = key;
    node->next = NULL;
    if (*head == NULL)
    {
        *head = *tail = node;
    }
    else
    {
        (*tail)->next = node;
        *tail = node;
    }
}

void print_list(NodeL* head)
{
    printf("\nRadacinile subarborilor AVL sunt:\n");
    while (head != NULL)
    {
        printf("%d ", head->key);
        head = head->next;
    }
    printf("\n");

}


/////////////////// pentru ABC ///////////////////
typedef struct ABC
{
    int id;
    int height;
    struct ABC* left;
    struct ABC* right;
}NodeT;

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
///////////////////////////////////////////////////////////////////////////////
///////////////// functia necesara rezolvarii problemei////////////////////////

int is_AVL(NodeT* root)
{
    int res = 1;
    if (root != NULL)
    {
        int HL = -1;
        int HR = -1;
        if (root->right != NULL)
        {
            HL = root->right->height;
        }
        if (root->left != NULL)
        {
            HR = root->left->height;
        }
        int abs = ABS(HR - HL); // sau (HR + 1) - (HL + 1)

        if (abs > 1)
        {
            res = 0;
        }
        else
        {
            res = is_AVL(root->right);
            res = is_AVL(root->left);

        }
        return res;

    }


}

void AVL_roots(NodeT* root, NodeL** head, NodeL** tail)
{
    if (root != NULL)
    {
        int avlRoot = is_AVL(root);
        if (avlRoot == 1)
        {
            insert_lastList(head, tail, root->id); 
        }
        AVL_roots(root->left, head, tail);
        AVL_roots(root->right, head, tail);
    }
}


int main()
{
    NodeT* root = NULL;
    NodeL* head = NULL;
    NodeL* tail = NULL;

    root = insert_ABC(root, 7);
    insert_ABC(root, 5);
    insert_ABC(root, 2);
    insert_ABC(root, 12);
    insert_ABC(root, 10);
    insert_ABC(root, 1);
    insert_ABC(root, 4);
    insert_ABC(root, 15);
    insert_ABC(root, 16);


    printf("arborele are elementele:\n");
    get_heights(root);
    preorder(root);
    printf("\n");
    AVL_roots(root, &head, &tail);
    print_list(head);
}