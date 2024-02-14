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

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->id = key;
    node->right = node->left = NULL;
    return node;
}

NodeT* insert_ABC(NodeT* root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }

    if (key < root->id)
    {
        root->left = insert_ABC(root->left, key);
    }
    if (key > root->id)
    {
        root->right = insert_ABC(root->right, key);
    }
    return root;

}



void inorder(NodeT* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->id);
        inorder(root->right);
    }
}

void store(NodeT* root, int* vector, int* index)
{
    if (root != NULL)
    {
        store(root->left, vector, index);
        vector[(*index)++] = root->id;
        store(root->right, vector, index);
    }
}

int main()
{
    int n , elem;
    NodeT* root = NULL;
    
    printf("introduceti numarul de elemente din vector: ");
    scanf("%d", &n);
    printf("\nintroduceti cele %d elemente din vector:\n", n); 
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        root = insert_ABC(root, elem); // realizeaza ordonarea sirului 
    }

    // parcurgerea InOrder afiseaza elementele stocate in arbore in ordine crescatoare
    printf("\nelementele ordonate crescator sunt:\n");
    inorder(root); 

    // pentru stocarea acestora intr-un vector vom proceda similar parcurgerii InOrder
    
    int* vector = (int*)malloc(n * sizeof(int));
    n = 0;
    store(root, vector, &n);
    
    printf("\n\nau fost stocate elementele:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}