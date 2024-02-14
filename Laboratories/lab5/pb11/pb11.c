#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT*));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* abc, int key)
{
    if (abc == NULL)
    {
        abc = create_node(key);
        return abc;
    }
    else
    {
        if (key < abc->key)
            abc->left = insert_ABC(abc->left, key);
        else
            abc->right = insert_ABC(abc->right, key);

        return abc;
    }
}
void Preorder(NodeT* abc)
{

    if (NULL != abc)
    {
        printf("%d ", abc->key);
        Preorder(abc->left);
        Preorder(abc->right);
    }
}

NodeT* cauta_noduri(NodeT* root, int key)
{
    while (root != NULL)
    {
        if (root->key == key)
        {
            return root;
        }
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
    }
    return root;

}
void drum_AB(NodeT* A, int B)
{
    if (A != NULL)
    {
        if (A->key != B)
        {
            printf("%d ", A->key);
            if (B < A->key)
            {
                drum_AB(A->left, B);
            }
            else
            {
                drum_AB(A->right, B);
            }
        }
        else
        {
            printf("%d ", B);

        }
    }
}
void drum(NodeT* root, int stopKey, int caz)
{
    // caz = 0 -> afisare de tipul root ---> nod (in sus)
    // caz = 1 -> afisare de fipul nod  ---> root ( in jos)
    if (root != NULL)
    {
        if(stopKey == root->key)
        {  
            printf("%d ", stopKey);
        }
        else
        {
            if (caz == 0 )
            {
                printf("%d ", root->key);
            }
            if (stopKey < root->key)
            {
                drum(root->left, stopKey, caz);
            }
            else
            {
                drum(root->right, stopKey, caz);
            }
            if (caz == 1 )
            {
                printf("%d ", root->key);
            }
        }
    }
}

int acelasi_subarbore(NodeT* A, NodeT* B)
{
    if (cauta_noduri(A, B->key) == NULL && cauta_noduri(B, A->key) == NULL)
    {
        return 0;
    }
    return 1;
}

NodeT* determina_pseudo_radacina(NodeT* root, int a, int b)
{
    if (root != NULL)
    {
        if (a < root->key && root->key < b)
        {
            return root;
        }
        else
        {
            if (b < root->key)
            {
                determina_pseudo_radacina(root->left, a, b);
            }
            else
            {
                determina_pseudo_radacina(root->right, a, b);
            }
        }
    }
}
void drum_cazuri(NodeT* root, NodeT* A, NodeT* B)
{
    if (A != NULL && B != NULL)
    {
        if (acelasi_subarbore(A, B) == 1)
        {
            if (A->key < B->key)
            {
                drum(A, B->key,0);
            }
            else
            {
                drum(B, A->key, 1);
            }
        }
    
        else
        {
            if (A->key < B->key)
            {
                root = determina_pseudo_radacina(root, A->key, B->key);
                drum(root, A->key, 1);
                // pornim de la root->right pt a nu afisa de 2 ori radacina
                drum(root->right, B->key, 0);
            }
            else
            {
                root = determina_pseudo_radacina(root, B->key, A->key);
                drum(root, A->key, 1);
                // pornim de la root->right pt a nu afisa de 2 ori radacina
                drum(root->left, B->key, 0);
            }
        }
    }
}

int main()
{
    NodeT* root = NULL;
    root = insert_ABC(root, 15);
    insert_ABC(root, 6);
    insert_ABC(root, 3);
    insert_ABC(root, 2);
    insert_ABC(root, 4);
    insert_ABC(root, 7);
    insert_ABC(root, 13);
    insert_ABC(root, 9);
    insert_ABC(root, 18);
    insert_ABC(root, 20);
    insert_ABC(root, 17);

    Preorder(root);
    printf("\n");


    // caz 1. A si B se afla in acelasi subarbore
    // => afisam dist de la min(A,B) la max(A,B)
    // caz 2. A si b se afla in subarbori diferiti
    // afisam in sens invers nodurile de la A la radacina 
    // afisam in sens normal nodurile de la radacina la B

    NodeT* A = NULL;
    NodeT* B = NULL;
    
    //drum_noduri(A, B);

    printf("\ncaz1: a si b fac parte din acelasi subarbore:\n");
    A = cauta_noduri(root, 6);
    B = cauta_noduri(root, 9);
    drum_cazuri(root,A, B);
    printf("\n\ncaz2: a si b fac parte din subarbori diferiti:\n\n~ ex1:radacina initiala:\n");
    A = cauta_noduri(root, 3);
    B = cauta_noduri(root, 17);
    drum_cazuri(root, A, B);
    printf("\n\n~ ex2: radacina diferita decat cea initiala:) \n");
    A = cauta_noduri(root, 3);
    B = cauta_noduri(root, 13);
    drum_cazuri(root, A, B);
    printf("\n");

}