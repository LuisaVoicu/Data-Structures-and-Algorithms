#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    char key[10];
    struct tree* left;
    struct tree* right;
}NodeT;

NodeT* Create_Tree(NodeT* tree, char s[100][10], int* n)
{
        if (*n > 0)
        {

                NodeT* tree = (NodeT*)malloc(sizeof(NodeT));

                (*n)--;
                strcpy(tree->key, s[*n]);
                if (strchr("*+-/", s[*n][0]) == 0)
                {
                    // e litera/numar deci e frunza
                    tree->right = tree->left = NULL;
                }
                else
                {

                    tree->right = Create_Tree(tree->right, s, n);
                    tree->left = Create_Tree(tree->left, s, n);
                }
                return tree;
        }
        return NULL;



}

void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%s ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    FILE* pf = fopen("file.txt", "r");
    char s[100], c;
    fgets(s,100,pf);
    printf("%s", s);
    char* p, sir[100][10];
    p = strtok(s, " ");

    int n = 0;
    while (p != NULL)
    {
        strcpy(sir[n++], p);
        p = strtok(NULL, " ");
    }

    NodeT* root = NULL;
    int m = n;
    root = Create_Tree(root, sir, &m);
    printf("\nExpresia in preorder:\n");
    preorder(root);
}
