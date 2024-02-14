#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
    int id;
    struct BinaryTree* left;
    struct BinaryTree* right;
}NodeT;

NodeT* createBinaryTree(FILE* pf)
{
    
    
    int key;
    fscanf(pf, "%d", &key);
    
    if (0 == key)
    {
        // nod vid
        return NULL;
    }

    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    
        if (NULL == node)
        {
            printf("eroare! nu poate fi alocata memorie!");
            return;
        }

    node->id = key;
    node->left = createBinaryTree(pf);
    node->right = createBinaryTree(pf);

    return node;
}

// parcurgere preorder

void PreOrder(NodeT* tree)
{
    if (NULL != tree)
    {
        printf("%d ", tree->id);
        PreOrder(tree->left);
        PreOrder(tree->right);
    }
}

void InOrder(NodeT* tree)
{
    if (NULL != tree)
    {
        
        InOrder(tree->left);
        printf("%d ", tree->id);
        InOrder(tree->right);
    }
}

void PostOrder(NodeT* tree)
{
    if (NULL != tree)
    {
        
        PostOrder(tree->left);
        PostOrder(tree->right);
        printf("%d ", tree->id);
    }
}

int Count_Leaves(NodeT* tree)
{
    if (NULL == tree)
    {
        return 0;
    }
    if (NULL == tree->left && NULL == tree->right)
    {
        return 1;
    }
    return Count_Leaves(tree->left) + Count_Leaves(tree->right);
}

int Count_Internal_Nodes(NodeT* tree)
{
    if (NULL == tree)
    {
        // arborele nu are elemente initial 
        return 0;
    }

    if (NULL != tree->left || NULL != tree->right)
    {
        return 1 + Count_Internal_Nodes(tree->left) + Count_Internal_Nodes(tree->right);
    }
    // cand intalneste o frunza returneaza 0
    return 0;
}


int Tree_Height(NodeT* tree)
{
    if(NULL == tree)
    {
        return -1;
    }
    
    int HL = Tree_Height(tree->left);
    int HR = Tree_Height(tree->right);

    if (HL > HR)
    {
        return 1 + HL;
    }

    return 1 + HR;
}

NodeT* Search_Key(NodeT* tree, int key)
{
    NodeT* node = NULL;

    if (NULL != tree)
    {
        if (tree->id == key)
        {
            return tree;
        }

        if (node == NULL)
        {
            node = Search_Key(tree->left, key);
        }
        if (node == NULL)
        {
            node = Search_Key(tree->right, key);
        }
        
       
    }

    return node;

}

int main()
{
    NodeT* root;
    FILE* pf = fopen("ArboreBinar.txt", "r");
    
    if (NULL == pf)
    {
        printf("Eroare! fisierul nu poate fi deschis");
        exit(1);
    }

    //constructie arbore
    root = createBinaryTree(pf);

    // parcurgeri
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");


    int k = Count_Leaves(root);
    printf("\nNr de radacini este: %d\n", k);
 
    k = Count_Internal_Nodes(root);
    printf("\nNr de noduri interne este: %d\n", k);
    
    k = Tree_Height(root);
    printf("\nInaltimea arborelui este: %d\n", k);

    int key = 4;
    NodeT* cheie = Search_Key(root,1111);
    if (NULL != cheie)
    {
        printf("\nAm gasit nodul %d !\n", cheie->id);
    }
    else
    {
        printf("\nNodul %d nu exista in arbore!\n", key);
    }
    
    fclose(pf);
}