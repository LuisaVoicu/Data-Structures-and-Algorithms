#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int id;
    struct tree* right;
    struct tree* left;
}NodeT;

typedef struct dlist
{
    int key;
    struct dlist* next;
    struct dlist* prev;
}NodeDL;

struct DLL
{
    NodeDL* tail;
    NodeDL* head;
};
// functii aditionale ( pentru testarea algoritmului)
NodeT* create_nodeT(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->id = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* create_binTree(FILE* pf)
{

    int value;
    fscanf(pf,"%d", &value);

    if (value != 0)
    {
        NodeT* root = (NodeT*)malloc(sizeof(NodeT));
        root->id = value;
        root->left = create_binTree(pf);
        root->right = create_binTree(pf);
        return root;
    }
    return NULL;

}
void insert_tail_doubly(struct DLL* list, int key)
{
    NodeDL* node = create_nodeT(key);

    if (list->head == NULL)
    {
        list->tail = list->head = node;
    }
    else
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}

void print_doubly(struct DLL list)
{
    if (list.head == NULL)
    {
        printf("lista goala!\n");
    }
    else
    {
        while (list.head != list.tail)
        {
            printf("%d <-> ", list.head->key);
            list.head = list.head->next;
        }
        printf("%d", list.tail->key);
    }
    printf("\n");
}


void Tree_to_Doubly(NodeT* root, struct DLL* list)
{
    // functia parcurge arborele InOrder si in acelasi timp formeaza lista dublu inlantuita specifica acestuia
    if (root != NULL)
    {
        Tree_to_Doubly(root->left,list);
        insert_tail_doubly(list, root->id);
        Tree_to_Doubly(root->right,list);
    }
}
void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%d ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    FILE* pf = fopen("file.txt", "r");

    if (pf == NULL)
    {
        printf("fisierul nu poate fi deschis!");
        exit(123);
    }
    struct DLL list = { NULL, NULL };
    NodeT* root = create_binTree(pf);
    Tree_to_Doubly(root,&list);
    printf("elementele arborelui sunt: ");
    preorder(root);
    printf("\nlista corespunzatoare arborelui: ");
    print_doubly(list);

}