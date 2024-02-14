#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct binTree
{
    char cuvant[100];
    struct binTree* left;
    struct binTree* right;
}NodeT;


NodeT* create_node(char* cuvant)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    memcpy(node->cuvant, cuvant, 100);
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_BST(NodeT* root, char* cuv)
{
    
    if (root == NULL)
    {  
        return  create_node(cuv);
    }
    if (strcmp(cuv, root->cuvant) < 0)
    {
        root->left = insert_BST(root->left, cuv);
    }
    else
    {
        root->right = insert_BST(root->right, cuv);
    }
    return root;
}

void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%s ", root->cuvant);
        preorder(root->left);
        preorder(root->right);
    }
}


NodeT* cuv_min(NodeT* root)
{
   if(root != NULL)
   {
       while (root->left != NULL)
       {
           root = root->left;
       }
       return root;
   }
   return NULL;
}
NodeT* sterge_cuvant(NodeT* root, char* cuv)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (strcmp(cuv, root->cuvant) < 0)
    {
        root->left = sterge_cuvant(root->left, cuv);
    }
    else if (strcmp(cuv, root->cuvant) > 0)
    {
        root->right = sterge_cuvant(root->right, cuv);
    }
    else if (strcmp(cuv, root->cuvant) == 0)
    {
        // am gasit cuvantul
        NodeT* aux;
        if (root->left == NULL)
        {
            // 0 sau 1 fiu
            aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL)
        {
            // 0 sau 1 fiu
            aux = root->left;
            free(root);
            return aux;
        }
        // 2 fii
        //inlocuiesc cu cel mai mic element (cel mai din stanga) din subarborele drept
        aux = cuv_min(root->right);
        memcpy(root->cuvant,aux->cuvant,100);
        root->right = sterge_cuvant(root->right, aux->cuvant);
    }
    return root;
}
int main()
{

    FILE* pf = fopen("fisier.txt", "r");

    if (pf == NULL)
    {
        printf("eroare. nu se deschide fisierul\n");
        exit(1);
    }
    int k = 0;
    NodeT* root = NULL;
    while (!feof(pf))
    {
        char* cuv = (char*)malloc(100*sizeof(char));
        fscanf(pf, "%s", cuv);
        printf("%s\n", cuv);
        if (k == 0)
        {
            // primul element inserat
            root = insert_BST(root, cuv);
        }
        else
        {
            insert_BST(root, cuv);
        }
        k = 1;
    }

    printf("\n\n\n arborele de cuvinte in parcurgerea preordine este:\n");
    preorder(root);

    printf("\n\n\n");

    char cuv[100];

    strcpy(cuv, "raluca");
    sterge_cuvant(root, cuv);
    printf("dupa ce am sters cuvantul \"%s\" , arborele este:\n", cuv);
    preorder(root);
    printf("\n");

    strcpy(cuv, "stela");
    sterge_cuvant(root, cuv);
    printf("\n\ndupa ce am sters cuvantul \"%s\" , arborele este:\n", cuv);
    preorder(root);
    printf("\n");
    
    strcpy(cuv, "denisa");
    sterge_cuvant(root, cuv);
    printf("\n\ndupa ce am sters cuvantul \"%s\" , arborele este:\n", cuv);
    preorder(root);
    printf("\n");

}