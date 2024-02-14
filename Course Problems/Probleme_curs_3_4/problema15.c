#define _CRT_SECURE_NO_WARNINGS_
#include <stdlib.h>
#include <stdio.h>

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

int  second_nb(int* vector, int* size, int value, int* val2, int sum)
{
    
    if (*size == -1)
    {
        vector[++(*size)] = value;
        return 0; 
    }
    else
    {
        // algoritm de cautare binara

        int lft = 0, rgh = *size ;
        int found = 0;

        while (lft <= rgh)
        {

            int midd = (rgh + lft) / 2;

            if (vector[midd] + value == sum)
            {
                found = 1;
                *val2 = vector[midd];
                break;
            }
            else if (vector[midd] + value < sum)
            {

                lft = midd + 1;
            }
            else if (vector[midd] + value > sum)
            {
                rgh = midd - 1;
            }

        }

        if (found == 0)
        {
            // nu am gasit niciun element potrivit
            // stocam val1 ( <=> adaugam elementele ordonate in vector)
            vector[++(*size)] = value;
        }
        return found;
    }
}

void inorder_traversal(NodeT* root, int* vector, int* size, int sum, int* val1, int* val2, int* found)
{
    if (root != NULL)
    {
        inorder_traversal(root->left, vector, size, sum, val1, val2, found);
        if (root->id < sum)
        {
            int k = second_nb(vector, size, root->id, val2, sum);

            if (k == 1)
            {
                *found = 1;
                *val1 = root->id;
                return;
            }

        }
        inorder_traversal(root->right, vector, size, sum, val1, val2, found);
    }
}

int main()
{

    NodeT* root = NULL;
    root = insert_ABC(root, 7);
    insert_ABC(root, 5);
    insert_ABC(root, 2);
    insert_ABC(root, 12);
    insert_ABC(root, 10);
    insert_ABC(root, 1);
    insert_ABC(root, 4);
    insert_ABC(root, 15);
    insert_ABC(root, 16);
    insert_ABC(root, 6);

    int* vect = (int*)malloc(sizeof(int) * 10);
    int val1 = 1, val2 = 1, size = -1, found = 0;
    int sum = 31;
    
    // cautam cele doua noduri printre elementele sortate(prin parcurgerea inOrder)
    inorder_traversal(root, vect, &size, sum, &val1, &val2, &found);

    if (found == 0)
    {
        printf("\nNu exista 2 noduri a caror suma este %d\n", sum);
    }
    else
    {
        printf("\nElemente gasite!  ( %d + %d = %d )\n", val1, val2, sum);
    }
}