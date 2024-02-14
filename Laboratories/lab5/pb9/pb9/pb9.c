#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int id;
    struct node_type* left, * right;
} NodeT;

NodeT* createBinTreeFromFile(FILE* f)
{
    NodeT* p;
    int c;
    fscanf(f, "%d", &c);
    if (c == 0)
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        if (p == NULL)
            return;

        p->id = c;
        p->left = createBinTreeFromFile(f);
        p->right = createBinTreeFromFile(f);
    }
    return p;
}

void preorder(NodeT* p)
{
    if (p != NULL)
    {
        printf("%d ", p->id);
        preorder(p->left);
        preorder(p->right);
    }
}

void mirror_trees(NodeT* tree1, NodeT* tree2, int* isMirror)
{
    if (tree1 != NULL && tree2 != NULL)
    {
        printf("%d %d\n", tree1->id, tree2->id);
        if (tree1->id != tree2->id)
        {
            *isMirror = 0;
            return;
        }
        mirror_trees(tree1->left, tree2->right, isMirror);
        mirror_trees(tree1->right, tree2->left, isMirror);
    }
    else if ((tree1 == NULL && tree2 != NULL) || (tree1 != NULL && tree2 == NULL))
    {
        *isMirror = 0;
        return;
    }
}
int main()
{
    FILE* pf = fopen("file1.txt", "r");
    FILE* qf = fopen("file2.txt", "r");

    if (pf == NULL || qf == NULL)
    {
        printf("eroare");
        exit(1);
    }

    NodeT* tree1 = createBinTreeFromFile(pf);
    NodeT* tree2 = createBinTreeFromFile(qf);

    preorder(tree1);
    printf("\n");
    preorder(tree2);
    printf("\n");
    int mirr = 1;
    mirror_trees(tree1, tree2, &mirr);

    if (mirr == 0)
    {
        printf("ARBORII NU SUNT IN OGLINDA!");
    }
    else
    {
        printf("ARBORII SUNT IN OGLINDA!");
    }

}
